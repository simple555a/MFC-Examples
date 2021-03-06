///////////////////////////////////////////////////////////////////
// Header  : DV_DOC.H
//
// Purpose : Interface for the CDocView2Doc class.
//
// Author  : Rob McGregor - rob_mcgregor@compuserve.com
//
// Date    : 05-12-96
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
// The CDocView2Doc document class

class CDocView2Doc : public CDocument
{
protected: 
	DECLARE_DYNCREATE(CDocView2Doc)

public:
	CDocView2Doc();
   virtual ~CDocView2Doc();

   // Overrides
   virtual BOOL OnNewDocument();
};

///////////////////////////////////////////////////////////////////
