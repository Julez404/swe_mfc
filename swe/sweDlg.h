
// sweDlg.h: Headerdatei
//

#pragma once
#include "afxwin.h"
#include "Liste.h"


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
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV-Unterstützung


// Implementierung
protected:
	HICON m_hIcon;

	// Generierte Funktionen für die Meldungstabellen
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();

private:

public:
private:
	double newRes;
public:
	afx_msg void OnBnClickedWiderstand();
private:
	UINT mouseX;
	UINT mouseY;
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	double newPreis;
	double frequency;
private:
	double newL;
	double newC;
public:
	afx_msg void OnBnClickedSpule();
	afx_msg void OnBnClickedKap();
private:
	CString newName;
	CListe* ListePtr;
};
