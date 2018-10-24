
// maskruleDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "dlg1.h"
#include "Dlg1.h"
#include "Dlg2.h"

// CmaskruleDlg 对话框
class CmaskruleDlg : public CDialogEx
{
// 构造
public:
	CmaskruleDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MASKRULE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tab;
	CDlg1 m_page1;
	CDlg2 m_page2;
	CDialog* pDialog[2];
	int m_CurSelTab;
	afx_msg void OnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedOk();
};
