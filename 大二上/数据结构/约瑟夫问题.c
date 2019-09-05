#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct link
{
    int data;
    struct link*locnext;
}Link;
void create(Link*head,int n)
{
    Link*locahead=head;
    int i;
    for( i=2;i<=n;i++)
    {
        locahead->locnext=(Link*)malloc(sizeof(Link));
        locahead=locahead->locnext;
        locahead->data=i;
    }
    locahead->locnext=head;
}
void delet(Link*ahead)
{
    //int m=ahead->locnext->data;
    Link*ans=ahead->locnext;
    ahead->locnext=ahead->locnext->locnext;
    free(ans);
    //return m;
}
Link* find(Link*head,int k)
{
	Link*start=head;
	k--;
	while(k--)
		start=start->locnext;
	return start;
}
void count(Link*start,int n,int m)
{
	int i,ten=0;
	while(1)
	{
		Link*flag=start;
		for(i=1;i<m;i++)
		{
			flag=start;
			start=start->locnext;
		}
		printf("%d",start->data); 
		start=start->locnext;
		delet(flag);
		n--;
		ten++;
		if(n!=0&&ten%10!=0) 
		printf(" ");
		else if(n==0)
		{
			printf("\n");
			exit(0);
		}
		else if(ten%10==0) printf("\n");
		else;
	}
}
int main()
{
    int n,m,k;
    scanf("%d,%d,%d",&n,&k,&m);
    if(n<1||k<1||m<1)
        printf("n,m,k must bigger than 0.\n");
    else if(k>n)
        printf("k should not bigger than n.\n");
    else
    {
        Link*head=(Link*)malloc(sizeof(Link));
        head->data=1;
        head->locnext=NULL;
        create(head,n);
		Link*start=find(head,k);
		count(start,n,m);
    }
}
