// MyAddress.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです。
//

#pragma once

#ifndef __AFXWIN_H__
	#error このファイルを PCH に含める前に、'stdafx.h' を含めてください。
#endif

#include "resource.h"		// メイン シンボル


#include <winuser.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
// Link with Iphlpapi.lib
#pragma comment(lib, "IPHLPAPI.lib")
// link with Ws2_32.lib
#pragma comment(lib,"Ws2_32.lib")


// CMyAddressApp:
// このクラスの実装については、MyAddress.cpp を参照してください。
//

class CMyAddressApp : public CWinApp
{
public:
	CMyAddressApp();

// オーバーライド
	public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CMyAddressApp theApp;
