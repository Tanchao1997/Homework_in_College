#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define ID_FATHER 0
#define ID_PRDUCER_START 1
#define ID_PRODUCER_END 2
#define ID_CUSTOMER_START 3
#define ID_CUSTOMER_END 5
#define PROCESS_NUM 5

#define PRODUCER_TIMES 6
#define CUSTOMER_TIMES 4

#define BUFFER_LENGTH 3
#define SHM_NAME "BUFFER"

//缓冲区结构（循环队列）
typedef struct mybuffer
{
    int buff[BUFFER_LENGTH];
    int head;
    int tail;
    int is_empty;
}BUFFER;

//共享主存区结构
typedef struct sharemem
{
    struct mybuffer data;
    HANDLE sem_empty;
    HANDLE sem_full;
    HANDLE sem_mutex;
}SHM;

//文件映射对象句柄
static HANDLE hMapping;

//子进程句柄数组
static HANDLE hs[PROCESS_NUM + 1];

//得到5000以内的一个随机数
int get_random()
{
    int t;
    srand((unsigned)(GetCurrentProcessId() + time(NULL)));
    t = rand() % 1000;
    return t;
}

//进程克隆（通过参数传递进程的序列号）
void StartClone(int nCloneID)
{
    char szFilename[MAX_PATH];
    char szCmdLine[MAX_PATH];
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    GetModuleFileName(NULL, szFilename, MAX_PATH);
    sprintf(szCmdLine, "\"%s\" %d", szFilename, nCloneID);
    memset(&si, 0, sizeof(si));
    si.cb = sizeof(si);
    //创建子进程
    BOOL bCreateOK = CreateProcess(szFilename, szCmdLine, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
    hs[nCloneID] = pi.hProcess;
}

//创建共享主存区
HANDLE MakeSharedFile()
{
    //创建文件映射对象
    HANDLE hMapping = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, sizeof(struct sharemem), SHM_NAME);
    if (hMapping != INVALID_HANDLE_VALUE)
    {
        //在文件映射上创建视图
        LPVOID pData = MapViewOfFile(hMapping, FILE_MAP_ALL_ACCESS, 0, 0, 0);
        if (pData != NULL)
        {
            ZeroMemory(pData, sizeof(struct sharemem));
        }
        //关闭文件视图
        UnmapViewOfFile(pData);
    }
    return (hMapping);
}

//主函数
int main(int argc, char * argv[])
{
    int i, j, k;
    int data,buf_len,randomtime;
    int pindex = 1; //下一个要创建的子进程的序列号
    int nClone = ID_FATHER; //本进程序列号
    SYSTEMTIME systime;

    //如果有参数，就作为子进程的序列号
    if (argc > 1)
    nClone=atoi(argv[1]);
    //对于主控进程
    if (nClone == ID_FATHER)
    {
        printf("Main process start.\n");
        //创建数据文件
        hMapping = MakeSharedFile();
        //映射视图
        HANDLE hFileMapping = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, SHM_NAME);
        LPVOID pFile = MapViewOfFile(hFileMapping, FILE_MAP_ALL_ACCESS, 0, 0, 0);
        if (pFile == NULL)
        {   
            printf("OpenFileMapping failed!\n");
        }   
        //初始化缓冲区
        struct sharemem * shm = (struct sharemem *)(pFile);
        shm->data.head = 0;
        shm->data.tail = 0;
        shm->data.is_empty=1;
        //创建信号量sem_empty、sem_full、sem_mutex并分别初始化为3，0，1
        shm->sem_empty = CreateSemaphore(NULL, BUFFER_LENGTH, BUFFER_LENGTH, (LPCSTR)"SEM_EMPTY");
        shm->sem_full = CreateSemaphore(NULL, 0, BUFFER_LENGTH, (LPCSTR)"SEM_FULL");
        shm->sem_mutex=CreateSemaphore(NULL,1,1,(LPCSTR)"SEM_MUTEX");
        UnmapViewOfFile(pFile);
        pFile = NULL;
        CloseHandle(hFileMapping);

        //依次创建子进程
        while (pindex <= PROCESS_NUM)
        {
            StartClone(pindex++);
        }
        //等待子进程完成
        for (k = 1; k <= PROCESS_NUM; k++)
        {
            WaitForSingleObject(hs[k], INFINITE);
            CloseHandle(hs[k]);
        }
        CloseHandle(hMapping);
        hMapping = INVALID_HANDLE_VALUE;
        printf("Main process ends.\n");
    }
    //对于生产者进程
    else if (nClone >= ID_PRDUCER_START && nClone <= ID_PRODUCER_END)
    {
        //映射视图
        HANDLE hFileMapping = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, SHM_NAME);
        LPVOID pFile = MapViewOfFile(hFileMapping, FILE_MAP_ALL_ACCESS, 0, 0, 0);
        if (pFile != NULL)
        {
            struct sharemem * shm = (struct sharemem *)(pFile);
            HANDLE empty=OpenSemaphore(SEMAPHORE_ALL_ACCESS,FALSE,(LPCSTR)"SEM_EMPTY");
            HANDLE full = OpenSemaphore(SEMAPHORE_ALL_ACCESS,FALSE,(LPCSTR)"SEM_FULL");
            HANDLE mutex=OpenSemaphore(SEMAPHORE_ALL_ACCESS,FALSE,(LPCSTR)"SEM_MUTEX");
            for (i = 0; i < PRODUCER_TIMES; i++)
            {
                randomtime=get_random();
                Sleep(randomtime);
                WaitForSingleObject(empty, INFINITE);
                WaitForSingleObject(mutex, INFINITE);
                data=get_random();
                shm->data.buff[shm->data.tail] =  data;
                shm->data.tail = (shm->data.tail + 1) % BUFFER_LENGTH;
                shm->data.is_empty = 0;
                GetLocalTime(&systime);
                printf("Current time:  %02d:%02d:%02d\n", systime.wHour, systime.wMinute, systime.wSecond);
                printf("producer %d write %d to buffer.\n", nClone - ID_FATHER, data);
                printf("Data in buffer: ");
                buf_len=(shm->data.tail+BUFFER_LENGTH-shm->data.head)%BUFFER_LENGTH;
                if(buf_len==0) buf_len+=BUFFER_LENGTH;
                for(j=0;j<buf_len;j++)
                {
                    printf("%d ",shm->data.buff[(shm->data.head+j)%BUFFER_LENGTH]);
                }
                printf("\n\n");
                ReleaseSemaphore(full, 1, NULL);
                ReleaseSemaphore(mutex, 1, NULL);
                
            }
            UnmapViewOfFile(pFile);
            pFile = NULL;
        }
        else
        {
            printf("OpenFileMapping failed.\n");
        }
        CloseHandle(hFileMapping);
    }
    //对于消费者进程
    else if (nClone >= ID_CUSTOMER_START && nClone <= ID_CUSTOMER_END)
    {
        //映射视图
        HANDLE hFileMapping = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, SHM_NAME);
        LPVOID pFile = MapViewOfFile(hFileMapping, FILE_MAP_ALL_ACCESS, 0, 0, 0);
        if (pFile != NULL)
        {
            struct sharemem * shm = (struct sharemem *)(pFile);
            HANDLE empty=OpenSemaphore(SEMAPHORE_ALL_ACCESS,FALSE,(LPCSTR)"SEM_EMPTY");
            HANDLE full = OpenSemaphore(SEMAPHORE_ALL_ACCESS,FALSE,(LPCSTR)"SEM_FULL");
            HANDLE mutex=OpenSemaphore(SEMAPHORE_ALL_ACCESS,FALSE,(LPCSTR)"SEM_MUTEX");
            for (i = 0; i < CUSTOMER_TIMES; i++)
            {
                randomtime=get_random();
                Sleep(randomtime);
                WaitForSingleObject(full, INFINITE);
                WaitForSingleObject(mutex, INFINITE);
                data = shm->data.buff[shm->data.head];
                shm->data.head = (shm->data.head + 1) % BUFFER_LENGTH;
                shm->data.is_empty = (shm->data.head == shm->data.tail);
                GetLocalTime(&systime);
                printf("Current:  %02d:%02d:%02d:\n", systime.wHour, systime.wMinute, systime.wSecond);
                printf("Customer %d read %d from buffer.\n", nClone - ID_PRODUCER_END, data);
                buf_len=(shm->data.tail+BUFFER_LENGTH-shm->data.head)%BUFFER_LENGTH;
                if(buf_len==0)
                    printf("No data in buffer.\n\n");
                else
                {
                    printf("Data in buffer: ");
                    for(j=0;j<buf_len;j++)
                    {
                        printf("%d ",shm->data.buff[(shm->data.head+j)%BUFFER_LENGTH]);
                    }
                    printf("\n\n");
                }
                ReleaseSemaphore(empty, 1, NULL);
                ReleaseSemaphore(mutex, 1, NULL);
            }
            UnmapViewOfFile(pFile);
            pFile = NULL;
        }
        else
        {
            printf("OpenFileMapping failed.\n");
        }
        CloseHandle(hFileMapping);
    }
    else ;
    return 0;
}