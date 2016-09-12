// ImageProperties.cpp : implementation file
//

#include "stdafx.h"
#include "InterCom.h"
#include "ImageProperties.h"
#include "ImSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define random(num)  (rand()%(num))

/////////////////////////////////////////////////////////////////////////////
// CImageProperties dialog


CImageProperties::CImageProperties(CWnd* pParent /*=NULL*/)
	: CDialog(CImageProperties::IDD, pParent)
{
	//{{AFX_DATA_INIT(CImageProperties)
	//}}AFX_DATA_INIT
	sh=0;
	sy=0;
	bitmap=NULL;
}


void CImageProperties::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CImageProperties)
	DDX_Control(pDX, IDC_SCROLLBAR1, m_vbar);
	DDX_Control(pDX, ID_OPEN, m_open);
	DDX_Control(pDX, IDOK, m_close);
	DDX_Control(pDX, IDC_LBXST, m_list);
	DDX_Control(pDX, ID_DEL, m_del);
	DDX_Control(pDX, ID_ADD, m_add);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CImageProperties, CDialog)
	//{{AFX_MSG_MAP(CImageProperties)
	ON_BN_CLICKED(ID_ADD, OnAdd)
	ON_BN_CLICKED(ID_DEL, OnDel)
	ON_WM_PAINT()
	ON_BN_CLICKED(ID_OPEN, OnOpen)
	ON_WM_VSCROLL()
	ON_LBN_DBLCLK(IDC_LBXST, OnDblclkLbxst)
	ON_COMMAND(ID_LISTINGS_COM_FR, OnListingsComFr)
	ON_UPDATE_COMMAND_UI(ID_LISTINGS_COM_FR, OnUpdateListingsComFr)
	ON_COMMAND(ID_LISTINGS_COM_FS, OnListingsComFs)
	ON_UPDATE_COMMAND_UI(ID_LISTINGS_COM_FS, OnUpdateListingsComFs)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImageProperties message handlers

void CImageProperties::OnAdd() 
{
	// TODO: Add your control notification handler code here
	if (bitmap != NULL) 
	{
		FIBITMAP * bm=NULL;

		if(FreeImage_GetBPP(bitmap) != 24)
			bm = FreeImage_ConvertTo24Bits(bitmap);
		else
			bm = FreeImage_Clone(bitmap);

		long pos=0;

		if(m_pdRs.Open("Images", CADORecordset::openTable))
		{
			m_pdRs.AddNew();
			pos=m_pdRs.GetAbsolutePosition();

			CImSet dlg;

			if(fif==FIF_BMP)
				dlg.pl=TRUE;
			
			UINT result = dlg.DoModal();
			if(result==IDOK)
			{
				// 1 - default picture, 2 - plan, 3 - photo
				if(dlg.m_def==TRUE)
					m_pdRs.SetFieldValue("PRIORITY", 1);
				else if(dlg.m_def==FALSE)
				{
					if(dlg.pl==TRUE)
						m_pdRs.SetFieldValue("PRIORITY", 2);
					else if(dlg.pl==FALSE)
						m_pdRs.SetFieldValue("PRIORITY", 3);
				}

				m_pdRs.SetFieldValue("TYPE", gfxMode); //Tell to programm, that image belong ComFS table

				m_pdRs.SetFieldValue("COMMENTS", dlg.m_com);

				m_pdRs.SetFieldValue("ID_NUM", ComID);

				m_pdRs.Update();

				//Generate file name nad save image 
				m_pdRs.SetAbsolutePosition(pos);

				int id;
				CString fn;
				CString fname=dir;
				fname+=imFolder;

				m_pdRs.GetFieldValue("ID", id);

//				int rnd = rand() % 5;

				char st[10];
				itoa(id, st, 10);
				fn=st;
				fname+=st;
				fname+=".jpg";
				fn+=".jpg";

//				AfxMessageBox(fname);

				FreeImage_Save(FIF_JPEG, bm, fname, 0);

				m_pdRs.Edit();

				m_pdRs.SetFieldValue("FNAME", fn);

				m_pdRs.Update();

				m_add.EnableWindow(false);
			}
		}
	}

	FillList();
}

void CImageProperties::OnDel() 
{
	// TODO: Add your control notification handler code here
	if(m_list.GetCurSel()!=LB_ERR)
	{
		CString str;
		m_list.GetText(m_list.GetCurSel(), str);
		str = str.Left(str.ReverseFind(':'));

		if(m_pdRs.Open("Images", CADORecordset::openTable))
		{
			for(UINT i=1; i<=m_pdRs.GetRecordCount(); i++)
			{
				m_pdRs.SetAbsolutePosition(i);
				int id=0;
				m_pdRs.GetFieldValue("ID_NUM", id);
				CString s;
				m_pdRs.GetFieldValue("TYPE", s);
				CString res;
				m_pdRs.GetFieldValue("FNAME", res);

				if((id==ComID) && (s==gfxMode) && (str==res))
				{
					m_pdRs.Delete();
					DeleteFile(dir+imFolder+str);
					m_list.DeleteString(m_list.GetCurSel());
				}
			}
			m_pdRs.Close();
		}

		UpdateData(false);
	}
}

BOOL CImageProperties::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_close.SetShade(CShadeButtonST::SHS_SOFTBUMP,8,20,5,RGB(55,55,255));
	m_add.SetShade(CShadeButtonST::SHS_SOFTBUMP,8,20,5,RGB(55,55,255));
	m_add.SetIcon(IDI_CLIP);
	m_del.SetShade(CShadeButtonST::SHS_SOFTBUMP,8,20,5,RGB(55,55,255));
	m_del.SetIcon(IDI_DEL);
	m_open.SetShade(CShadeButtonST::SHS_SOFTBUMP,8,20,5,RGB(55,55,255));

	CreateImageList();
	m_list.SetImageList(&m_ImageList);

	m_vbar.ShowWindow(false);  //Hide Vertical Scroll Bar

	FreeImage_Initialise();

	r.left=254;
	r.top=11;
	r.right=856;
	r.bottom=473;

	//Let's init DB and fill our list
	TRACE0("Let's init DB\n");
	if(m_pDb.Open(strConnection))
	{	
		m_pdRs = CADORecordset(&m_pDb);
		TRACE0("DB opened\n");

	}
	
	m_add.EnableWindow(false);

	FillList();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CImageProperties::CreateImageList()
{
	BOOL	bRetValue = FALSE;
	HICON	hIcon = NULL;

	// Create image list
	bRetValue = m_ImageList.Create(32, 32, ILC_COLOR32 | ILC_MASK, 5, 1);
	ASSERT(bRetValue == TRUE);

	// Add some icons
	hIcon = AfxGetApp()->LoadIcon(IDI_DEFINE);
	m_ImageList.Add(hIcon);	
	hIcon = AfxGetApp()->LoadIcon(IDI_PLAN);
	m_ImageList.Add(hIcon);
	hIcon = AfxGetApp()->LoadIcon(IDI_PHOTO);
	m_ImageList.Add(hIcon);	
} // End of CreateImageList

void CImageProperties::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	if(sh==-1)
		dc.Rectangle(254, 11, 856, FreeImage_GetHeight(bitmap)+13);
	else
		dc.Rectangle(254, 11, 856, 473);


	if(bitmap!=NULL)
	{
		BYTE *pData = FreeImage_GetBits(bitmap);

		SetStretchBltMode(dc.m_hDC, COLORONCOLOR);
		StretchDIBits(dc.m_hDC,
			// x-y-coord of destination upper-left corner
	        255, 12,                       
	        // width-height of destination rectangle
	        600, 460, 
	        // x-y-coord of source upper-left corner
	        0, sy,                                
	        // width-height of source rectangle
	        600, 460, 
	        pData,                               // bitmap bits
	        FreeImage_GetInfo(bitmap),    // bitmap data
	        DIB_RGB_COLORS,                      // usage options
	        SRCCOPY);
	}
	
	// Do not call CDialog::OnPaint() for painting messages
}

void CImageProperties::OnOpen() 
{
	// TODO: Add your control notification handler code here
	CString m_sFilename;
	CFileDialog dialog(TRUE, NULL, m_sFilename, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, 
							"Изображения (*.bmp, *.gif, *.jpeg, *.jpg)|*.bmp;*.gif;*.jpeg;*.jpg||");

	if (IDOK == dialog.DoModal())
	{
		LoadImage(dialog.GetPathName());
		m_add.EnableWindow(true);
	}
}

void CImageProperties::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	if(nSBCode == SB_LINEDOWN)
	{
		if(sy>0)
		{
			sy-=1;
			m_vbar.SetScrollPos(sh-sy, TRUE);
		}
	}
	else if(nSBCode == SB_LINEUP)
	{
		if(sy<(FreeImage_GetHeight(bitmap)-460))
		{
			sy+=1;
			m_vbar.SetScrollPos(sh-sy, TRUE);
		}
	}
	else if(nSBCode == SB_THUMBTRACK)
	{
		if(sy>=0)
		{
			if(sy<=FreeImage_GetHeight(bitmap)-460)
			{
				sy=sh-nPos;
				m_vbar.SetScrollPos(sh-sy, TRUE);
			}
		}
	}
	RedrawWindow(&r);

	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}

void CImageProperties::FillList()
{
	m_list.ResetContent();
	if(m_pdRs.Open("Images", CADORecordset::openTable))
	{
		for(UINT i=1; i<=m_pdRs.GetRecordCount(); i++)
		{
			m_pdRs.SetAbsolutePosition(i);
			int id=0;
			m_pdRs.GetFieldValue("ID_NUM", id);
			CString s;
			m_pdRs.GetFieldValue("TYPE", s);

			if((id==ComID) && (s==gfxMode))
			{
				CString res;
				m_pdRs.GetFieldValue("FNAME", s);
				res=s;
				m_pdRs.GetFieldValue("COMMENTS", s);
				res+=": ";
				res+=s;
				int it=-1;
				m_pdRs.GetFieldValue("PRIORITY", it);
				m_list.AddString(res, it-1);
			}
		}

		m_pdRs.Close();
	}
	else
		AfxMessageBox("Can't update list.");

	UpdateData(false);
}

void CImageProperties::LoadImage(CString FilePath)
{
	m_vbar.ShowWindow(false);

	fif = FIF_UNKNOWN;
		
	fif = FreeImage_GetFileType(FilePath, 0);
	if(fif == FIF_UNKNOWN)
	{
		// no signature ?
		// try to guess the file format from the file extension
		fif = FreeImage_GetFIFFromFilename(FilePath);
	}
	if((fif != FIF_UNKNOWN) && FreeImage_FIFSupportsReading(fif))
	{
		// ok, let's load the file
		bitmap = FreeImage_Load(fif, FilePath);
		// unless a bad file format, we are done !
		FIBITMAP * bm=NULL;

		if(FreeImage_GetBPP(bitmap) != 32)
			bm = FreeImage_ConvertTo32Bits(bitmap);
		else
			bm = FreeImage_Clone(bitmap);
			
		if(FreeImage_GetWidth(bitmap) != 600)
		{
			double rh = FreeImage_GetWidth(bitmap);
			double f = 600 / rh;
			double hg = FreeImage_GetHeight(bitmap) * f;
			int h = hg;

			bitmap = FreeImage_Rescale(bm, 600, h, FILTER_BICUBIC);
			if(bitmap==NULL)
				AfxMessageBox("Ошибка при открытии графического файла. Проверьте его наличие в соответствующей директории.");

		}

			
		if(FreeImage_GetHeight(bitmap)>460)
		{
			m_vbar.SetScrollRange(0, (FreeImage_GetHeight(bitmap)-460), TRUE);
			sy=FreeImage_GetHeight(bitmap)-460;
			sh=sy;
			m_vbar.SetScrollPos(0-sy, TRUE);
			m_vbar.ShowWindow(true);
		}
		else
		{
			sy=FreeImage_GetHeight(bitmap)-460;
			sh=-1;
		}
	}
	else
		AfxMessageBox("Неподдерживаемый графический формат!");

	RedrawWindow(&r);
	UpdateData(false);
}

void CImageProperties::OnDblclkLbxst() 
{
	// TODO: Add your control notification handler code here
	m_add.EnableWindow(false);
	CString s;
	m_list.GetText(m_list.GetCurSel(), s);
	s = s.Left(s.ReverseFind(':'));
//	AfxMessageBox(s);
	LoadImage(dir+imFolder+s);
}

void CImageProperties::OnListingsComFr() 
{
	// TODO: Add your command handler code here
	
}

void CImageProperties::OnUpdateListingsComFr(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}

void CImageProperties::OnListingsComFs() 
{
	// TODO: Add your command handler code here
	
}

void CImageProperties::OnUpdateListingsComFs(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}
