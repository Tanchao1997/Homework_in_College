// ConsoleApplication10.cpp: �������̨Ӧ�ó������ڵ㡣
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
	int theory_mintime; 
}store[MAX_SIZE];//��һ���ṹ�洢�������ͷš��ӹ�������ʱ��
int cmp(struct node a, struct node b)
{
	if (a.theory_mintime == b.theory_mintime)
	{
		if (a.dl == b.dl)
			return a.rtime < b.rtime;
		else return a.dl < b.dl;
	}
	else
		return a.theory_mintime < b.theory_mintime;
}
int main()
{
	int num;
	scanf("%d", &num);//�����ж��ٸ�������Ҫ�ӹ�
	for (int i = 0; i < num; i++)
		scanf("%d%d%d", &store[i].rtime, &store[i].ptime, &store[i].dl);
	for(int i=0;i<num;i++)
		store[i].theory_mintime=store[i].rtime+store[i].ptime;
	sort(store, store + num, cmp);//�Թ������Ȱ������������ʱ���С���������������������ʱ����ͬ��Խ���ʱ���С�������������߶���ͬ����ͷ�ʱ���С�������� 
	int loc = 0;//��¼�������ҵ�һ����δ�ӹ��Ĺ���λ�� 
	int addtime = 0;//��¼�ӳ�ʱ���ܺ�
	int currenttime = 0;//��¼��ǰ�Ѿ��ӹ��Ĺ���ʱ���ܺ�
	while (loc < num)
	{
		if (store[loc].rtime <= currenttime)//����ù����ڵ�ǰʱ���Ѿ��ͷţ���ӹ��ù��� 
		{
			printf("%d %d\n", store[loc].rtime, store[loc].dl);
			currenttime += store[loc].ptime;
			addtime += max(currenttime - store[loc].dl, 0);//��¼��ǰ�Ѽӹ��Ĺ����ӳ�ʱ���ܺ� 
			store[loc].dl = 0;//�Ѹù�������ʱ����Ϊ0����ʾ�Ѽӹ� 
			while (store[loc].dl == 0) loc++;//Ѱ����һ��δ�ӹ��Ĺ���λ�� 
		}
		else//����ù����ڵ�ǰʱ�仹δ�ͷţ�����Ѱ��ֱ���ҵ���ǰʱ���Ѿ��ͷ�����δ�ӹ��Ĺ��� 
		{
			int tem = loc + 1;
			while (store[tem].dl == 0 || store[tem].rtime > currenttime) tem++;//Ѱ��ֱ���ҵ���ǰʱ���Ѿ��ͷ�����δ�ӹ��Ĺ���λ�ò�����ӹ� 
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
