// InterComDoc.cpp : implementation of the CInterComDoc class
//

#include "stdafx.h"
#include "InterCom.h"

#include "InterComDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInterComDoc

IMPLEMENT_DYNCREATE(CInterComDoc, CDocument)

BEGIN_MESSAGE_MAP(CInterComDoc, CDocument)
	//{{AFX_MSG_MAP(CInterComDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInterComDoc construction/destruction

CInterComDoc::CInterComDoc()
{
	// TODO: add one-time construction code here

}

CInterComDoc::~CInterComDoc()
{
}

BOOL CInterComDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CInterComDoc serialization

void CInterComDoc::Serialize(CArchive& ar)
{
}

/////////////////////////////////////////////////////////////////////////////
// CInterComDoc diagnostics

#ifdef _DEBUG
void CInterComDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CInterComDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CInterComDoc commands
