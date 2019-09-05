#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct node
{
	 int data;
	 struct node *next;
}NODE;
void change(int n,int m,NODE*S)
{
	int k=0;
	NODE*loc=S;
	while(n!=0&&k<50)
	{
		loc->next=(NODE*)malloc(sizeof(NODE)); 
		loc=loc->next;
        loc->data=(n*10)/m;
        n=(n*10)%m;
        k++;
    }
    loc->next=NULL;
}
void output(NODE*head)
{
	int k=0;
	printf("0.");
	while(head->next!=NULL&&k<50)
	{
		printf("%d",head->next->data);
		head=head->next;
		k++;
	}
	printf("\n");
}
void DestroyList(NODE*head)
{
	NODE*p;
//	if(head==NULL)
//	return 0;
	while(head)
	{
	p=head->next;
	free(head);
	head=p;
	}
}
int main()
{
	int n,m;
	NODE*head;
	scanf("%d%d",&n,&m);
	head=(NODE*)malloc(sizeof(NODE));
	head->next=NULL;
	head->data=-1;
	change(n,m,head);
	output(head);
	DestroyList(head);
	return(0);
}














