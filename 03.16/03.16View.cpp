
// 03.16View.cpp : CMy0316View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "03.16.h"
#endif

#include "03.16Doc.h"
#include "03.16View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0316View

IMPLEMENT_DYNCREATE(CMy0316View, CView)

BEGIN_MESSAGE_MAP(CMy0316View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSEHOVER()
END_MESSAGE_MAP()

// CMy0316View ����/����

CMy0316View::CMy0316View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy0316View::~CMy0316View()
{
}

BOOL CMy0316View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy0316View ����

void CMy0316View::OnDraw(CDC*  pDC)
{
	CMy0316Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Rectangle(pDoc->m_tagRec);
}


// CMy0316View ���

#ifdef _DEBUG
void CMy0316View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0316View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0316Doc* CMy0316View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0316Doc)));
	return (CMy0316Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0316View ��Ϣ�������


void CMy0316View::OnLButtonDown(UINT nFlags, CPoint point)
{
	CMy0316Doc* pDoc = GetDocument();
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	{
	pDoc->m_tagRec.left = point.x;
	pDoc->m_tagRec.top = point.y;
	}

	CView::OnLButtonDown(nFlags, point);
}


void CMy0316View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMy0316Doc* pDoc = GetDocument();
	pDoc->m_tagRec.right=point.x ;
	pDoc->m_tagRec.bottom= point.y;
	CClientDC dc(this);
	dc.Rectangle(pDoc->m_tagRec);
	ReleaseCapture();
	CView::OnLButtonUp(nFlags, point);
}


void CMy0316View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMy0316Doc* pDoc = GetDocument();
	CClientDC dc(this);
	CString str;
   str.Format(_T("x=%d  y=%d"), point.x, point.y);
	dc.TextOutW(20, 30,str);

	CView::OnMouseMove(nFlags, point);
}




