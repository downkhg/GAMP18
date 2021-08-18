
// MFC_RPGSTATUSDlg.h: 헤더 파일
//

#pragma once


// CMFCRPGSTATUSDlg 대화 상자
class CMFCRPGSTATUSDlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCRPGSTATUSDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_RPGSTATUS_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int m_nHP;
	int m_nMP;
	int m_nStr;
	int m_nDef;
	int m_nInt;

	int m_nBonusPoint;
public:
	CEdit m_editHP;
	CEdit m_editMP;
	CEdit m_editStr;
	CEdit m_editInt;
	CEdit m_editDef;
	CStatic m_staticBonus;
	afx_msg void OnDeltaposSpin1(NMHDR* pNMHDR, LRESULT* pResult);
	CComboBox m_comboClass;
};
