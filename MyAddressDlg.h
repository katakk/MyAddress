#pragma once

class CMyAddressDlg : public CDialog
{
public:
	CMyAddressDlg(CWnd* pParent = NULL);	// �W���R���X�g���N�^

	CPoint m_pointOld ;
	BOOL m_bMoving;

	enum { IDD = IDD_MYADDRESS_DIALOG };
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �T�|�[�g

protected:
	CFont m_font;
    char m_host[512 + 1] ;   // host �Ɂu0.0.0.0�v�`���̕�������擾���܂��B
	HICON m_hIcon;
void CMyAddressDlg::MyAddress();
	// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
	virtual BOOL OnInitDialog();
	virtual void OnOk() {}; //
	virtual void OnCancel() {}; //
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnWindowPosChanging(WINDOWPOS* lpwndpos);
};
