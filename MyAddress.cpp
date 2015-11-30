// MyAddress.cpp : アプリケーションのクラス動作を定義します。
//

#include "stdafx.h"
#include "MyAddress.h"
#include "MyAddressDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

BEGIN_MESSAGE_MAP(CMyAddressApp, CWinApp)
END_MESSAGE_MAP()

CMyAddressApp::CMyAddressApp()
{
}

CMyAddressApp theApp;

BOOL CMyAddressApp::InitInstance()
{
	WSADATA data;

	CWinApp::InitInstance();

	ZeroMemory(&data, sizeof(data));
	WSAStartup(MAKEWORD(2, 2), &data);

	CMyAddressDlg dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();

	WSACleanup();
	return FALSE;
}
