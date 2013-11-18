// COptionsDlg.cpp : implementation file
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
#include "COptionsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COptionsDlg dialog


COptionsDlg::COptionsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COptionsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(COptionsDlg)
	//}}AFX_DATA_INIT
}


void COptionsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COptionsDlg)
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_CHECKUSEERRORPROTECTION, m_chkErrorProt);
	DDX_Control(pDX, IDC_CHECKONLYATH, m_chkUseOnlyATH);
	DDX_Control(pDX, IDC_EDITOUTPUTFREQ, m_edtOutputFreq);
	DDX_Control(pDX, IDC_EDITINPUTFREQ, m_edtInputFreq);
	DDX_Control(pDX, IDC_COMBOMAXBITRATE, m_cboMaxBitrate);
	DDX_Control(pDX, IDC_COMBOVBRQUALITY, m_cboVBRQuality);
	DDX_Control(pDX, IDC_COMBOPRIORITY, m_cboPriority);
	DDX_Control(pDX, IDC_COMBOMINBITRATE, m_cboMinBitrate);
	DDX_Control(pDX, IDC_COMBOBITRATE, m_cboBitrate);
	DDX_Control(pDX, IDC_CHECKVOICEMODE, m_chkVoiceMode);
	DDX_Control(pDX, IDC_CHECKUSEVBR, m_chkUseVBR);
	DDX_Control(pDX, IDC_CHECKNOSHORTBLOCKS, m_chkNoShortBlocks);
	DDX_Control(pDX, IDC_CHECKMARKASNONORIG, m_chkMarkNonOrig);
	DDX_Control(pDX, IDC_CHECKMARKASCOPYRIGHT, m_chkMarkAsCopyright);
	DDX_Control(pDX, IDC_CHECKHIGHQUALITY, m_chkHighQuality);
	DDX_Control(pDX, IDC_CHECKFASTMODE, m_chkFastMode);
	DDX_Control(pDX, IDC_CHECKDOWNMIX, m_chkDownmix);
	DDX_Control(pDX, IDC_CHECKDISABLESFB, m_chkDisableSFB);
	DDX_Control(pDX, IDC_CHECKDISABLEINFOTAG, m_chkDisableTag);
	DDX_Control(pDX, IDC_CHECKDIFFBLOCKS, m_chkDiffBlocks);
	DDX_Control(pDX, IDC_CHECKBYTESWAB, m_chkByteSwab);
	DDX_Control(pDX, IDC_CHECKALLPCM, m_chkAllPCM);

	DDX_Control(pDX, IDC_RADIOSTEREO, m_chkStereo);
	DDX_Control(pDX, IDC_RADIOJOINT, m_chkJoint);
	DDX_Control(pDX, IDC_RADIOFORCE, m_chkForce);
	DDX_Control(pDX, IDC_RADIOMONO, m_chkMono);

}


BEGIN_MESSAGE_MAP(COptionsDlg, CDialog)
	//{{AFX_MSG_MAP(COptionsDlg)
	ON_BN_CLICKED(IDC_BUTTONRESETALL, OnResetAll)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COptionsDlg message handlers
inline long COptionsDlg::BitrateFromComboSel(long lSel)
{
	return m_lBitrates[lSel];
}
inline long COptionsDlg::ComboSelFromBitrate(long lRate)
{
	long i;

	for(i=0;i<14;i++)
	{
		if(m_lBitrates[i] == lRate)
			return i;
	}
	return 0;
}
void COptionsDlg::SetAllFromEncoderX()
{
	CString sTemp;

	sTemp.Format("%f",m_lpEncoder->GetResampleFreq());
	m_edtOutputFreq.SetWindowText(sTemp);

	sTemp.Format("%f",m_lpEncoder->GetSamplingFreq());
	m_edtInputFreq.SetWindowText(sTemp);

	m_cboMaxBitrate.SetCurSel( ComboSelFromBitrate( m_lpEncoder->GetMaximumBitrate()));
	m_cboVBRQuality.SetCurSel( m_lpEncoder->GetVBRQuality());
	m_cboPriority.SetCurSel( m_lpEncoder->GetEncodingPriority());
	m_cboMinBitrate.SetCurSel( ComboSelFromBitrate( m_lpEncoder->GetMinimumBitrate()));
	m_cboBitrate.SetCurSel( ComboSelFromBitrate( m_lpEncoder->GetBitrate()));

	m_chkErrorProt.SetCheck(m_lpEncoder->GetErrorProtection());
	m_chkUseOnlyATH.SetCheck(m_lpEncoder->GetOnlyATHForMasking());
	m_chkVoiceMode.SetCheck(m_lpEncoder->GetVoiceMode());
	m_chkUseVBR.SetCheck(m_lpEncoder->GetUseVBR());
	m_chkNoShortBlocks.SetCheck(m_lpEncoder->GetNoShortBlocks());
	m_chkMarkNonOrig.SetCheck(m_lpEncoder->GetMarkAsNonOriginal());
	m_chkMarkAsCopyright.SetCheck(m_lpEncoder->GetMarkAsCopyrighted());
	m_chkHighQuality.SetCheck(m_lpEncoder->GetUseQualityImprovements());
	m_chkFastMode.SetCheck(m_lpEncoder->GetUseFastMode());
	m_chkDownmix.SetCheck(m_lpEncoder->GetDownmixToMono());
	m_chkDisableSFB.SetCheck(m_lpEncoder->GetDisableSFBCutoff());
	m_chkDisableTag.SetCheck(m_lpEncoder->GetDisableVBRInfoTag());
	m_chkDiffBlocks.SetCheck(m_lpEncoder->GetAllowChanDifBlockTypes());
	m_chkByteSwab.SetCheck(m_lpEncoder->GetForceByteSwab());
	m_chkAllPCM.SetCheck(m_lpEncoder->GetInputIsRawPCM());

	switch(m_lpEncoder->GetMode())
	{
		case 0:
			m_chkStereo.SetCheck(TRUE);
			break;
		case 1:
			m_chkJoint.SetCheck(TRUE);
			break;
		case 2:
			m_chkForce.SetCheck(TRUE);
			break;
		case 3:
			m_chkMono.SetCheck(TRUE);
			break;
	}
}
void COptionsDlg::SetEncoderXFromAll()
{
	CString sTemp;
	float ftmp;

	m_edtOutputFreq.GetWindowText(sTemp);
	ftmp = float(atof((LPCTSTR)sTemp));
	m_lpEncoder->SetResampleFreq(ftmp);
	
	m_edtInputFreq.GetWindowText(sTemp);
	ftmp = float(atof((LPCTSTR)sTemp));
	m_lpEncoder->SetSamplingFreq(ftmp);

	m_lpEncoder->SetMaximumBitrate(BitrateFromComboSel(m_cboMaxBitrate.GetCurSel()));
	m_lpEncoder->SetVBRQuality(m_cboVBRQuality.GetCurSel()); 
	m_lpEncoder->SetEncodingPriority(m_cboPriority.GetCurSel()); 
	m_lpEncoder->SetMinimumBitrate(BitrateFromComboSel(m_cboMinBitrate.GetCurSel()));
	m_lpEncoder->SetBitrate(BitrateFromComboSel(m_cboBitrate.GetCurSel()));

	m_lpEncoder->SetErrorProtection(m_chkErrorProt.GetCheck());
	m_lpEncoder->SetOnlyATHForMasking(m_chkUseOnlyATH.GetCheck());
	m_lpEncoder->SetVoiceMode(m_chkVoiceMode.GetCheck());
	m_lpEncoder->SetUseVBR(m_chkUseVBR.GetCheck());
	m_lpEncoder->SetNoShortBlocks(m_chkNoShortBlocks.GetCheck());
	m_lpEncoder->SetMarkAsNonOriginal(m_chkMarkNonOrig.GetCheck());
	m_lpEncoder->SetMarkAsCopyrighted(m_chkMarkAsCopyright.GetCheck());
	m_lpEncoder->SetUseQualityImprovements(m_chkHighQuality.GetCheck());
	m_lpEncoder->SetUseFastMode(m_chkFastMode.GetCheck());
	m_lpEncoder->SetDownmixToMono(m_chkDownmix.GetCheck());
	m_lpEncoder->SetDisableSFBCutoff(m_chkDisableSFB.GetCheck());
	m_lpEncoder->SetDisableVBRInfoTag(m_chkDisableTag.GetCheck());
	m_lpEncoder->SetAllowChanDifBlockTypes(m_chkDiffBlocks.GetCheck());
	m_lpEncoder->SetForceByteSwab(m_chkByteSwab.GetCheck());
	m_lpEncoder->SetInputIsRawPCM(m_chkAllPCM.GetCheck());

	long lMode = 0;

	if(m_chkStereo.GetCheck())
		lMode = 0;
	else if(m_chkJoint.GetCheck())
		lMode = 1;
	else if(m_chkForce.GetCheck())
		lMode = 2;
	else if(m_chkMono.GetCheck())
		lMode = 3;

	m_lpEncoder->SetMode(lMode);
}
void COptionsDlg::OnResetAll() 
{
	m_lpEncoder->SetAllDefaultParams();
	SetAllFromEncoderX();	
}

BOOL COptionsDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_lBitrates[0]=32;
	m_lBitrates[1]=40;
	m_lBitrates[2]=48;
	m_lBitrates[3]=56;
	m_lBitrates[4]=64;
	m_lBitrates[5]=80;
	m_lBitrates[6]=96;
	m_lBitrates[7]=112;
	m_lBitrates[8]=128;
	m_lBitrates[9]=160;
	m_lBitrates[10]=192;
	m_lBitrates[11]=224;
	m_lBitrates[12]=256;
	m_lBitrates[13]=320;

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
