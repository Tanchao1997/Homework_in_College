// mytime.cpp: �������̨Ӧ�ó������ڵ㡣
//

#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main(int argc, char **argv)
{
	STARTUPINFO si;	//�������������Ϣ�Ľṹ��
	memset(&si, 0, sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);	//Ӧ�ó�����뽫cb��ʼ��Ϊsizeof(STARTUPINFO)
	si.dwFlags = STARTF_USESHOWWINDOW;	//���ڱ�־
	si.wShowWindow = SW_SHOW;
	PROCESS_INFORMATION pi;	//�ر��������ý���
							//WideString(AnsiString(argv[1])).c_btr()
	SYSTEMTIME time_start, time_end;
	if (!CreateProcess(NULL, argv[1], NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi))
	{
		cout << "��������ʧ��!" << endl;
		exit(1);
	}
	else
	{
		cout << "�������̳ɹ�!" << endl;
		GetSystemTime(&time_start);
	}
	//ʹ�õȴ��������ȴ����������̵�����
	if (argv[2] == NULL)
		WaitForSingleObject(pi.hProcess, INFINITE);
	else
		WaitForSingleObject(pi.hProcess, atoi(argv[2])*1000);//��������ʱ������Ϊ��λ
	GetSystemTime(&time_end);

	int  hour, minutes, seconds, milliseconds;
	milliseconds = time_end.wMilliseconds - time_start.wMilliseconds;
	seconds = time_end.wSecond - time_start.wSecond;
	minutes = time_end.wMinute - time_start.wMinute;
	hour = time_end.wHour - time_start.wHour;
	if (milliseconds < 0)
	{
		seconds--;
		milliseconds += 1000;
	}
	if (seconds < 0)
	{
		minutes--;
		seconds += 60;
	}
	if (minutes < 0)
	{
		hour--;
		minutes += 60;
	}
	if (hour < 0)
	{
		hour += 24;
	}
	printf("��������ʱ��: ");
	if (hour > 0)
	{
		printf("%dСʱ", hour);
	}
	if (minutes > 0)
	{
		printf("%d����", minutes);
	}
	if (seconds > 0)
	{
		printf("%d��", seconds);
	}
	if (milliseconds > 0)
	{
		printf("%d����", milliseconds);
	}
	printf("\n");
	return 0;
}
