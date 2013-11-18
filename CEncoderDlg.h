#if !defined(AFX_CENCODERDLG_H__094D504E_C5C4_11D3_8290_0080C605ADA4__INCLUDED_)
#define AFX_CENCODERDLG_H__094D504E_C5C4_11D3_8290_0080C605ADA4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CEncoderDlg.h : header file
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


/////////////////////////////////////////////////////////////////////////////
// CEncoderDlg dialog
#include "DirTreeCtrl.h"
#include <deque>
using namespace std;

class CEncoderDlg : public CDialog
{
// Construction
public:
	CEncoderDlg(CWnd* pParent = NULL);   // standard constructor

	// vars
	deque <CString>		m_DisplayedFiles;
	deque <CString>		m_FilesToEncode;
	long				m_lNumberFiles;


	// funcs
	void				InitAll			();
	void				BuildSourceList	();

// Dialog Data
	//{{AFX_DATA(CEncoderDlg)
	enum { IDD = IDD_DIALOGENCODER };
	CListCtrl	m_ToEncodeList;
	CListCtrl	m_FilesList;
	CDirTreeCtrl	m_DirTree;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEncoderDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEncoderDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonaddfiles();
	afx_msg void OnButtonremove();
	afx_msg void OnSelchangedDirtree(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CENCODERDLG_H__094D504E_C5C4_11D3_8290_0080C605ADA4__INCLUDED_)
