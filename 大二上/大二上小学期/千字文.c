#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define len 65536
int count[len] = { 0 };
int repeat(int*a, int n)
{
	long i;
	for (i = 128; i < n; i++)
		if (a[i] > 1) return 1;
	return 0;
}
int main()
{
	unsigned char word[3];
	long i;
	while ((word[0] = getchar()) != 255)
	{
		//printf("%d\n",word[0]);
		if (word[0] < 128)
			;
		else if (word[0] >= 192 && word[0] < 224)
		{
			word[1] = getchar();
			count[word[0] * 64 + word[1] - 12416]++;
		}
		else
		{
			word[1] = getchar();
			word[2] = getchar();
			count[word[0] * 4096 + word[1] * 64 + word[2] - 925824]++;
		}
	}
	//printf("over\n");
	if (repeat(count, len) == 0)
	{
		printf("No repeat!\n");
		exit(0);
	}
	else
	{
		for (i = 128; i < len; i++)
		{
			if (count[i] > 1)
			{
				if (i < 2048)
				{
					long a = i / 64 + 192, b = i % 64 + 128;
					printf("%c%c ", a, b);
				}
				else
				{
					long a = i / 4096+224, b = (i/64) % 64 + 128, c = i % 64 + 128;
					printf("%c%c%c ", a, b, c);
				}
				printf("0x%04x ", i);
				printf("%d\n", count[i]);
			}
		}
	}
	//system("pause");
}
