#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct link
{
	struct link*ahead; 
    int data;
    struct link*next;
}Link;
void create(Link*head,int n)
{
    Link*locnow=head;
    //Link*test=head; 
    int i;
    for( i=2;i<=n;i++)
    {
        locnow->next=(Link*)malloc(sizeof(Link));
        locnow->next->ahead=locnow;
        locnow=locnow->next;
        locnow->data=i;
    }
    locnow->next=head;
    head->ahead=locnow;
    /*do
    {
    	printf("%d ",test->data);
    	test=test->next;
	}while(test!=head);
	printf("\n");
	test=head;
	do
    {
    	printf("%d ",test->data);
    	test=test->ahead;
	}while(test!=head);
	printf("\n");*/
}
void delet(Link*now)
{
    now->ahead->next=now->next;
    now->next->ahead=now->ahead;
    free(now);
}
Link* find(Link*head,int k)
{
	Link*start=head;
	k--;
	while(k--)
		start=start->next;
		//printf("%d\n",start->data);
	return start;
}
void count(Link*start,int n,int m)
{
	int i;
	Link*left=start;
	Link*right=start;
	Link*flagleft=NULL;
	Link*flagright=NULL;	
	while(1)
	{
		for(i=1;i<m;i++)
		{
			right=right->next;
			//printf("%d ",right->data);
			//printf("\n");
		}
		for(i=1;i<m;i++)
		{
			left=left->ahead;
			//printf("%d ",left->data);
			//printf("\n");
		}
		if(left==right)
		{
			printf("%d",left->data);
			flagleft=left;
			left=left->ahead;
			right=right->next;
			delet(flagleft);
			n--;
		}
		else
		{
			printf("%d-%d",right->data,left->data);
			flagleft=left;
			flagright=right;
			if(flagleft==flagright->next)
			{
				left=left->ahead->ahead;
				right=right->next->next;
			}
			else
			{
				left=left->ahead;
				right=right->next;
			}
			delet(flagleft);
			delet(flagright);
			n-=2;
		}
		printf(",");
		if(n==0) 
		{
			printf("\n");
			exit(0);
		}
		/*else if(n==1)
		{
			//printf("%d,\n",left->data);
			printf("%d,\n",right->data);
			exit(0);
		}
		else;*/
	}
}
int main()
{
    int n,m,k;
    scanf("%d,%d,%d",&n,&k,&m);
    if(n==0||k==0||m==0)
        printf("n,m,k must bigger than 0.\n");
    else if(k>n)
        printf("k should not bigger than n.\n");
    else
    {
        Link*head=(Link*)malloc(sizeof(Link));
        head->data=1;
        head->ahead=NULL; 
        head->next=NULL;
        create(head,n);
		Link*start=find(head,k);
		count(start,n,m);
    }
}
