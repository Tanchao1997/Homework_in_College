#include <stdio.h>
#include <time.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include<sys/wait.h>
//using namespace std;
#define PRODUCER_NUM 2      //生产者的数量
#define COMSUMER_NUM 3      //消费者的数量
#define PRODUCER_TIMES 6    //每个生产者的生产次数
#define CONSUMER_TIMES 4    //每个消费者的消费次数

#define BUF_LENGTH 3        //缓冲区大小
#define SHM_MODE 0600       

#define SEM_KEY 1234        //
#define SHM_KEY 6666

#define NUM_OF_SEM 3        //信号量集中的信号量数量
#define SEM_EMPTY 0         //empty、full、mutex信号量分别对应的索引
#define SEM_FULL 1
#define SEM_MUTEX 2

//缓冲区结构（循环队列）
typedef struct mybuffer
{
    int buff[BUF_LENGTH];
    int head;               //
    int tail;
    int is_empty;
}BUFFER;

//得到10以内的一个随机数，用以随机睡眠时间以及向缓冲区中加入的数据
int get_random_10()
{
    int t;
    srand((unsigned)(getpid() + time(NULL)));
    t = rand() % 10;
    return t;
}

//P操作
void p(int sem_id, int sem_num)
{
    struct sembuf xx;
    xx.sem_num = sem_num;
    xx.sem_op = -1;
    xx.sem_flg = 0;
    semop(sem_id, &xx, 1);
}

//V操作
void v(int sem_id, int sem_num)
{
    struct sembuf xx;
    xx.sem_num = sem_num;
    xx.sem_op = 1;
    xx.sem_flg = 0;
    semop(sem_id, &xx, 1);
}


int main(int argc, char * argv[])
{
    int i, j;
    int num_p = 0, num_c = 0;
    
    time_t now;
    pid_t pid_p, pid_c;
    
    //创建信号量集
    int sem_id = semget(SEM_KEY, NUM_OF_SEM, IPC_CREAT | 0660);
    if (sem_id == -1)
    {
        printf("Semget failed!\n");
        _Exit(1);
    }
    //自定义union semun结构
    union semun
    {
        int val;
        struct semd_ds* buf;
        unsigned short int* array;
        struct seminfo* _buf;
    };

    //初始化信号量集
    union semun sem_val;
    sem_val.val=BUF_LENGTH;
    semctl(sem_id,SEM_EMPTY,SETVAL,sem_val);     //信号量empty初始化为缓冲区长度
    sem_val.val=0;
    semctl(sem_id,SEM_FULL,SETVAL,sem_val);   //信号量full初始化为0
    sem_val.val=1;
    semctl(sem_id,SEM_MUTEX,SETVAL,sem_val);    //信号量mutex初始化为1
    
    //创建共享内存区
    int shm_id= shmget(SHM_KEY, sizeof(BUFFER), SHM_MODE|IPC_CREAT);
    if (shm_id < 0)
    {
        printf("Shmget failed!\n");
        exit(1);
    }
    //将共享内存区连接到当前进程的地址空间上
    BUFFER* shmaddr=shmat(shm_id, 0, 0);
    if (shmaddr == (void *)-1)
    {
        printf("Shmat failed!\n");
        _Exit(1);
    }
    //初始化缓冲区
    shmaddr->head = 0;
    shmaddr->tail = 0;
    shmaddr->is_empty = 1;
    int data,index,catch_length;
    //创建生产者进程
    while ((num_p++) < PRODUCER_NUM)
    {
        if ((pid_p = fork()) < 0)
        {
            printf("Fork failed!\n");
            exit(1);
        }
        if (pid_p == 0)
        {
            //将共享内存区连接到生产者进程的地址空间上
            if ((shmaddr = shmat(shm_id, 0, 0)) == (void *)-1)
            {
                printf("Shmat feiled!\n");
                exit(1);
            }
            //对于每个生产者，向缓冲区中写入数据
            for (i = 0; i < PRODUCER_TIMES; i++)
            {
                p(sem_id, SEM_EMPTY);
                data=get_random_10();
                sleep(data);
                p(sem_id, SEM_MUTEX);    //加锁
                shmaddr->buff[shmaddr->tail] = data;
                shmaddr->tail = (shmaddr->tail + 1) % BUF_LENGTH;
                shmaddr->is_empty = 0;
                now = time(NULL);
                printf("当前时间：%02d时%02d分%02d秒\n", localtime(&now)->tm_hour, localtime(&now)->tm_min, localtime(&now)->tm_sec);
                printf("生产者 %d 将数据 %d 放入缓冲区.\n", num_p, data);
                printf("当前缓冲区内的数据：\n");
                catch_length=(shmaddr->tail+BUF_LENGTH-shmaddr->head)%BUF_LENGTH;
                if(catch_length==0) catch_length+=BUF_LENGTH;
                for(j=0;j<catch_length;j++)
                {
                    index=(shmaddr->head+j)%BUF_LENGTH;
                    printf("%d ", shmaddr->buff[index]);
                }
                printf("\n\n");
                fflush(stdout);
                v(sem_id, SEM_MUTEX);    //解锁
                v(sem_id, SEM_FULL);
            }
            shmdt(shmaddr);
            exit(0);
        }
    }

    while (num_c++ < COMSUMER_NUM)
    {
        if ((pid_c = fork()) < 0)
        {
            printf("Fork failed!\n");
            exit(1);
        }
        //如果是子进程，开始创建消费者
        if (pid_c == 0)
        {
            if ((shmaddr = shmat(shm_id, 0, 0)) == (void *)-1)
            {
                printf("Shmat failed!\n");
                exit(1);
            }
            for (i = 0; i < CONSUMER_TIMES; i++)
            {
                p(sem_id, SEM_FULL);
                sleep(get_random_10());
                p(sem_id, SEM_MUTEX);       //加锁
                data = shmaddr->buff[shmaddr->head];
                shmaddr->head = (shmaddr->head + 1) % BUF_LENGTH;
                shmaddr->is_empty = (shmaddr->head == shmaddr->tail);
                now = time(NULL);
                printf("当前时间：%02d时%02d分%02d秒\n", localtime(&now)->tm_hour, localtime(&now)->tm_min, localtime(&now)->tm_sec);
                printf("消费者%d 将数据%d从缓冲区取出.\n",num_c,data);
                catch_length=(shmaddr->tail+BUF_LENGTH-shmaddr->head)%BUF_LENGTH;
                if(catch_length==0)
                    printf("当前缓冲区为空！\n\n");
                else
                {
                    printf("当前缓冲区内的数据：\n");
                    for(j=0;j<catch_length;j++)
                    {
                        index=(shmaddr->head+j)%BUF_LENGTH;
                        printf("%d ", shmaddr->buff[index]);
                    }
                    printf("\n\n");
                }
                fflush(stdout);
                v(sem_id, SEM_MUTEX);    //解锁
                v(sem_id, SEM_EMPTY);
            }
            shmdt(shmaddr);
            exit(0);
        }
    }
    
    //主控程序最后退出
    while(wait(0) != -1);
    shmdt(shmaddr);
    shmctl(shm_id, IPC_RMID, 0);
    semctl(sem_id, IPC_RMID, 0);
    printf("模拟结束！\n");
    fflush(stdout);
    exit(0);
}