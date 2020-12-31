#if !defined(AFX_HOOKVIEW_H__D649DA9B_3EFC_11D1_9C9A_444553540000__INCLUDED_)
#define AFX_HOOKVIEW_H__D649DA9B_3EFC_11D1_9C9A_444553540000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif

class CHookView : public CView
{
protected:
	CHookView();
	DECLARE_DYNCREATE(CHookView)

public:
	CHookDoc* GetDocument();
	//{{AFX_VIRTUAL(CHookView)
	public:
	virtual void OnDraw(CDC* pDC);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

public:
	virtual ~CHookView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	//{{AFX_MSG(CHookView)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG
inline CHookDoc* CHookView::GetDocument()
   { return (CHookDoc*)m_pDocument; }
#endif
//{{AFX_INSERT_LOCATION}}
#endif // !defined(AFX_HOOKVIEW_H__D649DA9B_3EFC_11D1_9C9A_444553540000__INCLUDED_)