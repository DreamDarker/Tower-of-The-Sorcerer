
// ToTSView.h: CToTSView 类的接口
//

#pragma once


class CToTSView : public CView
{
protected: // 仅从序列化创建
	CToTSView();
	DECLARE_DYNCREATE(CToTSView)

// 特性
public:
	CToTSDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CToTSView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ToTSView.cpp 中的调试版本
inline CToTSDoc* CToTSView::GetDocument() const
   { return reinterpret_cast<CToTSDoc*>(m_pDocument); }
#endif

