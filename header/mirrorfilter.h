// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.

/////////////////////////////////////////////////////////////////////////////
// CMirrorFilter wrapper class

class CMirrorFilter : public COleDispatchDriver
{
public:
	CMirrorFilter() {}		// Calls COleDispatchDriver default constructor
	CMirrorFilter(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CMirrorFilter(const CMirrorFilter& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	long GetDirection();
	void SetDirection(long nNewValue);
};
