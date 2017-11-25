

[TOC]

# xhuppppoe
西华大学仿生拨号客户端---name=
>描述:西华大学的客户端-*srun3k*和*西华大学上网客户端*都是以windows中rasapi来进行拨号的。其中，如果在windows系统中运行（win+r)输入rasphone命令，出现的asdl拨号簿，可以用之登陆学校的网络，移动网，电信网，联通网，还或校内网，办公网。只是各自在西华大学上网客户端中的用户名处需要各自增加域名。从前到后是@cmccgx,@96301,@unicom,@xhu,@office。同样在cmd命令窗口可以使用rasdial命令进行手动性拨号。

编写此程序理由：

1. 深澜客户端有时候会禁用电脑开热点，猎豹什么的，即使我很少用。
2. 校园网有ipv6，使用的是校内网登陆的。想给予一个方式使其他人知道如何去利用校内网进行一种学习。科学上网，查找学习资料等等。方便其他人，而且作为一个程序员，要使用自己写的软件，写自己的网站，用自己的程序，那才是对自己最友好的一个程序。
3. 进行对同学的介绍，被动可以知道后缀名，知道如何使用路由器进行上网。**知晓准确的账号**
3. 自己学会了MFC，自己对MFC的一点总结学习。学MFC，学使用api，学socks编程，学UI设计。



##2.0的期望

1. 期望可以实现sock的编程，无论是校内网还是其他网络可以实现**即时通讯**
2. 希望有个更好的UI设计

##1.1版本[api](#1.1Api)

 - 进行对程序最小化修改，放置在托盘
 - 对程序账号密码的默认记忆功能


##1.0版本[api](#1.0Api)
###功能

 - 简单的实现拨号程序
 - 简单的下载hosts并修改自己电脑的hosts文件，实现登陆校内网可以访问youtube
 - 登陆账号知道自己的ip地址，判定自己是否拥有ipv6



<span id="1.0Api">主要用到的API函数</span><br/>
######主要的头文件
```c++
#include <windows.h>
#include "ras.h"
#include "raserror.h"
#include "strsafe.h"
#include"RasDlg.h"
#pragma comment(lib, "Rasapi32.lib")
#pragma comment(lib, "Rasdlg.lib")
#pragma comment(lib, "Wininet.lib")
```

Rasapi
```c++
#include<ras.h>
/*函数
*RasSetEntryProperties
*RasEnumConnections
*RasEnumEntries
*RasSetCredentials
*Rasdial
*RasGetProjectionInfo
*RasGetEntryDialParams
*/
```
复制到剪贴板的函数
```c++
CString source=ipv4;
if (OpenClipboard())
	{
		//防止非ASCII语言复制到剪切板为乱码
		int buff_size = source.GetLength();
		CStringW strWide = CStringW(source);
		int nLen = strWide.GetLength();
		//将剪切板置空
		::EmptyClipboard();
		HANDLE clipbuffer = ::GlobalAlloc(GMEM_DDESHARE, (nLen + 1) * 2);
		if (!clipbuffer)
		{
			::CloseClipboard();
			return;
		}
		char* buffer = (char*)::GlobalLock(clipbuffer);
		memset(buffer, 0, (nLen + 1) * 2);
		memcpy_s(buffer, nLen * 2, strWide.GetBuffer(0), nLen * 2);
		strWide.ReleaseBuffer();
		::GlobalUnlock(clipbuffer);
		::SetClipboardData(CF_UNICODETEXT, clipbuffer);
		::CloseClipboard();
	}

```
下载文件api-网络编程
```c++
#include<WinInet.h>
#pragma comment(lib, "wininet.lib")  
#define BUF_SIZE 2048
#include<fstream>
/**函数
*InternetOpen
*InternetOpenUrlA
*InternetReadFile
*/
```
<sqpn id="1.1Api">托盘缩小</span>

```c++

//OnShowTask //回调

	NOTIFYICONDATA nid;
	nid.cbSize = (DWORD)sizeof(NOTIFYICONDATA);
	nid.hWnd = this->m_hWnd;
	nid.uID = IDR_MAINFRAME;
	nid.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
	nid.uCallbackMessage = WM_SHOWTASK;//自定义的消息名称
	nid.hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_MAINFRAME));
	wcscpy_s(nid.szTip, _T("拨号程序"));//信息提示条
	Shell_NotifyIcon(NIM_ADD, &nid);//在托盘区添加图标【NIM_DELETE]
	ShowWindow(SW_HIDE);//隐藏主窗口

```
