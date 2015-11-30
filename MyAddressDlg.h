#pragma once

class CMyAddressDlg : public CDialog
{
public:
	CMyAddressDlg(CWnd* pParent = NULL);	// 標準コンストラクタ

	CPoint m_pointOld ;
	BOOL m_bMoving;

	enum { IDD = IDD_MYADDRESS_DIALOG };
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV サポート

protected:
	CFont m_font;
    char m_host[512 + 1] ;   // host に「0.0.0.0」形式の文字列を取得します。
	HICON m_hIcon;
void CMyAddressDlg::MyAddress();
	// 生成された、メッセージ割り当て関数
	virtual BOOL OnInitDialog();
	virtual void OnOk() {}; //
	virtual void OnCancel() {}; //
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnWindowPosChanging(WINDOWPOS* lpwndpos);
};
