// ConsoleApplication10.cpp: �������̨Ӧ�ó������ڵ㡣
//

//#include "stdafx.h"
#include<algorithm>
#include<cstdio>
#include<time.h>
#include<cstring>
using namespace std;
#define MAX_SIZE 100
#define MAX_INT 2e9//����һ�����������Ϊminresult�ĳ�ʼֵ
int sequence[MAX_SIZE] = { 0 };//���������������кͱ仯������� 
#define random(x) (rand()%x)//�궨�����0-x�������  
typedef struct job//���幤���ṹ 
{
	int rtime;
	int ptime;
	int dl;
}JOB;
JOB jobs[MAX_SIZE];//�洢������Ϣ 
void generate_randomlist(int N)//����0-N��������� 
{
	memset(sequence,0,sizeof(sequence)); 
	int k = 1;
	while (k <= N)
	{
		int m = random(N);
		if (sequence[m] <= 0)
		{
			sequence[m] = k;//��ʱ��ʾ��m�������ǵ�k���ӹ� 
			k++;
		}
	}
	int tem[MAX_SIZE] = { 0 };//ͨ���м�����tem��sequence����ת������
	for (int i = 0; i < N; i++)
		tem[sequence[i] - 1] = i;
	for (int i = 0; i < N; i++)//ת�����ʾ��i���ӹ���Ԫ�����Ϊsequence[i] 
		sequence[i] = tem[i];
}
int time_calculate(int N)//��һ�����м�����ʱ
{
	int time = 0;
	int delay_time = 0;
	for (int i = 0; i < N; i++)
	{
		if (jobs[sequence[i]].rtime > time)
		{
			time = jobs[sequence[i]].rtime + jobs[sequence[i]].ptime;//����ǰʱ��ù�����δ�ͷţ��ȴ�ֱ���ͷ�
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
int localtest(int N)//����һ��������еõ�һ���� 
{
	for(int i=0;i<N;i++)
	printf("%d ",sequence[i]);
	printf("\n");
	int last_mintime=MAX_INT   ,mintime=time_calculate(N);
	printf("initial_mintime=%d\n", mintime);
	while (last_mintime != mintime)//���˴��Ż������Сʱ����Ż�֮ǰһ��������ﵽ�ֲ����ţ�ֹͣ�Ż�����������Ż� 
	{
		last_mintime = mintime;//last_mintime��ʾ�Ż�֮ǰ���ӳ�ʱ�䣬mintime��ʾ�Ż�֮����ӳ�ʱ��
		for(int i=0;i<N;i++)
		{
			int flag;
			flag=sequence[i];
			sequence[i]=sequence[(i+1)%N];
			sequence[(i+1)%N]=flag;//�������ڵ����������ļӹ�˳�� 
			if (time_calculate(N) < mintime)
			{
				mintime = time_calculate(N);//��ת������������ӳ�ʱ���С����ֵ��mintime
				//printf("optimize:%d\n", mintime);
			}
			else //�����ӳ�ʱ�䲢û��С���ָ���ԭ���ļӹ����� 
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
	int result[10000] = { 0 };//�洢ÿ�ξֲ����Ž�� 
	scanf("%d", &N);
	for (int i = 0; i<N; i++)
		scanf("%d%d%d", &jobs[i].rtime, &jobs[i].ptime, &jobs[i].dl);
	int times = 10000;//���������ֲ����ŵĴ���
	int count = 0;
	printf("�ֲ�������ʼ��\n");
	while (count<times)
	{
		generate_randomlist(N);//����һ��������� 
		//printf("case %d start\n", count);
		result[count] = localtest(N);
		//printf("case %d end\n", count);
		count++;
	}
	printf("�ֲ�������ɣ�\n");
	int min=MAX_INT;//�ҳ���ξֲ���������Сֵ��Ϊȫ������ֵ 
	for(int i=0;i<times;i++)
		if(result[i]<min) min=result[i];
	printf("%d\n", min);
	system("pause");
}
