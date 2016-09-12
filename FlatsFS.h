#if !defined(AFX_FLATSFS_H__3FF65821_956A_11D7_A43C_444553540000__INCLUDED_)
#define AFX_FLATSFS_H__3FF65821_956A_11D7_A43C_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define WM_ENDOFDIAL  WM_USER + 10
#define WM_SETPOINTER WM_USER + 15
#define WM_SAVECHANGES WM_USER + 20
#define WM_DELETECUR WM_USER + 25
#define WM_ADDNEW WM_USER + 30
#define WM_MFIRST WM_USER + 35
#define WM_MPREV WM_USER + 40
#define WM_MNEXT WM_USER + 45
#define WM_MLAST WM_USER + 50


// FlatsFS.h : header file
//

#include "CJFlatComboBox.h"
#include "BtnST.h"
#include "ShadeButtonST.h"
#include "FlatEdit.h"
#include "NumEdit.h"


/////////////////////////////////////////////////////////////////////////////
// CFlatsFS dialog

class CFlatsFS : public CDialog
{
// Construction
public:
	CFlatsFS(CWnd* pParent = NULL);   // standard constructor
	CFlatsFS(CView* pView);
	CView* m_pView;
	CFlatsFS* m_pDial;

// Dialog Data
	//{{AFX_DATA(CFlatsFS)
	enum { IDD = IDD_FFS };
	CCJFlatComboBox	m_phone;
	CShadeButtonST	m_cancel;
	CShadeButtonST	m_add;
	CShadeButtonST	m_delete;
	CShadeButtonST	m_prev;
	CShadeButtonST	m_next;
	CShadeButtonST	m_last;
	CShadeButtonST	m_first;
	CShadeButtonST	m_save;
	CShadeButtonST	m_clear;
	CNumEdit	m_r9;
	CNumEdit	m_r8;
	CNumEdit	m_r7;
	CNumEdit	m_r6;
	CNumEdit	m_r5;
	CNumEdit	m_r4;
	CNumEdit	m_r3;
	CNumEdit	m_r20;
	CNumEdit	m_r2;
	CNumEdit	m_r19;
	CNumEdit	m_r18;
	CNumEdit	m_r17;
	CNumEdit	m_r16;
	CNumEdit	m_r15;
	CNumEdit	m_r14;
	CNumEdit	m_r13;
	CNumEdit	m_r12;
	CNumEdit	m_r11;
	CNumEdit	m_r10;
	CNumEdit	m_r1;
	CNumEdit	m_skitchen;
	CNumEdit	m_sgeneral;
	CFlatEdit	m_rooms;
	CFlatEdit	m_floors;
	CFlatEdit	m_floor;
	CFlatEdit	m_distance;
	CFlatEdit	m_description;
	CFlatEdit	m_costfrom;
	CFlatEdit	m_address;
	CCJFlatComboBox	m_inwhat;
	CCJFlatComboBox	m_forwhat;
	CCJFlatComboBox	m_district;
	CCJFlatComboBox	m_wc;
	CCJFlatComboBox	m_metro;
	CCJFlatComboBox	m_htype;
	CCJFlatComboBox	m_aphone;
	CCJFlatComboBox	m_agent;
	//}}AFX_DATA

	BOOL cur;


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFlatsFS)
	public:
	virtual BOOL Create();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

protected:
	void CalcS();
	BOOL CheckEntry();

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFlatsFS)
		// NOTE: the ClassWizard will add member functions here
	virtual void OnCancel();
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	virtual BOOL OnInitDialog();
	afx_msg void OnChangeRooms();
	afx_msg void OnSave();
	afx_msg void OnAdd();
	afx_msg void OnDelete();
	afx_msg void OnLast();
	afx_msg void OnNext();
	afx_msg void OnPrev();
	afx_msg void OnFirst();
	afx_msg void OnSelchangeAgent();
	afx_msg void OnSelchangePhone();
	afx_msg void OnChangeR1();
	afx_msg void OnChangeR2();
	afx_msg void OnChangeR3();
	afx_msg void OnChangeR4();
	afx_msg void OnChangeR5();
	afx_msg void OnChangeR6();
	afx_msg void OnChangeR7();
	afx_msg void OnChangeR8();
	afx_msg void OnChangeR9();
	afx_msg void OnChangeSgeneral();
	afx_msg void OnChangeSkitchen();
	afx_msg void OnSelchangeWc();
	afx_msg void OnChangeAddress();
	afx_msg void OnChangeBuildingend();
	afx_msg void OnChangeCostfrom();
	afx_msg void OnChangeDescription();
	afx_msg void OnChangeDistance();
	afx_msg void OnSelchangeDistrict();
	afx_msg void OnChangeFloor();
	afx_msg void OnChangeFloors();
	afx_msg void OnSelchangeForwhat();
	afx_msg void OnSelchangeHousetype();
	afx_msg void OnSelchangeInwhat();
	afx_msg void OnSelchangeMetro();
	afx_msg void OnChangeR10();
	afx_msg void OnChangeR11();
	afx_msg void OnChangeR12();
	afx_msg void OnChangeR13();
	afx_msg void OnChangeR14();
	afx_msg void OnChangeR15();
	afx_msg void OnChangeR16();
	afx_msg void OnChangeR17();
	afx_msg void OnChangeR18();
	afx_msg void OnChangeR19();
	afx_msg void OnChangeR20();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FLATSFS_H__3FF65821_956A_11D7_A43C_444553540000__INCLUDED_)
