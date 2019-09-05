#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define len1 100005
#define len2 1005
struct type
{
	int rank,time;
}course[len1];
int cmp1(const void*a,const void*b)
{
	return (struct type*)a->time>(struct type*)b->time?1:-1; 
 } 
int cmp2(const void*a,const void*b)
{
	return *(int*)a>*(int*)b;
}
int car[len2];
int main()
{
	int T, n, m, mm, hh, k,i;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		for (i = 0; i < n; i++)
		{
			scanf("%d:%d%d", &hh, &mm, &k);
			course[i].time = hh * 60 + mm + 45 * k + 10 * (k - 1)+15;
			course[i].rank = i+1;
		}
		for (i = 0; i < m; i++)
		{
			scanf("%d:%d", &hh, &mm);
			car[i] = hh * 60 + mm;
		}
		qsort(course,n,sizeof(course[0]),cmp1);
		qsort(car,m,sizeof(car[0]),cmp2);
		int j=0;
		for(i=0,j=0;i<n,j<m;)
		{
			if(course[i].time >car[j]) j++;
			else 
			{
				course[i].time=car[j]-course[i].time;
				i++;
			} 
		}
		while(i<n)
		{
			course[i].time=-1;
			i++;
		}
		if(course[0].time==-1) printf("poor Ff!\n");
		else 
		{
			struct type flag=course[0];	
			for(i=1;i<n;i++)
			{
				if(course[i].time<flag.time) flag=course[i];
				else if(course[i].time==flag.time&&course[i].rank<flag.rank) flag=course[i];
				else ;
			}
			printf("%d\n",flag.rank);
		}
	}
}
