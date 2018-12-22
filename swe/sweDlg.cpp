
// sweDlg.cpp: Implementierungsdatei
//

#include "stdafx.h"
#include "swe.h"
#include "sweDlg.h"
#include "afxdialogex.h"
#include "Bauelement.h"
#include "Widerstand.h"
#include "Kap.h"
#include "Spule.h"
#include "ImpedanzRechner.h"
#include "ImpedanzRechner_Serie.h"
#include "ImpedanzRechner_Parallel.h"
#include "Liste.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg-Dialogfeld für Anwendungsbefehl "Info"

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// Dialogfelddaten
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung

// Implementierung
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CsweDlg-Dialogfeld



CsweDlg::CsweDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SWE_DIALOG, pParent)
	, newRes(10)
	, mouseX(0)
	, mouseY(0)
	, newPreis(0.15)
	, frequency(50)
	, newL(53)
	, newC(870)
	, newName(_T(""))
	, ListePtr(NULL)
	, impedanzTyp(0)
	, mCalculatedReal(0)
	, mCalculatedImag(0)
	, mGraph(10,10,WIDTH_OF_GRAPH,HEIGHT_OF_GRAPH,BOUNDRY_OF_GRAPH,RGB(0,0,255))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CsweDlg::~CsweDlg()
{
	delete ListePtr;
	delete Parallel_Rechner;
	delete Serie_Rechner;
}

void CsweDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, newRes);
	DDX_Text(pDX, IDC_EDIT2, mouseX);
	DDX_Text(pDX, IDC_EDIT3, mouseY);
	DDX_Text(pDX, IDC_EDIT6, newPreis);
	DDX_Text(pDX, IDC_EDIT7, frequency);
	DDV_MinMaxDouble(pDX, frequency, 0, DBL_MAX);
	DDX_Text(pDX, IDC_EDIT4, newL);
	DDX_Text(pDX, IDC_EDIT5, newC);
	DDX_Text(pDX, IDC_EDIT8, newName);
	DDX_Control(pDX, IDC_LIST1, bListe);
	DDX_Radio(pDX, IDC_RADIO1, impedanzTyp);
	DDV_MinMaxInt(pDX, impedanzTyp, 0, 1);
	DDX_Text(pDX, IDC_EDIT9, mCalculatedReal);
	DDX_Text(pDX, IDC_EDIT10, mCalculatedImag);
}

BEGIN_MESSAGE_MAP(CsweDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CsweDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CsweDlg::OnBnClickedWiderstand)
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_BUTTON2, &CsweDlg::OnBnClickedSpule)
	ON_BN_CLICKED(IDC_BUTTON3, &CsweDlg::OnBnClickedKap)
	ON_BN_CLICKED(IDC_BUTTON4, &CsweDlg::OnBnClickedBerechneImpedanz)
END_MESSAGE_MAP()


// CsweDlg-Meldungshandler

BOOL CsweDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Hinzufügen des Menübefehls "Info..." zum Systemmenü.

	// IDM_ABOUTBOX muss sich im Bereich der Systembefehle befinden.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Symbol für dieses Dialogfeld festlegen.  Wird automatisch erledigt
	//  wenn das Hauptfenster der Anwendung kein Dialogfeld ist
	SetIcon(m_hIcon, TRUE);			// Großes Symbol verwenden
	SetIcon(m_hIcon, FALSE);		// Kleines Symbol verwenden

	// TODO: Hier zusätzliche Initialisierung einfügen

	ListePtr = new CListe;
	Parallel_Rechner = new ImpedanzRechner_Parallel;
	Serie_Rechner = new ImpedanzRechner_Serie;
	impedanzTyp = 1;
	UpdateData(false);


	return TRUE;  // TRUE zurückgeben, wenn der Fokus nicht auf ein Steuerelement gesetzt wird
}



void CsweDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// Wenn Sie dem Dialogfeld eine Schaltfläche "Minimieren" hinzufügen, benötigen Sie
//  den nachstehenden Code, um das Symbol zu zeichnen.  Für MFC-Anwendungen, die das 
//  Dokument/Ansicht-Modell verwenden, wird dies automatisch ausgeführt.

void CsweDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // Gerätekontext zum Zeichnen

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Symbol in Clientrechteck zentrieren
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Symbol zeichnen
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
		CClientDC _cd(this);
		mGraph.drawBackground(&_cd);
	}
}

// Die System ruft diese Funktion auf, um den Cursor abzufragen, der angezeigt wird, während der Benutzer
//  das minimierte Fenster mit der Maus zieht.
HCURSOR CsweDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CsweDlg::OnBnClickedOk()
{
	// TODO: Fügen Sie hier Ihren Kontrollbehandlungscode für die Benachrichtigung ein.
	CDialogEx::OnOK();
}



void CsweDlg::OnBnClickedWiderstand()
{
	UpdateData(true);
	ListePtr->addToStart(new CWiderstand(newName, newPreis, CPunkt(mouseX, mouseY), newRes));
	bListe.AddString(ListePtr->getStart()->getName());
}

void CsweDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	if (nFlags & MK_LBUTTON)
	{
		mouseX = point.x;
		mouseY = point.y;
		UpdateData(false);
	}
	CDialogEx::OnMouseMove(nFlags, point);

}


void CsweDlg::OnBnClickedSpule()
{
	UpdateData(true);
	ListePtr->addToStart(new CSpule(newName, newPreis, CPunkt(mouseX, mouseY), newL));
	bListe.AddString(ListePtr->getStart()->getName());
}


void CsweDlg::OnBnClickedKap()
{
	UpdateData(true);
	ListePtr->addToStart(new CKap(newName, newPreis, CPunkt(mouseX, mouseY), newC));
	bListe.AddString(ListePtr->getStart()->getName());
}

void CsweDlg::OnBnClickedBerechneImpedanz()
{
	UpdateData(true);
	CComplex result;
	enum { serie, reihe };
	switch (impedanzTyp)
	{
	case serie:
		ListePtr->setImpPtr(Serie_Rechner);
		break;
	case reihe:
		ListePtr->setImpPtr(Parallel_Rechner);
		break;
	default:
		break;
	}
	result = ListePtr->getImpedanzOfList(frequency);
	mCalculatedReal = result.getReal();
	mCalculatedImag = result.getImag();
	UpdateData(false);
}
