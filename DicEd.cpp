// DicEd.cpp : implementation file
//

#include "stdafx.h"
#include "InterCom.h"
#include "DicEd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDicEd dialog


CDicEd::CDicEd(CWnd* pParent /*=NULL*/)
	: CDialog(CDicEd::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDicEd)
	m_value = _T("");
	//}}AFX_DATA_INIT
}


void CDicEd::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDicEd)
	DDX_Text(pDX, IDC_VALUE, m_value);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDicEd, CDialog)
	//{{AFX_MSG_MAP(CDicEd)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDicEd message handlers
