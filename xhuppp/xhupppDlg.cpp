
// xhupppDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "xhuppp.h"
#include "xhupppDlg.h"
#include "afxdialogex.h"
#include<iostream>
#include<WinInet.h>
using namespace std;
#include<string>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include<locale.h>


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
	
//	afx_msg void On32774();
	afx_msg void On32775();
	afx_msg void On32776();
	virtual BOOL OnInitDialog();
//	virtual BOOL DestroyWindow();
	afx_msg void OnClose();

	afx_msg void On32789();
	afx_msg void OnBnClickedMynewbutton();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	
//	ON_COMMAND(ID_32774, &CAboutDlg::On32774)
	ON_COMMAND(ID_32775, &CAboutDlg::On32775)
	ON_COMMAND(ID_32776, &CAboutDlg::On32776)
	ON_WM_CLOSE()

	ON_COMMAND(ID_32789, &CAboutDlg::On32789)
	ON_BN_CLICKED(IDC_MYNEWBUTTON, &CAboutDlg::OnBnClickedMynewbutton)
END_MESSAGE_MAP()


// CxhupppDlg 对话框



CxhupppDlg::CxhupppDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_XHUPPP_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_SelD = 0;
}

void CxhupppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_COMBO1, m_popYu);
	DDX_Control(pDX, IDC_COMBO1, m_Domin);
}

BEGIN_MESSAGE_MAP(CxhupppDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, &CxhupppDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CxhupppDlg::OnBnClickedButton1)
	ON_EN_SETFOCUS(IDC_EDIT1, &CxhupppDlg::OnEnSetfocusEdit1)
	ON_EN_SETFOCUS(IDC_EDIT2, &CxhupppDlg::OnEnSetfocusEdit2)
	ON_WM_TIMER()
	ON_CBN_SELENDOK(IDC_COMBO1, &CxhupppDlg::OnCbnSelendokCombo1)
	ON_STN_CLICKED(IDC_STATIC_USER, &CxhupppDlg::OnStnClickedStaticUser)
	ON_EN_KILLFOCUS(IDC_EDIT1, &CxhupppDlg::OnEnKillfocusEdit1)
	ON_BN_CLICKED(IDC_BUTTON_COPY4, &CxhupppDlg::OnBnClickedButtonCopy4)
	ON_BN_CLICKED(IDC_BUTTON_COPY6, &CxhupppDlg::OnBnClickedButtonCopy6)
	ON_COMMAND(ID_32771, &CxhupppDlg::On32771)
	ON_BN_CLICKED(IDC_BUTTON3, &CxhupppDlg::OnBnClickedButton3)
	ON_COMMAND(ID_32772, &CxhupppDlg::On32772)
	ON_COMMAND(ID_32774, &CxhupppDlg::On32774)
	ON_COMMAND(ID_32778, &CxhupppDlg::On32778)
	ON_WM_CLOSE()
	ON_WM_SIZE()
	ON_COMMAND(ID_32779, &CxhupppDlg::On32779)
	ON_MESSAGE(WM_SHOWTASK, OnShowTask)
	ON_COMMAND(ID_32785, &CxhupppDlg::On32785)
	ON_COMMAND(ID_32786, &CxhupppDlg::On32786)
	
	ON_COMMAND(ID_32773, &CxhupppDlg::On32773)
	ON_COMMAND(ID_32788, &CxhupppDlg::On32788)
	ON_EN_CHANGE(IDC_EDIT2, &CxhupppDlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT1, &CxhupppDlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CxhupppDlg 消息处理程序
pop A;
radidal ppppoe;

CString getUsr=NULL;CString getPwd = NULL;
CString setUsr = NULL;CString setPwd = NULL;
LPTSTR usr;// = new char[10];
LPTSTR pwd;
//bool DlgXiu = false;//判定修改过没
CString Showme = _T("        点击网络:514343378\n\r        学生网络多媒体中心\n\r                       4C310\r\n           TEL:028-87720159");
BOOL CxhupppDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	//设置combox
		m_Domin.InsertString(-1, L"未设定");//1--设定后缀处
	m_Domin.InsertString(DomXu, L"校内网：@xhu");
	m_Domin.InsertString(DomCM, L"移动网：@cmccgx");
	m_Domin.InsertString(DomUn, L"联通网：@unicom");
	m_Domin.InsertString(DomDX, L"电信网：@96301");
	m_Domin.InsertString(DomOf, L"办公网：@office");
	
	GetDlgItem(IDC_STATIC_SHOWME)->SetWindowText(Showme);
	//
	//m_Domin.SetCurSel(noDom);
	//第一步：查看有没有连接
	pop TempPpp;
	TempPpp.enum_conn();//如果有连接会返回flag=1；
	//打算修改
	//1.有连接
	if (TempPpp.flag == 1)
	{
		//打开二组，关闭一组；
		ShowGroup2();

		GetDlgItem(IDC_STATIC_ZT)->SetWindowText(TempPpp.activeConn);
		/*if (ERROR_SUCCESS == ppppoe.get_pppinfo())//得到user和password
		{
			//MessageBox(_T("tt"), _T("tt"), NULL);
			getUsr = ppppoe.user;
			getPwd = ppppoe.password;
		    m_SelLen = getUsr.GetLength();//确定有长度
			FindSel(getUsr);
			m_Domin.SetCurSel(m_SelD);
			GetDlgItem(IDC_EDIT1)->SetWindowText(getUsr);//uxm1e
			GetDlgItem(IDC_EDIT2)->SetWindowText(getPwd);
		}*/

		//获取ip地址
		//打开3组，关闭4组

		ShowGroup3();
		if (m_SelD == DomXu)
		{
			GetDlgItem(IDC_BUTTON_COPY6)->ShowWindow(SW_SHOW);
			ppppoe.ipv6Flag = true;

		}
		else
			GetDlgItem(IDC_BUTTON_COPY6)->ShowWindow(SW_HIDE);
		ppppoe.getipinfo();
		CString tipv6, tipv4;
		ipv4 = ppppoe.ipv4, ipv6 = ppppoe.ipv6;
		tipv4 = _T("IPV4:") + ppppoe.ipv4 + _T("\r\n"); CString ipv6Front; ipv6Front = _T(" 2001:250:2009:c000:\r\n");
		if (ppppoe.ipv6Flag)tipv6 = _T("IPV6:\r\n") + ipv6Front + ppppoe.ipv6;
		else
			tipv6 = _T("登陆的不是校内网，无V6!\r\n但也许能上外网。");
		//显示
		GetDlgItem(IDC_STATIC_SHOW)->SetWindowText(tipv4 + tipv6);
	
	}
	else {
		GetDlgItem(IDC_STATIC_ZT)->SetWindowText(_T("未连接"));
		//打开一组，关闭二组；
		ShowGroup1();
		//打开四组，关闭三组
		ShowMeClick();
		ShowGroup4();
	//2.无连接,查看有没有之前的连接,电话本，有的话获取账号密码，无的话显示空。
		if (ERROR_SUCCESS == ppppoe.get_pppinfo())
		{
			//MessageBox(_T("tt"), _T("tt"), NULL);
			getUsr = ppppoe.user;
			getPwd = ppppoe.password;
			m_SelLen = getUsr.GetLength();//确定有
			FindSel(getUsr);//查看后缀，然后设置
			m_Domin.SetCurSel(m_SelD);
			GetDlgItem(IDC_EDIT1)->SetWindowText(getUsr);
			GetDlgItem(IDC_EDIT2)->SetWindowText(getPwd);	
			//GetDlgItem(IDC_EDIT2)->SetFocus();
		}
	}
	HaveChange = false;
	ToTray();
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CxhupppDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	//增加关闭时最小化到托盘的函数
	//if ((nID & 0xFFF0) == SC_MINIMIZE)//SC_MINIMIZE   SC_CLOSE
	//{

	//	ToTray();
	//	return;

	//}
	
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CxhupppDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CxhupppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//断开连接
void CxhupppDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	//
	pop rasTemp; rasTemp.enum_conn();
	if (rasTemp.flag == 1)
	{
		rasTemp.disconn();//断开连接
		
	}
	//跳转到一组
	ShowGroup1();
	//A.enum_conn();
	//列出连接的过去的信息
	//显示组4
	ShowMeClick();
	ShowGroup4();
	GetDlgItem(IDC_STATIC_ZT)->SetWindowText(_T("未连接"));

	//if (ERROR_SUCCESS == ppppoe.get_pppinfo())
	//{
	//	//MessageBox(_T("tt"), _T("tt"), NULL);
	//	getUsr = ppppoe.user;
	//	getPwd = ppppoe.password;
	//	m_SelLen = getUsr.GetLength();//确定有
	//	FindSel(getUsr);//查看后缀，然后设置
	//	m_Domin.SetCurSel(m_SelD);
	//	GetDlgItem(IDC_EDIT1)->SetWindowText(getUsr);
	//	GetDlgItem(IDC_EDIT2)->SetWindowText(getPwd);
	//	//GetDlgItem(IDC_EDIT2)->SetFocus();
	//}
}

//拨号
void CxhupppDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//
	int dw = 0;
	if (m_SelD == -1)
	{
		MessageBox(_T("选择后缀"), L"提示", NULL);
		return;
	}
	//setlocale(LC_CTYPE, "utf-8");
	GetDlgItem(IDC_EDIT1)->GetWindowText(setUsr);
	GetDlgItem(IDC_EDIT2)->GetWindowText(setPwd);
	usr = (LPTSTR)(LPCTSTR)setUsr;
	pwd = (LPTSTR)(LPCTSTR)setPwd;
	ppppoe.setUP(usr, pwd);
	//ppppoe.setUP("3120150901232@xhu", "157833");
	//int val;
	SetTimer(1, 200, NULL);
	if (HaveChange)
	{
		//MessageBox(_T("111"), _T("sdf"), 0);
		dw = ppppoe.rasdial();
	}
	else
	{
		//MessageBox(_T("dfsf"), _T("sdf"), 0);
		dw = ppppoe.rasdial2();
	}HaveChange = false;
	if (dw == 1)return;
	//获取ip地址，并且设置
	
	//打开3组，关闭4组
	ShowGroup3();
	if (m_SelD == DomXu)
	{
		GetDlgItem(IDC_BUTTON_COPY6)->ShowWindow(SW_SHOW);
		ppppoe.ipv6Flag = true;

	}
	else
		GetDlgItem(IDC_BUTTON_COPY6)->ShowWindow(SW_HIDE);
	ppppoe.getipinfo();
	CString tipv6, tipv4;
	ipv4 = ppppoe.ipv4, ipv6 = ppppoe.ipv6;
	tipv4 = _T("IPV4:") + ppppoe.ipv4 + _T("\r\n"); CString ipv6Front; ipv6Front = _T(" 2001:250:2009:c000:\r\n");
	if (ppppoe.ipv6Flag)tipv6 = _T("IPV6:\r\n") + ipv6Front + ppppoe.ipv6;
	else
		tipv6 = _T("登陆的不是校内网，无V6!\r\n但也许能上外网。");
	//显示
	GetDlgItem(IDC_STATIC_SHOW)->SetWindowText(tipv4 + tipv6);


	pop rasTemp;
	rasTemp.enum_conn();//列举连接网络，设定flag
	GetDlgItem(IDC_STATIC_ZT)->SetWindowText(rasTemp.activeConn + _T("已连接"));
	if (dw == 0)
	{
		//跳转到二组
		SetTimer(1, 4000, NULL);
		//拨号成功点击关组一，打开组二
		ShowGroup2();
	}
	else return;
}


void CxhupppDlg::OnEnSetfocusEdit1()
{
	// TODO: 在此添加控件通知处理程序代码
	
}


void CxhupppDlg::OnEnSetfocusEdit2()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_EDIT2)->SetWindowText(_T(""));
	//点击后 就设定值
	
}
int TimerFlag = 0;
void CxhupppDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	switch (nIDEvent)
	{
	case 1:
		//GetDlgItem(IDC_STATIC_ZT)->SetWindowText(ppppoe.getconinfo());//显示更新
		//UpdateWindow();
		break;

	default:
		break;
	}
	CDialog::OnTimer(nIDEvent);
}

void CxhupppDlg::ShowMeClick()
{
	//CClientDC dc(this);

	CFont font; font.CreatePointFont(20, L"华文行楷", NULL);
	GetDlgItem(IDC_STATIC_SHOWME)->SetFont(&font);
	//GetDlgItem(IDC_STATIC_G1).setcolo
	GetDlgItem(IDC_STATIC_SHOWME)->SetWindowText(Showme);
}

void CxhupppDlg::ShowGroup1()
{
	GetDlgItem(IDC_STATIC_G1)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_STATIC_USER)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDIT1)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_STATIC_PWD)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDIT2)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_COMBO1)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_SHOW);

	//SW_SHOW SW_HIDE  IDC_STATIC_SHOWME
	//GetDlgItem(IDC_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_ZT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON2)->ShowWindow(SW_HIDE);
	

	//yincangwu
	GetDlgItem(IDC_EDIT_BH51)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT_BH52)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON3)->ShowWindow(SW_HIDE);
}

void CxhupppDlg::ShowGroup2()
{
	GetDlgItem(IDC_STATIC_G1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_USER)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_PWD)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT2)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_COMBO1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_HIDE);

	//SW_SHOW
	//GetDlgItem(IDC_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_STATIC_ZT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BUTTON2)->ShowWindow(SW_SHOW);
	

	//MessageBox(_T("d"), _T("d"), NULL);
	//yincangwu
	GetDlgItem(IDC_EDIT_BH51)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT_BH52)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON3)->ShowWindow(SW_HIDE);
}

void CxhupppDlg::ShowGroup3()
{
	GetDlgItem(IDC_STATIC_G3)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_STATIC_SHOW)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BUTTON_COPY4)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BUTTON_COPY6)->ShowWindow(SW_SHOW);
	//组4隐藏
	//GetDlgItem(IDC_EDIT2)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_STATIC_SHOWME)->ShowWindow(SW_HIDE);

	//yincangwu
	GetDlgItem(IDC_EDIT_BH51)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT_BH52)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON3)->ShowWindow(SW_HIDE);
}

void CxhupppDlg::ShowGroup4()
{
	GetDlgItem(IDC_STATIC_G3)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_SHOW)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON_COPY4)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON_COPY6)->ShowWindow(SW_HIDE);
	//四组打开
	ShowMeClick();
	GetDlgItem(IDC_STATIC_SHOWME)->ShowWindow(SW_SHOW);
	//yincangwu
	GetDlgItem(IDC_EDIT_BH51)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT_BH52)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON3)->ShowWindow(SW_HIDE);
}

void CxhupppDlg::ShowGroup5()
{
	GetDlgItem(IDC_EDIT_BH51)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDIT_BH52)->ShowWindow(SW_SHOW); 
	GetDlgItem(IDC_BUTTON3)->ShowWindow(SW_SHOW);

	GetDlgItem(IDC_STATIC_G3)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_SHOW)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON_COPY4)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON_COPY6)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_G1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_USER)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_PWD)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT2)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_COMBO1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_HIDE);
	//四组
	GetDlgItem(IDC_STATIC_SHOWME)->ShowWindow(SW_HIDE);
}

int CxhupppDlg::FindSel(CString UsrString)
{
	CString temp;
	//判断是否有@后缀
	if (m_SelLen>2)
	{

		int j = UsrString.Find('@');
		//temp.Format(_T("%d"), j);
		temp += UsrString.Right(m_SelLen - j - 1);
		//MessageBox(temp, _T("err"), NULL);
		//temp = UsrString.SetAt(i, m_SelLen);
		if (temp == L"xhu")
			//MessageBox(temp, _T("e2222r"), NULL);
			m_SelD = DomXu;
		else if (temp == L"cmccgx")
			m_SelD = DomCM;
		else if (temp == L"unicom")
			m_SelD = DomUn;
		else if (temp = L"96301")
			m_SelD = DomDX;
		else if (temp = L"office")
			m_SelD = DomOf;
		else
			m_SelD = noDom;
			return noDom;
	}
	else
		m_SelD = noDom;
		return noDom;//5
}

//一个函数，退出点击后，检查账号的后缀，然后设定。
int CxhupppDlg::DetermineDomin()
{
	CString UsrTemp,Temp2;
	GetDlgItem(IDC_EDIT1)->GetWindowText(UsrTemp);
	int UsrLength = UsrTemp.GetLength();//确定有值
	int FindU = UsrTemp.Find('@');
	if (FindU != -1) //找到@
	{
		CString Temp3 = UsrTemp.Right(UsrLength - FindU - 1);
		//查看还有没有@，有的话清掉后面的  --没有进行下一步
		if (Temp3.Find('@') != -1 ) {
			GetDlgItem(IDC_EDIT1)->SetWindowText(UsrTemp.Left(FindU));
			m_SelD = noDom;
			m_Domin.SetCurSel(noDom);
			return noDom;
		}
	}//没找到直接返回
	else {
		m_SelD = noDom;
		m_Domin.SetCurSel(noDom);
		return noDom;
	};
	
	if (FindU!=-1)
	{
		Temp2 = UsrTemp.Right(UsrLength - FindU - 1);
		if (Temp2 == L"xhu")
			return DomXu;
		else if (Temp2 == L"cmccgx")
			return DomCM;
		else if (Temp2 == L"unicom")
			return DomUn;
		else if (Temp2 == L"96301")
			return DomDX;
		else if (Temp2 == L"office")
			return DomOf;
		else 
			//m_SelD = noDom;
		return noDom;
	}
	//m_SelD = noDom;
	return noDom;
}

void CxhupppDlg::OnCbnSelendokCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	//一、选择
	int md = m_Domin.GetCurSel();
	m_SelD = md;
	//注释检验usr字符串的后面@的字符，如果不是后缀，那么设定提醒和修改
	//CString mdstr; mdstr.Format(L"md%d", md);
	//MessageBox(mdstr, _T("err"), NULL);
	//二、增加
	CString UsrTemp,UsrAddStr;
	GetDlgItem(IDC_EDIT1)->GetWindowText(UsrTemp);
	if(UsrTemp.Find('@') !=-1)//找到了
	UsrTemp = UsrTemp.Left(UsrTemp.Find('@'));
	else
	{
		if (UsrTemp.GetLength() > 2)
		{
			//添加,避免全删
		}
		else
		{
			m_SelD = noDom;
			m_Domin.SetCurSel(m_SelD);
			return;//返回
		}
	}switch (md)
	{
	case noDom:
		UsrAddStr = _T("");
		break;
	case DomCM:
		UsrAddStr = _T("@cmccgx");
		break;
	case DomXu:
		UsrAddStr = _T("@xhu");
		break;
	case DomDX:
		UsrAddStr = _T("@96301");
		break;
	case DomUn:
		UsrAddStr = _T("@unicom");
		break;
	case DomOf:
		UsrAddStr = _T("@office");
		break;
	default:
		UsrAddStr = _T("");
		break;
	}
	//三、检验
	int getMd;
	GetDlgItem(IDC_EDIT1)->SetWindowText(UsrTemp + UsrAddStr);
	getMd=DetermineDomin();//getmd=3 ooofice
	//CString Te; Te.Format(_T("getMd:%d md:%d"), getMd, md);
	if (md == getMd)
		return;
	else {
		m_SelD = noDom;
		m_Domin.SetCurSel(noDom);
	}
}


void CxhupppDlg::OnStnClickedStaticUser()
{
	// TODO: 在此添加控件通知处理程序代码
	//GetDlgItem(IDC_EDIT1)->SetFocus();
}

//离开焦点的时候
void CxhupppDlg::OnEnKillfocusEdit1()
{
	// TODO: 在此添加控件通知处理程序代码
	//检查最后字符串是不是规范的。
	
	//CString UsrTemp;
	//GetDlgItem(IDC_EDIT1)->GetWindowText(UsrTemp);
	int getMd;
	getMd = DetermineDomin();
	m_Domin.SetCurSel(getMd);
	m_SelD = getMd;
}


void CxhupppDlg::OnBnClickedButtonCopy4()
{
	// TODO: 在此添加控件通知处理程序代码
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
}


void CxhupppDlg::OnBnClickedButtonCopy6()
{
	// TODO: 在此添加控件通知处理程序代码
	CString source = ipv6;
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
}
radidal pppoe2;
static int clicknum = 0;
//点击第一次设置账号密码，点击第二次直接连接，连接失败，清掉
//查看有没有设定clickxhu,有的话设定clicknum为第一次
//连接成功设定clicknum=1，同时调用showgroup2
//有连接提示是否断开连接
void CxhupppDlg::On32771()
{
	// TODO: 在此添加命令处理程序代码
	//查看有没有连接
	pppoe2.setEntry();
	pop TempPpp;
	TempPpp.enum_conn();//如果有连接会返回flag=1；
						//打算修改
						//1.有连接
	CString error_t;
	if (TempPpp.flag == 1)
	{
		//打开二组，关闭一组；
		ShowGroup2();
		GetDlgItem(IDC_STATIC_ZT)->SetWindowText(TempPpp.activeConn);
		int i=MessageBox(TempPpp.activeConn + _T("已连接，是否断开？"), _T("提示"), 1);
		//如果是断开，则断开后继续，如果不是断开则是返回。
		//error_t.Format(_T("%d"), i);
		//MessageBox(error_t, _T("提示"),0);
		if (i == 1)
		{
			//MessageBox(TempPpp.activeConn + _T("已断开"), _T("提示"), 0);
			pop TempPpp2;
			TempPpp2.disconn();
			ShowGroup1();
			ShowGroup4();
			
		}return;
	}
	//没连接:
	//查看有没有clickxhu,如果有,且返回0，rasdia2直接登陆 //登陆成功返回
	if (pppoe2.hasLpsz())
	{
		
		if (pppoe2.rasdial2()!= 0)
		{
			pppoe2.disconn();
			pppoe2.clearEntry();
			return;//手动退出
		};
		//显示2组和3组
		pop rasTemp;
		rasTemp.enum_conn();//列举连接网络，设定flag
		GetDlgItem(IDC_STATIC_ZT)->SetWindowText(rasTemp.activeConn + _T("已连接"));
		ShowGroup2();
		ShowGroup3();

		pppoe2.get_pppinfo();
		CString s = pppoe2.user;
		if (s[s.GetLength()-1]=='u')
		{
			//MessageBox(_T("df"), _T("sdf"), NULL);
			GetDlgItem(IDC_BUTTON_COPY6)->ShowWindow(SW_SHOW);
			pppoe2.ipv6Flag = true;

		}
		else
			GetDlgItem(IDC_BUTTON_COPY6)->ShowWindow(SW_HIDE);
		pppoe2.getipinfo();
		CString tipv6, tipv4;
		ipv4 = pppoe2.ipv4, ipv6 = pppoe2.ipv6;
		tipv4 = _T("IPV4:") + pppoe2.ipv4 + _T("\r\n"); CString ipv6Front; ipv6Front = _T(" 2001:250:2009:c000:\r\n");
		if (pppoe2.ipv6Flag)tipv6 = _T("IPV6:\r\n") + ipv6Front + pppoe2.ipv6;
		else
			tipv6 = _T("登陆的不是校内网，无V6!\r\n但也许能上外网。");
		//显示
		GetDlgItem(IDC_STATIC_SHOW)->SetWindowText(tipv4 + tipv6);
		return;//登陆成功

	}

	//登陆失败设置重新设置账号密码
	
	ShowGroup5(); 
	//show5，账号和密码连接。




}

void CxhupppDlg::bohao()
{
}


void CxhupppDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	CString setUsr1, setPwd1;
	GetDlgItem(IDC_EDIT_BH51)->GetWindowText(setUsr1);
	GetDlgItem(IDC_EDIT_BH52)->GetWindowText(setPwd1);
	LPTSTR usr1, pwd1;
	usr1 = (LPTSTR)(LPCTSTR)setUsr1;
	pwd1 = (LPTSTR)(LPCTSTR)setPwd1;
	pppoe2.setUP(usr1, pwd1);
	if (pppoe2.rasdial() != 0)
	{
		pppoe2.clearEntry();
		return;
	};
	//连接成功显示组2和组4
	pop rasTemp;
	rasTemp.enum_conn();//列举连接网络，设定flag
	GetDlgItem(IDC_STATIC_ZT)->SetWindowText(rasTemp.activeConn + _T("已连接"));
	ShowGroup2();
	ShowGroup4();
}

//下载文件
void CxhupppDlg::On32772()
{
	CString ShowMe;
	CString temp_error;
	// TODO: 在此添加命令处理程序代码
	int guanli = MessageBox(_T("1.修改hosts必须需要是管理员运行，是否是管理员运行？\n确定继续，取消为关闭程序。"), _T("提示"), 1);
	//temp_error.Format(_T("%d"), guanli);
	//MessageBox(temp_error, _T("info"), 0);
	if (guanli == 2)
	{
		DestroyWindow();
		return;
	}
	GtHosts geturl;
	char buf[BUF_SIZE] = { 0 };
	char url[MAX_PATH] = "https://raw.githubusercontent.com/lennylxx/ipv6-hosts/master/hosts";
	//char url[MAX_PATH] = "https://msdn.microsoft.com/en-us/library/windows/desktop/aa385103(v=vs.85).aspx";
	CString TempShow = Showme + _T("\n"); CString Zifu = _T("==");

	GetDlgItem(IDC_STATIC_SHOWME)->SetWindowText(TempShow + _T("下载中")); Sleep(1000);
	geturl.GetInterNetURLText(url, buf);
	//MessageBox(geturl.Hosts, _T("输出"), 0);

	if (geturl.Geted)
	{
		TempShow = TempShow+Zifu;
		GetDlgItem(IDC_STATIC_SHOWME)->SetWindowText(TempShow);//1
		//MessageBox(L"2.登陆翻墙必须是校内网（学号和身份证后六位）！！\n3.访问为hosts文件内国外网址！hosts下载成功", L"提示1", NULL);
		temp_error = L"2.登陆翻墙必须是校内网（学号和身份证后六位）！！\n\r3.访问为hosts文件内国外网址！hosts下载成功\r\n";
		ShowMe =  temp_error;

		TempShow = TempShow + Zifu;
		GetDlgItem(IDC_STATIC_SHOWME)->SetWindowText(TempShow);//2
		fstream readfile("hosts",ios::in);
		if (!readfile.bad())
		{
			TempShow = TempShow + Zifu;
			GetDlgItem(IDC_STATIC_SHOWME)->SetWindowText(TempShow);//3
			//MessageBox(L"打开下载的hosts", L"提示2", NULL); 
			temp_error = L"4.下载了hosts，并且已经覆盖\r\n";
			ShowMe = ShowMe + temp_error;

			TempShow = TempShow + Zifu;
			GetDlgItem(IDC_STATIC_SHOWME)->SetWindowText(TempShow);//4
			char *filename = "C:\\Windows\\System32\\drivers\\etc\\hosts";
			//char *filename = "test\\host";
			//fstream writehosts(filename,ios::out);
			fstream writehosts("C:\\Windows\\System32\\drivers\\etc\\hosts", ios::out);

			TempShow = TempShow + Zifu;
			GetDlgItem(IDC_STATIC_SHOWME)->SetWindowText(TempShow);//5
			if (!writehosts.bad())
			{

				TempShow = TempShow + Zifu;
				GetDlgItem(IDC_STATIC_SHOWME)->SetWindowText(TempShow);//6
				//MessageBox(L"打开系统hosts也没错，复制下载的hosts到系统的", L"提示3", NULL);
				char szBuffer[BUF_SIZE] = { 0 };

				TempShow = TempShow + Zifu;
				GetDlgItem(IDC_STATIC_SHOWME)->SetWindowText(TempShow);//7
				while (!readfile.eof())
				{

					readfile.read(szBuffer, BUF_SIZE);
					temp_error.Format(L"%s----", szBuffer);
					writehosts.write(szBuffer, BUF_SIZE);
					//if(x<3){
					//MessageBox(temp_error, L"祝贺", NULL);
					//Sleep(1000);
					//x++;
				    //}
				}
				TempShow = TempShow + Zifu+Zifu;
				GetDlgItem(IDC_STATIC_SHOWME)->SetWindowText(TempShow);//8
				temp_error = L"成功\r\n";
				ShowMe = ShowMe + temp_error;
				MessageBox(ShowMe, L"提示", NULL);
				

			}
			writehosts.close();
			readfile.close();
		}
	}

	

	//删除hosts文件
	DeleteFile(L"hosts");
}




//void CAboutDlg::On32774()
//{
//	// TODO: 在此添加命令处理程序代码
//	CAboutDlg ABOUT;
//	ABOUT.DoModal();
//	GetDlgItem(IDD_ABOUTBOX)->ShowWindow(SW_SHOW);
//}

//一版本显示  版本显示 1.0版本
void CAboutDlg::On32775()
{
	// TODO: 在此添加命令处理程序代码GetDlgItem(IDC_STATIC_G1)->ShowWindow(SW_SHOW);
	//CButton *copy = new CMFCButton();
	//copy->Create(_T("复制github网址"), WS_CHILD | WS_VISIBLE | BP_PUSHBUTTON, CRect(20, 10, 150, 40), this, IDC_MYNEWBUTTON);
	
	CString InfoMy;
	InfoMy = _T("第一版本，也许也是最后一版本，源代码会贴在github---https://github.com/abearxiong/xhuppppoe\r\n也许有很多bug，但是注意功能自己可以实现了。功能\r\n1.实现很多人不知道拨号后缀，确定登陆账号和密码，知道路由器登陆。\r\n2.实现快捷拨号方式，保存了两种拨号，一种是必须设定账号密码，另一种目录上\"拨号\"，实现记忆功能个，拨号失败则会重新设置账号密码或者帮助中清除配置。\r\n3.设定获取hosts，登陆校内网有IPV6，可以实现登陆GOOGLE等一些国外IPV6网站，看youtube速度百兆带宽。\r\n4.获取登陆后的自己IP地址。\r\n5.科学上网的主要原理：是从网络github下载一个hosts文件，别人更新的关于ipv6地址的地址解析，把域名解析成ipv6地址，以至于自己不用输入ipv6地址既可以访问，因为某些原因Google的ipv6地址会变，所以需要更新。下载到本地后，把文件复制到C:\\Windows\\System32\\drivers\\etc\\hosts中，因为hosts是在系统文件夹里，所以需要管理员权限。同时下载github文件需要是在有网的网络状态中。\r\n\n6.ipv6能干什么，开通digitalocean，vultr，搬瓦工，可以实现登陆校内网访问ipv4，上QQ百度等内容。国内一些大型资源网站是IPV6，比如六维空间，北邮人，蒲公英，常见下载资源影视，音乐，学习资料，随时可以见单个分享出的资源上百G，百兆宽带和自己付费几兆相比，百兆下载速度快，而且资源全。通过双网卡，实现拨号双网，双网共用（仅校内网有ipv6），本人路由器拨号后wifi有ipv6，所以我可以使用双网。");
	GetDlgItem(IDC_STATIC_ABOUT1)->SetWindowText(InfoMy);
	GetDlgItem(IDC_STATIC_WANTCHANGE)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_STATIC_ABOUT1)->ShowWindow(SW_SHOW);
	//隐藏按钮
	
	GetDlgItem(IDC_MYNEWBUTTON)->SetWindowPos(GetDlgItem(IDC_STATIC_ABOUT1), 20, 400, 200, 40, 0);
	GetDlgItem(IDC_MYNEWBUTTON)->ShowWindow(SW_SHOW);
}

///版本改进想法  showChangeWant
void CAboutDlg::On32776()
{
	// TODO: 在此添加命令处理程序代码
	GetDlgItem(IDC_STATIC_ABOUT1)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_STATIC_WANTCHANGE)->ShowWindow(SW_SHOW);
	
	//隐藏按钮
	GetDlgItem(IDC_MYNEWBUTTON)->ShowWindow(SW_HIDE);
	
}


BOOL CAboutDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CString InfoMy;
	InfoMy = _T("第一版本，也许也是最后一版本，源代码会贴在github---https://github.com/abearxiong/xhuppppoe\r\n也许有很多bug，但是注意功能自己可以实现了。功能\r\n1.实现很多人不知道拨号后缀，确定登陆账号和密码，知道路由器登陆。\r\n2.实现快捷拨号方式，保存了两种拨号，一种是必须设定账号密码，另一种目录上\"拨号\"，实现记忆功能个，拨号失败则会重新设置账号密码或者帮助中清除配置。\r\n3.设定获取hosts，登陆校内网有IPV6，可以实现登陆GOOGLE等一些国外IPV6网站，看youtube速度百兆带宽。\r\n4.获取登陆后的自己IP地址。\r\n5.科学上网的主要原理：是从网络github下载一个hosts文件，别人更新的关于ipv6地址的地址解析，把域名解析成ipv6地址，以至于自己不用输入ipv6地址既可以访问，因为某些原因Google的ipv6地址会变，所以需要更新。下载到本地后，把文件复制到C:\\Windows\\System32\\drivers\\etc\\hosts中，因为hosts是在系统文件夹里，所以需要管理员权限。同时下载github文件需要是在有网的网络状态中。\r\n\n6.ipv6能干什么，开通digitalocean，vultr，搬瓦工，可以实现登陆校内网访问ipv4，上QQ百度等内容。国内一些大型资源网站是IPV6，比如六维空间，北邮人，蒲公英，常见下载资源影视，音乐，学习资料，随时可以见单个分享出的资源上百G，百兆宽带和自己付费几兆相比，百兆下载速度快，而且资源全。通过双网卡，实现拨号双网，双网共用（仅校内网有ipv6），本人路由器拨号后wifi有ipv6，所以我可以使用双网。");
	GetDlgItem(IDC_STATIC_ABOUT1)->SetWindowText(InfoMy);
	InfoMy = _T("如果有下一版本期望能力\r\n1.实现登陆校内网，因为ipv6互通，进行基于校内网的聊天，文件传输功能。\r\n2.基于ipv6对一些重要学习资料的传输。\r\n等等，还有很多没想到的，但是需要SOCKET编程。\r\n3.仅仅通过ipv6实现上网（全）功能\r\n4.如果有其他想法欢迎联系我");
	//CString InfoMy;
	GetDlgItem(IDC_STATIC_WANTCHANGE)->SetWindowText(InfoMy);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CxhupppDlg::On32774()
{
	// TODO: 在此添加命令处理程序代码
	
	CAboutDlg ABOUT;ShowWindow(SW_HIDE);
	ABOUT.DoModal();
	

	
}


//BOOL CAboutDlg::DestroyWindow()
//{
//	// TODO: 在此添加专用代码和/或调用基类
//	CWnd *a=GetParent();
//	a->ShowWindow(SW_SHOW);
//	return CDialogEx::DestroyWindow();
//}


void CxhupppDlg::On32778()
{
	// TODO: 在此添加命令处理程序代码
	CString helpdoc;
	helpdoc = _T("必须是连线的情况下，拨号学校的宽带。\r\n用目录上的拨号连上网络后可以断开程序\n\r1.清空配置，删除拨号记录\n\r2.点击右下角的小电脑，手动删除设定的宽带名称\r\n3.重启程序\r\n4.最终大法，重启电脑\r\n5.Q我1019443290，15级解决电脑小行家");
	MessageBox(helpdoc, _T("help"), NULL);
}


BOOL CxhupppDlg::DestroyWindow()
{
	// TODO: 在此添加专用代码和/或调用基类

	//MessageBox(_T("sd"), _T("d"), NULL);
	//extern CxhupppDlg dlg; 
	//dlg.DoModal();
	DeleteTray();
	return  CDialog::DestroyWindow();


}


void CAboutDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
    
	CDialogEx::OnClose();
	
}


void CxhupppDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	pop a;
	a.enum_conn();
	if (a.flag == 1)//有网络
	{
		//有连接最小化
		//CDialog::OnClose();
		//ShowWindow(SW_MINIMIZE);
		ShowWindow(SW_HIDE);
	}
	else
	{
		DestroyWindow();
		//CDialog::OnClose();
		
	}
	
}


void CxhupppDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);
	//MessageBox(_T("确认关闭？"), _T("提示"), 0);
	// TODO: 在此处添加消息处理程序代码
	//if (nType == SIZE_MINIMIZED)
	//{
	//	MessageBox(_T("确认关闭？"), _T("提示"), 0);
	//}
}

void CxhupppDlg::ToTray()
{
	NOTIFYICONDATA nid;
	nid.cbSize = (DWORD)sizeof(NOTIFYICONDATA);
	nid.hWnd = this->m_hWnd;
	nid.uID = IDR_MAINFRAME;
	nid.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
	nid.uCallbackMessage = WM_SHOWTASK;//自定义的消息名称
	nid.hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_MAINFRAME));
	wcscpy_s(nid.szTip, _T("拨号程序"));//信息提示条
	Shell_NotifyIcon(NIM_ADD, &nid);//在托盘区添加图标
	ShowWindow(SW_HIDE);//隐藏主窗口
}

LRESULT CxhupppDlg::OnShowTask(WPARAM wParam, LPARAM lParam)
{
	if (wParam != IDR_MAINFRAME)
	{
		//MessageBox(_T("不显示wparm"), _T("idr"), 0);
		return 1;
	}
	//MessageBox(_T("不显示wparm"), _T("idr"), 0);
	switch (lParam)
	{
	case WM_RBUTTONUP://右键起来时弹出快捷菜单，这里只有一个关闭
	{
		//LPPOINT lpoint = new tagPOINT;
		//::GetCursorPos(lpoint);//得到鼠标位置
		//CMenu menu;
		//menu.CreatePopupMenu();//声明一个弹出式菜单
		//					   //增加菜单项“关闭”，点击则发送消息WM_DESTROY给主窗口（已
		//					   //隐藏），将程序结束。
		//menu.AppendMenu(MF_STRING, WM_DESTROY, _T("退出"));
		////确定弹出式菜单的位置
		//menu.TrackPopupMenu(TPM_LEFTALIGN, lpoint->x, lpoint->y, this);
		////资源回收
		//HMENU hmenu = menu.Detach();
		//menu.DestroyMenu();
		//delete lpoint;
		CMenu menu;
		menu.LoadMenuW(IDR_MENU3);
		CPoint pt;
		GetCursorPos(&pt);
		GetForegroundWindow();
		
		menu.GetSubMenu(0)->TrackPopupMenu(TPM_RIGHTBUTTON, pt.x, pt.y, this);
		PostMessage(NULL, 0, 0);
	}
	break;
	case WM_LBUTTONDBLCLK://双击左键的处理
	{
		this->ShowWindow(SW_SHOW);//简单的显示主窗口
		this->ShowWindow(SW_RESTORE);
		//DeleteTray();
	}
	break;
	default:
		break;
	}


	return 0;
	//return LRESULT();
}

void CxhupppDlg::DeleteTray()
{
	NOTIFYICONDATA nid;
	nid.cbSize = (DWORD)sizeof(NOTIFYICONDATA);
	nid.hWnd = this->m_hWnd;
	nid.uID = IDR_MAINFRAME;
	nid.uFlags = NIF_ICON /*| NIF_MESSAGE | NIF_TIP*/;
	//nid.uCallbackMessage = WM_SHOWTASK;//自定义的消息名称
	//nid.hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_MAINFRAME));
	//wcscpy_s(nid.szTip, _T("***程序"));//信息提示条为“按计划任务提醒”
	Shell_NotifyIcon(NIM_DELETE, &nid);//在托盘中删除图标
}


void CxhupppDlg::On32779()
{
	// TODO: 在此添加命令处理程序代码
	SetFocus();
	ShowWindow(SW_SHOW);
	ShowWindow(SW_RESTORE);
}




void CxhupppDlg::On32785()
{
	//pop a;
	//a.enum_conn();
	//if (a.flag == true)//有网络
	//{
	//	//有连接最小化
	//	if (MessageBox(_T("当前连接网络是") + a.activeConn + _T("\r\n是否关闭并退出？否不退出"), _T("提示"), 1) == 1)
	//	{
	//		a.disconn(); CDialog::OnClose();
	//	}if (MessageBox(_T("确认关闭？"), _T("提示"), 1) == 1)
	//		CDialog::OnClose();
	//}

	DestroyWindow();
	// TODO: 在此添加命令处理程序代码
}


void CxhupppDlg::On32786()
{
	// TODO: 在此添加命令处理程序代码
	On32771();
}




void CxhupppDlg::On32773()
{
	// TODO: 在此添加命令处理程序代码
	// TODO: 在此添加命令处理程序代码
	radidal temp;
	temp.disconn();
	temp.clearEntry();
	temp.setEntry();
	temp.clearEntry();
	MessageBox(_T("删除记忆网络\r\nclickxhu和点击网络"), _T("提示"), NULL);
	//删除
}


void CxhupppDlg::On32788()
{
	// TODO: 在此添加命令处理程序代码
	On32772();
}


void CxhupppDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
	HaveChange = true;
	// TODO:  在此添加控件通知处理程序代码
}


void CxhupppDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
	HaveChange = true;
	// TODO:  在此添加控件通知处理程序代码
}

//显示1.1版本
void CAboutDlg::On32789()
{
	// TODO: 在此添加命令处理程序代码
	
	CString InfoMy;
	InfoMy = L"1.1版本\r\n修改了若干BUG\r\n1.增加了最小化按钮\r\n2.设定了拨号默认保存效果";

	GetDlgItem(IDC_STATIC_ABOUT1)->SetWindowText(InfoMy);

	GetDlgItem(IDC_STATIC_WANTCHANGE)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_STATIC_ABOUT1)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_MYNEWBUTTON)->ShowWindow(SW_HIDE);
}

//复制
void CAboutDlg::OnBnClickedMynewbutton()
{
	// TODO: 在此添加控件通知处理程序代码
	CString source=L"https://github.com/abearxiong/xhuppppoe";
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
}
