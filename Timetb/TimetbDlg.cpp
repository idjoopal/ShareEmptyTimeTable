// TimetbDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "Timetb.h"
#include "TimetbDlg.h"
#include "Weather.h"
#include "shlwapi.h"

#define ROWS 50
#define COLS 12.5


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CTimetbDlg ��ȭ ����




CTimetbDlg::CTimetbDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTimetbDlg::IDD, pParent)
	, name_str(_T(""))
	, chk_change(false)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTimetbDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT2, m_greet);
	DDX_Control(pDX, IDC_EDIT1, m_time);
}

BEGIN_MESSAGE_MAP(CTimetbDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_EDIT, &CTimetbDlg::OnBnClickedEdit)
	ON_BN_CLICKED(IDC_SHARE, &CTimetbDlg::OnBnClickedShare)
	ON_BN_CLICKED(IDC_WHAT, &CTimetbDlg::OnBnClickedWhat)
	ON_BN_CLICKED(IDC_SETTING, &CTimetbDlg::OnBnClickedSetting)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CTimetbDlg �޽��� ó����

BOOL CTimetbDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	system("mkdir dat");
	system("mkdir share");
	system("mkdir sys");

	CFile file;
	CFileException e;

	Weather wea;
	wea.DoModal();
	
	SetTimer(1,100,NULL);
	SetTimer(2,1000,NULL);

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CTimetbDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CTimetbDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CTimetbDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


BOOL CTimetbDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default
	
	CRect rect;
	GetClientRect(&rect);

	CDC dc;
	dc.CreateCompatibleDC(pDC);

	CBitmap bgbmp;
	CBitmap tablebmp;
	CBitmap logobmp;
	CBitmap applebmp;
	CBitmap sharkbmp;
	CBitmap milkbmp;
	CBitmap playboybmp;
	CBitmap totorobmp;
	
	tablebmp.LoadBitmapW(IDB_BITMAP1);
	bgbmp.LoadBitmapW(IDB_BITMAP2);
	logobmp.LoadBitmapW(IDB_BITMAP3);
	applebmp.LoadBitmapW(IDB_BITMAP4);
	sharkbmp.LoadBitmapW(IDB_BITMAP5);
	milkbmp.LoadBitmapW(IDB_BITMAP6);
	playboybmp.LoadBitmapW(IDB_BITMAP7);
	totorobmp.LoadBitmapW(IDB_BITMAP8);

	BITMAP bmpinfo;
	CBitmap *pbit = dc.SelectObject(&bgbmp);
	bgbmp.GetBitmap(&bmpinfo);
	pDC->StretchBlt(0,0,rect.Width(),rect.Height(), &dc, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);

	CFile file;
	CFileException e;
	char str[10] ={0};
	if(file.Open(_T("sys\\theme.txt"), CFile::modeCreate | CFile::modeNoTruncate | CFile::modeRead, &e))
	{
		file.Read(str,2);
		file.Close();	
	}
	int i = atoi(str);
	if(i==2)
	{
		dc.SelectObject(&applebmp);
		applebmp.GetBitmap(&bmpinfo);
		pDC->StretchBlt(0,0,rect.Width(),rect.Height(), &dc, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
	}
	else if(i==3)
	{
		dc.SelectObject(&sharkbmp);
		sharkbmp.GetBitmap(&bmpinfo);
		pDC->StretchBlt(0,0,rect.Width(),rect.Height(), &dc, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
	}
	else if(i==4)
	{
		dc.SelectObject(&milkbmp);
		milkbmp.GetBitmap(&bmpinfo);
		pDC->StretchBlt(0,0,rect.Width(),rect.Height(), &dc, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
	}
	else if(i==5)
	{
		dc.SelectObject(&playboybmp);
		playboybmp.GetBitmap(&bmpinfo);
		pDC->StretchBlt(0,0,rect.Width(),rect.Height(), &dc, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
	}
	else if(i==6)
	{
		dc.SelectObject(&totorobmp);
		totorobmp.GetBitmap(&bmpinfo);
		pDC->StretchBlt(0,0,rect.Width(),rect.Height(), &dc, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
	}

	dc.SelectObject(&tablebmp);
	tablebmp.GetBitmap(&bmpinfo);
	pDC->TransparentBlt(20,20,bmpinfo.bmWidth,bmpinfo.bmHeight,&dc,0,0,bmpinfo.bmWidth,bmpinfo.bmHeight,RGB(200,200,200));
	
	dc.SelectObject(&logobmp);
	logobmp.GetBitmap(&bmpinfo);
	pDC->TransparentBlt(500,460,100,50,&dc,0,0,bmpinfo.bmWidth,bmpinfo.bmHeight,RGB(200,200,200));
	
	dc.SelectObject(pbit);

	CTime theTime;
	theTime = CTime::GetCurrentTime();

	if(theTime.GetHour() >= 23 || theTime.GetHour() <= 2)
	{
		m_greet.SetWindowTextW(_T("���� ����׿�. ���� �ֹ�����."));
	}
	else if(theTime.GetHour() >= 3 && theTime.GetHour() <= 6)
	{
		m_greet.SetWindowTextW(_T("�̺���, �� �߰ſ���?"));
	}
	else if(theTime.GetHour() >= 7 && theTime.GetHour() <= 9)
	{
		m_greet.SetWindowTextW(_T("������ħ! ����� �ð�ǥ�� �Բ� ������ �Ϸ縦 �����ϼ���."));
	}
	else if(theTime.GetHour() >= 10 && theTime.GetHour() <= 11)
	{
		m_greet.SetWindowTextW(_T("����� �ð�ǥ�� �Բ� ���� �ϰ��� �غ��ϼ���."));
	}
	else if(theTime.GetHour() >= 12 && theTime.GetHour() <= 14)
	{
		m_greet.SetWindowTextW(_T("���� ���̸��� ģ���ֳ���? �����񱳱������ ģ���� ã�ƺ�����."));
	}
	else if(theTime.GetHour() >= 15 && theTime.GetHour() <= 17)
	{
		m_greet.SetWindowTextW(_T("�ȳ��ϼ���, ����ǽð�ǥ�Դϴ�."));
	}
	else if(theTime.GetHour() >= 18 && theTime.GetHour() <= 20)
	{
		m_greet.SetWindowTextW(_T("����Ļ� �ϼ̳���?"));
	}
	else if(theTime.GetHour() >= 21 && theTime.GetHour() <= 22)
	{
		m_greet.SetWindowTextW(_T("���� ���� ���������? ���� �ð�ǥ Ȯ���ϼ���."));
	}

	return true;
}


void CTimetbDlg::OnBnClickedEdit()
{
	// TODO: Add your control notification handler code here
	EditDialog edit;
	edit.DoModal();
}

void CTimetbDlg::OnBnClickedShare()
{
	// TODO: Add your control notification handler code here
	ShareDialog share;
	share.DoModal();
}

void CTimetbDlg::OnBnClickedWhat()
{
	// TODO: Add your control notification handler code here
	WhatDIalog what;
	what.DoModal();
}

void CTimetbDlg::OnBnClickedSetting()
{
	// TODO: Add your control notification handler code here
	SettingDialog setting;
	setting.DoModal();
}

void CTimetbDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	CTime theTime;
	theTime = CTime::GetCurrentTime();

	CString strmin;
	CString strsec;
	int ampm = 0;

	CString strtime;
	strtime = _T("���� �ð� - ");

	switch(nIDEvent)
	{
	case 1:
		//dc.SetBkMode(TRANSPARENT);
		if(theTime.GetHour() >= 13)
		{
			strtime += _T("PM ");
			ampm = theTime.GetHour()-12;
		}else
		{
			strtime += _T("AM ");
			ampm = theTime.GetHour();
		}
		if(theTime.GetMinute() <= 9)
		{
			strmin.Format(_T("%d : 0%d : "), ampm, theTime.GetMinute());
		}
		else
		{
			strmin.Format(_T("%d : %d : "), ampm, theTime.GetMinute());
		}

		if(theTime.GetSecond() <= 9)
		{
			strsec.Format(_T("0%d"), theTime.GetSecond());
		}
		else
		{
			strsec.Format(_T("%d "), theTime.GetSecond());
		}

		strtime += strmin;
		strtime += strsec;
		
		m_time.SetWindowTextW(strtime);

		break;

	case 2:
		CRect rect;
		GetClientRect(&rect);

		CDC memdc;
		memdc.CreateCompatibleDC(&dc);
		CBitmap tablebmp;
		tablebmp.LoadBitmapW(IDB_BITMAP1);
		BITMAP bmpinfo;
		CBitmap *pbit = (CBitmap*)memdc.SelectObject(&tablebmp);
		tablebmp.GetBitmap(&bmpinfo);
		dc.TransparentBlt(20,20,bmpinfo.bmWidth,bmpinfo.bmHeight,&memdc,0,0,bmpinfo.bmWidth,bmpinfo.bmHeight,RGB(200,200,200));
		memdc.SelectObject(pbit);

		CBrush m_brush;
		m_brush.CreateSolidBrush(RGB(180,180,180));
		dc.SelectObject(&m_brush);
		CFont font;
		font.CreatePointFont(70,_T("����"));  //�۾�ũ��, �۾�ü
		dc.SelectObject(&font);
		dc.SetBkMode(TRANSPARENT);

		CFile file;
		CFileException e;

		TCHAR nowPath[30000];
		GetModuleFileName(NULL, nowPath, 100); 
		//�������� ���μ����� ��� + ���ϸ� ��� �迭�� ����.
		PathRemoveFileSpec(nowPath); //������ ���ϸ� �κи� �����Ѵ�.

		CString nowfile_Path;
		nowfile_Path = nowPath;

		nowfile_Path += _T("\\dat\\maintable.txt");

		if(file.Open(nowfile_Path, CFile::modeCreate | CFile::modeNoTruncate | CFile::modeRead, &e))
		{
			char m_name[50]={0};
			char m_room[50]={0};
			char m_week[50]={0};
			char m_start[50]={0};
			char m_finish[50]={0};

			file.SeekToBegin();

			for(int i=0; i<file.GetLength()/350; i++)
			{
				file.Seek(50,CFile::current);
				file.Read(m_name,8);
				file.Seek(92,CFile::current);
				file.Read(m_room,8);
				file.Seek(42,CFile::current);
				file.Read(m_week,2);
				file.Seek(48,CFile::current);
				file.Read(m_start,2);
				file.Seek(48,CFile::current);
				file.Read(m_finish,2);
				file.Seek(48,CFile::current);

				int i_week=atoi(m_week);
				int i_start=atoi(m_start);
				int i_finish=atoi(m_finish);
				CString s_name, s_room;

				s_name = m_name;
				s_name += _T("..");

				s_room = m_room;

				dc.Rectangle(54+ROWS*i_week,54+COLS*i_start,54+ROWS+ROWS*i_week,54+COLS*i_finish);
				dc.TextOutW(60+ROWS*i_week,60+COLS*i_start,s_name);
				dc.TextOutW(60+ROWS*i_week,70+COLS*i_start,s_room);
			}
		}

		break;
	}

	CDialog::OnTimer(nIDEvent);
}

