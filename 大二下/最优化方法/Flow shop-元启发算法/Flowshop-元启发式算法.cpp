#include <iostream>
#include <algorithm>
#include <cstring>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <time.h>
using namespace std;
unsigned seed = (unsigned)time(0);//ԭ�ͣ�void srand(unsigned seed);
#define MAX_JOBS 30  //������������
#define MAX_MACHINE 10//������������
#define ANT_NUM 30   //��Ⱥ����
#define TMAC 1000   //����������
#define ROU 0.5     //����С
#define ALPHA 1     // ��Ϣ����Ҫ�̶ȵĲ���
#define BETA 4     // ����ʽ������Ҫ�̶ȵĲ���
#define Q 100 //��Ϣ�ز�������
int jobs_number, machine_number;
int process_time[MAX_JOBS][MAX_MACHINE] = { 0 };//time[i][j]��ʾ��i�������ڵ�j��������i�ϼӹ���ʱ��
const int maxn = 100;
double info[maxn][maxn];  //��Ϣ�ؾ���
						  //double E[CITY_NUM][CITY_NUM]; //�������Ӿ���
						  //int vis[CITY_NUM][CITY_NUM];
double Bestlength;
//double ans[CITY_NUM];
const double mmax = 10e9;
//����ָ����Χ�ڵ��������
int rnd(int nLow, int nUpper)
{
	return nLow + (nUpper - nLow)*rand() / (RAND_MAX + 1);
}
//����ָ����Χ�ڵ����������
double rnd(double dbLow, double dbUpper)
{
	double dbTemp = rand() / ((double)RAND_MAX + 1.0);
	return dbLow + dbTemp*(dbUpper - dbLow);
}
//���ظ�������������ȡ����ĸ�����
double ROUND(double dbA)
{
	return (double)((int)(dbA + 0.5));
}
int findMax(int* a, int n, int m)//�ҵ���ǰ�ӹ�����ʱ��
{
	int max = 0;
	if (n <= machine_number)
		for (int i = n - 1; i >= 0; i--)
		{
			if (process_time[a[i]][n - i + m] > max) max = process_time[a[i]][n - i + m];
		}
	else
		for (int i = n - 1; i >= n - machine_number; i--)
		{
			if (process_time[a[i]][n - i + m] > max) max = process_time[a[i]][n - i + m];
		}
	return max;
}
struct Ant
{
	int Path[MAX_JOBS];  //�����ߵ�·��
	int length;  //·����ʱ��
	int vis[MAX_JOBS]; //�߹��������
	int cur_jobno;   //��ǰ����
	int moved_cnt;    //���ߵ�����
					  //��ʼ��
	void Init()
	{
		memset(vis, 0, sizeof(vis));
		cur_jobno = rnd(0, jobs_number);//���ѡ��һ����������
		length = process_time[cur_jobno][0];
		Path[0] = cur_jobno;
		vis[cur_jobno] = 1;
		moved_cnt = 1;
		//printf("Init %d \n", cur_jobno);
	}
	//ѡ����һ������
	//����ֵ Ϊ���б��
	int chooseNextJob()
	{
		int nSelectedJob = -1; //���ؽ��������ʱ��������Ϊ-1
								//���㵱ǰ������ûȥ���Ĺ���֮�����Ϣ���ܺ�
		double dbTotal = 0.0;
		double prob[MAX_JOBS]; //�������������ѡ�еĸ���
		for (int i = 0; i < jobs_number; i++)
		{
			if (!vis[i])
			{
				prob[i] = pow(info[cur_jobno][i], ALPHA)
					*pow(1.0 / abs(process_time[cur_jobno][2] - process_time[i][1]), BETA);
				dbTotal += prob[i];
			}
			else
			{
				prob[i] = 0;
			}
		}
		//��������ѡ��
		double dbTemp = 0.0;
		if (dbTotal > 0.0) //�ܵ���Ϣ��ֵ����0
		{
			dbTemp = rnd(0.0, dbTotal);
			for (int i = 0; i < jobs_number; i++)
			{
				if (!vis[i])
				{
					dbTemp -= prob[i];
					if (dbTemp < 0.0)
					{
						nSelectedJob = i;
						break;
					}
				}
			}
		}
		//������������Ϣ�طǳ�С ( С����double�ܹ���ʾ����С�����ֻ�ҪС )
		//��������������Ͱѵ�һ��ûȥ���Ĺ�����Ϊ���ؽ��
		if (nSelectedJob == -1)
		{
			for (int i = 0; i < jobs_number; i++)
			{
				if (!vis[i]) //����ûȥ��
				{
					nSelectedJob = i;
					break;
				}
			}
		}
		return nSelectedJob;
	}
	//�����ڹ������ƶ�
	void Move()
	{
		int nCityno = chooseNextJob();//ѡ����һ������
		Path[moved_cnt] = nCityno;//���������ߵ�·��
		vis[nCityno] = 1;//������������ó��Ѿ�ȥ��
		cur_jobno = nCityno;
		//��������·������                           
		length += findMax(Path, moved_cnt, 0);
		moved_cnt++;
	}
	//���Ͻ�������һ��
	void Search()
	{
		Init();
		//�������ȥ���Ĺ�������С�ڹ����������ͼ����ƶ�
		while (moved_cnt < jobs_number)
		{
			Move();
		}
		for (int i = machine_number; i>0; i--)
			length += findMax(Path, i, machine_number - i);
	}
};
struct TSP
{
	Ant ants[ANT_NUM];  //����һȺ����
	Ant ant_best;       //������ý��������
	void Init()
	{
		//��ʼ��Ϊ���ֵ
		ant_best.length = mmax;
		//��ʼ��������Ϣ��
		puts("init info");
		for (int i = 0; i<jobs_number; i++)
		{
			for (int j = 0; j<jobs_number; j++)
			{
				info[i][j] = 1.0;
			}
		}
	}
	//������Ϣ��,��ǰÿ��·�ϵ���Ϣ�ص��ڹ�ȥ��������Ϣ��
	//����ÿ����������߹�ȥʣ�µ���Ϣ��
	void Updateinfo()
	{
		//puts("update info");
		double tmpinfo[MAX_JOBS][MAX_JOBS];
		memset(tmpinfo, 0, sizeof(tmpinfo));
		int m = 0;
		int n = 0;
		//����ÿֻ����
		for (int i = 0; i < ANT_NUM; i++) {
			for (int j = 1; j < jobs_number; j++)
			{
				m = ants[i].Path[j];
				n = ants[i].Path[j - 1];
				//printf("%d %d\n", m, n);
				tmpinfo[n][m] = tmpinfo[n][m] + Q / ants[i].length;
				tmpinfo[m][n] = tmpinfo[n][m];
			}
			//��󹤼��Ϳ�ʼ����֮�����Ϣ��
			n = ants[i].Path[0];
			tmpinfo[n][m] = tmpinfo[n][m] + Q / ants[i].length;
			tmpinfo[m][n] = tmpinfo[n][m];
		}
		//���»�����Ϣ��
		for (int i = 0; i < jobs_number; i++)
		{
			for (int j = 0; j < jobs_number; j++) {
				//���µĻ�����Ϣ�� = �������Ϣ�� + �����µ���Ϣ��
				info[i][j] = info[i][j] * ROU + tmpinfo[i][j];
			}
		}
	}
	//Ѱ��·��������TMAC��
	void Search()
	{
		for (int i = 0; i < TMAC; i++) {
			printf("current iteration times %d\n", i);
			for (int j = 0; j < ANT_NUM; j++) {
				ants[j].Search();
			}
			//������ѽ��
			for (int j = 0; j < ANT_NUM; j++) {
				if (ant_best.length > ants[j].length) {
					ant_best = ants[j];
				}
			}
			//���»�����Ϣ��
			Updateinfo();
			printf("current minimum time %d\n", ant_best.length);
		}
	}
};
int main()
{
	scanf("%d%d", &jobs_number, &machine_number);
	int ingore;
	for (int i = 1; i <= jobs_number; i++)
		for (int j = 1; j <= machine_number; j++)
			scanf("%d%d", &ingore, &process_time[i][j]);
	srand(seed);
	TSP tsp;
	//��ʼ����Ⱥ
	tsp.Init();
	//��ʼ����
	tsp.Search();
	printf("complete time:%d\n", tsp.ant_best.length);
	return 0;
}
