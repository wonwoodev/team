// GlassDetectView.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "PyroSoftM.h"
#include "MainFrm.h"
#include "ChildFrm.h"
#include "ResultView.h"
#include <time.h>

#define MAX_X_COUNT 60

// CResultView

IMPLEMENT_DYNCREATE(CResultView, CView)

CResultView::CResultView()
{
	m_Dlg_H = 100;
	pDoc = NULL;

	m_XCount = 0;
	m_XCount_modeThr = 0;
	fTime = 0;
}

CResultView::~CResultView()
{
}

BEGIN_MESSAGE_MAP(CResultView, CView)
	ON_WM_CREATE()
	ON_WM_SIZE()	
	ON_WM_MOUSEMOVE()
	ON_WM_SETCURSOR()
END_MESSAGE_MAP()


// CResultView 진단입니다.

#ifdef _DEBUG
void CResultView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CResultView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CResultView 메시지 처리기입니다.
int CResultView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	CRect rectDummy;
	rectDummy.SetRectEmpty();
		
	if(m_ResultDlg.GetSafeHwnd() == 0)
	{		
		if(!m_ResultDlg.Create(IDD_RESULT, this))
			return FALSE;	
		
		m_ResultDlg.ModifyStyle(0,WS_VISIBLE, 0);

		AdjustLayout();
	}

	return 0;
}

void CResultView::AdjustLayout()
{	
	if (GetSafeHwnd() == NULL)
	{
		return;
	}

	int preScaleWidth = theApp.nScaleDlgWidth - theApp.nResultDlgWidth;

	CRect rectClient;
	GetClientRect(rectClient);

	int dlgH = 0;
	
	if (theApp.adjust_count > 4)
	{
		CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
		CChildFrame *pChild = (CChildFrame *)pFrame->GetActiveFrame();

		if (rectClient.Height() == 0) return;
		if (rectClient.Width() == 0) return;

		theApp.nResultDlgWidth = rectClient.Width();
		theApp.nScaleDlgWidth = theApp.nResultDlgWidth + preScaleWidth;

		int nLeft = theApp.m_childFrmWidth - theApp.nResultDlgWidth - 20;

		if (nLeft <= 0) return;

		pChild->m_wndSplitter.SetColumnInfo(0, nLeft, 100);
		pChild->m_wndSplitter.SetColumnInfo(1, theApp.nResultDlgWidth, 100);


		int nScaleLeft = theApp.m_childFrmWidth - theApp.nScaleDlgWidth - 20;

		if (nScaleLeft <= 0) return;

		pChild->m_ScaleSplitter.SetColumnInfo(0, nScaleLeft, 20);
		pChild->m_ScaleSplitter.SetColumnInfo(1, theApp.nScaleDlgWidth, 20);
		pChild->m_ScaleSplitter.RecalcLayout();
	}
	else if(theApp.adjust_count == 4)
		theApp.adjust_count++;

	m_ResultDlg.SetWindowPos(NULL, rectClient.left,
		rectClient.top + dlgH,
		rectClient.Width(),
		rectClient.Height() - dlgH,
		SWP_NOACTIVATE | SWP_NOZORDER);
	
	//m_ResultDlg.m_Result_Tap.SetWindowPos(NULL, 0, 0, rectClient.Width(), rectClient.Height()*0.9, SWP_NOZORDER);
	//m_ResultDlg.m_MaxTabDlg.SetWindowPos(NULL, 5, 25, rectClient.Width() - 12, rectClient.Height()*0.9 - 33, SWP_NOZORDER);
	//m_ResultDlg.m_MinTabDlg.SetWindowPos(NULL, 5, 25, rectClient.Width() - 12, rectClient.Height()*0.9 - 33, SWP_NOZORDER);
	//m_ResultDlg.m_AvgTabDlg.SetWindowPos(NULL, 5, 25, rectClient.Width() - 12, rectClient.Height()*0.9 - 33, SWP_NOZORDER);

	//m_ResultDlg.m_ZoneInf_btn.SetWindowPos(NULL, 5, rectClient.Height() - 35 - 10, 100, 35, SWP_NOZORDER);
	//m_ResultDlg.m_Coefficient_btn.SetWindowPos(NULL, 110, rectClient.Height() - 35 - 10, 100, 35, SWP_NOZORDER);
}

void CResultView::OnSize(UINT nType, int cx, int cy)
{
	if(GetSafeHwnd()==NULL) return;

	CView::OnSize(nType, cx, cy);

	AdjustLayout();
}


///////////////////////////////////////////////////////////////////////////////////////////
void CResultView::OnDraw(CDC* pDC)
{
	return;
}


void CResultView::CheckROICount(int ROI_count, int cROI_count)
{
	CString str;

	if (ROI_count < cROI_count)
	{
		for (int i = ROI_count; i < cROI_count; i++)
		{
			str.Format("#%d", i + 1);
			m_ResultDlg.m_MaxTabDlg.m_Max_Chart.AddSeries(0);
			m_ResultDlg.m_MaxTabDlg.m_Max_Chart.Series(i).SetTitle(str);
			m_ResultDlg.m_MaxTabDlg.m_Max_Chart.Series(i).SetLegendTitle(str);
			m_ResultDlg.m_MaxTabDlg.m_Max_Chart.Series(i).SetColor(ColorRef(i));
			m_ResultDlg.m_MinTabDlg.m_Min_Chart.AddSeries(0);
			m_ResultDlg.m_MinTabDlg.m_Min_Chart.Series(i).SetTitle(str);
			m_ResultDlg.m_MinTabDlg.m_Min_Chart.Series(i).SetLegendTitle(str);
			m_ResultDlg.m_MinTabDlg.m_Min_Chart.Series(i).SetColor(ColorRef(i));
			m_ResultDlg.m_AvgTabDlg.m_Avg_Chart.AddSeries(0);
			m_ResultDlg.m_AvgTabDlg.m_Avg_Chart.Series(i).SetTitle(str);
			m_ResultDlg.m_AvgTabDlg.m_Avg_Chart.Series(i).SetLegendTitle(str);
			m_ResultDlg.m_AvgTabDlg.m_Avg_Chart.Series(i).SetColor(ColorRef(i));
		}
	}
	else if (ROI_count > cROI_count)
	{
		for (int i = ROI_count - 1; i >= cROI_count; i--)
		{
			m_ResultDlg.m_MaxTabDlg.m_Max_Chart.Series(i).Clear();
			m_ResultDlg.m_MinTabDlg.m_Min_Chart.Series(i).Clear();
			m_ResultDlg.m_AvgTabDlg.m_Avg_Chart.Series(i).Clear();
			m_ResultDlg.m_MaxTabDlg.m_Max_Chart.RemoveSeries(i);
			m_ResultDlg.m_MinTabDlg.m_Min_Chart.RemoveSeries(i);
			m_ResultDlg.m_AvgTabDlg.m_Avg_Chart.RemoveSeries(i);
		}
	}
}


void CResultView::UpdateResult()		
{
	CString str;

	if (pDoc->m_ROI_check_flag)
	{
		CheckROICount(pDoc->m_comp_ROICount, pDoc->m_ROICount);

		pDoc->m_ROI_check_flag = false;
	}

	if (pDoc->m_OpenMode != 1)			// Online, Simulation 인 경우에만
	{
		if (theApp.m_bLoggingRunning)
		{
			m_ResultDlg.m_ZoneInf_btn.EnableWindow(FALSE);
			m_ResultDlg.m_Coefficient_btn.EnableWindow(FALSE);
		}
		else
		{
			m_ResultDlg.m_ZoneInf_btn.EnableWindow(TRUE);
			m_ResultDlg.m_Coefficient_btn.EnableWindow(TRUE);
		}
	}


	// 나탕 최고 온도 Trend
	if (pDoc->m_ResultData.TMin[0] > 0.0f && theApp.m_bLoggingRunning  || pDoc->m_OpenMode == 2 || pDoc->m_OpenMode == 1 )
	{
		if (pDoc->m_OpenMode == 3)
		{
			if (theApp.m_TchartFlag)
				m_XCount_modeThr++;

			ProcessTime.Format(_T("%d%d:%d%d:%d%d"),
				(m_XCount_modeThr / 36000) % 10, (m_XCount_modeThr / 3600) % 10,	// 시
				(m_XCount_modeThr / 600) % 6, (m_XCount_modeThr / 60) % 10,			// 분
				(m_XCount_modeThr / 10) % 6, m_XCount_modeThr % 10);				// 초
		}
		else if (pDoc->m_OpenMode == 2)
		{
			ProcessTime.Format(_T("%d%d:%d%d:%d%d"),
				(m_XCount / 36000) % 10, (m_XCount / 3600) % 10,	// 시
				(m_XCount / 600) % 6, (m_XCount / 60) % 10,			// 분
				(m_XCount / 10) % 6, m_XCount % 10);				// 초
		}
		else
			ProcessTime.Format(_T("%d"), pDoc->m_IdxDS);

		if (pDoc->m_ChartFlag)
		{
			for (int i = 0; i < pDoc->m_ROICount; i++)
			{
				m_ResultDlg.m_MaxTabDlg.m_Max_Chart.Series(i).Clear();
				m_ResultDlg.m_MinTabDlg.m_Min_Chart.Series(i).Clear();
				m_ResultDlg.m_AvgTabDlg.m_Avg_Chart.Series(i).Clear();
			}

			pDoc->m_ChartFlag = false;
			m_XCount = 0;
			m_XCount_modeThr = 0;
		}
		else
		{
			for (int i = 0; i < pDoc->m_ROICount; i++)
			{
				if (pDoc->m_OpenMode == 3)
				{
					if (pDoc->m_ResultData.TMax[i] != 0.0f)
						m_ResultDlg.m_MaxTabDlg.m_Max_Chart.Series(i).AddXY(m_XCount, pDoc->m_ResultData.TMax[i], ProcessTime, ColorRef(i));
					if (pDoc->m_ResultData.TMin[i] != 0.0f)
						m_ResultDlg.m_MinTabDlg.m_Min_Chart.Series(i).AddXY(m_XCount, pDoc->m_ResultData.TMin[i], ProcessTime, ColorRef(i));
					if (pDoc->m_ResultData.TAvg[i] != 0.0f)
						m_ResultDlg.m_AvgTabDlg.m_Avg_Chart.Series(i).AddXY(m_XCount, pDoc->m_ResultData.TAvg[i], ProcessTime, ColorRef(i));
				}
				else 
				{
					if (pDoc->m_ResultData.TMax[i] != 0.0f)
						m_ResultDlg.m_MaxTabDlg.m_Max_Chart.Series(i).AddXY(m_XCount, pDoc->m_ResultData.TMax[i], ProcessTime, ColorRef(i));
					if (pDoc->m_ResultData.TMin[i] != 0.0f)
						m_ResultDlg.m_MinTabDlg.m_Min_Chart.Series(i).AddXY(m_XCount, pDoc->m_ResultData.TMin[i], ProcessTime, ColorRef(i));
					if (pDoc->m_ResultData.TAvg[i] != 0.0f)
						m_ResultDlg.m_AvgTabDlg.m_Avg_Chart.Series(i).AddXY(m_XCount, pDoc->m_ResultData.TAvg[i], ProcessTime, ColorRef(i));
				}
			}
			m_XCount++;
		}

		theApp.m_TchartFlag = false;
	}
}

COLORREF CResultView::ColorRef(int series_idx)
{
	BYTE R = 0, G = 0, B = 0;
	switch (series_idx)
	{
	case 0:		// 빨
		R = 255;
		break;
	case 1:		// 주
		R = 255;
		G = 153;
		break;
	case 2:		// 노
		R = 255;
		G = 255;
		break;
	case 3:		// 초
		G = 255;
		break;
	case 4:		// 파
		B = 255;
		break;
	case 5:		// 남
		B = 51;
		break;
	case 6:		// 보
		R = 102;
		B = 255;
		break;
	case 7:		// 빨약
		R = 255;
		G = 102;
		B = 102;
		break;
	case 8:		// 주약
		R = 255;
		G = 204;
		B = 102;
		break;
	case 9:		// 노약
		R = 255;
		G = 225;
		B = 153;
		break;
	case 10:	// 초약
		R = 153;
		G = 225;
		B = 204;
		break;
	default:
		srand((unsigned)time(NULL));
		R = rand() % 255;
		srand((unsigned)time(NULL));
		G = rand() % 255;
		srand((unsigned)time(NULL));
		B = rand() % 255;
		break;
	}
	return RGB(R, G, B);
}

void CResultView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	if(lHint<2 ) return;

	if(lHint<4)	{
		//실제 Updata를 동작시키는 부분
		UpdateResult();
	}

	switch (lHint)
	{
	case 7:
		CalAllResult();

		UpdateResult();

		m_ResultDlg.UpdateData(FALSE);
		break;
	}

}

void CResultView::CalAllResult()
{
	pDoc->CalMeasurement(pDoc->PPointArr.GetCount() , pDoc->sizeX, pDoc->sizeY, pDoc->pFrameBuffer);
}

void CResultView::OnMouseMove(UINT nFlags, CPoint point)
{
	CView::OnMouseMove(nFlags, point);
	return;
}


BOOL CResultView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	return CView::OnSetCursor(pWnd, nHitTest, message);
}

//ResultView의 파라미터 값 초기화
void CResultView::InitROIData()			
{
	CString str;
	
	setFont();

	for (int i = 0; i < pDoc->m_ROICount; i++)
	{
		str.Format("%d", i+1);
		m_ResultDlg.m_MaxTabDlg.m_Max_Chart.AddSeries(0);
		m_ResultDlg.m_MaxTabDlg.m_Max_Chart.Series(i).SetTitle(str);
		m_ResultDlg.m_MaxTabDlg.m_Max_Chart.Series(i).SetLegendTitle(str);
		m_ResultDlg.m_MaxTabDlg.m_Max_Chart.Series(i).SetColor(ColorRef(i));
		m_ResultDlg.m_MinTabDlg.m_Min_Chart.AddSeries(0);
		m_ResultDlg.m_MinTabDlg.m_Min_Chart.Series(i).SetTitle(str);
		m_ResultDlg.m_MinTabDlg.m_Min_Chart.Series(i).SetLegendTitle(str);
		m_ResultDlg.m_MinTabDlg.m_Min_Chart.Series(i).SetColor(ColorRef(i));
		m_ResultDlg.m_AvgTabDlg.m_Avg_Chart.AddSeries(0);
		m_ResultDlg.m_AvgTabDlg.m_Avg_Chart.Series(i).SetTitle(str);
		m_ResultDlg.m_AvgTabDlg.m_Avg_Chart.Series(i).SetLegendTitle(str);
		m_ResultDlg.m_AvgTabDlg.m_Avg_Chart.Series(i).SetColor(ColorRef(i));
	}

	int k = m_ResultDlg.m_MaxTabDlg.m_Max_Chart.GetSeriesCount();

	// init for IRDX file open
	if (pDoc->m_OpenMode == 1)
	{
		m_ResultDlg.m_ZoneInf_btn.EnableWindow(FALSE);
		m_ResultDlg.m_Coefficient_btn.EnableWindow(FALSE);
	}

	m_ResultDlg.UpdateData(FALSE);
}

void CResultView::setFont()
{
	m_bFont.CreateFontA(33, 13, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY, DEFAULT_PITCH, _T("고딕체"));
	m_mFont.CreateFontA(27, 9, 0, 0, FW_SEMIBOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY, DEFAULT_PITCH, _T("고딕체"));
	m_sFont.CreateFontA(21, 7, 0, 0, FW_SEMIBOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY, DEFAULT_PITCH, _T("고딕체"));

}