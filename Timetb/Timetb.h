// Timetb.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CTimetbApp:
// �� Ŭ������ ������ ���ؼ��� Timetb.cpp�� �����Ͻʽÿ�.
//

class CTimetbApp : public CWinApp
{
public:
	CTimetbApp();

// �������Դϴ�.
	public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CTimetbApp theApp;