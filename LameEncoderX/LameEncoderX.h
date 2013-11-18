#if !defined(AFX_LAMEENCODERX_H__F125376A_C467_11D3_8290_0080C605ADA4__INCLUDED_)
#define AFX_LAMEENCODERX_H__F125376A_C467_11D3_8290_0080C605ADA4__INCLUDED_
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
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// LameEncoderX.h : main header file for LAMEENCODERX.DLL

#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CLameEncoderXApp : See LameEncoderX.cpp for implementation.

class CLameEncoderXApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LAMEENCODERX_H__F125376A_C467_11D3_8290_0080C605ADA4__INCLUDED)
