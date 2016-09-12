// Error.cpp : implementation file
//

#include "stdafx.h"
#include "InterCom.h"
#include "Error.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CError dialog


CError::CError(CWnd* pParent /*=NULL*/)
	: CDialog(CError::IDD, pParent)
{
	//{{AFX_DATA_INIT(CError)
	//}}AFX_DATA_INIT
}


void CError::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CError)
	DDX_Control(pDX, IDOK, m_close);
	DDX_Control(pDX, IDC_LBXST, m_list);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CError, CDialog)
	//{{AFX_MSG_MAP(CError)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CError message handlers

BOOL CError::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
//	m_err.SetWindowText(m_error);

//	int sp=0;
	m_close.SetShade(CShadeButtonST::SHS_SOFTBUMP,8,20,5,RGB(55,55,255));

	CreateImageList();
	m_list.SetImageList(&m_ImageList);

	CString str;
	for(int i=0; i<m_error.GetLength(); ++i)
	{
		if(m_error.GetAt(i) == '|')
		{
//			AfxMessageBox(str);
			m_list.AddString(str, 0);
			str="";
//			i++;
		}
		else
			str+=m_error.GetAt(i);
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CError::CreateImageList()
{
	BOOL	bRetValue = FALSE;
	HICON	hIcon = NULL;

	// Create image list
	bRetValue = m_ImageList.Create(32, 32, ILC_COLOR32 | ILC_MASK, 5, 1);
	ASSERT(bRetValue == TRUE);

	// Add some icons
	hIcon = AfxGetApp()->LoadIcon(IDI_PUNKT);
	m_ImageList.Add(hIcon);	
} // End of CreateImageList
