#pragma once


#include<string.h>
#include<iostream>
# include <windows.h>
#include <stdio.h>
#include <Locale.h>
#include "ras.h"
#include "raserror.h"
#include "strsafe.h"
#include"RasDlg.h"
#include<process.h>//duoxiancheng
using namespace std;
#pragma comment(lib, "Rasapi32.lib")
#pragma comment(lib, "Rasdlg.lib")
#pragma comment(lib, "Wininet.lib")


class radidal
{
public:
	LPTSTR RAS_USR;
	LPTSTR RAS_PWD;
	radidal();
	int setUP(LPTSTR usrname, LPTSTR usrpassword);
	CString user;
	CString password;
	CString ipv4;
	CString ipv6;
	int get_pppinfo();//得到信息
	//VOID callfunc(UINT unMsg, RASCONNSTATE rasconnstate, DWORD dwError);
	int rasdial();
	int rasdial2();//没有设置的拨号；
	int disconn();
	int getipinfo();
	CString  getconinfo();
	~radidal();
	void setEntry()
	{
		lpszEntry = L"clickxhu";
	};
	void clearEntry()
	{
		RasDeleteEntry(NULL, lpszEntry);
	}
private:
	bool rasAlready = false;
	LPRASENTRY lpentry;
	LPRASDIALDLG lpInfo;
	HRASCONN hRasConn = NULL;//设置默认NULL，如果不NULL 回返回668 使得不能连接
	RASDIALPARAMSW RasPragma = { 0 };
	LPTSTR lpszEntry = L"点击网络";
public:bool ipv6Flag = false;
	   bool hasLpsz();
};

class pop
{
public:
	int enum_conn();
	CString error_ras;
	CString activeConn;
	int disconn();
	int flag=0;
};