// URLDemo.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "URLDemo.h"
#include "URLDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CURLDemoApp

BEGIN_MESSAGE_MAP(CURLDemoApp, CWinApp)
	//{{AFX_MSG_MAP(CURLDemoApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CURLDemoApp construction

CURLDemoApp::CURLDemoApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CURLDemoApp object

CURLDemoApp theApp;
static HINSTANCE g_hRichEdDLL=NULL;

/////////////////////////////////////////////////////////////////////////////
// CURLDemoApp initialization

BOOL CURLDemoApp::InitInstance()
{
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

	// Initialize RichEdit control
	// for About Dialog
	if(g_hRichEdDLL==NULL)
	{
		g_hRichEdDLL=::LoadLibrary(_T("RICHED32.DLL"));
		if(g_hRichEdDLL==NULL)
			TRACE(_T("Cannot load library to display RichEditTextControl"));
	}


	CURLDemoDlg dlg;
	m_pMainWnd = &dlg;
	switch(dlg.DoModal())
	{
	case IDOK:
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
		break;
	case IDCANCEL:
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}
		break;
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

int CURLDemoApp::ExitInstance() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	// unload the library
	if(g_hRichEdDLL!=NULL)
		::FreeLibrary(g_hRichEdDLL);

	return CWinApp::ExitInstance();
}
