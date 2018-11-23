// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class CBrush1;
class CGradient;
class CPen1;

/////////////////////////////////////////////////////////////////////////////
// CSeriesBandTool wrapper class

class CSeriesBandTool : public COleDispatchDriver
{
public:
	CSeriesBandTool() {}		// Calls COleDispatchDriver default constructor
	CSeriesBandTool(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CSeriesBandTool(const CSeriesBandTool& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	VARIANT GetSeries();
	void SetSeries(const VARIANT& newValue);
	CBrush1 GetBrush();
	BOOL GetDrawBehindSeries();
	void SetDrawBehindSeries(BOOL bNewValue);
	CGradient GetGradient();
	CPen1 GetPen();
	VARIANT GetSeries2();
	void SetSeries2(const VARIANT& newValue);
	long GetTransparency();
	void SetTransparency(long nNewValue);
};
