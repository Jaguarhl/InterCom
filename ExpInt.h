#if !defined(AFX_EXPINT_H__539614C1_97AD_11D7_A43C_C0108519334C__INCLUDED_)
#define AFX_EXPINT_H__539614C1_97AD_11D7_A43C_C0108519334C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define WM_ENDOFDIAL  WM_USER + 10
#define WM_SETPOINTER WM_USER + 15
#define WM_SENDTOINT WM_USER + 60

// ExpInt.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CExpInt dialog

class CExpInt : public CDialog
{
// Construction
public:
	CExpInt(CWnd* pParent = NULL);   // standard constructor
	CExpInt(CView* pView);
	CView* m_pView;
	CExpInt* m_pDial;

// Dialog Data
	//{{AFX_DATA(CExpInt)
	enum { IDD = IDD_EXPINT };
	CButton	m_flfr;
	CButton	m_rmfr;
	CButton	m_rmfs;
	CButton	m_flibh;
	CButton	m_flfs;
	CButton	m_cancel;
	CButton	m_send;
	CProgressCtrl	m_progress;
	CListBox	m_log;
	//}}AFX_DATA

	BOOL m_fibh;
	BOOL m_ffs;
	BOOL m_rfs;
	BOOL m_ffl;
	BOOL m_rfl;

	int m_lc;


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExpInt)
	public:
	virtual BOOL Create();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CExpInt)
	virtual BOOL OnInitDialog();
	virtual void OnCancel();
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	afx_msg void OnSend();
	afx_msg void OnFibh();
	afx_msg void OnRfs();
	afx_msg void OnFfs();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXPINT_H__539614C1_97AD_11D7_A43C_C0108519334C__INCLUDED_)
