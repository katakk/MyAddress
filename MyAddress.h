// MyAddress.h : PROJECT_NAME �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C���ł��B
//

#pragma once

#ifndef __AFXWIN_H__
	#error ���̃t�@�C���� PCH �Ɋ܂߂�O�ɁA'stdafx.h' ���܂߂Ă��������B
#endif

#include "resource.h"		// ���C�� �V���{��


#include <winuser.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
// Link with Iphlpapi.lib
#pragma comment(lib, "IPHLPAPI.lib")
// link with Ws2_32.lib
#pragma comment(lib,"Ws2_32.lib")


// CMyAddressApp:
// ���̃N���X�̎����ɂ��ẮAMyAddress.cpp ���Q�Ƃ��Ă��������B
//

class CMyAddressApp : public CWinApp
{
public:
	CMyAddressApp();

// �I�[�o�[���C�h
	public:
	virtual BOOL InitInstance();

// ����

	DECLARE_MESSAGE_MAP()
};

extern CMyAddressApp theApp;
