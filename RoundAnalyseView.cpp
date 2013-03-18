
// RoundAnalyseView.cpp : implementation of the CRoundAnalyseView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "RoundAnalyse.h"
#endif

#include "RoundAnalyseDoc.h"
#include "RoundAnalyseView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRoundAnalyseView

IMPLEMENT_DYNCREATE(CRoundAnalyseView, CView)

BEGIN_MESSAGE_MAP(CRoundAnalyseView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRoundAnalyseView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CRoundAnalyseView construction/destruction

CRoundAnalyseView::CRoundAnalyseView()
{
	// TODO: add construction code here

}

CRoundAnalyseView::~CRoundAnalyseView()
{
}

BOOL CRoundAnalyseView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CRoundAnalyseView drawing

void CRoundAnalyseView::OnDraw(CDC* /*pDC*/)
{
	CRoundAnalyseDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CRoundAnalyseView printing


void CRoundAnalyseView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CRoundAnalyseView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CRoundAnalyseView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CRoundAnalyseView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CRoundAnalyseView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CRoundAnalyseView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CRoundAnalyseView diagnostics

#ifdef _DEBUG
void CRoundAnalyseView::AssertValid() const
{
	CView::AssertValid();
}

void CRoundAnalyseView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRoundAnalyseDoc* CRoundAnalyseView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRoundAnalyseDoc)));
	return (CRoundAnalyseDoc*)m_pDocument;
}
#endif //_DEBUG


// CRoundAnalyseView message handlers
