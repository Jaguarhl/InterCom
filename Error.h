#if !defined(AFX_ERROR_H__05D8D6E1_481C_11D7_A43C_DF0D9750EA60__INCLUDED_)
#define AFX_ERROR_H__05D8D6E1_481C_11D7_A43C_DF0D9750EA60__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Error.h : header file
//

#include "ListBoxST.h"
#include "BtnST.h"
#include "ShadeButtonST.h"

/////////////////////////////////////////////////////////////////////////////
// CError dialog

class CError : public CDialog
{
// Construction
public:
	CError(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CError)
	enum { IDD = IDD_CERROR };
	CShadeButtonST	m_close;
	CListBoxST	m_list;
	//}}AFX_DATA

	CString m_error;
	CImageList	m_ImageList;


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CError)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void CreateImageList();

	// Generated message map functions
	//{{AFX_MSG(CError)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ERROR_H__05D8D6E1_481C_11D7_A43C_DF0D9750EA60__INCLUDED_)
