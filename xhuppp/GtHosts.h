#pragma once
#include<WinInet.h>
#pragma comment(lib, "wininet.lib")  
#define BUF_SIZE 2048
#include<fstream>
class GtHosts
{
public:
	GtHosts();
	~GtHosts();
	//CString Hosts;
	bool Geted = false;
	LPSTR GetInterNetURLText(LPSTR lpcInterNetURL, char* buff);
};

