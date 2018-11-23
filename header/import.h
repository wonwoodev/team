// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.

/////////////////////////////////////////////////////////////////////////////
// CImport wrapper class

class CImport : public COleDispatchDriver
{
public:
	CImport() {}		// Calls COleDispatchDriver default constructor
	CImport(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CImport(const CImport& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	void LoadFromFile(LPCTSTR FileName);
	void LoadFromURL(LPCTSTR URL);
	void LoadFromStream(const VARIANT& AStream);
	void LoadFromBase64Stream(const VARIANT& AStream);
	BOOL GetV5TeeCompatible();
	void SetV5TeeCompatible(BOOL bNewValue);
};
