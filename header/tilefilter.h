// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.

/////////////////////////////////////////////////////////////////////////////
// CTileFilter wrapper class

class CTileFilter : public COleDispatchDriver
{
public:
	CTileFilter() {}		// Calls COleDispatchDriver default constructor
	CTileFilter(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CTileFilter(const CTileFilter& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	long GetNumCols();
	void SetNumCols(long nNewValue);
	long GetNumRows();
	void SetNumRows(long nNewValue);
};
