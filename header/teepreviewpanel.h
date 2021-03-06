// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class CTeePanelsList;
class CGradient;
class CPen1;
class CCanvas;
class CTeeRect;

/////////////////////////////////////////////////////////////////////////////
// CTeePreviewPanel wrapper class

class CTeePreviewPanel : public CWnd
{
protected:
	DECLARE_DYNCREATE(CTeePreviewPanel)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0xce6d7ff1, 0x8a92, 0x4cd4, { 0x99, 0x47, 0xf3, 0xd1, 0xda, 0xed, 0x73, 0xf } };
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

// Operations
public:
	void SetChart(LPDISPATCH newValue);
	void SetChartLink(long nNewValue);
	void AboutBox();
	BOOL GetAllowResize();
	void SetAllowResize(BOOL bNewValue);
	BOOL GetAllowMove();
	void SetAllowMove(BOOL bNewValue);
	BOOL GetAsBitmap();
	void SetAsBitmap(BOOL bNewValue);
	BOOL GetDragImage();
	void SetDragImage(BOOL bNewValue);
	long GetOrientation();
	void SetOrientation(long nNewValue);
	unsigned long GetPaperColor();
	void SetPaperColor(unsigned long newValue);
	unsigned long GetShadowColor();
	void SetShadowColor(unsigned long newValue);
	long GetShadowSize();
	void SetShadowSize(long nNewValue);
	BOOL GetShowImage();
	void SetShowImage(BOOL bNewValue);
	CString GetTitle();
	void SetTitle(LPCTSTR lpszNewValue);
	void Repaint();
	CTeePanelsList GetPanels();
	void AddChart(LPDISPATCH Value);
	CGradient GetGradient();
	CPen1 GetMargins();
	void PrintPage();
	void AddChartLink(long Value);
	CCanvas GetCanvas();
	CTeeRect GetPaperRect();
	void ShowEditor();
};
