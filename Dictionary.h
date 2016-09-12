#if !defined(AFX_DICTIONARY_H__AAD97561_96A4_11D7_A43C_C83F96F30543__INCLUDED_)
#define AFX_DICTIONARY_H__AAD97561_96A4_11D7_A43C_C83F96F30543__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dictionary.h : header file
//

#include "ado.h"

/////////////////////////////////////////////////////////////////////////////
// CDictionary dialog

class CDictionary : public CDialog
{
// Construction
public:
	CDictionary(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDictionary)
	enum { IDD = IDD_DICTIONARY };
	CButton	m_add;
	CListBox	m_list;
	CComboBox	m_dict;
	CButton	m_change;
	int m_mode;
	//}}AFX_DATA

	DWORD app_w_mode;


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDictionary)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

public:
	void FillList();

// Implementation
protected:

	CADORecordset m_pdRs;
	CADODatabase m_pDb;

	// Generated message map functions
	//{{AFX_MSG(CDictionary)
	virtual BOOL OnInitDialog();
	afx_msg void OnEditchangeDict();
	afx_msg void OnSelchangeDict();
	afx_msg void OnChange();
	afx_msg void OnAdd();
	afx_msg void OnDblclkList();
	afx_msg void OnDelete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DICTIONARY_H__AAD97561_96A4_11D7_A43C_C83F96F30543__INCLUDED_)
