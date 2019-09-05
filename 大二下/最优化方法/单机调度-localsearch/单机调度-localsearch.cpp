// ConsoleApplication10.cpp: 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include<algorithm>
#include<cstdio>
#include<time.h>
#include<cstring>
using namespace std;
#define MAX_SIZE 100
#define MAX_INT 2e9//定义一个最大上限作为minresult的初始值
int sequence[MAX_SIZE] = { 0 };//保存产生的随机序列和变化后的序列 
#define random(x) (rand()%x)//宏定义产生0-x的随机数  
typedef struct job//定义工件结构 
{
	int rtime;
	int ptime;
	int dl;
}JOB;
JOB jobs[MAX_SIZE];//存储工件信息 
void generate_randomlist(int N)//生成0-N的随机序列 
{
	memset(sequence,0,sizeof(sequence)); 
	int k = 1;
	while (k <= N)
	{
		int m = random(N);
		if (sequence[m] <= 0)
		{
			sequence[m] = k;//此时表示第m个工件是第k个加工 
			k++;
		}
	}
	int tem[MAX_SIZE] = { 0 };//通过中间数组tem将sequence数组转换过来
	for (int i = 0; i < N; i++)
		tem[sequence[i] - 1] = i;
	for (int i = 0; i < N; i++)//转化后表示第i个加工的元件标号为sequence[i] 
		sequence[i] = tem[i];
}
int time_calculate(int N)//对一组序列计算延时
{
	int time = 0;
	int delay_time = 0;
	for (int i = 0; i < N; i++)
	{
		if (jobs[sequence[i]].rtime > time)
		{
			time = jobs[sequence[i]].rtime + jobs[sequence[i]].ptime;//若当前时间该工件还未释放，等待直到释放
			delay_time += max(time - jobs[sequence[i]].dl, 0);
		}
		else
		{
			time += jobs[sequence[i]].ptime;
			delay_time += max(time - jobs[sequence[i]].dl,0);
		}
	}
	return delay_time;
}
int localtest(int N)//根据一次随机序列得到一个解 
{
	for(int i=0;i<N;i++)
	printf("%d ",sequence[i]);
	printf("\n");
	int last_mintime=MAX_INT   ,mintime=time_calculate(N);
	printf("initial_mintime=%d\n", mintime);
	while (last_mintime != mintime)//若此次优化后的最小时间和优化之前一样则表明达到局部最优，停止优化，否则继续优化 
	{
		last_mintime = mintime;//last_mintime表示优化之前的延迟时间，mintime表示优化之后的延迟时间
		for(int i=0;i<N;i++)
		{
			int flag;
			flag=sequence[i];
			sequence[i]=sequence[(i+1)%N];
			sequence[(i+1)%N]=flag;//交换相邻的两个工件的加工顺序 
			if (time_calculate(N) < mintime)
			{
				mintime = time_calculate(N);//若转换到领域后总延迟时间减小，赋值给mintime
				//printf("optimize:%d\n", mintime);
			}
			else //若总延迟时间并没减小，恢复到原来的加工序列 
			{
				flag=sequence[i];
				sequence[i]=sequence[(i+1)%N];
				sequence[(i+1)%N]=flag;
			}
			
		} 
	}
}
int main()
{
	int N;
	int result[10000] = { 0 };//存储每次局部最优结果 
	scanf("%d", &N);
	for (int i = 0; i<N; i++)
		scanf("%d%d%d", &jobs[i].rtime, &jobs[i].ptime, &jobs[i].dl);
	int times = 10000;//控制跳出局部最优的次数
	int count = 0;
	printf("局部搜索开始！\n");
	while (count<times)
	{
		generate_randomlist(N);//产生一个随机序列 
		//printf("case %d start\n", count);
		result[count] = localtest(N);
		//printf("case %d end\n", count);
		count++;
	}
	printf("局部搜索完成！\n");
	int min=MAX_INT;//找出多次局部搜索的最小值作为全局最优值 
	for(int i=0;i<times;i++)
		if(result[i]<min) min=result[i];
	printf("%d\n", min);
	system("pause");
}
