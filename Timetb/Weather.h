#pragma once
#include "explorer1.h"


// Weather ��ȭ �����Դϴ�.

class Weather : public CDialog
{
	DECLARE_DYNAMIC(Weather)

public:
	Weather(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~Weather();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_WEATHER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CExplorer1 weather;
	virtual BOOL OnInitDialog();
};
