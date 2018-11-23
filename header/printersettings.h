// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.

/////////////////////////////////////////////////////////////////////////////
// CPrinterSettings wrapper class

class CPrinterSettings : public COleDispatchDriver
{
public:
	CPrinterSettings() {}		// Calls COleDispatchDriver default constructor
	CPrinterSettings(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CPrinterSettings(const CPrinterSettings& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	short GetOrientation();
	void SetOrientation(short nNewValue);
	short GetPaperSize();
	void SetPaperSize(short nNewValue);
	short GetPaperLength();
	void SetPaperLength(short nNewValue);
	short GetPaperWidth();
	void SetPaperWidth(short nNewValue);
	short GetCopies();
	void SetCopies(short nNewValue);
	short GetPrintQuality();
	void SetPrintQuality(short nNewValue);
	short GetColor();
	void SetColor(short nNewValue);
	short GetDuplex();
	void SetDuplex(short nNewValue);
	short GetScale();
	void SetScale(short nNewValue);
	short GetDefaultSource();
	void SetDefaultSource(short nNewValue);
	short GetTTOption();
	void SetTTOption(short nNewValue);
	short GetCollate();
	void SetCollate(short nNewValue);
	long GetSpecVersion();
	void SetSpecVersion(long nNewValue);
	long GetDriverVersion();
	void SetDriverVersion(long nNewValue);
	long GetSize();
	void SetSize(long nNewValue);
	long GetDriverExtra();
	void SetDriverExtra(long nNewValue);
	long GetLogPixels();
	void SetLogPixels(long nNewValue);
	long GetFields();
	void SetFields(long nNewValue);
	long GetBitsPerPel();
	void SetBitsPerPel(long nNewValue);
	long GetPelsWidth();
	void SetPelsWidth(long nNewValue);
	long GetPelsHeight();
	void SetPelsHeight(long nNewValue);
	long GetDisplayFlags();
	void SetDisplayFlags(long nNewValue);
	long GetDisplayFrequency();
	void SetDisplayFrequency(long nNewValue);
	long GetICMMethod();
	void SetICMMethod(long nNewValue);
	long GetICMIntent();
	void SetICMIntent(long nNewValue);
	short GetYResolution();
	void SetYResolution(short nNewValue);
	CString GetDeviceName();
	void SetDeviceName(LPCTSTR lpszNewValue);
	CString GetFormName();
	void SetFormName(LPCTSTR lpszNewValue);
};
