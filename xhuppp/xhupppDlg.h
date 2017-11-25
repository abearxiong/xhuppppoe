
// xhupppDlg.h: 头文件
//

#pragma once
#include "afxwin.h"
#include<shellapi.h>
#define noDom -1
#define DomXu 0
#define DomCM 1
#define DomUn 2
#define DomDX 3
#define DomOf 4

#define  WM_SHOWTASK (WM_USER + 1)

// CxhupppDlg 对话框
class CxhupppDlg : public CDialog
{
// 构造
public:
	CxhupppDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_XHUPPP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
//	CComboBox m_popYu;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnSetfocusEdit1();
	afx_msg void OnEnSetfocusEdit2();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void ShowMeClick();
	afx_msg void ShowGroup1();
	afx_msg void ShowGroup2();
	afx_msg void ShowGroup3();
	afx_msg void ShowGroup4();
	afx_msg void ShowGroup5();
	CComboBox m_Domin;
	int m_SelD=-1;//选择的是那个后缀
	int m_SelLen;//选择那个用户名的长度
	CString ipv4;
	CString ipv6;
	afx_msg int FindSel(CString UsrString);
	afx_msg int DetermineDomin();//判定后缀，返回后缀，删除等等。
	afx_msg void OnCbnSelendokCombo1();
	afx_msg void OnStnClickedStaticUser();
	afx_msg void OnEnKillfocusEdit1();
	afx_msg void OnBnClickedButtonCopy4();
	afx_msg void OnBnClickedButtonCopy6();
	afx_msg void On32771();
	afx_msg void bohao();
	afx_msg void OnBnClickedButton3();
	afx_msg void On32772();
	afx_msg void On32774();
	afx_msg void On32778();
	virtual BOOL DestroyWindow();
	afx_msg void OnClose();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void ToTray();
	afx_msg LRESULT  OnShowTask(WPARAM wParam, LPARAM lParam);
	afx_msg void DeleteTray();
	afx_msg void On32779();
	afx_msg void On32785();
	afx_msg void On32786();
	
	afx_msg void On32773();
	afx_msg void On32788();
	afx_msg void OnEnChangeEdit2();
private:
	bool HaveChange=false;
public:
	afx_msg void OnEnChangeEdit1();
};
