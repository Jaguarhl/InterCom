// ExpInt.cpp : implementation file
//

#include "stdafx.h"
#include "InterCom.h"
#include "ExpInt.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExpInt dialog


CExpInt::CExpInt(CWnd* pParent /*=NULL*/)
	: CDialog(CExpInt::IDD, pParent)
{
	//{{AFX_DATA_INIT(CExpInt)
	//}}AFX_DATA_INIT
}

CExpInt::CExpInt(CView* pView)
{
	m_pView = pView;
	m_pDial = this;
	m_ffl = FALSE;
	m_ffs = FALSE;
	m_fibh = FALSE;
	m_rfl = FALSE;
	m_rfs = FALSE;
	
}

void CExpInt::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CExpInt)
	DDX_Control(pDX, IDC_FFL, m_flfr);
	DDX_Control(pDX, IDC_RFL, m_rmfr);
	DDX_Control(pDX, IDC_RFS, m_rmfs);
	DDX_Control(pDX, IDC_FIBH, m_flibh);
	DDX_Control(pDX, IDC_FFS, m_flfs);
	DDX_Control(pDX, IDCANCEL, m_cancel);
	DDX_Control(pDX, ID_SEND, m_send);
	DDX_Control(pDX, IDC_PROGRESS, m_progress);
	DDX_Control(pDX, IDC_LOG, m_log);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CExpInt, CDialog)
	//{{AFX_MSG_MAP(CExpInt)
	ON_BN_CLICKED(ID_SEND, OnSend)
	ON_BN_CLICKED(IDC_FIBH, OnFibh)
	ON_BN_CLICKED(IDC_RFS, OnRfs)
	ON_BN_CLICKED(IDC_FFS, OnFfs)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExpInt message handlers

BOOL CExpInt::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_progress.SetRange(0, 100);
	m_lc=3;

	DWORD app_w_mode=APP_W_MODE;

	if(app_w_mode==1)
	{
		m_flfr.ShowWindow(false);
		m_rmfr.ShowWindow(false);
		m_flibh.ShowWindow(false);
		m_flfs.SetWindowText("Продажа");
		m_rmfs.SetWindowText("Аренда");

		m_lc=1;
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CExpInt::Create() 
{
	// TODO: Add your specialized code here and/or call the base class
	return CDialog::Create(CExpInt::IDD);
}

void CExpInt::OnCancel() 
{
	// TODO: Add extra cleanup here
	m_pView->PostMessage(WM_ENDOFDIAL);
}

void CExpInt::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized) 
{
	CDialog::OnActivate(nState, pWndOther, bMinimized);
	
	// TODO: Add your message handler code here
	m_gpMyApp = (CInterComApp*)m_pDial; 
	m_pView->PostMessage(WM_SETPOINTER);
}

void CExpInt::OnSend() 
{
	// TODO: Add your control notification handler code here
	m_pView->PostMessage(WM_SENDTOINT);
	
}

void CExpInt::OnFibh() 
{
	// TODO: Add your control notification handler code here
	if(m_fibh==FALSE)
	{
		m_fibh=TRUE;
		m_lc++;
	}
	else
	{
		m_fibh=FALSE;
		if(m_lc>0)
			m_lc--;
	}
	
}

void CExpInt::OnRfs() 
{
	// TODO: Add your control notification handler code here
	if(m_rfs==FALSE)
	{
		m_rfs=TRUE;
		m_lc++;
	}
	else
	{
		m_rfs=FALSE;
		if(m_lc>0)
			m_lc--;
	}
	
}

void CExpInt::OnFfs() 
{
	// TODO: Add your control notification handler code here
	if(m_ffs==FALSE)
	{
		m_ffs=TRUE;
		m_lc++;
	}
	else
	{
		m_ffs=FALSE;
		if(m_lc>0)
			m_lc--;
	}
	
}
