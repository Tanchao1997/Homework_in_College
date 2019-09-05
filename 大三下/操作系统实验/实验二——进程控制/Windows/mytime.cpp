// mytime.cpp: 定义控制台应用程序的入口点。
//

#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main(int argc, char **argv)
{
	STARTUPINFO si;	//进程启动相关信息的结构体
	memset(&si, 0, sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);	//应用程序必须将cb初始化为sizeof(STARTUPINFO)
	si.dwFlags = STARTF_USESHOWWINDOW;	//窗口标志
	si.wShowWindow = SW_SHOW;
	PROCESS_INFORMATION pi;	//必备参数设置结束
							//WideString(AnsiString(argv[1])).c_btr()
	SYSTEMTIME time_start, time_end;
	if (!CreateProcess(NULL, argv[1], NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi))
	{
		cout << "创建进程失败!" << endl;
		exit(1);
	}
	else
	{
		cout << "创建进程成功!" << endl;
		GetSystemTime(&time_start);
	}
	//使用等待函数来等待所创建进程的死亡
	if (argv[2] == NULL)
		WaitForSingleObject(pi.hProcess, INFINITE);
	else
		WaitForSingleObject(pi.hProcess, atoi(argv[2])*1000);//程序运行时间以秒为单位
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
	printf("程序运行时间: ");
	if (hour > 0)
	{
		printf("%d小时", hour);
	}
	if (minutes > 0)
	{
		printf("%d分钟", minutes);
	}
	if (seconds > 0)
	{
		printf("%d秒", seconds);
	}
	if (milliseconds > 0)
	{
		printf("%d毫秒", milliseconds);
	}
	printf("\n");
	return 0;
}
