#if !defined(__MBUTTON_H__)
#define __MBUTTON_H__

#define WM_BTNPOS	WM_USER+1000

class MCBitmapButton : public CBitmapButton
{
public:
	MCBitmapButton();
	BOOL LoadBitmaps
	(
		LPCTSTR lpszBitmapResource,
		LPCTSTR lpszBitmapResourceSel=NULL,
		LPCTSTR lpszBitmapResourceFocus=NULL,
		LPCTSTR lpszBitmapResourceDisabled=NULL,
		LPCTSTR lpszBitmapResourceMask=NULL
	);
	BOOL LoadBitmaps
	(
		UINT nIDBitmapResource,
		UINT nIDBitmapResourceSel=0,
		UINT nIDBitmapResourceFocus=0,
		UINT nIDBitmapResourceDisabled=0,
		UINT nIDBitmapResourceMask=0
	);
	BOOL AutoLoad(UINT nID, CWnd* pParent);
	void SetCheck(){m_bCheck=TRUE;}

protected:
	CBitmap m_bitmapMask;
	BOOL m_bCheck;
	afx_msg void OnLButtonUp(UINT, CPoint);
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDIS);
	DECLARE_DYNAMIC(MCBitmapButton)
	DECLARE_MESSAGE_MAP()
};

#endif