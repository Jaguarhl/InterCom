#if !defined(AFX_IMSET_H__3E6D8646_33E1_49D1_AFE4_FBC13FA6E1CF__INCLUDED_)
#define AFX_IMSET_H__3E6D8646_33E1_49D1_AFE4_FBC13FA6E1CF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ImSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CImSet dialog

class CImSet : public CDialog
{
// Construction
public:
	CImSet(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CImSet)
	enum { IDD = IDD_IMS };
	CButton	m_plan;
	CButton	m_photo;
	CString	m_com;
	BOOL	m_def;
	//}}AFX_DATA

	BOOL pl;


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImSet)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CImSet)
	virtual BOOL OnInitDialog();
	afx_msg void OnPlan();
	afx_msg void OnPhoto();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMSET_H__3E6D8646_33E1_49D1_AFE4_FBC13FA6E1CF__INCLUDED_)
