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

//{{AFX_INCLUDES()
#include "lameencoderx.h"
//}}AFX_INCLUDES

#if !defined(AFX_LAMEXDLG_H__094D5046_C5C4_11D3_8290_0080C605ADA4__INCLUDED_)
#define AFX_LAMEXDLG_H__094D5046_C5C4_11D3_8290_0080C605ADA4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CLameXDlg dialog
#include "COptionsDlg.h"
#include "CEncoderDlg.h"

class CLameXDlg : public CDialog
{
// Construction
public:
	CLameXDlg(CWnd* pParent = NULL);	// standard constructor


	// Vars
	COptionsDlg		m_dlgOptions;
	CEncoderDlg		m_dlgFilesToEncode;
	CString			m_sCurrentFile;
// Dialog Data
	//{{AFX_DATA(CLameXDlg)
	enum { IDD = IDD_LAMEX_DIALOG };
	CStatic	m_stcCurFile;
	CProgressCtrl	m_Progress;
	CButton	m_chkDeleteSources;
	CTabCtrl	m_Tab;
	CLameEncoderX	m_LameEncoderX;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLameXDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CLameXDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnPercentComplete(long lPercent, long lSample);
	afx_msg void OnEncodeFiles();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LAMEXDLG_H__094D5046_C5C4_11D3_8290_0080C605ADA4__INCLUDED_)
