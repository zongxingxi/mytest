
// maskruleDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "dlg1.h"
#include "Dlg1.h"
#include "Dlg2.h"

// CmaskruleDlg �Ի���
class CmaskruleDlg : public CDialogEx
{
// ����
public:
	CmaskruleDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MASKRULE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
