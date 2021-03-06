
// ToTSView.cpp: CToTSView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "ToTS.h"
#endif

#include "ToTSDoc.h"
#include "ToTSView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CToTSView

IMPLEMENT_DYNCREATE(CToTSView, CView)

BEGIN_MESSAGE_MAP(CToTSView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CToTSView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CToTSView 构造/析构

CToTSView::CToTSView()
{
	// TODO: 在此处添加构造代码

}

CToTSView::~CToTSView()
{
}

BOOL CToTSView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CToTSView 绘图

void CToTSView::OnDraw(CDC* pDC)
{
	CToTSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	// 绘制背景
	CRect clientRect;
	GetClientRect(&clientRect);

	int cx = pDoc->m_backgroud.GetWidth();
	int cy = pDoc->m_backgroud.GetHeight();

	float bmpAspect = float(cy) / cx;

	cx = clientRect.Width()* 0.7;
	cy = cx*bmpAspect;
	int x = (clientRect.Width() - cx) / 2;
	int y = (clientRect.Height() - cy) / 2;

	CDC memDC;
	memDC.CreateCompatibleDC(pDC);
	CBitmap memBmp;
	memBmp.CreateCompatibleBitmap(pDC, clientRect.Width(), clientRect.Height());
	memDC.SelectObject(&memBmp);
	memDC.FillSolidRect(0, 0, clientRect.Width(), clientRect.Height(), RGB(255, 255, 255));

	pDoc->m_backgroud.StretchBlt(memDC.GetSafeHdc(), x, y, cx, cy);

	pDC->BitBlt(0, 0, clientRect.Width(), clientRect.Height(), &memDC, 0, 0, SRCCOPY);

	// 文本输出
	CString str;
	str = " 1 ";
	pDC->TextOutW(550, 135, str);
	str = " 200 ";
	pDC->TextOutW(550, 225, str);
	str = " 10 ";
	pDC->TextOutW(550, 273, str);
	str = " 5 ";
	pDC->TextOutW(550, 325, str);
	str = " 0 ";
	pDC->TextOutW(550, 375, str);
	str = " 0 ";
	pDC->TextOutW(550, 425, str);
	str = " 0 ";
	pDC->TextOutW(550, 510, str);
	str = " 0 ";
	pDC->TextOutW(550, 595, str);
	str = " 0 ";
	pDC->TextOutW(550, 675, str);
}


// CToTSView 打印


void CToTSView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CToTSView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CToTSView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CToTSView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CToTSView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CToTSView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CToTSView 诊断

#ifdef _DEBUG
void CToTSView::AssertValid() const
{
	CView::AssertValid();
}

void CToTSView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CToTSDoc* CToTSView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CToTSDoc)));
	return (CToTSDoc*)m_pDocument;
}
#endif //_DEBUG


// CToTSView 消息处理程序
