#if !defined(AFX_COPTIONSDLG_H__094D504F_C5C4_11D3_8290_0080C605ADA4__INCLUDED_)
#define AFX_COPTIONSDLG_H__094D504F_C5C4_11D3_8290_0080C605ADA4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// COptionsDlg.h : header file
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
// COptionsDlg dialog
#include "lameencoderx.h"

class COptionsDlg : public CDialog
{
// Construction
public:
	COptionsDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(COptionsDlg)
	enum { IDD = IDD_DIALOGOPTIONS };
	//}}AFX_DATA
	CButton	m_chkErrorProt;
	CButton	m_chkUseOnlyATH;
	CEdit	m_edtOutputFreq;
	CEdit	m_edtInputFreq;
	CComboBox	m_cboMaxBitrate;
	CComboBox	m_cboVBRQuality;
	CComboBox	m_cboPriority;
	CComboBox	m_cboMinBitrate;
	CComboBox	m_cboBitrate;
	CButton	m_chkVoiceMode;
	CButton	m_chkUseVBR;
	CButton	m_chkNoShortBlocks;
	CButton	m_chkMarkNonOrig;
	CButton	m_chkMarkAsCopyright;
	CButton	m_chkHighQuality;
	CButton	m_chkFastMode;
	CButton	m_chkDownmix;
	CButton	m_chkDisableSFB;
	CButton	m_chkDisableTag;
	CButton	m_chkDiffBlocks;
	CButton	m_chkByteSwab;
	CButton	m_chkAllPCM;
	CButton	m_chkStereo;
	CButton	m_chkJoint;
	CButton	m_chkForce;
	CButton	m_chkMono;
	CLameEncoderX* m_lpEncoder;

	long		m_lBitrates[14];

	// funcs
	void		SetAllFromEncoderX		();
	void		SetEncoderXFromAll		();
	long		BitrateFromComboSel		(long lSel);
	long		ComboSelFromBitrate		(long lRate);
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COptionsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COptionsDlg)
	afx_msg void OnResetAll();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COPTIONSDLG_H__094D504F_C5C4_11D3_8290_0080C605ADA4__INCLUDED_)
