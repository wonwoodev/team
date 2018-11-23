// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.

/////////////////////////////////////////////////////////////////////////////
// CChartAxisPen wrapper class

class CChartAxisPen : public COleDispatchDriver
{
public:
	CChartAxisPen() {}		// Calls COleDispatchDriver default constructor
	CChartAxisPen(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CChartAxisPen(const CChartAxisPen& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	unsigned long GetColor();
	void SetColor(unsigned long newValue);
	long GetWidth();
	void SetWidth(long nNewValue);
	long GetStyle();
	void SetStyle(long nNewValue);
	BOOL GetVisible();
	void SetVisible(BOOL bNewValue);
	long GetEndStyle();
	void SetEndStyle(long nNewValue);
	void ShowEditor(BOOL HideColor, LPCTSTR Title);
	long GetSmallSpace();
	void SetSmallSpace(long nNewValue);
	long GetMode();
	void SetMode(long nNewValue);
	void Show();
	void Hide();
	long GetLineMode();
	void SetLineMode(long nNewValue);
};
