// Weather.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Timetb.h"
#include "Weather.h"


// Weather ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(Weather, CDialog)

Weather::Weather(CWnd* pParent /*=NULL*/)
	: CDialog(Weather::IDD, pParent)
{

}

Weather::~Weather()
{
}

void Weather::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EXPLORER1, weather);
}


BEGIN_MESSAGE_MAP(Weather, CDialog)
END_MESSAGE_MAP()


// Weather �޽��� ó�����Դϴ�.

BOOL Weather::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	CString strAppPath;
	GetCurrentDirectory(256,strAppPath.GetBuffer(256));
	CString strPath;

	strPath.Format(_T("http://m.kma.go.kr/m/observation/observation_01.jsp"),strAppPath);
	weather.Navigate(strPath,NULL,NULL,NULL,NULL);

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
