#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define len 100005
long long loca[len] = { 0 }, locl[len] = { 0 };
int cmp(const void*a, const void*b)
{
	return *(int*)a > *(int*)b;
}
int main()
{
	long long n,i;
	long long distance = 0;
	scanf("%lld", &n);
	for (i = 0; i < n; i++)
		scanf("%lld%lld", &loca[i],&locl[i]);
	qsort(loca, n, sizeof(loca[0]), cmp);
	qsort(locl, n, sizeof(locl[0]),cmp);
	for (i = 0; 2*i+1 < n; i++)
	{
		distance += (loca[n - i - 1] - loca[i]) + (locl[n - i - 1] - locl[i]);
	}
	printf("%lld\n", distance);
}
