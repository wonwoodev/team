// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class CTeePoint2D;

/////////////////////////////////////////////////////////////////////////////
// CLevelSegment wrapper class

class CLevelSegment : public COleDispatchDriver
{
public:
	CLevelSegment() {}		// Calls COleDispatchDriver default constructor
	CLevelSegment(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CLevelSegment(const CLevelSegment& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	long GetNumPoints();
	CTeePoint2D GetPoints(long Index);
};