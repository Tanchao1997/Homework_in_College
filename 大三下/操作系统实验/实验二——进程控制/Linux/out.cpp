#include"stdlib.h"
#include"iostream"
#include<sys/time.h>
using namespace std;
int main(int argc,char** argv)
{
	//cout<<"out:"<<endl;
	//cout<<"argc:"<<argc<<endl;
	//for(int i=0;i<argc;i++)
	//cout<<"argv["<<i<<"]:"<<argv[i]<<endl;
	//cout<<"argv[1]==NULL:"<<(argv[1]==NULL)<<endl;
	if(argc==1)
	{
		int num=10000;
		//cin >> num;
		for (int i = 0; i < num; i++)
			cout << i << ' ';
		cout << endl;
	}
	else
	{
		struct timeval starttime;
		struct timeval endtime;
		gettimeofday(&starttime,NULL);
		int i=0;
		
		//gettimeofday(&endtime,NULL);
		do
		{
			cout << i << ' ';
			gettimeofday(&endtime,NULL);
			i++;
		}while((endtime.tv_sec-starttime.tv_sec+endtime.tv_usec/1000000-starttime.tv_usec/1000000)<atof(argv[1]));
		cout << endl;
		//cout<<"atof:"<<atof(argv[1])<<endl;
	}
	return 0;
}