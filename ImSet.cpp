// ImSet.cpp : implementation file
//

#include "stdafx.h"
#include "InterCom.h"
#include "ImSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CImSet dialog


CImSet::CImSet(CWnd* pParent /*=NULL*/)
	: CDialog(CImSet::IDD, pParent)
{
	//{{AFX_DATA_INIT(CImSet)
	m_com = _T("");
	m_def = FALSE;
	//}}AFX_DATA_INIT
	pl=FALSE;
}


void CImSet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CImSet)
	DDX_Control(pDX, IDC_PLAN, m_plan);
	DDX_Control(pDX, IDC_PHOTO, m_photo);
	DDX_Text(pDX, IDC_COM, m_com);
	DDX_Check(pDX, IDC_DEF, m_def);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CImSet, CDialog)
	//{{AFX_MSG_MAP(CImSet)
	ON_BN_CLICKED(IDC_PLAN, OnPlan)
	ON_BN_CLICKED(IDC_PHOTO, OnPhoto)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImSet message handlers

BOOL CImSet::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	if(pl==TRUE)
	{
		m_plan.SetCheck(1);
		m_photo.SetCheck(0);
	}
	else
	{
		m_plan.SetCheck(0);
		m_photo.SetCheck(1);
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CImSet::OnPlan() 
{
	// TODO: Add your control notification handler code here
	m_plan.SetCheck(1);
	m_photo.SetCheck(0);
	pl=TRUE;
	UpdateData(false);
	
}

void CImSet::OnPhoto() 
{
	// TODO: Add your control notification handler code here
	m_plan.SetCheck(0);
	m_photo.SetCheck(1);
	pl=FALSE;
	UpdateData(false);
	
}
