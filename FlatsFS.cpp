// FlatsFS.cpp : implementation file
//

#include "stdafx.h"
#include "InterCom.h"
#include "FlatsFS.h"
#include "Error.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFlatsFS dialog


CFlatsFS::CFlatsFS(CWnd* pParent /*=NULL*/)
	: CDialog(CFlatsFS::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFlatsFS)
	//}}AFX_DATA_INIT
}

CFlatsFS::CFlatsFS(CView* pView)
{
	m_pView = pView;
	m_pDial = this;
	
}


void CFlatsFS::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFlatsFS)
	DDX_Control(pDX, IDC_PHONE_YN, m_phone);
	DDX_Control(pDX, IDCANCEL, m_cancel);
	DDX_Control(pDX, ID_ADD, m_add);
	DDX_Control(pDX, ID_DELETE, m_delete);
	DDX_Control(pDX, ID_PREV, m_prev);
	DDX_Control(pDX, ID_NEXT, m_next);
	DDX_Control(pDX, ID_LAST, m_last);
	DDX_Control(pDX, ID_FIRST, m_first);
	DDX_Control(pDX, ID_SAVE, m_save);
	DDX_Control(pDX, ID_CLEAR, m_clear);
	DDX_Control(pDX, IDC_R9, m_r9);
	DDX_Control(pDX, IDC_R8, m_r8);
	DDX_Control(pDX, IDC_R7, m_r7);
	DDX_Control(pDX, IDC_R6, m_r6);
	DDX_Control(pDX, IDC_R5, m_r5);
	DDX_Control(pDX, IDC_R4, m_r4);
	DDX_Control(pDX, IDC_R3, m_r3);
	DDX_Control(pDX, IDC_R20, m_r20);
	DDX_Control(pDX, IDC_R2, m_r2);
	DDX_Control(pDX, IDC_R19, m_r19);
	DDX_Control(pDX, IDC_R18, m_r18);
	DDX_Control(pDX, IDC_R17, m_r17);
	DDX_Control(pDX, IDC_R16, m_r16);
	DDX_Control(pDX, IDC_R15, m_r15);
	DDX_Control(pDX, IDC_R14, m_r14);
	DDX_Control(pDX, IDC_R13, m_r13);
	DDX_Control(pDX, IDC_R12, m_r12);
	DDX_Control(pDX, IDC_R11, m_r11);
	DDX_Control(pDX, IDC_R10, m_r10);
	DDX_Control(pDX, IDC_R1, m_r1);
	DDX_Control(pDX, IDC_SKITCHEN, m_skitchen);
	DDX_Control(pDX, IDC_SGENERAL, m_sgeneral);
	DDX_Control(pDX, IDC_ROOMS, m_rooms);
	DDX_Control(pDX, IDC_FLOORS, m_floors);
	DDX_Control(pDX, IDC_FLOOR, m_floor);
	DDX_Control(pDX, IDC_DISTANCE, m_distance);
	DDX_Control(pDX, IDC_DESCRIPTION, m_description);
	DDX_Control(pDX, IDC_COSTFROM, m_costfrom);
	DDX_Control(pDX, IDC_ADDRESS, m_address);
	DDX_Control(pDX, IDC_INWHAT, m_inwhat);
	DDX_Control(pDX, IDC_FORWHAT, m_forwhat);
	DDX_Control(pDX, IDC_DISTRICT, m_district);
	DDX_Control(pDX, IDC_WC, m_wc);
	DDX_Control(pDX, IDC_METRO, m_metro);
	DDX_Control(pDX, IDC_HOUSETYPE, m_htype);
	DDX_Control(pDX, IDC_PHONE, m_aphone);
	DDX_Control(pDX, IDC_AGENT, m_agent);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFlatsFS, CDialog)
	//{{AFX_MSG_MAP(CFlatsFS)
	ON_WM_ACTIVATE()
	ON_EN_CHANGE(IDC_ROOMS, OnChangeRooms)
	ON_BN_CLICKED(ID_SAVE, OnSave)
	ON_BN_CLICKED(ID_ADD, OnAdd)
	ON_BN_CLICKED(ID_DELETE, OnDelete)
	ON_BN_CLICKED(ID_LAST, OnLast)
	ON_BN_CLICKED(ID_NEXT, OnNext)
	ON_BN_CLICKED(ID_PREV, OnPrev)
	ON_BN_CLICKED(ID_FIRST, OnFirst)
	ON_CBN_SELCHANGE(IDC_AGENT, OnSelchangeAgent)
	ON_CBN_SELCHANGE(IDC_PHONE, OnSelchangePhone)
	ON_EN_CHANGE(IDC_R1, OnChangeR1)
	ON_EN_CHANGE(IDC_R2, OnChangeR2)
	ON_EN_CHANGE(IDC_R3, OnChangeR3)
	ON_EN_CHANGE(IDC_R4, OnChangeR4)
	ON_EN_CHANGE(IDC_R5, OnChangeR5)
	ON_EN_CHANGE(IDC_R6, OnChangeR6)
	ON_EN_CHANGE(IDC_R7, OnChangeR7)
	ON_EN_CHANGE(IDC_R8, OnChangeR8)
	ON_EN_CHANGE(IDC_R9, OnChangeR9)
	ON_EN_CHANGE(IDC_SGENERAL, OnChangeSgeneral)
	ON_EN_CHANGE(IDC_SKITCHEN, OnChangeSkitchen)
	ON_CBN_SELCHANGE(IDC_WC, OnSelchangeWc)
	ON_EN_CHANGE(IDC_ADDRESS, OnChangeAddress)
	ON_EN_CHANGE(IDC_COSTFROM, OnChangeCostfrom)
	ON_EN_CHANGE(IDC_DESCRIPTION, OnChangeDescription)
	ON_EN_CHANGE(IDC_DISTANCE, OnChangeDistance)
	ON_CBN_SELCHANGE(IDC_DISTRICT, OnSelchangeDistrict)
	ON_EN_CHANGE(IDC_FLOOR, OnChangeFloor)
	ON_EN_CHANGE(IDC_FLOORS, OnChangeFloors)
	ON_CBN_SELCHANGE(IDC_FORWHAT, OnSelchangeForwhat)
	ON_CBN_SELCHANGE(IDC_HOUSETYPE, OnSelchangeHousetype)
	ON_CBN_SELCHANGE(IDC_INWHAT, OnSelchangeInwhat)
	ON_CBN_SELCHANGE(IDC_METRO, OnSelchangeMetro)
	ON_EN_CHANGE(IDC_R10, OnChangeR10)
	ON_EN_CHANGE(IDC_R11, OnChangeR11)
	ON_EN_CHANGE(IDC_R12, OnChangeR12)
	ON_EN_CHANGE(IDC_R13, OnChangeR13)
	ON_EN_CHANGE(IDC_R14, OnChangeR14)
	ON_EN_CHANGE(IDC_R15, OnChangeR15)
	ON_EN_CHANGE(IDC_R16, OnChangeR16)
	ON_EN_CHANGE(IDC_R17, OnChangeR17)
	ON_EN_CHANGE(IDC_R18, OnChangeR18)
	ON_EN_CHANGE(IDC_R19, OnChangeR19)
	ON_EN_CHANGE(IDC_R20, OnChangeR20)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFlatsFS message handlers

BOOL CFlatsFS::Create() 
{
	// TODO: Add your specialized code here and/or call the base class
	return CDialog::Create(CFlatsFS::IDD);
}

void CFlatsFS::OnCancel() 
{
	// TODO: Add extra cleanup here
	m_pView->PostMessage(WM_ENDOFDIAL);
}

void CFlatsFS::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized) 
{
	CDialog::OnActivate(nState, pWndOther, bMinimized);
	
	// TODO: Add your message handler code here
	m_gpMyApp = (CInterComApp*)m_pDial; 
	m_pView->PostMessage(WM_SETPOINTER);
}

BOOL CFlatsFS::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
//	cur=TRUE;

	m_rooms.LimitText(2);
	m_sgeneral.LimitText(7);
	m_skitchen.LimitText(5);
	m_r1.LimitText(5);
	m_r2.LimitText(5);
	m_r3.LimitText(5);
	m_r4.LimitText(5);
	m_r5.LimitText(5);
	m_r6.LimitText(5);
	m_r7.LimitText(5);
	m_r8.LimitText(5);
	m_r9.LimitText(5);
	m_r10.LimitText(5);
	m_r11.LimitText(5);
	m_r12.LimitText(5);
	m_r13.LimitText(5);
	m_r14.LimitText(5);
	m_r15.LimitText(5);
	m_r16.LimitText(5);
	m_r17.LimitText(5);
	m_r18.LimitText(5);
	m_r19.LimitText(5);
	m_r20.LimitText(5);
	m_distance.LimitText(4);
	m_costfrom.LimitText(4);
	m_description.LimitText(31);
	m_address.LimitText(31);
	m_floor.LimitText(2);
	m_floors.LimitText(2);
	m_inwhat.AddString("пеш");
	m_inwhat.AddString("тр");
	m_inwhat.AddString("ост");
	m_forwhat.AddString("объект");
	m_forwhat.AddString("метр кв.");
	m_forwhat.AddString("договорная");
	m_phone.AddString("Есть");
	m_phone.AddString("Нет");

	m_cancel.SetShade(CShadeButtonST::SHS_SOFTBUMP,8,20,5,RGB(55,55,255));
	m_clear.SetShade(CShadeButtonST::SHS_SOFTBUMP,8,20,5,RGB(55,55,255));
	m_save.SetShade(CShadeButtonST::SHS_SOFTBUMP,8,20,5,RGB(55,55,255));
	m_last.SetShade(CShadeButtonST::SHS_SOFTBUMP,8,20,5,RGB(55,55,255));
	m_next.SetShade(CShadeButtonST::SHS_SOFTBUMP,8,20,5,RGB(55,55,255));
	m_prev.SetShade(CShadeButtonST::SHS_SOFTBUMP,8,20,5,RGB(55,55,255));
	m_add.SetShade(CShadeButtonST::SHS_SOFTBUMP,8,20,5,RGB(55,55,255));
	m_delete.SetShade(CShadeButtonST::SHS_SOFTBUMP,8,20,5,RGB(55,55,255));
	m_first.SetShade(CShadeButtonST::SHS_SOFTBUMP,8,20,5,RGB(55,55,255));
	m_first.SetIcon(IDI_FIRST);
	m_first.SetTooltipText("Первая запись");
	m_first.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, 30);
	m_last.SetIcon(IDI_LAST);
	m_last.SetTooltipText("Последняя запись");
	m_last.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, 30);
	m_next.SetIcon(IDI_NEXT);
	m_next.SetTooltipText("Следующая запись");
	m_next.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, 30);
	m_prev.SetIcon(IDI_PREV);
	m_prev.SetTooltipText("Предидущая запись");
	m_prev.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, 30);
	m_add.SetIcon(IDI_ADD);
	m_add.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, 30);
	m_delete.SetIcon(IDI_DEL);
	m_delete.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, 30);
	m_save.SetIcon(IDI_EDIT);
	m_save.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, 30);

	m_sgeneral.Init();
	m_skitchen.Init();
	//	m_cancel.SetIcon(IDI_WEB2);
			
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CFlatsFS::OnChangeRooms() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CString s;
	m_rooms.GetWindowText(s);
	LPSTR p = s.GetBuffer(2);
	int i=atoi(p);
	if(i<=0)
	{
		AfxMessageBox("Количество комнат не может иметь отрицательное значение или быть равным нулю. Проверьте пожалуйста правильность введенной информации.");
		m_rooms.SetWindowText("1");
	}
	else if(i>20)
	{
		AfxMessageBox("Количество комнат не может быть более 20. Проверьте пожалуйста правильность введенной информации.");
		m_rooms.SetWindowText("20");
	}
	else
	{
		m_r1.EnableWindow(false);
		m_r1.SetWindowText("");
		m_r2.EnableWindow(false);
		m_r2.SetWindowText("");
		m_r3.EnableWindow(false);
		m_r3.SetWindowText("");
		m_r4.EnableWindow(false);
		m_r4.SetWindowText("");
		m_r5.EnableWindow(false);
		m_r5.SetWindowText("");
		m_r6.EnableWindow(false);
		m_r6.SetWindowText("");
		m_r7.EnableWindow(false);
		m_r7.SetWindowText("");
		m_r8.EnableWindow(false);
		m_r8.SetWindowText("");
		m_r9.EnableWindow(false);
		m_r9.SetWindowText("");
		m_r10.EnableWindow(false);
		m_r10.SetWindowText("");
		m_r11.EnableWindow(false);
		m_r11.SetWindowText("");
		m_r12.EnableWindow(false);
		m_r12.SetWindowText("");
		m_r13.EnableWindow(false);
		m_r13.SetWindowText("");
		m_r14.EnableWindow(false);
		m_r14.SetWindowText("");
		m_r15.EnableWindow(false);
		m_r15.SetWindowText("");
		m_r16.EnableWindow(false);
		m_r16.SetWindowText("");
		m_r17.EnableWindow(false);
		m_r17.SetWindowText("");
		m_r18.EnableWindow(false);
		m_r18.SetWindowText("");
		m_r19.EnableWindow(false);
		m_r19.SetWindowText("");
		m_r20.EnableWindow(false);
		m_r20.SetWindowText("");

		switch(i)
		{
			case 1:
				{
					m_r1.EnableWindow();
				}
				break;
			case 2:
				{
					m_r1.EnableWindow();
					m_r2.EnableWindow();
				}
				break;
			case 3:
				{
					m_r1.EnableWindow();
					m_r2.EnableWindow();
					m_r3.EnableWindow();
				}
				break;
			case 4:
				{
					m_r1.EnableWindow();
					m_r2.EnableWindow();
					m_r3.EnableWindow();
					m_r4.EnableWindow();
				}
				break;
			case 5:
				{
					m_r1.EnableWindow();
					m_r2.EnableWindow();
					m_r3.EnableWindow();
					m_r4.EnableWindow();
					m_r5.EnableWindow();
				}
				break;
			case 6:
				{
					m_r1.EnableWindow();
					m_r2.EnableWindow();
					m_r3.EnableWindow();
					m_r4.EnableWindow();
					m_r5.EnableWindow();
					m_r6.EnableWindow();
				}
				break;
			case 7:
				{
					m_r1.EnableWindow();
					m_r2.EnableWindow();
					m_r3.EnableWindow();
					m_r4.EnableWindow();
					m_r5.EnableWindow();
					m_r6.EnableWindow();
					m_r7.EnableWindow();
				}
				break;
			case 8:
				{
					m_r1.EnableWindow();
					m_r2.EnableWindow();
					m_r3.EnableWindow();
					m_r4.EnableWindow();
					m_r5.EnableWindow();
					m_r6.EnableWindow();
					m_r7.EnableWindow();
					m_r8.EnableWindow();
				}
				break;
			case 9:
				{
					m_r1.EnableWindow();
					m_r2.EnableWindow();
					m_r3.EnableWindow();
					m_r4.EnableWindow();
					m_r5.EnableWindow();
					m_r6.EnableWindow();
					m_r7.EnableWindow();
					m_r8.EnableWindow();
					m_r9.EnableWindow();
				}
				break;
			case 10:
				{
					m_r1.EnableWindow();
					m_r2.EnableWindow();
					m_r3.EnableWindow();
					m_r4.EnableWindow();
					m_r5.EnableWindow();
					m_r6.EnableWindow();
					m_r7.EnableWindow();
					m_r8.EnableWindow();
					m_r9.EnableWindow();
					m_r10.EnableWindow();
				}
				break;
			case 11:
				{
					m_r1.EnableWindow();
					m_r2.EnableWindow();
					m_r3.EnableWindow();
					m_r4.EnableWindow();
					m_r5.EnableWindow();
					m_r6.EnableWindow();
					m_r7.EnableWindow();
					m_r8.EnableWindow();
					m_r9.EnableWindow();
					m_r10.EnableWindow();
					m_r11.EnableWindow();
				}
				break;
			case 12:
				{
					m_r1.EnableWindow();
					m_r2.EnableWindow();
					m_r3.EnableWindow();
					m_r4.EnableWindow();
					m_r5.EnableWindow();
					m_r6.EnableWindow();
					m_r7.EnableWindow();
					m_r8.EnableWindow();
					m_r9.EnableWindow();
					m_r10.EnableWindow();
					m_r11.EnableWindow();
					m_r12.EnableWindow();
				}
				break;
			case 13:
				{
					m_r1.EnableWindow();
					m_r2.EnableWindow();
					m_r3.EnableWindow();
					m_r4.EnableWindow();
					m_r5.EnableWindow();
					m_r6.EnableWindow();
					m_r7.EnableWindow();
					m_r8.EnableWindow();
					m_r9.EnableWindow();
					m_r10.EnableWindow();
					m_r11.EnableWindow();
					m_r12.EnableWindow();
					m_r13.EnableWindow();
				}
				break;
			case 14:
				{
					m_r1.EnableWindow();
					m_r2.EnableWindow();
					m_r3.EnableWindow();
					m_r4.EnableWindow();
					m_r5.EnableWindow();
					m_r6.EnableWindow();
					m_r7.EnableWindow();
					m_r8.EnableWindow();
					m_r9.EnableWindow();
					m_r10.EnableWindow();
					m_r11.EnableWindow();
					m_r12.EnableWindow();
					m_r13.EnableWindow();
					m_r14.EnableWindow();
				}
				break;
			case 15:
				{
					m_r1.EnableWindow();
					m_r2.EnableWindow();
					m_r3.EnableWindow();
					m_r4.EnableWindow();
					m_r5.EnableWindow();
					m_r6.EnableWindow();
					m_r7.EnableWindow();
					m_r8.EnableWindow();
					m_r9.EnableWindow();
					m_r10.EnableWindow();
					m_r11.EnableWindow();
					m_r12.EnableWindow();
					m_r13.EnableWindow();
					m_r14.EnableWindow();
					m_r15.EnableWindow();
				}
				break;
			case 16:
				{
					m_r1.EnableWindow();
					m_r2.EnableWindow();
					m_r3.EnableWindow();
					m_r4.EnableWindow();
					m_r5.EnableWindow();
					m_r6.EnableWindow();
					m_r7.EnableWindow();
					m_r8.EnableWindow();
					m_r9.EnableWindow();
					m_r10.EnableWindow();
					m_r11.EnableWindow();
					m_r12.EnableWindow();
					m_r13.EnableWindow();
					m_r14.EnableWindow();
					m_r15.EnableWindow();
					m_r16.EnableWindow();
				}
				break;
			case 17:
				{
					m_r1.EnableWindow();
					m_r2.EnableWindow();
					m_r3.EnableWindow();
					m_r4.EnableWindow();
					m_r5.EnableWindow();
					m_r6.EnableWindow();
					m_r7.EnableWindow();
					m_r8.EnableWindow();
					m_r9.EnableWindow();
					m_r10.EnableWindow();
					m_r11.EnableWindow();
					m_r12.EnableWindow();
					m_r13.EnableWindow();
					m_r14.EnableWindow();
					m_r15.EnableWindow();
					m_r16.EnableWindow();
					m_r17.EnableWindow();
				}
				break;
			case 18:
				{
					m_r1.EnableWindow();
					m_r2.EnableWindow();
					m_r3.EnableWindow();
					m_r4.EnableWindow();
					m_r5.EnableWindow();
					m_r6.EnableWindow();
					m_r7.EnableWindow();
					m_r8.EnableWindow();
					m_r9.EnableWindow();
					m_r10.EnableWindow();
					m_r11.EnableWindow();
					m_r12.EnableWindow();
					m_r13.EnableWindow();
					m_r14.EnableWindow();
					m_r15.EnableWindow();
					m_r16.EnableWindow();
					m_r17.EnableWindow();
					m_r18.EnableWindow();
				}
				break;
			case 19:
				{
					m_r1.EnableWindow();
					m_r2.EnableWindow();
					m_r3.EnableWindow();
					m_r4.EnableWindow();
					m_r5.EnableWindow();
					m_r6.EnableWindow();
					m_r7.EnableWindow();
					m_r8.EnableWindow();
					m_r9.EnableWindow();
					m_r10.EnableWindow();
					m_r11.EnableWindow();
					m_r12.EnableWindow();
					m_r13.EnableWindow();
					m_r14.EnableWindow();
					m_r15.EnableWindow();
					m_r16.EnableWindow();
					m_r17.EnableWindow();
					m_r18.EnableWindow();
					m_r19.EnableWindow();
				}
				break;
			case 20:
				{
					m_r1.EnableWindow();
					m_r2.EnableWindow();
					m_r3.EnableWindow();
					m_r4.EnableWindow();
					m_r5.EnableWindow();
					m_r6.EnableWindow();
					m_r7.EnableWindow();
					m_r8.EnableWindow();
					m_r9.EnableWindow();
					m_r10.EnableWindow();
					m_r11.EnableWindow();
					m_r12.EnableWindow();
					m_r13.EnableWindow();
					m_r14.EnableWindow();
					m_r15.EnableWindow();
					m_r16.EnableWindow();
					m_r17.EnableWindow();
					m_r18.EnableWindow();
					m_r19.EnableWindow();
					m_r20.EnableWindow();
				}
				break;

		}
		UpdateData(false);
	}
	
}

void CFlatsFS::OnSave() 
{
	// TODO: Add your control notification handler code here
	if(CheckEntry())
	{
		m_save.EnableWindow(false);
		if(!cur)
			m_delete.EnableWindow();

		m_pView->PostMessage(WM_SAVECHANGES);
	}
	
}

void CFlatsFS::OnAdd() 
{
	// TODO: Add your control notification handler code here
	m_pView->PostMessage(WM_ADDNEW);
	
}

void CFlatsFS::OnDelete() 
{
	// TODO: Add your control notification handler code here
	m_pView->PostMessage(WM_DELETECUR);
	
}

void CFlatsFS::OnLast() 
{
	// TODO: Add your control notification handler code here
	m_pView->PostMessage(WM_MLAST);
	
}

void CFlatsFS::OnNext() 
{
	// TODO: Add your control notification handler code here
	m_pView->PostMessage(WM_MNEXT);
	
}

void CFlatsFS::OnPrev() 
{
	// TODO: Add your control notification handler code here
	m_pView->PostMessage(WM_MPREV);
	
}

void CFlatsFS::OnFirst() 
{
	// TODO: Add your control notification handler code here
	m_pView->PostMessage(WM_MFIRST);
}

void CFlatsFS::OnSelchangeAgent() 
{
	// TODO: Add your control notification handler code here
	m_save.EnableWindow();
	
}

void CFlatsFS::OnSelchangePhone() 
{
	// TODO: Add your control notification handler code here
	m_save.EnableWindow();
	
}

void CFlatsFS::OnChangeR1() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CalcS();
	m_save.EnableWindow();
	
}

void CFlatsFS::OnChangeR2() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CalcS();
	m_save.EnableWindow();
	
}

void CFlatsFS::OnChangeR3() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CalcS();
	m_save.EnableWindow();
	
}

void CFlatsFS::OnChangeR4() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CalcS();
	m_save.EnableWindow();
	
}

void CFlatsFS::OnChangeR5() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CalcS();
	m_save.EnableWindow();
	
}

void CFlatsFS::OnChangeR6() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CalcS();
	m_save.EnableWindow();
	
}

void CFlatsFS::OnChangeR7() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CalcS();
	m_save.EnableWindow();
	
}

void CFlatsFS::OnChangeR8() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CalcS();
	m_save.EnableWindow();
	
}

void CFlatsFS::OnChangeR9() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CalcS();
	m_save.EnableWindow();
	
}

void CFlatsFS::OnChangeSgeneral() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	m_save.EnableWindow();
	
}

void CFlatsFS::OnChangeSkitchen() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CalcS();
	m_save.EnableWindow();
	
}

void CFlatsFS::OnSelchangeWc() 
{
	// TODO: Add your control notification handler code here
	m_save.EnableWindow();
	
}

void CFlatsFS::OnChangeAddress() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	m_save.EnableWindow();
	
}

void CFlatsFS::OnChangeBuildingend() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	m_save.EnableWindow();
	
}

void CFlatsFS::OnChangeCostfrom() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	m_save.EnableWindow();
	
}

void CFlatsFS::OnChangeDescription() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	m_save.EnableWindow();
	
}

void CFlatsFS::OnChangeDistance() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	m_save.EnableWindow();
	
}

void CFlatsFS::OnSelchangeDistrict() 
{
	// TODO: Add your control notification handler code here
	m_save.EnableWindow();
	
}

void CFlatsFS::OnChangeFloor() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	m_save.EnableWindow();
	
}

void CFlatsFS::OnChangeFloors() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	m_save.EnableWindow();
	
}

void CFlatsFS::OnSelchangeForwhat() 
{
	// TODO: Add your control notification handler code here
	CString s="";
	m_forwhat.GetLBText(m_forwhat.GetCurSel(), s);
	if(s=="договорная")
	{
		m_costfrom.SetWindowText("");
		m_costfrom.EnableWindow(false);
	}
	else
		m_costfrom.EnableWindow();
	m_save.EnableWindow();
	
}

void CFlatsFS::OnSelchangeHousetype() 
{
	// TODO: Add your control notification handler code here
	m_save.EnableWindow();
	
}

void CFlatsFS::OnSelchangeInwhat() 
{
	// TODO: Add your control notification handler code here
	m_save.EnableWindow();
	
}

void CFlatsFS::OnSelchangeMetro() 
{
	// TODO: Add your control notification handler code here
	m_save.EnableWindow();
	
}

void CFlatsFS::OnChangeR10() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CalcS();
	m_save.EnableWindow();
	
}

void CFlatsFS::OnChangeR11() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CalcS();
	m_save.EnableWindow();
	
}

void CFlatsFS::OnChangeR12() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	m_sgeneral.Set_Number(m_sgeneral.Get_Number()+m_r12.Get_Number());
	m_save.EnableWindow();
	
}

void CFlatsFS::OnChangeR13() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CalcS();
	m_save.EnableWindow();
	
}

void CFlatsFS::OnChangeR14() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CalcS();
	m_save.EnableWindow();
	
}

void CFlatsFS::OnChangeR15() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CalcS();
	m_save.EnableWindow();
	
}

void CFlatsFS::OnChangeR16() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CalcS();
	m_save.EnableWindow();
	
}

void CFlatsFS::OnChangeR17() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CalcS();
	m_save.EnableWindow();
	
}

void CFlatsFS::OnChangeR18() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CalcS();
	m_save.EnableWindow();
	
}

void CFlatsFS::OnChangeR19() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	m_sgeneral.Set_Number(m_sgeneral.Get_Number()+m_r19.Get_Number());
	m_save.EnableWindow();
	
}

void CFlatsFS::OnChangeR20() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CalcS();
	m_save.EnableWindow();
	
}

void CFlatsFS::CalcS()
{
	m_sgeneral.Set_Number(m_r1.Get_Number()+m_r2.Get_Number()+m_r3.Get_Number()+
		m_r4.Get_Number()+m_r5.Get_Number()+m_r6.Get_Number()+m_r7.Get_Number()+
		m_r9.Get_Number()+m_r10.Get_Number()+m_r11.Get_Number()+m_r12.Get_Number()+
		m_r13.Get_Number()+m_r14.Get_Number()+m_r15.Get_Number()+m_r16.Get_Number()+
		m_r17.Get_Number()+m_r18.Get_Number()+m_r19.Get_Number()+m_r20.Get_Number()+
		m_skitchen.Get_Number());
}

BOOL CFlatsFS::CheckEntry()
{
	CString error;
	CString s;

	m_agent.GetLBText(m_agent.GetCurSel(), s);
	if(s.IsEmpty())
	{
		error+="необходимо выбрать агента в соответствующем поле |";

	}
	s="";
	m_aphone.GetLBText(m_aphone.GetCurSel(), s);
	if(s.IsEmpty())
	{
		error+="необходимо выбрать телефон агентства в соответствующем поле |";

	}
	s="";
	if(m_sgeneral.Get_Number() < m_r1.Get_Number()+m_r2.Get_Number()+m_r3.Get_Number()+m_r4.Get_Number()+m_r5.Get_Number()+m_r6.Get_Number()+m_r7.Get_Number()+m_r9.Get_Number()+m_r10.Get_Number()+m_r11.Get_Number()+m_r12.Get_Number()+m_r13.Get_Number()+m_r14.Get_Number()+m_r15.Get_Number()+m_r16.Get_Number()+m_r17.Get_Number()+m_r18.Get_Number()+m_r19.Get_Number()+m_r20.Get_Number()+m_skitchen.Get_Number())
	{
		error+="общая площадь не может быть меньше суммы площадей комнат и кухни\nпроверьте правильность введенного значения|";
	}
	if(m_sgeneral.Get_Number() > 1000)
	{
		error+="общая площадь не может быть более 1000 м. кв.\nпроверьте правильность введенного значения|";
	}
	if(m_sgeneral.Get_Number() < 15)
	{
		error+="общая площадь не может быть менее 15 м. кв.\nпроверьте правильность введенного значения|";
	}
	if(m_skitchen.Get_Number() > 99)
	{
		error+="площадь кухни не может быть более 99 м. кв.\nпроверьте правильность введенного значения|";
	}
	if(m_skitchen.Get_Number() < 5)
	{
		error+="площадь кухни не может быть менее 5 м. кв.\nпроверьте правильность введенного значения|";
	}
	m_floor.GetWindowText(s);
	LPSTR p = s.GetBuffer(2);
	int i=atoi(p);
	if((i<1) || (i>40))
	{
		error+="указан неверный этаж\nпроверьте правильность введенного значения (от 1 до 40)|";
	}
	s="";
	m_floors.GetWindowText(s);
	p = s.GetBuffer(2);
	i=atoi(p);
	if((i<1) || (i>40))
	{
		error+="указано неверное количество этажей\nпроверьте правильность введенного значения (от 1 до 40)|";
	}
	s="";
	m_htype.GetLBText(m_htype.GetCurSel(), s);
	if(s.IsEmpty())
	{
		error+="необходимо выбрать тип дома в соответствующем поле |";

	}
	s="";
	m_wc.GetLBText(m_wc.GetCurSel(), s);
	if(s.IsEmpty())
	{
		error+="необходимо выбрать тип санузла в соответствующем поле |";

	}
	s="";
	m_costfrom.GetWindowText(s);
	p = s.GetBuffer(2);
	i=atoi(p);
	if((i<1) || (i>5000))
	{
		s="";
		m_forwhat.GetLBText(m_forwhat.GetCurSel(), s);
		if(s.IsEmpty())
			error+="необходимо указать тип цены в соответствующем поле|";
		else if(s!="договорная")
			error+="указана неверная цена\nпроверьте правильность введенного значения (от 1 до 5000)|";
	}
	s="";
	m_district.GetLBText(m_district.GetCurSel(), s);
	if(s.IsEmpty())
	{
		error+="необходимо выбрать район в соответствующем поле |";
	}
	s="";
	m_metro.GetLBText(m_metro.GetCurSel(), s);
	if(s.IsEmpty())
	{
		error+="необходимо выбрать станцию метро\nили вписать транспортный узел в соответствующем поле |";
	}
	s="";
	m_distance.GetWindowText(s);
	p = s.GetBuffer(2);
	i=atoi(p);
	if((i<1) || (i>30))
	{
		error+="указано неверное расстояние до станции метро\nпроверьте правильность введенного значения (от 1 до 30)|";
	}
	s="";
	m_inwhat.GetLBText(m_inwhat.GetCurSel(), s);
	if(s.IsEmpty())
	{
		error+="необходимо указать в чем выражается дистанция в соответствующем поле |";
	}
	s="";
	m_phone.GetLBText(m_phone.GetCurSel(), s);
	if(s.IsEmpty())
	{
		error+="необходимо указать наличие телефона в соответствующем поле |";
	}
	s="";
	m_address.GetWindowText(s);
	if(s.IsEmpty())
	{
		error+="необходимо указать адрес в соответствующем поле |";
	}


	if(error.IsEmpty())
		return TRUE;
	else
	{
//		MessageBox(error, "Ошибка:", MB_OK);
		CError dlg;
		dlg.m_error=error;
		dlg.DoModal();
		return FALSE;
	}
}
