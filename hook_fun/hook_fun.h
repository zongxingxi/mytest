
// hook_fun.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Chook_funApp:
// �йش����ʵ�֣������ hook_fun.cpp
//

class Chook_funApp : public CWinApp
{
public:
	Chook_funApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Chook_funApp theApp;