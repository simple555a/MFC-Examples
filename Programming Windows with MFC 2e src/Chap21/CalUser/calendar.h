#if !defined(AFX_CALENDAR_H__68932D46_CFE2_11D2_9282_00C04F8ECF0C__INCLUDED_)
#define AFX_CALENDAR_H__68932D46_CFE2_11D2_9282_00C04F8ECF0C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.

/////////////////////////////////////////////////////////////////////////////
// CCalendar wrapper class

class CCalendar : public CWnd
{
protected:
	DECLARE_DYNCREATE(CCalendar)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0xed780d6b, 0xcc9f, 0x11d2, { 0x92, 0x82, 0x0, 0xc0, 0x4f, 0x8e, 0xcf, 0xc } };
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName,
		LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect,
		CWnd* pParentWnd, UINT nID,
		CCreateContext* pContext = NULL)
	{ return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID); }

    BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect, CWnd* pParentWnd, UINT nID,
		CFile* pPersist = NULL, BOOL bStorage = FALSE,
		BSTR bstrLicKey = NULL)
	{ return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
		pPersist, bStorage, bstrLicKey); }

// Attributes
public:
	OLE_COLOR GetBackColor();
	void SetBackColor(OLE_COLOR);
	BOOL GetRedSundays();
	void SetRedSundays(BOOL);

// Operations
public:
	DATE GetDate();
	BOOL SetDate(short nYear, short nMonth, short nDay);
	void AboutBox();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CALENDAR_H__68932D46_CFE2_11D2_9282_00C04F8ECF0C__INCLUDED_)