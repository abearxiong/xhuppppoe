#include "stdafx.h"
#include "GtHosts.h"


GtHosts::GtHosts()
{
}


GtHosts::~GtHosts()
{
}

LPSTR GtHosts::GetInterNetURLText(LPSTR lpcInterNetURL, char * buff)
{

	HINTERNET hSession;
	LPSTR lpResult = NULL;
	hSession = InternetOpen(L"WinInet", INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
	__try
	{
		if (hSession != NULL)
		{
			HINTERNET hRequest;
			hRequest = InternetOpenUrlA(hSession, lpcInterNetURL, NULL, 0, INTERNET_FLAG_RELOAD, 0);
			__try
			{
				if (hRequest != NULL)
				{
					DWORD dwBytesRead;
					char szBuffer[BUF_SIZE] = { 0 };
					CString temp;
					fstream outfile("hosts", ios::out);
					if (outfile.bad())
					{
						MessageBox(NULL, L"创建文件失败", L"error", NULL);
						return 0;
					}
					while (InternetReadFile(hRequest, szBuffer, BUF_SIZE, &dwBytesRead))
					{
						RtlMoveMemory(buff, szBuffer, BUF_SIZE);
						outfile.write(szBuffer,BUF_SIZE);
						temp.Format(L"%s", szBuffer);
						if (dwBytesRead == 0)break;
						//Hosts = Hosts + temp;

					}
					Geted = true;
					outfile.close();
					return 0;
				}
			}
			__finally
			{
				InternetCloseHandle(hRequest);
			}
		}
	}
	__finally
	{
		InternetCloseHandle(hSession);
	}
	return lpResult;
}
