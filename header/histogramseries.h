// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class CPen1;
class CBrush1;

/////////////////////////////////////////////////////////////////////////////
// CHistogramSeries wrapper class

class CHistogramSeries : public COleDispatchDriver
{
public:
	CHistogramSeries() {}		// Calls COleDispatchDriver default constructor
	CHistogramSeries(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CHistogramSeries(const CHistogramSeries& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	CPen1 GetLinesPen();
	long GetTransparency();
	void SetTransparency(long nNewValue);
	CPen1 GetLinePen();
	CBrush1 GetBrush();
	double GetYOrigin();
	void SetYOrigin(double newValue);
	BOOL GetUseYOrigin();
	void SetUseYOrigin(BOOL bNewValue);
};
