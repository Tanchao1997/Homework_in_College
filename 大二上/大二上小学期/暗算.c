#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define len 101
int ahead(char*a,int n)
{
	while(a[n]==0&&n>=0) n--;
	if(n>=0) return 1;
	return 0; 
}
int after(char*a,int n)
{
	while(a[n]==0&&n<strlen(a)) n++;
	if(n<strlen(a)) return 1;
	return 0;
}
void trans(char*a, int*b)
{
	int num = 1,i;
	for (i = 0; i < strlen(a); i++)
	{
		if (a[i] == ' '&&ahead(a,i) !=0&&after(a,i)!=0) num++;
		else b[num]++;
	}
	b[0] = num;
}//��ÿ�����ĵ��ʸ����ŵ�b[0]��b[1]-b[num]Ϊnum�����ʷֱ�ĳ���
int repeat(char*s)
{
	int a[30]={0},i=0;
	for(i=0;i<26;i++)
		a[s[i]-'a']++;
	for(i=0;i<26;i++)
	{
		if(a[i]!=1) return 1;
	}
	return 0;
} 
int main()
{
	int time;
	scanf("%d", &time);
	getchar();
	char key[len * 2] = { 0 };
	int keynum[len * 2] = { 0 };
	gets(key);
	getchar();
	trans(key, keynum);
	while (time--)
	{
		char text[len][len * 2] = { 0 }, storage[30] = { 0 };
		int i = 0, textnum[len][len * 2] = { 0 };
		while (gets(text[i])&&strlen(text[i])!=0) i++;
		int j = 0, flag1[len] = { 0 }, l,count=0;
		for (j = 0; j < i; j++)
		{
			int flag2 ;
			trans(text[j], textnum[j]);
			if (textnum[j][0] == keynum[0])
			{
				flag2 = 1;
				for (l = 0; l <= keynum[0]; l++)
					if (textnum[j][l] != keynum[l]) 
					{
						flag2 = 0; break;
					}
			}//53��61�м��鵥�ʸ�����ͬ��������Ӧ���ʳ����Ƿ���ͬ
			else flag2 = 0;
			if(strlen(key)!=strlen(text[j])) flag2=0; 
			if (flag2 == 1) flag1[count++] = j;
		}//49��64�м���ÿ���������ʸ����Ͷ�Ӧ���ʳ����Ƿ���ͬ
		int m=0;
		for( m=0;m<count;m++)
		{
			int flag3=1,k;
			for(k=0;k<strlen(key);k++)
				if((key[k]==' '&&text[flag1[m]][k]!=' ')||(key[k]!=' '&&text[flag1[m]][k]==' '))
				{
					flag3=0;break;
				}
			for (k = 0; k < strlen(key); k++)
			{
				if (text[flag1[m]][k] != ' ')
				{
					if (storage[text[flag1[m]][k] - 'a'] != 0 && storage[text[flag1[m]][k] - 'a'] != key[k])
						{
							flag3 = 0;break;
						}
					else 
					storage[text[flag1[m]][k] - 'a'] = key[k];
				}
			}
			for(k=0;k<26;k++)
				if(storage[k]==0) 
				{
					flag3=0;break;
				}
			if(repeat(storage)==1) flag3=0;//80�к�86��91�����ĸ�Ƿ�һһ��Ӧ 
			if (flag3 != 0) 
			{
				for (k = 0; k < i; k++)
				{
					for (l = 0; l < strlen(text[k]); l++)
					{
						if (text[k][l] ==' ') printf(" ");
						else printf("%c", storage[text[k][l] - 'a']);
					}
						printf("\n");
				}
				break;
			}
		}
		if (m >= count) printf("No solution.\n");
		if (time > 0) printf("\n");	
	}
}

