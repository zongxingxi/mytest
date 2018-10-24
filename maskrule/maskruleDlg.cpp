
// maskruleDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "maskrule.h"
#include "maskruleDlg.h"
#include "afxdialogex.h"

#include "json/json_helper.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CmaskruleDlg 对话框




CmaskruleDlg::CmaskruleDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CmaskruleDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CmaskruleDlg::DoDataExchange(CDataExchange* pDX)
{
	DDX_Control(pDX, IDC_TAB1, m_tab);
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CmaskruleDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CmaskruleDlg::OnSelchangeTab1)
	ON_BN_CLICKED(IDOK, &CmaskruleDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CmaskruleDlg 消息处理程序

BOOL CmaskruleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_tab.InsertItem(0, _T("test1"));
	m_tab.InsertItem(1, _T("test2"));

	m_page1.Create(IDD_DIALOG1, &m_tab);
	m_page2.Create(IDD_DIALOG2, &m_tab);

	CRect rc;
	m_tab.GetClientRect(rc);
	rc.top += 23;
	rc.bottom -= 3;
	rc.left += 3;
	rc.right -= 3;
	
	m_page1.MoveWindow(&rc);
	m_page2.MoveWindow(&rc);

	pDialog[0] = &m_page1;
	pDialog[1] = &m_page2;

	pDialog[0]->ShowWindow(SW_SHOW);
	pDialog[1]->ShowWindow(SW_HIDE);
	m_CurSelTab = 0;

	m_page1.SetBackgroundColor(RGB(255,255,255));
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CmaskruleDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CmaskruleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CmaskruleDlg::OnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	pDialog[m_CurSelTab]->ShowWindow(SW_HIDE);
	m_CurSelTab = m_tab.GetCurSel();
	pDialog[m_CurSelTab]->ShowWindow(SW_SHOW);
	*pResult = 0;
}


void CmaskruleDlg::OnBnClickedOk()
{
	int page1_check1 = ((CButton*)m_page1.GetDlgItem(IDC_CHECK1))->GetCheck();
	int page1_check2 = ((CButton*)m_page1.GetDlgItem(IDC_CHECK2))->GetCheck();
	int page1_check3 = ((CButton*)m_page1.GetDlgItem(IDC_CHECK3))->GetCheck();
	int page1_check4 = ((CButton*)m_page1.GetDlgItem(IDC_CHECK4))->GetCheck();

	int page2_check1 = ((CButton*)m_page2.GetDlgItem(IDC_CHECK1))->GetCheck();
	int page2_check2 = ((CButton*)m_page2.GetDlgItem(IDC_CHECK2))->GetCheck();
	int page2_check3 = ((CButton*)m_page2.GetDlgItem(IDC_CHECK3))->GetCheck();
	int page2_check4 = ((CButton*)m_page2.GetDlgItem(IDC_CHECK4))->GetCheck();

	Json::Value value;
	auto& json_page1 = value["page1"] ;
	json_page1["phone"] = page1_check1;
	json_page1["idcard"] = page1_check2;
	json_page1["cardid"] = page1_check3;
	json_page1["address"] = page1_check4;

	auto& json_page2 = value["page2"] ;
	json_page2["phone"] = page2_check1;
	json_page2["idcard"] = page2_check2;
	json_page2["cardid"] = page2_check3;
	json_page2["address"] = page2_check4;

	Json::FastWriter write;
	std::string out_str = write.write(value);

	SetDlgItemTextA(m_hWnd, IDC_EDIT1, out_str.c_str());
	
	//CDialogEx::OnOK();
}
