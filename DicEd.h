#if !defined(AFX_DICED_H__AAD97562_96A4_11D7_A43C_C83F96F30543__INCLUDED_)
#define AFX_DICED_H__AAD97562_96A4_11D7_A43C_C83F96F30543__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DicEd.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDicEd dialog

class CDicEd : public CDialog
{
// Construction
public:
	CDicEd(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDicEd)
	enum { IDD = IDD_DICED };
	CString	m_value;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDicEd)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDicEd)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DICED_H__AAD97562_96A4_11D7_A43C_C83F96F30543__INCLUDED_)
