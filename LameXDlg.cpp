// LameXDlg.cpp : implementation file
/*
** Copyright (C) 2000 David W. Swigger
**  
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 2 of the License, or
** (at your option) any later version.
** 
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
** 
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software 
** Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/


#include "stdafx.h"
#include "LameX.h"
#include "LameXDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLameXDlg dialog

CLameXDlg::CLameXDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLameXDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLameXDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLameXDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLameXDlg)
	DDX_Control(pDX, IDC_SCURFILE, m_stcCurFile);
	DDX_Control(pDX, IDC_PROGRESS1, m_Progress);
	DDX_Control(pDX, IDC_CHECKDELETESOURCES, m_chkDeleteSources);
	DDX_Control(pDX, IDC_TAB1, m_Tab);
	DDX_Control(pDX, IDC_LAMEENCODERXCTRL1, m_LameEncoderX);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CLameXDlg, CDialog)
	//{{AFX_MSG_MAP(CLameXDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, OnSelchangeTab1)
	ON_BN_CLICKED(IDC_BUTTONENCODE, OnEncodeFiles)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLameXDlg message handlers

BOOL CLameXDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// Set Up our Tab Ctrl
	m_Tab.DeleteAllItems();

	TCITEM tagItem;

	tagItem.mask = TCIF_TEXT;
	tagItem.pszText = "Encoder";
	m_Tab.InsertItem(0,&tagItem);
	tagItem.pszText = "Encoder Options";
	m_Tab.InsertItem(1,&tagItem);

	CRect rcRect;
	m_Tab.GetClientRect(&rcRect);

	rcRect.DeflateRect( 1, 22, 1, 1 );

	m_dlgOptions.Create(IDD_DIALOGOPTIONS,CWnd::FromHandle(m_Tab.m_hWnd));
	m_dlgOptions.MoveWindow(&rcRect,FALSE);
	m_dlgOptions.ShowWindow(SW_HIDE);
	m_dlgOptions.m_lpEncoder = &m_LameEncoderX;
	m_dlgOptions.SetAllFromEncoderX();

	m_dlgFilesToEncode.Create(IDD_DIALOGENCODER,CWnd::FromHandle(m_Tab.m_hWnd));
	m_dlgFilesToEncode.MoveWindow(&rcRect,FALSE);
	m_dlgFilesToEncode.ShowWindow(SW_SHOW);

	m_Progress.SetRange(0,100);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CLameXDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CLameXDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CLameXDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CLameXDlg::OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	switch(m_Tab.GetCurSel())
	{
		case 0:
				m_dlgOptions.SetEncoderXFromAll();
				m_dlgOptions.ShowWindow(SW_HIDE);
				m_dlgFilesToEncode.ShowWindow(SW_SHOW);
				break;
		case 1:
				m_dlgFilesToEncode.ShowWindow(SW_HIDE);
				m_dlgOptions.ShowWindow(SW_SHOW);
				break;
	}
	
	*pResult = 0;
}

BEGIN_EVENTSINK_MAP(CLameXDlg, CDialog)
    //{{AFX_EVENTSINK_MAP(CLameXDlg)
	ON_EVENT(CLameXDlg, IDC_LAMEENCODERXCTRL1, 1 /* PercentComplete */, OnPercentComplete, VTS_I4 VTS_I4)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CLameXDlg::OnPercentComplete(long lPercent, long lSample) 
{
	m_Progress.SetPos(lPercent);
	CString sInfo;
	sInfo.Format("LameX Encoding %s (%d%%)",m_sCurrentFile,lPercent);
	SetWindowText(sInfo);
	
}

void CLameXDlg::OnEncodeFiles() 
{
	long i;
	CTime tmStart = CTime::GetCurrentTime();

	for(i=0;i<m_dlgFilesToEncode.m_lNumberFiles;i++)
	{
		CFileFind ffind;

		CString sInputFile = m_dlgFilesToEncode.m_FilesToEncode[i];
		CString sOutputFile = sInputFile.Left( (sInputFile.GetLength()-3));
		sOutputFile += "mp3";

		if(ffind.FindFile(sInputFile))
		{
			m_LameEncoderX.SetInputFile(sInputFile);
			m_LameEncoderX.SetOutputFile(sOutputFile);

			m_sCurrentFile = sInputFile;

			OnPercentComplete(0,0);

			if(m_LameEncoderX.StartEncode())
			{
				// it was successful
				if(m_chkDeleteSources.GetCheck())
				{
					DeleteFile(sInputFile);
				}
			}

		}

	}
	CTimeSpan tmspn = CTime::GetCurrentTime() - tmStart;
	CString sInfo;
	sInfo.Format("Job Completed : (%.2d:%.2d:%.2d)",tmspn.GetHours(),tmspn.GetMinutes(),tmspn.GetSeconds());

	m_stcCurFile.SetWindowText(sInfo);
	m_dlgFilesToEncode.InitAll();
	SetWindowText("LameX");
}
