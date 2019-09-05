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
//��ʾ������ǣ��ñ�Ǳ�ʾ����Ӧ�ó�����ڴ���з��ʵ�����
inline bool TestSet(DWORD dwTarget, DWORD dwMask)
{
	return ((dwTarget &dwMask) == dwMask);
}
#define SHOWMASK(dwTarget,type) if(TestSet(dwTarget,PAGE_##type)){cout << "," << #type;} 
void ShowProtection(DWORD dwTarget)
{//�����ҳ�汣������	
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
//�������������ڴ棬����ʾ���ڴ������ԵĹ�������ķ���
void WalkVM(HANDLE hProcess)
{
	SYSTEM_INFO si;
	//ϵͳ��Ϣ�ṹ	
	ZeroMemory(&si, sizeof(si));
	//��ʼ��	
	GetSystemInfo(&si);
	//���ϵͳ��Ϣ 	
	MEMORY_BASIC_INFORMATION mbi;
	//���������ڴ�ռ�Ļ�����Ϣ�ṹ	
	ZeroMemory(&mbi, sizeof(mbi));
	//���仺���������ڱ�����Ϣ 	
	//ѭ������Ӧ�ó����ַ�ռ�	
	LPCVOID pBlock = (LPVOID)si.lpMinimumApplicationAddress;
	while (pBlock < si.lpMaximumApplicationAddress)
	{
		//�����һ�������ڴ�����Ϣ		
		if (VirtualQueryEx(
			hProcess,	//��صĽ���			
			pBlock,		//��ʼλ��			
			&mbi,		//������			
			sizeof(mbi)) == sizeof(mbi))	//���ȵ�ȷ�ϣ����ʧ�ܷ���0		
		{
			//�����Ľ�β���䳤��			
			LPCVOID pEnd = (PBYTE)pBlock + mbi.RegionSize;
			TCHAR szSize[MAX_PATH];
			//������ת�����ַ���			
			StrFormatByteSize(mbi.RegionSize, szSize, MAX_PATH);
			//��ʾ���ַ�ͳ���			
			cout.fill('0');
			cout << hex << setw(8) << (DWORD)pBlock << "-" << hex << setw(8) << (DWORD)pEnd << (strlen((char*)szSize) == 7 ? "(" : "(") << szSize << ")"; 	
			//cout << hex << setw(8) << pBlock << "-" << hex << setw(8) << pEnd << (strlen((char*)szSize) == 7 ? "(" : "(") << szSize << ")";
			//��ʾ���״̬			
			switch (mbi.State)
			{
			case MEM_COMMIT:
				printf("���ύ");
				break;
			case MEM_FREE:
				printf("����");
				break;
			case MEM_RESERVE:
				printf("��Ԥ��");
				break;
			}
			//��ʾ����			
			if (mbi.Protect == 0 && mbi.State != MEM_FREE)
			{
				mbi.Protect = PAGE_READONLY;
			}
			ShowProtection(mbi.Protect);
			//��ʾ����			
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
			//�����ִ�е�ӳ��			
			TCHAR szFilename[MAX_PATH];
			if (GetModuleFileName(
				(HMODULE)pBlock,			//ʵ�������ڴ��ģ����				
				szFilename,					//��ȫָ�����ļ�����				
				MAX_PATH) > 0)				//ʵ��ʹ�õĻ���������			
			{
				//��ȥ·������ʾ				
				PathStripPath(szFilename);
				printf(", Module:%s", szFilename);
			}
			printf("\n");
			//�ƶ���ָ���Ի����һ����			
			pBlock = pEnd;
		}
	}
}
int main(int argc, char* argv[])
{
	//���ϵͳ�����Ϣ	
	SYSTEM_INFO si;
	ZeroMemory(&si, sizeof(si));
	GetSystemInfo(&si);
	printf("---------------------ϵͳ��Ϣ-------------------------\n");
	printf("�ڴ�ҳ�Ĵ�СΪ��%dKB.\n", (int)si.dwPageSize / 1024);
	cout << "ÿ�����̿��õ�ַ�ռ����С�ڴ��ַΪ: 0x" << si.lpMinimumApplicationAddress << endl;
	cout << "ÿ�����̿��õ�˽�е�ַ�ռ������ڴ��ַΪ: 0x" << si.lpMaximumApplicationAddress << endl;
	cout << "����Ԥ����ַ�ռ�����ķ�������Ϊ: " << si.dwAllocationGranularity / 1024 << "KB" << endl;
	printf("------------------------------------------------------\n");
	//��ȡϵͳ��������Ϣ
	PERFORMANCE_INFORMATION pi;
	pi.cb = sizeof(pi);
	GetPerformanceInfo(&pi, sizeof(pi));
	printf("----------------ϵͳ�Ĵ洢��ʹ�����------------------\n");
	cout << "�������ڴ��С: " << pi.PhysicalTotal<<"ҳ" << endl;
	cout << "���������ڴ��С: " << pi.PhysicalAvailable <<"ҳ"<< endl;
	cout << "ϵͳCache������Ϊ: " << pi.SystemCache<<"ҳ" << endl;
	cout << "ҳ�Ĵ�СΪ: " << pi.PageSize <<"�ֽ�"<< endl;
	cout << "��ǰ�򿪵ľ������Ϊ: " << pi.HandleCount << endl;
	cout << "��ǰ���̸���Ϊ: " << pi.ProcessCount << endl;
	cout << "��ǰ�̸߳���Ϊ: " << pi.ThreadCount << endl;
	printf("------------------------------------------------------\n");
	//���ϵͳ�ڴ���Ϣ
	MEMORYSTATUSEX statex;
	statex.dwLength = sizeof(statex);
	GlobalMemoryStatusEx(&statex);
	printf("---------------�ڴ���Ϣ-----------------\n");
	printf("�����ڴ��ʹ����Ϊ:%ld%%\n", statex.dwMemoryLoad);
	printf("�����ڴ��������Ϊ: %.2fGB.\n", (float)statex.ullTotalPhys / 1024 / 1024 / 1024);
	printf("���õ������ڴ�Ϊ: %.2fGB.\n", (float)statex.ullAvailPhys / 1024 / 1024 / 1024);
	printf("�ܵ�ҳ���СΪ:%.2fGB.\n", (float)statex.ullTotalPageFile / 1024 / 1024 / 1024);
	printf("��ǰ���̿��õ�����ڴ���Ϊ��%.2fGB.\n", (float)statex.ullAvailPageFile / 1024 / 1024 / 1024);
	printf("��ǰ��������ڴ�Ѱַ��ַ��%.2fGB.\n", (float)statex.ullTotalVirtual / 1024 / 1024 / 1024);
	printf("��ǰ���̿�������ڴ棺%.2fGB.\n", (float)statex.ullAvailVirtual / 1024 / 1024 / 1024);	
	printf("------------------------------------------------------\n");
	printf("-------���������ַ�ռ䲼�ֺ͹�������Ϣ��ѯ---------\n");
	int pid;
	while (true)
	{
		printf("����Ҫ��ѯ�Ľ���ID:");
		cin >> pid;
		if (pid <0)	break;
		HANDLE hP = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
		WalkVM(hP);
		
	}
	system("pause");
	return 0;
}
