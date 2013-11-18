; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CLameXDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "LameX.h"

ClassCount=5
Class1=CLameXApp
Class2=CLameXDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_DIALOGOPTIONS
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Resource4=IDD_LAMEX_DIALOG
Class4=CEncoderDlg
Class5=COptionsDlg
Resource5=IDD_DIALOGENCODER

[CLS:CLameXApp]
Type=0
HeaderFile=LameX.h
ImplementationFile=LameX.cpp
Filter=N

[CLS:CLameXDlg]
Type=0
HeaderFile=LameXDlg.h
ImplementationFile=LameXDlg.cpp
Filter=D
LastObject=IDC_BUTTONENCODE
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=LameXDlg.h
ImplementationFile=LameXDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_LAMEX_DIALOG]
Type=1
Class=CLameXDlg
ControlCount=7
Control1=IDC_STATIC,static,1350569998
Control2=IDC_TAB1,SysTabControl32,1342177280
Control3=IDC_SCURFILE,static,1342308353
Control4=IDC_PROGRESS1,msctls_progress32,1342177281
Control5=IDC_CHECKDELETESOURCES,button,1342242819
Control6=IDC_BUTTONENCODE,button,1342242816
Control7=IDC_LAMEENCODERXCTRL1,{CEA71983-C458-11D3-8290-0080C605ADA4},1073807360

[DLG:IDD_DIALOGOPTIONS]
Type=1
Class=COptionsDlg
ControlCount=39
Control1=IDC_RADIOSTEREO,button,1342177289
Control2=IDC_RADIOJOINT,button,1342177289
Control3=IDC_RADIOFORCE,button,1342177289
Control4=IDC_RADIOMONO,button,1342177289
Control5=IDC_STATIC,button,1342308359
Control6=IDC_COMBOBITRATE,combobox,1344339970
Control7=IDC_EDITINPUTFREQ,edit,1350631552
Control8=IDC_EDITOUTPUTFREQ,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_CHECKVOICEMODE,button,1342242819
Control13=IDC_CHECKUSEVBR,button,1342242819
Control14=IDC_COMBOVBRQUALITY,combobox,1344340226
Control15=IDC_STATIC,static,1342308352
Control16=IDC_COMBOMINBITRATE,combobox,1344339970
Control17=IDC_STATIC,static,1342308352
Control18=IDC_COMBOMAXBITRATE,combobox,1344339970
Control19=IDC_STATIC,static,1342308352
Control20=IDC_CHECKDISABLEINFOTAG,button,1342242819
Control21=IDC_STATIC,button,1342177287
Control22=IDC_CHECKHIGHQUALITY,button,1342242819
Control23=IDC_CHECKFASTMODE,button,1342242819
Control24=IDC_CHECKDISABLESFB,button,1342242819
Control25=IDC_CHECKDIFFBLOCKS,button,1342242819
Control26=IDC_CHECKONLYATH,button,1342242819
Control27=IDC_CHECKNOSHORTBLOCKS,button,1342242819
Control28=IDC_CHECKALLPCM,button,1342242819
Control29=IDC_CHECKBYTESWAB,button,1342242819
Control30=IDC_CHECKDOWNMIX,button,1342242819
Control31=IDC_CHECKUSEERRORPROTECTION,button,1342242819
Control32=IDC_CHECKMARKASCOPYRIGHT,button,1342242819
Control33=IDC_CHECKMARKASNONORIG,button,1342242819
Control34=IDC_STATIC,button,1342177287
Control35=IDC_STATIC,button,1342177287
Control36=IDC_STATIC,button,1342177287
Control37=IDC_COMBOPRIORITY,combobox,1344339970
Control38=IDC_STATIC,static,1342308352
Control39=IDC_BUTTONRESETALL,button,1342242816

[DLG:IDD_DIALOGENCODER]
Type=1
Class=CEncoderDlg
ControlCount=5
Control1=IDC_FILELIST,SysListView32,1350680577
Control2=IDC_DIRTREE,SysTreeView32,1350631431
Control3=IDC_TOENCODELIST,SysListView32,1350680577
Control4=IDC_BUTTONADDFILES,button,1342242816
Control5=IDC_BUTTONREMOVE,button,1342242816

[CLS:CEncoderDlg]
Type=0
HeaderFile=CEncoderDlg.h
ImplementationFile=CEncoderDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CEncoderDlg

[CLS:COptionsDlg]
Type=0
HeaderFile=COptionsDlg.h
ImplementationFile=COptionsDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=COptionsDlg
VirtualFilter=dWC

