
// 03.16View.h : CMy0316View ��Ľӿ�
//

#pragma once


class CMy0316View : public CView
{
protected: // �������л�����
	CMy0316View();
	DECLARE_DYNCREATE(CMy0316View)

// ����
public:
	CMy0316Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMy0316View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 03.16View.cpp �еĵ��԰汾
inline CMy0316Doc* CMy0316View::GetDocument() const
   { return reinterpret_cast<CMy0316Doc*>(m_pDocument); }
#endif

