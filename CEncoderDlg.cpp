// CEncoderDlg.cpp : implementation file
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
#include "CEncoderDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEncoderDlg dialog


CEncoderDlg::CEncoderDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEncoderDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEncoderDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_lNumberFiles = 0;
}


void CEncoderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEncoderDlg)
	DDX_Control(pDX, IDC_TOENCODELIST, m_ToEncodeList);
	DDX_Control(pDX, IDC_FILELIST, m_FilesList);
	DDX_Control(pDX, IDC_DIRTREE, m_DirTree);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEncoderDlg, CDialog)
	//{{AFX_MSG_MAP(CEncoderDlg)
	ON_BN_CLICKED(IDC_BUTTONADDFILES, OnButtonaddfiles)
	ON_BN_CLICKED(IDC_BUTTONREMOVE, OnButtonremove)
	ON_NOTIFY(TVN_SELCHANGED, IDC_DIRTREE, OnSelchangedDirtree)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEncoderDlg message handlers

BOOL CEncoderDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	CRect rcRect;

	m_FilesList.GetClientRect(rcRect);
	rcRect.DeflateRect(1,1,1,1);
	m_FilesList.InsertColumn(0,"",LVCFMT_LEFT,rcRect.Width());

	m_ToEncodeList.GetClientRect(rcRect);
	rcRect.DeflateRect(1,1,1,1);
	m_ToEncodeList.InsertColumn(0,"",LVCFMT_LEFT,rcRect.Width());
	
	m_DirTree.DisplayTree(NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
void CEncoderDlg::InitAll()
{
	m_FilesList.DeleteAllItems();
	m_ToEncodeList.DeleteAllItems();
	m_FilesToEncode.clear();
	m_DisplayedFiles.clear();
	m_lNumberFiles = 0;
}
void CEncoderDlg::BuildSourceList()
{
	long i;

	m_ToEncodeList.DeleteAllItems();

	for(i=0;i<m_lNumberFiles;i++)
	{
		m_ToEncodeList.InsertItem(i,m_FilesToEncode[i]);
	}
}
void CEncoderDlg::OnButtonaddfiles() 
{
	long i,j;

	for(i=0;i<m_FilesList.GetItemCount();i++)
	{
		if( (m_FilesList.GetItemState(i,LVIS_SELECTED) & LVIS_SELECTED) != 0)
		{
			BOOL bAdd = TRUE;

			// dont add it twice
			for(j=0;j<m_lNumberFiles;j++)
			{
				if(m_FilesToEncode[j] == m_DisplayedFiles[i])
				{
					bAdd = FALSE;
					break;
				}
			}

			if(bAdd)
			{
				m_FilesToEncode.push_back(m_DisplayedFiles[i]);
				m_lNumberFiles++;
			}
		}
	}
	BuildSourceList();
	
}

void CEncoderDlg::OnButtonremove() 
{
	long i,j;

	deque<CString>	DeleteList;
	long			lNum = 0;


	for(i=0;i<m_ToEncodeList.GetItemCount();i++)
	{
		if( (m_ToEncodeList.GetItemState(i,LVIS_SELECTED) & LVIS_SELECTED) != 0)
		{
			// dont add it twice
			DeleteList.push_back(m_FilesToEncode[i]);
			lNum++;
		}
	}

	for(i=0;i<lNum;i++)
	{
		for(j=0;j<m_lNumberFiles;j++)
		{
			if(m_FilesToEncode[j] == DeleteList[i])
			{
				m_FilesToEncode.erase((m_FilesToEncode.begin()+j));
				m_lNumberFiles--;
				break;
			}
		}
	}
	BuildSourceList();
}

void CEncoderDlg::OnSelchangedDirtree(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;

	CString		sSearchPath;
	CFileFind	ffind;
	long		lItem = 0;
	CString		sPath = m_DirTree.GetFullPath( pNMTreeView->itemNew.hItem );


	sSearchPath.Format("%s\\*.*",sPath);

	m_FilesList.DeleteAllItems();
	m_DisplayedFiles.clear();

	if(ffind.FindFile(sSearchPath))
	{
		BOOL bKeepLooking = TRUE;

		while(bKeepLooking)
		{
			bKeepLooking = ffind.FindNextFile();

			if(ffind.IsDirectory() == FALSE)
			{
				m_DisplayedFiles.push_back(ffind.GetFilePath());
				m_FilesList.InsertItem(lItem++,ffind.GetFileName());
			}
		}
	}
	*pResult = 0;
}
