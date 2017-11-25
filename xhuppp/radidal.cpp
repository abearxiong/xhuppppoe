#include "stdafx.h"
#include "radidal.h"

#include"winnt.h"
#define DEVICE_NAME_LENGTH 6
#define DEVICE_TYPE_LENGTH 6
radidal::radidal()
{
	RAS_USR = NULL; RAS_PWD = NULL;
	lpentry = (LPRASENTRY)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(RASENTRY));
	// Allocate heap memory and initialize RASDIALDLG structure
	lpInfo = (LPRASDIALDLG)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(RASDIALDLG));
	// Allocate heap memory and initialize RASENTRY structure
	if (lpentry == NULL || lpInfo == NULL) {
		//wprintf(L"HeapAlloc failed");
		CString error_ras;
		error_ras = _T("rasdial HeapAlloc failed!---重启试试，分配内存错误");
		MessageBox(NULL, error_ras, _T("error"), NULL);
		HeapFree(GetProcessHeap(), 0, lpentry);
		HeapFree(GetProcessHeap(), 0, lpInfo);
	}
	//
	LPTSTR lpszdevicename = L"PPPoe";
	LPTSTR lpszdevicetype = RASDT_PPPoE;// RASDT_Modem;//

	CString error_ras;
	DWORD dwError = ERROR_SUCCESS;
	// The RASDIALDLG and RASENTRY dwSize members have to be initialized or the RasDialDlg()
	// RasSetEntryProperties() APIs will fail below.
	lpInfo->dwSize = sizeof(RASDIALDLG);
	lpentry->dwDialMode = RASEDM_DialAll;
	lpentry->dwSize = sizeof(RASENTRY);
	lpentry->dwFramingProtocol = RASFP_Ppp;
	lpentry->dwfNetProtocols = RASNP_Ip | RASNP_Ipv6;
	lpentry->dwfOptions = 0| RASEO_RemoteDefaultGateway;// | RASEO_UseLogonCredentials;
	lpentry->dwType = RASET_Broadband;
	lpentry->dwfOptions2 = RASEO2_DontNegotiateMultilink;
	dwError |= StringCchCopyN(lpentry->szDeviceName, RAS_MaxDeviceName, lpszdevicename, DEVICE_NAME_LENGTH);
	dwError |= StringCchCopyN(lpentry->szDeviceType, RAS_MaxDeviceType, lpszdevicetype, DEVICE_TYPE_LENGTH);
	if (dwError != S_OK) {
		//wprintf(L"Structure initilization failed: Error = %d\n", dwError);
		error_ras = _T("Structure initilization failed！ 复制失败!---重启试试，分配内存错误，我也不知道为什么。联系我");
		MessageBox(NULL, error_ras, _T("error"), NULL);
		HeapFree(GetProcessHeap(), 0, lpentry);
		HeapFree(GetProcessHeap(), 0, lpInfo);
	}
	//strcpy_s(lpentry->szLocalPhoneNumber, lpszphonenumber); //printf("123123"); system("pause");
	//strcpy_s(lpentry->szDeviceName, lpszdevicename);
	//strcpy_s(lpentry->szDeviceType, lpszdevicetype);
}
int radidal::setUP(LPTSTR usrname, LPTSTR usrpassword)
{
	RAS_USR= usrname;
	RAS_PWD=usrpassword;
	return 0;
}
int radidal::get_pppinfo()
{
	DWORD dwRet = ERROR_SUCCESS;
	//LPTSTR lpszUserName = L"点击网络";
	CString error_ras;
	// Allocate heap memory for the RASCREDENTIALS structure
	LPRASCREDENTIALS lpCred = (LPRASCREDENTIALS)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(RASCREDENTIALS));
	
	if (lpCred == NULL) {
		error_ras = "GetPopinfo HeapAlloc failed!";
		HeapFree(GetProcessHeap(), 0, lpCred);
		MessageBox(NULL, error_ras, _T("error"), NULL);
		return 1;
	}
	dwRet |= StringCchCopyN(lpCred->szDomain, DNLEN, L"", 0);
	dwRet |= StringCchCopyN(lpCred->szUserName, UNLEN, L"", 0);
	dwRet |= StringCchCopyN(lpCred->szPassword, UNLEN, L"", 0);
	if (dwRet != ERROR_SUCCESS) {
		//wprintf(L"RASCREDENTIALS structure reset failed!\n");
		error_ras = "get info-RASCREDENTIALS structure reset failed!\n";
		MessageBox(NULL, error_ras, _T("error"), NULL);
		HeapFree(GetProcessHeap(), 0, lpCred);
		return 1;
	}
	lpCred->dwSize = sizeof(RASCREDENTIALS);
	lpCred->dwMask = RASCM_UserName | RASCM_Password /*| RASCM_Domain*/;
	// Grab the newly created entry's credentials
	dwRet = RasGetCredentials(NULL, lpszEntry, lpCred);
	if (dwRet == ERROR_SUCCESS)
	{

	}
	else
	{
		HeapFree(GetProcessHeap(), 0, lpCred);
		return 2;
	}
	user = lpCred->szUserName;
	password = lpCred->szPassword;
	HeapFree(GetProcessHeap(), 0, lpCred);
	return ERROR_SUCCESS;
}
VOID callfunc(UINT unMsg, RASCONNSTATE rasconnstate, DWORD dwError)
{
	/*UINT unMsg; RASCONNSTATE rasconnstate; DWORD dwError;*/
	CString Tishi1,Tishi; int w = unMsg; long w2 = dwError;
	//Tishi1.Format(_T("%d %f"), unMsg, dwError);
	switch (rasconnstate)
	{
	case RASCS_OpenPort:
		Tishi=_T("RASCS_OpenPort");
		break;
	case RASCS_PortOpened:
		Tishi = _T("RASCS_PortOpened");
		break;
	case RASCS_ConnectDevice:
		Tishi = _T("RASCS_ConnectDevice");
		break;
	case RASCS_DeviceConnected:
		Tishi = _T("RASCS_DeviceConnected");
		break;
	case RASCS_AllDevicesConnected:
		Tishi = _T("RASCS_AllDevicesConnected");
		break;
	case RASCS_Authenticate:
		Tishi = _T("RASCS_Authenticate");
		break;
	case RASCS_AuthNotify:
		Tishi = _T("RASCS_AuthNotify");
		break;
	case RASCS_AuthRetry:
		Tishi = _T("RASCS_AuthRetry");
		break;
	case RASCS_AuthCallback:
		Tishi = _T("RASCS_AuthCallback");
		break;
	case RASCS_AuthChangePassword:
		Tishi = _T("RASCS_AuthChangePassword");
		break;
	case RASCS_AuthProject:
		Tishi = _T("RASCS_AuthProject");
		break;
	case RASCS_AuthLinkSpeed:
		Tishi = _T("RASCS_AuthLinkSpeed");
		break;
	case RASCS_AuthAck:
		Tishi = _T("RASCS_AuthAck");
		break;
	case RASCS_ReAuthenticate:
		Tishi = _T("RASCS_ReAuthenticate");
		break;
	case RASCS_Authenticated:
		Tishi = _T("RASCS_Authenticated");
		break;
	case RASCS_PrepareForCallback:
		Tishi = _T("RASCS_PrepareForCallback");
		break;
	case RASCS_WaitForModemReset:
		Tishi = _T("RASCS_WaitForModemReset");
		break;
	case RASCS_WaitForCallback:
		Tishi = _T("RASCS_WaitForCallback");
		break;
	case RASCS_Interactive:
		Tishi = _T("RASCS_Interactive");
		break;
	case RASCS_RetryAuthentication:
		Tishi = _T("RASCS_RetryAuthentication");
		break;
	case RASCS_CallbackSetByCaller:
		Tishi = _T("RASCS_CallbackSetByCaller");
		break;
	case RASCS_PasswordExpired:
		Tishi = _T("RASCS_PasswordExpired");
		break;
	case RASCS_Connected:
		Tishi = _T("RASCS_Connected");
		break;
	case RASCS_Disconnected:
		Tishi = _T("RASCS_Disconnected");
		break;
	default:
		
		break;
	}
	MessageBox(NULL, Tishi, _T("error"), NULL);
}
bool radidal::hasLpsz()
{
	int dwError;
	dwError = RasValidateEntryName(NULL, lpszEntry);
	if (dwError != ERROR_SUCCESS) {
		return true;
	}
	else return false;
}
int radidal::rasdial()
{
	hRasConn = NULL;
	ipv6Flag = false;
	DWORD dwError = ERROR_SUCCESS;
	BOOL nRet = TRUE;
	//
	LPTSTR lpszdevicename = L"PPPoe";
	CString error_ras;
	dwError = RasValidateEntryName(NULL, lpszEntry);
	if (dwError != ERROR_SUCCESS) {
	}
	else {
		
		// Create and set the new entry's properties
		dwError = RasSetEntryProperties(NULL, lpszEntry, lpentry, lpentry->dwSize, NULL, 0);
		if (dwError != ERROR_SUCCESS) {
			//wprintf(L"RasSetEntryProperties failed: Error = %d\n", dwError);
			error_ras = "RasSetEntryProperties failed: Error=用户没有正确的权限，只有管理员可以完成或者缓冲区无效，或电话簿损坏，或BUG";
			MessageBox(NULL, error_ras, _T("error"), NULL);
			return 1;
		}
	}
	//char *entryname = "点击网络";//如果不是拨号条目里面的，那么不能拨号，必须是拨号条目里面的/。
							 /*char *username = "3120150901232@xhu";
							 char *password = "157833";*/
	//CHAR* username = RAS_USR; 
	//CHAR* password = RAS_PWD;
	RasPragma.dwSize = sizeof(RASDIALPARAMSW);
	//strcpy_s(RasPragma.szEntryName, entryname);//set PPPOE Dial up entry name
											   //strcpy_s(RasPragma.szPhoneNumber, "");
											   //strcpy_s(RasPragma.szCallbackNumber, "");
	//strcpy_s(RasPragma.szUserName, username);//set PPPOE Dial up user name
	//strcpy_s(RasPragma.szPassword, password);//set PPPOE Dial up password
											 //strcpy_s(RasPragma.szDomain, "");
											 //指定的拨号连接。
	//RasPragma.szUserName = username;
	int tempLength = wcslen(lpszEntry);
	StringCchCopyN(RasPragma.szEntryName, RAS_MaxDeviceName, lpszEntry, tempLength);
	tempLength = wcslen(RAS_USR);
	StringCchCopyN(RasPragma.szUserName, RAS_MaxDeviceName, RAS_USR, tempLength);
	tempLength = wcslen(RAS_PWD);
	StringCchCopyN(RasPragma.szPassword, RAS_MaxDeviceName, RAS_PWD, tempLength);
	int w = RasSetEntryDialParams(NULL, &RasPragma, true);
	//error_ras.Format(_T("%d"), w);
	//MessageBox(NULL, error_ras, _T("error"), NULL);
	//LPRASDIALDLG lpInfo = (LPRASDIALDLG)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(RASDIALDLG));
	//lpInfo->dwSize = sizeof(RASDIALDLG);
	//int nRet2 = RasDialDlg(NULL, lpszEntry, NULL, lpInfo);
	RASCREDENTIALSW RasCredent = { 0 };
	RasCredent.dwSize = sizeof(RASCREDENTIALSA);
	//strcpy_s(RasCredent.szUserName, RAS_USR);
	//strcpy_s(RasCredent.szPassword, RAS_PWD);
	tempLength = wcslen(RAS_USR);
	StringCchCopyN(RasCredent.szUserName, RAS_MaxDeviceName, RAS_USR, tempLength);
	tempLength = wcslen(RAS_PWD);
	StringCchCopyN(RasCredent.szPassword, RAS_MaxDeviceName, RAS_PWD, tempLength);
	RasCredent.dwMask = RASCM_UserName | RASCM_Password;

	RasSetCredentialsW(NULL, lpszEntry, &RasCredent, 0);
	int nRet2 = RasDialW(NULL, NULL, &RasPragma, 0, NULL, &hRasConn);
	tempLength = wcslen(RAS_USR);
	//error_ras.Format(_T("%d"), tempLength);
	//MessageBox(NULL, error_ras, _T("error"), NULL);

	if (RAS_USR[tempLength-1]=='u')
	{
		ipv6Flag = true; 
		//error_ras = "have xhu";
		//MessageBox(NULL, error_ras, _T("error"), NULL);
	}
	if (ERROR_SUCCESS == nRet2)
	{

	}
	else
	{
		error_ras = "拨号错误，返回错误码："; 
		CString temp; temp.Format(_T("%d"), nRet2);
		CString temp2 = _T("\n百度路由和远程访问错误代码\n可尝试一、修改账号密码二、点击 帮助 清空配置  重新配置!");
		MessageBox(NULL, error_ras + temp + temp2, _T("error"), NULL);
		return 1;
	}
	return 0;
}

int radidal::
rasdial2()
{
	HRASCONN hRasConn2 = NULL;
	RASDIALPARAMS rdParams = { 0 };
	DWORD dwRet;
	BOOL f_get_password;
	CString error_t;
	rdParams.dwSize = sizeof(RASDIALPARAMS);
	int tempLength = wcslen(lpszEntry);
	StringCchCopyN(rdParams.szEntryName, RAS_MaxDeviceName, lpszEntry, tempLength);
	
	dwRet = RasGetEntryDialParams(NULL, &rdParams, &f_get_password);
	//error_t.Format(_T("%s+%s+%s"), rdParams.szUserName, rdParams.szPassword, rdParams.szEntryName);
	//MessageBox(NULL, error_t, L"error", 0);
	if (dwRet != 0)
	{
		error_t.Format(_T("%d"), dwRet);
		MessageBox(NULL, error_t+L"-Dial Failed, get entry adsl failed", L"error", 0);

		return 1;
	}
	if (f_get_password == false)
	{
		MessageBox(NULL, L"error", L"Dial Failed: get password failed", 0);

		//return 1;
	}
	dwRet  = RasDialW(NULL, NULL, &rdParams, 0L, NULL, &hRasConn2);
	if (dwRet != 0)
	{
		error_t.Format(_T("%d"), dwRet);
		MessageBox(NULL, error_t + L"Dial Failed",L"error", 0);
		return 1;
	}
	return 0;

}

int radidal::disconn()
{
	if (hRasConn != NULL)
	{
		RasHangUp(hRasConn);
		Sleep(2000);
		hRasConn = NULL;
	}
	return 0;
}

int radidal::getipinfo()
{
	ipv4 = L"NULL"; ipv6 = L"NULL";;
	DWORD dwCb = 0;
	DWORD dwRet = ERROR_SUCCESS;
	DWORD dwConnections = 0;//connect number
	RASCONN rasconn;
	rasconn.dwSize = sizeof(RASCONN);
	dwRet = RasEnumConnections(&rasconn, &rasconn.dwSize, &dwConnections);
	

	if (dwRet == 0)
	{
		if (dwConnections)   // 一般只有一个活动连接
		{
			CString error_ras;

			DWORD dwCb = 0;
			DWORD dwRet = ERROR_SUCCESS;
			RASPPPIP rip;
			rip.dwSize = sizeof(RASPPPIP);
			
			RASPPPIPV6 rip2;
			rip2.dwSize = sizeof(RASPPPIPV6);
			DWORD ll;// , ret;

			int dws = RasGetProjectionInfo(rasconn.hrasconn, RASP_PppIp, (LPVOID)&rip, (LPDWORD)&ll);
			if (dws == ERROR_SUCCESS) {
				//cout << rip.szIpAddress << endl;
				//cout << rip.szServerIpAddress << endl;
				ipv4.Format(_T("%s"), rip.szIpAddress);
			}
			else if (dws == ERROR_BUFFER_TOO_SMALL)
			{
				error_ras = "SHOW IPV4 ERROR_BUFFER_TOO_SMALL";
				MessageBox(NULL, error_ras, _T("error"), NULL);
			}
			else if (dws == ERROR_INVALID_HANDLE) {
				error_ras = "SHOW IPV4 ERROR_INVALID_HANDLE";
			}
			else if (dws == ERROR_INVALID_PARAMETER) {
				error_ras = "SHOW IPV4 ERROR_INVALID_PARAMETER";	MessageBox(NULL, error_ras, _T("error"), NULL);
			}
			else if (dws == ERROR_INVALID_SIZE) {
				error_ras = "SHOW IPV4 ERROR_INVALID_SIZE";	MessageBox(NULL, error_ras, _T("error"), NULL);
			}
			else if (dws == ERROR_PROTOCOL_NOT_CONFIGURED) {
				error_ras = "SHOW IPV4 ERROR_PROTOCOL_NOT_CONFIGURED\n不是用rasdia拨号";	MessageBox(NULL, error_ras, _T("error"), NULL);
			}
			if (ipv6Flag)//获取ipv6
			{
				dws = RasGetProjectionInfo(rasconn.hrasconn, RASP_PppIpv6, (LPVOID)&rip2, (LPDWORD)&ll);
				if (dws == ERROR_SUCCESS) {
					/*for (int i = 0; i < 8; i++)cout << hex << (int)rip2.bLocalInterfaceIdentifier[i] << " ";
					cout << endl;*/
					CString t[8];
					for (int i = 0; i < 8; i++)
					{
						t[i].Format(_T("%02x"), (int)rip2.bLocalInterfaceIdentifier[i]);
					}
					ipv6 = t[0] + t[1] + _T(":");// MessageBox(NULL, ipv6, _T("error"), NULL);
					ipv6 = ipv6 + t[2] + t[3] + _T(":");
					ipv6 = ipv6 + t[4] + t[5] + _T(":");
					ipv6=ipv6+t[6] + t[7];
				}
				else if (dws == ERROR_BUFFER_TOO_SMALL) {
					error_ras = "SHOW IPV6 ERROR_BUFFER_TOO_SMALL";
					MessageBox(NULL, error_ras, _T("error"), NULL);
				}
				else if (dws == ERROR_INVALID_HANDLE) {
					error_ras = "SHOW IPV6 ERROR_INVALID_HANDLE";	MessageBox(NULL, error_ras, _T("error"), NULL);
				}
				else if (dws == ERROR_INVALID_PARAMETER) {
					error_ras = "SHOW IPV6 ERROR_INVALID_PARAMETER";	MessageBox(NULL, error_ras, _T("error"), NULL);
				}
				else if (dws == ERROR_INVALID_SIZE) {
					error_ras = "SHOW IPV6 ERROR_INVALID_SIZE";	MessageBox(NULL, error_ras, _T("error"), NULL);
				}
				else if (dws == ERROR_PROTOCOL_NOT_CONFIGURED) {
					//error_ras = "SHOW IPV6 ERROR_PROTOCOL_NOT_CONFIGURED";	MessageBox(NULL, error_ras, _T("error"), NULL);
					ipv6 = _T("无");
				}
			}
			//使用后清除
			//ipv6Flag = false;
		}
	}
	
	return 0;
}

CString radidal::getconinfo()
{
	if (!hRasConn)
	{
		//	LPRASCONNSTATUS lprasconnstatus = { 0 };
		//lprasconnstatus[0].dwSiz

		LPRASCONNSTATUS lprasconnstatus = (LPRASCONNSTATUS)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(LPRASCONNSTATUS));
		lprasconnstatus->dwSize = sizeof(RASCONNSTATUS);
		RasGetConnectStatus(hRasConn, lprasconnstatus);
		lprasconnstatus->rasconnstate;
		CString Tishi;
		switch (lprasconnstatus->rasconnstate)
		{
		case RASCS_OpenPort:
			Tishi = _T("RASCS_OpenPort");
			break;
		case RASCS_PortOpened:
			Tishi = _T("RASCS_PortOpened");
			break;
		case RASCS_ConnectDevice:
			Tishi = _T("RASCS_ConnectDevice");
			break;
		case RASCS_DeviceConnected:
			Tishi = _T("RASCS_DeviceConnected");
			break;
		case RASCS_AllDevicesConnected:
			Tishi = _T("RASCS_AllDevicesConnected");
			break;
		case RASCS_Authenticate:
			Tishi = _T("RASCS_Authenticate");
			break;
		case RASCS_AuthNotify:
			Tishi = _T("RASCS_AuthNotify");
			break;
		case RASCS_AuthRetry:
			Tishi = _T("RASCS_AuthRetry");
			break;
		case RASCS_AuthCallback:
			Tishi = _T("RASCS_AuthCallback");
			break;
		case RASCS_AuthChangePassword:
			Tishi = _T("RASCS_AuthChangePassword");
			break;
		case RASCS_AuthProject:
			Tishi = _T("RASCS_AuthProject");
			break;
		case RASCS_AuthLinkSpeed:
			Tishi = _T("RASCS_AuthLinkSpeed");
			break;
		case RASCS_AuthAck:
			Tishi = _T("RASCS_AuthAck");
			break;
		case RASCS_ReAuthenticate:
			Tishi = _T("RASCS_ReAuthenticate");
			break;
		case RASCS_Authenticated:
			Tishi = _T("RASCS_Authenticated");
			break;
		case RASCS_PrepareForCallback:
			Tishi = _T("RASCS_PrepareForCallback");
			break;
		case RASCS_WaitForModemReset:
			Tishi = _T("RASCS_WaitForModemReset");
			break;
		case RASCS_WaitForCallback:
			Tishi = _T("RASCS_WaitForCallback");
			break;
		case RASCS_Interactive:
			Tishi = _T("RASCS_Interactive");
			break;
		case RASCS_RetryAuthentication:
			Tishi = _T("RASCS_RetryAuthentication");
			break;
		case RASCS_CallbackSetByCaller:
			Tishi = _T("RASCS_CallbackSetByCaller");
			break;
		case RASCS_PasswordExpired:
			Tishi = _T("RASCS_PasswordExpired");
			break;
		case RASCS_Connected:
			Tishi = _T("RASCS_Connected");
			break;
		case RASCS_Disconnected:
			Tishi = _T("RASCS_Disconnected");
			break;
		default:
			break;
		}
		//MessageBox(NULL, Tishi,_T("terr"),NULL);
		return Tishi;
	}
	return _T("未连接");
}

radidal::~radidal()
{
	HeapFree(GetProcessHeap(), 0, lpentry);
	HeapFree(GetProcessHeap(), 0, lpInfo);
	//if (hRasConn != NULL)
	//{
		//RasHangUp(hRasConn);
	//	Sleep(2000);
	//	hRasConn = NULL;
	//}
}

//活动连接有的话设置flag
int pop::enum_conn()
{

	DWORD dwCb = 0;
	DWORD dwRet = ERROR_SUCCESS;
	DWORD dwConnections = 0;
	LPRASCONN lpRasConn = NULL;
	//CHAR *temp;
	// Call RasEnumConnections with lpRasConn = NULL. dwCb is returned with the required buffer size and 
	// a return code of ERROR_BUFFER_TOO_SMALL
	dwRet = RasEnumConnections(lpRasConn, &dwCb, &dwConnections);

	if (dwRet == ERROR_BUFFER_TOO_SMALL) {
		// Allocate the memory needed for the array of RAS structure(s).
		lpRasConn = (LPRASCONN)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, dwCb);
		if (lpRasConn == NULL) {
			//wprintf(L"HeapAlloc failed!\n");
			error_ras = "HeapAlloc failed!\n";
			MessageBox(NULL, error_ras, _T("提示"), NULL);
			return 1;
		}
		// The first RASCONN structure in the array must contain the RASCONN structure size
		lpRasConn[0].dwSize = sizeof(RASCONN);

		// Call RasEnumConnections to enumerate active connections
		dwRet = RasEnumConnections(lpRasConn, &dwCb, &dwConnections);
		// If successful, print the names of the active connections.
		if (ERROR_SUCCESS == dwRet) {
			//wprintf(L"The following RAS connections are currently active:\n");
			for (DWORD i = 0; i < dwConnections; i++) {
				//wprintf(L"%s\n", lpRasConn[i].szEntryName);
				//temp = lpRasConn[i].szEntryName;
				activeConn = lpRasConn[i].szEntryName;	
				
				flag = 1;
				//printf("%s\n", temp);
			}
			//error_ras=L"已连接网络，连接网络名为：";
			//MessageBox(NULL, error_ras+activeConn, _T("提示"), NULL);
			HeapFree(GetProcessHeap(), 0, lpRasConn);
			lpRasConn = NULL;
			return 2;
		}
		//Deallocate memory for the connection buffer
		HeapFree(GetProcessHeap(), 0, lpRasConn);
		lpRasConn = NULL;
		return 0;
	}
	return 0;
}
int pop::disconn()
{
	//DWORD dwCb = 0;
	//DWORD dwRet = ERROR_SUCCESS;
	//DWORD dwConnections = 0;//connect number
	//LPRASCONN lpRasConn = NULL;
	//RasEnumConnections(lpRasConn, &dwCb, &dwConnections);
	//lpRasConn = (LPRASCONN)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, dwCb);
	//if (lpRasConn == NULL) {
	//	//wprintf(L"HeapAlloc failed!\n");
	//	error_ras = "Active HeapAlloc failed! ";
	//	throw error_ras;
	//}
	//// The first RASCONN structure in the array must contain the RASCONN structure size
	//lpRasConn[0].dwSize = sizeof(RASCONN);

	//// Call RasEnumConnections to enumerate active connections
	//dwRet = RasEnumConnections(lpRasConn, &dwCb, &dwConnections);
	//char *temp = lpRasConn[0].szEntryName;
	//AcitiveEnumenter = temp;
	//printf("%s\n", temp);
	//RasHangUp(lpRasConn->hrasconn);
	//HeapFree(GetProcessHeap(), 0, lpRasConn);

	DWORD dwCb = 0;
	DWORD dwRet = ERROR_SUCCESS;
	DWORD dwConnections = 0;//connect number
	RASCONN rasconn;
	rasconn.dwSize = sizeof(RASCONN);
	dwRet = RasEnumConnections(&rasconn, &rasconn.dwSize, &dwConnections);
	if (dwRet == 0)
	{
		if (dwConnections)   // 一般只有一个活动连接
		{
			RasHangUp(rasconn.hrasconn);flag = 0;
			Sleep(2000);
			
		}
	}
	return ERROR_SUCCESS;
}