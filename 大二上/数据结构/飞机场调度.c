// ConsoleApplication1.cpp: 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define Numway  100
int i;
typedef struct node
{
	int number, time;
	struct node*next;
}NODE;
int cheak(int a[Numway][3], int n)
{
	for (i = 1; i <= n; i++)
		if (a[i][1] != 0) return 1;
	return 0;
}
void stimulate(int waynum, int landtime, int takeofftime)
{
	int landplane = 0, takeoffplane = 0;//该次降落与起飞的飞机数量 
	int currenttime = 0;
	int runway[Numway][3] = { 0 };
	int landnum = 5000, takeoffnum = 0;//排列序号
	int waitland = 0, waittakeoff = 0;//降落与起飞的飞机分别的等待时间
	int countland = 0, counttakeoff = 0;//降落与起飞分别的飞机总数
	NODE *Headland = (NODE*)malloc(sizeof(NODE));
	Headland->next = NULL;
	NODE*Endland = Headland;
	NODE *Headtakeoff = (NODE*)malloc(sizeof(NODE));
	Headtakeoff->next = NULL;
	NODE*Endtakeoff = Headtakeoff;
	printf("Current Time: %4d\n", 0);
	while (1)
	{
		scanf("%d%d", &landplane, &takeoffplane);
		if (landplane >= 0 && takeoffplane >= 0)
		{
			countland += landplane;
			counttakeoff += takeoffplane;
			currenttime++;
			for (i = 0; i < landplane; i++)//将要降落的飞机放入等待序列
			{
				//printf("Landing plane has been put into waiting queue\n");
				Endland->number = ++landnum;
				Endland->time = currenttime;
				Endland->next = (NODE*)malloc(sizeof(NODE));
				Endland = Endland->next;
				Endland->next = NULL;
			}
			for (i = 0; i < takeoffplane; i++)//将要起飞的飞机放入等待序列
			{
				//printf("Takeing off plane has been put into waiting queue\n");
				Endtakeoff->number = ++takeoffnum;
				Endtakeoff->time = currenttime;
				Endtakeoff->next = (NODE*)malloc(sizeof(NODE));
				Endtakeoff = Endtakeoff->next;
				Endtakeoff->next = NULL;
			}
			for (i = 1; i <= waynum; i++)//将等待的飞机放入跑道
			{
				if (runway[i][0] != 0) continue;
				else
				{
					//printf("The waiting plane has been put into runway\n");
					if (Headland != Endland)
					{
						waitland += currenttime - Headland->time;
						runway[i][0] = Headland->number;
						//runway[i][1] = 0;
						//if (Headland->number > 5000)
						runway[i][2] += landtime;
						//else
						//runway[i][2] += takeofftime;
						printf("airplane %04d is ready to land on runway %02d\n", runway[i][0], i);
						NODE*ans = Headland;
						Headland = Headland->next;
						free(ans);
					}
					else if (Headtakeoff != Endtakeoff)
					{
						waittakeoff += currenttime - Headtakeoff->time;
						runway[i][0] = Headtakeoff->number;
						printf("airplane %04d is ready to takeoff on runway %02d\n", runway[i][0], i);
						//runway[i][1] = 1;
						//if (Headland->number < 5000)
						//runway[i][2] += landtime;
						//else
						runway[i][2] += takeofftime;
						NODE*ans = Headtakeoff;
						Headtakeoff = Headtakeoff->next;
						free(ans);
					}
					else break;
				}
			}
			printf("Current Time: %4d\n", currenttime);
			for (i = 1; i <= waynum; i++)
			{
				//printf("Add each time\n");
				if(runway[i][0]!=0)
				{
					runway[i][1]++;
					if (runway[i][0] > 5000 && runway[i][1] == landtime)
					{
						runway[i][1] = 0;
						runway[i][0] = 0;
						printf("runway %02d is free\n", i);
					}
					else if (runway[i][0] < 5000 && runway[i][1] == takeofftime)
					{
						runway[i][1] = 0;
						runway[i][0] = 0;
						printf("runway %02d is free\n", i);
					}
					else;
				}
			}
		}
		else
		{
			while (cheak(runway, waynum) || (Headland->next != NULL) || (Headtakeoff->next != NULL))
			{
				//printf("cheak:%d\n headland->next:%d\n headtakeoff:%d",cheak(runway,waynum),Headland->next,Headtakeoff->next);
				//if (cheak(runway, waynum)==0 && (Headland ->next==0) &&(Headtakeoff->next==0)) break;
				//printf("Cheak:%d\n", cheak(runway, waynum));
				//printf("Headlan!=Endland:%d\n", Headland->next);
				//printf("Headtakeoff!=Endtakeoff:%d\n", Headtakeoff->next);
				currenttime++;
				for (i = 1; i <= waynum; i++)//将等待的飞机放入跑道
				{
					if (runway[i][0] != 0);
					else
					{
						//printf("**The waiting plane has been put into runway\n");
						if (Headland != Endland)
						{
							waitland += currenttime - Headland->time;
							runway[i][0] = Headland->number;
							//runway[i][1] = 1;
							//if (Headland->number < 5000)
							runway[i][2] += landtime;
							//else
							//runway[i][2] += takeofftime;
							printf("airplane %04d is ready to land on runway %02d\n", runway[i][0], i);
							NODE*ans = Headland;
							Headland = Headland->next;
							free(ans);
						}
						else if (Headtakeoff != Endtakeoff)
						{
							waittakeoff += currenttime - Headtakeoff->time;
							runway[i][0] = Headtakeoff->number;
							//runway[i][1] = 1;
							//if (Headland->number < 5000)
							//runway[i][2] += landtime;
							//else
							runway[i][2] += takeofftime;
							printf("airplane %04d is ready to takeoff on runway %02d\n", runway[i][0], i);
							NODE*ans = Headtakeoff;
							Headtakeoff = Headtakeoff->next;
							free(ans);
						}
						else break;
					}
				}
				printf("Current Time: %4d\n", currenttime);
				for (i = 1; i <= waynum; i++)
				{
					//printf("**Add each time\n");
					if(runway[i][0]!=0)
					{
						runway[i][1]++;
						if (runway[i][0] > 5000 && runway[i][1] == landtime)
						{
							runway[i][1] = 0;
							runway[i][0] = 0;
							printf("runway %02d is free\n", i);
						}
						else if (runway[i][0] < 5000 && runway[i][1] == takeofftime)
						{
							runway[i][1] = 0;
							runway[i][0] = 0;
							printf("runway %02d is free\n", i);
						}
						else;
					}
				}
			}
			break;
		}
	}
	printf("simulation finished\n");
	printf("simulation time: %4d\n", currenttime);
	if (countland == 0)
		printf("average waiting time of landing: 0.0\n");
	else
			printf("average waiting time of landing: %4.1f\n", (double)waitland / countland);
	if (counttakeoff == 0)
		printf("average waiting time of takeoff: 0.0\n");
	else
		printf("average waiting time of takeoff: %4.1f\n", (double)waittakeoff / counttakeoff);
	for (i = 1; i <= waynum; i++)
		printf("runway %02d busy time: %4d\n", i, runway[i][2]);
	if (currenttime == 0 || waynum == 0)
		printf("runway average busy time percentage: 0.0%%\n");
	else
		printf("runway average busy time percentage: %4.1f%%\n", (double)(landtime*countland + takeofftime*counttakeoff) * 100 / (waynum*currenttime));
}
int main()
{
	int waynum = 0, landtime = 0, takeofftime = 0;
	scanf("%d%d%d", &waynum, &landtime, &takeofftime);
	stimulate(waynum, landtime, takeofftime);
	//system("pause");
	return 0;
}




