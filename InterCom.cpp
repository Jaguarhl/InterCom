// InterCom.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "InterCom.h"

#include "MainFrm.h"
#include "InterComDoc.h"
#include "InterComView.h"
//#include "Splash.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInterComApp

BEGIN_MESSAGE_MAP(CInterComApp, CWinApp)
	//{{AFX_MSG_MAP(CInterComApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInterComApp construction

CInterComApp::CInterComApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CInterComApp object

CInterComApp theApp;
CInterComApp* NEAR m_gpMyApp = &theApp;

/////////////////////////////////////////////////////////////////////////////
// CInterComApp initialization

BOOL CInterComApp::InitInstance()
{
	// CG: The following block was added by the Splash Screen component.
\
	{
\
		CCommandLineInfo cmdInfo;
\
		ParseCommandLine(cmdInfo);
\

\
//		CSplashWnd::EnableSplashScreen(cmdInfo.m_bShowSplash);
\
	}
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	// Change the registry key under which our settings are stored.
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CInterComDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CInterComView));
	AddDocTemplate(pDocTemplate);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	CMenu* pMenu = m_pMainWnd->GetMenu();
	if(pMenu)
		pMenu->DestroyMenu();
	HMENU hMenu = ((CMainFrame*) m_pMainWnd)->NewMenu();
	pMenu = CMenu::FromHandle( hMenu );
	m_pMainWnd->SetMenu(pMenu);
	((CMainFrame*)m_pMainWnd)->m_hMenuDefault = hMenu;


	// The one and only window has been initialized, so show and update it.
	m_pMainWnd->ShowWindow(SW_SHOWMAXIMIZED);
	m_pMainWnd->UpdateWindow();

	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
		// No message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CInterComApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CInterComApp message handlers


BOOL CInterComApp::PreTranslateMessage(MSG* pMsg)
{
	// CG: The following lines were added by the Splash Screen component.
//	if (CSplashWnd::PreTranslateAppMessage(pMsg))
//		return TRUE;

	return CWinApp::PreTranslateMessage(pMsg);
}

BOOL CInterComApp::GetPrinterDeviceDefaults(PRINTDLG *pPrintDlg)
{
	if(m_hDevNames == NULL)
	{

		UpdatePrinterSelection(m_hDevNames == NULL); //force default if no current
		if (m_hDevNames == NULL)
			return FALSE;               // no printer defaults

		LPDEVMODE lpDevDevMode = (LPDEVMODE)::GlobalLock(m_hDevMode);
		if(lpDevDevMode != NULL)
		{
			lpDevDevMode->dmFields = lpDevDevMode->dmFields | DM_ORIENTATION;
			lpDevDevMode->dmOrientation = DMORIENT_LANDSCAPE;
		}

		pPrintDlg->hDevNames = m_hDevNames;
		pPrintDlg->hDevMode = m_hDevMode;

		::GlobalUnlock(m_hDevNames);
		::GlobalUnlock(m_hDevMode);
	}
	return TRUE;
}

int CInterComApp::GetPageOrientation()
{
	if(m_hDevMode==NULL)
		return 0;
	LPDEVMODE lpDevDevMode = (LPDEVMODE)::GlobalLock(m_hDevMode);
	if(lpDevDevMode == NULL)
		return 0;
	int iOrientation = lpDevDevMode->dmOrientation;

	::GlobalUnlock(m_hDevNames);
	::GlobalUnlock(m_hDevMode);
	return iOrientation;
}
