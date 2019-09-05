#include <iostream>
#include <algorithm>
#include <cstring>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <time.h>
using namespace std;
unsigned seed = (unsigned)time(0);//原型：void srand(unsigned seed);
#define MAX_JOBS 30  //工件数量上限
#define MAX_MACHINE 10//机器数量上限
#define ANT_NUM 30   //蚁群数量
#define TMAC 1000   //迭代最大次数
#define ROU 0.5     //误差大小
#define ALPHA 1     // 信息素重要程度的参数
#define BETA 4     // 启发式因子重要程度的参数
#define Q 100 //信息素残留参数
int jobs_number, machine_number;
int process_time[MAX_JOBS][MAX_MACHINE] = { 0 };//time[i][j]表示第i个工件在第j个机器上i上加工的时间
const int maxn = 100;
double info[maxn][maxn];  //信息素矩阵
						  //double E[CITY_NUM][CITY_NUM]; //启发因子矩阵
						  //int vis[CITY_NUM][CITY_NUM];
double Bestlength;
//double ans[CITY_NUM];
const double mmax = 10e9;
//返回指定范围内的随机整数
int rnd(int nLow, int nUpper)
{
	return nLow + (nUpper - nLow)*rand() / (RAND_MAX + 1);
}
//返回指定范围内的随机浮点数
double rnd(double dbLow, double dbUpper)
{
	double dbTemp = rand() / ((double)RAND_MAX + 1.0);
	return dbLow + dbTemp*(dbUpper - dbLow);
}
//返回浮点数四舍五入取整后的浮点数
double ROUND(double dbA)
{
	return (double)((int)(dbA + 0.5));
}
int findMax(int* a, int n, int m)//找到当前加工最多的时间
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
	int Path[MAX_JOBS];  //蚂蚁走的路径
	int length;  //路径总时间
	int vis[MAX_JOBS]; //走过工件标记
	int cur_jobno;   //当前工件
	int moved_cnt;    //已走的数量
					  //初始化
	void Init()
	{
		memset(vis, 0, sizeof(vis));
		cur_jobno = rnd(0, jobs_number);//随机选择一个出发工件
		length = process_time[cur_jobno][0];
		Path[0] = cur_jobno;
		vis[cur_jobno] = 1;
		moved_cnt = 1;
		//printf("Init %d \n", cur_jobno);
	}
	//选择下一个工件
	//返回值 为城市编号
	int chooseNextJob()
	{
		int nSelectedJob = -1; //返回结果，先暂时把其设置为-1
								//计算当前工件和没去过的工件之间的信息素总和
		double dbTotal = 0.0;
		double prob[MAX_JOBS]; //保存各个工件被选中的概率
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
		//进行轮盘选择
		double dbTemp = 0.0;
		if (dbTotal > 0.0) //总的信息素值大于0
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
		//如果工件间的信息素非常小 ( 小到比double能够表示的最小的数字还要小 )
		//出现这种情况，就把第一个没去过的工件作为返回结果
		if (nSelectedJob == -1)
		{
			for (int i = 0; i < jobs_number; i++)
			{
				if (!vis[i]) //工件没去过
				{
					nSelectedJob = i;
					break;
				}
			}
		}
		return nSelectedJob;
	}
	//蚂蚁在工件间移动
	void Move()
	{
		int nCityno = chooseNextJob();//选择下一个工件
		Path[moved_cnt] = nCityno;//保存蚂蚁走的路径
		vis[nCityno] = 1;//把这个工件设置成已经去过
		cur_jobno = nCityno;
		//更新已走路径长度                           
		length += findMax(Path, moved_cnt, 0);
		moved_cnt++;
	}
	//蚂蚁进行搜索一次
	void Search()
	{
		Init();
		//如果蚂蚁去过的工件数量小于工件数量，就继续移动
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
	Ant ants[ANT_NUM];  //定义一群蚂蚁
	Ant ant_best;       //保存最好结果的蚂蚁
	void Init()
	{
		//初始化为最大值
		ant_best.length = mmax;
		//初始化环境信息素
		puts("init info");
		for (int i = 0; i<jobs_number; i++)
		{
			for (int j = 0; j<jobs_number; j++)
			{
				info[i][j] = 1.0;
			}
		}
	}
	//更新信息素,当前每条路上的信息素等于过去保留的信息素
	//加上每个蚂蚁这次走过去剩下的信息素
	void Updateinfo()
	{
		//puts("update info");
		double tmpinfo[MAX_JOBS][MAX_JOBS];
		memset(tmpinfo, 0, sizeof(tmpinfo));
		int m = 0;
		int n = 0;
		//遍历每只蚂蚁
		for (int i = 0; i < ANT_NUM; i++) {
			for (int j = 1; j < jobs_number; j++)
			{
				m = ants[i].Path[j];
				n = ants[i].Path[j - 1];
				//printf("%d %d\n", m, n);
				tmpinfo[n][m] = tmpinfo[n][m] + Q / ants[i].length;
				tmpinfo[m][n] = tmpinfo[n][m];
			}
			//最后工件和开始工件之间的信息素
			n = ants[i].Path[0];
			tmpinfo[n][m] = tmpinfo[n][m] + Q / ants[i].length;
			tmpinfo[m][n] = tmpinfo[n][m];
		}
		//更新环境信息素
		for (int i = 0; i < jobs_number; i++)
		{
			for (int j = 0; j < jobs_number; j++) {
				//最新的环境信息素 = 留存的信息素 + 新留下的信息素
				info[i][j] = info[i][j] * ROU + tmpinfo[i][j];
			}
		}
	}
	//寻找路径，迭代TMAC次
	void Search()
	{
		for (int i = 0; i < TMAC; i++) {
			printf("current iteration times %d\n", i);
			for (int j = 0; j < ANT_NUM; j++) {
				ants[j].Search();
			}
			//保存最佳结果
			for (int j = 0; j < ANT_NUM; j++) {
				if (ant_best.length > ants[j].length) {
					ant_best = ants[j];
				}
			}
			//更新环境信息素
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
	//初始化蚁群
	tsp.Init();
	//开始查找
	tsp.Search();
	printf("complete time:%d\n", tsp.ant_best.length);
	return 0;
}
