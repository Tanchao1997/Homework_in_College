// ConsoleApplication10.cpp: 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include<algorithm>
#include<cstdio>
#define MAX_SIZE 100
//#define _CRT_SECURE_NO_DEPRECATE
using namespace std;
struct node
{
	int rtime;
	int ptime;
	int dl;
}store[MAX_SIZE];//用一个结构存储工件的释放、加工、交货时间
int cmp(struct node a, struct node b)
{
	if (a.ptime == b.ptime)
	{
		if (a.dl == b.dl)
			return a.rtime < b.rtime;
		else return a.dl < b.dl;
	}
	else
		return a.ptime < b.ptime;
}
int main()
{
	int num;
	scanf("%d", &num);//输入有多少个工件需要加工
	for (int i = 0; i < num; i++)
		scanf("%d%d%d", &store[i].rtime, &store[i].ptime, &store[i].dl);
	sort(store, store + num, cmp);//对工件首先按加工时间从小到大排序，若加工时间相同则对交货时间从小到大排序，若两者都相同则对释放时间从小到大排序 
	int loc = 0;//记录从左往右第一个还未加工的工件位置 
	int addtime = 0;//记录延迟时间总和
	int currenttime = 0;//记录当前已经加工的工件时间总和
	while (loc < num)
	{
		if (store[loc].rtime <= currenttime)//如果该工件在当前时间已经释放，则加工该工件 
		{
			printf("%d %d\n", store[loc].rtime, store[loc].dl);
			currenttime += store[loc].ptime;
			addtime += max(currenttime - store[loc].dl, 0);//记录当前已加工的工件延迟时间总和 
			store[loc].dl = 0;//把该工件交货时间置为0，表示已加工 
			while (store[loc].dl == 0) loc++;//寻找下一个未加工的工件位置 
		}
		else//如果该工件在当前时间还未释放，往后寻找直到找到当前时间已经释放且仍未加工的工件 
		{
			int tem = loc + 1;
			while (store[tem].dl == 0 || store[tem].rtime > currenttime) tem++;//寻找直到找到当前时间已经释放且仍未加工的工件位置并对其加工 
			printf("%d %d\n", store[tem].rtime, store[tem].dl);
			currenttime += store[tem].ptime;
			addtime += max(currenttime - store[tem].dl, 0);
			store[tem].dl = 0;
		}
	}
	printf("%d\n", addtime);
	//system("pause");
	return 0;
}
