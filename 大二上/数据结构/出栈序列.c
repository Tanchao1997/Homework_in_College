// ConsoleApplication1.cpp: 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct node
{
	int num;
	struct node*next;
}NODE;
typedef struct node1
{
	int num;
	struct node1 *ahead, *next;
}NODE1;
void  push(NODE1*stack, int i)
{
	stack->ahead = (NODE1*)malloc(sizeof(NODE1));
		stack->ahead->next = stack;
		stack = stack->ahead;
		stack->num = i;
		stack->ahead = NULL;
}
void pop(NODE1*stack, NODE*p)
{
   			while (p!=NULL&&(stack->num == p->num)) 
			{
				NODE1*ans1 = stack;
				stack = stack->next;
				stack->ahead=NULL;
				free(ans1);
				NODE*ans2 = p;
				p = p->next;
				free(ans2);
			}
}
void check(NODE*head, int n)
{
	NODE*p = head->next;
	NODE1*stack = (NODE1*)malloc(sizeof(NODE1));
	stack->ahead = NULL;
	stack->next = NULL;
	stack->num = 0;
	int i;
	for (i = 1; i <= n; i++)
	{
		//printf("stack1:%d\n", stack->num);
		push(stack, i);
		/*stack->ahead = (NODE1*)malloc(sizeof(NODE1));
		stack->ahead->next = stack;
		stack = stack->ahead;
		stack->num = i;
		stack->ahead = NULL;*/ 
		//printf("stack2:%d\n", stack->num);
		//printf("%d %d\n", stack->num, p->num);
		//if (stack->num == p->num)
		//{
			pop(stack, p);
			/*while (p!=NULL&&(stack->num == p->num)) 
			{
				NODE1*ans1 = stack;
				stack = stack->next;
				stack->ahead=NULL;
				free(ans1);
				NODE*ans2 = p;
				p = p->next;
				free(ans2);
			}*/ 
			//printf("left:%d %d\n", stack->num, p->num);
		//}
		//else continue;
	}
	if (p == NULL)
		printf("Yes\n");
	else
		printf("No\n");
	while (p != NULL)
	{
		NODE*ans = p;
		p = p->next;
		free(ans);
	}
	while (stack != NULL)
	{
		NODE1*ans = stack;
		stack = stack->next;
		free(ans);
	}
	free(head);
}
int main()
{
	int n, m, flag = 0, i, j;
	while (scanf("%d%d", &n, &m) && (n != 0 || m != 0))
	{
		if (flag != 0) printf("\n");
		//printf("LOOP1\n");
		for (i = 0; i < m; i++)
		{
			//printf("LOOP2\n");
			NODE*head = (NODE*)malloc(sizeof(NODE));
			head->next = NULL;
			NODE*loc = head;
			for (j = 0; j < n; j++)
			{
				loc->next = (NODE*)malloc(sizeof(NODE));
				loc = loc->next;
				scanf("%d", &loc->num);
				loc->next = NULL;
			}
			/*NODE*ans = head->next;
			while (ans != NULL)
			{
				printf("%d ", ans->num);
				ans = ans->next;
			}
			printf("\n");*/
			check(head, n);
		}
		flag++;
	}
	//system("pause");
}
