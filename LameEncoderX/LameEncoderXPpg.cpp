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
#include "LameEncoderX.h"
#include "LameEncoderXPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CLameEncoderXPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CLameEncoderXPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CLameEncoderXPropPage)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CLameEncoderXPropPage, "LAMEENCODERX.LameEncoderXPropPage.1",
	0xf1253765, 0xc467, 0x11d3, 0x82, 0x90, 0, 0x80, 0xc6, 0x5, 0xad, 0xa4)


/////////////////////////////////////////////////////////////////////////////
// CLameEncoderXPropPage::CLameEncoderXPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CLameEncoderXPropPage

BOOL CLameEncoderXPropPage::CLameEncoderXPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_LAMEENCODERX_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CLameEncoderXPropPage::CLameEncoderXPropPage - Constructor

CLameEncoderXPropPage::CLameEncoderXPropPage() :
	COlePropertyPage(IDD, IDS_LAMEENCODERX_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CLameEncoderXPropPage)
	// NOTE: ClassWizard will add member initialization here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CLameEncoderXPropPage::DoDataExchange - Moves data between page and properties

void CLameEncoderXPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CLameEncoderXPropPage)
	// NOTE: ClassWizard will add DDP, DDX, and DDV calls here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CLameEncoderXPropPage message handlers
