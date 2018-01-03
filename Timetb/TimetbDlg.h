// TimetbDlg.h : ��� ����
//

#pragma once
#include "EditDialog.h"
#include "ShareDialog.h"
#include "WhatDIalog.h"
#include "SettingDialog.h"
#include "atltypes.h"
#include "afxwin.h"
#include "afxcmn.h"


// CTimetbDlg ��ȭ ����
class CTimetbDlg : public CDialog
{
// �����Դϴ�.
public:
	CTimetbDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.
	

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TIMETB_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnBnClickedEdit();
	afx_msg void OnBnClickedShare();
	afx_msg void OnBnClickedWhat();
	afx_msg void OnBnClickedSetting();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CRect timerect;
	CString name_str;
	bool chk_change;
	CEdit m_greet;
	CEdit m_time;
};
