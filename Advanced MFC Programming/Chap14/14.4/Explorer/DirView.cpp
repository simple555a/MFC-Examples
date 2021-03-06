#include "stdafx.h"
#include "Explorer.h"
#include "DirView.h"
#include <direct.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CDirView, CTreeView)

CDirView::CDirView()
{
}

CDirView::~CDirView()
{
}


BEGIN_MESSAGE_MAP(CDirView, CTreeView)
	//{{AFX_MSG_MAP(CDirView)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CDirView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
}

#ifdef _DEBUG
void CDirView::AssertValid() const
{
	CTreeView::AssertValid();
}

void CDirView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif

void CDirView::OnInitialUpdate() 
{
	TV_INSERTSTRUCT tvInsertStruct;
	HTREEITEM hTreeItem;
	CImageList *pilCtrl;
	CBitmap bmp;
	char buffer[MAX_COMPUTERNAME_LENGTH+1];
	DWORD dwSize=MAX_COMPUTERNAME_LENGTH+1;
	LONG lStyleOld;
	int drive, curdrive;

	pilCtrl=new CImageList();
	pilCtrl->Create(BMP_SIZE_X, BMP_SIZE_Y, ILC_MASK, 6, 0);
	
	bmp.LoadBitmap(IDB_BITMAP_DESKTOP);
	pilCtrl->Add(&bmp, RGB(255, 255, 255));
	bmp.DeleteObject();
	
	bmp.LoadBitmap(IDB_BITMAP_COMPUTER);
	pilCtrl->Add(&bmp, RGB(255, 255, 255));
	bmp.DeleteObject();

	bmp.LoadBitmap(IDB_BITMAP_HARD);
	pilCtrl->Add(&bmp, RGB(255, 255, 255));
	bmp.DeleteObject();

	bmp.LoadBitmap(IDB_BITMAP_FLOOPY);
	pilCtrl->Add(&bmp, RGB(255, 255, 255));
	bmp.DeleteObject();

	bmp.LoadBitmap(IDB_BITMAP_CLOSEFOLDER);
	pilCtrl->Add(&bmp, RGB(255, 255, 255));
	bmp.DeleteObject();

	bmp.LoadBitmap(IDB_BITMAP_OPENFOLDER);
	pilCtrl->Add(&bmp, RGB(255, 255, 255));
	bmp.DeleteObject();

	pilCtrl->SetBkColor(RGB(255, 255, 255));
	GetTreeCtrl().SetImageList(pilCtrl, TVSIL_NORMAL);

	lStyleOld=::GetWindowLong(GetTreeCtrl().GetSafeHwnd(), GWL_STYLE);
	lStyleOld|=TVS_HASLINES | TVS_LINESATROOT | TVS_HASBUTTONS;
	::SetWindowLong(GetTreeCtrl().GetSafeHwnd(), GWL_STYLE, lStyleOld);

	memset(&tvInsertStruct, 0, sizeof(TV_INSERTSTRUCT));

	tvInsertStruct.hParent=NULL;
	tvInsertStruct.hInsertAfter=TVI_LAST;
	tvInsertStruct.item.iImage=0;
	tvInsertStruct.item.iSelectedImage=0;
	tvInsertStruct.item.pszText="Desktop";
	tvInsertStruct.item.mask=TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_TEXT | TVIF_STATE;
	tvInsertStruct.item.stateMask|=TVIS_EXPANDED;
	tvInsertStruct.item.state|=TVIS_EXPANDED;

	hTreeItem=GetTreeCtrl().InsertItem(&tvInsertStruct);
	ASSERT(hTreeItem);

	::GetComputerName(buffer, &dwSize);

	tvInsertStruct.hParent=hTreeItem;
	tvInsertStruct.hInsertAfter=TVI_LAST;
	tvInsertStruct.item.mask=TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_TEXT | TVIF_STATE;
	tvInsertStruct.item.iImage=1;
	tvInsertStruct.item.iSelectedImage=1;
	tvInsertStruct.item.pszText=buffer;
	tvInsertStruct.item.stateMask|=TVIS_EXPANDED;
	tvInsertStruct.item.state|=TVIS_EXPANDED;

	hTreeItem=GetTreeCtrl().InsertItem(&tvInsertStruct);
	ASSERT(hTreeItem);

	curdrive=_getdrive();
	for(drive=1; drive <= 26; drive++)
	{
		if(!_chdrive(drive))
		{
			memset(buffer, 0, dwSize);
			buffer[0]=drive+'A'-1;
			buffer[1]=':';
			tvInsertStruct.hParent=hTreeItem;
			tvInsertStruct.hInsertAfter=TVI_LAST;
			tvInsertStruct.item.mask=TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_TEXT | TVIF_STATE;
			tvInsertStruct.item.iImage=2;
			tvInsertStruct.item.iSelectedImage=2;
			tvInsertStruct.item.pszText=buffer;
			tvInsertStruct.item.stateMask|=TVIS_EXPANDED;
			tvInsertStruct.item.state|=TVIS_EXPANDED;

			GetTreeCtrl().InsertItem(&tvInsertStruct);
		}
	}

	_chdrive( curdrive );

	CTreeView::OnInitialUpdate();
}

void CDirView::OnDestroy() 
{
	CImageList *pilCtrl;

	GetTreeCtrl().DeleteAllItems();
	pilCtrl=GetTreeCtrl().GetImageList(TVSIL_NORMAL);
	pilCtrl->DeleteImageList();
	delete pilCtrl;

	CTreeView::OnDestroy();
}
