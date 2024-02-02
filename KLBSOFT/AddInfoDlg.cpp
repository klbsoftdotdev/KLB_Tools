///-----------------------------------------------------------------
///
/// @file      AddInfoDlg.cpp
/// @author    KLBTech
/// Created:   3/12/2021 3:56:14 AM
/// @section   DESCRIPTION
///            AddInfoDlg class implementation
///
///------------------------------------------------------------------

#include "AddInfoDlg.h"
#include <wx/textfile.h>
#include <wx/dir.h>
#include <wx/wfstream.h>
#include <wx/txtstrm.h>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <dirent.h>
#include <stdio.h>
#pragma comment(lib, "user32.lib")
#include <tchar.h>
#include <unistd.h>
#include <conio.h>

using namespace std;
//Do not add custom headers
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// AddInfoDlg
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(AddInfoDlg,wxDialog)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(AddInfoDlg::OnClose)
	EVT_ACTIVATE(AddInfoDlg::AddInfoDlgActivate)
	
	EVT_UPDATE_UI(ID_WXPANEL1,AddInfoDlg::WxPanel1UpdateUI)
END_EVENT_TABLE()
////Event Table End

AddInfoDlg::AddInfoDlg(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxDialog(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

AddInfoDlg::~AddInfoDlg()
{
} 

void AddInfoDlg::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End.
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	WxPanel1 = new wxPanel(this, ID_WXPANEL1, wxPoint(0, -1), wxSize(458, 292));

	WxStaticBox1 = new wxStaticBox(WxPanel1, ID_WXSTATICBOX1, _("WxStaticBox1"), wxPoint(6, 5), wxSize(444, 57));

	WxStaticBox2 = new wxStaticBox(WxPanel1, ID_WXSTATICBOX2, _("WxStaticBox2"), wxPoint(7, 66), wxSize(444, 188));

	WxButton1 = new wxButton(WxPanel1, ID_WXBUTTON1, _("WxButton1"), wxPoint(360, 25), wxSize(75, 25), 0, wxDefaultValidator, _("WxButton1"));

	WxEdit1 = new wxTextCtrl(WxPanel1, ID_WXEDIT1, _("WxEdit1"), wxPoint(22, 29), wxSize(324, 19), 0, wxDefaultValidator, _("WxEdit1"));

	wxArrayString arrayStringFor_WxComboBox1;
	WxComboBox1 = new wxComboBox(WxPanel1, ID_WXCOMBOBOX1, _("WxComboBox1"), wxPoint(19, 89), wxSize(415, 23), arrayStringFor_WxComboBox1, 0, wxDefaultValidator, _("WxComboBox1"));

	wxArrayString arrayStringFor_WxListBox1;
	WxListBox1 = new wxListBox(WxPanel1, ID_WXLISTBOX1, wxPoint(19, 120), wxSize(414, 117), arrayStringFor_WxListBox1, wxLB_SINGLE);

	WxButton2 = new wxButton(WxPanel1, ID_WXBUTTON2, _("WxButton2"), wxPoint(377, 259), wxSize(75, 25), 0, wxDefaultValidator, _("WxButton2"));

	WxButton3 = new wxButton(WxPanel1, ID_WXBUTTON3, _("WxButton3"), wxPoint(291, 259), wxSize(75, 25), 0, wxDefaultValidator, _("WxButton3"));

	WxStaticText1 = new wxStaticText(this, ID_WXSTATICTEXT1, _("WxStaticText1"), wxPoint(486, 22), wxDefaultSize, 0, _("WxStaticText1"));

	WxStaticText2 = new wxStaticText(this, ID_WXSTATICTEXT2, _("WxStaticText2"), wxPoint(488, 52), wxDefaultSize, 0, _("WxStaticText2"));

	SetTitle(_("AddInfoDlg"));
	SetIcon(wxNullIcon);
	SetSize(8,8,694,328);
	Center();
	
	////GUI Items Creation End
}

void AddInfoDlg::OnClose(wxCloseEvent& /*event*/)
{
	Destroy();
}

/*
 * WxButton1Click
 */
void AddInfoDlg::WxButton1Click(wxCommandEvent& event)
{
    this->Close();
	// insert your code here
}

/*
 * WxPanel1UpdateUI
 */
void AddInfoDlg::WxPanel1UpdateUI(wxUpdateUIEvent& event)
{
	// insert your code here
}

/*
 * AddInfoDlgActivate
 */
void AddInfoDlg::AddInfoDlgActivate(wxActivateEvent& event)
{
    
    
	// insert your code here
}

/*
 * WxButton2Click
 */


/*
 * WxButton2Click
 */
void AddInfoDlg::WxButton2Click(wxCommandEvent& event)
{
    // int ans=wxMessageBox("Save Info?, you will never be able to undo?","Continue?",wxICON_WARNING|wxYES_NO);
//     if(ans==wxYES){
//        ofstream config;
//        config.open(WxStaticText1->GetLabel()+"\\CONFIG_INFO.TXT");      
//        config << ""+WxEdit1->GetValue();
//        config.close();
//        
//        wxTextFile file(wxT(""+WxStaticText1->GetLabel()+"\\CONFIG_INFO.TXT"));
//        file.Open();
//        file.AddLine(wxT("\n\n\n=========================================\nCopyright (c) 2020-2021, KLBTech."));
//        //file.AddLine(wxT("Copyright (©) 2020-2021, KLBTech."));
//        file.Write();
//        file.Close();
//        this->Close();
//    }
    
}
