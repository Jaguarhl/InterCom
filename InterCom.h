// InterCom.h : main header file for the InterCom application
//

#if !defined(AFX_InterCom_H__6929CF43_309F_11D7_A43C_E7333806FC4F__INCLUDED_)
#define AFX_InterCom_H__6929CF43_309F_11D7_A43C_E7333806FC4F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

enum {FinBH, RFS, FFS, EI, CFS, CFR};

#define APP_W_MODE				1;

const CString ag="÷Õ »Õ¿“¿";

const CString strConnection = _T("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=Database\\listings.mdb");

const CString strIConnection = _T("DRIVER={MySQL ODBC 3.51 Driver};SERVER=localhost;DATABASE=inata;USER=jaguar;PASSWORD=654321;OPTION=4;");

const CString imFolder = "Database\\Documents\\";

const CString plFolder = "Plugins\\";


//DWORD app_w_mode = COMMERCE_RE;



/////////////////////////////////////////////////////////////////////////////
// CInterComApp:
// See InterCom.cpp for the implementation of this class
//

class CInterComApp : public CWinApp
{
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CInterComApp();

	BOOL GetPrinterDeviceDefaults(PRINTDLG *pPrintDlg);
	int GetPageOrientation();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInterComApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CInterComApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_InterCom_H__6929CF43_309F_11D7_A43C_E7333806FC4F__INCLUDED_)
