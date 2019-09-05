#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<Windowsx.h>
#include<string.h>
#define buf_size 4096 
void copyFile(char * fsource, char * ftarget)
{
	WIN32_FIND_DATA lpfindfiledata;
	HANDLE hfind = FindFirstFile(fsource, &lpfindfiledata);
	//打开源文件
	HANDLE hsource = CreateFile(fsource, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	//创建目标文件
	HANDLE htarget = CreateFile(ftarget, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	//源文件的大小	
	if (SetFileTime(htarget, &lpfindfiledata.ftCreationTime, &lpfindfiledata.ftLastAccessTime, &lpfindfiledata.ftLastWriteTime) == 0) printf("设置文件时间属性失败\n");
	LONG size = lpfindfiledata.nFileSizeLow - lpfindfiledata.nFileSizeHigh;
	DWORD wordbit;
	//新建缓冲区，保存数据	
	int *BUFFER = new int[size];
	//源文件读数据	
	ReadFile(hsource, BUFFER, size, &wordbit, NULL);
	//目标文件写数据	
	WriteFile(htarget, BUFFER, size, &wordbit, NULL);
	//关闭句柄
	CloseHandle(hfind);
	CloseHandle(hsource);
	CloseHandle(htarget);
}
//将源目录信息复制到目标目录下
void mycp(char * fsource, char * ftarget)
{
	WIN32_FIND_DATA lpfindfiledata;
	WIN32_FIND_DATA lpfindfiledatatarget;
	char source[buf_size];
	char target[buf_size];
	lstrcpy(source, fsource);
	lstrcpy(target, ftarget);
	lstrcat(source, "\\*.*");
	lstrcat(target, "\\*.*");
	
	HANDLE hfind = FindFirstFile(source, &lpfindfiledata);
	HANDLE htarget= FindFirstFile(target, &lpfindfiledatatarget);
	
	if (hfind != INVALID_HANDLE_VALUE&&htarget!=INVALID_HANDLE_VALUE)
	{
		while (FindNextFile(hfind, &lpfindfiledata) != 0)
		{			
			memset(source, '0', sizeof(source));
			memset(target, '0', sizeof(target));
			lstrcpy(source, fsource);
			lstrcat(source, "\\");
			lstrcpy(target, ftarget);
			lstrcat(target, "\\");
			lstrcat(source, lpfindfiledata.cFileName);					
			lstrcat(target, lpfindfiledata.cFileName);
			if ((lpfindfiledata.dwFileAttributes) == 16)//判断是否为目录(若为目录FILE_ATTRIBUTE_DIRECTORY是16)			
			{
				//判断该目录是否当前目录或父目录，.表示当前目录，..表示父目录
				if ((strcmp(lpfindfiledata.cFileName, ".") != 0) && (strcmp(lpfindfiledata.cFileName, "..") != 0))
				{
					//如果既不是当前目录也不是父目录，则递归调用mycp()函数
					CreateDirectory(target, NULL);//为目标文件创建目录					
					mycp(source, target);//进入子目录复制		
					HANDLE sou = CreateFile(source, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL);
					HANDLE tar = CreateFile(target, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL);
					FILETIME create, access, change;
					GetFileTime(sou, &create, &access, &change);
					SetFileTime(tar, &create, &access, &change);
				}
			}
			else //如果是个文件就调用copyFile()复制
				copyFile(source, target);//直接调用文件复制函数				
		}
	}
	else
	{
		printf("查找指定文件路径的文件失败!\n");
	}
	//lstrcpy(source, fsource);
	//lstrcpy(target, ftarget);
	//lstrcat(source, "\\*.*");
	//lstrcat(target, "\\*.*");
	//HANDLE sou = CreateFile(source, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL);
	//HANDLE tar = CreateFile(target, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL);
	//FILETIME create, access, change;
	//GetFileTime(sou, &create, &access, &change);
	//SetFileTime(tar, &create, &access, &change);
}
int main(int argc, char *argv[])
{
	WIN32_FIND_DATA lpfindfiledata;
	if (argc != 3)
	{
		printf("参数错误!\n");
	}
	else
	{
		if (FindFirstFile(argv[1], &lpfindfiledata) == INVALID_HANDLE_VALUE)
		{
			printf("查找源文件路径失败!\n");
			exit(0);
		}
		if (FindFirstFile(argv[2], &lpfindfiledata) == INVALID_HANDLE_VALUE)
		{
			CreateDirectory(argv[2], NULL);//为目标文件创建目录		
		}
		mycp(argv[1], argv[2]);
		printf("复制完成!\n");
	}
	return 0;
}
