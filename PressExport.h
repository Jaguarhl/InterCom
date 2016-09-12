#if !defined(AFX_PRESSEXPORT_H__E8461F64_EBCE_4D2A_82E3_E65342E65FA0__INCLUDED_)
#define AFX_PRESSEXPORT_H__E8461F64_EBCE_4D2A_82E3_E65342E65FA0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PressExport.h : header file

//#define DllImport   __declspec( dllimport )
//
typedef int (*PFUNC)(void);	
typedef LPSTR (*PLGNAME)(void);	

//#include "MultiCheckListBox.h"
#include "BtnST.h"
#include "ShadeButtonST.h"
/////////////////////////////////////////////////////////////////////////////
// CPressExport dialog

class CPressExport : public CDialog
{
// Construction
public:
	CPressExport(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPressExport)
	enum { IDD = IDD_PRESS_EXPORT };
	CShadeButtonST	m_exp;
	CCheckListBox	m_list;
	CShadeButtonST	m_close;
	//}}AFX_DATA

//	CImageList	m_ImageList;


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPressExport)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CDWordArray m_dwa;


protected:

	void CreateImageList();
	void FillList();
	void LoadLibraries();

	// Generated message map functions
	//{{AFX_MSG(CPressExport)
	virtual BOOL OnInitDialog();
	afx_msg void OnExport();
	afx_msg void OnDestroy();
	afx_msg void OnExp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRESSEXPORT_H__E8461F64_EBCE_4D2A_82E3_E65342E65FA0__INCLUDED_)
