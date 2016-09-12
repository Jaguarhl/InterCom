// ComFS.cpp : implementation file
//

#include "stdafx.h"
#include "InterCom.h"
#include "ComFS.h"
#include "Error.h"
#include "ImageProperties.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CComFS dialog


CComFS::CComFS(CWnd* pParent /*=NULL*/)
	: CDialog(CComFS::IDD, pParent)
{
	//{{AFX_DATA_INIT(CComFS)
	//}}AFX_DATA_INIT
}

CComFS::CComFS(CView* pView)
{
	m_pView = pView;
	m_pDial = this;

	gfxMode="";
	
	m_COid = -1;
}


void CComFS::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CComFS)
	DDX_Control(pDX, ID_IMAGES, m_images);
	DDX_Control(pDX, IDCANCEL, m_cancel);
	DDX_Control(pDX, IDC_WATERSUPPLY, m_watersupply);
	DDX_Control(pDX, IDC_SPLOT, m_splot);
	DDX_Control(pDX, IDC_SGENERAL, m_sgeneral);
	DDX_Control(pDX, IDC_SEWERAGE, m_sewerage);
	DDX_Control(pDX, IDC_PHONE, m_phone);
	DDX_Control(pDX, IDC_PARKING, m_parking);
	DDX_Control(pDX, IDC_OBJ_TYPE, m_obj_type);
	DDX_Control(pDX, IDC_HEATING, m_heating);
	DDX_Control(pDX, IDC_GUARD_S, m_guard_s);
	DDX_Control(pDX, IDC_FORWHAT, m_forwhat);
	DDX_Control(pDX, IDC_FLOORS, m_floors);
	DDX_Control(pDX, IDC_FLOOR, m_floor);
	DDX_Control(pDX, IDC_FIRE_S, m_fire_s);
	DDX_Control(pDX, IDC_ENTRANCE, m_entrance);
	DDX_Control(pDX, IDC_ELECTRICITY, m_electricity);
	DDX_Control(pDX, IDC_DOORWAY, m_doorway);
	DDX_Control(pDX, IDC_DISTRICT, m_district);
	DDX_Control(pDX, IDC_DESCRIPTION, m_description);
	DDX_Control(pDX, IDC_COSTFROM, m_costfrom);
	DDX_Control(pDX, IDC_CONDITION, m_condition);
	DDX_Control(pDX, IDC_CEILINGHEIGHT, m_ceilingheight);
	DDX_Control(pDX, IDC_APPOINTMENT, m_appointment);
	DDX_Control(pDX, IDC_APHONE, m_aphone);
	DDX_Control(pDX, IDC_AGENT, m_agent);
	DDX_Control(pDX, IDC_ADDRESS, m_address);
	DDX_Control(pDX, ID_SAVE, m_save);
	DDX_Control(pDX, ID_PREV, m_prev);
	DDX_Control(pDX, ID_NEXT, m_next);
	DDX_Control(pDX, ID_LAST, m_last);
	DDX_Control(pDX, ID_FIRST, m_first);
	DDX_Control(pDX, ID_DELETE, m_delete);
	DDX_Control(pDX, ID_CLEAR, m_clear);
	DDX_Control(pDX, ID_ADD, m_add);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CComFS, CDialog)
	//{{AFX_MSG_MAP(CComFS)
	ON_WM_ACTIVATE()
	ON_BN_CLICKED(ID_SAVE, OnSave)
	ON_CBN_SELCHANGE(IDC_OBJ_TYPE, OnSelchangeObjType)
	ON_CBN_SELCHANGE(IDC_AGENT, OnSelchangeAgent)
	ON_CBN_SELCHANGE(IDC_APHONE, OnSelchangeAphone)
	ON_EN_CHANGE(IDC_SGENERAL, OnChangeSgeneral)
	ON_EN_CHANGE(IDC_SPLOT, OnChangeSplot)
	ON_EN_CHANGE(IDC_FLOOR, OnChangeFloor)
	ON_EN_CHANGE(IDC_FLOORS, OnChangeFloors)
	ON_CBN_SELCHANGE(IDC_ENTRANCE, OnSelchangeEntrance)
	ON_CBN_SELCHANGE(IDC_CONDITION, OnSelchangeCondition)
	ON_EN_CHANGE(IDC_CEILINGHEIGHT, OnChangeCeilingheight)
	ON_CBN_SELCHANGE(IDC_DOORWAY, OnSelchangeDoorway)
	ON_EN_CHANGE(IDC_COSTFROM, OnChangeCostfrom)
	ON_CBN_SELCHANGE(IDC_FORWHAT, OnSelchangeForwhat)
	ON_CBN_SELCHANGE(IDC_DISTRICT, OnSelchangeDistrict)
	ON_EN_CHANGE(IDC_ADDRESS, OnChangeAddress)
	ON_EN_CHANGE(IDC_DESCRIPTION, OnChangeDescription)
	ON_CBN_SELCHANGE(IDC_APPOINTMENT, OnSelchangeAppointment)
	ON_BN_CLICKED(IDC_ELECTRICITY, OnElectricity)
	ON_BN_CLICKED(IDC_WATERSUPPLY, OnWatersupply)
	ON_BN_CLICKED(IDC_HEATING, OnHeating)
	ON_BN_CLICKED(IDC_SEWERAGE, OnSewerage)
	ON_BN_CLICKED(IDC_PHONE, OnPhone)
	ON_BN_CLICKED(IDC_PARKING, OnParking)
	ON_BN_CLICKED(IDC_GUARD_S, OnGuardS)
	ON_BN_CLICKED(IDC_FIRE_S, OnFireS)
	ON_BN_CLICKED(ID_NEXT, OnNext)
	ON_BN_CLICKED(ID_LAST, OnLast)
	ON_BN_CLICKED(ID_PREV, OnPrev)
	ON_BN_CLICKED(ID_FIRST, OnFirst)
	ON_BN_CLICKED(ID_ADD, OnAdd)
	ON_BN_CLICKED(ID_DELETE, OnDelete)
	ON_BN_CLICKED(ID_CLEAR, OnClear)
	ON_BN_CLICKED(ID_IMAGES, OnImages)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CComFS message handlers

BOOL CComFS::Create() 
{
	// TODO: Add your specialized code here and/or call the base class
	return CDialog::Create(CComFS::IDD);
}

void CComFS::OnCancel() 
{
	// TODO: Add extra cleanup here
	m_pView->PostMessage(WM_ENDOFDIAL);
}

void CComFS::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized) 
{
	CDialog::OnActivate(nState, pWndOther, bMinimized);
	
	// TODO: Add your message handler code here
	m_gpMyApp = (CInterComApp*)m_pDial; 
	m_pView->PostMessage(WM_SETPOINTER);
}

BOOL CComFS::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	re_m=0;

	m_sgeneral.LimitText(7);
	m_splot.LimitText(7);
	m_ceilingheight.LimitText(5);
	m_costfrom.LimitText(4);
	m_description.LimitText(31);
	m_address.LimitText(31);
	m_floor.LimitText(2);
	m_floors.LimitText(2);
	
	m_cancel.SetShade(CShadeButtonST::SHS_SOFTBUMP,8,20,5,RGB(55,55,255));
	m_clear.SetShade(CShadeButtonST::SHS_SOFTBUMP,8,20,5,RGB(55,55,255));
	m_save.SetShade(CShadeButtonST::SHS_SOFTBUMP,8,20,5,RGB(55,55,255));
	m_last.SetShade(CShadeButtonST::SHS_SOFTBUMP,8,20,5,RGB(55,55,255));
	m_next.SetShade(CShadeButtonST::SHS_SOFTBUMP,8,20,5,RGB(55,55,255));
	m_prev.SetShade(CShadeButtonST::SHS_SOFTBUMP,8,20,5,RGB(55,55,255));
	m_add.SetShade(CShadeButtonST::SHS_SOFTBUMP,8,20,5,RGB(55,55,255));
	m_images.SetShade(CShadeButtonST::SHS_SOFTBUMP,8,20,5,RGB(55,55,255));
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
	m_splot.Init();
	m_ceilingheight.Init();

	path=GetCommandLine();		// получаем командную строку
	path=path.Mid(1,path.ReverseFind('\\'));
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CComFS::OnSave() 
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

void CComFS::OnAdd() 
{
	// TODO: Add your control notification handler code here
	m_pView->PostMessage(WM_ADDNEW);
	
}

void CComFS::OnDelete() 
{
	// TODO: Add your control notification handler code here
	m_pView->PostMessage(WM_DELETECUR);
	
}

void CComFS::OnLast() 
{
	// TODO: Add your control notification handler code here
	m_pView->PostMessage(WM_MLAST);
	
}

void CComFS::OnNext() 
{
	// TODO: Add your control notification handler code here
	m_pView->PostMessage(WM_MNEXT);
	
}

void CComFS::OnPrev() 
{
	// TODO: Add your control notification handler code here
	m_pView->PostMessage(WM_MPREV);
	
}

void CComFS::OnFirst() 
{
	// TODO: Add your control notification handler code here
	m_pView->PostMessage(WM_MFIRST);
}

BOOL CComFS::CheckEntry()
{
	CString error;
	CString s;

	if(m_agent.GetCurSel()==CB_ERR)
	{
		error+="необходимо выбрать агента в соответствующем поле |";

	}
	if(m_aphone.GetCurSel()==CB_ERR)
	{
		error+="необходимо выбрать телефон агентства в соответствующем поле |";

	}
	if(m_obj_type.GetCurSel()==CB_ERR)
	{
		error+="необходимо указать тип объекта в соответствующем поле |";

	}
	if(m_sgeneral.IsWindowEnabled())
	{
		if(m_sgeneral.Get_Number() <= 0)
		{
			error+="общая площадь не может быть меньше 0\nпроверьте правильность введенного значения|";
		}
		if(m_sgeneral.Get_Number() > 100000)
		{
			error+="общая площадь не может быть более 100000 м. кв.\nпроверьте правильность введенного значения|";
		}
	}
	if(m_splot.IsWindowEnabled())
	{
		if(m_splot.Get_Number() > 100000)
		{
			error+="площадь участка не может быть более 100000 м. кв.\nпроверьте правильность введенного значения|";
		}
		if(m_splot.Get_Number() <= 0)
		{
			error+="площадь участка не может быть менее 0 м. кв.\nпроверьте правильность введенного значения|";
		}
	}
	if(m_floor.IsWindowEnabled())
	{
		s="";
		m_floor.GetWindowText(s);
		LPSTR p = s.GetBuffer(2);
		int i=atoi(p);
		if((i<1) || (i>40))
		{
			error+="указан неверный этаж\nпроверьте правильность введенного значения (от 1 до 40)|";
		}
	}
	
	if(m_floors.IsWindowEnabled())
	{
		s="";
		m_floors.GetWindowText(s);
		LPSTR p = s.GetBuffer(2);
		int i=atoi(p);
		if((i<1) || (i>40))
		{
			error+="указано неверное количество этажей\nпроверьте правильность введенного значения (от 1 до 40)|";
		}
	}
	if(m_entrance.IsWindowEnabled())
	{
		if(m_entrance.GetCurSel()==CB_ERR)
		{
			error+="необходимо указать количество входов в соответствующем поле |";
		}
	}
	if(m_condition.IsWindowEnabled())
	{
		if(m_condition.GetCurSel()==CB_ERR)
		{
			error+="необходимо указать состояние объекта в соответствующем поле |";
		}
	}
	if(m_ceilingheight.IsWindowEnabled())
	{
		if(m_ceilingheight.Get_Number() > 50)
		{
			error+="высота потолков не может быть более 50 м.\nпроверьте правильность введенного значения |";
		}
		if(m_ceilingheight.Get_Number() < 0)
		{
			error+="высота потолков не может быть менее 0 м.\nпроверьте правильность введенного значения |";
		}
	}
	if(m_doorway.IsWindowEnabled())
	{
		if(m_doorway.GetCurSel()==CB_ERR)
		{
			error+="необходимо указать подъезд в соответствующем поле |";
		}
	}
	s="";
	m_costfrom.GetWindowText(s);
	LPSTR p = s.GetBuffer(2);
	int i=atoi(p);
	if((i<1) || (i>5000))
	{
		if(m_forwhat.GetCurSel()==CB_ERR)
			error+="необходимо указать тип цены в соответствующем поле |";
		else
		{
			s="";
			m_forwhat.GetLBText(m_forwhat.GetCurSel(), s);
			if(s!="договорная")
				error+="указана неверная цена\nпроверьте правильность введенного значения (от 1 до 5000)|";
		}
	}
	if(m_district.GetCurSel()==CB_ERR)
	{
		error+="необходимо выбрать район в соответствующем поле |";
	}
	s="";
	m_address.GetWindowText(s);
	if(s.IsEmpty())
	{
		error+="необходимо указать адрес в соответствующем поле |";
	}
	if(m_appointment.IsWindowEnabled())
	{
		if(m_appointment.GetCurSel()==CB_ERR)
		{
			error+="необходимо указать назначение объекта в соответствующем поле |";
		}
	}


	if(error.IsEmpty())
		return TRUE;
	else
	{
		CError dlg;
		dlg.m_error=error;
		dlg.DoModal();
		return FALSE;
	}
}

void CComFS::OnSelchangeObjType() 
{
	// TODO: Add your control notification handler code here
	DisableCtrls();
		
	m_save.EnableWindow();
	
}

void CComFS::OnSelchangeAgent() 
{
	// TODO: Add your control notification handler code here
	m_save.EnableWindow();
	
}

void CComFS::OnSelchangeAphone() 
{
	// TODO: Add your control notification handler code here
	m_save.EnableWindow();
	
}

void CComFS::OnChangeSgeneral() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	m_save.EnableWindow();
	
}

void CComFS::OnChangeSplot() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	m_save.EnableWindow();
	
}

void CComFS::OnChangeFloor() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	m_save.EnableWindow();
	
}

void CComFS::OnChangeFloors() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	m_save.EnableWindow();
	
}

void CComFS::OnSelchangeEntrance() 
{
	// TODO: Add your control notification handler code here
	m_save.EnableWindow();
	
}

void CComFS::OnSelchangeCondition() 
{
	// TODO: Add your control notification handler code here
	m_save.EnableWindow();
	
}

void CComFS::OnChangeCeilingheight() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	m_save.EnableWindow();
	
}

void CComFS::OnSelchangeDoorway() 
{
	// TODO: Add your control notification handler code here
	m_save.EnableWindow();
	
}

void CComFS::OnChangeCostfrom() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	m_save.EnableWindow();
	
}

void CComFS::OnSelchangeForwhat() 
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

void CComFS::OnSelchangeDistrict() 
{
	// TODO: Add your control notification handler code here
	m_save.EnableWindow();
	
}

void CComFS::OnChangeAddress() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	m_save.EnableWindow();
	
}

void CComFS::OnChangeDescription() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	m_save.EnableWindow();
	
}

void CComFS::OnSelchangeAppointment() 
{
	// TODO: Add your control notification handler code here
	m_save.EnableWindow();
	
}

void CComFS::OnElectricity() 
{
	// TODO: Add your control notification handler code here
	m_save.EnableWindow();
}

void CComFS::OnWatersupply() 
{
	// TODO: Add your control notification handler code here
	m_save.EnableWindow();
}

void CComFS::OnHeating() 
{
	// TODO: Add your control notification handler code here
	m_save.EnableWindow();
}

void CComFS::OnSewerage() 
{
	// TODO: Add your control notification handler code here
	m_save.EnableWindow();
}

void CComFS::OnPhone() 
{
	// TODO: Add your control notification handler code here
	m_save.EnableWindow();
}

void CComFS::OnParking() 
{
	// TODO: Add your control notification handler code here
	m_save.EnableWindow();
}

void CComFS::OnGuardS() 
{
	// TODO: Add your control notification handler code here
	m_save.EnableWindow();
}

void CComFS::OnFireS() 
{
	// TODO: Add your control notification handler code here
	m_save.EnableWindow();
}

void CComFS::OnClear() 
{
	// TODO: Add your control notification handler code here
	
}

void CComFS::DisableCtrls()
{
	CString s="";
	m_obj_type.GetLBText(m_obj_type.GetCurSel(), s);
	if((s=="офис")||(s=="сф. обслуживания")||(s=="разл. назначения"))
	{
		re_m=1;
		m_appointment.SetCurSel(-1);
		m_appointment.EnableWindow(false);
		m_floors.EnableWindow();
		m_floor.EnableWindow();
		m_entrance.EnableWindow();
		m_splot.SetWindowText("");
		m_splot.EnableWindow(false);
		m_doorway.SetCurSel(-1);
		m_doorway.EnableWindow(false);
		m_ceilingheight.SetWindowText("");
		m_ceilingheight.EnableWindow(false);
		m_condition.EnableWindow();
		m_sgeneral.EnableWindow();
		if(!cur)
		{
			m_electricity.SetCheck(1);
			m_watersupply.SetCheck(1);
			m_heating.SetCheck(1);
			m_sewerage.SetCheck(1);
			m_phone.SetCheck(1);
		}
		UpdateData(false);
	}
	else if(s=="ОСЗ")
	{
		re_m=2;
		m_appointment.SetCurSel(-1);
		m_appointment.EnableWindow(false);
		m_floors.SetWindowText("");
		m_floors.EnableWindow();
		m_floor.SetWindowText("");
		m_floor.EnableWindow(false);
		m_entrance.SetCurSel(-1);
		m_entrance.EnableWindow(false);
		m_splot.EnableWindow();
		m_doorway.SetCurSel(-1);
		m_doorway.EnableWindow(false);
		m_ceilingheight.SetWindowText("");
		m_ceilingheight.EnableWindow(false);
		m_condition.EnableWindow();
		m_sgeneral.EnableWindow();
		if(!cur)
		{
			m_electricity.SetCheck(1);
			m_watersupply.SetCheck(1);
			m_heating.SetCheck(1);
			m_sewerage.SetCheck(1);
			m_phone.SetCheck(0);
		}
		UpdateData(false);
	}
	else if((s=="склад")||(s=="пром. недвижимость"))
	{
		re_m=3;
		m_appointment.SetCurSel(-1);
		m_appointment.EnableWindow(false);
		m_floors.SetWindowText("");
		m_floors.EnableWindow(false);
		m_floor.SetWindowText("");
		m_floor.EnableWindow(false);
		m_entrance.SetCurSel(-1);
		m_entrance.EnableWindow(false);
		m_splot.EnableWindow();
		m_doorway.EnableWindow();
		m_ceilingheight.EnableWindow();
		m_condition.EnableWindow();
		m_sgeneral.EnableWindow();
		if(!cur)
		{
			m_electricity.SetCheck(0);
			m_watersupply.SetCheck(0);
			m_heating.SetCheck(0);
			m_sewerage.SetCheck(0);
			m_phone.SetCheck(0);
		}
		UpdateData(false);
	}
	else if(s=="зем. участок")
	{
		re_m=4;
		m_appointment.SetCurSel(-1);
		m_appointment.EnableWindow();
		m_floors.SetWindowText("");
		m_floors.EnableWindow(false);
		m_floor.SetWindowText("");
		m_floor.EnableWindow(false);
		m_entrance.SetCurSel(-1);
		m_entrance.EnableWindow(false);
		m_splot.EnableWindow();
		m_doorway.SetCurSel(-1);
		m_doorway.EnableWindow(false);
		m_ceilingheight.SetWindowText("");
		m_ceilingheight.EnableWindow(false);
		m_condition.SetCurSel(-1);
		m_condition.EnableWindow(false);
		m_sgeneral.SetWindowText("");
		m_sgeneral.EnableWindow(false);
		if(!cur)
		{
			m_electricity.SetCheck(0);
			m_watersupply.SetCheck(0);
			m_heating.SetCheck(0);
			m_sewerage.SetCheck(0);
			m_phone.SetCheck(0);
		}
		UpdateData(false);
	}

}

void CComFS::OnImages() 
{
	// TODO: Add your control notification handler code here
	if(m_COid!=-1)
	{
//		char st[10];
//		itoa(m_COid, st, 10);
		SetCurrentDirectory(path);
//		AfxMessageBox(st);

		CImageProperties dlg;

		dlg.dir=path;
		dlg.gfxMode=gfxMode;
		dlg.ComID=m_COid;

		dlg.DoModal();
	}
	
}
