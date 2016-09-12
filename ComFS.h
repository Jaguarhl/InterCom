#if !defined(AFX_COMFS_H__09783F18_0ECB_4B66_B754_B92176045345__INCLUDED_)
#define AFX_COMFS_H__09783F18_0ECB_4B66_B754_B92176045345__INCLUDED_

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

// ComFS.h : header file
//

#include "CJFlatComboBox.h"
#include "BtnST.h"
#include "ShadeButtonST.h"
#include "FlatEdit.h"
#include "NumEdit.h"

/////////////////////////////////////////////////////////////////////////////
// CComFS dialog

class CComFS : public CDialog
{
// Construction
public:
	CComFS(CWnd* pParent = NULL);   // standard constructor
	CComFS(CView* pView);
	CView* m_pView;
	CComFS* m_pDial;

	CString path;
	CString gfxMode;

	int m_COid;

// Dialog Data
	//{{AFX_DATA(CComFS)
	enum { IDD = IDD_COMFS };
	CShadeButtonST	m_images;
	CShadeButtonST	m_cancel;
	CButton		m_watersupply;
	CNumEdit	m_splot;
	CNumEdit	m_sgeneral;
	CButton		m_sewerage;
	CButton		m_phone;
	CButton		m_parking;
	CCJFlatComboBox	m_obj_type;
	CButton		m_heating;
	CButton		m_guard_s;
	CCJFlatComboBox	m_forwhat;
	CFlatEdit	m_floors;
	CFlatEdit	m_floor;
	CButton		m_fire_s;
	CCJFlatComboBox	m_entrance;
	CButton		m_electricity;
	CCJFlatComboBox	m_doorway;
	CCJFlatComboBox	m_district;
	CFlatEdit	m_description;
	CFlatEdit	m_costfrom;
	CCJFlatComboBox	m_condition;
	CNumEdit	m_ceilingheight;
	CCJFlatComboBox	m_appointment;
	CCJFlatComboBox	m_aphone;
	CCJFlatComboBox	m_agent;
	CFlatEdit	m_address;
	CShadeButtonST	m_save;
	CShadeButtonST	m_prev;
	CShadeButtonST	m_next;
	CShadeButtonST	m_last;
	CShadeButtonST	m_first;
	CShadeButtonST	m_delete;
	CShadeButtonST	m_clear;
	CShadeButtonST	m_add;
	//}}AFX_DATA

	BOOL cur;
	int re_m;


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CComFS)
	public:
	virtual BOOL Create();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

protected:
	BOOL CheckEntry();

public:
	void DisableCtrls();

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CComFS)
	virtual void OnCancel();
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	virtual BOOL OnInitDialog();
	afx_msg void OnSave();
	afx_msg void OnSelchangeObjType();
	afx_msg void OnSelchangeAgent();
	afx_msg void OnSelchangeAphone();
	afx_msg void OnChangeSgeneral();
	afx_msg void OnChangeSplot();
	afx_msg void OnChangeFloor();
	afx_msg void OnChangeFloors();
	afx_msg void OnSelchangeEntrance();
	afx_msg void OnSelchangeCondition();
	afx_msg void OnChangeCeilingheight();
	afx_msg void OnSelchangeDoorway();
	afx_msg void OnChangeCostfrom();
	afx_msg void OnSelchangeForwhat();
	afx_msg void OnSelchangeDistrict();
	afx_msg void OnChangeAddress();
	afx_msg void OnChangeDescription();
	afx_msg void OnSelchangeAppointment();
	afx_msg void OnCommunications();
	afx_msg void OnElectricity();
	afx_msg void OnWatersupply();
	afx_msg void OnHeating();
	afx_msg void OnSewerage();
	afx_msg void OnPhone();
	afx_msg void OnParking();
	afx_msg void OnGuardS();
	afx_msg void OnFireS();
	afx_msg void OnNext();
	afx_msg void OnLast();
	afx_msg void OnPrev();
	afx_msg void OnFirst();
	afx_msg void OnAdd();
	afx_msg void OnDelete();
	afx_msg void OnClear();
	afx_msg void OnImages();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMFS_H__09783F18_0ECB_4B66_B754_B92176045345__INCLUDED_)
