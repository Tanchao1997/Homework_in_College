//#include"stdafx.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define maxlen 500
int cmp(char a, char b)
{
	if (a == '(') return 0;
	if (a == b&&a == '^') return 0;
	if (a == b) return 1;
	if ((a == '*' || a == '/') && (b == '+' || b == '-')) return 1;
	if ((a == '+' || a == '-') && (b == '*' || b == '/')) return 0;
	if (a != '^'&&b == '^') return 0;
	if (a == '^'&&b != '^') return 1;
	if ((a == '+' || a == '-') && (b == '+' || b == '-')) return 1;
	if ((a == '*' || a == '/') && (b == '*' || b == '/')) return 1;
}
int main()
{
	int N,j;
	char expre[maxlen] = { 0 };
	char stack[maxlen] = { 0 };
	scanf("%d", &N);
	while (N--)
	{
		memset(expre, 0, sizeof(expre));
		memset(stack, 0, sizeof(stack));
		scanf("%s", expre);
		int top = 0;
		for ( j = 0; j < strlen(expre)-1; j++)
		{
			if ((expre[j] >= 'A'&&expre[j] <= 'Z')||(expre[j]>='a'&&expre[j]<='z')) printf("%c", expre[j]);
			else
			{
				if (expre[j] == '(')
						stack[++top] = expre[j];
				/*if (top == 0) stack[++top] = expre[j];
				else if(stack[top]=='(') 
				stack[++top]=expre[j];*/ 
				else
				{
					//if (expre[j] == '(')
						//stack[++top] = expre[j];
					if (expre[j] == ')')
					{
						while (stack[top] != '('&&top > 0)
						{
							printf("%c", stack[top]);
							stack[top]=0;
							top--;
						}
						stack[top] = 0;
						top--;
					}
					else
					{
						if (!cmp(stack[top], expre[j]))
							stack[++top] = expre[j];
						else
						{
							while (cmp(stack[top], expre[j])&&top>0)
							{
								printf("%c", stack[top]);
								stack[top]=0;
								top--;
							}
							stack[++top] = expre[j];
						}
					}
				}
			}
		}
		while (top > 0)
		{
			printf("%c", stack[top]);
			stack[top]=0;
			top--;
		}
		printf("\n");
	}
}
