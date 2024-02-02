///-----------------------------------------------------------------
///
/// @file      ReadInfoDlg.cpp
/// @author    KLBTech
/// Created:   3/13/2021 6:04:32 AM
/// @section   DESCRIPTION
///            ReadInfoDlg class implementation
///
///------------------------------------------------------------------

#include "ReadInfoDlg.h"
#include <windows.h>
#include <wx/dir.h>
#include <wx/wfstream.h>
#include <wx/txtstrm.h>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <dirent.h>
#include <wx/textfile.h>
#include <wx/wx.h>
#include <wx/utils.h>
#include <wx/string.h>
#include "wx/filename.h"
#include <wx/textctrl.h>
#include <wx/file.h>
#include <wx/txtstrm.h>
#include <wx/stdpaths.h>
#include <wx/stattext.h>




using namespace std;
//Do not add custom headers
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End
class wxDirectoriesEnumerator : public wxDirTraverser {
public:
    virtual bool OnInit();
    wxArrayString *dirs;
    wxArrayString *fils;
    wxDirectoriesEnumerator(wxArrayString* dirs_)  {
        dirs=dirs_;
        fils=dirs_;
    }
    //This function will be called when a file is found
    virtual wxDirTraverseResult OnFile(const wxString& filename) {
        //Do nothing, continue with the next file or directory
        fils->Add(filename);
        return wxDIR_CONTINUE;
    }
    //This function will be called when a directory is found
    virtual wxDirTraverseResult OnDir(const wxString& dirname) {
        //Add the directory to the results
        dirs->Add(dirname);
        //Do NOT enter this directory
        return wxDIR_IGNORE;
    }
};
//----------------------------------------------------------------------------
// ReadInfoDlg
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(ReadInfoDlg,wxDialog)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(ReadInfoDlg::OnClose)
	EVT_ACTIVATE(ReadInfoDlg::ReadInfoDlgActivate)
	EVT_TIMER(ID_WXTIMER1,ReadInfoDlg::WxTimer1Timer)
	EVT_BUTTON(ID_WXBUTTON10,ReadInfoDlg::WxButton10Click)
	
	EVT_TEXT(ID_WXEDIT1,ReadInfoDlg::WxEdit1Updated0)
	EVT_COMBOBOX(ID_WXCOMBOBOX2,ReadInfoDlg::WxComboBox2Selected1)
	EVT_COMBOBOX(ID_WXCOMBOBOX1,ReadInfoDlg::WxComboBox1Selected)
	EVT_BUTTON(ID_WXBUTTON2,ReadInfoDlg::WxButton2Click)
	EVT_BUTTON(ID_WXBUTTON1,ReadInfoDlg::WxButton1Click)
	EVT_LISTBOX(ID_WXLISTBOX1,ReadInfoDlg::WxListBox1Selected)
	EVT_COMBOBOX(ID_WXCOMBOBOX3,ReadInfoDlg::WxComboBox3Selected)
	EVT_CHECKBOX(ID_WXCHECKBOX1,ReadInfoDlg::WxCheckBox1Click)
	EVT_BUTTON(ID_WXBUTTON5,ReadInfoDlg::WxButton5Click)
	EVT_BUTTON(ID_WXBUTTON4,ReadInfoDlg::WxButton4Click)
	EVT_BUTTON(ID_WXBUTTON3,ReadInfoDlg::WxButton3Click)
	EVT_LISTBOX(ID_WXLISTBOX2,ReadInfoDlg::WxListBox2Selected)
	EVT_BUTTON(ID_WXBUTTON8,ReadInfoDlg::WxButton8Click)
	EVT_BUTTON(ID_WXBUTTON7,ReadInfoDlg::WxButton7Click)
	EVT_BUTTON(ID_WXBUTTON6,ReadInfoDlg::WxButton6Click)
END_EVENT_TABLE()
////Event Table End

ReadInfoDlg::ReadInfoDlg(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxDialog(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

ReadInfoDlg::~ReadInfoDlg()
{
} 

void ReadInfoDlg::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End.
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	WxPanel1 = new wxPanel(this, ID_WXPANEL1, wxPoint(-2, -2), wxSize(369, 403));

	WxNotebook1 = new wxNotebook(WxPanel1, ID_WXNOTEBOOK1, wxPoint(13, 7), wxSize(343, 374), wxNB_DEFAULT);

	WxNoteBookPage1 = new wxPanel(WxNotebook1, ID_WXNOTEBOOKPAGE1, wxPoint(4, 26), wxSize(335, 344));
	WxNotebook1->AddPage(WxNoteBookPage1, _("Category Settings"));

	WxStaticBox3 = new wxStaticBox(WxNoteBookPage1, ID_WXSTATICBOX3, _("Edit Category"), wxPoint(7, 3), wxSize(320, 76));

	WxEdit4 = new wxTextCtrl(WxNoteBookPage1, ID_WXEDIT4, _(""), wxPoint(19, 45), wxSize(289, 19), wxSTATIC_BORDER, wxDefaultValidator, _("WxEdit4"));

	WxStaticText7 = new wxStaticText(WxNoteBookPage1, ID_WXSTATICTEXT7, _("Category Name:"), wxPoint(18, 23), wxDefaultSize, 0, _("WxStaticText7"));

	WxButton6 = new wxButton(WxNoteBookPage1, ID_WXBUTTON6, _("WxButton6"), wxPoint(252, 315), wxSize(75, 25), 0, wxDefaultValidator, _("WxButton6"));

	WxButton7 = new wxButton(WxNoteBookPage1, ID_WXBUTTON7, _("WxButton7"), wxPoint(174, 314), wxSize(75, 25), 0, wxDefaultValidator, _("WxButton7"));

	WxButton8 = new wxButton(WxNoteBookPage1, ID_WXBUTTON8, _("WxButton8"), wxPoint(95, 313), wxSize(75, 25), 0, wxDefaultValidator, _("WxButton8"));

	WxStaticBox6 = new wxStaticBox(WxNoteBookPage1, ID_WXSTATICBOX6, _("Select Category"), wxPoint(7, 82), wxSize(319, 224));

	wxArrayString arrayStringFor_WxListBox2;
	WxListBox2 = new wxListBox(WxNoteBookPage1, ID_WXLISTBOX2, wxPoint(18, 105), wxSize(293, 190), arrayStringFor_WxListBox2, wxLB_SINGLE | wxSTATIC_BORDER);

	WxNoteBookPage2 = new wxPanel(WxNotebook1, ID_WXNOTEBOOKPAGE2, wxPoint(4, 26), wxSize(335, 344));
	WxNotebook1->AddPage(WxNoteBookPage2, _("Tools Settings"));

	WxButton3 = new wxButton(WxNoteBookPage2, ID_WXBUTTON3, _("OK"), wxPoint(98, 315), wxSize(75, 25), 0, wxDefaultValidator, _("WxButton3"));

	WxButton4 = new wxButton(WxNoteBookPage2, ID_WXBUTTON4, _("OK"), wxPoint(177, 315), wxSize(75, 25), 0, wxDefaultValidator, _("WxButton4"));

	WxButton5 = new wxButton(WxNoteBookPage2, ID_WXBUTTON5, _("OK"), wxPoint(252, 315), wxSize(75, 25), 0, wxDefaultValidator, _("WxButton5"));

	WxStaticBox2 = new wxStaticBox(WxNoteBookPage2, ID_WXSTATICBOX2, _("Edit Tools "), wxPoint(6, 195), wxSize(321, 116));

	WxEdit3 = new wxTextCtrl(WxNoteBookPage2, ID_WXEDIT3, _(""), wxPoint(18, 231), wxSize(299, 21), wxSTATIC_BORDER, wxDefaultValidator, _("WxEdit3"));

	wxArrayString arrayStringFor_WxComboBox4;
	WxComboBox4 = new wxComboBox(WxNoteBookPage2, ID_WXCOMBOBOX4, _(""), wxPoint(17, 276), wxSize(299, 23), arrayStringFor_WxComboBox4, wxCB_READONLY, wxDefaultValidator, _("WxComboBox4"));

	WxStaticText8 = new wxStaticText(WxNoteBookPage2, ID_WXSTATICTEXT8, _("Set Tool Name:"), wxPoint(19, 212), wxDefaultSize, 0, _("WxStaticText8"));

	WxCheckBox1 = new wxCheckBox(WxNoteBookPage2, ID_WXCHECKBOX1, _("Change Location"), wxPoint(19, 256), wxSize(126, 17), 0, wxDefaultValidator, _("WxCheckBox1"));

	WxStaticBox4 = new wxStaticBox(WxNoteBookPage2, ID_WXSTATICBOX4, _("Select Tools Category"), wxPoint(7, 1), wxSize(320, 52));

	wxArrayString arrayStringFor_WxComboBox3;
	WxComboBox3 = new wxComboBox(WxNoteBookPage2, ID_WXCOMBOBOX3, _(""), wxPoint(18, 22), wxSize(298, 23), arrayStringFor_WxComboBox3, wxCB_READONLY, wxDefaultValidator, _("WxComboBox3"));

	WxStaticBox5 = new wxStaticBox(WxNoteBookPage2, ID_WXSTATICBOX5, _("Select Tools"), wxPoint(7, 55), wxSize(321, 137));

	wxArrayString arrayStringFor_WxListBox1;
	WxListBox1 = new wxListBox(WxNoteBookPage2, ID_WXLISTBOX1, wxPoint(18, 77), wxSize(299, 104), arrayStringFor_WxListBox1, wxLB_SINGLE | wxSTATIC_BORDER);

	WxNoteBookPage3 = new wxPanel(WxNotebook1, ID_WXNOTEBOOKPAGE3, wxPoint(4, 26), wxSize(335, 344));
	WxNotebook1->AddPage(WxNoteBookPage3, _("Information Settings"));

	WxButton1 = new wxButton(WxNoteBookPage3, ID_WXBUTTON1, _("CLOSE"), wxPoint(252, 318), wxSize(73, 24), 0, wxDefaultValidator, _("WxButton1"));

	WxButton2 = new wxButton(WxNoteBookPage3, ID_WXBUTTON2, _("SAVE"), wxPoint(158, 318), wxSize(89, 24), 0, wxDefaultValidator, _("WxButton2"));

	wxArrayString arrayStringFor_WxComboBox1;
	WxComboBox1 = new wxComboBox(WxNoteBookPage3, ID_WXCOMBOBOX1, _(""), wxPoint(98, 8), wxSize(228, 23), arrayStringFor_WxComboBox1, wxSTATIC_BORDER | wxCB_READONLY, wxDefaultValidator, _("WxComboBox1"));

	wxArrayString arrayStringFor_WxComboBox2;
	WxComboBox2 = new wxComboBox(WxNoteBookPage3, ID_WXCOMBOBOX2, _(""), wxPoint(98, 35), wxSize(228, 23), arrayStringFor_WxComboBox2, wxSTATIC_BORDER | wxCB_READONLY, wxDefaultValidator, _("WxComboBox2"));

	WxEdit1 = new wxTextCtrl(WxNoteBookPage3, ID_WXEDIT1, _(""), wxPoint(12, 63), wxSize(314, 222), wxSTATIC_BORDER | wxTE_MULTILINE, wxDefaultValidator, _("WxEdit1"));
	WxEdit1->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_CAPTIONTEXT));

	WxEdit2 = new wxTextCtrl(WxNoteBookPage3, ID_WXEDIT2, _(""), wxPoint(11, 290), wxSize(236, 19), wxSTATIC_BORDER, wxDefaultValidator, _("WxEdit2"));
	WxEdit2->Enable(false);

	WxButton10 = new wxButton(WxNoteBookPage3, ID_WXBUTTON10, _("BROWSE"), wxPoint(251, 287), wxSize(75, 25), 0, wxDefaultValidator, _("WxButton10"));
	WxButton10->Enable(false);

	WxStaticText5 = new wxStaticText(WxNoteBookPage3, ID_WXSTATICTEXT5, _("Tools Category:"), wxPoint(11, 10), wxDefaultSize, 0, _("WxStaticText5"));

	WxStaticText13 = new wxStaticText(WxNoteBookPage3, ID_WXSTATICTEXT13, _("Tools Name:"), wxPoint(13, 39), wxDefaultSize, 0, _("WxStaticText13"));

	WxGauge1 = new wxGauge(WxPanel1, ID_WXGAUGE1, 100, wxPoint(0, 386), wxSize(368, 17), wxGA_HORIZONTAL, wxDefaultValidator, _("WxGauge1"));
	WxGauge1->SetRange(100);
	WxGauge1->SetValue(0);

	WxStaticText15 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT15, _("WxStaticText15"), wxPoint(446, 229), wxDefaultSize, 0, _("WxStaticText15"));

	WxStaticText14 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT14, _("WxStaticText14"), wxPoint(429, 188), wxDefaultSize, 0, _("WxStaticText14"));

	WxStaticText3 = new wxStaticText(this, ID_WXSTATICTEXT3, _("WxStaticText3"), wxPoint(688, 12), wxDefaultSize, 0, _("WxStaticText3"));

	WxStaticText2 = new wxStaticText(this, ID_WXSTATICTEXT2, _("Category: "), wxPoint(624, 13), wxDefaultSize, 0, _("WxStaticText2"));

	WxStaticText1 = new wxStaticText(this, ID_WXSTATICTEXT1, _("Tools Name: "), wxPoint(621, 36), wxDefaultSize, 0, _("WxStaticText1"));

	WxStaticText4 = new wxStaticText(this, ID_WXSTATICTEXT4, _("WxStaticText4"), wxPoint(694, 34), wxDefaultSize, 0, _("WxStaticText4"));

	WxStaticText6 = new wxStaticText(this, ID_WXSTATICTEXT6, _("WxStaticText6"), wxPoint(637, 71), wxDefaultSize, 0, _("WxStaticText6"));

	WxStaticText9 = new wxStaticText(this, ID_WXSTATICTEXT9, _("WxStaticText9"), wxPoint(640, 127), wxDefaultSize, 0, _("WxStaticText9"));

	WxStaticText10 = new wxStaticText(this, ID_WXSTATICTEXT10, _("WxStaticText10"), wxPoint(644, 149), wxDefaultSize, 0, _("WxStaticText10"));

	WxStaticText11 = new wxStaticText(this, ID_WXSTATICTEXT11, _("WxStaticText11"), wxPoint(592, 200), wxDefaultSize, 0, _("WxStaticText11"));

	WxStaticText12 = new wxStaticText(this, ID_WXSTATICTEXT12, _("WxStaticText12"), wxPoint(596, 222), wxDefaultSize, 0, _("WxStaticText12"));

	WxTimer1 = new wxTimer();
	WxTimer1->SetOwner(this, ID_WXTIMER1);

	WxStaticText16 = new wxStaticText(this, ID_WXSTATICTEXT16, _("WxStaticText16"), wxPoint(551, 112), wxDefaultSize, 0, _("WxStaticText16"));

	SetTitle(_("ReadInfoDlg"));
	SetIcon(wxNullIcon);
	SetSize(8,8,372,426);
	Center();
	
	////GUI Items Creation End
}

void ReadInfoDlg::OnClose(wxCloseEvent& /*event*/)
{
    if(WxStaticText16->GetLabel()=="importSave"){
    }else{
        ofstream config;
        config.open("Data\\Resources\\klbsoft.temp\\tmpSettings.txt"); 
        config << "\n";
        config << ""+WxComboBox3->GetValue();
        config << "\n\n\nWARNING!!! DO NOT DELETE!!! (c) 2020-2021, KLBSoft. All Rights Reserve.";
        config.close();
                    
        wxString tempFilePath = "Data\\Resources\\klbsoft.temp\\.tmp$MenuFile";  // Change this to your desired file path
    
        wxFile tempFile;
        if (tempFile.Create(tempFilePath, true)) {
            const char* data = "WARNING!!! DO NOT DELETE!!! (c) 2020-2021, KLBSoft. All Rights Reserve.";
            tempFile.Write(data, strlen(data));
            tempFile.Close();
        } 
    }
    WxStaticText16->SetLabel("");
    
	Destroy();
}

/*
 * WxComboBox1Selected
 */
void ReadInfoDlg::WxComboBox1Selected(wxCommandEvent& event )
{
    remove("Data\\Resources\\klbsoft.temp\\data_config.txt");
    remove("Data\\Resources\\klbsoft.temp\\ReadME!.txt");
    remove("Data\\Resources\\klbsoft.temp\\.tmpKLBSoft040194$.tmp");
    WxEdit1->Clear();
    WxEdit1->SetValue("No Info. loaded. Click 'VIEW INFO' button to load ("+WxComboBox2->GetValue()+") Info.");
    WxEdit1->Enable(false);
    WxComboBox2->Clear();
    wxArrayString dirList2;
    wxDirectoriesEnumerator traverser2(&dirList2);
    wxDir fils("Data\\Programs\\"+WxComboBox1->GetValue()+"\\");
    if(fils.IsOpened()){
    fils.Traverse(traverser2);
    for(unsigned int i=0; i<dirList2.GetCount(); i++) {
    WxComboBox2->Append(dirList2.Item(i).AfterLast('\\').AfterLast('/').BeforeLast('.'));
    WxComboBox2->SetSelection(0);
    }};
    
    if(WxComboBox2->GetValue().IsEmpty()){
        WxButton2->SetLabel("OK");
        WxButton2->Enable(false);
    }
    else{
        WxButton2->Enable(true);
        WxButton2->SetLabel("VIEW INFO");
    }
}

/*
 * WxComboBox2Selected
 */
void ReadInfoDlg::WxComboBox2Selected(wxCommandEvent& event )
{
    WxEdit2->Clear();
    
}

/*
 * ReadInfoDlgActivate
 */
void ReadInfoDlg::ReadInfoDlgActivate(wxActivateEvent& event)
{
    
}

/*
 * WxButton2Click
 */
void ReadInfoDlg::WxButton2Click(wxCommandEvent& event)
{
    if(WxButton2->GetLabel()=="VIEW INFO"){
        remove("Data\\Resources\\klbsoft.temp\\ReadME!.txt");
        remove("Data\\Resources\\klbsoft.temp\\.tmpKLBSoft040194$.tmp");
        WxStaticText14->SetLabel("vInfo");
        WxTimer1->Start(100);
        ShellExecute(NULL,NULL,_T("cmd.exe"), _T("/c Data\\uharc.exe x -pw@@!!klbSoft$$2020!!@@ -t""Data\\Resources\\klbsoft.temp\\"" -y+ \"Data\\Programs\\"+WxComboBox1->GetValue()+"\\"+WxComboBox2->GetValue()+".uha\" & echo WARNING!!! DO NOT DELETE!!! MASISIRA ANG BUHAY MO :)!!! - (c) 2020-2021 KLBSoft. All Rights Reserve.> Data\\Resources\\klbsoft.temp\\.tmpKLBSoft040194$.tmp"),NULL,SW_HIDE);      
    }else if(WxButton2->GetLabel()=="SAVE"){
        int ans=wxMessageBox("Save Info?","Continue?",wxICON_WARNING|wxYES_NO);
        if(ans==wxYES){   
            ofstream config;
            config.open(WxStaticText6->GetLabel()+"\\ReadME!.txt");      
            config << ""+WxEdit1->GetValue();
            config.close(); 
            this->Close();
        }
    }else if(WxButton2->GetLabel()=="EDIT"){
        WxEdit1->Enable(true);
        WxEdit1->SetEditable(true);
        WxEdit1->SelectAll();
        WxEdit1->SetFocus();
        WxButton10->Enable(true);
        WxButton2->SetLabel("UPDATE");
        WxButton1->SetLabel("CANCEL");
        WxComboBox1->Enable(false);
        WxComboBox2->Enable(false);
    }else{
        int ans=wxMessageBox("Update '"+WxComboBox2->GetValue()+"' Info.?","UPDATE_INFO",wxICON_WARNING|wxYES_NO);
        if(ans==wxYES){
            remove("Data\\Resources\\klbsoft.temp\\.tmpKLBSoft040194$.tmp");
            remove("Data\\Programs\\"+WxComboBox1->GetValue()+"\\"+WxComboBox2->GetValue()+".uha");
            ifstream uReadme;
            uReadme.open("Data\\Resources\\klbsoft.temp\\ReadME!.txt");
            if(uReadme){
                ofstream config;
                config.open("Data\\Resources\\klbsoft.temp\\ReadME!.txt");      
                config << ""+WxEdit1->GetValue();
                config.close(); 
                WxStaticText14->SetLabel("uInfo");
                WxTimer1->Start(100);
                ShellExecute(NULL,NULL,_T("cmd.exe"), _T("/c Data\\uharc.exe a -r+ -ed- -pe -mx -mm+ -md32768 -pw@@!!klbSoft$$2020!!@@ -y+ \"Data\\Programs\\"+WxComboBox1->GetValue()+"\\"+WxComboBox2->GetValue()+".uha\" Data\\Resources\\klbsoft.temp\\"),NULL,SW_HIDE); 
            }else{
                ofstream config;
                config.open("Data\\Resources\\klbsoft.temp\\ReadME!.txt");      
                config << ""+WxEdit1->GetValue();
                config.close(); 
                WxStaticText14->SetLabel("uInfo");
                WxTimer1->Start(100);
                ShellExecute(NULL,NULL,_T("cmd.exe"), _T("/c Data\\uharc.exe a -r+ -ed- -pe -mx -mm+ -md32768 -pw@@!!klbSoft$$2020!!@@ -y+ \"Data\\Programs\\"+WxComboBox1->GetValue()+"\\"+WxComboBox2->GetValue()+".uha\" Data\\Resources\\klbsoft.temp\\"),NULL,SW_HIDE);    
            }
        }
    }
}

/*
 * WxButton1Click
 */
void ReadInfoDlg::WxButton1Click(wxCommandEvent& event)
{
    if(WxButton1->GetLabel()=="CANCEL"){
        WxEdit1->Enable(true);
        WxEdit1->SetEditable(false);
        WxButton2->SetLabel("EDIT");
        WxButton1->SetLabel("CLOSE");
        WxButton10->Enable(false);
        WxComboBox1->Enable(true);
        WxComboBox2->Enable(true);
    }else{
        this->Close();
    }
	// insert your code here
}

/*
 * WxEdit2Enter
 */
void ReadInfoDlg::WxEdit2Enter(wxCommandEvent& event)
{
   
	// insert your code here
}

/*
 * WxEdit2Updated
 */
void ReadInfoDlg::WxEdit2Updated(wxCommandEvent& event)
{
    if(WxButton2->GetLabel()!="SAVE"){
        WxButton2->Enable(true);
        WxButton2->SetLabel("UPDATE");
    }
}

/*
 * WxListBox1Selected
 */
void ReadInfoDlg::WxListBox1Selected(wxCommandEvent& event)
{
    WxButton3->Enable(true);
    WxButton3->SetLabel("UPDATE");
    WxButton4->Enable(true);
    WxButton4->SetLabel("DELETE");
    WxButton5->SetLabel("CANCEL");
    WxStaticBox2->SetLabel("Edit Tools ("+WxListBox1->GetStringSelection()+" )");
    WxStaticText9->SetLabel(WxListBox1->GetStringSelection());
    WxEdit3->SetValue(WxListBox1->GetStringSelection());
    WxEdit3->SetFocus();
    WxEdit3->SelectAll();
	// insert your code here
}

/*
 * WxComboBox3Selected
 */
void ReadInfoDlg::WxComboBox3Selected(wxCommandEvent& event )
{
    WxButton3->Enable(false);
    WxButton3->SetLabel("UPDATE");
    WxButton4->Enable(false);
    WxButton4->SetLabel("OK");
    WxButton5->SetLabel("CLOSE");
    
    WxStaticBox2->SetLabel("");
    WxEdit3->Clear();
    wxArrayString dirList;
    wxDirectoriesEnumerator traverser(&dirList);
    wxDir dir("Data\\Programs\\"+WxComboBox3->GetStringSelection()+"\\");
    if(dir.IsOpened()){
    dir.Traverse(traverser);
    WxListBox1->Clear();
    for(unsigned int i=0; i<dirList.GetCount(); i++) {
    WxListBox1->Append(dirList.Item(i).AfterLast('\\').AfterLast('/').BeforeLast('.')); 
    }};
    
    WxComboBox4->SetSelection(WxComboBox3->GetSelection());
}

/*
 * WxButton5Click
 */
void ReadInfoDlg::WxButton5Click(wxCommandEvent& event)
{
    if(WxButton5->GetLabel()=="CANCEL"){
        int ans=wxMessageBox("Are you sure you want to cancel?","Continue?",wxICON_WARNING|wxYES_NO);
        if(ans==wxYES){
            WxStaticBox2->SetLabel("Edit Tools");
            WxButton3->Enable(false);
            WxButton4->SetLabel("OK");
            WxButton4->Enable(false);
            WxButton5->SetLabel("CLOSE");
            WxEdit3->Clear();
            WxListBox1->Deselect(0);
            
        }
    }else{
        Close();
    }

	// insert your code here
}

/*
 * WxButton3Click
 */
void ReadInfoDlg::WxButton3Click(wxCommandEvent& event)
{
    if(WxButton3->GetLabel()=="UPDATE"){
        if(WxEdit3->GetValue().IsEmpty()){
            wxMessageBox("Tools Name should not be empty!", "EMPTY_FIELD_ERROR", wxICON_ERROR | wxOK);
        }else{
            if(WxCheckBox1->IsChecked()){
                int ans=wxMessageBox("Move '"+WxStaticText9->GetLabel()+" (Tools)'  to  '"+WxComboBox4->GetValue()+" (Directory)' ?","MOVE_TO_NEW_LOCATION",wxICON_WARNING|wxYES_NO);
                if(ans==wxYES){
                    remove("Data\\Resources\\klbsoft.temp\\.tmpKLBSoft040194$.tmp"); 
                    WxStaticText14->SetLabel("mvFile");
                    WxTimer1->Start(100);
                    ShellExecute(NULL,NULL,_T("cmd.exe"), _T("/c TIMEOUT /T 2 /NOBREAK & echo %DATE%::%TIME% WARNING!!! DO NOT DELETE!!! > Data\\Resources\\klbsoft.temp\\.tmpKLBSoft040194$.tmp"),NULL,SW_HIDE); 
                }else{
                } 
            }else{  
                remove("Data\\Resources\\klbsoft.temp\\.tmpKLBSoft040194$.tmp"); 
                WxStaticText14->SetLabel("renFile");
                WxTimer1->Start(100);
                ShellExecute(NULL,NULL,_T("cmd.exe"), _T("/c TIMEOUT /T 2 /NOBREAK & echo %DATE%::%TIME% WARNING!!! DO NOT DELETE!!! > Data\\Resources\\klbsoft.temp\\.tmpKLBSoft040194$.tmp"),NULL,SW_HIDE);    
            }         
        }
    }else{
    }
}

void ReadInfoDlg::WxListBox2Selected(wxCommandEvent& event)
{
   WxEdit4->SetValue(WxListBox2->GetStringSelection()); 
   WxStaticText10->SetLabel(WxListBox2->GetStringSelection()); 
   WxEdit4->SetFocus();
   WxEdit4->SelectAll();
   
   WxButton8->SetLabel("UPDATE");
   WxButton7->SetLabel("DELETE");
   WxButton7->Enable(true);
   WxButton6->SetLabel("CANCEL");
}

/*
 * WxButton6Click
 */
void ReadInfoDlg::WxButton6Click(wxCommandEvent& event)
{
    if(WxButton6->GetLabel()=="CANCEL"){     
        int ans=wxMessageBox("Are you sure you want to cancel?","Continue?",wxICON_WARNING|wxYES_NO);
        if(ans==wxYES){
            WxEdit4->Clear();
            WxEdit4->SetFocus();
            WxButton8->SetLabel("ADD");
            WxButton7->SetLabel("OK");
            WxButton7->Enable(false);
            WxButton6->SetLabel("CLOSE");
            WxListBox2->Deselect(0);
        }
    }else{
        Close();
    }
}

/*
 * WxButton8Click
 */
void ReadInfoDlg::WxButton8Click(wxCommandEvent& event)
{
    if(WxButton8->GetLabel()=="UPDATE"){
        
        remove("Data\\Resources\\klbsoft.temp\\.tmpKLBSoft040194$.tmp"); 
        WxStaticText14->SetLabel("renCat");
        
        int ans = wxMessageBox(wxString::Format("Updating '%s' will rename it to '%s', \nProceed?", WxStaticText10->GetLabel(), WxEdit4->GetValue()), "Rename Category.", wxICON_WARNING|wxYES_NO);    
        if(ans == wxYES){
            WxTimer1->Start(100);
            ShellExecute(NULL,NULL,_T("cmd.exe"), _T("/c TIMEOUT /T 2 /NOBREAK & echo %DATE%::%TIME% WARNING!!! DO NOT DELETE!!! > Data\\Resources\\klbsoft.temp\\.tmpKLBSoft040194$.tmp "),NULL,SW_HIDE);      
        }else{
        }     
    }else{
        remove("Data\\Resources\\klbsoft.temp\\.tmpKLBSoft040194$.tmp"); 
        WxStaticText14->SetLabel("addCat");
        int ans = wxMessageBox(wxString::Format("You are about to add '%s' as a new 'Tools Category', \nProceed?", WxEdit4->GetValue()), "New Category.", wxICON_QUESTION|wxYES_NO);    
        if(ans == wxYES){
            WxTimer1->Start(100);        
            ShellExecute(NULL,NULL,_T("cmd.exe"), _T("/c TIMEOUT /T 2 /NOBREAK & echo %DATE%::%TIME% WARNING!!! DO NOT DELETE!!! > Data\\Resources\\klbsoft.temp\\.tmpKLBSoft040194$.tmp "),NULL,SW_HIDE);      
        }else{
        } 
    }
}

/*
 * WxButton7Click
 */
void ReadInfoDlg::WxButton7Click(wxCommandEvent& event)
{
    if(WxButton7->GetLabel()=="DELETE"){
        remove("Data\\Resources\\klbsoft.temp\\.tmpKLBSoft040194$.tmp");
        WxStaticText14->SetLabel("delCat");
        int ans=wxMessageBox("Deleting '"+WxEdit4->GetValue()+"', will also delete all of it's contents.\n Are you sure?","Warning.",wxICON_WARNING|wxYES_NO);
        if(ans==wxYES){
            WxTimer1->Start(100);
            ShellExecute(NULL,NULL,_T("cmd.exe"), _T("/c TIMEOUT /T 2 /NOBREAK & echo %DATE%::%TIME% WARNING!!! DO NOT DELETE!!! > Data\\Resources\\klbsoft.temp\\.tmpKLBSoft040194$.tmp"),NULL,SW_HIDE);      
        }
    }else{
    }
}

/*
 * WxNotebook1PageChanging
 */
void ReadInfoDlg::WxNotebook1PageChanging(wxNotebookEvent& event)
{
    
    //wxMessageBox(WxNotebook1->GetSelection(0));
	// insert your code here
}

/*
 * WxCheckBox1Click
 */
void ReadInfoDlg::WxCheckBox1Click(wxCommandEvent& event)
{
    if(WxCheckBox1->IsChecked()){
        
        WxComboBox4->Enable(true);
    }else{
        WxComboBox4->SetSelection(WxComboBox3->GetSelection());
        WxComboBox4->Enable(false);
    }
	// insert your code here
}

/*
 * WxButton4Click
 */
void ReadInfoDlg::WxButton4Click(wxCommandEvent& event)
{
    if(WxButton4->GetLabel()=="DELETE"){
        int ans=wxMessageBox("Delete "+WxEdit3->GetValue()+"?","CONTINUE?",wxICON_WARNING|wxYES_NO);
        if(ans==wxYES){
            
            remove("Data\\Resources\\klbsoft.temp\\.tmpKLBSoft040194$.tmp"); 
            WxStaticText14->SetLabel("delFile");
            WxTimer1->Start(100);
            ShellExecute(NULL,NULL,_T("cmd.exe"), _T("/c TIMEOUT /T 2 /NOBREAK & echo %DATE%::%TIME% WARNING!!! DO NOT DELETE!!! > Data\\Resources\\klbsoft.temp\\.tmpKLBSoft040194$.tmp "),NULL,SW_HIDE);    
            
        }
    }

	// insert your code here
}

void ReadInfoDlg::WxEdit1Updated(wxCommandEvent& event)
{
    
	// insert your code here{

}

/*
 * WxCheckBox2Click
 */
void ReadInfoDlg::WxCheckBox2Click(wxCommandEvent& event)
{        
        
	// insert your code here
}

/*
 * WxEdit1Updated0
 */
void ReadInfoDlg::WxEdit1Updated0(wxCommandEvent& event)
{
    if(WxStaticText12->GetLabel()=="addInfo" | WxComboBox2->GetValue()=="ReadME!.txt"){
    }else{
        WxButton2->Enable(true);
        WxButton2->SetLabel("UPDATE");
    }
	// insert your code here
}

/*
 * WxComboBox2Selected0
 */
void ReadInfoDlg::WxComboBox2Selected0(wxCommandEvent& event )
{
    
    //WxStaticText5->SetLabel(" Ready...");
    //WxStaticText13->SetLabel(" "+WxComboBox2->GetValue()+" ");
    
}

/*
 * WxComboBox2Updated
 */
void ReadInfoDlg::WxComboBox2Updated(wxCommandEvent& event )
{
    
	// insert your code here
}

/*
 * WxButton9Click
 */
void ReadInfoDlg::WxButton9Click(wxCommandEvent& event)
{
    
     ofstream config;
            config.open(WxStaticText6->GetLabel()+"\\ReadME!.txt");      
            config << ""+WxEdit1->GetValue();
            config.close(); 
            this->Close();
	// insert your code here



}

/*
 * WxTimer1Timer
 */
void ReadInfoDlg::WxTimer1Timer(wxTimerEvent& event)
{
    if(WxStaticText14->GetLabel()=="mvFile"){
        wxString filePath = "Data\\Resources\\klbsoft.temp\\.tmpKLBSoft040194$.tmp";
        if (wxFileName::FileExists(filePath)){
            WxGauge1->SetValue(0);
            WxTimer1->Stop();
            
            wxString oldFileName = wxT("Data\\Programs\\") + WxComboBox3->GetValue() + wxT("\\") + WxListBox1->GetStringSelection() + wxT(".uha");
            wxString newFileName = wxT("Data\\Programs\\") + WxComboBox4->GetValue() + wxT("\\") + WxEdit3->GetValue() + wxT(".uha");
            
            if(MoveFile(oldFileName.c_str(), newFileName.c_str())){ 
                wxMessageBox("' "+WxListBox1->GetStringSelection()+ " ' has been move to ' " + WxComboBox4->GetValue() +" ' \n as ' "+WxEdit3->GetValue()+" '" , "File Moved", wxICON_INFORMATION | wxOK);    
            }else{
                wxMessageBox("Failed to rename the file.", "RENAME_ERROR", wxICON_ERROR | wxOK);
            }  
                wxArrayString dirList;
                wxDirectoriesEnumerator traverser(&dirList);
                wxDir dir("Data\\Programs\\"+WxComboBox3->GetValue()+"\\");
                if(dir.IsOpened()){
                dir.Traverse(traverser);
                WxListBox1->Clear();
                for(unsigned int i=0; i<dirList.GetCount(); i++) {
                WxListBox1->Append(dirList.Item(i).AfterLast('\\').AfterLast('/').BeforeLast('.')); }};
                
                WxButton3->Enable(false);
                WxButton4->SetLabel("OK");
                WxButton4->Enable(false);
                WxButton5->SetLabel("CLOSE");
                WxEdit3->Clear();
                WxEdit1->SetValue("No Info. loaded. Click 'VIEW INFO' button to load ("+WxComboBox2->GetValue()+") Info.");
                WxEdit1->Enable(false);
                WxButton2->SetLabel("VIEW INFO");
                WxEdit3->Clear();
                WxStaticBox2->SetLabel("");
                WxCheckBox1->SetValue(1);
                WxButton3->Enable(false);
                WxButton4->SetLabel("OK");
                WxButton4->Enable(false);
                WxButton5->SetLabel("CLOSE");
                WxStaticBox2->SetLabel("Edit Tools");
                WxEdit3->Clear();
        }else{
            int counter= 1000;
            counter++;
            WxGauge1->SetValue(counter % (WxGauge1->GetRange()+ 1));
        } 
    }else if (WxStaticText14->GetLabel()=="renFile"){
        
        wxString filePath = "Data\\Resources\\klbsoft.temp\\.tmpKLBSoft040194$.tmp";
        if (wxFileName::FileExists(filePath)){
            WxGauge1->SetValue(0);
            WxTimer1->Stop();
            
            wxString oldFileName = wxT("Data\\Programs\\") + WxComboBox3->GetValue() + wxT("\\") + WxListBox1->GetStringSelection() + wxT(".uha");
            wxString newFileName = wxT("Data\\Programs\\") + WxComboBox4->GetValue() + wxT("\\") + WxEdit3->GetValue() + wxT(".uha");
            
            if(MoveFile(oldFileName.c_str(), newFileName.c_str())){
                WxComboBox2->Clear();
                wxArrayString dirList;
                wxDirectoriesEnumerator traverser(&dirList);
                wxDir dir("Data\\Programs\\"+WxComboBox3->GetValue()+"\\");
                if(dir.IsOpened()){
                dir.Traverse(traverser);
                WxListBox1->Clear();
                for(unsigned int i=0; i<dirList.GetCount(); i++) {
                WxComboBox2->Append(dirList.Item(i).AfterLast('\\').AfterLast('/').BeforeLast('.'));
                WxListBox1->Append(dirList.Item(i).AfterLast('\\').AfterLast('/').BeforeLast('.'));}};
                WxComboBox2->SetSelection(0);
                WxEdit3->Clear();
                WxStaticBox2->SetLabel("");
                WxButton3->Enable(false);
                WxButton4->SetLabel("OK");
                WxButton4->Enable(false);
                WxButton5->SetLabel("CLOSE");
                WxEdit1->SetValue("No Info. loaded. Click 'VIEW INFO' button to load ("+WxComboBox2->GetValue()+") Info.");
                WxEdit1->Enable(false);
                WxStaticBox2->SetLabel("Edit Tools");
                WxButton2->SetLabel("VIEW INFO");
                WxEdit3->Clear();
                wxMessageBox("File has been UPDATED.", "RENAME_SUCCESS", wxICON_INFORMATION | wxOK);
            }else{
                wxMessageBox("Failed to rename the file.", "RENAME_ERROR", wxICON_ERROR | wxOK);
            }
        }else{
            int counter= 1000;
            counter++;
            WxGauge1->SetValue(counter % (WxGauge1->GetRange()+ 1));
        }
    }else if (WxStaticText14->GetLabel()=="delFile"){
        
        wxString filePath = "Data\\Resources\\klbsoft.temp\\.tmpKLBSoft040194$.tmp";
        if (wxFileName::FileExists(filePath)){
            WxGauge1->SetValue(0);
            WxTimer1->Stop();
            
             if( remove("Data\\Programs\\"+WxComboBox3->GetValue()+"\\"+WxListBox1->GetStringSelection()+".uha") != 0 ){
                wxMessageBox("Error deleting FILE. ","DELETE_ERROR",wxICON_ERROR|wxOK); 
             }else{
                WxListBox1->Clear();
                WxComboBox2->Clear();
                wxArrayString dirList;
                wxDirectoriesEnumerator traverser(&dirList);
                wxDir dir("Data\\Programs\\"+WxComboBox3->GetValue()+"\\");
                if(dir.IsOpened()){
                dir.Traverse(traverser);
                WxListBox1->Clear();
                for(unsigned int i=0; i<dirList.GetCount(); i++) {
                WxComboBox2->Append(dirList.Item(i).AfterLast('\\').AfterLast('/').BeforeLast('.'));
                WxListBox1->Append(dirList.Item(i).AfterLast('\\').AfterLast('/').BeforeLast('.'));}}; 
                
                WxComboBox2->SetSelection(0);
                WxEdit3->Clear();
                WxStaticBox2->SetLabel("");
                WxButton3->Enable(false);
                WxButton4->SetLabel("OK");
                WxButton4->Enable(false);
                WxButton5->SetLabel("CLOSE");
                WxEdit3->Clear();
                
                if(WxComboBox2->GetValue().IsEmpty()){
                    WxEdit1->SetValue("");
                    WxEdit1->Enable(false);
                    WxButton2->SetLabel("OK");
                    WxButton2->Enable(false);
                }else{
                    WxEdit1->SetValue("No Info. loaded. Click 'VIEW INFO' button to load ("+WxComboBox2->GetValue()+") Info.");
                    WxEdit1->Enable(false);
                    WxButton2->SetLabel("VIEW INFO");
                }
                wxMessageBox("Delete SUCCESS!","DELETE_SUCCESS",wxICON_INFORMATION|wxOK); 
            }
        }else{
            int counter= 1000;
            counter++;
            WxGauge1->SetValue(counter % (WxGauge1->GetRange()+ 1)); 
        }
        
         
    }else if(WxStaticText14->GetLabel()=="renCat"){
        wxString filePath = "Data\\Resources\\klbsoft.temp\\.tmpKLBSoft040194$.tmp";
        if (wxFileName::FileExists(filePath)){
            WxGauge1->SetValue(0);
            WxTimer1->Stop();

            wxString oldFolderPath = wxT("Data\\Programs\\" + WxStaticText10->GetLabel() + "\\");
            wxString newFolderName = WxEdit4->GetValue().Trim();
            if (newFolderName.IsEmpty()) {
                wxMessageBox("New folder name cannot be empty.", "Error", wxICON_ERROR | wxOK);
                return;
            }
            wxString newFolderPath = wxT("Data\\Programs\\" + newFolderName + "\\");
        
            if (wxFileName::DirExists(newFolderPath)) {
                wxMessageBox(wxString::Format("Category '%s' already exists. Choose a different name.", newFolderName), "Rename Error", wxICON_ERROR | wxOK);
                return;
            }
            wxString command = wxT("cmd.exe /c rename \"") + oldFolderPath + wxT("\" \"") + newFolderName + wxT("\"");
            int result = wxExecute(command, wxEXEC_HIDE_CONSOLE | wxEXEC_NODISABLE);
        
            if (wxFileName::DirExists(oldFolderPath) || wxFileName::DirExists(newFolderPath)) {
                wxMessageBox(wxString::Format("Category renamed successfully."), "Rename Success", wxICON_INFORMATION | wxOK);
            } else {
                wxMessageBox(wxString::Format("Failed to rename Category from '%s' to '%s'.", oldFolderPath, newFolderPath), "Rename Error", wxICON_ERROR | wxOK);
            }
            
                if(WxListBox2->GetStringSelection()==WxComboBox3->GetValue()){
                    wxArrayString dirList;
                    wxDirectoriesEnumerator traverser(&dirList);
                    wxDir dir("Data\\Programs\\");
                    if(dir.IsOpened()){
                    dir.Traverse(traverser);
                    WxComboBox3->Clear();
                    WxListBox2->Clear();
                    for(unsigned int i=0; i<dirList.GetCount(); i++) {
                    WxListBox2->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
                    WxComboBox3->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
                    WxComboBox3->SetStringSelection(WxEdit4->GetValue());
                    }}; 
                    wxArrayString dirList2;
                    wxDirectoriesEnumerator traverser2(&dirList2);
                    wxDir dir2("Data\\Programs\\"+WxComboBox3->GetValue()+"\\");
                    if(dir2.IsOpened()){
                    dir2.Traverse(traverser2);
                    WxListBox1->Clear();
                    for(unsigned int i=0; i<dirList2.GetCount(); i++) {
                    WxListBox1->Append(dirList2.Item(i).AfterLast('\\').AfterLast('/').BeforeLast('.'));
                    }};
                      
                    WxEdit4->Clear();
                    WxEdit4->SetFocus();
                    WxButton8->SetLabel("ADD");
                    WxButton7->SetLabel("OK");
                    WxButton7->Enable(false);
                    WxButton6->SetLabel("CLOSE");
                }else{
                    wxArrayString dirList2;
                    wxDirectoriesEnumerator traverser2(&dirList2);
                    wxDir dir2("Data\\Programs\\"+WxComboBox3->GetValue()+"\\");
                    if(dir2.IsOpened()){
                    dir2.Traverse(traverser2);
                    WxListBox1->Clear();
                    for(unsigned int i=0; i<dirList2.GetCount(); i++) {
                    WxListBox1->Append(dirList2.Item(i).AfterLast('\\').AfterLast('/').BeforeLast('.'));
                    }};
                      
                    WxEdit4->Clear();
                    WxEdit4->SetFocus();
                    WxButton8->SetLabel("ADD");
                    WxButton7->SetLabel("OK");
                    WxButton7->Enable(false);
                    WxButton6->SetLabel("CLOSE");
                }
                
            WxEdit4->Clear();
            WxEdit4->SetFocus();
            WxButton8->SetLabel("ADD");
            WxButton7->SetLabel("OK");
            WxButton7->Enable(false);
            WxButton6->SetLabel("CLOSE");   
        }else{
            int counter= 1000;
            counter++;
            WxGauge1->SetValue(counter % (WxGauge1->GetRange()+ 1)); 
        }
        
    }else if(WxStaticText14->GetLabel()=="delCat"){
        wxString filePath = "Data\\Resources\\klbsoft.temp\\.tmpKLBSoft040194$.tmp";
        if (wxFileName::FileExists(filePath)){
            WxGauge1->SetValue(0);
            WxTimer1->Stop();
            
            std::string category = std::string(WxEdit4->GetValue());
            std::string folderPath = "Data\\Programs\\" + category;
            wxString command = wxT("cmd.exe /c RMDIR /S /Q \"") + wxString(folderPath) + wxT("\"");
            wxArrayString output;
            int result = wxExecute(command, output, wxEXEC_HIDE_CONSOLE | wxEXEC_NODISABLE);
        
            if (result == -1) {
                wxMessageBox("Error executing command.", "Error", wxOK | wxICON_ERROR, this);
            } else {
                if (!output.IsEmpty()) {
                    wxMessageBox("Error deleting category:\n", "Error", wxOK | wxICON_ERROR, this);
                } else {
                    
                    if(WxListBox2->GetStringSelection()==WxComboBox3->GetValue()){
                        wxArrayString dirList;
                        wxDirectoriesEnumerator traverser(&dirList);
                        wxDir dir("Data\\Programs\\");
                        if(dir.IsOpened()){
                        dir.Traverse(traverser);
                        WxComboBox3->Clear();
                        WxListBox2->Clear();
                        for(unsigned int i=0; i<dirList.GetCount(); i++) {
                        WxListBox2->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
                        WxComboBox3->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
                        WxComboBox3->SetSelection(0);
                        }}; 
    
                        wxArrayString dirList2;
                        wxDirectoriesEnumerator traverser2(&dirList2);
                        wxDir dir2("Data\\Programs\\"+WxComboBox3->GetValue()+"\\");
                        if(dir2.IsOpened()){
                        dir2.Traverse(traverser2);
                        WxListBox1->Clear();
                        for(unsigned int i=0; i<dirList2.GetCount(); i++) {
                        WxListBox1->Append(dirList2.Item(i).AfterLast('\\').AfterLast('/').BeforeLast('.'));
                        }};
                          
                        WxEdit4->Clear();
                        WxEdit4->SetFocus();
                        WxButton8->SetLabel("ADD");
                        WxButton7->SetLabel("OK");
                        WxButton7->Enable(false);
                        WxButton6->SetLabel("CLOSE");
                        wxMessageBox("Category has been DELETED.", "DELETE_SUCCESS", wxICON_INFORMATION | wxOK, this);
                    }else{
                        wxArrayString dirList;
                        wxDirectoriesEnumerator traverser(&dirList);
                        wxDir dir("Data\\Programs\\");
                        if(dir.IsOpened()){
                        dir.Traverse(traverser);
                        WxComboBox3->Clear();
                        WxListBox2->Clear();
                        for(unsigned int i=0; i<dirList.GetCount(); i++) {
                        WxListBox2->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
                        WxComboBox3->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
                        WxComboBox3->SetStringSelection(WxStaticText15->GetLabel());
                        }}; 
    
                        wxArrayString dirList2;
                        wxDirectoriesEnumerator traverser2(&dirList2);
                        wxDir dir2("Data\\Programs\\"+WxComboBox3->GetValue()+"\\");
                        if(dir2.IsOpened()){
                        dir2.Traverse(traverser2);
                        WxListBox1->Clear();
                        for(unsigned int i=0; i<dirList2.GetCount(); i++) {
                        WxListBox1->Append(dirList2.Item(i).AfterLast('\\').AfterLast('/').BeforeLast('.'));
                        }};
                          
                        WxEdit4->Clear();
                        WxEdit4->SetFocus();
                        WxButton8->SetLabel("ADD");
                        WxButton7->SetLabel("OK");
                        WxButton7->Enable(false);
                        WxButton6->SetLabel("CLOSE");
                        wxMessageBox("Category has been DELETED.", "DELETE_SUCCESS", wxICON_INFORMATION | wxOK, this);
                    }
                }
            }
                     
        }else{
            int counter= 1000;
            counter++;
            WxGauge1->SetValue(counter % (WxGauge1->GetRange()+ 1)); 
        } 
    }else if(WxStaticText14->GetLabel()=="addCat"){
        WxStaticText15->SetLabel(WxComboBox3->GetValue());
        wxString filePath = "Data\\Resources\\klbsoft.temp\\.tmpKLBSoft040194$.tmp";
        if (wxFileName::FileExists(filePath)){
            WxGauge1->SetValue(0);
            WxTimer1->Stop();
            
            wxString category = WxEdit4->GetValue().Trim();
            if (category.IsEmpty()) {
                wxMessageBox("Please enter a valid category name.", "EMPTY_CATEGORY_NAME_ERROR", wxICON_ERROR | wxOK, this);
                return;
            }
            wxString folderPath = "Data\\Programs\\" + category;
            if (wxFileName::DirExists(folderPath)) {
                wxMessageBox("Category already exists. Choose a different name.", "DUPLICATE_CATEGORY_ERROR", wxICON_ERROR | wxOK, this);
            } else {
                if (!wxFileName::Mkdir(folderPath, wxS_DIR_DEFAULT, wxPATH_MKDIR_FULL)) {
                    wxMessageBox("Error creating category. Please try again.", "CREATE_CATEGORY_ERROR", wxOK | wxICON_ERROR, this);
                } else {
                    
                    wxArrayString dirList;
                    wxDirectoriesEnumerator traverser(&dirList);
                    wxDir dir("Data\\Programs\\");
                    if(dir.IsOpened()){
                    dir.Traverse(traverser);
                    WxComboBox3->Clear();
                    WxListBox2->Clear();
                    for(unsigned int i=0; i<dirList.GetCount(); i++) {
                    WxListBox2->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
                    WxComboBox3->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
                    WxComboBox3->SetStringSelection(WxStaticText15->GetLabel());
                    }}; 

                    wxArrayString dirList2;
                    wxDirectoriesEnumerator traverser2(&dirList2);
                    wxDir dir2("Data\\Programs\\"+WxComboBox3->GetValue()+"\\");
                    if(dir2.IsOpened()){
                    dir2.Traverse(traverser2);
                    WxListBox1->Clear();
                    for(unsigned int i=0; i<dirList2.GetCount(); i++) {
                    WxListBox1->Append(dirList2.Item(i).AfterLast('\\').AfterLast('/').BeforeLast('.'));
                    }};
                    
                    WxEdit4->Clear();
                    WxEdit4->SetFocus();
    
                    wxMessageBox("Category folder has been created.", "Create Success", wxICON_INFORMATION | wxOK, this);
                }
            }  
        }else{
            int counter= 1000;
            counter++;
            WxGauge1->SetValue(counter % (WxGauge1->GetRange()+ 1)); 
        } 
        
    }else if(WxStaticText14->GetLabel()=="vInfo"){
        wxString filePath = "Data\\Resources\\klbsoft.temp\\.tmpKLBSoft040194$.tmp";///CS001 temp file for settings code 001
        if (wxFileName::FileExists(filePath)){
            WxGauge1->SetValue(0);
            WxTimer1->Stop();
            
            std::ifstream configFile("Data\\Resources\\klbsoft.temp\\ReadME!.txt");
            if (!configFile) {
                WxEdit1->Clear();
                WxEdit2->Clear();
                WxEdit1->SetValue("No Info. AVAILABLE.");
                WxButton2->SetLabel("EDIT");
                WxButton2->Enable(true);
                WxEdit1->Enable(true);
                WxEdit1->SetEditable(false);
            }else{
                WxEdit1->Clear();
                WxEdit2->Clear();
                WxEdit1->Enable(true);
                WxEdit1->SetEditable(false);
                wxFileInputStream input(wxT("Data\\Resources\\klbsoft.temp\\ReadME!.txt"));
                wxTextInputStream text(input,wxT("\x09"),wxConvUTF8);
                while(input.IsOk()&& !input.Eof()){
                wxString line=text.ReadLine();
                WxEdit1->AppendText(line+"\n");}
                WxButton2->SetLabel("EDIT");
                WxButton2->Enable(true);
            }
        }else{
            int counter= 1000;
            counter++;
            WxGauge1->SetValue(counter % (WxGauge1->GetRange()+ 1)); 
        } 
        
    }else if(WxStaticText14->GetLabel()=="uInfo"){
         wxString filePath = "Data\\Programs\\"+WxComboBox1->GetValue()+"\\"+WxComboBox2->GetValue()+".uha";
        if (wxFileName::FileExists(filePath)){
            WxGauge1->SetValue(0);
            WxTimer1->Stop();
            wxMessageBox("Info. has been UPDATED.","UPDATE_INFO",wxICON_INFORMATION|wxOK);
            WxButton2->SetLabel("EDIT");
            WxButton2->Enable(true);
            WxButton10->Enable(false);
            WxButton1->SetLabel("CLOSE");
            WxComboBox1->Enable(true);
            WxComboBox2->Enable(true);
            WxEdit1->Enable(true);
            WxEdit1->SetEditable(false);
        }else{
            int counter= 1000;
            counter++;
            WxGauge1->SetValue(counter % (WxGauge1->GetRange()+ 1)); 
        } 
        
    }else{
    }
            
	// insert your code here
}

 
void ReadInfoDlg::WxButton10Click(wxCommandEvent& event)
{
     wxFileDialog openFileDialog(this, wxT("Open Text File"), wxT(""), wxT(""), wxT("Text files (*.txt)|*.txt|All files (*.*)|*.*"), wxFD_OPEN | wxFD_FILE_MUST_EXIST);
        if (openFileDialog.ShowModal() == wxID_CANCEL) {
            return; 
        }
        WxEdit1->Clear();
        wxString filePath = openFileDialog.GetPath();
        wxFileName fileName(filePath);
        if (!fileName.IsFileReadable()) {
            wxMessageBox(wxT("File is not readable or does not exist."), wxT("Error"), wxICON_ERROR | wxOK);
            return;
        }
        wxString fileContent;
        if (wxFileExists(filePath)) {
            wxFile file(filePath);
            if (file.IsOpened()) {
                wxFileOffset length = file.Length();
                wxCharBuffer buf(length);
                file.Read(buf.data(), length);
                fileContent = wxString::FromUTF8(buf);
            } else {
                wxMessageBox(wxT("Failed to open file for reading."), wxT("Error"), wxICON_ERROR | wxOK);
                return;
            }
        } else {
            wxMessageBox(wxT("File does not exist."), wxT("Error"), wxICON_ERROR | wxOK);
            return;
        }
        WxEdit1->AppendText(fileContent);
        WxEdit2->SetValue(filePath);
	
}

/*
 * WxButton9Click0
 */
 
 
void ReadInfoDlg::WxButton9Click0(wxCommandEvent& event)
{
}

/*
 * WxComboBox2Selected1
 */
void ReadInfoDlg::WxComboBox2Selected1(wxCommandEvent& event )
{
    remove("Data\\Resources\\klbsoft.temp\\ReadME!.txt");
    remove("Data\\_tmp.tmp");
     
    WxEdit1->Clear();
    WxEdit1->SetValue("No Info. loaded. Click 'VIEW INFO' button to load ("+WxComboBox2->GetValue()+") Info.");
    WxEdit1->Enable(false);
    WxButton2->Enable(true);
    WxButton2->SetLabel("VIEW INFO");
    WxEdit2->Clear();
    
	// insert your code here
}
