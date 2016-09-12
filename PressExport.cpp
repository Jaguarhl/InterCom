// PressExport.cpp : implementation file
//

#include "stdafx.h"
#include "InterCom.h"
#include "PressExport.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPressExport dialog


CPressExport::CPressExport(CWnd* pParent /*=NULL*/)
	: CDialog(CPressExport::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPressExport)
	//}}AFX_DATA_INIT
}


void CPressExport::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPressExport)
	DDX_Control(pDX, ID_EXP, m_exp);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDOK, m_close);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPressExport, CDialog)
	//{{AFX_MSG_MAP(CPressExport)
	ON_WM_DESTROY()
	ON_BN_CLICKED(ID_EXP, OnExp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPressExport message handlers

BOOL CPressExport::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_close.SetShade(CShadeButtonST::SHS_SOFTBUMP,8,20,5,RGB(55,55,255));
	m_exp.SetShade(CShadeButtonST::SHS_SOFTBUMP,8,20,5,RGB(55,55,255));

	m_list.SubclassDlgItem(IDC_LIST1,this);
//	m_list.SetCheckStyle(BS_CHECKBOX);

	LoadLibraries();

	FillList();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CPressExport::FillList()
{
	m_list.ResetContent(); //Clear the contents of the listbox

    for(int i=0; i<m_dwa.GetSize() ; i++)
	{
		PLGNAME pFunc = (PLGNAME)GetProcAddress((HINSTANCE)m_dwa.GetAt(i), _T("PlgName"));
		if (pFunc != NULL)
		{
			m_list.AddString(pFunc());
			m_list.SetCheck(i, 1);
			m_list.UpdateData();
		}
	}

	UpdateData(false);
}

void CPressExport::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	for (int i=0; i<m_dwa.GetSize() ; i++)
	{
		// Free all the libs we used
		FreeLibrary((HMODULE)m_dwa[i]);
	}	
}

void CPressExport::LoadLibraries()
{
	CString path=GetCommandLine();		// получаем командную строку
	path=path.Mid(1,path.ReverseFind('\\'));
	SetCurrentDirectory(path+plFolder);
	CFileFind finder;
	CString strWildCard = _T("*.dll"); //look for the plugin files

	//call this to set up the finder to iterate through all the plugins
	BOOL bWorking = finder.FindFile(strWildCard); 
	while (bWorking)
	{
		//have to call FindNextFile() before GetFileName()
		//because FindFile just sets the object up an returns
		//true if _ANY_ files were found
	    bWorking = finder.FindNextFile(); 
		if (finder.IsDots() || finder.IsDirectory())
			continue;

		HMODULE hm = LoadLibrary(finder.GetFilePath());

		//typedef int (*PFUNC)(void);	
		if ( !hm )
		{
			MessageBox("couldn't load");
		
		} 
		else
		{ //loaded OK, so add each library's HMODULE to an array.
			m_dwa.Add((DWORD)hm);
		}
	}
}

void CPressExport::OnExp() 
{
	// TODO: Add your control notification handler code here
}
