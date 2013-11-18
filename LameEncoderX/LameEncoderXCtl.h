#if !defined(AFX_LAMEENCODERXCTL_H__F1253772_C467_11D3_8290_0080C605ADA4__INCLUDED_)
#define AFX_LAMEENCODERXCTL_H__F1253772_C467_11D3_8290_0080C605ADA4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

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

// CLameEncoderXCtrl : See LameEncoderXCtl.cpp for implementation.

 class CLameEncoderXCtrl : public COleControl
{
	DECLARE_DYNCREATE(CLameEncoderXCtrl)

	// Vars
	long				m_lPriority;
	int					m_iSavedPriority;
	CString				m_sInputFile;
	CString				m_sOutputFile;
	CString				m_sLameCommandString;
	CTimeSpan			m_tsEncodingTime;


	//------------------------------------------ Lame Vars -----------------------------------
	//-m mode         (s)tereo, (j)oint, (f)orce or (m)ono  (default %c)\n",DFLT_MOD);
	long				m_lMode;

	  //-b <bitrate>    set the bitrate, default 128kbps\n");
	long				m_lBitrate;

	//-s sfreq        sampling frequency of input file(kHz) - default %4.1f\n",DFLT_SFQ);
	float				m_fInputSampleFreq;

	//--resample sfreq  sampling frequency of output file(kHz)- default=input sfreq\n");
	float				m_fResampleFreq;

	//--mp3input        input file is a MP3 file\n");

	//--voice           experimental voice mode\n");
	BOOL				m_bVoiceMode;

	//-v              use variable bitrate (VBR)\n");
	BOOL				m_bUseVBR;

	//-V n            quality setting for VBR.  default n=%i\n",VBR_q);
    //                0=high quality,bigger files. 9=smaller files\n");
	long				m_lVBRQuality;

	//-b <bitrate>    specify minimum allowed bitrate, default 32kbs\n");
	long				m_lMinimumBitrate;

	//-B <bitrate>    specify maximum allowed bitrate, default 256kbs\n");
	long				m_lMaximumBitrate;

	//-t	          disable Xing VBR informational tag\n");
	BOOL				m_bDisableVBRInfoTag;

	//-h              use (maybe) quality improvements\n");
	BOOL				m_bUseQualityImprovements;

	//-f              fast mode (low quality)\n");
	BOOL				m_bUseFastMode;

	//-k              disable sfb=21 cutoff\n");
	BOOL				m_bDisableSFB;

	//-d              allow channels to have different blocktypes\n");
	BOOL				m_bAllowDifferentBlocktypes;

	//--athonly         only use the ATH for masking\n");
	BOOL				m_bUseOnlyATH;

	//--noshort         do not use short blocks\n");
	BOOL				m_bNoShortBlocks;

	//-r              input is raw pcm\n");
	BOOL				m_bInputIsPCM;

	//-x              force byte-swapping of input\n");
	BOOL				m_bForceByteSwab;

	//-a              downmix from stereo to mono file for mono encoding\n");
	BOOL				m_bForceDownmix;

	//-p              error protection.  adds 16bit checksum to every frame\n");
    //              (the checksum is computed correctly)\n");
	BOOL				m_bUseErrorProtection;

	//-c              mark as copyright\n");
	BOOL				m_bMarkAsCopyright;

	//-o              mark as non-original\n");
	BOOL				m_bMarkAsNonOriginal;


	// Specifying any of the following options will add an ID3 tag:\n");
	//--tt \"title\"     title of song (max 30 chars)\n");
	CString			m_sTitle;

	//--ta \"artist\"    artist who did the song (max 30 chars)\n");
	CString			m_sArtist;

	//--tl \"album\"     album where it came from (max 30 chars)\n");
	CString			m_sAlbum;

	//--ty \"year\"      year in which the song/album was made (max 4 chars)\n");
	CString			m_sYear;

	//--tc \"comment\"   additional info (max 30 chars)\n");
	CString			m_sComment;

	//--tg \"genre\"     genre of song (name or number)\n");
	CString			m_sGenre;


	// Funcs
	void				BumpPriority		();
	void				RestorePriority		();
	void				SetDefaultParams	();
	void				Pump				();
	void				GetCommandString	(char **args,int& nArgs);	
	void				ConcatParam			(CString& sSource,CString sFormat,long lParam);
	void				ConcatParam			(CString& sSource,CString sFormat,float lParam);
	
// Constructor
public:
	CLameEncoderXCtrl();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLameEncoderXCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	virtual DWORD GetControlFlags();
	//}}AFX_VIRTUAL

// Implementation
protected:
	~CLameEncoderXCtrl();

	DECLARE_OLECREATE_EX(CLameEncoderXCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CLameEncoderXCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CLameEncoderXCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CLameEncoderXCtrl)		// Type name and misc status

// Message maps
	//{{AFX_MSG(CLameEncoderXCtrl)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CLameEncoderXCtrl)
	afx_msg BSTR GetInputFile();
	afx_msg void SetInputFile(LPCTSTR lpszNewValue);
	afx_msg BSTR GetOutputFile();
	afx_msg void SetOutputFile(LPCTSTR lpszNewValue);
	afx_msg long GetEncodingPriority();
	afx_msg void SetEncodingPriority(long nNewValue);
	afx_msg long GetMode();
	afx_msg void SetMode(long nNewValue);
	afx_msg long GetBitrate();
	afx_msg void SetBitrate(long nNewValue);
	afx_msg float GetSamplingFreq();
	afx_msg void SetSamplingFreq(float newValue);
	afx_msg BOOL GetVoiceMode();
	afx_msg void SetVoiceMode(BOOL bNewValue);
	afx_msg BOOL GetUseVBR();
	afx_msg void SetUseVBR(BOOL bNewValue);
	afx_msg long GetVBRQuality();
	afx_msg void SetVBRQuality(long nNewValue);
	afx_msg long GetMinimumBitrate();
	afx_msg void SetMinimumBitrate(long nNewValue);
	afx_msg long GetMaximumBitrate();
	afx_msg void SetMaximumBitrate(long nNewValue);
	afx_msg BOOL GetDisableVBRInfoTag();
	afx_msg void SetDisableVBRInfoTag(BOOL bNewValue);
	afx_msg BOOL GetUseQualityImprovements();
	afx_msg void SetUseQualityImprovements(BOOL bNewValue);
	afx_msg BOOL GetUseFastMode();
	afx_msg void SetUseFastMode(BOOL bNewValue);
	afx_msg BOOL GetDisableSFBCutoff();
	afx_msg void SetDisableSFBCutoff(BOOL bNewValue);
	afx_msg BOOL GetAllowChanDifBlockTypes();
	afx_msg void SetAllowChanDifBlockTypes(BOOL bNewValue);
	afx_msg BOOL GetOnlyATHForMasking();
	afx_msg void SetOnlyATHForMasking(BOOL bNewValue);
	afx_msg BOOL GetNoShortBlocks();
	afx_msg void SetNoShortBlocks(BOOL bNewValue);
	afx_msg BOOL GetInputIsRawPCM();
	afx_msg void SetInputIsRawPCM(BOOL bNewValue);
	afx_msg BOOL GetForceByteSwab();
	afx_msg void SetForceByteSwab(BOOL bNewValue);
	afx_msg BOOL GetDownmixToMono();
	afx_msg void SetDownmixToMono(BOOL bNewValue);
	afx_msg BOOL GetErrorProtection();
	afx_msg void SetErrorProtection(BOOL bNewValue);
	afx_msg BOOL GetMarkAsCopyrighted();
	afx_msg void SetMarkAsCopyrighted(BOOL bNewValue);
	afx_msg BOOL GetMarkAsNonOriginal();
	afx_msg void SetMarkAsNonOriginal(BOOL bNewValue);
	afx_msg BSTR GetTitle();
	afx_msg void SetTitle(LPCTSTR lpszNewValue);
	afx_msg BSTR GetArtist();
	afx_msg void SetArtist(LPCTSTR lpszNewValue);
	afx_msg BSTR GetAlbum();
	afx_msg void SetAlbum(LPCTSTR lpszNewValue);
	afx_msg BSTR GetYear();
	afx_msg void SetYear(LPCTSTR lpszNewValue);
	afx_msg BSTR GetComment();
	afx_msg void SetComment(LPCTSTR lpszNewValue);
	afx_msg BSTR GetGenre();
	afx_msg void SetGenre(LPCTSTR lpszNewValue);
	afx_msg float GetResampleFreq();
	afx_msg void SetResampleFreq(float newValue);
	afx_msg float GetEnoderXVersion();
	afx_msg void SetEnoderXVersion(float newValue);
	afx_msg BOOL StartEncode();
	afx_msg BSTR GetCurrentCommandString();
	afx_msg void SetAllDefaultParams();
	afx_msg BSTR GetTotalEncodingTime();
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	//{{AFX_EVENT(CLameEncoderXCtrl)
	void FirePercentComplete(long lPercent, long lSample)
		{FireEvent(eventidPercentComplete,EVENT_PARAM(VTS_I4  VTS_I4), lPercent, lSample);}
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
	//{{AFX_DISP_ID(CLameEncoderXCtrl)
	dispidInputFile = 1L,
	dispidOutputFile = 2L,
	dispidEncodingPriority = 3L,
	dispidMode = 4L,
	dispidBitrate = 5L,
	dispidSamplingFreq = 6L,
	dispidVoiceMode = 7L,
	dispidUseVBR = 8L,
	dispidVBRQuality = 9L,
	dispidMinimumBitrate = 10L,
	dispidMaximumBitrate = 11L,
	dispidDisableVBRInfoTag = 12L,
	dispidUseQualityImprovements = 13L,
	dispidUseFastMode = 14L,
	dispidDisableSFBCutoff = 15L,
	dispidAllowChanDifBlockTypes = 16L,
	dispidOnlyATHForMasking = 17L,
	dispidNoShortBlocks = 18L,
	dispidInputIsRawPCM = 19L,
	dispidForceByteSwab = 20L,
	dispidDownmixToMono = 21L,
	dispidErrorProtection = 22L,
	dispidMarkAsCopyrighted = 23L,
	dispidMarkAsNonOriginal = 24L,
	dispidTitle = 25L,
	dispidArtist = 26L,
	dispidAlbum = 27L,
	dispidYear = 28L,
	dispidComment = 29L,
	dispidGenre = 30L,
	dispidResampleFreq = 31L,
	dispidEnoderXVersion = 32L,
	dispidStartEncode = 33L,
	dispidGetCurrentCommandString = 34L,
	dispidSetAllDefaultParams = 35L,
	dispidGetTotalEncodingTime = 36L,
	eventidPercentComplete = 1L,
	//}}AFX_DISP_ID
	};
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LAMEENCODERXCTL_H__F1253772_C467_11D3_8290_0080C605ADA4__INCLUDED)
