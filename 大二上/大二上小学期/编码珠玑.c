#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define len 402
void transform(char*s, int*a)
{
	int point = 0, i;
	while (s[point] != '.'&&point<strlen(s)) point++;
	for (i = point - 1; i >= 0; i--)
		a[400 + i - point + 1] = (int)s[i] - 48;
	for (i = point + 1; i < strlen(s); i++)
		a[400 + i - point] = (int)s[i] - 48;
}//将字符串转换为整数数组
int main()
{
	char s1[len] = { '0' }, s2[len] = { '0' };
	int i = 0, j = 0, aftra1[len * 2] = { 0 }, aftra2[len * 2] = { 0 }, result[len * 2] = { 0 };
	scanf("%s%s", s1, s2);
	transform(s1, aftra1);
	transform(s2, aftra2);
	for (i = 0; i <= 800; i++)
		printf("%d", result[i]);
	printf("\n");
	for (i = 0; i <= 800; i++)
		printf("%d", aftra1[i]);
	printf("\n");
	for (i = 0; i <= 800; i++)
		printf("%d", aftra2[i]);
	printf("\n");
	for (i = 800; i >= 0; i--)
	{
		result[i] += aftra1[i] + aftra2[i];
		if (result[i] >= 10)
		{
			result[i] -= 10;
			result[i - 1]++;
		}
	}
	for (i = 0; i <= 800; i++)
		printf("%d", result[i]);
	printf("\n");
	printf("%d\n",result[400]);
	while (result[i] == 0&&i<=400) i++;
	if (i > 400) printf("%d", 0);
	else
		for (; i <= 400; i++)
			printf("%d", result[i]);
	i = 800;
	while (result[i] == 0&&i>400) i--;
	if (i > 400)
	{
		printf(".");
		for (j = 401; j <= i; j++)
			printf("%d", result[j]);
	}
	printf("\n");
}
