#include <Windows.h>
#include <iostream>
#include <conio.h>

#define MAX_THREADS 2

DWORD WINAPI MyThreadProc(LPVOID);
typedef int *Pint;
using namespace std;

void main()
{
	DWORD ThreadIdArray[MAX_THREADS];
	HANDLE hThreadArray[MAX_THREADS];
	Pint pInt[MAX_THREADS];
	int i;
	for(i=1;i<=MAX_THREADS;i++)
	{
		pInt[i-1]=new int(i);
		hThreadArray[i-1]=CreateThread(NULL,0,MyThreadProc,pInt[i-1],0,&ThreadIdArray[i-1]);
	}
	WaitForMultipleObjects(MAX_THREADS,hThreadArray,true,INFINITE);
	for(i=0;i<MAX_THREADS;i++)
	{
		CloseHandle(hThreadArray[i]);
		delete pInt[i];
		pInt[i]=NULL;
	}

}

DWORD WINAPI MyThreadProc(LPVOID lParam)
{
	Pint i =(Pint)lParam;
	int j=*i;
	for(int k=0;k<10;k++)
	{
		cout<<"\n Inside Thread "<<j;
		_sleep(j*1000);
		//cout<<"\n Press "<<i<<" to terminate ";
	}
	return 1;
}