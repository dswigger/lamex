// LameEncoderXCtl.cpp : Implementation of the CLameEncoderXCtrl ActiveX Control class.
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
#include "LameEncoderXCtl.h"
#include "LameEncoderXPpg.h"
#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <sys/stat.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CLameEncoderXCtrl, COleControl)

extern "C"
{
#include "BladeMP3EncDLLX.h"
}



/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CLameEncoderXCtrl, COleControl)
	//{{AFX_MSG_MAP(CLameEncoderXCtrl)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CLameEncoderXCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CLameEncoderXCtrl)
	DISP_PROPERTY_EX(CLameEncoderXCtrl, "InputFile", GetInputFile, SetInputFile, VT_BSTR)
	DISP_PROPERTY_EX(CLameEncoderXCtrl, "OutputFile", GetOutputFile, SetOutputFile, VT_BSTR)
	DISP_PROPERTY_EX(CLameEncoderXCtrl, "EncodingPriority", GetEncodingPriority, SetEncodingPriority, VT_I4)
	DISP_PROPERTY_EX(CLameEncoderXCtrl, "Mode", GetMode, SetMode, VT_I4)
	DISP_PROPERTY_EX(CLameEncoderXCtrl, "Bitrate", GetBitrate, SetBitrate, VT_I4)
	DISP_PROPERTY_EX(CLameEncoderXCtrl, "SamplingFreq", GetSamplingFreq, SetSamplingFreq, VT_R4)
	DISP_PROPERTY_EX(CLameEncoderXCtrl, "VoiceMode", GetVoiceMode, SetVoiceMode, VT_BOOL)
	DISP_PROPERTY_EX(CLameEncoderXCtrl, "UseVBR", GetUseVBR, SetUseVBR, VT_BOOL)
	DISP_PROPERTY_EX(CLameEncoderXCtrl, "VBRQuality", GetVBRQuality, SetVBRQuality, VT_I4)
	DISP_PROPERTY_EX(CLameEncoderXCtrl, "MinimumBitrate", GetMinimumBitrate, SetMinimumBitrate, VT_I4)
	DISP_PROPERTY_EX(CLameEncoderXCtrl, "MaximumBitrate", GetMaximumBitrate, SetMaximumBitrate, VT_I4)
	DISP_PROPERTY_EX(CLameEncoderXCtrl, "DisableVBRInfoTag", GetDisableVBRInfoTag, SetDisableVBRInfoTag, VT_BOOL)
	DISP_PROPERTY_EX(CLameEncoderXCtrl, "UseQualityImprovements", GetUseQualityImprovements, SetUseQualityImprovements, VT_BOOL)
	DISP_PROPERTY_EX(CLameEncoderXCtrl, "UseFastMode", GetUseFastMode, SetUseFastMode, VT_BOOL)
	DISP_PROPERTY_EX(CLameEncoderXCtrl, "DisableSFBCutoff", GetDisableSFBCutoff, SetDisableSFBCutoff, VT_BOOL)
	DISP_PROPERTY_EX(CLameEncoderXCtrl, "AllowChanDifBlockTypes", GetAllowChanDifBlockTypes, SetAllowChanDifBlockTypes, VT_BOOL)
	DISP_PROPERTY_EX(CLameEncoderXCtrl, "OnlyATHForMasking", GetOnlyATHForMasking, SetOnlyATHForMasking, VT_BOOL)
	DISP_PROPERTY_EX(CLameEncoderXCtrl, "NoShortBlocks", GetNoShortBlocks, SetNoShortBlocks, VT_BOOL)
	DISP_PROPERTY_EX(CLameEncoderXCtrl, "InputIsRawPCM", GetInputIsRawPCM, SetInputIsRawPCM, VT_BOOL)
	DISP_PROPERTY_EX(CLameEncoderXCtrl, "ForceByteSwab", GetForceByteSwab, SetForceByteSwab, VT_BOOL)
	DISP_PROPERTY_EX(CLameEncoderXCtrl, "DownmixToMono", GetDownmixToMono, SetDownmixToMono, VT_BOOL)
	DISP_PROPERTY_EX(CLameEncoderXCtrl, "ErrorProtection", GetErrorProtection, SetErrorProtection, VT_BOOL)
	DISP_PROPERTY_EX(CLameEncoderXCtrl, "MarkAsCopyrighted", GetMarkAsCopyrighted, SetMarkAsCopyrighted, VT_BOOL)
	DISP_PROPERTY_EX(CLameEncoderXCtrl, "MarkAsNonOriginal", GetMarkAsNonOriginal, SetMarkAsNonOriginal, VT_BOOL)
	DISP_PROPERTY_EX(CLameEncoderXCtrl, "Title", GetTitle, SetTitle, VT_BSTR)
	DISP_PROPERTY_EX(CLameEncoderXCtrl, "Artist", GetArtist, SetArtist, VT_BSTR)
	DISP_PROPERTY_EX(CLameEncoderXCtrl, "Album", GetAlbum, SetAlbum, VT_BSTR)
	DISP_PROPERTY_EX(CLameEncoderXCtrl, "Year", GetYear, SetYear, VT_BSTR)
	DISP_PROPERTY_EX(CLameEncoderXCtrl, "Comment", GetComment, SetComment, VT_BSTR)
	DISP_PROPERTY_EX(CLameEncoderXCtrl, "Genre", GetGenre, SetGenre, VT_BSTR)
	DISP_PROPERTY_EX(CLameEncoderXCtrl, "ResampleFreq", GetResampleFreq, SetResampleFreq, VT_R4)
	DISP_PROPERTY_EX(CLameEncoderXCtrl, "EnoderXVersion", GetEnoderXVersion, SetEnoderXVersion, VT_R4)
	DISP_FUNCTION(CLameEncoderXCtrl, "StartEncode", StartEncode, VT_BOOL, VTS_NONE)
	DISP_FUNCTION(CLameEncoderXCtrl, "GetCurrentCommandString", GetCurrentCommandString, VT_BSTR, VTS_NONE)
	DISP_FUNCTION(CLameEncoderXCtrl, "SetAllDefaultParams", SetAllDefaultParams, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CLameEncoderXCtrl, "GetTotalEncodingTime", GetTotalEncodingTime, VT_BSTR, VTS_NONE)
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(CLameEncoderXCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CLameEncoderXCtrl, COleControl)
	//{{AFX_EVENT_MAP(CLameEncoderXCtrl)
	EVENT_CUSTOM("PercentComplete", FirePercentComplete, VTS_I4  VTS_I4)
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CLameEncoderXCtrl, 1)
	PROPPAGEID(CLameEncoderXPropPage::guid)
END_PROPPAGEIDS(CLameEncoderXCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CLameEncoderXCtrl, "LAMEENCODERX.LameEncoderXCtrl.1",
	0xcea71983, 0xc458, 0x11d3, 0x82, 0x90, 0, 0x80, 0xc6, 0x5, 0xad, 0xa4)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CLameEncoderXCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DLameEncoderX =
		{ 0xf1253763, 0xc467, 0x11d3, { 0x82, 0x90, 0, 0x80, 0xc6, 0x5, 0xad, 0xa4 } };
const IID BASED_CODE IID_DLameEncoderXEvents =
		{ 0xf1253764, 0xc467, 0x11d3, { 0x82, 0x90, 0, 0x80, 0xc6, 0x5, 0xad, 0xa4 } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwLameEncoderXOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CLameEncoderXCtrl, IDS_LAMEENCODERX, _dwLameEncoderXOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CLameEncoderXCtrl::CLameEncoderXCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CLameEncoderXCtrl

BOOL CLameEncoderXCtrl::CLameEncoderXCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegApartmentThreading to 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_LAMEENCODERX,
			IDB_LAMEENCODERX,
			afxRegApartmentThreading,
			_dwLameEncoderXOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CLameEncoderXCtrl::CLameEncoderXCtrl - Constructor

CLameEncoderXCtrl::CLameEncoderXCtrl()
{
	InitializeIIDs(&IID_DLameEncoderX, &IID_DLameEncoderXEvents);

	SetDefaultParams();
}


/////////////////////////////////////////////////////////////////////////////
// CLameEncoderXCtrl::~CLameEncoderXCtrl - Destructor

CLameEncoderXCtrl::~CLameEncoderXCtrl()
{
	// TODO: Cleanup your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CLameEncoderXCtrl::OnDraw - Drawing function

void CLameEncoderXCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	// TODO: Replace the following code with your own drawing code.
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}


/////////////////////////////////////////////////////////////////////////////
// CLameEncoderXCtrl::DoPropExchange - Persistence support

void CLameEncoderXCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.

}


/////////////////////////////////////////////////////////////////////////////
// CLameEncoderXCtrl::GetControlFlags -
// Flags to customize MFC's implementation of ActiveX controls.
//
// For information on using these flags, please see MFC technical note
// #nnn, "Optimizing an ActiveX Control".
DWORD CLameEncoderXCtrl::GetControlFlags()
{
	DWORD dwFlags = COleControl::GetControlFlags();


	// The control can activate without creating a window.
	// TODO: when writing the control's message handlers, avoid using
	//		the m_hWnd member variable without first checking that its
	//		value is non-NULL.
	dwFlags |= windowlessActivate;
	return dwFlags;
}


/////////////////////////////////////////////////////////////////////////////
// CLameEncoderXCtrl::OnResetState - Reset control to default state

void CLameEncoderXCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}


/////////////////////////////////////////////////////////////////////////////
// CLameEncoderXCtrl::AboutBox - Display an "About" box to the user

void CLameEncoderXCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_LAMEENCODERX);
	dlgAbout.DoModal();
}


/////////////////////////////////////////////////////////////////////////////
// CLameEncoderXCtrl message handlers

BOOL CLameEncoderXCtrl::StartEncode() 
{
	CTime tmStart = CTime::GetCurrentTime();
	char Args[30][255];
	char*	lpArgs[30];

	// Check to make sure our input and output are not blank
	if(m_sInputFile == "" && m_sOutputFile == "")
		return FALSE;

	for(long i=0;i<30;i++)
		lpArgs[i] = Args[i];

	// Now encode that sucker

	int pumper = 0;

	BumpPriority();

	// Open RAW file
	
	int hIn = open((LPCTSTR)m_sInputFile, O_RDONLY | O_BINARY);

	if(hIn == -1)	
	{
		RestorePriority();
		return FALSE;
	}

	// Generate filename.mp3

	char zOutputFilename[MAX_PATH + 1];	

	strcpy(zOutputFilename,(LPCTSTR)m_sOutputFile);

	// Open MP3 file

	int hOut = open(zOutputFilename, O_WRONLY | O_BINARY | O_TRUNC | O_CREAT, S_IWRITE);

	if(hOut == -1)	
	{
		RestorePriority();
		return FALSE;
	}

	// Open MP3 Encoding Stream
/*
	BE_CONFIG	beConfig;

	beConfig.dwConfig = BE_CONFIG_MP3;

	beConfig.format.mp3.dwSampleRate	= 44100;
	beConfig.format.mp3.byMode			= BE_MP3_MODE_STEREO;
	beConfig.format.mp3.wBitrate		= 128;
	beConfig.format.mp3.bCopyright		= FALSE;
	beConfig.format.mp3.bCRC			= FALSE;
	beConfig.format.mp3.bOriginal		= FALSE;
	beConfig.format.mp3.bPrivate		= FALSE;
*/
	DWORD		dwSamples, dwMP3Buffer;
	HBE_STREAM	hbeStream;
	BE_ERR		err;

	int		iArgs;

	GetCommandString(lpArgs,iArgs);

	err = beInitStreamWDirectParams(iArgs,lpArgs,&dwSamples, &dwMP3Buffer, &hbeStream);

	//err = beInitStream(&beConfig, &dwSamples, &dwMP3Buffer, &hbeStream);

	if(err != BE_ERR_SUCCESSFUL)	
	{
		RestorePriority();
		return FALSE;
	}

	// Allocate buffers

	PBYTE pMP3Buffer = new BYTE[dwMP3Buffer];

	PSHORT pBuffer = new SHORT[dwSamples];

	if(!pMP3Buffer || !pBuffer)	
	{
		RestorePriority();
		return FALSE;
	}

	// Start encoding

	DWORD	length = filelength(hIn);
	DWORD	done = 0;
	DWORD	dwWrite;
	DWORD	toread;
	DWORD	towrite;
	long	lPercentComplete;

	setbuf(stdout,NULL);

	long lLastPercent = -1;

	while(done < length)	
	{

		if(done + dwSamples * 2 < length)	
		{

			toread = dwSamples * 2;
		}
		else	
		{

			toread = length - done;
		}

		if(read(hIn, pBuffer, toread) == -1)	
		{
			RestorePriority();
			return FALSE;
		}		 

		err = beEncodeChunk(hbeStream, toread/2, pBuffer, pMP3Buffer, &towrite);

		if(err != BE_ERR_SUCCESSFUL)	
		{

			beCloseStream(hbeStream);
			RestorePriority();
			return FALSE;
		}
		
		if(write(hOut, pMP3Buffer, towrite) == -1)	
		{
			RestorePriority();
			return FALSE;
		}

		done += toread;

		lPercentComplete = long(100 * (float)done/(float)length);

		if(lLastPercent != lPercentComplete)
		{
			lLastPercent = lPercentComplete;
			FirePercentComplete(lPercentComplete,done);
		}

		pumper++;
		if(pumper >= 10)
		{
			Pump();
			pumper = 0;
		}
//		sInfo.Format("Percent Complete: %0.2f%%", 100 * (float)done/(float)length);
		//printf("Done: %0.2f%%     \r", 100 * (float)done/(float)length);	
	}

	err = beDeinitStream(hbeStream, pMP3Buffer, &dwWrite);

	if(err != BE_ERR_SUCCESSFUL)	
	{
		beCloseStream(hbeStream);
		RestorePriority();
		return FALSE;
	}

	if(dwWrite)	
	{

		if(write(hOut, pMP3Buffer, dwWrite) == -1)	
		{
			RestorePriority();
			return FALSE;
		}
	}

	beCloseStream(hbeStream);

	// Set our total time
	m_tsEncodingTime = CTime::GetCurrentTime() - tmStart;

	close(hIn);
	close(hOut);	

	RestorePriority();

	return TRUE;
}
BSTR CLameEncoderXCtrl::GetInputFile() 
{
	return m_sInputFile.AllocSysString();
}
void CLameEncoderXCtrl::SetInputFile(LPCTSTR lpszNewValue) 
{
	m_sInputFile = lpszNewValue;
}
BSTR CLameEncoderXCtrl::GetOutputFile() 
{
	return m_sOutputFile.AllocSysString();
}
void CLameEncoderXCtrl::SetOutputFile(LPCTSTR lpszNewValue) 
{
	m_sOutputFile = lpszNewValue;
}
long CLameEncoderXCtrl::GetEncodingPriority() 
{
	return m_lPriority;
}
void CLameEncoderXCtrl::SetEncodingPriority(long nNewValue) 
{
	// Priority

	//6	THREAD_PRIORITY_TIME_CRITICAL
	//5	THREAD_PRIORITY_HIGHEST
	//4	THREAD_PRIORITY_ABOVE_NORMAL
	//3	THREAD_PRIORITY_NORMAL
	//2	THREAD_PRIORITY_BELOW_NORMAL
	//1	THREAD_PRIORITY_LOWEST
	//0	THREAD_PRIORITY_IDLE 
	m_lPriority = nNewValue;
}
void CLameEncoderXCtrl::BumpPriority()
{
	int iNewPriority = THREAD_PRIORITY_NORMAL;

	switch(m_lPriority)
	{
		case 0:
				iNewPriority = THREAD_PRIORITY_IDLE;;
				break;
		case 1:
				iNewPriority = THREAD_PRIORITY_LOWEST;;
				break;
		case 2:
				iNewPriority = THREAD_PRIORITY_BELOW_NORMAL;;
				break;
		case 3:
				iNewPriority = THREAD_PRIORITY_NORMAL;;
				break;
		case 4:
				iNewPriority = THREAD_PRIORITY_ABOVE_NORMAL;;
				break;
		case 5:
				iNewPriority = THREAD_PRIORITY_HIGHEST;;
				break;
		case 6:
				iNewPriority = THREAD_PRIORITY_TIME_CRITICAL;;
				break;
	}

	m_iSavedPriority = AfxGetApp()->GetThreadPriority();

	AfxGetApp()->SetThreadPriority(iNewPriority);

}
void CLameEncoderXCtrl::RestorePriority()
{
	AfxGetApp()->SetThreadPriority(m_iSavedPriority);
}
void CLameEncoderXCtrl::SetDefaultParams()
{
 	// Mode
	//0 stereo 
    //1 joint 
    //2 force 
	//3 mono

	m_lMode							= 0;
	m_lBitrate						= 128;
	m_fInputSampleFreq				= -1;
	m_fResampleFreq					= -1;
	m_bVoiceMode					= FALSE;
	m_bUseVBR						= FALSE;
	m_lVBRQuality					= 4;
	m_lMinimumBitrate				= 128;
	m_lMaximumBitrate				= 128;
	m_bDisableVBRInfoTag			= FALSE;
	m_bUseQualityImprovements		= FALSE;
	m_bUseFastMode					= FALSE;
	m_bDisableSFB					= TRUE;
	m_bAllowDifferentBlocktypes		= FALSE;
	m_bUseOnlyATH					= FALSE;
	m_bNoShortBlocks				= FALSE;
	m_bInputIsPCM					= FALSE;
	m_bForceByteSwab				= FALSE;
	m_bForceDownmix					= FALSE;
	m_bUseErrorProtection			= FALSE;
	m_bMarkAsCopyright				= FALSE;
	m_bMarkAsNonOriginal			= FALSE;

	m_sTitle						= "";
	m_sArtist						= "";
	m_sAlbum						= "";
	m_sYear							= "";
	m_sComment						= "";
	m_sGenre						= "";

	m_lPriority						= 3;// Normal Priority
	m_sInputFile					= "";
	m_sOutputFile					= "";
}
inline void CLameEncoderXCtrl::ConcatParam(CString& sSource,CString sFormat,long lParam)
{
	CString sFormatted;

	sFormatted.Format(sFormat,lParam);

	sSource += sFormatted;
}
inline void CLameEncoderXCtrl::ConcatParam(CString& sSource,CString sFormat,float lParam)
{
	CString sFormatted;

	sFormatted.Format(sFormat,lParam);

	sSource += sFormatted;
}
void CLameEncoderXCtrl::GetCommandString(char **args,int& nArgs)
{
	// I know that the Blade Code does a lot of this, but I wanted
	// to re-write it for this OCX since I could use MFC CString
	nArgs = 0;

	CString sRet = "";

	// The Mode
	switch(m_lMode)
	{
		case 0:
				strcpy(args[nArgs++],"-ms");
				break;
		case 1:
				strcpy(args[nArgs++],"-mj");
				break;
		case 2:
				strcpy(args[nArgs++],"-mf");
				break;
		case 3:
				strcpy(args[nArgs++],"-mm");
				break;
	}
	nArgs++;

	// Bitrate
	if(m_bUseVBR == FALSE && m_lBitrate != 128)
	{
		
		sRet.Format("-b %d",m_lBitrate);
		strcpy(args[nArgs++],(LPCTSTR)sRet);
	}
		
	if(m_fInputSampleFreq > 0)
	{
		sRet.Format("-s %f", float(m_fInputSampleFreq/1000.0));
		strcpy(args[nArgs++],(LPCTSTR)sRet);
	}

	if(m_fResampleFreq > 0)
	{
		sRet.Format("--resample %f",float(m_fResampleFreq/1000.0));
		strcpy(args[nArgs++],(LPCTSTR)sRet);
	}

	if(m_sInputFile.Right(3) == "mp3")
	{
		strcpy(args[nArgs++],"--mp3input");
	}

	if(m_bVoiceMode == TRUE)
	{
		strcpy(args[nArgs++],"--voice");
	}

	if(m_bUseVBR == TRUE)
	{
		strcpy(args[nArgs++],"-v");
	}

	if(m_lVBRQuality != 4)
	{
		sRet.Format("-V %d",m_lVBRQuality);
		strcpy(args[nArgs++],(LPCTSTR)sRet);
	}

	if(m_lMinimumBitrate != 128)
	{
		sRet.Format("-b %d",m_lMinimumBitrate);
		strcpy(args[nArgs++],(LPCTSTR)sRet);	
	}

	if(m_lMaximumBitrate != 128)
	{
		sRet.Format("-B %d",m_lMaximumBitrate);
		strcpy(args[nArgs++],(LPCTSTR)sRet);
	}

	if(m_bDisableVBRInfoTag == TRUE)
	{
		strcpy(args[nArgs++],"-t");
	}

	if(m_bUseQualityImprovements == TRUE)
	{
		strcpy(args[nArgs++],"-h");
	}

	if(m_bUseFastMode == TRUE)
	{
		strcpy(args[nArgs++],"-f");
	}

	if(m_bDisableSFB == TRUE)
	{
		strcpy(args[nArgs++],"-k");
	}

	if(m_bAllowDifferentBlocktypes == TRUE)
	{
		strcpy(args[nArgs++],"-d");
	}

	if(m_bUseOnlyATH == TRUE)
	{
		strcpy(args[nArgs++],"--athonly");
	}

	if(m_bNoShortBlocks == TRUE)
	{
		strcpy(args[nArgs++],"--noshort");
	}

	if(m_bInputIsPCM == TRUE)
	{
		strcpy(args[nArgs++],"-r");
	}

	if(m_bForceByteSwab == TRUE)
	{
		strcpy(args[nArgs++],"-x");
	}

	if(m_bForceDownmix == TRUE)
	{
		strcpy(args[nArgs++],"-a");
	}

	if(m_bUseErrorProtection == TRUE)
	{
		strcpy(args[nArgs++],"-p");
	}

	if(m_bMarkAsCopyright == TRUE)
	{
		strcpy(args[nArgs++],"-c");
	}

	if(m_bMarkAsNonOriginal == TRUE)
	{
		strcpy(args[nArgs++],"-o");
	}


	/* Will implement later
	// Specifying any of the following options will add an ID3 tag:\n");
	m_sTitle;
	//--ta \"artist\"    artist who did the song (max 30 chars)\n");
	m_sArtist;
	//--tl \"album\"     album where it came from (max 30 chars)\n");
	m_sAlbum;
	//--ty \"year\"      year in which the song/album was made (max 4 chars)\n");
	m_sYear;
	//--tc \"comment\"   additional info (max 30 chars)\n");
	m_sComment;
	//--tg \"genre\"     genre of song (name or number)\n");
	m_sGenre;
	*/

	// add the input and output NULLs
	strcpy(args[nArgs++],"NULL.wav");
	strcpy(args[nArgs++],"NULL.mp3");
}
// ----------------------------- Lame Sets and Gets----------------------------------------
long CLameEncoderXCtrl::GetMode() 
{return m_lMode;}
void CLameEncoderXCtrl::SetMode(long nNewValue) 
{m_lMode = nNewValue;}
long CLameEncoderXCtrl::GetBitrate() 
{return m_lBitrate;}
void CLameEncoderXCtrl::SetBitrate(long nNewValue) 
{m_lBitrate = nNewValue;}
float CLameEncoderXCtrl::GetSamplingFreq() 
{return m_fInputSampleFreq;}
void CLameEncoderXCtrl::SetSamplingFreq(float fNewValue) 
{m_fInputSampleFreq = fNewValue;}
BOOL CLameEncoderXCtrl::GetVoiceMode() 
{return m_bVoiceMode;}
void CLameEncoderXCtrl::SetVoiceMode(BOOL bNewValue) 
{m_bVoiceMode = bNewValue;}
BOOL CLameEncoderXCtrl::GetUseVBR() 
{return m_bUseVBR;}
void CLameEncoderXCtrl::SetUseVBR(BOOL bNewValue) 
{m_bUseVBR = bNewValue;}
long CLameEncoderXCtrl::GetVBRQuality() 
{return m_lVBRQuality;}
void CLameEncoderXCtrl::SetVBRQuality(long nNewValue) 
{m_lVBRQuality = nNewValue;}
long CLameEncoderXCtrl::GetMinimumBitrate() 
{return m_lMinimumBitrate;}
void CLameEncoderXCtrl::SetMinimumBitrate(long nNewValue) 
{m_lMinimumBitrate = nNewValue;}
long CLameEncoderXCtrl::GetMaximumBitrate() 
{return m_lMaximumBitrate;}
void CLameEncoderXCtrl::SetMaximumBitrate(long nNewValue) 
{m_lMaximumBitrate = nNewValue;}
BOOL CLameEncoderXCtrl::GetDisableVBRInfoTag() 
{return m_bDisableVBRInfoTag;}
void CLameEncoderXCtrl::SetDisableVBRInfoTag(BOOL bNewValue) 
{m_bDisableVBRInfoTag = bNewValue;}
BOOL CLameEncoderXCtrl::GetUseQualityImprovements() 
{return m_bUseQualityImprovements;}
void CLameEncoderXCtrl::SetUseQualityImprovements(BOOL bNewValue) 
{m_bUseQualityImprovements = bNewValue;}
BOOL CLameEncoderXCtrl::GetUseFastMode() 
{return m_bUseFastMode;}
void CLameEncoderXCtrl::SetUseFastMode(BOOL bNewValue) 
{m_bUseFastMode = bNewValue;}
BOOL CLameEncoderXCtrl::GetDisableSFBCutoff() 
{return m_bDisableSFB;}
void CLameEncoderXCtrl::SetDisableSFBCutoff(BOOL bNewValue) 
{m_bDisableSFB = bNewValue;}
BOOL CLameEncoderXCtrl::GetAllowChanDifBlockTypes() 
{return m_bAllowDifferentBlocktypes;}
void CLameEncoderXCtrl::SetAllowChanDifBlockTypes(BOOL bNewValue) 
{m_bAllowDifferentBlocktypes = bNewValue;}
BOOL CLameEncoderXCtrl::GetOnlyATHForMasking() 
{return m_bUseOnlyATH;}
void CLameEncoderXCtrl::SetOnlyATHForMasking(BOOL bNewValue) 
{m_bUseOnlyATH = bNewValue;}
BOOL CLameEncoderXCtrl::GetNoShortBlocks() 
{return m_bNoShortBlocks;}
void CLameEncoderXCtrl::SetNoShortBlocks(BOOL bNewValue) 
{m_bNoShortBlocks = bNewValue;}
BOOL CLameEncoderXCtrl::GetInputIsRawPCM() 
{return m_bInputIsPCM;}
void CLameEncoderXCtrl::SetInputIsRawPCM(BOOL bNewValue) 
{m_bInputIsPCM = bNewValue;}
BOOL CLameEncoderXCtrl::GetForceByteSwab() 
{return m_bForceByteSwab;}
void CLameEncoderXCtrl::SetForceByteSwab(BOOL bNewValue) 
{m_bForceByteSwab = bNewValue;}
BOOL CLameEncoderXCtrl::GetDownmixToMono() 
{return m_bForceDownmix;}
void CLameEncoderXCtrl::SetDownmixToMono(BOOL bNewValue) 
{m_bForceDownmix = bNewValue;}
BOOL CLameEncoderXCtrl::GetErrorProtection() 
{return m_bUseErrorProtection;}
void CLameEncoderXCtrl::SetErrorProtection(BOOL bNewValue) 
{m_bUseErrorProtection = bNewValue;}
BOOL CLameEncoderXCtrl::GetMarkAsCopyrighted() 
{return m_bMarkAsCopyright;}
void CLameEncoderXCtrl::SetMarkAsCopyrighted(BOOL bNewValue) 
{m_bMarkAsCopyright = bNewValue;}
BOOL CLameEncoderXCtrl::GetMarkAsNonOriginal() 
{return m_bMarkAsNonOriginal;}
void CLameEncoderXCtrl::SetMarkAsNonOriginal(BOOL bNewValue) 
{m_bMarkAsNonOriginal = bNewValue;}
BSTR CLameEncoderXCtrl::GetTitle() 
{return m_sTitle.AllocSysString();}
void CLameEncoderXCtrl::SetTitle(LPCTSTR lpszNewValue) 
{m_sTitle = lpszNewValue;}
BSTR CLameEncoderXCtrl::GetArtist() 
{return m_sArtist.AllocSysString();}
void CLameEncoderXCtrl::SetArtist(LPCTSTR lpszNewValue) 
{m_sArtist = lpszNewValue;}
BSTR CLameEncoderXCtrl::GetAlbum() 
{return m_sAlbum.AllocSysString();}
void CLameEncoderXCtrl::SetAlbum(LPCTSTR lpszNewValue) 
{m_sAlbum = lpszNewValue;}
BSTR CLameEncoderXCtrl::GetYear() 
{return m_sYear.AllocSysString();}
void CLameEncoderXCtrl::SetYear(LPCTSTR lpszNewValue) 
{m_sYear = lpszNewValue;}
BSTR CLameEncoderXCtrl::GetComment() 
{return m_sComment.AllocSysString();}
void CLameEncoderXCtrl::SetComment(LPCTSTR lpszNewValue) 
{m_sComment = lpszNewValue;}
BSTR CLameEncoderXCtrl::GetGenre() 
{return m_sGenre.AllocSysString();}
void CLameEncoderXCtrl::SetGenre(LPCTSTR lpszNewValue) 
{m_sGenre =lpszNewValue;}
float CLameEncoderXCtrl::GetResampleFreq() 
{return m_fResampleFreq;}
void CLameEncoderXCtrl::SetResampleFreq(float fNewValue) 
{m_fResampleFreq = fNewValue;}

float CLameEncoderXCtrl::GetEnoderXVersion() 
{
	return 1.2f;
}

void CLameEncoderXCtrl::SetEnoderXVersion(float newValue) 
{
	SetModifiedFlag();
}

BSTR CLameEncoderXCtrl::GetCurrentCommandString() 
{
	long i;
	char Args[30][255];
	char*	lpArgs[30];

	int iArgs;

	for(i=0;i<30;i++)
		lpArgs[i] = Args[i];


	CString strResult = "";

	
	GetCommandString(lpArgs,iArgs);

	for(i=0;i<iArgs;i++)
	{
		strResult += Args[i];
		strResult += " ";
	}

	return strResult.AllocSysString();
}

void CLameEncoderXCtrl::SetAllDefaultParams() 
{
	SetDefaultParams();
}

BSTR CLameEncoderXCtrl::GetTotalEncodingTime() 
{
	CString strResult;
	strResult.Format("%.2d:%.2d:%.2d",m_tsEncodingTime.GetHours(),m_tsEncodingTime.GetMinutes(),m_tsEncodingTime.GetSeconds());
	return strResult.AllocSysString();
}
inline void CLameEncoderXCtrl::Pump()
{
MSG msg;
  // simple message pump that Cancels if WM_QUIT is received
  while(::PeekMessage(&msg, (HWND)NULL, 0, 0, PM_REMOVE)){
    if(msg.message == WM_QUIT)
	{
      //m_bCancel = TRUE;
    }
    ::TranslateMessage(&msg);
    ::DispatchMessage(&msg);
  }
}