
// UIS63.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CUIS63App:
// �� Ŭ������ ������ ���ؼ��� UIS63.cpp�� �����Ͻʽÿ�.
//

class CUIS63App : public CWinApp
{
public:
	CUIS63App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CUIS63App theApp;