// Edit_AddDialog.cpp : implementation file
//

#include "stdafx.h"
#include "Timetb.h"
#include "Edit_AddDialog.h"
#include "AddTableDialog.h"
#include "stdlib.h"
#include "stdio.h"
#include "shlwapi.h"


// Edit_AddDialog dialog

IMPLEMENT_DYNAMIC(Edit_AddDialog, CDialog)

Edit_AddDialog::Edit_AddDialog(CWnd* pParent /*=NULL*/)
	: CDialog(Edit_AddDialog::IDD, pParent)
{

}

Edit_AddDialog::~Edit_AddDialog()
{
}

void Edit_AddDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_NEWNAME, new_name);
}


BEGIN_MESSAGE_MAP(Edit_AddDialog, CDialog)
	ON_BN_CLICKED(IDC_EDIT_ADD_ADD, &Edit_AddDialog::OnBnClickedEditAddAdd)
END_MESSAGE_MAP()


// Edit_AddDialog message handlers

void Edit_AddDialog::OnBnClickedEditAddAdd()
{
	AddTableDialog m_AddTableDlg;

	CString str;
	new_name.GetWindowTextW(str);
	CString path;
	path.Format(_T("\\dat\\%s.txt"),str);
	m_AddTableDlg.filename = str;

	CFile file;
	CFileException e;

	TCHAR nowPath[30000];
	GetModuleFileName(NULL, nowPath, 100); 
	//�������� ���μ����� ��� + ���ϸ� ��� �迭�� ����.
	PathRemoveFileSpec(nowPath); //������ ���ϸ� �κи� �����Ѵ�.

	CString nowfile_Path;
	nowfile_Path = nowPath;

	nowfile_Path += path;

	if(!file.Open(nowfile_Path, CFile::modeCreate | CFile::modeNoTruncate | CFile::modeRead, &e))
	{
		e.ReportError();
	}

	file.Close();

	OnOK();
	AfxMessageBox(_T("�ð�ǥ�� �߰��Ǿ����ϴ�. ����ȭ�鿡�� �ð�ǥ�� ���� ������ �߰��ϼ���."));
}
