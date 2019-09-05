#include <cstdio>
#include <cstdlib>
#include <iostream> 
#include <windows.h>
#include <psapi.h>
#include <tlhelp32.h>
#include <shlwapi.h>
#include <iomanip>
#pragma comment(lib,"Shlwapi.lib")
#pragma comment(lib, "psapi.lib")
using namespace std;
//显示保护标记，该标记表示允许应用程序对内存进行访问的类型
inline bool TestSet(DWORD dwTarget, DWORD dwMask)
{
	return ((dwTarget &dwMask) == dwMask);
}
#define SHOWMASK(dwTarget,type) if(TestSet(dwTarget,PAGE_##type)){cout << "," << #type;} 
void ShowProtection(DWORD dwTarget)
{//定义的页面保护类型	
	SHOWMASK(dwTarget, READONLY);
	SHOWMASK(dwTarget, GUARD);
	SHOWMASK(dwTarget, NOCACHE);
	SHOWMASK(dwTarget, READWRITE);
	SHOWMASK(dwTarget, WRITECOPY);
	SHOWMASK(dwTarget, EXECUTE);
	SHOWMASK(dwTarget, EXECUTE_READ);
	SHOWMASK(dwTarget, EXECUTE_READWRITE);
	SHOWMASK(dwTarget, EXECUTE_WRITECOPY);
	SHOWMASK(dwTarget, NOACCESS);
}
//遍历整个虚拟内存，并显示各内存区属性的工作程序的方法
void WalkVM(HANDLE hProcess)
{
	SYSTEM_INFO si;
	//系统信息结构	
	ZeroMemory(&si, sizeof(si));
	//初始化	
	GetSystemInfo(&si);
	//获得系统信息 	
	MEMORY_BASIC_INFORMATION mbi;
	//进程虚拟内存空间的基本信息结构	
	ZeroMemory(&mbi, sizeof(mbi));
	//分配缓冲区，用于保存信息 	
	//循环整个应用程序地址空间	
	LPCVOID pBlock = (LPVOID)si.lpMinimumApplicationAddress;
	while (pBlock < si.lpMaximumApplicationAddress)
	{
		//获得下一个虚拟内存块的信息		
		if (VirtualQueryEx(
			hProcess,	//相关的进程			
			pBlock,		//开始位置			
			&mbi,		//缓冲区			
			sizeof(mbi)) == sizeof(mbi))	//长度的确认，如果失败返回0		
		{
			//计算块的结尾及其长度			
			LPCVOID pEnd = (PBYTE)pBlock + mbi.RegionSize;
			TCHAR szSize[MAX_PATH];
			//将数字转换成字符串			
			StrFormatByteSize(mbi.RegionSize, szSize, MAX_PATH);
			//显示块地址和长度			
			cout.fill('0');
			cout << hex << setw(8) << (DWORD)pBlock << "-" << hex << setw(8) << (DWORD)pEnd << (strlen((char*)szSize) == 7 ? "(" : "(") << szSize << ")"; 	
			//cout << hex << setw(8) << pBlock << "-" << hex << setw(8) << pEnd << (strlen((char*)szSize) == 7 ? "(" : "(") << szSize << ")";
			//显示块的状态			
			switch (mbi.State)
			{
			case MEM_COMMIT:
				printf("已提交");
				break;
			case MEM_FREE:
				printf("空闲");
				break;
			case MEM_RESERVE:
				printf("已预留");
				break;
			}
			//显示保护			
			if (mbi.Protect == 0 && mbi.State != MEM_FREE)
			{
				mbi.Protect = PAGE_READONLY;
			}
			ShowProtection(mbi.Protect);
			//显示类型			
			switch (mbi.Type)
			{
			case MEM_IMAGE:
				printf(", Image");
				break;
			case MEM_MAPPED:
				printf(", Mapped");
				break;
			case MEM_PRIVATE:
				printf(", Private");
				break;
			}
			//检验可执行的映像			
			TCHAR szFilename[MAX_PATH];
			if (GetModuleFileName(
				(HMODULE)pBlock,			//实际虚拟内存的模块句柄				
				szFilename,					//完全指定的文件名称				
				MAX_PATH) > 0)				//实际使用的缓冲区长度			
			{
				//除去路径并显示				
				PathStripPath(szFilename);
				printf(", Module:%s", szFilename);
			}
			printf("\n");
			//移动块指针以获得下一个块			
			pBlock = pEnd;
		}
	}
}
int main(int argc, char* argv[])
{
	//获得系统相关信息	
	SYSTEM_INFO si;
	ZeroMemory(&si, sizeof(si));
	GetSystemInfo(&si);
	printf("---------------------系统信息-------------------------\n");
	printf("内存页的大小为：%dKB.\n", (int)si.dwPageSize / 1024);
	cout << "每个进程可用地址空间的最小内存地址为: 0x" << si.lpMinimumApplicationAddress << endl;
	cout << "每个进程可用的私有地址空间的最大内存地址为: 0x" << si.lpMaximumApplicationAddress << endl;
	cout << "用于预定地址空间区域的分配粒度为: " << si.dwAllocationGranularity / 1024 << "KB" << endl;
	printf("------------------------------------------------------\n");
	//获取系统的性能信息
	PERFORMANCE_INFORMATION pi;
	pi.cb = sizeof(pi);
	GetPerformanceInfo(&pi, sizeof(pi));
	printf("----------------系统的存储器使用情况------------------\n");
	cout << "总物理内存大小: " << pi.PhysicalTotal<<"页" << endl;
	cout << "可用物理内存大小: " << pi.PhysicalAvailable <<"页"<< endl;
	cout << "系统Cache的容量为: " << pi.SystemCache<<"页" << endl;
	cout << "页的大小为: " << pi.PageSize <<"字节"<< endl;
	cout << "当前打开的句柄个数为: " << pi.HandleCount << endl;
	cout << "当前进程个数为: " << pi.ProcessCount << endl;
	cout << "当前线程个数为: " << pi.ThreadCount << endl;
	printf("------------------------------------------------------\n");
	//获得系统内存信息
	MEMORYSTATUSEX statex;
	statex.dwLength = sizeof(statex);
	GlobalMemoryStatusEx(&statex);
	printf("---------------内存信息-----------------\n");
	printf("物理内存的使用率为:%ld%%\n", statex.dwMemoryLoad);
	printf("物理内存的总容量为: %.2fGB.\n", (float)statex.ullTotalPhys / 1024 / 1024 / 1024);
	printf("可用的物理内存为: %.2fGB.\n", (float)statex.ullAvailPhys / 1024 / 1024 / 1024);
	printf("总的页面大小为:%.2fGB.\n", (float)statex.ullTotalPageFile / 1024 / 1024 / 1024);
	printf("当前进程可用的最大内存数为：%.2fGB.\n", (float)statex.ullAvailPageFile / 1024 / 1024 / 1024);
	printf("当前进程最大内存寻址地址：%.2fGB.\n", (float)statex.ullTotalVirtual / 1024 / 1024 / 1024);
	printf("当前进程可用最大内存：%.2fGB.\n", (float)statex.ullAvailVirtual / 1024 / 1024 / 1024);	
	printf("------------------------------------------------------\n");
	printf("-------进程虚拟地址空间布局和工作集信息查询---------\n");
	int pid;
	while (true)
	{
		printf("输入要查询的进程ID:");
		cin >> pid;
		if (pid <0)	break;
		HANDLE hP = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
		WalkVM(hP);
		
	}
	system("pause");
	return 0;
}
