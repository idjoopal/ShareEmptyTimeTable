// WhatShowDialog.cpp : implementation file
//

#include "stdafx.h"
#include "Timetb.h"
#include "WhatShowDialog.h"
#include "WhatDIalog.h"


// WhatShowDialog dialog

IMPLEMENT_DYNAMIC(WhatShowDialog, CDialog)

WhatShowDialog::WhatShowDialog(CWnd* pParent /*=NULL*/)
	: CDialog(WhatShowDialog::IDD, pParent)
	, whatindex(0)
	, genderindex(0)
{

}

WhatShowDialog::~WhatShowDialog()
{
}

void WhatShowDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EXPLORER1, html);
}


BEGIN_MESSAGE_MAP(WhatShowDialog, CDialog)
END_MESSAGE_MAP()


// WhatShowDialog message handlers

BOOL WhatShowDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	WhatDIalog what;
	CString strAppPath;
	GetCurrentDirectory(256,strAppPath.GetBuffer(256));
	CString strPath;


	if(whatindex == 0 && genderindex == 0)
	{
		strPath.Format(_T("file:///%s/html/���� 30�а���.html"),strAppPath);
		html.Navigate(strPath,NULL,NULL,NULL,NULL);
	}
	else if(whatindex == 0 && genderindex == 1)
	{
		strPath.Format(_T("file:///%s/html/���� 30�а���.html"),strAppPath);
		html.Navigate(strPath,NULL,NULL,NULL,NULL);
	}
	else if(whatindex == 1 && genderindex == 0)
	{
		strPath.Format(_T("file:///%s/html/���� 1�ð�����.html"),strAppPath);
		html.Navigate(strPath,NULL,NULL,NULL,NULL);
	}
	else if(whatindex == 1 && genderindex == 1)
	{
		strPath.Format(_T("file:///%s/html/���� 1�ð�����.html"),strAppPath);
		html.Navigate(strPath,NULL,NULL,NULL,NULL);
	}
	else if(whatindex == 2 && genderindex == 0)
	{
		strPath.Format(_T("file:///%s/html/���� 2�ð�����.html"),strAppPath);
		html.Navigate(strPath,NULL,NULL,NULL,NULL);
	}
	else if(whatindex == 2 && genderindex == 1)
	{
		strPath.Format(_T("file:///%s/html/���� 2�ð�����.html"),strAppPath);
		html.Navigate(strPath,NULL,NULL,NULL,NULL);
	}
	else if(whatindex == 3 && genderindex == 0)
	{
		strPath.Format(_T("file:///%s/html/���� 3�ð�����.html"),strAppPath);
		html.Navigate(strPath,NULL,NULL,NULL,NULL);
	}
	else if(whatindex == 3 && genderindex == 1)
	{
		strPath.Format(_T("file:///%s/html/���� 3�ð�����.html"),strAppPath);
		html.Navigate(strPath,NULL,NULL,NULL,NULL);
	}
	else
	{
		AfxMessageBox(_T("�׸��� �������� �ʾҽ��ϴ�."));
	}


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
