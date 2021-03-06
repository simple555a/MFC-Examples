#include "stdafx.h"
#include "CDB.h"
#include "FileDlg.h"
#include "CDBDoc.h"
#include "CusFDlg.h"
#include "Dlgs.h"
#include "shlobj.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CCDBDoc, CDocument)

BEGIN_MESSAGE_MAP(CCDBDoc, CDocument)
	//{{AFX_MSG_MAP(CCDBDoc)
	ON_COMMAND(ID_FILEDIALOGBOX_FILEOPEN, OnFiledialogboxFileopen)
	ON_COMMAND(ID_FILEDIALOGBOX_FILESAVE, OnFiledialogboxFilesave)
	ON_COMMAND(ID_FILEDIALOGBOX_CUSTOMIZEDFILEOPEN, OnFiledialogboxCustomizedfileopen)
	ON_COMMAND(ID_FILEDIALOGBOX_CUSTOMIZEFILEOPENOLD, OnFiledialogboxCustomizefileopenold)
	ON_COMMAND(ID_FILEDIALOGBOX_DIRDIALOG, OnFiledialogboxDirdialog)
	ON_COMMAND(ID_FILEDIALOGBOX_DIRDIALOGOLD, OnFiledialogboxDirdialogold)
	ON_COMMAND(ID_FILEDIALOGBOX_CUSTOMFILEDLG, OnFiledialogboxCustomfiledlg)
	ON_COMMAND(ID_COLORDIALOGBOX_INITIALIZE, OnColordialogboxInitialize)
	ON_COMMAND(ID_COLORDIALOGBOX_DISABLEFULLOPEN, OnColordialogboxDisablefullopen)
	ON_COMMAND(ID_COLORDIALOGBOX_FULLOPEN, OnColordialogboxFullopen)
	ON_COMMAND(ID_COLORDIALOGBOX_CHOOSEBASECOLOR, OnColordialogboxChoosebasecolor)
	ON_COMMAND(ID_COLORDIALOGBOX_CHOOSECOSTUMCOLOR, OnColordialogboxChoosecostumcolor)
	ON_COMMAND(ID_FONTDIALOGBOX_INITIALIZE, OnFontdialogboxInitialize)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CCDBDoc::CCDBDoc()
{
}

CCDBDoc::~CCDBDoc()
{
}

BOOL CCDBDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	return TRUE;
}

void CCDBDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	}
	else
	{
	}
}

#ifdef _DEBUG
void CCDBDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCDBDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif

void CCDBDoc::OnFiledialogboxFileopen() 
{
	CFileDialog	dlg(TRUE);
	CString szStr;

    dlg.m_ofn.lpstrFilter="Source Files(*.C;*.CPP;*.H;*.HPP)\0*.C;*.CPP;*.H;*.HPP\0Document(*.DOC;*.HTML)\0*.DOC;*.HTML\0All(*.*)\0*.*\0";
    dlg.m_ofn.nFilterIndex=1; 
	dlg.m_ofn.lpstrCustomFilter="DIB Files(*.BMP)\0*.BMP\0";
	dlg.m_ofn.nMaxCustFilter=26;
	if(dlg.DoModal() == IDOK)
	{
		szStr="File Name: ";
		szStr+=dlg.GetFileName();
		AfxMessageBox(szStr);
		szStr.Empty();
		szStr="Path Name: ";
		szStr+=dlg.GetPathName();
		AfxMessageBox(szStr);
	}
}

void CCDBDoc::OnFiledialogboxFilesave() 
{
	char szFile[256];
	CFileDialog	dlg(FALSE);
	CString szStr;

	sprintf(szFile, "TestFile");
	dlg.m_ofn.lpstrFile=szFile;
    dlg.m_ofn.nMaxFile=sizeof(szFile);
    dlg.m_ofn.lpstrDefExt="DIB";
    dlg.m_ofn.lpstrFilter="Source Files(*.C;*.CPP;*.H;*.HPP)\0*.C;*.CPP;*.H;*.HPP\0Document(*.DOC;*.HTML)\0*.DOC;*.HTML\0All(*.*)\0*.*\0";
    dlg.m_ofn.nFilterIndex=1;
	if(dlg.DoModal() == IDOK)
	{
		szStr="File Name: ";
		szStr+=dlg.GetFileName();
		AfxMessageBox(szStr);
		szStr.Empty();
		szStr="Path Name: ";
		szStr+=dlg.GetPathName();
		AfxMessageBox(szStr);
	}
}

void CCDBDoc::OnFiledialogboxCustomizedfileopen() 
{
	CFileDialog	dlg(TRUE);
	CString szStr;
	POSITION posi;
	LPSTR lpstr;

    dlg.m_ofn.lpstrFilter="Source Files(*.C;*.CPP;*.H;*.HPP)\0*.C;*.CPP;*.H;*.HPP\0Document(*.DOC;*.HTML)\0*.DOC;*.HTML\0All(*.*)\0*.*\0";
    dlg.m_ofn.nFilterIndex=1; 
	dlg.m_ofn.lpstrCustomFilter="DIB Files(*.BMP)\0*.BMP\0";
	dlg.m_ofn.nMaxCustFilter=26;
	dlg.m_ofn.Flags|=OFN_ALLOWMULTISELECT | OFN_SHOWHELP;
	dlg.m_ofn.Flags&=~OFN_HIDEREADONLY;
	dlg.m_ofn.lpstrTitle="Explorer Style Open";
	if(dlg.DoModal() == IDOK)
	{
		szStr="File Name: ";
		lpstr=dlg.m_ofn.lpstrFile+dlg.m_ofn.nFileOffset;
		while(*lpstr != '\0')
		{
			szStr+=lpstr;
			szStr+="; ";
			lpstr+=strlen(lpstr);
			lpstr++;
		}
		AfxMessageBox(szStr);
		szStr.Empty();
		szStr="Path Name: ";
		posi=dlg.GetStartPosition();
		while(posi != NULL)
		{
			szStr+=dlg.GetNextPathName(posi);
			szStr+="; ";
		}
		AfxMessageBox(szStr);
	}	
}

void CCDBDoc::OnFiledialogboxCustomizefileopenold() 
{
	CFileDialog	dlg(TRUE);
	CString szStr;
	POSITION posi;
	LPSTR lpstr;
	LPSTR lpstrNx;
	char buf[256];

    dlg.m_ofn.lpstrFilter="Source Files(*.C;*.CPP;*.H;*.HPP)\0*.C;*.CPP;*.H;*.HPP\0Document(*.DOC;*.HTML)\0*.DOC;*.HTML\0All(*.*)\0*.*\0";
    dlg.m_ofn.nFilterIndex=1; 
	dlg.m_ofn.lpstrCustomFilter="DIB Files(*.BMP)\0*.BMP\0";
	dlg.m_ofn.nMaxCustFilter=26;
	dlg.m_ofn.Flags|=OFN_ALLOWMULTISELECT | OFN_SHOWHELP;
	dlg.m_ofn.Flags&=~OFN_EXPLORER;
	dlg.m_ofn.Flags&=~OFN_HIDEREADONLY;
	dlg.m_ofn.Flags&=~OFN_LONGNAMES;
	dlg.m_ofn.lpstrTitle="Old Style Open";
	if(dlg.DoModal() == IDOK)
	{
		szStr="File Name: ";
		lpstr=dlg.m_ofn.lpstrFile+dlg.m_ofn.nFileOffset;
		while(TRUE)
		{
			lpstrNx=strchr(lpstr, ' ');
			if(lpstrNx == NULL)
			{
				szStr+=lpstr;
				break;
			}
			else
			{
				memset(buf, 0, 256);
				strncpy(buf, lpstr, lpstrNx-lpstr);
				szStr+=buf;
			}
			szStr+="; ";
			lpstr=lpstrNx;
			lpstr++;
		}
		AfxMessageBox(szStr);
		szStr.Empty();
		szStr="Path Name: ";
		posi=dlg.GetStartPosition();
		while(posi != NULL)
		{
			szStr+=dlg.GetNextPathName(posi);
			szStr+="; ";
		}
		AfxMessageBox(szStr);
	}	
}

void CCDBDoc::OnFiledialogboxDirdialog() 
{
	BROWSEINFO bi;
	char szBuf[MAX_PATH];
	LPITEMIDLIST pidl;
	LPMALLOC pMalloc;
	CString szStr;

	if(::SHGetMalloc(&pMalloc) == NOERROR)
	{
		bi.hwndOwner=NULL;
		bi.pidlRoot=NULL;
		bi.pszDisplayName=szBuf;
		bi.lpszTitle=_T("Select Directory");
		bi.ulFlags=BIF_RETURNFSANCESTORS | BIF_RETURNONLYFSDIRS;
		bi.lpfn=NULL;
		bi.lParam=0;
		if((pidl=::SHBrowseForFolder(&bi)) != NULL)
		{
			if(::SHGetPathFromIDList(pidl, szBuf))
			{ 
				szStr="Selected Directory: ";
				szStr+=szBuf;
				AfxMessageBox(szStr);
			}
			pMalloc->Free(pidl);
		}
		pMalloc->Release();
	}
}

void CCDBDoc::OnFiledialogboxDirdialogold() 
{
	CString szStr;
    MCFileDialog  dlg
	(
		FALSE,
		NULL,
		NULL, 
		OFN_SHOWHELP | OFN_HIDEREADONLY | 
		OFN_OVERWRITEPROMPT | OFN_ENABLETEMPLATE,
		NULL, 
		AfxGetApp()->m_pMainWnd
	);
    dlg.m_ofn.hInstance=AfxGetInstanceHandle();
    dlg.m_ofn.lpTemplateName=MAKEINTRESOURCE(IDD_DIR);
	dlg.m_ofn.Flags&=~OFN_EXPLORER;
	dlg.m_ofn.Flags&=~OFN_LONGNAMES;
	dlg.m_ofn.lpstrTitle="Directory Dialog";
    if(dlg.DoModal() == IDOK)
    {
		dlg.m_ofn.lpstrFile[dlg.m_ofn.nFileOffset-1]=0;
		szStr="Selected Dir: ";
		szStr+=dlg.m_ofn.lpstrFile;
		AfxMessageBox(szStr);
    }	
}

void CCDBDoc::OnFiledialogboxCustomfiledlg() 
{
	MCCusFileDialog dlg(TRUE);

	dlg.m_ofn.lpTemplateName=MAKEINTRESOURCE(IDD_COMDLG32);
	dlg.m_ofn.Flags|=OFN_ENABLETEMPLATE;

	dlg.DoModal();
}

void CCDBDoc::ColorDialog(COLORREF colorInit, DWORD dwFlags)
{
	CColorDialog dlg(colorInit);
	COLORREF color[16];
	COLORREF colorRlt;
	CString szStr;
	CString szStrRGB;
	int i;

	dlg.m_cc.Flags|=dwFlags;
	for(i=0; i<16; i++)
	{
		color[i]=RGB
		(
			(i/4+1)*64-1,
			((i/2)%2 == 0) ? 127:255,
			(i%2 == 0) ? 127:255
		);
	}
	dlg.m_cc.lpCustColors=color;
	if(dlg.DoModal() == IDOK)
	{
		colorRlt=dlg.GetColor();
		szStr.Format
		(
			"Color returned by GetColor:\n\tR=%d, G=%d, B=%d",
			(int)GetRValue(colorRlt),
			(int)GetGValue(colorRlt),
			(int)GetBValue(colorRlt)
		);
		AfxMessageBox(szStr);
		szStr.Empty();
		szStr="Custom colors:";
		for(i=0; i<16; i++)
		{
			szStrRGB.Empty();
			szStrRGB.Format
			(
				"\n\tColor(%d) R=%d, G=%d, B=%d",
				i,
				(int)GetRValue(color[i]),
				(int)GetGValue(color[i]),
				(int)GetBValue(color[i])
			);
			szStr+=szStrRGB;
		}
		AfxMessageBox(szStr);
	}
}

void CCDBDoc::OnColordialogboxInitialize() 
{
	ColorDialog(RGB(255, 0, 0));
}

void CCDBDoc::OnColordialogboxDisablefullopen() 
{
	ColorDialog(RGB(0, 255, 0), CC_PREVENTFULLOPEN);
}

void CCDBDoc::OnColordialogboxFullopen() 
{
	ColorDialog(RGB(0, 255, 0), CC_FULLOPEN);
}

void CCDBDoc::OnColordialogboxChoosebasecolor() 
{
	CColorDialog dlg;
	
	dlg.m_cc.Flags|=CC_ENABLETEMPLATE;
	dlg.m_cc.Flags|=CC_FULLOPEN;
	dlg.m_cc.hInstance=(HWND)AfxGetInstanceHandle();
	dlg.m_cc.lpTemplateName="CHOOSECOLOR";
	dlg.DoModal();
}

void CCDBDoc::OnColordialogboxChoosecostumcolor() 
{
	CColorDialog dlg;
	int i;
	COLORREF color[16];

	for(i=0; i<16; i++)
	{
		color[i]=RGB
		(
			(i/4+1)*64-1,
			((i/2)%2 == 0) ? 127:255,
			(i%2 == 0) ? 127:255
		);
	}
	dlg.m_cc.lpCustColors=color;
	dlg.m_cc.Flags|=CC_ENABLETEMPLATE;
	dlg.m_cc.Flags|=CC_FULLOPEN;
	dlg.m_cc.hInstance=(HWND)AfxGetInstanceHandle();
	dlg.m_cc.lpTemplateName="CHOOSECUSCOLOR";
	dlg.DoModal();
}

void CCDBDoc::OnFontdialogboxInitialize() 
{
	LOGFONT lf;
	CFontDialog dlg;
	CString szStr;
	COLORREF color;

	memset(&lf, 0, sizeof(LOGFONT));
	lf.lfItalic=TRUE;
	lf.lfUnderline=TRUE;
	lf.lfStrikeOut=TRUE;
	lf.lfWeight=FW_BOLD;
	strcpy(lf.lfFaceName, "Times New Roman");

	dlg.m_cf.rgbColors=RGB(255, 255, 0);
	dlg.m_cf.Flags|=CF_LIMITSIZE|CF_EFFECTS|CF_INITTOLOGFONTSTRUCT;
	dlg.m_cf.nSizeMin=20;
	dlg.m_cf.nSizeMax=48;
	dlg.m_cf.lpLogFont=&lf;
	if(dlg.DoModal() == IDOK)
	{
		color=dlg.GetColor();
		szStr.Format("Font Color: R=%d, G=%d, B=%d", 
					  GetRValue(color), GetGValue(color), GetBValue(color));
		szStr+="\nFace Name: ";
		szStr+=dlg.GetFaceName();
		if(dlg.IsItalic() == TRUE)szStr+="\nFont is italic";
		if(dlg.IsUnderline() == TRUE)szStr+="\nFont is underlined";
		if(dlg.IsStrikeOut() == TRUE)szStr+="\nFont is strike out";
		if(dlg.IsBold())szStr+="\nFont is bolded";
		AfxMessageBox(szStr);
	}
}
