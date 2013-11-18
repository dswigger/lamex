#if !defined(AFX_LAMEENCODERXPPG_H__F1253774_C467_11D3_8290_0080C605ADA4__INCLUDED_)
#define AFX_LAMEENCODERXPPG_H__F1253774_C467_11D3_8290_0080C605ADA4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// LameEncoderXPpg.h : Declaration of the CLameEncoderXPropPage property page class.

////////////////////////////////////////////////////////////////////////////
// CLameEncoderXPropPage : See LameEncoderXPpg.cpp.cpp for implementation.

class CLameEncoderXPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CLameEncoderXPropPage)
	DECLARE_OLECREATE_EX(CLameEncoderXPropPage)

// Constructor
public:
	CLameEncoderXPropPage();

// Dialog Data
	//{{AFX_DATA(CLameEncoderXPropPage)
	enum { IDD = IDD_PROPPAGE_LAMEENCODERX };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CLameEncoderXPropPage)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LAMEENCODERXPPG_H__F1253774_C467_11D3_8290_0080C605ADA4__INCLUDED)
