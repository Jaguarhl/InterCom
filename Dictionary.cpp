// Dictionary.cpp : implementation file
//

#include "stdafx.h"
#include "InterCom.h"
#include "Dictionary.h"
#include "DicEd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDictionary dialog


CDictionary::CDictionary(CWnd* pParent /*=NULL*/)
	: CDialog(CDictionary::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDictionary)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDictionary::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDictionary)
	DDX_Control(pDX, ID_ADD, m_add);
	DDX_Control(pDX, IDC_LIST, m_list);
	DDX_Control(pDX, IDC_DICT, m_dict);
	DDX_Control(pDX, ID_CHANGE, m_change);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDictionary, CDialog)
	//{{AFX_MSG_MAP(CDictionary)
	ON_CBN_EDITCHANGE(IDC_DICT, OnEditchangeDict)
	ON_CBN_SELCHANGE(IDC_DICT, OnSelchangeDict)
	ON_BN_CLICKED(ID_CHANGE, OnChange)
	ON_BN_CLICKED(ID_ADD, OnAdd)
	ON_LBN_DBLCLK(IDC_LIST, OnDblclkList)
	ON_BN_CLICKED(ID_DELETE, OnDelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDictionary message handlers

BOOL CDictionary::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	app_w_mode=APP_W_MODE;

	TRACE0("Let's init DB\n");
//	CString strConnection = _T("Driver={Microsoft Access Driver (*.mdb)};"
//        "Dbq=Database\\listings.mdb;Uid=;Pwd=;");
	if(m_pDb.Open(strConnection))
	{	
		m_pdRs = CADORecordset(&m_pDb);
		TRACE0("DB opened\n");

	}

	if(app_w_mode==2)
	{
		m_dict.AddString("Список агентов");
		m_dict.AddString("Список телефонов");
		m_dict.AddString("Типы домов");
		m_dict.AddString("Типы санузлов");
	
		if(m_mode==1)
			m_dict.SelectString(-1, "Список агентов");
		else if(m_mode==2)
			m_dict.SelectString(-1, "Список телефонов");
		else if(m_mode==3)
			m_dict.SelectString(-1, "Типы домов");
		else if(m_mode==4)
			m_dict.SelectString(-1, "Типы санузлов");
	}
	else if(app_w_mode==1)
	{
		m_dict.AddString("Список агентов");
		m_dict.AddString("Список телефонов");
		m_dict.AddString("Типы объектов");
		m_dict.AddString("Состояние");
		m_dict.AddString("Назначение");
		m_dict.AddString("Подъезд");
		m_dict.AddString("Вход");
	
		if(m_mode==1)
			m_dict.SelectString(-1, "Список агентов");
		else if(m_mode==2)
			m_dict.SelectString(-1, "Список телефонов");
		else if(m_mode==3)
			m_dict.SelectString(-1, "Типы объектов");
		else if(m_mode==4)
			m_dict.SelectString(-1, "Состояние");
		else if(m_mode==5)
			m_dict.SelectString(-1, "Назначение");
		else if(m_mode==6)
			m_dict.SelectString(-1, "Подъезд");
		else if(m_mode==7)
			m_dict.SelectString(-1, "Вход");
	}


	FillList();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDictionary::FillList()
{
	CString s;
	m_dict.GetLBText(m_dict.GetCurSel(), s);

	m_list.ResetContent();

	if(s=="Список агентов")
	{
		if(m_pdRs.Open("Agents", CADORecordset::openTable))
		{
			for(UINT i=1; i<=m_pdRs.GetRecordCount(); i++)
			{
				m_pdRs.SetAbsolutePosition(i);
				CString s;
				m_pdRs.GetFieldValue("AGENT", s);
				m_list.AddString(s);
			}
		
			m_pdRs.Close();
		}
	}
	else if(s=="Список телефонов")
	{
		if(m_pdRs.Open("Phones", CADORecordset::openTable))
		{
			for(UINT i=1; i<=m_pdRs.GetRecordCount(); i++)
			{
				m_pdRs.SetAbsolutePosition(i);
				CString s;
				m_pdRs.GetFieldValue("PHONE", s);
				m_list.AddString(s);
			}
		
			m_pdRs.Close();
		}
	}
	else if(s=="Типы домов")
	{
		if(m_pdRs.Open("Htype", CADORecordset::openTable))
		{
			for(UINT i=1; i<=m_pdRs.GetRecordCount(); i++)
			{
				m_pdRs.SetAbsolutePosition(i);
				CString s;
				m_pdRs.GetFieldValue("HTYPE", s);
				m_list.AddString(s);
			}
		
			m_pdRs.Close();
		}
	}
	else if(s=="Типы санузлов")
	{
		if(m_pdRs.Open("Bathroom", CADORecordset::openTable))
		{
			for(UINT i=1; i<=m_pdRs.GetRecordCount(); i++)
			{
				m_pdRs.SetAbsolutePosition(i);
				CString s;
				m_pdRs.GetFieldValue("WC", s);
				m_list.AddString(s);
			}
		
			m_pdRs.Close();
		}
	}
	else if(s=="Типы объектов")
	{
		if(m_pdRs.Open("ComObjects", CADORecordset::openTable))
		{
			for(UINT i=1; i<=m_pdRs.GetRecordCount(); i++)
			{
				m_pdRs.SetAbsolutePosition(i);
				CString s;
				m_pdRs.GetFieldValue("OBJECT", s);
				m_list.AddString(s);
			}
		
			m_pdRs.Close();
		}
	}
	else if(s=="Состояние")
	{
		if(m_pdRs.Open("Condition", CADORecordset::openTable))
		{
			for(UINT i=1; i<=m_pdRs.GetRecordCount(); i++)
			{
				m_pdRs.SetAbsolutePosition(i);
				CString s;
				m_pdRs.GetFieldValue("CONDITION", s);
				m_list.AddString(s);
			}
		
			m_pdRs.Close();
		}
	}
	else if(s=="Назначение")
	{
		if(m_pdRs.Open("Appointment", CADORecordset::openTable))
		{
			for(UINT i=1; i<=m_pdRs.GetRecordCount(); i++)
			{
				m_pdRs.SetAbsolutePosition(i);
				CString s;
				m_pdRs.GetFieldValue("APPOINTMENT", s);
				m_list.AddString(s);
			}
		
			m_pdRs.Close();
		}
	}
	else if(s=="Подъезд")
	{
		if(m_pdRs.Open("Doorway", CADORecordset::openTable))
		{
			for(UINT i=1; i<=m_pdRs.GetRecordCount(); i++)
			{
				m_pdRs.SetAbsolutePosition(i);
				CString s;
				m_pdRs.GetFieldValue("DOORWAY", s);
				m_list.AddString(s);
			}
		
			m_pdRs.Close();
		}
	}
	else if(s=="Вход")
	{
		if(m_pdRs.Open("Entrance", CADORecordset::openTable))
		{
			for(UINT i=1; i<=m_pdRs.GetRecordCount(); i++)
			{
				m_pdRs.SetAbsolutePosition(i);
				CString s;
				m_pdRs.GetFieldValue("ENTRANCE", s);
				m_list.AddString(s);
			}
		
			m_pdRs.Close();
		}
	}

	UpdateData(false);
}

void CDictionary::OnEditchangeDict() 
{
	// TODO: Add your control notification handler code here
	FillList();
	
}

void CDictionary::OnSelchangeDict() 
{
	// TODO: Add your control notification handler code here
	FillList();
	
}

void CDictionary::OnChange() 
{
	// TODO: Add your control notification handler code here
	CString s;
	int i=m_list.GetCurSel();
	m_list.GetText(i, s);
	CDicEd dlg;
	dlg.m_value=s;
	UINT res=dlg.DoModal();
	if(res==IDOK)
	{
		CString r;
		m_dict.GetLBText(m_dict.GetCurSel(), r);
		if(r=="Список агентов")
		{
			if(m_pdRs.Open("Agents", CADORecordset::openTable))
			{
				m_pdRs.SetAbsolutePosition(i+1);
				m_pdRs.Edit();
				m_pdRs.SetFieldValue("AGENT", dlg.m_value);
			}
		}
		else if(r=="Список телефонов")
		{
			if(m_pdRs.Open("Phones", CADORecordset::openTable))
			{
				m_pdRs.SetAbsolutePosition(i+1);
				m_pdRs.Edit();
				m_pdRs.SetFieldValue("PHONE", dlg.m_value);
			}
		}
		else if(r=="Типы домов")
		{
			if(m_pdRs.Open("Htype", CADORecordset::openTable))
			{
				m_pdRs.SetAbsolutePosition(i+1);
				m_pdRs.Edit();
				m_pdRs.SetFieldValue("HTYPE", dlg.m_value);
			}
		}
		else if(r=="Типы санузлов")
		{
			if(m_pdRs.Open("Bathroom", CADORecordset::openTable))
			{
				m_pdRs.SetAbsolutePosition(i+1);
				m_pdRs.Edit();
				m_pdRs.SetFieldValue("WC", dlg.m_value);
			}
		}
		else if(r=="Типы объектов")
		{
			AfxMessageBox("Внимание! Крайне не рекомендуется менять настройки в этом словаре. Возможна неверная работа программы.");
			if(m_pdRs.Open("ComObjects", CADORecordset::openTable))
			{
				m_pdRs.SetAbsolutePosition(i+1);
				m_pdRs.Edit();
				m_pdRs.SetFieldValue("OBJECT", dlg.m_value);
			}
		}
		else if(r=="Состояние")
		{
			if(m_pdRs.Open("Condition", CADORecordset::openTable))
			{
				m_pdRs.SetAbsolutePosition(i+1);
				m_pdRs.Edit();
				m_pdRs.SetFieldValue("CONDITION", dlg.m_value);
			}
		}
		else if(r=="Назначение")
		{
			if(m_pdRs.Open("Appointment", CADORecordset::openTable))
			{
				m_pdRs.SetAbsolutePosition(i+1);
				m_pdRs.Edit();
				m_pdRs.SetFieldValue("APPOINTMENT", dlg.m_value);
			}
		}
		else if(r=="Подъезд")
		{
			if(m_pdRs.Open("Doorway", CADORecordset::openTable))
			{
				m_pdRs.SetAbsolutePosition(i+1);
				m_pdRs.Edit();
				m_pdRs.SetFieldValue("DOORWAY", dlg.m_value);
			}
		}
		else if(r=="Вход")
		{
			if(m_pdRs.Open("Entrance", CADORecordset::openTable))
			{
				m_pdRs.SetAbsolutePosition(i+1);
				m_pdRs.Edit();
				m_pdRs.SetFieldValue("ENTRANCE", dlg.m_value);
			}
		}

		m_pdRs.Update();

		FillList();
	}
	
}

void CDictionary::OnAdd() 
{
	// TODO: Add your control notification handler code here
	CDicEd dlg;
	UINT res=dlg.DoModal();
	if(res==IDOK)
	{
		CString r;
		m_dict.GetLBText(m_dict.GetCurSel(), r);
		if(r=="Список агентов")
		{
			if(m_pdRs.Open("Agents", CADORecordset::openTable))
			{
				m_pdRs.AddNew();
				m_pdRs.SetFieldValue("AGENT", dlg.m_value);
			}
		}
		else if(r=="Список телефонов")
		{
			if(m_pdRs.Open("Phones", CADORecordset::openTable))
			{
				m_pdRs.AddNew();
				m_pdRs.SetFieldValue("PHONE", dlg.m_value);
			}
		}
		else if(r=="Типы домов")
		{
			if(m_pdRs.Open("Htype", CADORecordset::openTable))
			{
				m_pdRs.AddNew();
				m_pdRs.SetFieldValue("HTYPE", dlg.m_value);
			}
		}
		else if(r=="Типы санузлов")
		{
			if(m_pdRs.Open("Bathroom", CADORecordset::openTable))
			{
				m_pdRs.AddNew();
				m_pdRs.SetFieldValue("WC", dlg.m_value);
			}
		}
		else if(r=="Типы объектов")
		{
			if(m_pdRs.Open("ComObjects", CADORecordset::openTable))
			{
				m_pdRs.AddNew();
				m_pdRs.SetFieldValue("OBJECT", dlg.m_value);
			}
		}
		else if(r=="Состояние")
		{
			if(m_pdRs.Open("Condition", CADORecordset::openTable))
			{
				m_pdRs.AddNew();
				m_pdRs.SetFieldValue("CONDITION", dlg.m_value);
			}
		}
		else if(r=="Назначение")
		{
			if(m_pdRs.Open("Appointment", CADORecordset::openTable))
			{
				m_pdRs.AddNew();
				m_pdRs.SetFieldValue("APPOINTMENT", dlg.m_value);
			}
		}
		else if(r=="Подъезд")
		{
			if(m_pdRs.Open("Doorway", CADORecordset::openTable))
			{
				m_pdRs.AddNew();
				m_pdRs.SetFieldValue("DOORWAY", dlg.m_value);
			}
		}
		else if(r=="Вход")
		{
			if(m_pdRs.Open("Entrance", CADORecordset::openTable))
			{
				m_pdRs.AddNew();
				m_pdRs.SetFieldValue("ENTRANCE", dlg.m_value);
			}
		}

		m_pdRs.Update();
		
		FillList();
	}
	
}

void CDictionary::OnDblclkList() 
{
	// TODO: Add your control notification handler code here
	OnChange();
	
}

void CDictionary::OnDelete() 
{
	// TODO: Add your control notification handler code here
	int i=m_list.GetCurSel();
	CString r;
	m_dict.GetLBText(m_dict.GetCurSel(), r);
	if(r=="Список агентов")
	{
		if(m_pdRs.Open("Agents", CADORecordset::openTable))
		{
			m_pdRs.SetAbsolutePosition(i+1);
			m_pdRs.Delete();
		}
	}
	else if(r=="Список телефонов")
	{
		if(m_pdRs.Open("Phones", CADORecordset::openTable))
		{
			m_pdRs.SetAbsolutePosition(i+1);
			m_pdRs.Delete();
		}
	}
	else if(r=="Типы объектов")
		{
			if(m_pdRs.Open("ComObjects", CADORecordset::openTable))
			{
				m_pdRs.SetAbsolutePosition(i+1);
				m_pdRs.Delete();
			}
		}
		else if(r=="Состояние")
		{
			if(m_pdRs.Open("Condition", CADORecordset::openTable))
			{
				m_pdRs.SetAbsolutePosition(i+1);
				m_pdRs.Delete();
			}
		}
		else if(r=="Назначение")
		{
			if(m_pdRs.Open("Appointment", CADORecordset::openTable))
			{
				m_pdRs.SetAbsolutePosition(i+1);
				m_pdRs.Delete();
			}
		}
		else if(r=="Подъезд")
		{
			if(m_pdRs.Open("Doorway", CADORecordset::openTable))
			{
				m_pdRs.SetAbsolutePosition(i+1);
				m_pdRs.Delete();
			}
		}
		else if(r=="Вход")
		{
			if(m_pdRs.Open("Entrance", CADORecordset::openTable))
			{
				m_pdRs.SetAbsolutePosition(i+1);
				m_pdRs.Delete();
			}
		}

	m_pdRs.Update();
		
	FillList();
}
