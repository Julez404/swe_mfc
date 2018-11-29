
// sweDlg.h: Headerdatei
//

#pragma once
#include "afxwin.h"


// CsweDlg-Dialogfeld
class CsweDlg : public CDialogEx
{
// Konstruktion
public:
	CsweDlg(CWnd* pParent = NULL);	// Standardkonstruktor

// Dialogfelddaten
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SWE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV-Unterst�tzung


// Implementierung
protected:
	HICON m_hIcon;

	// Generierte Funktionen f�r die Meldungstabellen
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	int input_1;
	int input_2;
	int output_1;
	afx_msg void OnBnClickedOk();
	int mathOperation;
};
