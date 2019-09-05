#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define len 1000005
int a[len] = { 0 }; 
int main()
{
	int n, i;
	while (scanf("%d", &n) != EOF)
	{
		memset(a, 0, sizeof(a));
		int count = 0,add=0;
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		for (i = n - 1; i >= 0;)
		{
			if (a[i] >= 0)
			{
				count++;
				i--;
			}
			else
			{
				add = a[i];
				while (add < 0) add += a[--i];
				count++;
				i--;
			}
		}
		printf("%d\n", count);
	}
	//system("pause");
}
