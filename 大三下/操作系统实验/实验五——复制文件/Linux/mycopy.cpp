#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <dirent.h>
#include <utime.h>
#include<sys/time.h>
#define buf_size 4096 //文件复制函数
#define MAX_PATH 260  //最大路径名长度
//文件复制
void copyFile(char *fsource, char *ftarget)
{    
    //打开原文件，返回文件描述符    
    int fd1 = open(fsource, O_RDONLY);    
    if (fd1 == -1)    
    {        
        printf("打开源文件失败!\n");  
        exit(0);  
    }     
    int fd2;    
    struct stat statbuf;    
    struct utimbuf timeby;    
    char BUFFER[buf_size];    
    int wordbit;    
    //将原文件的信息放入statbuf中    
    stat(fsource,&statbuf);    
    //创建新文件，返回文件描述符    
    fd2 = creat(ftarget,statbuf.st_mode);    
    if (fd2 == -1)    
    {        
        printf("创建目标文件失败!\n");   
        exit(0);    
    }   
    while((wordbit = read(fd1,BUFFER,buf_size)) > 0)    
    {   
        if (write(fd2,BUFFER,wordbit) != wordbit)//写入目标文件     
        {
            printf("写入错误!\n"); 
            exit(0);  
        }       
    }    
    timeby.actime = statbuf.st_atime;//修改时间属性    
    timeby.modtime = statbuf.st_mtime;   
    utime(ftarget,&timeby); 
    close(fd1);    
    close(fd2);
} 
//目录复制
void mycp(char *fsource,char *ftarget)
{    
    char source[MAX_PATH];   
    char target[MAX_PATH];    
    struct stat statbuf;    
    struct utimbuf timeby;    
    struct dirent *entry;    
    DIR *dir;    
    //DIR* dirT;
    strcpy(source,fsource);    
    strcpy(target,ftarget);    //打开目录，返回指向DIR结构的指针    
    dir = opendir(source);    
    if(opendir(target)==NULL)
    {
        stat(source,&statbuf);                   
        mkdir(target,statbuf.st_mode);
    }
    while((entry = readdir(dir)) != NULL)//读目录    
    {        
        if (strcmp(entry->d_name,".") == 0 || strcmp(entry->d_name,"..") == 0)        
        {            
            continue;        
        }     
        strcpy(source,fsource);            
        strcpy(target,ftarget);    
        strcat(source,"/");            
        strcat(source,entry->d_name);            
        strcat(target,"/");            
        strcat(target,entry->d_name);
        if (entry->d_type == 4)//如果是目录       
        {                     
            mycp(source,target);                  
        }
        else if(entry->d_type==10)  //如果是个符号链接
        {
            stat(source,&statbuf); 
            char buff[buf_size];
            int length=readlink(source,buff,MAX_PATH);
            //printf("link path:%s\n",buff);
            if(symlink(buff,target)==-1)
            {
                printf("软连接失败\n");
            }
            //timeby.actime = statbuf.st_atime;            
            //timeby.modtime = statbuf.st_mtime;
            //if(utime(target,&timeby)<0)
            //printf("link utime failed\n");   
            struct stat statbuff;
            lstat(source,&statbuff);
            struct timeval times[2];
            times[0].tv_sec=statbuff.st_atime;
            times[0].tv_usec=0;
            times[1].tv_sec=statbuff.st_mtime;
            times[1].tv_usec=0;
            lutimes(target,times);
        }        
        else//如果是文件，直接复制        
        {                    
            copyFile(source,target);//调用文件复制函数                   
        }    
    }
    //最后修改时间属性
    strcpy(source,fsource);    
    strcpy(target,ftarget);
    stat(source,&statbuf);            
    timeby.actime = statbuf.st_atime;            
    timeby.modtime = statbuf.st_mtime;            
    //修改文件的访问时间和修改时间			
    utime(target,&timeby);
} 
int main(int argc,char *argv[])
{	
    struct stat statbuf;     //stat结构	
    struct utimbuf timeby;	 //
    DIR *dir;  
    if (argc != 3)	
    {        
        printf("参数错误!\n");	
    }	
    else	
    {         
        if ((dir = opendir(argv[1])) == NULL)        
        {                
            printf("源文件打开错误!\n");        
            exit(0);
        }        
        if ((dir = opendir(argv[2])) == NULL)        
        {            
            stat(argv[1],&statbuf);//将源文件中的文件属性信息填入statbuf中            
            mkdir(argv[2],statbuf.st_mode);//创建目录			            
            timeby.actime = statbuf.st_atime;//文件数据的最后存取时间            
            timeby.modtime = statbuf.st_mtime;//文件数据的最后修改时间            
            utime(argv[2],&timeby);//用utime()函数修改目标文件的访问时间和修改时间       
        }        
        mycp(argv[1],argv[2]);//开始复制	
        printf("复制完成!\n");
    }	
    	
    return 0;
}
