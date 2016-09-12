// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "InterCom.h"

#include "MainFrm.h"
#include "InterComView.h"
#include "Splash.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_WM_MEASUREITEM()
	ON_WM_MENUCHAR()
	ON_WM_INITMENUPOPUP()
	ON_WM_DESTROY()
	ON_UPDATE_COMMAND_UI(ID_INDICATOR_SN, OnUpdateRecs)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_SN,
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	print=FALSE;	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	app_m=APP_W_MODE;

	if(app_m==2)
	{
		if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
			| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
			!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
		{
			TRACE0("Failed to create toolbar\n");
			return -1;      // fail to create
		}
	}
	else if(app_m==1)
	{
		if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
			| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
			!m_wndToolBar.LoadToolBar(IDR_COMMERCE))
		{
			TRACE0("Failed to create toolbar\n");
			return -1;      // fail to create
		}
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	if(app_m==1)
		SetWindowText("Dark Unicorn InterCom RE :: Коммерческая недвижимость");
	else if(app_m==2)
		SetWindowText("Dark Unicorn InterCom RE :: Жилая недвижимость");

	// CG: The following line was added by the Splash Screen component.
//	CSplashWnd::ShowSplashScreen(this);

//	UpdateSB("!!!");
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	cs.style = WS_OVERLAPPED | WS_CAPTION //| FWS_ADDTOTITLE
		| WS_THICKFRAME | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_MAXIMIZE;

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers

HMENU CMainFrame::NewMenu()
{
	// Load the menu from the resources
	// ****replace IDR_MAINFRAME with your menu ID****
	if(app_m==2)
	{
		m_menu.LoadMenu(IDR_MAINFRAME);  
	// One method for adding bitmaps to menu options is 
	// through the LoadToolbar member function.This method 
	// allows you to add all the bitmaps in a toolbar object 
	// to menu options (if they exist). The function parameter 
	// is an the toolbar id. There is also a function called 
	// LoadToolbars that takes an array of id's.
		m_menu.LoadToolbar(IDR_MAINFRAME);
	}
	else if(app_m==1)
	{
		m_menu.LoadMenu(IDR_COMMERCE);
		m_menu.LoadToolbar(IDR_COMMERCE);
	}


/*	CImageList temp;
	temp.Create(16,15,ILC_COLORDDB|ILC_MASK,1,1);
	temp.Add((HICON)AfxGetApp()->LoadIcon(IDI_DEL));
	m_menu.ModifyODMenu(NULL,ID_RECORD_DELETE_CUR,&temp,0);
	temp.Create(16,15,ILC_COLORDDB|ILC_MASK,1,1);
	temp.Add((HICON)AfxGetApp()->LoadIcon(IDI_ADD));
	m_menu.ModifyODMenu(NULL,ID_RECORD_ADD,&temp,0);
	temp.Create(16,15,ILC_COLORDDB|ILC_MASK,1,1);
	temp.Add((HICON)AfxGetApp()->LoadIcon(IDI_EDIT));
	m_menu.ModifyODMenu(NULL,ID_RECORD_EDIT_CUR,&temp,0);*/

	return(m_menu.Detach());
}

void CMainFrame::OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct) 
{
	// TODO: Add your message handler code here and/or call default
	BOOL setflag=FALSE;
	if(lpMeasureItemStruct->CtlType==ODT_MENU)
	{
		if(IsMenu((HMENU)lpMeasureItemStruct->itemID))
		{
			CMenu* cmenu = CMenu::FromHandle((HMENU)lpMeasureItemStruct->itemID);

			if(m_menu.IsMenu(cmenu))
			{
				m_menu.MeasureItem(lpMeasureItemStruct);
				setflag=TRUE;
			}
		}
	}
	if(!setflag)
		CFrameWnd::OnMeasureItem(nIDCtl, lpMeasureItemStruct);
}

LRESULT CMainFrame::OnMenuChar(UINT nChar, UINT nFlags, CMenu* pMenu) 
{
	// TODO: Add your message handler code here and/or call default
	LRESULT lresult;
	if(m_menu.IsMenu(pMenu))
		lresult=BCMenu::FindKeyboardShortcut(nChar, nFlags, pMenu);
	else
		lresult=CFrameWnd::OnMenuChar(nChar, nFlags, pMenu);
	
	return(lresult);
}

void CMainFrame::OnInitMenuPopup(CMenu* pPopupMenu, UINT nIndex, BOOL bSysMenu) 
{
	// TODO: Add your message handler code here
	CFrameWnd::OnInitMenuPopup(pPopupMenu, nIndex, bSysMenu);
	if(!bSysMenu)
	{
		if(m_menu.IsMenu(pPopupMenu))
			BCMenu::UpdateMenu(pPopupMenu);
	}	
}

void CMainFrame::OnDestroy() 
{
	CFrameWnd::OnDestroy();
	
	// TODO: Add your message handler code here
//	m_menu.DestroyMenu();
	
}

void CMainFrame::UpdateSB(CString s)
{
//	m_wndStatusBar.SetPaneText(m_wndStatusBar.CommandToIndex(ID_INDICATOR_SN), s, TRUE);
}

void CMainFrame::OnUpdateRecs(CCmdUI *pCmdUI) 
{
	pCmdUI->Enable(); 
	CString strNodes;
	if(!print)
	{
		if(GetICView()->m_pGridCtrl.GetFocusCell().row!=-1)
			strNodes.Format("%d/%d", GetICView()->m_pGridCtrl.GetFocusCell().row, GetICView()->m_pGridCtrl.GetRowCount()-1);
		else
			strNodes.Format("не выбрана / %d", GetICView()->m_pGridCtrl.GetRowCount()-1);
		pCmdUI->SetText("Запись: "+strNodes);
	}
	else
		pCmdUI->SetText("Печать документа");

}

CInterComView* CMainFrame::GetICView()
{
	return (CInterComView*)GetActiveView();
}
