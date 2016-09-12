// InformerView.h : interface of the CInterComView class
//
/////////////////////////////////////////////////////////////////////////////

#include "ado.h"

#if !defined(AFX_INFORMERVIEW_H__6929CF4B_309F_11D7_A43C_E7333806FC4F__INCLUDED_)
#define AFX_INFORMERVIEW_H__6929CF4B_309F_11D7_A43C_E7333806FC4F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "GridCtrl/GridCtrl.h"
#include "FlatsInBH.h"
#include "FlatsFS.h"
#include "RoomsFS.h"
#include "ComFS.h"

#include "ExpInt.h"

#define PRN_XMARGIN		5
#define PRN_YMARGIN		5

static int nRowInPage, PageWight, PageHight;

class CInterComView : public CView
{
protected: // create from serialization only
	CInterComView();
	DECLARE_DYNCREATE(CInterComView)

	void PrintHead(CDC* pDC, CPrintInfo* pInfo);
	void PrintGridPage(CDC* pDC, CPrintInfo* pInfo);
	void PrintHeadCell(CDC* pDC, int nCol, int nRow, int x, int y);
	void PrintGridCell(CDC* pDC, int nCol, int nRow, int x, int y);

// Attributes
public:
//	CInterComDoc* GetDocument();

	CGridCtrl m_pGridCtrl;

	//		Жилая недвижимость
	CFlatsInBH* m_pFIBH;
	CFlatsFS* m_pFFS;
	CRoomsFS* m_pRFS;

	//		Коммерческая недвижимость
	CComFS* m_pCFS;

	//		Экспорт 
	CExpInt* m_pEI;

	DWORD app_w_mode;

	CString gfxMode;

// Operations
public:

//	virtual CALXCellCtrl* CreateCellCtrl(int nCol, int nRow, DWORD dwStyle = WS_CHILD, UINT nID = NULL);
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInterComView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	//}}AFX_VIRTUAL

//	virtual CELL_DATA GetCellData(int nCol, int nRow);
//	virtual BOOL OnSaveCellData(int nCol, int nRow);
//	virtual void OnSetActiveCell(int nCol, int nRow);

	LONG OnEndOfDial(UINT wParam, LONG lParam);
	LONG OnSetPointer(UINT wParam, LONG lParam);
	LONG OnSaveChanges(UINT wParam, LONG lParam);
	LONG OnDeleteCurrent(UINT wParam, LONG lParam);
	LONG OnAddNew(UINT wParam, LONG lParam);
	LONG OnMoveFirst(UINT wParam, LONG lParam);
	LONG OnMoveNext(UINT wParam, LONG lParam);
	LONG OnMovePrev(UINT wParam, LONG lParam);
	LONG OnMoveLast(UINT wParam, LONG lParam);
	LONG OnSendToInt(UINT wParam, LONG lParam);

	void InitForm(BOOL cur=FALSE);
	void GetFromDialog(BOOL cur=FALSE);
	void DeleteRow();
	void ExportToInternet();
	void ExportBN();
	void DeleteGfx(int idf);

	BOOL GetPrint();

	CString NumToStr(double var);

// Implementation
public:
	virtual ~CInterComView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

public:
//	CDialogBar	m_wndDlgBar;

protected:
	//ADO
	CADORecordset m_pRs;
	CADORecordset m_pdRs;
	CADODatabase m_pDb;
	CADODatabase m_pIDb;
	CADORecordset m_pIRs;
	
	

	//DAO
/*	DAODBEngine* pDBEngine;
	CDaoDatabase* db;
	CDaoRecordset* cf;*/

protected:

	BOOL s_edtable;
	int mode;
	int pr_mode;

public:

	BOOL print;		// Режим печати для SB

protected:

    CSize       m_PaperSize;	// Page size in device units.

// Generated message map functions
protected:
	//{{AFX_MSG(CInterComView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnRecordEditCur();
	afx_msg void OnUpdateRecordEditCur(CCmdUI* pCmdUI);
	afx_msg void OnRecordAdd();
	afx_msg void OnUpdateRecordAdd(CCmdUI* pCmdUI);
	afx_msg void OnRecordDeleteCur();
	afx_msg void OnUpdateRecordDeleteCur(CCmdUI* pCmdUI);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnDestroy();
	afx_msg void OnFileExportXml();
	afx_msg void OnFileExportInternet();
	afx_msg void OnListingsFlatsinbhFs();
	afx_msg void OnUpdateListingsFlatsinbhFs(CCmdUI* pCmdUI);
	afx_msg void OnListingsRoomsFs();
	afx_msg void OnUpdateListingsRoomsFs(CCmdUI* pCmdUI);
	afx_msg void OnListingsFlatsFs();
	afx_msg void OnUpdateListingsFlatsFs(CCmdUI* pCmdUI);
	afx_msg void OnServiceAgents();
	afx_msg void OnServiceAphones();
	afx_msg void OnServiceSprHtypes();
	afx_msg void OnServiceSprWc();
	afx_msg void OnServiceSprAppointment();
	afx_msg void OnServiceSprCondition();
	afx_msg void OnServiceSprDoorway();
	afx_msg void OnServiceSprEntrance();
	afx_msg void OnServiceSprObjtypes();
	afx_msg void OnListingsComFs();
	afx_msg void OnUpdateListingsComFs(CCmdUI* pCmdUI);
	afx_msg void OnListingsComFr();
	afx_msg void OnUpdateListingsComFr(CCmdUI* pCmdUI);
	afx_msg void OnRecordDeleteAll();
	afx_msg void OnFileExportPress();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	void DrawText(CDC* pDC, CString& str, CRect& rect, UINT nFormat );
};

#ifndef _DEBUG  // debug version in InformerView.cpp
//inline CInterComDoc* CInterComView::GetDocument()
//   { return (CInterComDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INFORMERVIEW_H__6929CF4B_309F_11D7_A43C_E7333806FC4F__INCLUDED_)
