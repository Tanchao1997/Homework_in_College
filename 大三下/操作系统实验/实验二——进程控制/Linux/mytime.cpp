#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<sys/wait.h>
#include<sys/time.h>
#include<sys/types.h>
#include<unistd.h> 
using namespace std;
int main(int argc, char **argv)
{	
    //char* const env_list[]={"USER=root","PATH=/home/new/test1/OS_experiments",0};
    struct timeval time_start;	struct timeval time_end;	
    pid_t pid;	
    pid = fork();	
    gettimeofday(&time_start,NULL);	
    if (pid < 0)		
    {		
        printf("Create faild!\n");		
        exit(0);	
    }	
    else if (pid == 0)	
    {		
        printf("Create sucess\n");		
        //cout<<"mytime:"<<endl;
        //cout<<"argc:"<<argc<<endl;
        //for(int i=0;i<argc;i++)
	    //cout<<"argv["<<i<<"]:"<<argv[i]<<endl;
        //cout<<"argv[2]==NULL:"<<(argv[2]==NULL)<<endl;
        if(argv[2]==NULL)	
            execl(argv[1],argv[1],NULL);
        else 
            execl(argv[1],argv[1],argv[2],NULL);
    }	
    else	
    {					
        wait(NULL);	//等待子进程结束		
        gettimeofday(&time_end,NULL);
        long time_sec=time_end.tv_sec - time_start.tv_sec;
        long time_usec=time_end.tv_usec - time_start.tv_usec;
        if(time_usec<0)
        {
            time_sec-=1;
            time_usec+=1000000;
        }
        long time_msec=time_usec%1000;
        time_usec/=1000;		
        printf("Program running time：%lds%ldms%ldus\n",time_sec,time_msec,time_usec);	
    }	
            return 0;
}
