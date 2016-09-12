#if !defined(AFX_IMAGEPROPERTIES_H__12BD66CA_D211_4E0C_B9F7_F17D031E5081__INCLUDED_)
#define AFX_IMAGEPROPERTIES_H__12BD66CA_D211_4E0C_B9F7_F17D031E5081__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ImageProperties.h : header file
//

#include "ListBoxST.h"
#include "BtnST.h"
#include "ShadeButtonST.h"
#include "freeimage.h"
#include "ado.h"

/////////////////////////////////////////////////////////////////////////////
// CImageProperties dialog

class CImageProperties : public CDialog
{
// Construction
public:
	CImageProperties(CWnd* pParent = NULL);   // standard constructor

	int sy;
	int sh;

	FIBITMAP * bitmap;

	FREE_IMAGE_FORMAT fif;

	RECT r;

	CString dir; //programm directory
	CString gfxMode; //parent table for image
	int ComID; //object identificator

// Dialog Data
	//{{AFX_DATA(CImageProperties)
	enum { IDD = IDD_IMPROP };
	CScrollBar	m_vbar;
	CShadeButtonST	m_open;
	CShadeButtonST	m_close;
	CListBoxST	m_list;
	CShadeButtonST	m_del;
	CShadeButtonST	m_add;
	//}}AFX_DATA


	CImageList	m_ImageList;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImageProperties)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CADORecordset m_pdRs;
	CADODatabase m_pDb;

protected:
	void CreateImageList();
	void FillList();
	void LoadImage(CString FilePath);

	// Generated message map functions
	//{{AFX_MSG(CImageProperties)
	afx_msg void OnAdd();
	afx_msg void OnDel();
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnOpen();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnDblclkLbxst();
	afx_msg void OnListingsComFr();
	afx_msg void OnUpdateListingsComFr(CCmdUI* pCmdUI);
	afx_msg void OnListingsComFs();
	afx_msg void OnUpdateListingsComFs(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGEPROPERTIES_H__12BD66CA_D211_4E0C_B9F7_F17D031E5081__INCLUDED_)
