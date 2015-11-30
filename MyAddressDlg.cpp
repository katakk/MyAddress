// MyAddressDlg.cpp : é¿ëïÉtÉ@ÉCÉã
//

#include "stdafx.h"
#include "MyAddress.h"
#include "MyAddressDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

void CMyAddressDlg::MyAddress()
{
	CBrush    brush(RGB(255,255,255));

	CClientDC dc(NULL);
	CWnd *wnd;
	CRect rect;

	CFont *oldfont;
	CPen *oldpen;
	CPen pen( PS_SOLID, 1, GetSysColor(COLOR_BTNFACE));

	ULONG len = 0;
	DWORD ret = GetAdaptersAddresses(AF_UNSPEC, 0, 0, 0, &len);

	if(ret != ERROR_BUFFER_OVERFLOW) return;

	PIP_ADAPTER_ADDRESSES adpts = (PIP_ADAPTER_ADDRESSES)new BYTE[len];
	if(adpts == 0) return;

	ret = GetAdaptersAddresses(AF_UNSPEC, 0, 0, adpts, &len);
	if(ret != ERROR_SUCCESS){
		delete [] adpts;
		return;
	}

	m_host[0]='X';m_host[1]='X';m_host[2]='X';m_host[3]='.';
	m_host[4]='X';m_host[5]='X';m_host[6]='X';m_host[7]='.';
	m_host[8]='X';m_host[9]='X';m_host[10]='X';m_host[11]='.';
	m_host[12]='X';m_host[13]='X';m_host[14]='X';m_host[15]='\0';
	m_host[16]='\0';
	m_host[17]='\0';
	m_host[18]='\0';

	for(PIP_ADAPTER_ADDRESSES adpt = adpts; adpt; adpt = adpt->Next)
	{
		if(!adpt->PhysicalAddressLength) continue;
		if(adpt->IfType == IF_TYPE_SOFTWARE_LOOPBACK) continue;

		for(PIP_ADAPTER_UNICAST_ADDRESS uni = adpt->FirstUnicastAddress; uni; uni = uni->Next){
			if(adpt->Description[0] == 'V')  continue; //VirtualBox VMnet
			if(~(uni->Flags) & IP_ADAPTER_ADDRESS_DNS_ELIGIBLE) continue;
			if(uni->Flags & IP_ADAPTER_ADDRESS_TRANSIENT) continue;
			if(getnameinfo(uni->Address.lpSockaddr,
				uni->Address.iSockaddrLength,
				m_host, 256, 0, 0, NI_NUMERICHOST) == 0){
					break;	
					//				TRACE("%s %s %s %lx\n", adpt->AdapterName,  adpt->Description, m_host, uni->Address.lpSockaddr);
				}
		}
	}
	delete [] adpts;

	if( (wnd = GetDesktopWindow()) == NULL ) return;

	oldpen = dc.SelectObject(&pen);
	oldfont = dc.SelectObject(&m_font);
	wnd->GetClientRect(&rect);
	rect.left = rect.Width() /5;

	dc.DrawText(  CString(m_host),rect,0 );

	dc.SelectObject(&oldpen);
	dc.SelectObject(&oldfont);

}

CMyAddressDlg::CMyAddressDlg(CWnd* pParent /*=NULL*/)
: CDialog(CMyAddressDlg::IDD, pParent)
{

}

void CMyAddressDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMyAddressDlg, CDialog)
	//}}AFX_MSG_MAP
	ON_WM_TIMER()
END_MESSAGE_MAP()

BOOL CMyAddressDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_font.CreatePointFont( 150, "ÇlÇr ÉSÉVÉbÉN" );
	MyAddress();
	SetTimer(1, 2000, NULL);
	return TRUE;
}

void CMyAddressDlg::OnTimer(UINT nIDEvent)
{
	MyAddress();
	CDialog::OnTimer(nIDEvent);
}
