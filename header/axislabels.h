// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class CTeeFont;
class CTeeCustomShape;
class CAxisLabelsItem;

/////////////////////////////////////////////////////////////////////////////
// CAxisLabels wrapper class

class CAxisLabels : public COleDispatchDriver
{
public:
	CAxisLabels() {}		// Calls COleDispatchDriver default constructor
	CAxisLabels(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CAxisLabels(const CAxisLabels& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	long GetAngle();
	void SetAngle(long nNewValue);
	BOOL GetVisible();
	void SetVisible(BOOL bNewValue);
	CString GetDateTimeFormat();
	void SetDateTimeFormat(LPCTSTR lpszNewValue);
	CTeeFont GetFont();
	CString FormattedValue(double SomeValue);
	long GetPos();
	long Height(double SomeValue);
	long MaxWidth();
	BOOL GetOnAxis();
	void SetOnAxis(BOOL bNewValue);
	BOOL GetRoundFirstLabel();
	void SetRoundFirstLabel(BOOL bNewValue);
	long GetSeparation();
	void SetSeparation(long nNewValue);
	long GetSize();
	void SetSize(long nNewValue);
	long GetStyle();
	void SetStyle(long nNewValue);
	CString GetValueFormat();
	void SetValueFormat(LPCTSTR lpszNewValue);
	long Width(double SomeValue);
	BOOL GetMultiline();
	void SetMultiline(BOOL bNewValue);
	void TeeSplitInLines(BSTR* St, LPCTSTR Separator);
	BOOL GetExponent();
	void SetExponent(BOOL bNewValue);
	long GetAlign();
	void SetAlign(long nNewValue);
	CTeeCustomShape GetFormat();
	long Add(double Value, LPCTSTR Text);
	CAxisLabelsItem GetItem(long Index);
	void Clear();
	long Count();
	BOOL GetAlternate();
	void SetAlternate(BOOL bNewValue);
	BOOL GetAutomatic();
	void SetAutomatic(BOOL bNewValue);
	BOOL GetBehind();
	void SetBehind(BOOL bNewValue);
};