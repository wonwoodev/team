// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.

/////////////////////////////////////////////////////////////////////////////
// CTeeListBoxSection wrapper class

class CTeeListBoxSection : public COleDispatchDriver
{
public:
	CTeeListBoxSection() {}		// Calls COleDispatchDriver default constructor
	CTeeListBoxSection(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CTeeListBoxSection(const CTeeListBoxSection& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	long GetWidth();
	void SetWidth(long nNewValue);
	BOOL GetVisible();
	void SetVisible(BOOL bNewValue);
};
