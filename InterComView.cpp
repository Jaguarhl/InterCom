// InterComView.cpp : implementation of the CInterComView class
//

#include "stdafx.h"
#include "afxinet.h"
#include "InterCom.h"

#include "InterComDoc.h"
#include "InterComView.h"
#include "MainFrm.h"
#include "Dictionary.h"
#include "PressExport.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//struct ColInfo
//{
//	UINT	 nID;		  // ID for this column
//
//} m_ColInfo;

/////////////////////////////////////////////////////////////////////////////
// CInterComView

IMPLEMENT_DYNCREATE(CInterComView, CView)

BEGIN_MESSAGE_MAP(CInterComView, CView)
	//{{AFX_MSG_MAP(CInterComView)
	ON_WM_CREATE()
	ON_COMMAND(ID_RECORD_EDIT_CUR, OnRecordEditCur)
	ON_UPDATE_COMMAND_UI(ID_RECORD_EDIT_CUR, OnUpdateRecordEditCur)
	ON_COMMAND(ID_RECORD_ADD, OnRecordAdd)
	ON_UPDATE_COMMAND_UI(ID_RECORD_ADD, OnUpdateRecordAdd)
	ON_COMMAND(ID_RECORD_DELETE_CUR, OnRecordDeleteCur)
	ON_UPDATE_COMMAND_UI(ID_RECORD_DELETE_CUR, OnUpdateRecordDeleteCur)
	ON_WM_LBUTTONDOWN()
	ON_WM_DESTROY()
	ON_COMMAND(ID_FILE_EXPORT_XML, OnFileExportXml)
	ON_COMMAND(ID_FILE_EXPORT_INTERNET, OnFileExportInternet)
	ON_COMMAND(ID_LISTINGS_FLATSINBH, OnListingsFlatsinbhFs)
	ON_UPDATE_COMMAND_UI(ID_LISTINGS_FLATSINBH, OnUpdateListingsFlatsinbhFs)
	ON_COMMAND(ID_LISTINGS_ROOMS_FS, OnListingsRoomsFs)
	ON_UPDATE_COMMAND_UI(ID_LISTINGS_ROOMS_FS, OnUpdateListingsRoomsFs)
	ON_COMMAND(ID_LISTINGS_FLATS_FS, OnListingsFlatsFs)
	ON_UPDATE_COMMAND_UI(ID_LISTINGS_FLATS_FS, OnUpdateListingsFlatsFs)
	ON_COMMAND(ID_SERVICE_AGENTS, OnServiceAgents)
	ON_COMMAND(ID_SERVICE_APHONES, OnServiceAphones)
	ON_COMMAND(ID_SERVICE_SPR_HTYPES, OnServiceSprHtypes)
	ON_COMMAND(ID_SERVICE_SPR_WC, OnServiceSprWc)
	ON_COMMAND(ID_SERVICE_SPR_APPOINTMENT, OnServiceSprAppointment)
	ON_COMMAND(ID_SERVICE_SPR_CONDITION, OnServiceSprCondition)
	ON_COMMAND(ID_SERVICE_SPR_DOORWAY, OnServiceSprDoorway)
	ON_COMMAND(ID_SERVICE_SPR_ENTRANCE, OnServiceSprEntrance)
	ON_COMMAND(ID_SERVICE_SPR_OBJTYPES, OnServiceSprObjtypes)
	ON_COMMAND(ID_LISTINGS_COM_FS, OnListingsComFs)
	ON_UPDATE_COMMAND_UI(ID_LISTINGS_COM_FS, OnUpdateListingsComFs)
	ON_COMMAND(ID_LISTINGS_COM_FR, OnListingsComFr)
	ON_UPDATE_COMMAND_UI(ID_LISTINGS_COM_FR, OnUpdateListingsComFr)
	ON_COMMAND(ID_RECORD_DELETE_ALL, OnRecordDeleteAll)
	ON_COMMAND(ID_FILE_EXPORT_PRESS, OnFileExportPress)
	ON_MESSAGE(WM_ENDOFDIAL, OnEndOfDial)
	ON_MESSAGE(WM_SETPOINTER, OnSetPointer)
	ON_MESSAGE(WM_SAVECHANGES, OnSaveChanges)
	ON_MESSAGE(WM_DELETECUR, OnDeleteCurrent)
	ON_MESSAGE(WM_ADDNEW, OnAddNew)
	ON_MESSAGE(WM_MFIRST, OnMoveFirst)
	ON_MESSAGE(WM_MPREV, OnMovePrev)
	ON_MESSAGE(WM_MNEXT, OnMoveNext)
	ON_MESSAGE(WM_MLAST, OnMoveLast)
	ON_MESSAGE(WM_SENDTOINT, OnSendToInt)
	ON_WM_LBUTTONDBLCLK()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInterComView construction/destruction

CInterComView::CInterComView()
{
//	m_pGridCtrl = NULL;

	app_w_mode=APP_W_MODE;

	print=FALSE;
	pr_mode=0;

	// TODO: add construction code here
	if(app_w_mode==2)
	{
		mode=FinBH;

/*		CString strHeadTitle;
		strHeadTitle.LoadString(ID_ID);
		AddCol(25, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_ID);
		strHeadTitle.LoadString(ID_AGENT);
		AddCol(100, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_AGENT);
		strHeadTitle.LoadString(ID_ROOMS);
		AddCol(25, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_ROOMS);
		strHeadTitle.LoadString(ID_DISTRICT);
		AddCol(100, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_DISTRICT);
		strHeadTitle.LoadString(ID_ADDRESS);
		AddCol(150, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_ADDRESS);
		strHeadTitle.LoadString(ID_FLOORS);
		AddCol(45, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_FLOORS);
		strHeadTitle.LoadString(ID_SGENERAL);
		AddCol(55, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_SGENERAL);
		strHeadTitle.LoadString(ID_SKITCHEN);
		AddCol(45, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_SKITCHEN);
		strHeadTitle.LoadString(ID_SROOMS);
		AddCol(200, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_SROOMS);
		strHeadTitle.LoadString(ID_METRO);
		AddCol(150, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_METRO);
		strHeadTitle.LoadString(ID_HTYPE);
		AddCol(25, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_HTYPE);
		strHeadTitle.LoadString(ID_WC);
		AddCol(25, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_WC);
		strHeadTitle.LoadString(ID_PRICE);
		AddCol(85, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_PRICE);
		strHeadTitle.LoadString(ID_B_END);
		AddCol(65, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_B_END);
		strHeadTitle.LoadString(ID_DESCRIPTION);
		AddCol(170, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_DESCRIPTION);
		strHeadTitle.LoadString(ID_A_PHONE);
		AddCol(60, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_A_PHONE);
			
		SetGridRowCount(0);*/
	}
	else if(app_w_mode==1)
	{
		mode = CFS;
		gfxMode="CFS";

/*		CString strHeadTitle;
		strHeadTitle.LoadString(ID_ID);
//		DefineColCtrl(AddCol(25, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_ID),GA_CELLCTRL);
//		EnableCtrl(FALSE);
		AddCol(25, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_ID);
		strHeadTitle.LoadString(ID_AGENT);
		AddCol(100, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_AGENT);
		strHeadTitle.LoadString(ID_OBJ_TYPE);
		AddCol(100, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_OBJ_TYPE);
		strHeadTitle.LoadString(ID_DISTRICT);
		AddCol(100, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_DISTRICT);
		strHeadTitle.LoadString(ID_ADDRESS);
		AddCol(150, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_ADDRESS);
		strHeadTitle.LoadString(ID_FLOORS);
		AddCol(45, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_FLOORS);
		strHeadTitle.LoadString(ID_SGENERAL);
		AddCol(55, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_SGENERAL);
		strHeadTitle.LoadString(ID_SPLOT);
		AddCol(45, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_SPLOT);
		strHeadTitle.LoadString(ID_CEILINGHEIGHT);
		AddCol(45, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_CEILINGHEIGHT);
		strHeadTitle.LoadString(ID_ENTRANCE);
		AddCol(45, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_ENTRANCE);
		strHeadTitle.LoadString(ID_CONDITION);
		AddCol(100, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_CONDITION);
		strHeadTitle.LoadString(ID_ELECTRICITY);
		AddCol(45, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_ELECTRICITY);
		strHeadTitle.LoadString(ID_WATERSUPPLY);
		AddCol(45, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_WATERSUPPLY);
		strHeadTitle.LoadString(ID_HEATING);
		AddCol(45, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_HEATING);
		strHeadTitle.LoadString(ID_SEWERAGE);
		AddCol(45, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_SEWERAGE);
		strHeadTitle.LoadString(ID_PARKING);
		AddCol(45, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_PARKING);
		strHeadTitle.LoadString(ID_GUARD_S);
		AddCol(45, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_GUARD_S);
		strHeadTitle.LoadString(ID_FIRE_S);
		AddCol(45, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_FIRE_S);
		strHeadTitle.LoadString(ID_PHONE);
		AddCol(45, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_PHONE);
		strHeadTitle.LoadString(ID_DOORWAY);
		AddCol(45, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_DOORWAY);
		strHeadTitle.LoadString(ID_APPOINTMENT);
		AddCol(100, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_APPOINTMENT);
		strHeadTitle.LoadString(ID_PRICE);
		AddCol(85, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_PRICE);
		strHeadTitle.LoadString(ID_DESCRIPTION);
		AddCol(170, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_DESCRIPTION);
		strHeadTitle.LoadString(ID_A_PHONE);
		AddCol(60, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_A_PHONE);

		SetGridRowCount(0);

//		SetFrozenColCount(3);*/
	}
			// Standard initialization
}

CInterComView::~CInterComView()
{
	if (m_pGridCtrl)
		delete m_pGridCtrl;

	TRACE0("Starting to delete database objects");
	m_pRs.Close();
	m_pdRs.Close();
	m_pDb.Close();
	TRACE0("Stoped to delete database objects");
}

BOOL CInterComView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	
//	cs.style |= AGS_FLAT | AGS_ROWSELECT;

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CInterComView data exchange

/*CELL_DATA CInterComView::GetCellData(int nCol, int nRow)
{
	CELL_DATA CellData = CALXGrid::GetCellData(nCol,nRow);

	int r=m_pRs.GetRecordCount();
	if(r>0)
	{
		m_pRs.SetAbsolutePosition(nRow+1);

		switch(GetCellCtrlID(nCol,nRow))
		{
			case ID_ID: 
			{
				char num[10];
				int id=0;
				m_pRs.GetFieldValue("ID", id);
				itoa(id, num, 10);
				CellData.m_strText = num;
				break;
			}
			case ID_AGENT: 
			{
				CString s;
				m_pRs.GetFieldValue("AGENT", s);
				CellData.m_strText = s;
				break;
			}
			case ID_DISTRICT: 
			{
				CString s;
				m_pRs.GetFieldValue("DISTRICT", s);
				CellData.m_strText = s;
				break;
			}
			case ID_ROOMS: 
			{
				char num[10];
				int id=0;
				m_pRs.GetFieldValue("ROOMS", id);
				itoa(id, num, 10);
				CellData.m_strText = num;
				break;
			}
			case ID_FLOORS: 
			{
				CString s;
				char num[10];
				int id=0;
				m_pRs.GetFieldValue("FLOOR", id);
				itoa(id, num, 10);
				s=num;
				s+="/";
				m_pRs.GetFieldValue("FLOORS", id);
				itoa(id, num, 10);
				s+=num;
				CellData.m_strText = s;
				break;
			}
			case ID_SGENERAL: 
			{
				double id=0;
				m_pRs.GetFieldValue("S_GENERAL", id);
				CellData.m_strText = NumToStr(id);
				break;
			}
			case ID_SKITCHEN: 
			{
				double id=0;
				m_pRs.GetFieldValue("S_KITCHEN", id);
				CellData.m_strText = NumToStr(id);
				break;
			}
			case ID_SPLOT: 
			{
				double id=0;
				m_pRs.GetFieldValue("S_PLOT", id);
				CellData.m_strText = NumToStr(id);
				break;
			}
			case ID_SROOMS: 
			{
				CString s;
				double id=0;
				m_pRs.GetFieldValue("S_R1", id);
				s=NumToStr(id);			
				m_pRs.GetFieldValue("S_R2", id);
				if(id>0)
				{
					s+=" + ";
					m_pRs.GetFieldValue("S_R2", id);
					s+=NumToStr(id);
				}
				m_pRs.GetFieldValue("S_R3", id);
				if(id>0)
				{
					s+=" + ";
					m_pRs.GetFieldValue("S_R3", id);
					s+=NumToStr(id);
				}
				m_pRs.GetFieldValue("S_R4", id);
				if(id>0)
				{
					s+=" + ";
					m_pRs.GetFieldValue("S_R4", id);
					s+=NumToStr(id);
				}
				m_pRs.GetFieldValue("S_R5", id);
				if(id>0)
				{
					s+=" + ";
					m_pRs.GetFieldValue("S_R5", id);
					s+=NumToStr(id);
				}
				m_pRs.GetFieldValue("S_R6", id);
				if(id>0)
				{
					s+=" + ";
					m_pRs.GetFieldValue("S_R6", id);
					s+=NumToStr(id);
				}
				m_pRs.GetFieldValue("S_R7", id);
				if(id>0)
				{
					s+=" + ";
					m_pRs.GetFieldValue("S_R7", id);
					s+=NumToStr(id);
				}
				m_pRs.GetFieldValue("S_R8", id);
				if(id>0)
				{
					s+=" + ";
					m_pRs.GetFieldValue("S_R8", id);
					s+=NumToStr(id);
				}
				m_pRs.GetFieldValue("S_R9", id);
				if(id>0)
				{
					s+=" + ";
					m_pRs.GetFieldValue("S_R9", id);
					s+=NumToStr(id);
				}
				m_pRs.GetFieldValue("S_R10", id);
				if(id>0)
				{
					s+=" + ";
					m_pRs.GetFieldValue("S_R10", id);
					s+=NumToStr(id);
				}
				m_pRs.GetFieldValue("S_R11", id);
				if(id>0)
				{
					s+=" + ";
					m_pRs.GetFieldValue("S_R11", id);
					s+=NumToStr(id);
				}
				m_pRs.GetFieldValue("S_R12", id);
				if(id>0)
				{
					s+=" + ";
					m_pRs.GetFieldValue("S_R12", id);
					s+=NumToStr(id);
				}
				m_pRs.GetFieldValue("S_R13", id);
				if(id>0)
				{
					s+=" + ";
					m_pRs.GetFieldValue("S_R13", id);
					s+=NumToStr(id);
				}
				m_pRs.GetFieldValue("S_R14", id);
				if(id>0)
				{
					s+=" + ";
					m_pRs.GetFieldValue("S_R14", id);
					s+=NumToStr(id);
				}	
				m_pRs.GetFieldValue("S_R15", id);
				if(id>0)
				{
					s+=" + ";
					m_pRs.GetFieldValue("S_R15", id);
					s+=NumToStr(id);
				}
				m_pRs.GetFieldValue("S_R16", id);
				if(id>0)
				{
					s+=" + ";
					m_pRs.GetFieldValue("S_R16", id);
					s+=NumToStr(id);
				}
				m_pRs.GetFieldValue("S_R17", id);
				if(id>0)
				{
					s+=" + ";
					m_pRs.GetFieldValue("S_R17", id);
					s+=NumToStr(id);
				}
				m_pRs.GetFieldValue("S_R18", id);
				if(id>0)
				{
					s+=" + ";
					m_pRs.GetFieldValue("S_R18", id);
					s+=NumToStr(id);
				}
				m_pRs.GetFieldValue("S_R19", id);
				if(id>0)
				{
					s+=" + ";
					m_pRs.GetFieldValue("S_R19", id);
					s+=NumToStr(id);
				}
				m_pRs.GetFieldValue("S_R20", id);
				if(id>0)
				{
					s+=" + ";
					m_pRs.GetFieldValue("S_R20", id);
					s+=NumToStr(id);
				}
				CellData.m_strText = s;
				break;
			}
//			if(mode==RFS)
//			{
			case ID_RRN:
			{
				CString s;
				char num[10];
				int id=0;
				m_pRs.GetFieldValue("W_ROOMS", id);
				itoa(id, num, 10);
				s=num;
				s+="/";
				m_pRs.GetFieldValue("RENTERS", id);
				itoa(id, num, 10);
				s+=num;
				s+="/";
				m_pRs.GetFieldValue("NEIGHBOURS", id);
				itoa(id, num, 10);
				s+=num;
				CellData.m_strText = s;
				break;
			}
//		}
			case ID_ADDRESS: 
			{
				CString s;
				m_pRs.GetFieldValue("ADDRESS", s);
				CellData.m_strText = s;
				break;
			}
			case ID_METRO: 
			{
				CString s;
				CString r;
				m_pRs.GetFieldValue("METRO", s);
				s+=", ";
				char num[10];
				int id=0;
				m_pRs.GetFieldValue("DISTANCE", id);
				itoa(id, num, 10);
				s+=num;
				m_pRs.GetFieldValue("IN_WHAT", r);
				s+=" ";
				s+=r;
				CellData.m_strText = s;
				break;
			}
			case ID_HTYPE: 
			{
				CString s;
				m_pRs.GetFieldValue("H_TYPE", s);
				CellData.m_strText = s;
				break;
			}
			case ID_WC: 
			{
				CString s;
				m_pRs.GetFieldValue("WC", s);
				CellData.m_strText = s;
				break;
			}
			case ID_PRICE: 
			{
				CString s;
				CString r;
				char num[10];
				int id=0;
				m_pRs.GetFieldValue("PRICE", id);
				itoa(id, num, 10);
				s+=num;
				m_pRs.GetFieldValue("P_TYPE", r);
				s+=" / ";
				s+=r;
				CellData.m_strText = s;
				break;
			}
//			if(mode==FinBH)
//			{
				case ID_B_END: 
				{
					CString s;
					m_pRs.GetFieldValue("B_END", s);
					CellData.m_strText = s;
					break;
				}
//			}
//		if((mode==FFS) || (mode==RFS))
//		{
			case ID_PHONE: 
			{
				CString s;
				m_pRs.GetFieldValue("PHONE", s);
				CellData.m_strText = s;
				break;
			}
			case ID_ELECTRICITY: 
			{
				CString s;
				m_pRs.GetFieldValue("ELECTRICITY", s);
				CellData.m_strText = s;
				break;
			}
			case ID_WATERSUPPLY: 
			{
				CString s;
				m_pRs.GetFieldValue("WATER_SUPPLY", s);
				CellData.m_strText = s;
				break;
			}
			case ID_SEWERAGE: 
			{
				CString s;
				m_pRs.GetFieldValue("SEWERAGE", s);
				CellData.m_strText = s;
				break;
			}
			case ID_HEATING: 
			{
				CString s;
				m_pRs.GetFieldValue("HEATING", s);
				CellData.m_strText = s;
				break;
			}
			case ID_PARKING: 
			{
				CString s;
				m_pRs.GetFieldValue("PARKING", s);
				CellData.m_strText = s;
				break;
			}
			case ID_GUARD_S: 
			{
				CString s;
				m_pRs.GetFieldValue("GUARD_SIGNALLING", s);
				CellData.m_strText = s;
				break;
			}
			case ID_FIRE_S: 
			{
				CString s;
				m_pRs.GetFieldValue("FIRE_SIGNALLING", s);
				CellData.m_strText = s;
				break;
			}
			case ID_CONDITION: 
			{
				CString s;
				m_pRs.GetFieldValue("CONDITION", s);
				CellData.m_strText = s;
				break;
			}
			case ID_OBJ_TYPE: 
			{
				CString s;
				m_pRs.GetFieldValue("OBJECT_TYPE", s);
				CellData.m_strText = s;
				break;
			}
			case ID_CEILINGHEIGHT: 
			{
				double id=0;
				m_pRs.GetFieldValue("CEILING_HEIGHT", id);
				CellData.m_strText = NumToStr(id);
				break;
			}
			case ID_ENTRANCE: 
			{
				CString s;
				m_pRs.GetFieldValue("ENTRANCE", s);
				CellData.m_strText = s;
				break;
			}
			case ID_DOORWAY: 
			{
				CString s;
				m_pRs.GetFieldValue("DOORWAY", s);
				CellData.m_strText = s;
				break;
			}
			case ID_APPOINTMENT: 
			{
				CString s;
				m_pRs.GetFieldValue("APPOINTMENT", s);
				CellData.m_strText = s;
				break;
			}
//		}
			case ID_DESCRIPTION: 
			{
				CString s;
				m_pRs.GetFieldValue("DESCRIPTION", s);
				CellData.m_strText = s;
				break;
			}
			case ID_A_PHONE: 
			{
				CString s;
				m_pRs.GetFieldValue("A_PHONE", s);
				CellData.m_strText = s;
				break;
			}
		}
	}

	return CellData;
	TRACE0("Finishing to fill this cell\n");
}

BOOL CInterComView::OnSaveCellData(int nCol, int nRow)
{
//	CInterComDoc* pDoc = GetDocument();
	CALXCellCtrl* pCellCtrl = GetCellCtrl(nCol,nRow);
	if(pCellCtrl != NULL)
	{
		CELL_DATA Data = pCellCtrl->GetCellData();
	}
	return TRUE;
}*/

/////////////////////////////////////////////////////////////////////////////
// CInterComView drawing

void CInterComView::OnDraw(CDC* pDC)
{
//	CInterComDoc* pDoc = GetDocument();
//	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

void CInterComView::OnInitialUpdate()
{

	CView::OnInitialUpdate();

	s_edtable=FALSE;

	CRect rect;
	GetClientRect(rect);
	m_pGridCtrl.Create(rect, this, 100);

	m_pGridCtrl.SetEditable(FALSE);
	m_pGridCtrl.SetGridBkColor(RGB(255, 255, 255));
	m_pGridCtrl.SetGridLineColor(RGB(236, 233, 216));
	m_pGridCtrl.SetListMode();
	m_pGridCtrl.SetSingleRowSelection();
	m_pGridCtrl.SetFixedColumnSelection(FALSE);
	m_pGridCtrl.SetHeaderSort();
	m_pGridCtrl.SetDefCellHeight(18);
	m_pGridCtrl.SetFrameFocusCell(FALSE);
	m_pGridCtrl.AutoSize(GVS_HEADER);

	TRACE0("Let's init DB\n");
//	CString strConnection = _T("Driver={Microsoft Access Driver (*.mdb)};" "Dbq=Database\\listings.mdb;Uid=;Pwd=;");              
	if(m_pDb.Open(strConnection))
	{	
		m_pRs = CADORecordset(&m_pDb);
		m_pdRs = CADORecordset(&m_pDb);
		TRACE0("DB opened\n");

		if(app_w_mode==2)
		{
			if(m_pRs.Open("FlatsInBH_FS", CADORecordset::openTable))
			{
				TRACE0("Recordset opened\n");
				
				// Create the Gridctrl window
				CRect rect;
				GetClientRect(rect);
				m_pGridCtrl.Create(rect, this, 100);
					
					// fill it up with stuff
				m_pGridCtrl.SetEditable(FALSE);
					
				try {
					m_pGridCtrl.SetRowCount(m_pRs.GetRecordCount()+1);
					m_pGridCtrl.SetColumnCount(0);
					m_pGridCtrl.SetFixedColumnCount(1);
				}
				catch (CMemoryException* e)
				{
					e->ReportError();
					e->Delete();
					return;
				}
					
				CString strHeadTitle;
				strHeadTitle.LoadString(ID_ID);
				m_pGridCtrl.InsertColumn(strHeadTitle, 0, -1);
				
/*				strHeadTitle.LoadString(ID_AGENT);
				AddCol(100, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_AGENT);
				strHeadTitle.LoadString(ID_ROOMS);
				AddCol(25, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_ROOMS);
				strHeadTitle.LoadString(ID_DISTRICT);
				AddCol(100, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_DISTRICT);
				strHeadTitle.LoadString(ID_ADDRESS);
				AddCol(150, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_ADDRESS);
				strHeadTitle.LoadString(ID_FLOORS);
				AddCol(45, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_FLOORS);
				strHeadTitle.LoadString(ID_SGENERAL);
				AddCol(55, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_SGENERAL);
				strHeadTitle.LoadString(ID_SKITCHEN);
				AddCol(45, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_SKITCHEN);
				strHeadTitle.LoadString(ID_SROOMS);
				AddCol(200, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_SROOMS);
				strHeadTitle.LoadString(ID_METRO);
				AddCol(150, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_METRO);
				strHeadTitle.LoadString(ID_HTYPE);
				AddCol(25, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_HTYPE);
				strHeadTitle.LoadString(ID_WC);
				AddCol(25, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_WC);
				strHeadTitle.LoadString(ID_PRICE);
				AddCol(85, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_PRICE);
				strHeadTitle.LoadString(ID_B_END);
				AddCol(65, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_B_END);
				strHeadTitle.LoadString(ID_DESCRIPTION);
				AddCol(170, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_DESCRIPTION);
				strHeadTitle.LoadString(ID_A_PHONE);
				AddCol(60, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_A_PHONE);
	
//				SetGridRowCount(0);
				SetGridRowCount(m_pRs.GetRecordCount());*/

				AfxGetMainWnd()->SetWindowText("Dark Unicorn InterCom RE :: Жилая недвижимость - Квартиры в строящихся домах");

			}
		}
		else if(app_w_mode==1)
		{
			gfxMode="CFS";
			if(m_pRs.Open("ComRE_FS", CADORecordset::openTable))
			{
				TRACE0("Recordset opened\n");

				try 
				{
					m_pGridCtrl.SetRowCount(m_pRs.GetRecordCount()+1);
					m_pGridCtrl.SetColumnCount(0);
					m_pGridCtrl.SetFixedRowCount(1);
				}
				catch (CMemoryException* e)
				{
					e->ReportError();
					e->Delete();
					return;
				}
					
				CString strHeadTitle;
				strHeadTitle.LoadString(ID_ID);
				m_pGridCtrl.InsertColumn(strHeadTitle, 0, -1);
				m_pGridCtrl.SetColumnWidth(0, 25);
				strHeadTitle.LoadString(ID_AGENT);
				m_pGridCtrl.InsertColumn(strHeadTitle, 0, -1);
				m_pGridCtrl.SetColumnWidth(1, 100);
				strHeadTitle.LoadString(ID_OBJ_TYPE);
				m_pGridCtrl.InsertColumn(strHeadTitle, 0, -1);
				m_pGridCtrl.SetColumnWidth(2, 100);
				strHeadTitle.LoadString(ID_DISTRICT);
				m_pGridCtrl.InsertColumn(strHeadTitle, 0, -1);
				m_pGridCtrl.SetColumnWidth(3, 100);
				strHeadTitle.LoadString(ID_ADDRESS);
				m_pGridCtrl.InsertColumn(strHeadTitle, 0, -1);
				m_pGridCtrl.SetColumnWidth(4, 150);
				strHeadTitle.LoadString(ID_FLOORS);
				m_pGridCtrl.InsertColumn(strHeadTitle, 0, -1);
				m_pGridCtrl.SetColumnWidth(5, 45);
				strHeadTitle.LoadString(ID_SGENERAL);
				m_pGridCtrl.InsertColumn(strHeadTitle, 0, -1);
				m_pGridCtrl.SetColumnWidth(6, 55);
				strHeadTitle.LoadString(ID_SPLOT);
				m_pGridCtrl.InsertColumn(strHeadTitle, 0, -1);
				m_pGridCtrl.SetColumnWidth(7, 45);
				strHeadTitle.LoadString(ID_CEILINGHEIGHT);
				m_pGridCtrl.InsertColumn(strHeadTitle, 0, -1);
				m_pGridCtrl.SetColumnWidth(8, 45);
				strHeadTitle.LoadString(ID_ENTRANCE);
				m_pGridCtrl.InsertColumn(strHeadTitle, 0, -1);
				m_pGridCtrl.SetColumnWidth(9, 45);
				strHeadTitle.LoadString(ID_CONDITION);
				m_pGridCtrl.InsertColumn(strHeadTitle, 0, -1);
				m_pGridCtrl.SetColumnWidth(10, 100);
				strHeadTitle.LoadString(ID_ELECTRICITY);
				m_pGridCtrl.InsertColumn(strHeadTitle, 0, -1);
				m_pGridCtrl.SetColumnWidth(11, 25);
				strHeadTitle.LoadString(ID_WATERSUPPLY);
				m_pGridCtrl.InsertColumn(strHeadTitle, 0, -1);
				m_pGridCtrl.SetColumnWidth(12, 25);
				strHeadTitle.LoadString(ID_HEATING);
				m_pGridCtrl.InsertColumn(strHeadTitle, 0, -1);
				m_pGridCtrl.SetColumnWidth(13, 25);
				strHeadTitle.LoadString(ID_SEWERAGE);
				m_pGridCtrl.InsertColumn(strHeadTitle, 0, -1);
				m_pGridCtrl.SetColumnWidth(14, 25);
				strHeadTitle.LoadString(ID_PARKING);
				m_pGridCtrl.InsertColumn(strHeadTitle, 0, -1);
				m_pGridCtrl.SetColumnWidth(15, 25);
				strHeadTitle.LoadString(ID_GUARD_S);
				m_pGridCtrl.InsertColumn(strHeadTitle, 0, -1);
				m_pGridCtrl.SetColumnWidth(16, 25);
				strHeadTitle.LoadString(ID_FIRE_S);
				m_pGridCtrl.InsertColumn(strHeadTitle, 0, -1);
				m_pGridCtrl.SetColumnWidth(17, 25);
				strHeadTitle.LoadString(ID_PHONE);
				m_pGridCtrl.InsertColumn(strHeadTitle, 0, -1);
				m_pGridCtrl.SetColumnWidth(18, 25);
				strHeadTitle.LoadString(ID_DOORWAY);
				m_pGridCtrl.InsertColumn(strHeadTitle, 0, -1);
				m_pGridCtrl.SetColumnWidth(19, 25);
				strHeadTitle.LoadString(ID_APPOINTMENT);
				m_pGridCtrl.InsertColumn(strHeadTitle, 0, -1);
				m_pGridCtrl.SetColumnWidth(20, 100);
				strHeadTitle.LoadString(ID_PRICE);
				m_pGridCtrl.InsertColumn(strHeadTitle, 0, -1);
				m_pGridCtrl.SetColumnWidth(21, 85);
				strHeadTitle.LoadString(ID_DESCRIPTION);
				m_pGridCtrl.InsertColumn(strHeadTitle, 0, -1);
				m_pGridCtrl.SetColumnWidth(22, 170);
				strHeadTitle.LoadString(ID_A_PHONE);
				m_pGridCtrl.InsertColumn(strHeadTitle, 0, -1);
				m_pGridCtrl.SetColumnWidth(23, 60);

				AfxGetMainWnd()->SetWindowText("Dark Unicorn InterCom RE :: Коммерческая недвижимость - Продажа");

			}
		}
	}
	else
	{
		AfxMessageBox(m_pDb.GetLastErrorString());
		DWORD dwError = m_pDb.GetLastError();
	}

}

/////////////////////////////////////////////////////////////////////////////
// CInterComView printing

BOOL CInterComView::OnPreparePrinting(CPrintInfo* pInfo)
{
	return DoPreparePrinting(pInfo);
}

void CInterComView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	if (m_pGridCtrl)
		m_pGridCtrl.OnBeginPrinting(pDC, pInfo);
}

void CInterComView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	if (m_pGridCtrl)
		m_pGridCtrl.OnEndPrinting(pDC, pInfo);
}


/////////////////////////////////////////////////////////////////////////////
// CInterComView diagnostics

#ifdef _DEBUG
void CInterComView::AssertValid() const
{
	CView::AssertValid();
}

void CInterComView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

/*CInterComDoc* CInterComView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CInterComDoc)));
	return (CInterComDoc*)m_pDocument;
}*/
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CInterComView message handlers


int CInterComView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	return 0;
}

//********************************************************************
// Обработка событий диалога  //**************************************
////////////////////////////////**************************************

LONG CInterComView::OnEndOfDial(UINT wParam, LONG lParam)
{
	if(mode==FinBH)
	{
		m_pFIBH->DestroyWindow();
		delete m_pFIBH;
	}
	else if(mode==FFS)
	{
		m_pFFS->DestroyWindow();
		delete m_pFFS;
	}
	else if(mode==RFS)
	{
		m_pRFS->DestroyWindow();
		delete m_pRFS;
	}
	else if((mode==CFS) || (mode==CFR))
	{
		m_pCFS->DestroyWindow();
		delete m_pCFS;
	}
	else if(mode==EI)
	{
		m_pEI->DestroyWindow();
		delete m_pEI;
		mode=pr_mode;
	}
	s_edtable=!s_edtable;

	return 0;
}

LONG CInterComView::OnSetPointer(UINT wParam, LONG lParam)
{
	if(mode==FinBH)
		m_pFIBH = (CFlatsInBH*)m_gpMyApp;
	else if(mode==FFS)
		m_pFFS = (CFlatsFS*)m_gpMyApp;
	else if(mode==RFS)
		m_pRFS = (CRoomsFS*)m_gpMyApp;
	else if((mode==CFS) || (mode==CFR))
		m_pCFS = (CComFS*)m_gpMyApp;
	else if(mode==EI)
		m_pEI = (CExpInt*)m_gpMyApp;
	
	return 0;
} 

LONG CInterComView::OnSaveChanges(UINT wParam, LONG lParam)
{
	if(mode==FinBH)
	{
		if(m_pFIBH->cur==TRUE)
			GetFromDialog(TRUE);
		else
			GetFromDialog();
	}
	else if(mode==FFS)
	{
		if(m_pFFS->cur==TRUE)
			GetFromDialog(TRUE);
		else
			GetFromDialog();
	}
	else if(mode==RFS)
	{
		if(m_pRFS->cur==TRUE)
			GetFromDialog(TRUE);
		else
			GetFromDialog();
	}
	else if((mode==CFS) || (mode==CFR))
	{
		if(m_pCFS->cur==TRUE)
			GetFromDialog(TRUE);
		else
			GetFromDialog();
	}

	return 0;
}

LONG CInterComView::OnDeleteCurrent(UINT wParam, LONG lParam)
{
	DeleteRow();

	InitForm(TRUE);

	return 0;
}

LONG CInterComView::OnAddNew(UINT wParam, LONG lParam)
{
	if(mode==FinBH)
	{
		m_pFIBH->DestroyWindow();
		m_pFIBH = new CFlatsInBH(this);
		m_pFIBH->Create();
		m_pFIBH->m_rooms.SetWindowText("1");
		m_pFIBH->m_delete.EnableWindow(FALSE);
	}
	else if(mode==FFS)
	{
		m_pFFS->DestroyWindow();
		m_pFFS = new CFlatsFS(this);
		m_pFFS->Create();
		m_pFFS->m_rooms.SetWindowText("1");
		m_pFFS->m_delete.EnableWindow(FALSE);
	}
	else if(mode==RFS)
	{
		m_pRFS->DestroyWindow();
		m_pRFS = new CRoomsFS(this);
		m_pRFS->Create();
		m_pRFS->m_rooms.SetWindowText("1");
		m_pRFS->m_delete.EnableWindow(FALSE);
	}
	else if((mode==CFS) || (mode==CFR))
	{
		m_pCFS->DestroyWindow();
		m_pCFS = new CComFS(this);
		m_pCFS->Create();
		m_pCFS->m_delete.EnableWindow(FALSE);
	}
	InitForm(FALSE);

	return 0;
}

LONG CInterComView::OnMoveFirst(UINT wParam, LONG lParam)
{
	m_pGridCtrl.SetFocusCell(0, 0);
	m_pGridCtrl.SetSelectedRange(0, 0, 0, m_pGridCtrl.GetColumnCount()-1);
	Invalidate();
	InitForm(TRUE);

	return 0;
}

LONG CInterComView::OnMovePrev(UINT wParam, LONG lParam)
{
	m_pGridCtrl.SetFocusCell(m_pGridCtrl.GetFocusCell().row - 1, 0);
	m_pGridCtrl.SetSelectedRange(m_pGridCtrl.GetFocusCell().row, 0, m_pGridCtrl.GetFocusCell().row, m_pGridCtrl.GetColumnCount()-1);
	Invalidate();
	InitForm(TRUE);

	return 0;
}

LONG CInterComView::OnMoveNext(UINT wParam, LONG lParam)
{
	if(m_pGridCtrl.GetFocusCell().row + 1 <= m_pRs.GetRecordCount())
	{
		m_pGridCtrl.SetFocusCell(m_pGridCtrl.GetFocusCell().row + 1, 0);
		m_pGridCtrl.SetSelectedRange(m_pGridCtrl.GetFocusCell().row, 0, m_pGridCtrl.GetFocusCell().row, m_pGridCtrl.GetColumnCount()-1);
		Invalidate();
		InitForm(TRUE);
	}

	return 0;
}

LONG CInterComView::OnMoveLast(UINT wParam, LONG lParam)
{
	m_pGridCtrl.SetFocusCell(m_pRs.GetRecordCount(), 0);
	m_pGridCtrl.SetSelectedRange(m_pRs.GetRecordCount(), 0, m_pRs.GetRecordCount(), m_pGridCtrl.GetColumnCount()-1);
	Invalidate();
	InitForm(TRUE);

	return 0;
}

LONG CInterComView::OnSendToInt(UINT wParam, LONG lParam)
{

	ExportToInternet();

	return 0;
}

//////////////////////////////////////////////////////////////////////
// Конец обработки событий диалога
//********************************************************************

void CInterComView::InitForm(BOOL cur)
{
	if(mode==FinBH)
	{
		m_pFIBH->cur=cur;

		//Load agents data
		if(m_pdRs.Open("Agents", CADORecordset::openTable))
		{
			for(UINT i=1; i<=m_pdRs.GetRecordCount(); i++)
			{
				m_pdRs.SetAbsolutePosition(i);
				CString s;
				m_pdRs.GetFieldValue("AGENT", s);
				m_pFIBH->m_agent.AddString(s);
			}
		
			m_pdRs.Close();
		}
		if(m_pdRs.Open("Phones", CADORecordset::openTable))
		{
			for(UINT i=1; i<=m_pdRs.GetRecordCount(); i++)
			{
				m_pdRs.SetAbsolutePosition(i);
				CString s;
				m_pdRs.GetFieldValue("PHONE", s);
				m_pFIBH->m_aphone.AddString(s);
			}
		
			m_pdRs.Close();
		}
		if(m_pdRs.Open("Bathroom", CADORecordset::openTable))
		{
			for(UINT i=1; i<=m_pdRs.GetRecordCount(); i++)
			{
				m_pdRs.SetAbsolutePosition(i);
				CString s;
				m_pdRs.GetFieldValue("WC", s);
				m_pFIBH->m_wc.AddString(s);
			}
	
			m_pdRs.Close();
		}
		if(m_pdRs.Open("Htype", CADORecordset::openTable))
		{
			for(UINT i=1; i<=m_pdRs.GetRecordCount(); i++)
			{
				m_pdRs.SetAbsolutePosition(i);
				CString s;
				m_pdRs.GetFieldValue("HTYPE", s);
				m_pFIBH->m_htype.AddString(s);
			}
	
			m_pdRs.Close();
		}
		if(m_pdRs.Open("Metro", CADORecordset::openTable))
		{
			for(UINT i=1; i<=m_pdRs.GetRecordCount(); i++)
			{
				m_pdRs.SetAbsolutePosition(i);
				CString s;
				m_pdRs.GetFieldValue("METRO", s);
				m_pFIBH->m_metro.AddString(s);
			}
	
			m_pdRs.Close();
		}
		if(m_pdRs.Open("District", CADORecordset::openTable))
		{
			for(UINT i=1; i<=m_pdRs.GetRecordCount(); i++)
			{
				m_pdRs.SetAbsolutePosition(i);
				CString s;
				m_pdRs.GetFieldValue("DISTRICT", s);
				m_pFIBH->m_district.AddString(s);
			}
	
			m_pdRs.Close();
		}
	}
	else if(mode==FFS)
	{
		m_pFFS->cur=cur;

		//Load agents data
		if(m_pdRs.Open("Agents", CADORecordset::openTable))
		{
			for(UINT i=1; i<=m_pdRs.GetRecordCount(); i++)
			{
				m_pdRs.SetAbsolutePosition(i);
				CString s;
				m_pdRs.GetFieldValue("AGENT", s);
				m_pFFS->m_agent.AddString(s);
			}
		
			m_pdRs.Close();
		}
		if(m_pdRs.Open("Phones", CADORecordset::openTable))
		{
			for(UINT i=1; i<=m_pdRs.GetRecordCount(); i++)
			{
				m_pdRs.SetAbsolutePosition(i);
				CString s;
				m_pdRs.GetFieldValue("PHONE", s);
				m_pFFS->m_aphone.AddString(s);
			}
		
			m_pdRs.Close();
		}
		if(m_pdRs.Open("Bathroom", CADORecordset::openTable))
		{
			for(UINT i=1; i<=m_pdRs.GetRecordCount(); i++)
			{
				m_pdRs.SetAbsolutePosition(i);
				CString s;
				m_pdRs.GetFieldValue("WC", s);
				m_pFFS->m_wc.AddString(s);
			}
	
			m_pdRs.Close();
		}
		if(m_pdRs.Open("Htype", CADORecordset::openTable))
		{
			for(UINT i=1; i<=m_pdRs.GetRecordCount(); i++)
			{
				m_pdRs.SetAbsolutePosition(i);
				CString s;
				m_pdRs.GetFieldValue("HTYPE", s);
				m_pFFS->m_htype.AddString(s);
			}
	
			m_pdRs.Close();
		}
		if(m_pdRs.Open("Metro", CADORecordset::openTable))
		{
			for(UINT i=1; i<=m_pdRs.GetRecordCount(); i++)
			{
				m_pdRs.SetAbsolutePosition(i);
				CString s;
				m_pdRs.GetFieldValue("METRO", s);
				m_pFFS->m_metro.AddString(s);
			}
	
			m_pdRs.Close();
		}
		if(m_pdRs.Open("District", CADORecordset::openTable))
		{
			for(UINT i=1; i<=m_pdRs.GetRecordCount(); i++)
			{
				m_pdRs.SetAbsolutePosition(i);
				CString s;
				m_pdRs.GetFieldValue("DISTRICT", s);
				m_pFFS->m_district.AddString(s);
			}
	
			m_pdRs.Close();
		}
	}
	else if(mode==RFS)
	{
		m_pRFS->cur=cur;

		//Load agents data
		if(m_pdRs.Open("Agents", CADORecordset::openTable))
		{
			for(UINT i=1; i<=m_pdRs.GetRecordCount(); i++)
			{
				m_pdRs.SetAbsolutePosition(i);
				CString s;
				m_pdRs.GetFieldValue("AGENT", s);
				m_pRFS->m_agent.AddString(s);
			}
		
			m_pdRs.Close();
		}
		if(m_pdRs.Open("Phones", CADORecordset::openTable))
		{
			for(UINT i=1; i<=m_pdRs.GetRecordCount(); i++)
			{
				m_pdRs.SetAbsolutePosition(i);
				CString s;
				m_pdRs.GetFieldValue("PHONE", s);
				m_pRFS->m_aphone.AddString(s);
			}
		
			m_pdRs.Close();
		}
		if(m_pdRs.Open("Bathroom", CADORecordset::openTable))
		{
			for(UINT i=1; i<=m_pdRs.GetRecordCount(); i++)
			{
				m_pdRs.SetAbsolutePosition(i);
				CString s;
				m_pdRs.GetFieldValue("WC", s);
				m_pRFS->m_wc.AddString(s);
			}
	
			m_pdRs.Close();
		}
		if(m_pdRs.Open("Htype", CADORecordset::openTable))
		{
			for(UINT i=1; i<=m_pdRs.GetRecordCount(); i++)
			{
				m_pdRs.SetAbsolutePosition(i);
				CString s;
				m_pdRs.GetFieldValue("HTYPE", s);
				m_pRFS->m_htype.AddString(s);
			}
	
			m_pdRs.Close();
		}
		if(m_pdRs.Open("Metro", CADORecordset::openTable))
		{
			for(UINT i=1; i<=m_pdRs.GetRecordCount(); i++)
			{
				m_pdRs.SetAbsolutePosition(i);
				CString s;
				m_pdRs.GetFieldValue("METRO", s);
				m_pRFS->m_metro.AddString(s);
			}
	
			m_pdRs.Close();
		}
		if(m_pdRs.Open("District", CADORecordset::openTable))
		{
			for(UINT i=1; i<=m_pdRs.GetRecordCount(); i++)
			{
				m_pdRs.SetAbsolutePosition(i);
				CString s;
				m_pdRs.GetFieldValue("DISTRICT", s);
				m_pRFS->m_district.AddString(s);
			}
	
			m_pdRs.Close();
		}
	}
	else if((mode==CFS) || (mode==CFR))
	{
		m_pCFS->cur=cur;
		m_pCFS->m_COid=-1;
		m_pCFS->gfxMode=gfxMode;

		if(gfxMode=="CFS")
		{
			m_pCFS->m_forwhat.AddString("объект");
			m_pCFS->m_forwhat.AddString("метр кв.");
			m_pCFS->m_forwhat.AddString("договорная");
		}
		else if(gfxMode=="CFR")
			m_pCFS->m_forwhat.AddString("мес.");

		//Load agents data
		if(m_pdRs.Open("Agents", CADORecordset::openTable))
		{
			for(UINT i=1; i<=m_pdRs.GetRecordCount(); i++)
			{
				m_pdRs.SetAbsolutePosition(i);
				CString s;
				m_pdRs.GetFieldValue("AGENT", s);
				m_pCFS->m_agent.AddString(s);
			}
		
			m_pdRs.Close();
		}
		if(m_pdRs.Open("Phones", CADORecordset::openTable))
		{
			for(UINT i=1; i<=m_pdRs.GetRecordCount(); i++)
			{
				m_pdRs.SetAbsolutePosition(i);
				CString s;
				m_pdRs.GetFieldValue("PHONE", s);
				m_pCFS->m_aphone.AddString(s);
			}
		
			m_pdRs.Close();
		}
		if(m_pdRs.Open("District", CADORecordset::openTable))
		{
			for(UINT i=1; i<=m_pdRs.GetRecordCount(); i++)
			{
				m_pdRs.SetAbsolutePosition(i);
				CString s;
				m_pdRs.GetFieldValue("DISTRICT", s);
				m_pCFS->m_district.AddString(s);
			}
		
			m_pdRs.Close();
		}
		if(m_pdRs.Open("Condition", CADORecordset::openTable))
		{
			for(UINT i=1; i<=m_pdRs.GetRecordCount(); i++)
			{
				m_pdRs.SetAbsolutePosition(i);
				CString s;
				m_pdRs.GetFieldValue("CONDITION", s);
				m_pCFS->m_condition.AddString(s);
			}
	
			m_pdRs.Close();
		}
		if(m_pdRs.Open("Appointment", CADORecordset::openTable))
		{
			for(UINT i=1; i<=m_pdRs.GetRecordCount(); i++)
			{
				m_pdRs.SetAbsolutePosition(i);
				CString s;
				m_pdRs.GetFieldValue("APPOINTMENT", s);
				m_pCFS->m_appointment.AddString(s);
			}
	
			m_pdRs.Close();
		}
		if(m_pdRs.Open("Doorway", CADORecordset::openTable))
		{
			for(UINT i=1; i<=m_pdRs.GetRecordCount(); i++)
			{
				m_pdRs.SetAbsolutePosition(i);
				CString s;
				m_pdRs.GetFieldValue("DOORWAY", s);
				m_pCFS->m_doorway.AddString(s);
			}
	
			m_pdRs.Close();
		}
		if(m_pdRs.Open("Entrance", CADORecordset::openTable))
		{
			for(UINT i=1; i<=m_pdRs.GetRecordCount(); i++)
			{
				m_pdRs.SetAbsolutePosition(i);
				CString s;
				m_pdRs.GetFieldValue("ENTRANCE", s);
				m_pCFS->m_entrance.AddString(s);
			}
	
			m_pdRs.Close();
		}
		if(m_pdRs.Open("ComObjects", CADORecordset::openTable))
		{
			for(UINT i=1; i<=m_pdRs.GetRecordCount(); i++)
			{
				m_pdRs.SetAbsolutePosition(i);
				CString s;
				m_pdRs.GetFieldValue("OBJECT", s);
				m_pCFS->m_obj_type.AddString(s);
			}
	
			m_pdRs.Close();
		}
	}
	
//	m_pRs.Open("FlatsInBH_FS", CADORecordset::openTable);

	if(cur==TRUE)
	{
		m_pRs.SetAbsolutePosition(m_pGridCtrl.GetFocusCell().row);
		
		if(mode==FinBH)
		{
			CString s;
			m_pRs.GetFieldValue("AGENT", s);
			m_pFIBH->m_agent.SelectString(-1, s);
			m_pRs.GetFieldValue("DISTRICT", s);
			m_pFIBH->m_district.SelectString(-1, s);
			m_pRs.GetFieldValue("METRO", s);
			m_pFIBH->m_metro.SelectString(-1, s);
			m_pRs.GetFieldValue("IN_WHAT", s);
			m_pFIBH->m_inwhat.SelectString(-1, s);
			m_pRs.GetFieldValue("H_TYPE", s);
			m_pFIBH->m_htype.SelectString(-1, s);
			m_pRs.GetFieldValue("WC", s);
			m_pFIBH->m_wc.SelectString(-1, s);
			m_pRs.GetFieldValue("P_TYPE", s);
			m_pFIBH->m_forwhat.SelectString(-1, s);
			m_pRs.GetFieldValue("AGENT", s);
			m_pFIBH->m_agent.SelectString(-1, s);
			m_pRs.GetFieldValue("A_PHONE", s);
			m_pFIBH->m_aphone.SelectString(-1, s);

			m_pRs.GetFieldValue("ROOMS", s);
			m_pFIBH->m_rooms.SetWindowText(s);
			m_pRs.GetFieldValue("ADDRESS", s);
			m_pFIBH->m_address.SetWindowText(s);
			m_pRs.GetFieldValue("FLOOR", s);
			m_pFIBH->m_floor.SetWindowText(s);
			m_pRs.GetFieldValue("FLOORS", s);
			m_pFIBH->m_floors.SetWindowText(s);
			m_pRs.GetFieldValue("DISTANCE", s);
			m_pFIBH->m_distance.SetWindowText(s);
			m_pRs.GetFieldValue("PRICE", s);
			m_pFIBH->m_costfrom.SetWindowText(s);
			m_pRs.GetFieldValue("B_END", s);
			m_pFIBH->m_buildingend.SetWindowText(s);
			m_pRs.GetFieldValue("DESCRIPTION", s);
			m_pFIBH->m_description.SetWindowText(s);
			double id=0;
			m_pRs.GetFieldValue("S_GENERAL", id);
			m_pFIBH->m_sgeneral.Init(id);
			m_pRs.GetFieldValue("S_KITCHEN", id);
			m_pFIBH->m_skitchen.Init(id);
			m_pRs.GetFieldValue("S_R1", id);
			m_pFIBH->m_r1.Init(id);
			m_pRs.GetFieldValue("S_R2", id);
			if(id>0)
			{
				m_pFIBH->m_r2.Init(id);
			}
			m_pRs.GetFieldValue("S_R3", id);
			if(id>0)
			{
				m_pFIBH->m_r3.Init(id);
			}
			m_pRs.GetFieldValue("S_R4", id);
			if(id>0)
			{
				m_pFIBH->m_r4.Init(id);
			}
			m_pRs.GetFieldValue("S_R5", id);
			if(id>0)
			{
				m_pFIBH->m_r5.Init(id);
			}
			m_pRs.GetFieldValue("S_R6", id);
			if(id>0)
			{
				m_pFIBH->m_r6.Init(id);
			}
			m_pRs.GetFieldValue("S_R7", id);
			if(id>0)
			{
				m_pFIBH->m_r7.Init(id);
			}
		}
		else if(mode==FFS)
		{
			CString s;
			m_pRs.GetFieldValue("AGENT", s);
			m_pFFS->m_agent.SelectString(-1, s);
			m_pRs.GetFieldValue("DISTRICT", s);
			m_pFFS->m_district.SelectString(-1, s);
			m_pRs.GetFieldValue("METRO", s);
			m_pFFS->m_metro.SelectString(-1, s);
			m_pRs.GetFieldValue("IN_WHAT", s);
			m_pFFS->m_inwhat.SelectString(-1, s);
			m_pRs.GetFieldValue("H_TYPE", s);
			m_pFFS->m_htype.SelectString(-1, s);
			m_pRs.GetFieldValue("WC", s);
			m_pFFS->m_wc.SelectString(-1, s);
			m_pRs.GetFieldValue("P_TYPE", s);
			m_pFFS->m_forwhat.SelectString(-1, s);
			m_pRs.GetFieldValue("AGENT", s);
			m_pFFS->m_agent.SelectString(-1, s);
			m_pRs.GetFieldValue("A_PHONE", s);
			m_pFFS->m_aphone.SelectString(-1, s);

			m_pRs.GetFieldValue("ROOMS", s);
			m_pFFS->m_rooms.SetWindowText(s);
			m_pRs.GetFieldValue("ADDRESS", s);
			m_pFFS->m_address.SetWindowText(s);
			m_pRs.GetFieldValue("FLOOR", s);
			m_pFFS->m_floor.SetWindowText(s);
			m_pRs.GetFieldValue("FLOORS", s);
			m_pFFS->m_floors.SetWindowText(s);
			m_pRs.GetFieldValue("DISTANCE", s);
			m_pFFS->m_distance.SetWindowText(s);
			m_pRs.GetFieldValue("PRICE", s);
			m_pFFS->m_costfrom.SetWindowText(s);
			m_pRs.GetFieldValue("DESCRIPTION", s);
			m_pFFS->m_description.SetWindowText(s);
			double id=0;
			m_pRs.GetFieldValue("S_GENERAL", id);
			m_pFFS->m_sgeneral.Init(id);
			m_pRs.GetFieldValue("S_KITCHEN", id);
			m_pFFS->m_skitchen.Init(id);
			m_pRs.GetFieldValue("S_R1", id);
			m_pFFS->m_r1.Init(id);
			m_pRs.GetFieldValue("S_R2", id);
			if(id>0)
			{
				m_pFFS->m_r2.Init(id);
			}
			m_pRs.GetFieldValue("S_R3", id);
			if(id>0)
			{
				m_pFFS->m_r3.Init(id);
			}
			m_pRs.GetFieldValue("S_R4", id);
			if(id>0)
			{
				m_pFFS->m_r4.Init(id);
			}
			m_pRs.GetFieldValue("S_R5", id);
			if(id>0)
			{
				m_pFFS->m_r5.Init(id);
			}
			m_pRs.GetFieldValue("S_R6", id);
			if(id>0)
			{
				m_pFFS->m_r6.Init(id);
			}
			m_pRs.GetFieldValue("S_R7", id);
			if(id>0)
			{
				m_pFFS->m_r7.Init(id);
			}
			m_pRs.GetFieldValue("PHONE", s);
			if(s=="+")
				m_pFFS->m_phone.SelectString(-1, "Есть");
			else if(s=="-")
				m_pFFS->m_phone.SelectString(-1, "Нет");
		}
		else if(mode==RFS)
		{
			CString s;
			m_pRs.GetFieldValue("AGENT", s);
			m_pRFS->m_agent.SelectString(-1, s);
			m_pRs.GetFieldValue("DISTRICT", s);
			m_pRFS->m_district.SelectString(-1, s);
			m_pRs.GetFieldValue("METRO", s);
			m_pRFS->m_metro.SelectString(-1, s);
			m_pRs.GetFieldValue("IN_WHAT", s);
			m_pRFS->m_inwhat.SelectString(-1, s);
			m_pRs.GetFieldValue("H_TYPE", s);
			m_pRFS->m_htype.SelectString(-1, s);
			m_pRs.GetFieldValue("WC", s);
			m_pRFS->m_wc.SelectString(-1, s);
			m_pRs.GetFieldValue("P_TYPE", s);
			m_pRFS->m_forwhat.SelectString(-1, s);
			m_pRs.GetFieldValue("AGENT", s);
			m_pRFS->m_agent.SelectString(-1, s);
			m_pRs.GetFieldValue("A_PHONE", s);
			m_pRFS->m_aphone.SelectString(-1, s);

			m_pRs.GetFieldValue("ROOMS", s);
			m_pRFS->m_rooms.SetWindowText(s);
			m_pRs.GetFieldValue("W_ROOMS", s);
			m_pRFS->m_wrooms.SetWindowText(s);
			m_pRs.GetFieldValue("RENTERS", s);
			m_pRFS->m_renters.SetWindowText(s);
			m_pRs.GetFieldValue("NEIGHBOURS", s);
			m_pRFS->m_neighbours.SetWindowText(s);
			m_pRs.GetFieldValue("ADDRESS", s);
			m_pRFS->m_address.SetWindowText(s);
			m_pRs.GetFieldValue("FLOOR", s);
			m_pRFS->m_floor.SetWindowText(s);
			m_pRs.GetFieldValue("FLOORS", s);
			m_pRFS->m_floors.SetWindowText(s);
			m_pRs.GetFieldValue("DISTANCE", s);
			m_pRFS->m_distance.SetWindowText(s);
			m_pRs.GetFieldValue("PRICE", s);
			m_pRFS->m_costfrom.SetWindowText(s);
			m_pRs.GetFieldValue("DESCRIPTION", s);
			m_pRFS->m_description.SetWindowText(s);
			double id=0;
			m_pRs.GetFieldValue("S_KITCHEN", id);
			m_pRFS->m_skitchen.Init(id);
			m_pRs.GetFieldValue("S_R1", id);
			m_pRFS->m_r1.Init(id);
			m_pRs.GetFieldValue("S_R2", id);
			if(id>0)
			{
				m_pRFS->m_r2.Init(id);
			}
			m_pRs.GetFieldValue("S_R3", id);
			if(id>0)
			{
				m_pRFS->m_r3.Init(id);
			}
			m_pRs.GetFieldValue("S_R4", id);
			if(id>0)
			{
				m_pRFS->m_r4.Init(id);
			}
			m_pRs.GetFieldValue("S_R5", id);
			if(id>0)
			{
				m_pRFS->m_r5.Init(id);
			}
			m_pRs.GetFieldValue("S_R6", id);
			if(id>0)
			{
				m_pRFS->m_r6.Init(id);
			}
			m_pRs.GetFieldValue("S_R7", id);
			if(id>0)
			{
				m_pRFS->m_r7.Init(id);
			}
			m_pRs.GetFieldValue("PHONE", s);
			if(s=="+")
				m_pRFS->m_phone.SelectString(-1, "Есть");
			else if(s=="-")
				m_pRFS->m_phone.SelectString(-1, "Нет");
		}
		else if((mode==CFS) || (mode==CFR))
		{
			CString s;
			m_pRs.GetFieldValue("AGENT", s);
			m_pCFS->m_agent.SelectString(-1, s);
			m_pRs.GetFieldValue("DISTRICT", s);
			m_pCFS->m_district.SelectString(-1, s);
			m_pRs.GetFieldValue("OBJECT_TYPE", s);
			m_pCFS->m_obj_type.SelectString(-1, s);
			m_pCFS->DisableCtrls();
			m_pRs.GetFieldValue("CONDITION", s);
			m_pCFS->m_condition.SelectString(-1, s);
			m_pRs.GetFieldValue("APPOINTMENT", s);
			m_pCFS->m_appointment.SelectString(-1, s);
			m_pRs.GetFieldValue("DOORWAY", s);
			m_pCFS->m_doorway.SelectString(-1, s);
			m_pRs.GetFieldValue("ENTRANCE", s);
			m_pCFS->m_entrance.SelectString(-1, s);
			m_pRs.GetFieldValue("P_TYPE", s);
			m_pCFS->m_forwhat.SelectString(-1, s);
			m_pRs.GetFieldValue("AGENT", s);
			m_pCFS->m_agent.SelectString(-1, s);
			m_pRs.GetFieldValue("A_PHONE", s);
			m_pCFS->m_aphone.SelectString(-1, s);

			m_pRs.GetFieldValue("ADDRESS", s);
			m_pCFS->m_address.SetWindowText(s);
			m_pRs.GetFieldValue("FLOOR", s);
			m_pCFS->m_floor.SetWindowText(s);
			m_pRs.GetFieldValue("FLOORS", s);
			m_pCFS->m_floors.SetWindowText(s);
			m_pRs.GetFieldValue("PRICE", s);
			m_pCFS->m_costfrom.SetWindowText(s);
			m_pRs.GetFieldValue("DESCRIPTION", s);
			m_pCFS->m_description.SetWindowText(s);
			double id=0;
			m_pRs.GetFieldValue("S_GENERAL", id);
			m_pCFS->m_sgeneral.Init(id);
			m_pRs.GetFieldValue("S_PLOT", id);
			m_pCFS->m_splot.Init(id);
			m_pRs.GetFieldValue("CEILING_HEIGHT", id);
			m_pCFS->m_ceilingheight.Init(id);
			m_pRs.GetFieldValue("ELECTRICITY", s);
			if(s=="+")
				m_pCFS->m_electricity.SetCheck(1);
			else if(s=="-")
				m_pCFS->m_electricity.SetCheck(0);
			m_pRs.GetFieldValue("WATER_SUPPLY", s);
			if(s=="+")
				m_pCFS->m_watersupply.SetCheck(1);
			else if(s=="-")
				m_pCFS->m_watersupply.SetCheck(0);
			m_pRs.GetFieldValue("HEATING", s);
			if(s=="+")
				m_pCFS->m_heating.SetCheck(1);
			else if(s=="-")
				m_pCFS->m_heating.SetCheck(0);
			m_pRs.GetFieldValue("SEWERAGE", s);
			if(s=="+")
				m_pCFS->m_sewerage.SetCheck(1);
			else if(s=="-")
				m_pCFS->m_sewerage.SetCheck(0);
			m_pRs.GetFieldValue("PARKING", s);
			if(s=="+")
				m_pCFS->m_parking.SetCheck(1);
			else if(s=="-")
				m_pCFS->m_parking.SetCheck(0);
			m_pRs.GetFieldValue("GUARD_SIGNALLING", s);
			if(s=="+")
				m_pCFS->m_guard_s.SetCheck(1);
			else if(s=="-")
				m_pCFS->m_guard_s.SetCheck(0);
			m_pRs.GetFieldValue("FIRE_SIGNALLING", s);
			if(s=="+")
				m_pCFS->m_fire_s.SetCheck(1);
			else if(s=="-")
				m_pCFS->m_fire_s.SetCheck(0);
			m_pRs.GetFieldValue("PHONE", s);
			if(s=="+")
				m_pCFS->m_phone.SetCheck(1);
			else if(s=="-")
				m_pCFS->m_phone.SetCheck(0);

			m_pRs.GetFieldValue("ID", m_pCFS->m_COid);

			
		}
	}

	if(mode==FinBH)
	{
		m_pFIBH->m_save.EnableWindow(FALSE);
		m_pFIBH->UpdateData(false);
		m_pFIBH->ShowWindow(SW_SHOW);
	}
	else if(mode==FFS)
	{
		m_pFFS->m_save.EnableWindow(FALSE);
		m_pFFS->UpdateData(false);
		m_pFFS->ShowWindow(SW_SHOW);
	}
	else if(mode==RFS)
	{
		m_pRFS->m_save.EnableWindow(FALSE);
		m_pRFS->UpdateData(false);
		m_pRFS->ShowWindow(SW_SHOW);
	}
	else if((mode==CFS) || (mode==CFR))
	{
		m_pCFS->m_save.EnableWindow(FALSE);
		m_pCFS->UpdateData(false);
		m_pCFS->ShowWindow(SW_SHOW);
	}
}


void CInterComView::OnRecordEditCur() 
{
	// TODO: Add your command handler code here
	if((m_pGridCtrl.GetRowCount()>0) && (m_pGridCtrl.GetFocusCell().row >= 0) && (!s_edtable))
	{
		if(mode==FinBH)
		{
			s_edtable=!s_edtable;
			m_pFIBH = new CFlatsInBH(this);
			m_pFIBH->Create();
			InitForm(TRUE);	
		}
		else if(mode==FFS)
		{
			s_edtable=!s_edtable;
			m_pFFS = new CFlatsFS(this);
			m_pFFS->Create();
			InitForm(TRUE);
		}
		else if(mode==RFS)
		{
			s_edtable=!s_edtable;
			m_pRFS = new CRoomsFS(this);
			m_pRFS->Create();
			InitForm(TRUE);
		}
		else if((mode==CFS) || (mode==CFR))
		{
			s_edtable=!s_edtable;
			m_pCFS = new CComFS(this);
			m_pCFS->Create();
			InitForm(TRUE);	
		}
	}		
}

void CInterComView::OnUpdateRecordEditCur(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(!s_edtable);	
}

void CInterComView::OnRecordAdd() 
{
	// TODO: Add your command handler code here
	if(mode==FinBH)
	{
		s_edtable=!s_edtable;
		m_pFIBH = new CFlatsInBH(this);
		m_pFIBH->Create();
		m_pFIBH->m_rooms.SetWindowText("1");
		m_pFIBH->m_delete.EnableWindow(FALSE);
		InitForm();	
	}
	else if(mode==FFS)
	{
		s_edtable=!s_edtable;
		m_pFFS = new CFlatsFS(this);
		m_pFFS->Create();
		m_pFFS->m_rooms.SetWindowText("1");
		m_pFFS->m_delete.EnableWindow(FALSE);
		InitForm();	
	}
	else if(mode==RFS)
	{
		s_edtable=!s_edtable;
		m_pRFS = new CRoomsFS(this);
		m_pRFS->Create();
		m_pRFS->m_rooms.SetWindowText("1");
		m_pRFS->m_delete.EnableWindow(FALSE);
		InitForm();	
	}
	else if((mode==CFS) || (mode==CFR))
	{
		s_edtable=!s_edtable;
		m_pCFS = new CComFS(this);
		m_pCFS->Create();
		m_pCFS->m_delete.EnableWindow(FALSE);
		InitForm();	
	}
}

void CInterComView::OnUpdateRecordAdd(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(!s_edtable);	
	
}

void CInterComView::OnRecordDeleteCur() 
{
	// TODO: Add your command handler code here
	if((m_pGridCtrl.GetRowCount()>0) && (m_pGridCtrl.GetFocusCell().row >= 0) && (!s_edtable))
		DeleteRow();		
}

void CInterComView::OnUpdateRecordDeleteCur(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(!s_edtable);	
	
}

/*void CInterComView::OnSetActiveCell(int nCol, int nRow)
{
	SetSelectRange(1, GetHeadColCount(1), nCol, nCol);
}*/

void CInterComView::GetFromDialog(BOOL cur)
{
	if(cur==FALSE)
	{
		m_pRs.AddNew();
	}
	else
	{
		m_pRs.SetAbsolutePosition(m_pGridCtrl.GetFocusCell().row);
		m_pRs.Edit();
	}

	if(mode==FinBH)
	{
		CString s;
		m_pFIBH->m_agent.GetLBText(m_pFIBH->m_agent.GetCurSel(), s);
		m_pRs.SetFieldValue("AGENT", s);
		m_pFIBH->m_rooms.GetWindowText(s);
		m_pRs.SetFieldValue("ROOMS", s);
		m_pFIBH->m_district.GetLBText(m_pFIBH->m_district.GetCurSel(), s);
		m_pRs.SetFieldValue("DISTRICT", s);
		m_pFIBH->m_address.GetWindowText(s);
		m_pRs.SetFieldValue("ADDRESS", s);
		m_pFIBH->m_floor.GetWindowText(s);
		m_pRs.SetFieldValue("FLOOR", s);
		m_pFIBH->m_floors.GetWindowText(s);
		m_pRs.SetFieldValue("FLOORS", s);
		m_pFIBH->m_sgeneral.GetWindowText(s);
		m_pRs.SetFieldValue("S_GENERAL", s);
		m_pFIBH->m_skitchen.GetWindowText(s);
		m_pRs.SetFieldValue("S_KITCHEN", s);
		m_pFIBH->m_r1.GetWindowText(s);
		m_pRs.SetFieldValue("S_R1", s);
		m_pFIBH->m_r2.GetWindowText(s);
		m_pRs.SetFieldValue("S_R2", s);
		m_pFIBH->m_r3.GetWindowText(s);
		m_pRs.SetFieldValue("S_R3", s);
		m_pFIBH->m_r4.GetWindowText(s);
		m_pRs.SetFieldValue("S_R4", s);
		m_pFIBH->m_r5.GetWindowText(s);
		m_pRs.SetFieldValue("S_R5", s);
		m_pFIBH->m_r6.GetWindowText(s);
		m_pRs.SetFieldValue("S_R6", s);
		m_pFIBH->m_r7.GetWindowText(s);
		m_pRs.SetFieldValue("S_R7", s);
		m_pFIBH->m_r8.GetWindowText(s);
		m_pRs.SetFieldValue("S_R8", s);
		m_pFIBH->m_r9.GetWindowText(s);
		m_pRs.SetFieldValue("S_R9", s);
		m_pFIBH->m_r10.GetWindowText(s);
		m_pRs.SetFieldValue("S_R10", s);
		m_pFIBH->m_r11.GetWindowText(s);
		m_pRs.SetFieldValue("S_R11", s);
		m_pFIBH->m_r12.GetWindowText(s);
		m_pRs.SetFieldValue("S_R12", s);
		m_pFIBH->m_r13.GetWindowText(s);
		m_pRs.SetFieldValue("S_R13", s);
		m_pFIBH->m_r14.GetWindowText(s);
		m_pRs.SetFieldValue("S_R14", s);
		m_pFIBH->m_r15.GetWindowText(s);
		m_pRs.SetFieldValue("S_R15", s);
		m_pFIBH->m_r16.GetWindowText(s);
		m_pRs.SetFieldValue("S_R16", s);
		m_pFIBH->m_r17.GetWindowText(s);
		m_pRs.SetFieldValue("S_R17", s);
		m_pFIBH->m_r18.GetWindowText(s);
		m_pRs.SetFieldValue("S_R18", s);
		m_pFIBH->m_r19.GetWindowText(s);
		m_pRs.SetFieldValue("S_R19", s);
		m_pFIBH->m_r20.GetWindowText(s);
		m_pRs.SetFieldValue("S_R20", s);
		m_pFIBH->m_metro.GetLBText(m_pFIBH->m_metro.GetCurSel(), s);
		m_pRs.SetFieldValue("METRO", s);
		m_pFIBH->m_distance.GetWindowText(s);
		m_pRs.SetFieldValue("DISTANCE", s);
		m_pFIBH->m_inwhat.GetLBText(m_pFIBH->m_inwhat.GetCurSel(), s);
		m_pRs.SetFieldValue("IN_WHAT", s);
		m_pFIBH->m_htype.GetLBText(m_pFIBH->m_htype.GetCurSel(), s);
		m_pRs.SetFieldValue("H_TYPE", s);
		m_pFIBH->m_wc.GetLBText(m_pFIBH->m_wc.GetCurSel(), s);
		m_pRs.SetFieldValue("WC", s);
		m_pFIBH->m_costfrom.GetWindowText(s);
		m_pRs.SetFieldValue("PRICE", s);
		m_pFIBH->m_forwhat.GetLBText(m_pFIBH->m_forwhat.GetCurSel(), s);
		m_pRs.SetFieldValue("P_TYPE", s);
		m_pFIBH->m_buildingend.GetWindowText(s);
		m_pRs.SetFieldValue("B_END", s);
		m_pFIBH->m_description.GetWindowText(s);
		m_pRs.SetFieldValue("DESCRIPTION", s);
		m_pFIBH->m_aphone.GetLBText(m_pFIBH->m_aphone.GetCurSel(), s);
		m_pRs.SetFieldValue("A_PHONE", s);
	}
	else if(mode==FFS)
	{
		CString s;
		m_pFFS->m_agent.GetLBText(m_pFFS->m_agent.GetCurSel(), s);
		m_pRs.SetFieldValue("AGENT", s);
		m_pFFS->m_rooms.GetWindowText(s);
		m_pRs.SetFieldValue("ROOMS", s);
		m_pFFS->m_district.GetLBText(m_pFFS->m_district.GetCurSel(), s);
		m_pRs.SetFieldValue("DISTRICT", s);
		m_pFFS->m_address.GetWindowText(s);
		m_pRs.SetFieldValue("ADDRESS", s);
		m_pFFS->m_floor.GetWindowText(s);
		m_pRs.SetFieldValue("FLOOR", s);
		m_pFFS->m_floors.GetWindowText(s);
		m_pRs.SetFieldValue("FLOORS", s);
		m_pFFS->m_sgeneral.GetWindowText(s);
		m_pRs.SetFieldValue("S_GENERAL", s);
		m_pFFS->m_skitchen.GetWindowText(s);
		m_pRs.SetFieldValue("S_KITCHEN", s);
		m_pFFS->m_r1.GetWindowText(s);
		m_pRs.SetFieldValue("S_R1", s);
		m_pFFS->m_r2.GetWindowText(s);
		m_pRs.SetFieldValue("S_R2", s);
		m_pFFS->m_r3.GetWindowText(s);
		m_pRs.SetFieldValue("S_R3", s);
		m_pFFS->m_r4.GetWindowText(s);
		m_pRs.SetFieldValue("S_R4", s);
		m_pFFS->m_r5.GetWindowText(s);
		m_pRs.SetFieldValue("S_R5", s);
		m_pFFS->m_r6.GetWindowText(s);
		m_pRs.SetFieldValue("S_R6", s);
		m_pFFS->m_r7.GetWindowText(s);
		m_pRs.SetFieldValue("S_R7", s);
		m_pFFS->m_r8.GetWindowText(s);
		m_pRs.SetFieldValue("S_R8", s);
		m_pFFS->m_r9.GetWindowText(s);
		m_pRs.SetFieldValue("S_R9", s);
		m_pFFS->m_r10.GetWindowText(s);
		m_pRs.SetFieldValue("S_R10", s);
		m_pFFS->m_r11.GetWindowText(s);
		m_pRs.SetFieldValue("S_R11", s);
		m_pFFS->m_r12.GetWindowText(s);
		m_pRs.SetFieldValue("S_R12", s);
		m_pFFS->m_r13.GetWindowText(s);
		m_pRs.SetFieldValue("S_R13", s);
		m_pFFS->m_r14.GetWindowText(s);
		m_pRs.SetFieldValue("S_R14", s);
		m_pFFS->m_r15.GetWindowText(s);
		m_pRs.SetFieldValue("S_R15", s);
		m_pFFS->m_r16.GetWindowText(s);
		m_pRs.SetFieldValue("S_R16", s);
		m_pFFS->m_r17.GetWindowText(s);
		m_pRs.SetFieldValue("S_R17", s);
		m_pFFS->m_r18.GetWindowText(s);
		m_pRs.SetFieldValue("S_R18", s);
		m_pFFS->m_r19.GetWindowText(s);
		m_pRs.SetFieldValue("S_R19", s);
		m_pFFS->m_r20.GetWindowText(s);
		m_pRs.SetFieldValue("S_R20", s);
		m_pFFS->m_metro.GetLBText(m_pFFS->m_metro.GetCurSel(), s);
		m_pRs.SetFieldValue("METRO", s);
		m_pFFS->m_distance.GetWindowText(s);
		m_pRs.SetFieldValue("DISTANCE", s);
		m_pFFS->m_inwhat.GetLBText(m_pFFS->m_inwhat.GetCurSel(), s);
		m_pRs.SetFieldValue("IN_WHAT", s);
		m_pFFS->m_htype.GetLBText(m_pFFS->m_htype.GetCurSel(), s);
		m_pRs.SetFieldValue("H_TYPE", s);
		m_pFFS->m_wc.GetLBText(m_pFFS->m_wc.GetCurSel(), s);
		m_pRs.SetFieldValue("WC", s);
		m_pFFS->m_phone.GetLBText(m_pFFS->m_phone.GetCurSel(), s);
		CString r;
		if(s=="Есть")
			r="+";			
		else if(s=="Нет")
			r="-";
		m_pRs.SetFieldValue("PHONE", r);
		m_pFFS->m_costfrom.GetWindowText(s);
		m_pRs.SetFieldValue("PRICE", s);
		m_pFFS->m_forwhat.GetLBText(m_pFFS->m_forwhat.GetCurSel(), s);
		m_pRs.SetFieldValue("P_TYPE", s);
		m_pFFS->m_description.GetWindowText(s);
		m_pRs.SetFieldValue("DESCRIPTION", s);
		m_pFFS->m_aphone.GetLBText(m_pFFS->m_aphone.GetCurSel(), s);
		m_pRs.SetFieldValue("A_PHONE", s);
	}
	else if(mode==RFS)
	{
		CString s;
		m_pRFS->m_agent.GetLBText(m_pRFS->m_agent.GetCurSel(), s);
		m_pRs.SetFieldValue("AGENT", s);
		m_pRFS->m_rooms.GetWindowText(s);
		m_pRs.SetFieldValue("ROOMS", s);
		m_pRFS->m_district.GetLBText(m_pRFS->m_district.GetCurSel(), s);
		m_pRs.SetFieldValue("DISTRICT", s);
		m_pRFS->m_address.GetWindowText(s);
		m_pRs.SetFieldValue("ADDRESS", s);
		m_pRFS->m_floor.GetWindowText(s);
		m_pRs.SetFieldValue("FLOOR", s);
		m_pRFS->m_floors.GetWindowText(s);
		m_pRs.SetFieldValue("FLOORS", s);
		m_pRFS->m_skitchen.GetWindowText(s);
		m_pRs.SetFieldValue("S_KITCHEN", s);
		m_pRFS->m_r1.GetWindowText(s);
		m_pRs.SetFieldValue("S_R1", s);
		m_pRFS->m_r2.GetWindowText(s);
		m_pRs.SetFieldValue("S_R2", s);
		m_pRFS->m_r3.GetWindowText(s);
		m_pRs.SetFieldValue("S_R3", s);
		m_pRFS->m_r4.GetWindowText(s);
		m_pRs.SetFieldValue("S_R4", s);
		m_pRFS->m_r5.GetWindowText(s);
		m_pRs.SetFieldValue("S_R5", s);
		m_pRFS->m_r6.GetWindowText(s);
		m_pRs.SetFieldValue("S_R6", s);
		m_pRFS->m_r7.GetWindowText(s);
		m_pRs.SetFieldValue("S_R7", s);
		m_pRFS->m_r8.GetWindowText(s);
		m_pRs.SetFieldValue("S_R8", s);
		m_pRFS->m_r9.GetWindowText(s);
		m_pRs.SetFieldValue("S_R9", s);
		m_pRFS->m_r10.GetWindowText(s);
		m_pRs.SetFieldValue("S_R10", s);
		m_pRFS->m_r11.GetWindowText(s);
		m_pRs.SetFieldValue("S_R11", s);
		m_pRFS->m_r12.GetWindowText(s);
		m_pRs.SetFieldValue("S_R12", s);
		m_pRFS->m_r13.GetWindowText(s);
		m_pRs.SetFieldValue("S_R13", s);
		m_pRFS->m_r14.GetWindowText(s);
		m_pRs.SetFieldValue("S_R14", s);
		m_pRFS->m_r15.GetWindowText(s);
		m_pRs.SetFieldValue("S_R15", s);
		m_pRFS->m_r16.GetWindowText(s);
		m_pRs.SetFieldValue("S_R16", s);
		m_pRFS->m_r17.GetWindowText(s);
		m_pRs.SetFieldValue("S_R17", s);
		m_pRFS->m_r18.GetWindowText(s);
		m_pRs.SetFieldValue("S_R18", s);
		m_pRFS->m_r19.GetWindowText(s);
		m_pRs.SetFieldValue("S_R19", s);
		m_pRFS->m_r20.GetWindowText(s);
		m_pRs.SetFieldValue("S_R20", s);
		m_pRFS->m_wrooms.GetWindowText(s);
		m_pRs.SetFieldValue("W_ROOMS", s);
		m_pRFS->m_renters.GetWindowText(s);
		m_pRs.SetFieldValue("RENTERS", s);
		m_pRFS->m_neighbours.GetWindowText(s);
		m_pRs.SetFieldValue("NEIGHBOURS", s);
		m_pRFS->m_metro.GetLBText(m_pRFS->m_metro.GetCurSel(), s);
		m_pRs.SetFieldValue("METRO", s);
		m_pRFS->m_distance.GetWindowText(s);
		m_pRs.SetFieldValue("DISTANCE", s);
		m_pRFS->m_inwhat.GetLBText(m_pRFS->m_inwhat.GetCurSel(), s);
		m_pRs.SetFieldValue("IN_WHAT", s);
		m_pRFS->m_htype.GetLBText(m_pRFS->m_htype.GetCurSel(), s);
		m_pRs.SetFieldValue("H_TYPE", s);
		m_pRFS->m_wc.GetLBText(m_pRFS->m_wc.GetCurSel(), s);
		m_pRs.SetFieldValue("WC", s);
		m_pRFS->m_phone.GetLBText(m_pRFS->m_phone.GetCurSel(), s);
		CString r;
		if(s=="Есть")
			r="+";			
		else if(s=="Нет")
			r="-";
		m_pRs.SetFieldValue("PHONE", r);
		m_pRFS->m_costfrom.GetWindowText(s);
		m_pRs.SetFieldValue("PRICE", s);
		m_pRFS->m_forwhat.GetLBText(m_pRFS->m_forwhat.GetCurSel(), s);
		m_pRs.SetFieldValue("P_TYPE", s);
		m_pRFS->m_description.GetWindowText(s);
		m_pRs.SetFieldValue("DESCRIPTION", s);
		m_pRFS->m_aphone.GetLBText(m_pRFS->m_aphone.GetCurSel(), s);
		m_pRs.SetFieldValue("A_PHONE", s);
	}
	else if((mode==CFS) || (mode==CFR))
	{
		CString s;
		m_pCFS->m_agent.GetLBText(m_pCFS->m_agent.GetCurSel(), s);
		m_pRs.SetFieldValue("AGENT", s);
		m_pCFS->m_obj_type.GetLBText(m_pCFS->m_obj_type.GetCurSel(), s);
		m_pRs.SetFieldValue("OBJECT_TYPE", s);
		m_pCFS->m_district.GetLBText(m_pCFS->m_district.GetCurSel(), s);
		m_pRs.SetFieldValue("DISTRICT", s);
		m_pCFS->m_address.GetWindowText(s);
		m_pRs.SetFieldValue("ADDRESS", s);
		m_pCFS->m_floor.GetWindowText(s);
		m_pRs.SetFieldValue("FLOOR", s);
		m_pCFS->m_floors.GetWindowText(s);
		m_pRs.SetFieldValue("FLOORS", s);
		m_pCFS->m_splot.GetWindowText(s);
		m_pRs.SetFieldValue("S_PLOT", s);
		m_pCFS->m_ceilingheight.GetWindowText(s);
		m_pRs.SetFieldValue("CEILING_HEIGHT", s);
		m_pCFS->m_sgeneral.GetWindowText(s);
		m_pRs.SetFieldValue("S_GENERAL", s);
		if(m_pCFS->m_entrance.IsWindowEnabled())
		{
			m_pCFS->m_entrance.GetLBText(m_pCFS->m_entrance.GetCurSel(), s);
			m_pRs.SetFieldValue("ENTRANCE", s);
		}
		if(m_pCFS->m_doorway.IsWindowEnabled())
		{
			m_pCFS->m_doorway.GetLBText(m_pCFS->m_doorway.GetCurSel(), s);
			m_pRs.SetFieldValue("DOORWAY", s);
		}
		if(m_pCFS->m_condition.IsWindowEnabled())
		{
			m_pCFS->m_condition.GetLBText(m_pCFS->m_condition.GetCurSel(), s);
			m_pRs.SetFieldValue("CONDITION", s);
		}
		if(m_pCFS->m_appointment.IsWindowEnabled())
		{
			m_pCFS->m_appointment.GetLBText(m_pCFS->m_appointment.GetCurSel(), s);
			m_pRs.SetFieldValue("APPOINTMENT", s);
		}
		if(m_pCFS->m_phone.GetCheck()==1)
			s="+";
		else if(m_pCFS->m_phone.GetCheck()==0)
			s="-";
		m_pRs.SetFieldValue("PHONE", s);
		if(m_pCFS->m_electricity.GetCheck()==1)
			s="+";			
		else if(m_pCFS->m_electricity.GetCheck()==0)
			s="-";
		m_pRs.SetFieldValue("ELECTRICITY", s);
		if(m_pCFS->m_watersupply.GetCheck()==1)
			s="+";			
		else if(m_pCFS->m_watersupply.GetCheck()==0)
			s="-";
		m_pRs.SetFieldValue("WATER_SUPPLY", s);
		if(m_pCFS->m_heating.GetCheck()==1)
			s="+";			
		else if(m_pCFS->m_heating.GetCheck()==0)
			s="-";
		m_pRs.SetFieldValue("HEATING", s);
		if(m_pCFS->m_sewerage.GetCheck()==1)
			s="+";			
		else if(m_pCFS->m_sewerage.GetCheck()==0)
			s="-";
		m_pRs.SetFieldValue("SEWERAGE", s);
		if(m_pCFS->m_parking.GetCheck()==1)
			s="+";			
		else if(m_pCFS->m_parking.GetCheck()==0)
			s="-";
		m_pRs.SetFieldValue("PARKING", s);
		if(m_pCFS->m_guard_s.GetCheck()==1)
			s="+";			
		else if(m_pCFS->m_guard_s.GetCheck()==0)
			s="-";
		m_pRs.SetFieldValue("GUARD_SIGNALLING", s);
		if(m_pCFS->m_fire_s.GetCheck()==1)
			s="+";			
		else if(m_pCFS->m_fire_s.GetCheck()==0)
			s="-";
		m_pRs.SetFieldValue("FIRE_SIGNALLING", s);
		m_pCFS->m_costfrom.GetWindowText(s);
		m_pRs.SetFieldValue("PRICE", s);
		m_pCFS->m_forwhat.GetLBText(m_pCFS->m_forwhat.GetCurSel(), s);
		m_pRs.SetFieldValue("P_TYPE", s);
		m_pCFS->m_description.GetWindowText(s);
		m_pRs.SetFieldValue("DESCRIPTION", s);
		m_pCFS->m_aphone.GetLBText(m_pCFS->m_aphone.GetCurSel(), s);
		m_pRs.SetFieldValue("A_PHONE", s);
	}

	m_pRs.Update();

	if((mode==CFS) || (mode==CFR))
		m_pRs.GetFieldValue("ID", m_pCFS->m_COid);

	m_pGridCtrl.SetRowCount(m_pRs.GetRecordCount()+1);
	if(cur==FALSE)
	{
		m_pGridCtrl.SetFocusCell(m_pRs.GetAbsolutePosition(), 0);
	}
//	UpdateScrollSizes();
	Invalidate();
}

void CInterComView::OnDestroy() 
{
	CView::OnDestroy();
	
	// TODO: Add your message handler code here
}

void CInterComView::DeleteRow()
{
	int n=m_pRs.GetRecordCount();
	if(n>0)
	{	
		int r=MessageBox("Эти данные будут удалены безвозвратно. Продолжить?", "Предупреждение", MB_YESNO);

		if(r==IDYES)
		{
			m_pRs.SetAbsolutePosition(m_pGridCtrl.GetFocusCell().row);

			if((mode==CFS) || (mode==CFR))
			{
				int i;
				m_pRs.GetFieldValue("ID", i);
				DeleteGfx(i);
			}
		
			m_pRs.Delete();
			m_pRs.Update();

			if(n>=1)
				m_pRs.MovePrevious();
	
			m_pGridCtrl.SetRowCount(m_pRs.GetRecordCount()+1);
			m_pGridCtrl.SetFocusCell(m_pRs.GetAbsolutePosition(), 0);
//			UpdateScrollSizes();
			Invalidate();
		}
	}
}

CString CInterComView::NumToStr(double var)
{
	char num[10];
	gcvt(var, 4, num);
	CString s=num;
	int l=s.GetLength();
	for(int i=0; i<l; ++i)
	{
		if(s.GetAt(i)=='.')
		{
			s.SetAt(i,' ');

			if((i+1 < l) && ((s.GetAt(i+1)=='0') || (s.GetAt(i+1)=='1') || (s.GetAt(i+1)=='2') || (s.GetAt(i+1)=='3') || (s.GetAt(i+1)=='4') || (s.GetAt(i+1)=='5') || (s.GetAt(i+1)=='6') || (s.GetAt(i+1)=='7') || (s.GetAt(i+1)=='8') || (s.GetAt(i+1)=='9')))
				s.SetAt(i,'.');

		}
	}

	return s;
}

void CInterComView::OnFileExportXml() 
{
	// TODO: Add your command handler code here
	CFileDialog dlg(FALSE,_T("xml"),_T("*.xml"),OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,_T("XML File (*.xml)|*.xml|"));

	int r=dlg.DoModal();
	if(r==IDOK)
	{
		m_pRs.SaveAsXML(dlg.GetPathName());
	}
	
}

void CInterComView::OnFileExportInternet() 
{
	// TODO: Add your command handler code here
	pr_mode=mode;
	mode=EI;	
	s_edtable=!s_edtable;
	m_pEI = new CExpInt(this);
	m_pEI->Create();
	m_pEI->ShowWindow(SW_SHOW);

}

void CInterComView::OnListingsFlatsinbhFs() 
{
	// TODO: Add your command handler code here
	mode=FinBH;
	m_pRs.Open("FlatsInBH_FS", CADORecordset::openTable);
/*	RemoveAllCol();
	CString strHeadTitle;
	strHeadTitle.LoadString(ID_ID);
	AddCol(25, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_ID);
	strHeadTitle.LoadString(ID_AGENT);
	AddCol(100, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_AGENT);
	strHeadTitle.LoadString(ID_ROOMS);
	AddCol(25, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_ROOMS);
	strHeadTitle.LoadString(ID_DISTRICT);
	AddCol(100, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_DISTRICT);
	strHeadTitle.LoadString(ID_ADDRESS);
	AddCol(150, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_ADDRESS);
	strHeadTitle.LoadString(ID_FLOORS);
	AddCol(45, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_FLOORS);
	strHeadTitle.LoadString(ID_SGENERAL);
	AddCol(55, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_SGENERAL);
	strHeadTitle.LoadString(ID_SKITCHEN);
	AddCol(45, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_SKITCHEN);
	strHeadTitle.LoadString(ID_SROOMS);
	AddCol(200, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_SROOMS);
	strHeadTitle.LoadString(ID_METRO);
	AddCol(150, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_METRO);
	strHeadTitle.LoadString(ID_HTYPE);
	AddCol(25, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_HTYPE);
	strHeadTitle.LoadString(ID_WC);
	AddCol(25, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_WC);
	strHeadTitle.LoadString(ID_PRICE);
	AddCol(85, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_PRICE);
	strHeadTitle.LoadString(ID_B_END);
	AddCol(65, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_B_END);
	strHeadTitle.LoadString(ID_DESCRIPTION);
	AddCol(170, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_DESCRIPTION);
	strHeadTitle.LoadString(ID_A_PHONE);
	AddCol(60, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_A_PHONE);

	SetGridRowCount(m_pRs.GetRecordCount());
	UpdateScrollSizes();*/
	Invalidate();

	AfxGetMainWnd()->SetWindowText("Dark Unicorn InterCom RE :: Жилая недвижимость - Квартиры в строящихся домах");

}

void CInterComView::OnUpdateListingsFlatsinbhFs(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if((mode!=FinBH) && (!s_edtable))
		pCmdUI->Enable();
	else
		pCmdUI->Enable(FALSE);
	
}

void CInterComView::OnListingsRoomsFs() 
{
	// TODO: Add your command handler code here
	mode=RFS;
	m_pRs.Open("Rooms_FS", CADORecordset::openTable);
/*	RemoveAllCol();
	CString strHeadTitle;
	strHeadTitle.LoadString(ID_ID);
	AddCol(25, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_ID);
	strHeadTitle.LoadString(ID_AGENT);
	AddCol(100, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_AGENT);
	strHeadTitle.LoadString(ID_ROOMS);
	AddCol(25, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_ROOMS);
	strHeadTitle.LoadString(ID_DISTRICT);
	AddCol(100, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_DISTRICT);
	strHeadTitle.LoadString(ID_ADDRESS);
	AddCol(150, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_ADDRESS);
	strHeadTitle.LoadString(ID_FLOORS);
	AddCol(45, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_FLOORS);
	strHeadTitle.LoadString(ID_SKITCHEN);
	AddCol(45, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_SKITCHEN);
	strHeadTitle.LoadString(ID_SROOMS);
	AddCol(200, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_SROOMS);
	strHeadTitle.LoadString(ID_RRN);
	AddCol(45, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_RRN);
	strHeadTitle.LoadString(ID_METRO);
	AddCol(150, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_METRO);
	strHeadTitle.LoadString(ID_HTYPE);
	AddCol(25, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_HTYPE);
	strHeadTitle.LoadString(ID_WC);
	AddCol(25, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_WC);
	strHeadTitle.LoadString(ID_PHONE);
	AddCol(25, strHeadTitle, ACFF_CENTER, AHFF_LEFT,0,0,ID_PHONE);
	strHeadTitle.LoadString(ID_PRICE);
	AddCol(85, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_PRICE);
	strHeadTitle.LoadString(ID_DESCRIPTION);
	AddCol(170, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_DESCRIPTION);
	strHeadTitle.LoadString(ID_A_PHONE);
	AddCol(60, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_A_PHONE);

	SetGridRowCount(m_pRs.GetRecordCount());
	UpdateScrollSizes();*/
	Invalidate();

	AfxGetMainWnd()->SetWindowText("Dark Unicorn InterCom RE :: Жилая недвижимость - Комнаты на продажу");

}

void CInterComView::OnUpdateListingsRoomsFs(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if((mode!=RFS) && (!s_edtable))
		pCmdUI->Enable();
	else
		pCmdUI->Enable(FALSE);	
}

void CInterComView::OnListingsFlatsFs() 
{
	// TODO: Add your command handler code here
	mode=FFS;
	m_pRs.Open("Flats_FS", CADORecordset::openTable);
/*	RemoveAllCol();
	CString strHeadTitle;
	strHeadTitle.LoadString(ID_ID);
	AddCol(25, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_ID);
	strHeadTitle.LoadString(ID_AGENT);
	AddCol(100, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_AGENT);
	strHeadTitle.LoadString(ID_ROOMS);
	AddCol(25, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_ROOMS);
	strHeadTitle.LoadString(ID_DISTRICT);
	AddCol(100, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_DISTRICT);
	strHeadTitle.LoadString(ID_ADDRESS);
	AddCol(150, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_ADDRESS);
	strHeadTitle.LoadString(ID_FLOORS);
	AddCol(45, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_FLOORS);
	strHeadTitle.LoadString(ID_SGENERAL);
	AddCol(55, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_SGENERAL);
	strHeadTitle.LoadString(ID_SKITCHEN);
	AddCol(45, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_SKITCHEN);
	strHeadTitle.LoadString(ID_SROOMS);
	AddCol(200, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_SROOMS);
	strHeadTitle.LoadString(ID_METRO);
	AddCol(150, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_METRO);
	strHeadTitle.LoadString(ID_HTYPE);
	AddCol(25, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_HTYPE);
	strHeadTitle.LoadString(ID_WC);
	AddCol(25, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_WC);
	strHeadTitle.LoadString(ID_PHONE);
	AddCol(25, strHeadTitle, ACFF_CENTER, AHFF_LEFT,0,0,ID_PHONE);
	strHeadTitle.LoadString(ID_PRICE);
	AddCol(85, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_PRICE);
	strHeadTitle.LoadString(ID_DESCRIPTION);
	AddCol(170, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_DESCRIPTION);
	strHeadTitle.LoadString(ID_A_PHONE);
	AddCol(60, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_A_PHONE);

	SetGridRowCount(m_pRs.GetRecordCount());
	UpdateScrollSizes();*/
	Invalidate();

	AfxGetMainWnd()->SetWindowText("Dark Unicorn InterCom RE :: Жилая недвижимость - Квартиры на продажу");
	
}

void CInterComView::OnUpdateListingsFlatsFs(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if((mode!=FFS) && (!s_edtable))
		pCmdUI->Enable();
	else
		pCmdUI->Enable(FALSE);	
	
}

void CInterComView::OnServiceAgents() 
{
	// TODO: Add your command handler code here
	CDictionary dlg;
	dlg.m_mode=1;
	dlg.DoModal();	
}

void CInterComView::OnServiceAphones() 
{
	// TODO: Add your command handler code here
	CDictionary dlg;
	dlg.m_mode=2;
	dlg.DoModal();	
}

void CInterComView::OnServiceSprHtypes() 
{
	// TODO: Add your command handler code here
	CDictionary dlg;
	dlg.m_mode=3;
	dlg.DoModal();	
}

void CInterComView::OnServiceSprWc() 
{
	// TODO: Add your command handler code here
	CDictionary dlg;
	dlg.m_mode=4;
	dlg.DoModal();
}


//////////////////////////////////////////////////////////////////////////////////////////////////
///********************************************************************************************///
///******
///			Экспорт данных в Итетнет														   ///
///******
///********************************************************************************************///
//////////////////////////////////////////////////////////////////////////////////////////////////
void CInterComView::ExportToInternet()
{
	CFtpConnection* m_pFtpConnection;
	CInternetSession m_Session;

	app_w_mode=APP_W_MODE;

	if(app_w_mode==2)
	{
	int pc=0;

	m_pEI->m_progress.SetRange(0, 10+m_pEI->m_lc*35+10);
	m_pEI->m_cancel.EnableWindow(FALSE);
	m_pEI->m_log.AddString("Устанавливаем связь с сервером...");
	m_pEI->UpdateData(false);
	m_pEI->ShowWindow(SW_SHOW);

	if(m_pIDb.Open(strIConnection))
	{
		
		pc+=10;
		m_pEI->m_progress.SetPos(pc);
		m_pEI->m_log.AddString("Связь установлена. Открываем базу данных...");
		m_pEI->UpdateData(false);
		m_pEI->ShowWindow(SW_SHOW);

		m_pIRs = CADORecordset(&m_pIDb);

		//Для квартир в строящихся домах
		if((m_pIRs.Open("du_ps_fibh", CADORecordset::openTable))&&(m_pEI->m_fibh==TRUE))
		{
			pc+=15;
			m_pEI->m_progress.SetPos(pc);
			m_pEI->m_log.AddString("Таблица du_ps_fibh открыта. Очищаем таблицу.");
			m_pEI->UpdateData(false);
			m_pEI->ShowWindow(SW_SHOW);

			
			int count=m_pIRs.GetRecordCount();
			for(UINT i=count; i>0; --i)
			{
				m_pIRs.SetAbsolutePosition(i);
				m_pIRs.Delete();
				m_pIRs.Update();
				count=m_pIRs.GetRecordCount();
			}

			m_pIRs.Update();

			pc+=10;
			m_pEI->m_progress.SetPos(pc);
			m_pEI->m_log.AddString("Таблица du_ps_fibh очищена. Копируем новые данные.");
			m_pEI->UpdateData(false);
			m_pEI->ShowWindow(SW_SHOW);

			m_pdRs.Open("FlatsInBH_FS", CADORecordset::openTable);
			
			for(i=1; i<=m_pdRs.GetRecordCount(); ++i)
			{
				m_pdRs.SetAbsolutePosition(i);
				m_pIRs.AddNew();

				CString s;
				int r;
				double d;

				
				m_pdRs.GetFieldValue("AGENT", s);
				m_pIRs.SetFieldValue("AGENT", s);
				m_pdRs.GetFieldValue("ROOMS", r);
				m_pIRs.SetFieldValue("ROOMS", r);
				m_pdRs.GetFieldValue("DISTRICT", s);
				m_pIRs.SetFieldValue("DISTRICT", s);
				m_pdRs.GetFieldValue("ADDRESS", s);
				m_pIRs.SetFieldValue("ADDRESS", s);
				m_pdRs.GetFieldValue("FLOOR", r);
				m_pIRs.SetFieldValue("FLOOR", r);
				m_pdRs.GetFieldValue("FLOORS", r);
				m_pIRs.SetFieldValue("FLOORS", r);
				m_pdRs.GetFieldValue("S_GENERAL", d);
				m_pIRs.SetFieldValue("S_GENERAL", d);
				m_pdRs.GetFieldValue("S_KITCHEN", d);
				m_pIRs.SetFieldValue("S_KITCHEN", d);
				m_pdRs.GetFieldValue("S_R1", d);
				m_pIRs.SetFieldValue("S_R1", d);
				m_pdRs.GetFieldValue("S_R2", d);
				m_pIRs.SetFieldValue("S_R2", d);
				m_pdRs.GetFieldValue("S_R3", d);
				m_pIRs.SetFieldValue("S_R3", d);
				m_pdRs.GetFieldValue("S_R4", d);
				m_pIRs.SetFieldValue("S_R4", d);
				m_pdRs.GetFieldValue("S_R5", d);
				m_pIRs.SetFieldValue("S_R5", d);
				m_pdRs.GetFieldValue("S_R6", d);
				m_pIRs.SetFieldValue("S_R6", d);
				m_pdRs.GetFieldValue("S_R7", d);
				m_pIRs.SetFieldValue("S_R7", d);
				m_pdRs.GetFieldValue("S_R8", d);
				m_pIRs.SetFieldValue("S_R8", d);
				m_pdRs.GetFieldValue("S_R9", d);
				m_pIRs.SetFieldValue("S_R9", d);
				m_pdRs.GetFieldValue("S_R10", d);
				m_pIRs.SetFieldValue("S_R10", d);
				m_pdRs.GetFieldValue("S_R11", d);
				m_pIRs.SetFieldValue("S_R11", d);
				m_pdRs.GetFieldValue("S_R12", d);
				m_pIRs.SetFieldValue("S_R12", d);
				m_pdRs.GetFieldValue("S_R13", d);
				m_pIRs.SetFieldValue("S_R13", d);
				m_pdRs.GetFieldValue("S_R14", d);
				m_pIRs.SetFieldValue("S_R14", d);
				m_pdRs.GetFieldValue("S_R15", d);
				m_pIRs.SetFieldValue("S_R15", d);
				m_pdRs.GetFieldValue("S_R16", d);
				m_pIRs.SetFieldValue("S_R16", d);
				m_pdRs.GetFieldValue("S_R17", d);
				m_pIRs.SetFieldValue("S_R17", d);
				m_pdRs.GetFieldValue("S_R18", d);
				m_pIRs.SetFieldValue("S_R18", d);
				m_pdRs.GetFieldValue("S_R19", d);
				m_pIRs.SetFieldValue("S_R19", d);
				m_pdRs.GetFieldValue("S_R20", d);
				m_pIRs.SetFieldValue("S_R20", d);
				m_pdRs.GetFieldValue("METRO", s);
				m_pIRs.SetFieldValue("METRO", s);
				m_pdRs.GetFieldValue("DISTANCE", r);
				m_pIRs.SetFieldValue("DISTANCE", r);
				m_pdRs.GetFieldValue("IN_WHAT", s);
				m_pIRs.SetFieldValue("IN_WHAT", s);
				m_pdRs.GetFieldValue("H_TYPE", s);
				m_pIRs.SetFieldValue("H_TYPE", s);
				m_pdRs.GetFieldValue("WC", s);
				m_pIRs.SetFieldValue("WC", s);
				m_pdRs.GetFieldValue("PRICE", r);
				m_pIRs.SetFieldValue("PRICE", r);
				m_pdRs.GetFieldValue("P_TYPE", s);
				m_pIRs.SetFieldValue("P_TYPE", s);
				m_pdRs.GetFieldValue("B_END", s);
				m_pIRs.SetFieldValue("B_END", s);
				m_pdRs.GetFieldValue("DESCRIPTION", s);
				m_pIRs.SetFieldValue("DESCRIPTION", s);
				m_pdRs.GetFieldValue("A_PHONE", s);
				m_pIRs.SetFieldValue("A_PHONE", s);
				m_pdRs.GetFieldValue("ID", r);
				m_pIRs.SetFieldValue("ID", r);

				m_pIRs.Update();
			}

			m_pIRs.Update();

			pc+=10;
			m_pEI->m_progress.SetPos(pc);
			m_pEI->m_log.AddString("Данные успешно добавлены в таблицу du_ps_fibh.");
			m_pEI->UpdateData(false);
			m_pEI->ShowWindow(SW_SHOW);

			m_pIRs.Close();
			m_pdRs.Close();
			
		}
		else if(m_pEI->m_fibh==TRUE)
		{
			m_pEI->m_progress.SetPos(10+m_pEI->m_lc*35);
			m_pEI->m_log.AddString("Не удается открыть таблицу.");
			m_pEI->m_cancel.EnableWindow();
			m_pEI->UpdateData(false);
			m_pEI->ShowWindow(SW_SHOW);
		}
		

		//Для квартир на продажу
		if((m_pIRs.Open("du_ps_ffs", CADORecordset::openTable))&&(m_pEI->m_ffs==TRUE))
		{
			pc+=15;
			m_pEI->m_progress.SetPos(pc);
			m_pEI->m_log.AddString("Таблица du_ps_ffs открыта. Очищаем таблицу.");
			m_pEI->UpdateData(false);
			m_pEI->ShowWindow(SW_SHOW);

			
			int count=m_pIRs.GetRecordCount();
			for(UINT i=count; i>0; --i)
			{
				m_pIRs.SetAbsolutePosition(i);
				m_pIRs.Delete();
				m_pIRs.Update();
				count=m_pIRs.GetRecordCount();
			}

			m_pIRs.Update();

			pc+=10;
			m_pEI->m_progress.SetPos(pc);
			m_pEI->m_log.AddString("Таблица du_ps_ffs очищена. Копируем новые данные.");
			m_pEI->UpdateData(false);
			m_pEI->ShowWindow(SW_SHOW);

			m_pdRs.Open("Flats_FS", CADORecordset::openTable);
			
			for(i=1; i<=m_pdRs.GetRecordCount(); ++i)
			{
				m_pdRs.SetAbsolutePosition(i);
				m_pIRs.AddNew();

				CString s;
				int r;
				double d;

				
				m_pdRs.GetFieldValue("AGENT", s);
				m_pIRs.SetFieldValue("AGENT", s);
				m_pdRs.GetFieldValue("ROOMS", r);
				m_pIRs.SetFieldValue("ROOMS", r);
				m_pdRs.GetFieldValue("DISTRICT", s);
				m_pIRs.SetFieldValue("DISTRICT", s);
				m_pdRs.GetFieldValue("ADDRESS", s);
				m_pIRs.SetFieldValue("ADDRESS", s);
				m_pdRs.GetFieldValue("FLOOR", r);
				m_pIRs.SetFieldValue("FLOOR", r);
				m_pdRs.GetFieldValue("FLOORS", r);
				m_pIRs.SetFieldValue("FLOORS", r);
				m_pdRs.GetFieldValue("S_GENERAL", d);
				m_pIRs.SetFieldValue("S_GENERAL", d);
				m_pdRs.GetFieldValue("S_KITCHEN", d);
				m_pIRs.SetFieldValue("S_KITCHEN", d);
				m_pdRs.GetFieldValue("S_R1", d);
				m_pIRs.SetFieldValue("S_R1", d);
				m_pdRs.GetFieldValue("S_R2", d);
				m_pIRs.SetFieldValue("S_R2", d);
				m_pdRs.GetFieldValue("S_R3", d);
				m_pIRs.SetFieldValue("S_R3", d);
				m_pdRs.GetFieldValue("S_R4", d);
				m_pIRs.SetFieldValue("S_R4", d);
				m_pdRs.GetFieldValue("S_R5", d);
				m_pIRs.SetFieldValue("S_R5", d);
				m_pdRs.GetFieldValue("S_R6", d);
				m_pIRs.SetFieldValue("S_R6", d);
				m_pdRs.GetFieldValue("S_R7", d);
				m_pIRs.SetFieldValue("S_R7", d);
				m_pdRs.GetFieldValue("S_R8", d);
				m_pIRs.SetFieldValue("S_R8", d);
				m_pdRs.GetFieldValue("S_R9", d);
				m_pIRs.SetFieldValue("S_R9", d);
				m_pdRs.GetFieldValue("S_R10", d);
				m_pIRs.SetFieldValue("S_R10", d);
				m_pdRs.GetFieldValue("S_R11", d);
				m_pIRs.SetFieldValue("S_R11", d);
				m_pdRs.GetFieldValue("S_R12", d);
				m_pIRs.SetFieldValue("S_R12", d);
				m_pdRs.GetFieldValue("S_R13", d);
				m_pIRs.SetFieldValue("S_R13", d);
				m_pdRs.GetFieldValue("S_R14", d);
				m_pIRs.SetFieldValue("S_R14", d);
				m_pdRs.GetFieldValue("S_R15", d);
				m_pIRs.SetFieldValue("S_R15", d);
				m_pdRs.GetFieldValue("S_R16", d);
				m_pIRs.SetFieldValue("S_R16", d);
				m_pdRs.GetFieldValue("S_R17", d);
				m_pIRs.SetFieldValue("S_R17", d);
				m_pdRs.GetFieldValue("S_R18", d);
				m_pIRs.SetFieldValue("S_R18", d);
				m_pdRs.GetFieldValue("S_R19", d);
				m_pIRs.SetFieldValue("S_R19", d);
				m_pdRs.GetFieldValue("S_R20", d);
				m_pIRs.SetFieldValue("S_R20", d);
				m_pdRs.GetFieldValue("METRO", s);
				m_pIRs.SetFieldValue("METRO", s);
				m_pdRs.GetFieldValue("DISTANCE", r);
				m_pIRs.SetFieldValue("DISTANCE", r);
				m_pdRs.GetFieldValue("IN_WHAT", s);
				m_pIRs.SetFieldValue("IN_WHAT", s);
				m_pdRs.GetFieldValue("H_TYPE", s);
				m_pIRs.SetFieldValue("H_TYPE", s);
				m_pdRs.GetFieldValue("WC", s);
				m_pIRs.SetFieldValue("WC", s);
				m_pdRs.GetFieldValue("PHONE", s);
				m_pIRs.SetFieldValue("PHONE", s);
				m_pdRs.GetFieldValue("PRICE", r);
				m_pIRs.SetFieldValue("PRICE", r);
				m_pdRs.GetFieldValue("P_TYPE", s);
				m_pIRs.SetFieldValue("P_TYPE", s);
				m_pdRs.GetFieldValue("DESCRIPTION", s);
				m_pIRs.SetFieldValue("DESCRIPTION", s);
				m_pdRs.GetFieldValue("A_PHONE", s);
				m_pIRs.SetFieldValue("A_PHONE", s);
				m_pdRs.GetFieldValue("ID", r);
				m_pIRs.SetFieldValue("ID", r);

				m_pIRs.Update();
			}

			pc+=10;
			m_pEI->m_progress.SetPos(pc);
			m_pEI->m_log.AddString("Данные успешно добавлены в таблицу du_ps_ffs.");
			m_pEI->UpdateData(false);
			m_pEI->ShowWindow(SW_SHOW);

			m_pIRs.Close();
			m_pdRs.Close();
			
		}
		else if(m_pEI->m_ffs==TRUE)
		{
			m_pEI->m_progress.SetPos(10+m_pEI->m_lc*35);
			m_pEI->m_log.AddString("Не удается открыть таблицу.");
			m_pEI->m_cancel.EnableWindow();
			m_pEI->UpdateData(false);
			m_pEI->ShowWindow(SW_SHOW);
		}
		
		//Для комнат на продажу
		if((m_pIRs.Open("du_ps_rfs", CADORecordset::openTable))&&(m_pEI->m_rfs==TRUE))
		{
			pc+=15;
			m_pEI->m_progress.SetPos(pc);
			m_pEI->m_log.AddString("Таблица du_ps_rfs открыта. Очищаем таблицу.");
			m_pEI->UpdateData(false);
			m_pEI->ShowWindow(SW_SHOW);

			
			int count=m_pIRs.GetRecordCount();
			for(UINT i=count; i>0; --i)
			{
				m_pIRs.SetAbsolutePosition(i);
				m_pIRs.Delete();
				m_pIRs.Update();
				count=m_pIRs.GetRecordCount();
			}

			m_pIRs.Update();

			pc+=10;
			m_pEI->m_progress.SetPos(pc);
			m_pEI->m_log.AddString("Таблица du_ps_rfs очищена. Копируем новые данные.");
			m_pEI->UpdateData(false);
			m_pEI->ShowWindow(SW_SHOW);

			m_pdRs.Open("Rooms_FS", CADORecordset::openTable);
			
			for(i=1; i<=m_pdRs.GetRecordCount(); ++i)
			{
				m_pdRs.SetAbsolutePosition(i);
				m_pIRs.AddNew();

				CString s;
				int r;
				double d;

				
				m_pdRs.GetFieldValue("AGENT", s);
				m_pIRs.SetFieldValue("AGENT", s);
				m_pdRs.GetFieldValue("ROOMS", r);
				m_pIRs.SetFieldValue("ROOMS", r);
				m_pdRs.GetFieldValue("DISTRICT", s);
				m_pIRs.SetFieldValue("DISTRICT", s);
				m_pdRs.GetFieldValue("ADDRESS", s);
				m_pIRs.SetFieldValue("ADDRESS", s);
				m_pdRs.GetFieldValue("FLOOR", r);
				m_pIRs.SetFieldValue("FLOOR", r);
				m_pdRs.GetFieldValue("FLOORS", r);
				m_pIRs.SetFieldValue("FLOORS", r);
				m_pdRs.GetFieldValue("S_KITCHEN", d);
				m_pIRs.SetFieldValue("S_KITCHEN", d);
				m_pdRs.GetFieldValue("S_R1", d);
				m_pIRs.SetFieldValue("S_R1", d);
				m_pdRs.GetFieldValue("S_R2", d);
				m_pIRs.SetFieldValue("S_R2", d);
				m_pdRs.GetFieldValue("S_R3", d);
				m_pIRs.SetFieldValue("S_R3", d);
				m_pdRs.GetFieldValue("S_R4", d);
				m_pIRs.SetFieldValue("S_R4", d);
				m_pdRs.GetFieldValue("S_R5", d);
				m_pIRs.SetFieldValue("S_R5", d);
				m_pdRs.GetFieldValue("S_R6", d);
				m_pIRs.SetFieldValue("S_R6", d);
				m_pdRs.GetFieldValue("S_R7", d);
				m_pIRs.SetFieldValue("S_R7", d);
				m_pdRs.GetFieldValue("S_R8", d);
				m_pIRs.SetFieldValue("S_R8", d);
				m_pdRs.GetFieldValue("S_R9", d);
				m_pIRs.SetFieldValue("S_R9", d);
				m_pdRs.GetFieldValue("S_R10", d);
				m_pIRs.SetFieldValue("S_R10", d);
				m_pdRs.GetFieldValue("S_R11", d);
				m_pIRs.SetFieldValue("S_R11", d);
				m_pdRs.GetFieldValue("S_R12", d);
				m_pIRs.SetFieldValue("S_R12", d);
				m_pdRs.GetFieldValue("S_R13", d);
				m_pIRs.SetFieldValue("S_R13", d);
				m_pdRs.GetFieldValue("S_R14", d);
				m_pIRs.SetFieldValue("S_R14", d);
				m_pdRs.GetFieldValue("S_R15", d);
				m_pIRs.SetFieldValue("S_R15", d);
				m_pdRs.GetFieldValue("S_R16", d);
				m_pIRs.SetFieldValue("S_R16", d);
				m_pdRs.GetFieldValue("S_R17", d);
				m_pIRs.SetFieldValue("S_R17", d);
				m_pdRs.GetFieldValue("S_R18", d);
				m_pIRs.SetFieldValue("S_R18", d);
				m_pdRs.GetFieldValue("S_R19", d);
				m_pIRs.SetFieldValue("S_R19", d);
				m_pdRs.GetFieldValue("S_R20", d);
				m_pIRs.SetFieldValue("S_R20", d);
				m_pdRs.GetFieldValue("W_ROOMS", r);
				m_pIRs.SetFieldValue("W_ROOMS", r);
				m_pdRs.GetFieldValue("RENTERS", r);
				m_pIRs.SetFieldValue("RENTERS", r);
				m_pdRs.GetFieldValue("NEIGHBOURS", r);
				m_pIRs.SetFieldValue("NEIGHBOURS", r);
				m_pdRs.GetFieldValue("METRO", s);
				m_pIRs.SetFieldValue("METRO", s);
				m_pdRs.GetFieldValue("DISTANCE", r);
				m_pIRs.SetFieldValue("DISTANCE", r);
				m_pdRs.GetFieldValue("IN_WHAT", s);
				m_pIRs.SetFieldValue("IN_WHAT", s);
				m_pdRs.GetFieldValue("H_TYPE", s);
				m_pIRs.SetFieldValue("H_TYPE", s);
				m_pdRs.GetFieldValue("WC", s);
				m_pIRs.SetFieldValue("WC", s);
				m_pdRs.GetFieldValue("PHONE", s);
				m_pIRs.SetFieldValue("PHONE", s);
				m_pdRs.GetFieldValue("PRICE", r);
				m_pIRs.SetFieldValue("PRICE", r);
				m_pdRs.GetFieldValue("P_TYPE", s);
				m_pIRs.SetFieldValue("P_TYPE", s);
				m_pdRs.GetFieldValue("DESCRIPTION", s);
				m_pIRs.SetFieldValue("DESCRIPTION", s);
				m_pdRs.GetFieldValue("A_PHONE", s);
				m_pIRs.SetFieldValue("A_PHONE", s);
				m_pdRs.GetFieldValue("ID", r);
				m_pIRs.SetFieldValue("ID", r);

				m_pIRs.Update();
			}

			m_pIRs.Update();

			pc+=10;
			m_pEI->m_progress.SetPos(pc);
			m_pEI->m_log.AddString("Данные успешно добавлены в таблицу du_ps_rfs.");
			m_pEI->UpdateData(false);
			m_pEI->ShowWindow(SW_SHOW);

			m_pIRs.Close();
			m_pdRs.Close();
			
		}
		else if(m_pEI->m_ffs==TRUE)
		{
			m_pEI->m_progress.SetPos(10+m_pEI->m_lc*35+10);
			m_pEI->m_log.AddString("Не удается открыть таблицу.");
			m_pEI->m_cancel.EnableWindow();
			m_pEI->UpdateData(false);
			m_pEI->ShowWindow(SW_SHOW);
		}

		pc+=10;
		m_pEI->m_progress.SetPos(pc);
		m_pEI->m_log.AddString("Данные успешно внесены.");
		m_pEI->m_cancel.EnableWindow();
		m_pEI->UpdateData(false);
		m_pEI->ShowWindow(SW_SHOW);

	}
	else
	{
		m_pEI->m_progress.SetPos(10+m_pEI->m_lc*35+10);
		m_pEI->m_log.AddString("Не удается установить соединение с сервером.");
		m_pEI->m_cancel.EnableWindow();
		m_pEI->UpdateData(false);
		m_pEI->ShowWindow(SW_SHOW);
	}
	}
	else if(app_w_mode==1)
	{
		int pc=0;

		m_pEI->m_progress.SetRange(0, 10+m_pEI->m_lc*35+10);
		m_pEI->m_cancel.EnableWindow(FALSE);
		m_pEI->m_log.AddString("Устанавливаем связь с сервером...");
		m_pEI->UpdateData(false);
		m_pEI->ShowWindow(SW_SHOW);

		if(m_pIDb.Open(strIConnection))
		{
		
			pc+=10;
			m_pEI->m_progress.SetPos(pc);
			m_pEI->m_log.AddString("Связь установлена. Открываем базу данных...");
			m_pEI->UpdateData(false);
			m_pEI->ShowWindow(SW_SHOW);

			m_pIRs = CADORecordset(&m_pIDb);

			//Для объектов на продажу
			if((m_pIRs.Open("du_ps_cfs", CADORecordset::openTable))&&(m_pEI->m_ffs==TRUE))
			{
				pc+=15;
				m_pEI->m_progress.SetPos(pc);
				m_pEI->m_log.AddString("Таблица du_ps_cfs открыта. Очищаем таблицу.");
				m_pEI->UpdateData(false);
				m_pEI->ShowWindow(SW_SHOW);
	
				int count=m_pIRs.GetRecordCount();
				for(UINT i=count; i>0; --i)
				{
					m_pIRs.SetAbsolutePosition(i);
					m_pIRs.Delete();
					m_pIRs.Update();
					count=m_pIRs.GetRecordCount();
				}
	
				m_pIRs.Update();
	
				pc+=10;
				m_pEI->m_progress.SetPos(pc);
				m_pEI->m_log.AddString("Таблица du_ps_cfs очищена. Копируем новые данные.");
				m_pEI->UpdateData(false);
				m_pEI->ShowWindow(SW_SHOW);
		
				m_pdRs.Open("ComRE_FS", CADORecordset::openTable);
				
				if(m_pdRs.GetFieldCount()>0)
				{
					m_pdRs.SetAbsolutePosition(1);
					while(!m_pdRs.IsEof())
					{
						m_pIRs.AddNew();
	
						CString s;
						int r;
						double d;

						m_pdRs.GetFieldValue("ID", r);
						m_pIRs.SetFieldValue("ID", r);
						m_pdRs.GetFieldValue("AGENT", s);
						m_pIRs.SetFieldValue("AGENT", s);
						m_pdRs.GetFieldValue("OBJECT_TYPE", s);
						m_pIRs.SetFieldValue("OBJECT_TYPE", s);
						m_pdRs.GetFieldValue("DISTRICT", s);
						m_pIRs.SetFieldValue("DISTRICT", s);
						m_pdRs.GetFieldValue("ADDRESS", s);
						m_pIRs.SetFieldValue("ADDRESS", s);
						m_pdRs.GetFieldValue("FLOOR", r);
						m_pIRs.SetFieldValue("FLOOR", r);
						m_pdRs.GetFieldValue("FLOORS", r);
						m_pIRs.SetFieldValue("FLOORS", r);
						m_pdRs.GetFieldValue("S_PLOT", d);
						m_pIRs.SetFieldValue("S_PLOT", d);
						m_pdRs.GetFieldValue("CEILING_HEIGHT", d);
						m_pIRs.SetFieldValue("CEILING_HEIGHT", d);
						m_pdRs.GetFieldValue("S_GENERAL", d);
						m_pIRs.SetFieldValue("S_GENERAL", d);
						m_pdRs.GetFieldValue("ENTRANCE", s);
						m_pIRs.SetFieldValue("ENTRANCE", s);
						m_pdRs.GetFieldValue("DOORWAY", s);
						m_pIRs.SetFieldValue("DOORWAY", s);
						m_pdRs.GetFieldValue("CONDITION", s);
						m_pIRs.SetFieldValue("CONDITION", s);
						m_pdRs.GetFieldValue("APPOINTMENT", s);
						m_pIRs.SetFieldValue("APPOINTMENT", s);
						m_pdRs.GetFieldValue("PHONE", s);
						m_pIRs.SetFieldValue("PHONE", s);
						m_pdRs.GetFieldValue("ELECTRICITY", s);
						m_pIRs.SetFieldValue("ELECTRICITY", s);
						m_pdRs.GetFieldValue("WATER_SUPPLY", s);
						m_pIRs.SetFieldValue("WATER_SUPPLY", s);
						m_pdRs.GetFieldValue("HEATING", s);
						m_pIRs.SetFieldValue("HEATING", s);
						m_pdRs.GetFieldValue("SEWERAGE", s);
						m_pIRs.SetFieldValue("SEWERAGE", s);
						m_pdRs.GetFieldValue("PARKING", s);
						m_pIRs.SetFieldValue("PARKING", s);
						m_pdRs.GetFieldValue("GUARD_SIGNALLING", s);
						m_pIRs.SetFieldValue("GUARD_SIGNALLING", s);
						m_pdRs.GetFieldValue("FIRE_SIGNALLING", s);
						m_pIRs.SetFieldValue("FIRE_SIGNALLING", s);
						m_pdRs.GetFieldValue("PRICE", r);
						m_pIRs.SetFieldValue("PRICE", r);
						m_pdRs.GetFieldValue("P_TYPE", s);
						m_pIRs.SetFieldValue("P_TYPE", s);
						m_pdRs.GetFieldValue("DESCRIPTION", s);
						m_pIRs.SetFieldValue("DESCRIPTION", s);
						m_pdRs.GetFieldValue("A_PHONE", s);
						m_pIRs.SetFieldValue("A_PHONE", s);
	
						m_pIRs.Update();

						m_pdRs.MoveNext();
					}
				}
				
				m_pIRs.Update();

				pc+=10;
				m_pEI->m_progress.SetPos(pc);
				m_pEI->m_log.AddString("Данные успешно добавлены в таблицу du_ps_cfs.");
				m_pEI->UpdateData(false);
				m_pEI->ShowWindow(SW_SHOW);
	
				m_pIRs.Close();
				m_pdRs.Close();
			}
			else if(m_pEI->m_ffs==TRUE)
			{
				m_pEI->m_progress.SetPos(10+m_pEI->m_lc*35);
				m_pEI->m_log.AddString("Не удается открыть таблицу.");
				m_pEI->m_cancel.EnableWindow();
				m_pEI->UpdateData(false);
				m_pEI->ShowWindow(SW_SHOW);
			}

			//Для объектов в аренду
			if((m_pIRs.Open("du_ps_cfr", CADORecordset::openTable))&&(m_pEI->m_rfs==TRUE))
			{
				pc+=15;
				m_pEI->m_progress.SetPos(pc);
				m_pEI->m_log.AddString("Таблица du_ps_cfr открыта. Очищаем таблицу.");
				m_pEI->UpdateData(false);
				m_pEI->ShowWindow(SW_SHOW);
	
				int count=m_pIRs.GetRecordCount();
				for(UINT i=count; i>0; --i)
				{
					m_pIRs.SetAbsolutePosition(i);
					m_pIRs.Delete();
					m_pIRs.Update();
					count=m_pIRs.GetRecordCount();
				}
	
				m_pIRs.Update();
	
				pc+=10;
				m_pEI->m_progress.SetPos(pc);
				m_pEI->m_log.AddString("Таблица du_ps_cfr очищена. Копируем новые данные.");
				m_pEI->UpdateData(false);
				m_pEI->ShowWindow(SW_SHOW);
		
				m_pdRs.Open("ComRE_FR", CADORecordset::openTable);
				
				if(m_pdRs.GetFieldCount()>0)
				{
					m_pdRs.SetAbsolutePosition(1);
					while(!m_pdRs.IsEof())
					{
						m_pIRs.AddNew();
		
						CString s;
						int r;
						double d;
	
						m_pdRs.GetFieldValue("ID", r);
						m_pIRs.SetFieldValue("ID", r);
						m_pdRs.GetFieldValue("AGENT", s);
						m_pIRs.SetFieldValue("AGENT", s);
						m_pdRs.GetFieldValue("OBJECT_TYPE", s);
						m_pIRs.SetFieldValue("OBJECT_TYPE", s);
						m_pdRs.GetFieldValue("DISTRICT", s);
						m_pIRs.SetFieldValue("DISTRICT", s);
						m_pdRs.GetFieldValue("ADDRESS", s);
						m_pIRs.SetFieldValue("ADDRESS", s);
						m_pdRs.GetFieldValue("FLOOR", r);
						m_pIRs.SetFieldValue("FLOOR", r);
						m_pdRs.GetFieldValue("FLOORS", r);
						m_pIRs.SetFieldValue("FLOORS", r);
						m_pdRs.GetFieldValue("S_PLOT", d);
						m_pIRs.SetFieldValue("S_PLOT", d);
						m_pdRs.GetFieldValue("CEILING_HEIGHT", d);
						m_pIRs.SetFieldValue("CEILING_HEIGHT", d);
						m_pdRs.GetFieldValue("S_GENERAL", d);
						m_pIRs.SetFieldValue("S_GENERAL", d);
						m_pdRs.GetFieldValue("ENTRANCE", s);
						m_pIRs.SetFieldValue("ENTRANCE", s);
						m_pdRs.GetFieldValue("DOORWAY", s);
						m_pIRs.SetFieldValue("DOORWAY", s);
						m_pdRs.GetFieldValue("CONDITION", s);
						m_pIRs.SetFieldValue("CONDITION", s);
						m_pdRs.GetFieldValue("APPOINTMENT", s);
						m_pIRs.SetFieldValue("APPOINTMENT", s);
						m_pdRs.GetFieldValue("PHONE", s);
						m_pIRs.SetFieldValue("PHONE", s);
						m_pdRs.GetFieldValue("ELECTRICITY", s);
						m_pIRs.SetFieldValue("ELECTRICITY", s);
						m_pdRs.GetFieldValue("WATER_SUPPLY", s);
						m_pIRs.SetFieldValue("WATER_SUPPLY", s);
						m_pdRs.GetFieldValue("HEATING", s);
						m_pIRs.SetFieldValue("HEATING", s);
						m_pdRs.GetFieldValue("SEWERAGE", s);
						m_pIRs.SetFieldValue("SEWERAGE", s);
						m_pdRs.GetFieldValue("PARKING", s);
						m_pIRs.SetFieldValue("PARKING", s);
						m_pdRs.GetFieldValue("GUARD_SIGNALLING", s);
						m_pIRs.SetFieldValue("GUARD_SIGNALLING", s);
						m_pdRs.GetFieldValue("FIRE_SIGNALLING", s);
						m_pIRs.SetFieldValue("FIRE_SIGNALLING", s);
						m_pdRs.GetFieldValue("PRICE", r);
						m_pIRs.SetFieldValue("PRICE", r);
						m_pdRs.GetFieldValue("P_TYPE", s);
						m_pIRs.SetFieldValue("P_TYPE", s);
						m_pdRs.GetFieldValue("DESCRIPTION", s);
						m_pIRs.SetFieldValue("DESCRIPTION", s);
						m_pdRs.GetFieldValue("A_PHONE", s);
						m_pIRs.SetFieldValue("A_PHONE", s);
	
						m_pIRs.Update();

						m_pdRs.MoveNext();
					}
				}
				
				m_pIRs.Update();

				pc+=10;
				m_pEI->m_progress.SetPos(pc);
				m_pEI->m_log.AddString("Данные успешно добавлены в таблицу du_ps_cfr.");
				m_pEI->UpdateData(false);
				m_pEI->ShowWindow(SW_SHOW);
	
				m_pIRs.Close();
				m_pdRs.Close();
			}
			else if(m_pEI->m_rfs==TRUE)
			{
				m_pEI->m_progress.SetPos(10+m_pEI->m_lc*35);
				m_pEI->m_log.AddString("Не удается открыть таблицу.");
				m_pEI->m_cancel.EnableWindow();
				m_pEI->UpdateData(false);
				m_pEI->ShowWindow(SW_SHOW);
			}

			//Для изображений
			if((m_pIRs.Open("du_ps_images", CADORecordset::openTable)) && ((m_pEI->m_rfs==TRUE) || (m_pEI->m_ffs==TRUE)))
			{
				pc+=15;
				m_pEI->m_progress.SetPos(pc);
				m_pEI->m_log.AddString("Таблица du_ps_images открыта. Очищаем таблицу.");
				m_pEI->UpdateData(false);
				m_pEI->ShowWindow(SW_SHOW);
	
				int count=m_pIRs.GetRecordCount();
				for(UINT i=count; i>0; --i)
				{
					m_pIRs.SetAbsolutePosition(i);
					m_pIRs.Delete();
					m_pIRs.Update();
					count=m_pIRs.GetRecordCount();
				}
	
				m_pIRs.Update();
	
				pc+=10;
				m_pEI->m_progress.SetPos(pc);
				m_pEI->m_log.AddString("Таблица du_ps_images очищена. Копируем новые данные.");
				m_pEI->UpdateData(false);
				m_pEI->ShowWindow(SW_SHOW);
		
				m_pdRs.Open("Images", CADORecordset::openTable);
				
				if(m_pdRs.GetFieldCount()>0)
				{
					m_pFtpConnection = NULL;
					
					try
					{
						m_pFtpConnection = m_Session.GetFtpConnection("localhost",
							"inata7","123",INTERNET_INVALID_PORT_NUMBER);
					}
					catch(CInternetException *pEx)
					{
						pEx->ReportError(MB_ICONEXCLAMATION);
						m_pFtpConnection = NULL;
						pEx->Delete();
					}

					CString path=GetCommandLine();		// получаем командную строку
					path=path.Mid(1,path.ReverseFind('\\'));

					m_pdRs.SetAbsolutePosition(1);
					while(!m_pdRs.IsEof())
					{
						m_pIRs.AddNew();
		
						CString s;
						int r;
	
						m_pdRs.GetFieldValue("ID", r);
						m_pIRs.SetFieldValue("ID", r);
						m_pdRs.GetFieldValue("PRIORITY", r);
						m_pIRs.SetFieldValue("PRIORITY", r);
						m_pdRs.GetFieldValue("ID_NUM", r);
						m_pIRs.SetFieldValue("ID_NUM", r);
						m_pdRs.GetFieldValue("TYPE", s);
						m_pIRs.SetFieldValue("TYPE", s);
						m_pdRs.GetFieldValue("FNAME", s);
						m_pIRs.SetFieldValue("FNAME", s);

						m_pIRs.Update();

						if(m_pFtpConnection != NULL)
						{
							CFileFind Finder;
							CString strFileName;
							
							if(Finder.FindFile(path+imFolder+s)==TRUE)
							{
								Finder.FindNextFile();
								strFileName = Finder.GetFileName();
								Finder.Close();
							}
							
							BOOL bUploaded = m_pFtpConnection->PutFile(path+imFolder+s,
								strFileName,FTP_TRANSFER_TYPE_BINARY,1);
						}

						m_pdRs.MoveNext();
					}
					
					m_Session.Close();
					m_pFtpConnection->Close();
					
					if(m_pFtpConnection!=NULL)
						delete m_pFtpConnection;

				}

				pc+=10;
				m_pEI->m_progress.SetPos(pc);
				m_pEI->m_log.AddString("Данные успешно добавлены в таблицу du_ps_images.");
				m_pEI->UpdateData(false);
				m_pEI->ShowWindow(SW_SHOW);
	
				m_pIRs.Close();
				m_pdRs.Close();
			}
			else if(m_pEI->m_rfs==TRUE)
			{
				m_pEI->m_progress.SetPos(10+m_pEI->m_lc*35);
				m_pEI->m_log.AddString("Не удается открыть таблицу.");
				m_pEI->m_cancel.EnableWindow();
				m_pEI->UpdateData(false);
				m_pEI->ShowWindow(SW_SHOW);
			}

			pc+=10;
			m_pEI->m_progress.SetPos(pc);
			m_pEI->m_log.AddString("Данные успешно внесены.");
			m_pEI->m_cancel.EnableWindow();
			m_pEI->UpdateData(false);
			m_pEI->ShowWindow(SW_SHOW);
		}
		else
		{
			m_pEI->m_progress.SetPos(10+m_pEI->m_lc*35+10);
			m_pEI->m_log.AddString("Не удается установить соединение с сервером.");
			m_pEI->m_cancel.EnableWindow();
			m_pEI->UpdateData(false);
			m_pEI->ShowWindow(SW_SHOW);
		}
	}
}

void CInterComView::ExportBN()
{
	CStdioFile file;

	////////////////////////////////////////////////////////////////////////////////////
	//Квартиры в строящихся домах

	BOOL opened = file.Open("Press\\BN_кв_в_стр_д.txt", CFile::modeCreate | CFile::modeWrite);
	if (opened)
	{
		m_pdRs.Open("FlatsInBH_FS", CADORecordset::openTable);
		for(UINT i=1; i<=m_pdRs.GetRecordCount(); i++)
		{
			CString out;
			double id;
			m_pdRs.SetAbsolutePosition(i);
			CString s;
			m_pdRs.GetFieldValue("ID", s);
			out+=s;
			out+=";";
			m_pdRs.GetFieldValue("AGENT", s);
			out+=s;
			out+=";";
			m_pdRs.GetFieldValue("ROOMS", s);
			out+=s;
			out+=";";
			m_pdRs.GetFieldValue("DISTRICT", s);
			out+=s;
			out+=";";
			m_pdRs.GetFieldValue("ADDRESS", s);
			out+=s;
			out+=";";
			m_pdRs.GetFieldValue("FLOOR", s);
			out+=s;
			out+=";";
			m_pdRs.GetFieldValue("FLOORS", s);
			out+=s;
			out+=";";
			m_pdRs.GetFieldValue("S_GENERAL", id);
			out+=NumToStr(id);
			out+=";";
			m_pdRs.GetFieldValue("S_KITCHEN", id);
			out+=NumToStr(id);
			out+=";";
			m_pdRs.GetFieldValue("S_R1", id);
			out+=NumToStr(id);
			out+=";";
			m_pdRs.GetFieldValue("S_R2", id);
			out+=NumToStr(id);
			out+=";";
			m_pdRs.GetFieldValue("S_R3", id);
			out+=NumToStr(id);
			out+=";";
			m_pdRs.GetFieldValue("S_R4", id);
			out+=NumToStr(id);
			out+=";";
			m_pdRs.GetFieldValue("S_R5", id);
			out+=NumToStr(id);
			out+=";";
			m_pdRs.GetFieldValue("S_R6", id);
			out+=NumToStr(id);
			out+=";";
			m_pdRs.GetFieldValue("S_R7", id);
			out+=NumToStr(id);
			out+=";";
			m_pdRs.GetFieldValue("S_R8", id);
			out+=NumToStr(id);
			out+=";";
			m_pdRs.GetFieldValue("S_R9", id);
			out+=NumToStr(id);
			out+=";";
			m_pdRs.GetFieldValue("S_R10", id);
			out+=NumToStr(id);
			out+=";";
			m_pdRs.GetFieldValue("S_R11", id);
			out+=NumToStr(id);
			out+=";";
			m_pdRs.GetFieldValue("S_R12", id);
			out+=NumToStr(id);
			out+=";";
			m_pdRs.GetFieldValue("S_R13", id);
			out+=NumToStr(id);
			out+=";";
			m_pdRs.GetFieldValue("S_R14", id);
			out+=NumToStr(id);
			out+=";";
			m_pdRs.GetFieldValue("S_R15", id);
			out+=NumToStr(id);
			out+=";";
			m_pdRs.GetFieldValue("S_R16", id);
			out+=NumToStr(id);
			out+=";";
			m_pdRs.GetFieldValue("S_R17", id);
			out+=NumToStr(id);
			out+=";";
			m_pdRs.GetFieldValue("S_R18", id);
			out+=NumToStr(id);
			out+=";";
			m_pdRs.GetFieldValue("S_R19", id);
			out+=NumToStr(id);
			out+=";";
			m_pdRs.GetFieldValue("S_R20", id);
			out+=NumToStr(id);
			out+=";";
			m_pdRs.GetFieldValue("METRO", s);
			out+=s;
			out+=";";
			m_pdRs.GetFieldValue("DISTANCE", s);
			out+=s;
			out+=";";
			m_pdRs.GetFieldValue("IN_WHAT", s);
			out+=s;
			out+=";";
			m_pdRs.GetFieldValue("H_TYPE", s);
			out+=s;
			out+=";";
			m_pdRs.GetFieldValue("WC", s);
			out+=s;
			out+=";";
			m_pdRs.GetFieldValue("PRICE", s);
			out+=s;
			out+=";";
			m_pdRs.GetFieldValue("P_TYPE", s);
			out+=s;
			out+=";";
			m_pdRs.GetFieldValue("B_END", s);
			out+=s;
			out+=";";
			m_pdRs.GetFieldValue("DESCRIPTION", s);
			out+=s;
			out+=";";
			m_pdRs.GetFieldValue("A_PHONE", s);
			out+=s;
			out+="\n";

			file.WriteString(out);
		}

		file.Close();
	}

	////////////////////////////////////////////////////////////////////////////////////
	//Квартиры на продажу

	opened = file.Open("Press\\BN_кв_на_пр.txt", CFile::modeCreate | CFile::modeWrite);
	if (opened)
	{
		m_pdRs.Open("FlatsInBH_FS", CADORecordset::openTable);
		for(UINT i=1; i<=m_pdRs.GetRecordCount(); i++)
		{
			CString out;
			double id;
			m_pdRs.SetAbsolutePosition(i);
			CString s="продажа;";
			m_pdRs.GetFieldValue("ROOMS", s);
			out+=s;
			out+="ккв;";
			m_pdRs.GetFieldValue("DISTRICT", s);
			out+=s;
			out+=";";
			m_pdRs.GetFieldValue("ADDRESS", s);
			out+=s;
			out+=";";
			m_pdRs.GetFieldValue("FLOOR", s);
			out+=s;
			out+="/";
			m_pdRs.GetFieldValue("FLOORS", s);
			out+=s;
			out+=";";
			m_pdRs.GetFieldValue("S_GENERAL", id);
			out+=NumToStr(id);
			out+=";";
			m_pdRs.GetFieldValue("S_R1", id);
			out+=NumToStr(id);
			m_pdRs.GetFieldValue("S_R2", id);
			if(id>0)
			{
				out+="+";
				out+=NumToStr(id);
			}
			m_pdRs.GetFieldValue("S_R3", id);
			if(id>0)
			{
				out+="+";
				out+=NumToStr(id);
			}
			m_pdRs.GetFieldValue("S_R4", id);
			if(id>0)
			{
				out+="+";
				out+=NumToStr(id);
			}
			m_pdRs.GetFieldValue("S_R5", id);
			if(id>0)
			{
				out+="+";
				out+=NumToStr(id);
			}
			m_pdRs.GetFieldValue("S_R6", id);
			if(id>0)
			{
				out+="+";
				out+=NumToStr(id);
			}
			m_pdRs.GetFieldValue("S_R7", id);
			if(id>0)
			{
				out+="+";
				out+=NumToStr(id);
			}
			m_pdRs.GetFieldValue("S_R8", id);
			if(id>0)
			{
				out+="+";
				out+=NumToStr(id);
			}
			m_pdRs.GetFieldValue("S_R9", id);
			if(id>0)
			{
				out+="+";
				out+=NumToStr(id);
			}
			m_pdRs.GetFieldValue("S_R10", id);
			if(id>0)
			{
				out+="+";
				out+=NumToStr(id);
			}
			m_pdRs.GetFieldValue("S_R11", id);
			if(id>0)
			{
				out+="+";
				out+=NumToStr(id);
			}
			m_pdRs.GetFieldValue("S_R12", id);
			if(id>0)
			{
				out+="+";
				out+=NumToStr(id);
			}
			m_pdRs.GetFieldValue("S_R13", id);
			if(id>0)
			{
				out+="+";
				out+=NumToStr(id);
			}
			m_pdRs.GetFieldValue("S_R14", id);
			if(id>0)
			{
				out+="+";
				out+=NumToStr(id);
			}
			m_pdRs.GetFieldValue("S_R15", id);
			if(id>0)
			{
				out+="+";
				out+=NumToStr(id);
			}
			m_pdRs.GetFieldValue("S_R16", id);
			if(id>0)
			{
				out+="+";
				out+=NumToStr(id);
			}
			m_pdRs.GetFieldValue("S_R17", id);
			if(id>0)
			{
				out+="+";
				out+=NumToStr(id);
			}
			m_pdRs.GetFieldValue("S_R18", id);
			if(id>0)
			{
				out+="+";
				out+=NumToStr(id);
			}
			m_pdRs.GetFieldValue("S_R19", id);
			if(id>0)
			{
				out+="+";
				out+=NumToStr(id);
			}
			m_pdRs.GetFieldValue("S_R20", id);
			if(id>0)
			{
				out+="+";
				out+=NumToStr(id);
			}
			out+=";";
			m_pdRs.GetFieldValue("S_KITCHEN", id);
			out+=NumToStr(id);
			out+=";";
			m_pdRs.GetFieldValue("METRO", s);
			out+=s;
			out+=" ";
			m_pdRs.GetFieldValue("DISTANCE", s);
			out+=s;
			out+=" ";
			m_pdRs.GetFieldValue("IN_WHAT", s);
			out+=s;
			out+=";";
			m_pdRs.GetFieldValue("PHONE", s);
			out+=s;
			out+=";";
			m_pdRs.GetFieldValue("H_TYPE", s);
			out+=s;
			out+=";";
			m_pdRs.GetFieldValue("WC", s);
			out+=s;
			out+=";";
			s+=ag;
			out+=";";
			m_pdRs.GetFieldValue("A_PHONE", s);
			out+=s;
			out+=";";
			m_pdRs.GetFieldValue("PRICE", s);
			out+=s;
			out+=" ";
			m_pdRs.GetFieldValue("P_TYPE", s);
			out+=s;
			out+=";";
			m_pdRs.GetFieldValue("DESCRIPTION", s);
			out+=s;
			out+="\n";

			file.WriteString(out);
		}

		file.Close();
	}
}

void CInterComView::OnServiceSprAppointment() 
{
	// TODO: Add your command handler code here
	CDictionary dlg;
	dlg.m_mode=5;
	dlg.DoModal();
	
}

void CInterComView::OnServiceSprCondition() 
{
	// TODO: Add your command handler code here
	CDictionary dlg;
	dlg.m_mode=4;
	dlg.DoModal();
	
}

void CInterComView::OnServiceSprDoorway() 
{
	// TODO: Add your command handler code here
	CDictionary dlg;
	dlg.m_mode=6;
	dlg.DoModal();
	
}

void CInterComView::OnServiceSprEntrance() 
{
	// TODO: Add your command handler code here
	CDictionary dlg;
	dlg.m_mode=7;
	dlg.DoModal();
	
}

void CInterComView::OnServiceSprObjtypes() 
{
	// TODO: Add your command handler code here
	CDictionary dlg;
	dlg.m_mode=3;
	dlg.DoModal();
	
}

void CInterComView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	// TODO: Add your specialized code here and/or call the base class
//	AfxMessageBox("Update");
}

void CInterComView::OnPrint(CDC* pDC, CPrintInfo* pInfo) 
{
	if (m_pGridCtrl)
		m_pGridCtrl.OnPrint(pDC, pInfo);
}

void CInterComView::PrintHead(CDC* pDC, CPrintInfo* pInfo)
{
/*	CFont* pOldFont = NULL;
	pOldFont = pDC->SelectObject(GetHeadFont());
	int OldBkMode =	pDC->SetBkMode(TRANSPARENT);


	// Выводится каждая строка в области перерисовки.
	for (int nRow = 0, y = PRN_YMARGIN; nRow < GetHeadRowCount(); y += GetHeadRowHeight(), nRow++)
		// Выводится каждый столбец в области перерисовки
		for (int nCol = 0, x = PRN_XMARGIN; nCol < GetHeadColCount(nRow); x = x + GetHeadColWidth(nCol,nRow), nCol++)
			PrintHeadCell(pDC,nCol,nRow,x,y);

	if(pOldFont != NULL)
		pDC->SelectObject(pOldFont);
	pDC->SetBkMode(OldBkMode);*/
}

void CInterComView::PrintGridPage(CDC* pDC, CPrintInfo* pInfo)
{
/*	CFont* pOldFont = NULL;
	pOldFont = pDC->SelectObject(GetGridFont());
	int OldBkMode =	pDC->SetBkMode(TRANSPARENT);
	UINT OldAlign = pDC->GetTextAlign(); 
	pDC->SetTextAlign(TA_LEFT | TA_TOP | TA_NOUPDATECP);

	int y = GetHeadRowCount()*GetHeadRowHeight()+PRN_YMARGIN;

	int nFirstRow = (pInfo->m_nCurPage-1)*nRowInPage;
	int nLastRow = min(GetGridRowCount(),(int)(pInfo->m_nCurPage*nRowInPage));

	// Выводится каждая строка в области перерисовки
	for (int nRow = nFirstRow; nRow < nLastRow; y += GetGridRowHeight(), nRow++)
		// Выводится каждая ячейка в области перерисовки
		for (int nCol = 0, x = PRN_XMARGIN; nCol < GetHeadColCount(); x = x + GetHeadColWidth(nCol), nCol++)
			PrintGridCell(pDC,nCol,nRow,x,y);

	if(pOldFont != NULL)
		pDC->SelectObject(pOldFont);
	pDC->SetBkMode(OldBkMode);
	pDC->SetTextAlign(OldAlign);*/
}

void CInterComView::PrintHeadCell(CDC* pDC, int nCol, int nRow, int x, int y)
{
/*	CRect rectCell(x,y,x+GetHeadColWidth(nCol,nRow)+1,y+GetHeadRowHeight()+1);
	COLORREF clrCellFrame = RGB(0,0,0);

	// выводим рамку
	pDC->Draw3dRect(rectCell,clrCellFrame,clrCellFrame);
	rectCell.DeflateRect(1,1,1,1);

	CBrush brushBackground;
	// закрашиваем ячейку
	if(brushBackground.CreateSolidBrush(::GetSysColor(COLOR_BTNFACE)))
		pDC->FillRect(&rectCell, &brushBackground);
	rectCell.DeflateRect(2,2,1,0);
	// получаем текст и стиль 
	HEADCELL_INFO CellInfo = GetHeadCellInfo(nCol,nRow);
	// выводим текст
	pDC->DrawText(CellInfo.m_strText, rectCell, CellInfo.m_nFormat);*/
}

void CInterComView::PrintGridCell(CDC* pDC, int nCol, int nRow, int x, int y)
{
/*	CELL_INFO CellInfo;
	CELL_DATA CellData;
	CRect rectCell(x,y,x+GetHeadColWidth(nCol)+1,y+GetHeadRowHeight()+1);
	COLORREF clrCellFrame = RGB(0,0,0);

	// выводим рамку
	pDC->Draw3dRect(rectCell,clrCellFrame,clrCellFrame);
	rectCell.DeflateRect(1,1,1,1);

	CBrush brushBackground;
	// закрашиваем ячейку
	if(brushBackground.CreateSolidBrush(::GetSysColor(COLOR_WINDOW)))
		pDC->FillRect(&rectCell, &brushBackground);
	rectCell.DeflateRect(2,2,1,0);

	// Получаем информацию о типе ячейки
	CellInfo = GetCellInfo(nCol,nRow);
	// Получаем информацию о содержании ячейки
	CellData = GetCellData(nCol,nRow);

	// Если ячейка с изображением
	if(IsImage(nCol,nRow))
	{
		CPoint pt;
		CSize sz;

		// Получаем размер изображения
		GetSizeImage(nCol,nRow,sz);
		// Уменьшаем размер изображения, если требуется
		sz.cx = min(rectCell.Width(),sz.cx);
		sz.cy = min(rectCell.Height(),sz.cy);

		pt.x = rectCell.left+1;
		// Смещаем изображение в центр ячейки по оси у
		pt.y = rectCell.top + (rectCell.Height() - sz.cy)/2;

		DrawImage(pDC,nCol,nRow,pt,sz,FALSE);

		// Смещаем левую границу вправо
		rectCell.left = min(rectCell.right,rectCell.left+sz.cx+2);
	}

	rectCell.DeflateRect(1,1,1,1); // Уменьшаем область рисования

	// Если надо рисовать элемент управления
	if(CellInfo.m_nTypeCtrl > 0)
		DrawCellCtrl(pDC,rectCell,CellInfo,CellData);
	else
//		pDC->DrawText((LPCTSTR)CellData.m_strText, rectCell, CellInfo.m_nFormat);
		DrawText(pDC,CellData.m_strText, rectCell, CellInfo.m_nFormat);*/
}

void CInterComView::DrawText(CDC *pDC, CString &str, CRect& rect, UINT nFormat)
{
/*	if(!(nFormat & DT_RIGHT) || pDC->GetTextExtent(str).cx > rect.Width())
	{
		pDC->DrawText(str,rect,nFormat);
		return;
	}

	UINT OldAlign = pDC->GetTextAlign();

	pDC->SetTextAlign(TA_RIGHT | TA_TOP);

	pDC->TextOut(rect.right,rect.top,str);

	pDC->SetTextAlign(OldAlign);*/
}

BOOL CInterComView::GetPrint()
{
	return print;
}

void CInterComView::OnListingsComFs() 
{
	// TODO: Add your command handler code here
	mode=CFS;
	gfxMode="CFS";
//	RemoveAllCol();
	if(m_pRs.Open("ComRE_FS", CADORecordset::openTable))
	{
		TRACE0("Recordset opened\n");

		m_pGridCtrl.DeleteAllItems();

		CString strHeadTitle;
		strHeadTitle.LoadString(ID_ID);
		m_pGridCtrl.InsertColumn(strHeadTitle, 0, -1);
		m_pGridCtrl.SetColumnWidth(0, 25);
		strHeadTitle.LoadString(ID_AGENT);
		m_pGridCtrl.InsertColumn(strHeadTitle, 0, -1);
		m_pGridCtrl.SetColumnWidth(1, 100);
		strHeadTitle.LoadString(ID_OBJ_TYPE);
		m_pGridCtrl.InsertColumn(strHeadTitle, 0, -1);
		m_pGridCtrl.SetColumnWidth(2, 100);
		strHeadTitle.LoadString(ID_DISTRICT);
		m_pGridCtrl.InsertColumn(strHeadTitle, 0, -1);
		m_pGridCtrl.SetColumnWidth(3, 100);
		strHeadTitle.LoadString(ID_ADDRESS);
		m_pGridCtrl.InsertColumn(strHeadTitle, 0, -1);
		m_pGridCtrl.SetColumnWidth(4, 150);
		strHeadTitle.LoadString(ID_FLOORS);
		m_pGridCtrl.InsertColumn(strHeadTitle, 0, -1);
		m_pGridCtrl.SetColumnWidth(5, 45);
		strHeadTitle.LoadString(ID_SGENERAL);
		m_pGridCtrl.InsertColumn(strHeadTitle, 0, -1);
		m_pGridCtrl.SetColumnWidth(6, 55);
		strHeadTitle.LoadString(ID_SPLOT);
		m_pGridCtrl.InsertColumn(strHeadTitle, 0, -1);
		m_pGridCtrl.SetColumnWidth(7, 45);
		strHeadTitle.LoadString(ID_CEILINGHEIGHT);
		m_pGridCtrl.InsertColumn(strHeadTitle, 0, -1);
		m_pGridCtrl.SetColumnWidth(8, 45);
		strHeadTitle.LoadString(ID_ENTRANCE);
		m_pGridCtrl.InsertColumn(strHeadTitle, 0, -1);
		m_pGridCtrl.SetColumnWidth(9, 45);
		strHeadTitle.LoadString(ID_CONDITION);
		m_pGridCtrl.InsertColumn(strHeadTitle, 0, -1);
		m_pGridCtrl.SetColumnWidth(10, 100);
		strHeadTitle.LoadString(ID_ELECTRICITY);
		m_pGridCtrl.InsertColumn(strHeadTitle, 0, -1);
		m_pGridCtrl.SetColumnWidth(11, 25);
		strHeadTitle.LoadString(ID_WATERSUPPLY);
		m_pGridCtrl.InsertColumn(strHeadTitle, 0, -1);
		m_pGridCtrl.SetColumnWidth(12, 25);
		strHeadTitle.LoadString(ID_HEATING);
		m_pGridCtrl.InsertColumn(strHeadTitle, 0, -1);
		m_pGridCtrl.SetColumnWidth(13, 25);
		strHeadTitle.LoadString(ID_SEWERAGE);
		m_pGridCtrl.InsertColumn(strHeadTitle, 0, -1);
		m_pGridCtrl.SetColumnWidth(14, 25);
		strHeadTitle.LoadString(ID_PARKING);
		m_pGridCtrl.InsertColumn(strHeadTitle, 0, -1);
		m_pGridCtrl.SetColumnWidth(15, 25);
		strHeadTitle.LoadString(ID_GUARD_S);
		m_pGridCtrl.InsertColumn(strHeadTitle, 0, -1);
		m_pGridCtrl.SetColumnWidth(16, 25);
		strHeadTitle.LoadString(ID_FIRE_S);
		m_pGridCtrl.InsertColumn(strHeadTitle, 0, -1);
		m_pGridCtrl.SetColumnWidth(17, 25);
		strHeadTitle.LoadString(ID_PHONE);
		m_pGridCtrl.InsertColumn(strHeadTitle, 0, -1);
		m_pGridCtrl.SetColumnWidth(18, 25);
		strHeadTitle.LoadString(ID_DOORWAY);
		m_pGridCtrl.InsertColumn(strHeadTitle, 0, -1);
		m_pGridCtrl.SetColumnWidth(19, 25);
		strHeadTitle.LoadString(ID_APPOINTMENT);
		m_pGridCtrl.InsertColumn(strHeadTitle, 0, -1);
		m_pGridCtrl.SetColumnWidth(20, 100);
		strHeadTitle.LoadString(ID_PRICE);
		m_pGridCtrl.InsertColumn(strHeadTitle, 0, -1);
		m_pGridCtrl.SetColumnWidth(21, 85);
		strHeadTitle.LoadString(ID_DESCRIPTION);
		m_pGridCtrl.InsertColumn(strHeadTitle, 0, -1);
		m_pGridCtrl.SetColumnWidth(22, 170);
		strHeadTitle.LoadString(ID_A_PHONE);
		m_pGridCtrl.InsertColumn(strHeadTitle, 0, -1);
		m_pGridCtrl.SetColumnWidth(23, 60);

		Invalidate();
		AfxGetMainWnd()->SetWindowText("Dark Unicorn InterCom RE :: Коммерческая недвижимость - Продажа");
	}	
}

void CInterComView::OnUpdateListingsComFs(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if((mode!=CFS) && (!s_edtable))
		pCmdUI->Enable();
	else
		pCmdUI->Enable(FALSE);	
	
}

void CInterComView::OnListingsComFr() 
{
	// TODO: Add your command handler code here
	mode=CFR;
	gfxMode="CFR";
//	RemoveAllCol();
	if(m_pRs.Open("ComRE_FR", CADORecordset::openTable))
	{
		TRACE0("Recordset opened\n");

/*		CString strHeadTitle;
		strHeadTitle.LoadString(ID_ID);
		AddCol(25, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_ID);
		strHeadTitle.LoadString(ID_AGENT);
		AddCol(100, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_AGENT);
		strHeadTitle.LoadString(ID_OBJ_TYPE);
		AddCol(100, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_OBJ_TYPE);
		strHeadTitle.LoadString(ID_DISTRICT);
		AddCol(100, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_DISTRICT);
		strHeadTitle.LoadString(ID_ADDRESS);
		AddCol(150, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_ADDRESS);
		strHeadTitle.LoadString(ID_FLOORS);
		AddCol(45, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_FLOORS);
		strHeadTitle.LoadString(ID_SGENERAL);
		AddCol(55, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_SGENERAL);
		strHeadTitle.LoadString(ID_SPLOT);
		AddCol(45, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_SPLOT);
		strHeadTitle.LoadString(ID_CEILINGHEIGHT);
		AddCol(45, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_CEILINGHEIGHT);
		strHeadTitle.LoadString(ID_ENTRANCE);
		AddCol(45, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_ENTRANCE);
		strHeadTitle.LoadString(ID_CONDITION);
		AddCol(100, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_CONDITION);
		strHeadTitle.LoadString(ID_ELECTRICITY);
		AddCol(45, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_ELECTRICITY);
		strHeadTitle.LoadString(ID_WATERSUPPLY);
		AddCol(45, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_WATERSUPPLY);
		strHeadTitle.LoadString(ID_HEATING);
		AddCol(45, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_HEATING);
		strHeadTitle.LoadString(ID_SEWERAGE);
		AddCol(45, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_SEWERAGE);
		strHeadTitle.LoadString(ID_PARKING);
		AddCol(45, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_PARKING);
		strHeadTitle.LoadString(ID_GUARD_S);
		AddCol(45, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_GUARD_S);
		strHeadTitle.LoadString(ID_FIRE_S);
		AddCol(45, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_FIRE_S);
		strHeadTitle.LoadString(ID_PHONE);
		AddCol(45, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_PHONE);
		strHeadTitle.LoadString(ID_DOORWAY);
		AddCol(45, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_DOORWAY);
		strHeadTitle.LoadString(ID_APPOINTMENT);
		AddCol(100, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_APPOINTMENT);
		strHeadTitle.LoadString(ID_PRICE);
		AddCol(85, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_PRICE);
		strHeadTitle.LoadString(ID_DESCRIPTION);
		AddCol(170, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_DESCRIPTION);
		strHeadTitle.LoadString(ID_A_PHONE);
		AddCol(60, strHeadTitle, ACFF_LEFT, AHFF_LEFT,0,0,ID_A_PHONE);

		SetGridRowCount(m_pRs.GetRecordCount());
		UpdateScrollSizes();*/
		Invalidate();
		AfxGetMainWnd()->SetWindowText("Dark Unicorn InterCom RE :: Коммерческая недвижимость - Аренда");
	}
}

void CInterComView::OnUpdateListingsComFr(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if((mode!=CFR) && (!s_edtable))
		pCmdUI->Enable();
	else
		pCmdUI->Enable(FALSE);	
}

void CInterComView::OnRecordDeleteAll() 
{
	// TODO: Add your command handler code here
	if((m_pRs.GetRecordCount()>0) && (!s_edtable))
	{
		int r=MessageBox("Выполнение этой операции приведет к уничтожению всех данных в таблице. Продолжить?", "Предупреждение", MB_YESNO);

		if(r==IDYES)
		{
/*		for(int i=1; i<=m_pRs.GetFieldCount(); ++i)
		{
			m_pRs.SetAbsolutePosition(i);
			m_pRs.Delete();
			m_pRs.Update();

//			SetGridRowCount(m_pRs.GetRecordCount());
//			SetActiveRow(m_pRs.GetAbsolutePosition()-1);
			UpdateScrollSizes();
			Invalidate();
		}*/

			m_pRs.SetAbsolutePosition(1);
			while(!m_pRs.IsEof())
			{
				if((mode==CFS) || (mode==CFR))
				{
					int i;
					m_pRs.GetFieldValue("ID", i);
					DeleteGfx(i);
				}
				m_pRs.Delete();
				m_pRs.Update();
			
				m_pRs.MoveNext();
			}
//			SetGridRowCount(m_pRs.GetRecordCount());
//			SetActiveRow(m_pRs.GetAbsolutePosition()-1);
//			UpdateScrollSizes();
			Invalidate();
		}
	}	
}

void CInterComView::DeleteGfx(int idf)
{
	CString path=GetCommandLine();		// получаем командную строку
	path=path.Mid(1,path.ReverseFind('\\'));

	if(m_pdRs.Open("Images", CADORecordset::openTable))
	{
		if(m_pdRs.GetFieldCount()>0)
		{
			m_pdRs.SetAbsolutePosition(1);
			while(!m_pdRs.IsEof())
			{
				int id=0;
				m_pdRs.GetFieldValue("ID_NUM", id);
				CString s;
				m_pdRs.GetFieldValue("TYPE", s);

				if((id==idf) && (s==gfxMode))
				{
					m_pdRs.GetFieldValue("FNAME", s);
					m_pdRs.Delete();
					DeleteFile(path+imFolder+s);
				}

				m_pdRs.MoveNext();
			}
		}

	m_pdRs.Close();

	}
}

void CInterComView::OnFileExportPress() 
{
	// TODO: Add your command handler code here
	CPressExport dlg;
	dlg.DoModal();
	
}

void CInterComView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	CView::OnLButtonDblClk(nFlags, point);
}


void CInterComView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnLButtonDown(nFlags, point);
}

/*void CInterComView::FillGrid()
{

}*/

BOOL CInterComView::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) 
{
	// TODO: Add your specialized code here and/or call the base class
	NM_GRIDVIEW *gv = (NM_GRIDVIEW*) lParam;
	
	int row = gv->iRow;
	int col = gv->iColumn;
	int code = gv->hdr.code;

	if(code == NM_DBLCLK)
		OnRecordEditCur();
	else if((s_edtable) && (code == GVN_SELCHANGED))
	{
		if(m_pGridCtrl.GetFocusCell().row != -1)
		{
			m_pGridCtrl.SetFocusCell(m_pGridCtrl.GetFocusCell().row, 0);
			m_pGridCtrl.SetSelectedRange(m_pGridCtrl.GetFocusCell().row, 0, m_pGridCtrl.GetFocusCell().row, m_pGridCtrl.GetColumnCount()-1);
			Invalidate();
			InitForm(TRUE);
		}
	}
	
	return CView::OnNotify(wParam, lParam, pResult);
}
