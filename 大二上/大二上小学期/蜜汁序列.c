#include <stdio.h>
#include <stdlib.h>
#define len 15
int check(int*loc, int n)
{
	int i;
	for (i = 1; i < n; i++)
	{
		if (loc[i] == loc[n] || (loc[i] - i) == (loc[n] - n) || (loc[i] + i) == (loc[n] + n))
			return 0;
	}
	return 1;
}
int main()
{
	int n;
	scanf("%d", &n);
	int loc[len] = { 0 };
	int count = 0, line = 1;
	loc[1] = 1;
	while (1)
	{
		if (check(loc, line))
		{
			if (line == n )
			{
				count++;
				loc[line] = 0;
				line--;
				loc[line]++;
			}
			else
			{
				line++;
				loc[line] = 1;
			}
		}
		else
		{
			loc[line]++;
			if (loc[line]> n)
			{
				loc[line] = 0;
				line--;
				if (line <= 0) break;
				loc[line]++;
			}
		}
	}
	printf("%d\n", count);
	system("pause");
}
