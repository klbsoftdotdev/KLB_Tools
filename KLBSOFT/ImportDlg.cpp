///-----------------------------------------------------------------
///
/// @file      ImportDlg.cpp
/// @author    KLBTech
/// Created:   3/11/2021 7:57:11 PM
/// @section   DESCRIPTION
///            ImportDlg class implementation
///
///------------------------------------------------------------------

#include "ImportDlg.h"
#include "AddInfoDlg.h"
#include "ReadInfoDlg.h"
#include <iostream>
#include <fstream>
#include <wx/dir.h>
#include <wx/filefn.h>
#include <wx/filename.h>


using namespace std;

//Do not add custom headers
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End
class wxDirectoriesEnumerator : public wxDirTraverser {
public:
    wxArrayString *dirs;
    wxArrayString *fils;
    wxDirectoriesEnumerator(wxArrayString* dirs_)  {
        dirs=dirs_;
        fils=dirs_;
    }
    virtual wxDirTraverseResult OnFile(const wxString& filename) {
        fils->Add(filename);
        return wxDIR_CONTINUE;
    }
    virtual wxDirTraverseResult OnDir(const wxString& dirname) {
        dirs->Add(dirname);
        return wxDIR_IGNORE;
    }
};
//----------------------------------------------------------------------------
// ImportDlg
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(ImportDlg,wxDialog)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(ImportDlg::OnClose)
	EVT_ACTIVATE(ImportDlg::ImportDlgActivate)
	EVT_TIMER(ID_WXTIMER1,ImportDlg::WxTimer1Timer)
	EVT_BUTTON(ID_WXBUTTON7,ImportDlg::WxButton7Click0)
	EVT_BUTTON(ID_WXBUTTON5,ImportDlg::WxButton5Click0)
	EVT_LISTBOX(ID_WXLISTBOX1,ImportDlg::WxListBox1Selected)
	EVT_BUTTON(ID_WXBUTTON4,ImportDlg::WxButton4Click0)
	EVT_COMBOBOX(ID_WXCOMBOBOX2,ImportDlg::WxComboBox2Selected)
	EVT_TEXT_ENTER(ID_WXEDIT5,ImportDlg::WxEdit5Enter)
	EVT_BUTTON(ID_WXBUTTON1,ImportDlg::WxButton1Click)
	EVT_BUTTON(ID_WXBUTTON3,ImportDlg::WxButton3Click)
	EVT_BUTTON(ID_WXBUTTON2,ImportDlg::WxButton2Click)
	
	EVT_UPDATE_UI(ID_WXPANEL1,ImportDlg::WxPanel1UpdateUI)
END_EVENT_TABLE()
////Event Table End

ImportDlg::ImportDlg(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxDialog(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

ImportDlg::~ImportDlg()
{
} 

void ImportDlg::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End.
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	WxPanel1 = new wxPanel(this, ID_WXPANEL1, wxPoint(-2, -2), wxSize(340, 339));

	WxStaticBox2 = new wxStaticBox(WxPanel1, ID_WXSTATICBOX2, _("Target Folder"), wxPoint(6, 4), wxSize(327, 47));

	WxButton2 = new wxButton(WxPanel1, ID_WXBUTTON2, _("CLOSE"), wxPoint(258, 289), wxSize(74, 25), wxSTATIC_BORDER, wxDefaultValidator, _("WxButton2"));

	WxButton3 = new wxButton(WxPanel1, ID_WXBUTTON3, _("IMPORT"), wxPoint(180, 289), wxSize(73, 25), wxSTATIC_BORDER, wxDefaultValidator, _("WxButton3"));
	WxButton3->Enable(false);

	WxButton1 = new wxButton(WxPanel1, ID_WXBUTTON1, _("BROWSE"), wxPoint(246, 21), wxSize(77, 22), 0, wxDefaultValidator, _("WxButton1"));

	WxEdit4 = new wxTextCtrl(WxPanel1, ID_WXEDIT4, _(""), wxPoint(19, 24), wxSize(221, 19), wxSTATIC_BORDER, wxDefaultValidator, _("WxEdit4"));

	WxStaticBox3 = new wxStaticBox(WxPanel1, ID_WXSTATICBOX3, _("Select Category"), wxPoint(6, 235), wxSize(326, 52));

	wxArrayString arrayStringFor_WxComboBox1;
	WxComboBox1 = new wxComboBox(WxPanel1, ID_WXCOMBOBOX1, _(""), wxPoint(19, 254), wxSize(302, 23), arrayStringFor_WxComboBox1, wxCB_READONLY, wxDefaultValidator, _("WxComboBox1"));

	WxStaticBox4 = new wxStaticBox(WxPanel1, ID_WXSTATICBOX4, _("Enter Tools Name"), wxPoint(6, 51), wxSize(327, 47));

	WxEdit5 = new wxTextCtrl(WxPanel1, ID_WXEDIT5, _(""), wxPoint(19, 71), wxSize(302, 19), wxSTATIC_BORDER, wxDefaultValidator, _("WxEdit5"));

	WxStaticBox1 = new wxStaticBox(WxPanel1, ID_WXSTATICBOX1, _("Options"), wxPoint(7, 101), wxSize(325, 133));

	wxArrayString arrayStringFor_WxComboBox2;
	arrayStringFor_WxComboBox2.Add(_("Cross-Platform Application"));
	arrayStringFor_WxComboBox2.Add(_("Combine 32-bit & 64-bit Application"));
	arrayStringFor_WxComboBox2.Add(_("32-bit Application"));
	arrayStringFor_WxComboBox2.Add(_("64-bit Application"));
	WxComboBox2 = new wxComboBox(WxPanel1, ID_WXCOMBOBOX2, _("Cross-Platform Application"), wxPoint(20, 120), wxSize(299, 23), arrayStringFor_WxComboBox2, wxSTATIC_BORDER | wxCB_DROPDOWN | wxCB_READONLY, wxDefaultValidator, _("WxComboBox2"));

	WxEdit1 = new wxTextCtrl(WxPanel1, ID_WXEDIT1, _(""), wxPoint(20, 149), wxSize(105, 19), wxSTATIC_BORDER, wxDefaultValidator, _("WxEdit1"));
	WxEdit1->Enable(false);
	WxEdit1->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_GRAYTEXT));
	WxEdit1->SetFont(wxFont(9, wxSWISS, wxITALIC, wxNORMAL, false));

	WxButton4 = new wxButton(WxPanel1, ID_WXBUTTON4, _("<<"), wxPoint(129, 148), wxSize(46, 22), 0, wxDefaultValidator, _("WxButton4"));
	WxButton4->Enable(false);

	wxArrayString arrayStringFor_WxListBox1;
	WxListBox1 = new wxListBox(WxPanel1, ID_WXLISTBOX1, wxPoint(179, 148), wxSize(140, 77), arrayStringFor_WxListBox1, wxLB_SINGLE | wxSTATIC_BORDER);
	WxListBox1->Enable(false);

	WxEdit2 = new wxTextCtrl(WxPanel1, ID_WXEDIT2, _(""), wxPoint(20, 174), wxSize(105, 19), wxSTATIC_BORDER, wxDefaultValidator, _("WxEdit2"));
	WxEdit2->Enable(false);
	WxEdit2->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_GRAYTEXT));
	WxEdit2->SetFont(wxFont(9, wxSWISS, wxITALIC, wxNORMAL, false));

	WxButton5 = new wxButton(WxPanel1, ID_WXBUTTON5, _("<<"), wxPoint(129, 172), wxSize(46, 22), 0, wxDefaultValidator, _("WxButton5"));
	WxButton5->Enable(false);

	WxButton7 = new wxButton(WxPanel1, ID_WXBUTTON7, _("Add/Import Info."), wxPoint(19, 201), wxSize(156, 25), 0, wxDefaultValidator, _("WxButton7"));
	WxButton7->Enable(false);

	WxGauge1 = new wxGauge(WxPanel1, ID_WXGAUGE1, 100, wxPoint(1, 319), wxSize(338, 17), wxGA_HORIZONTAL, wxDefaultValidator, _("WxGauge1"));
	WxGauge1->SetRange(100);
	WxGauge1->SetValue(0);

	WxStaticText1 = new wxStaticText(this, ID_WXSTATICTEXT1, _("WxStaticText1"), wxPoint(827, 10), wxDefaultSize, 0, _("WxStaticText1"));

	WxStaticText2 = new wxStaticText(this, ID_WXSTATICTEXT2, _("WxStaticText2"), wxPoint(829, 33), wxDefaultSize, 0, _("WxStaticText2"));

	WxStaticText4 = new wxStaticText(this, ID_WXSTATICTEXT4, _("WxStaticText4"), wxPoint(823, 52), wxDefaultSize, 0, _("WxStaticText4"));

	WxStaticText5 = new wxStaticText(this, ID_WXSTATICTEXT5, _("WxStaticText5"), wxPoint(827, 72), wxDefaultSize, 0, _("WxStaticText5"));

	WxStaticText8 = new wxStaticText(this, ID_WXSTATICTEXT8, _("WxStaticText8"), wxPoint(820, 97), wxDefaultSize, 0, _("WxStaticText8"));

	WxStaticText9 = new wxStaticText(this, ID_WXSTATICTEXT9, _("WxStaticText9"), wxPoint(821, 125), wxDefaultSize, 0, _("WxStaticText9"));

	WxStaticText10 = new wxStaticText(this, ID_WXSTATICTEXT10, _("WxStaticText10"), wxPoint(819, 149), wxDefaultSize, 0, _("WxStaticText10"));

	WxStaticText11 = new wxStaticText(this, ID_WXSTATICTEXT11, _("WxStaticText11"), wxPoint(823, 166), wxDefaultSize, 0, _("WxStaticText11"));

	WxStaticText12 = new wxStaticText(this, ID_WXSTATICTEXT12, _("WxStaticText12"), wxPoint(827, 197), wxDefaultSize, 0, _("WxStaticText12"));

	WxStaticText13 = new wxStaticText(this, ID_WXSTATICTEXT13, _("WxStaticText13"), wxPoint(820, 221), wxDefaultSize, 0, _("WxStaticText13"));

	WxStaticText14 = new wxStaticText(this, ID_WXSTATICTEXT14, _("WxStaticText14"), wxPoint(822, 251), wxDefaultSize, 0, _("WxStaticText14"));

	WxDirDialog1 =  new wxDirDialog(this, _("Choose a directory"), _(""));

	WxOpenFileDialog1 =  new wxFileDialog(this, _("Choose a file"), _(""), _(""), _("*.*"), wxFD_OPEN);

	WxTimer1 = new wxTimer();
	WxTimer1->SetOwner(this, ID_WXTIMER1);

	WxStaticText3 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT3, _("WxStaticText3"), wxPoint(19, 295), wxDefaultSize, 0, _("WxStaticText3"));

	SetTitle(_("Create Tools Config"));
	SetIcon(wxNullIcon);
	SetSize(8,8,343,359);
	Center();
	
	////GUI Items Creation End
}

void ImportDlg::OnClose(wxCloseEvent& /*event*/)
{
    ofstream config;
    config.open("Data\\Resources\\klbsoft.temp\\tmpSettings.txt"); 
    config << "\n";
    config << ""+WxComboBox1->GetValue();
    config << "\n\n\nWARNING!!! DO NOT DELETE!!! (c) 2020-2021, KLBSoft. All Rights Reserve.";
    config.close();
    
    
     wxString tempFilePath = "Data\\Resources\\klbsoft.temp\\.tmp$MenuFile";  // Change this to your desired file path

    wxFile tempFile;
    if (tempFile.Create(tempFilePath, true)) {
        const char* data = "WARNING!!! DO NOT DELETE!!! (c) 2020-2021, KLBSoft. All Rights Reserve.";
        tempFile.Write(data, strlen(data));
        tempFile.Close();
    }
    
	Destroy();
}

/*
 * WxButton2Click
 */
void ImportDlg::WxButton2Click(wxCommandEvent& event)
{
    this->Close();
	// insert your code here
}

/*
 * WxButton1Click
 */
void ImportDlg::WxButton1Click(wxCommandEvent& event)
{
    if (WxDirDialog1->ShowModal() == wxID_OK)
    {
         wxString selectedFolder = WxDirDialog1->GetPath();
            wxString folderName = wxFileName(selectedFolder).GetFullName();
            WxEdit5->SetValue(folderName);
        WxEdit1->SetValue("Tools.exe");
        WxEdit1->Enable(true);
        WxEdit2->Enable(false);
        WxEdit2->Clear();
        WxListBox1->Enable(true);
        WxButton4->SetLabel("<<");
        WxButton5->SetLabel("<<");
        WxButton4->Enable(true);
        WxButton5->Enable(false);
        WxButton7->Enable(true);
        WxComboBox1->Clear();
        WxComboBox1->Enable(true);
        WxComboBox2->Enable(true);
        
        WxEdit4->SetLabel(WxDirDialog1->GetPath());
        //WxEdit5->SetValue(WxDirDialog1->GetFullName());
        wxArrayString dirList2;
        wxDirectoriesEnumerator traverser2(&dirList2);
        wxDir dir("Data\\Programs\\");
        if(dir.IsOpened()){
        dir.Traverse(traverser2);
        for(unsigned int i=0; i<dirList2.GetCount(); i++) {
        WxComboBox1->Append(dirList2.Item(i).AfterLast('\\').AfterLast('/'));
        WxComboBox1->SetSelection(0);
        }};
        
        WxListBox1->Clear();
        wxArrayString dirList;
        wxDirectoriesEnumerator traverser(&dirList);
        wxDir fils(WxEdit4->GetLabel()+"\\");
        if(fils.IsOpened()){
        fils.Traverse(traverser);
        for(unsigned int i=0; i<dirList.GetCount(); i++) {
        WxListBox1->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
        }};
        WxButton3->Enable(true);
        //WxCheckBox1->Enable(true);
//        WxCheckBox2->Enable(true);
        WxEdit5->SetFocus();  
        WxComboBox2->SetSelection(0);
        
    } 
    
    
    
    
    //if (WxDirDialog1->ShowModal() == wxID_OK) {
//    // Set values and enable/disable controls
//    //WxCheckBox1->SetValue(true);
//    WxEdit1->SetValue("Tools.exe");
//    WxEdit3->SetValue("Attach .chm Info.");
//    WxEdit1->Enable(true);
//    WxEdit2->Enable(false);
//    WxEdit2->Clear();
//    WxListBox1->Enable(true);
//    WxEdit3->Enable(true);
//    WxButton4->SetLabel("<<");
//    WxButton5->SetLabel("<<");
//    WxButton6->SetLabel("<<");
//    WxButton4->Enable(true);
//    WxButton5->Enable(false);
//    WxButton6->Enable(true);
//    WxButton7->Enable(true);
//
//    // Populate WxComboBox1 with plugin names
//    WxComboBox1->Clear();
//    WxEdit4->SetLabel(WxDirDialog1->GetPath());
//    wxArrayString pluginList;
//    wxDirectoriesEnumerator pluginTraverser(&pluginList);
//    wxDir pluginDir("Data\\Programs\\");
//    if (pluginDir.IsOpened()) {
//        pluginDir.Traverse(pluginTraverser);
//        for (const auto& plugin : pluginList) {
//            WxComboBox1->Append(plugin.AfterLast('\\').AfterLast('/'));
//        }
//        WxComboBox1->SetSelection(0);
//    }
//
//    // Populate WxListBox1 with directory names
//    WxListBox1->Clear();
//    wxArrayString dirList;
//    wxDirectoriesEnumerator dirTraverser(&dirList);
//    wxDir files(WxEdit4->GetLabel() + "\\");
//    if (files.IsOpened()) {
//        files.Traverse(dirTraverser);
//        for (const auto& directory : dirList) {
//            WxListBox1->Append(directory.AfterLast('\\').AfterLast('/'));
//        }
//    }
//
//    // Enable controls and set focus
//    WxButton3->Enable(true);
//    WxCheckBox1->Enable(true);
//    WxCheckBox2->Enable(true);
//    WxEdit5->SetFocus();
//    WxComboBox2->SetSelection(0);
//}
    
    
    //if (WxDirDialog1->ShowModal() == wxID_OK)
//    {
//        //WxCheckBox1->SetValue(true);
//        WxEdit1->SetValue("Tools.exe");
//        //WxEdit3->SetValue("Attach .chm Info.");
//        WxEdit1->Enable(true);
//        WxEdit2->Enable(false);
//        WxEdit2->Clear();
//        WxListBox1->Enable(true);
//       // WxEdit3->Enable(true);
//        WxButton4->SetLabel("<<");
//        WxButton5->SetLabel("<<");
//        //WxButton6->SetLabel("<<");
//        WxButton4->Enable(true);
//        WxButton5->Enable(false);
//        //WxButton6->Enable(true);
//        WxButton7->Enable(true);
//        
//        WxComboBox1->Clear();
//        WxEdit4->SetLabel(WxDirDialog1->GetPath());
//        wxArrayString dirList2;
//        wxDirectoriesEnumerator traverser2(&dirList2);
//        wxDir dir("Data\\Programs\\");
//        if(dir.IsOpened()){
//        dir.Traverse(traverser2);
//        for(unsigned int i=0; i<dirList2.GetCount(); i++) {
//        WxComboBox1->Append(dirList2.Item(i).AfterLast('\\').AfterLast('/'));
//        WxComboBox1->SetSelection(0);
//        }};
//        
//        WxListBox1->Clear();
//        wxArrayString dirList;
//        wxDirectoriesEnumerator traverser(&dirList);
//        wxDir fils(WxEdit4->GetLabel()+"\\");
//        if(fils.IsOpened()){
//        fils.Traverse(traverser);
//        for(unsigned int i=0; i<dirList.GetCount(); i++) {
//        WxListBox1->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
//        }};
//        WxButton3->Enable(true);
//        //WxCheckBox1->Enable(true);
//       // WxCheckBox2->Enable(true);
//        WxEdit5->SetFocus();  
//        WxComboBox2->SetSelection(0);
//        
//    } 
    
    
    
    // wxDirDialog dlg(this, "Choose a directory", "", wxDD_DEFAULT_STYLE | wxDD_DIR_MUST_EXIST);
//
// //       if (dlg.ShowModal() == wxID_OK)
////        {
////            wxString folderPath = dlg.GetPath();
////            WxListBox1->Clear();
////            WxEdit4->SetLabel(folderPath);
////            wxDir dir(folderPath);
////            if (dir.IsOpened())
////            {
////                wxString filename;
////                bool cont = dir.GetFirst(&filename);
////
////                while (cont)
////                {
////                    WxListBox1->Append(filename);
////                    cont = dir.GetNext(&filename);
////                }
////            }
////        }
//    if (WxDirDialog1->ShowModal() == wxID_OK)
//    {
//        //WxCheckBox3->SetValue(true);
//        WxComboBox2->SetSelection(0);
//        WxEdit1->SetValue("Tools.exe");
//        WxEdit2->Clear();
//        WxListBox1->Enable(true);
//       // WxEdit3->Enable(true);
//        WxButton4->SetLabel("<<");
//        WxButton5->SetLabel("<<");
//       // WxButton6->SetLabel("<<");
//        WxButton4->Enable(true);
//        WxButton5->Enable(false);
//       // WxButton6->Enable(true);
//        WxButton7->Enable(true);
//        
//        WxComboBox1->Clear();
//        WxEdit4->SetLabel(WxDirDialog1->GetPath());
//        wxArrayString dirList2;
//        wxDirectoriesEnumerator traverser2(&dirList2);
//        wxDir dir("Data\\Programs\\");
//        if(dir.IsOpened()){
//        dir.Traverse(traverser2);
//        for(unsigned int i=0; i<dirList2.GetCount(); i++) {
//        WxComboBox1->Append(dirList2.Item(i).AfterLast('\\').AfterLast('/'));
//        WxComboBox1->SetSelection(0);
//        }};
//        
//        WxListBox1->Clear();
//        wxArrayString dirList;
//        wxDirectoriesEnumerator traverser(&dirList);
//        wxDir fils(WxEdit4->GetLabel()+"\\");
//        if(fils.IsOpened()){
//        fils.Traverse(traverser);
//        for(unsigned int i=0; i<dirList.GetCount(); i++) {
//        WxListBox1->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
//        }};
//
//        WxButton3->Enable(true);
//        //WxCheckBox1->Enable(true);
//        //WxCheckBox2->Enable(true);
//        WxEdit5->SetFocus();  
//
////        
//    } 
	// insert your code here
}

/*
 * WxButton3Click
 */
void ImportDlg::WxButton3Click(wxCommandEvent& event)
{
    
    if(WxEdit5->GetValue().IsEmpty()){
        wxMessageBox("Enter Tools Name First!", "TOOLS_NAME_ERROR", wxICON_ERROR | wxOK);
    }else if (WxEdit1->GetValue() == "Tools(x86).exe" || WxEdit2->GetValue() == "Tools(x64).exe" || WxEdit1->GetValue() == "Tools.exe") {
        wxMessageBox("Oops! It seems you have missed to add correct data.\nPlease enter correct data to continue.", "INPUT_FIELD_ERROR", wxICON_ERROR | wxOK);
    }else{
        ifstream ifile;
        ifile.open("Data\\Programs\\"+WxComboBox1->GetValue()+"\\"+WxEdit5->GetValue()+".uha");
        if(ifile){
            wxMessageBox("Filename already EXIST.","FILENAME_ERROR",wxICON_ERROR|wxOK);
            WxEdit5->SetFocus();
            WxEdit5->SelectAll();
        }else{
            
            if(WxComboBox2->GetValue()=="Cross-Platform Application"){
                ofstream config;
                config.open(WxEdit4->GetValue()+"\\data_config.txt"); 
                config << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
                config << "\n"+WxEdit1->GetValue();     
                config << "\nnull";
                config << "\ncpa";   
                config << "\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";             
                config << "\n\nWARNING!!!... DO NOT DELETE!!! \n\n\n(c) 2020-2021 KLBSoft. All Rights Reserve.";
                config.close(); 
            }else if(WxComboBox2->GetValue()=="32-bit Application"){
                ofstream config;
                config.open(WxEdit4->GetValue()+"\\data_config.txt");  
                config << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";    
                config << "\n"+WxEdit1->GetValue(); 
                config << "\nnull";
                config << "\n32bit";
                config << "\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
                config << "\n\nWARNING!!!... DO NOT DELETE!!! \n\n\n(c) 2020-2021 KLBSoft. All Rights Reserve.";
                config.close(); 
                
            }else if(WxComboBox2->GetValue()=="64-bit Application"){
                ofstream config;
                config.open(WxEdit4->GetValue()+"\\data_config.txt"); 
                config << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
                config << "\nnull";     
                config << "\n"+WxEdit2->GetValue(); 
                config << "\n64bit";
                config << "\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
                config << "\n\nWARNING!!!... DO NOT DELETE!!! \n\n\n(c) 2020-2021 KLBSoft. All Rights Reserve.";
                config.close();
                
            }else if(WxComboBox2->GetValue()=="Combine 32-bit & 64-bit Application"){
                ofstream config;
                config.open(WxEdit4->GetValue()+"\\data_config.txt"); 
                config << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
                config << "\n"+WxEdit1->GetValue();   
                config << "\n"+WxEdit2->GetValue(); 
                config << "\ncombine";
                config << "\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
                config << "\n\nWARNING!!!... DO NOT DELETE!!! \n\n\n(c) 2020-2021 KLBSoft. All Rights Reserve.";
                config.close(); 
            }
            WxTimer1->Start(100);
            remove("Data\\Resources\\klbsoft.temp\\.tmpKLBSoft040194$.tmp"); 
            ShellExecute(NULL,NULL,_T("cmd.exe"), _T("/c Data\\uharc.exe a -r+ -ed- -pe -mx -mm+ -md32768 -pw@@!!klbSoft$$2020!!@@ -y+ \"Data\\Programs\\"+WxComboBox1->GetValue()+"\\"+WxEdit5->GetValue()+".uha\" \""+WxEdit4->GetLabel()+"\\"),NULL,SW_HIDE); 
        }      
    }
    
    

}

/*
 * ImportDlgActivate
 */
void ImportDlg::ImportDlgActivate(wxActivateEvent& event)
{
    WxEdit5->SetFocus();
}

/*
 * WxCheckBox1Click
 */
void ImportDlg::WxCheckBox1Click(wxCommandEvent& event)
{
    
	// insert your code here
}
/*
 * WxRadioButton1Click
 */
void ImportDlg::WxRadioButton1Click(wxCommandEvent& event)
{
    WxButton5->Enable(false);
    WxEdit2-Enable(false);
	// insert your code here
}

/*
 * WxRadioButton2Click
 */
void ImportDlg::WxRadioButton2Click(wxCommandEvent& event)
{
    WxButton5->Enable(true);
    WxEdit2-Enable(true);
	// insert your code here
}

/*
 * WxCheckBox1Click0
 */
void ImportDlg::WxCheckBox1Click0(wxCommandEvent& event)
{
    //WxListBox1->Enable(true);
     //if(WxCheckBox1->IsChecked()){
//        WxCheckBox2->SetValue(true);
//            
//        }else{
//          WxCheckBox2->SetValue(false);  
//        }
////        WxCheckBox2->SetValue(false);
//        WxEdit1->SetValue("Tools.exe");
//        //WxEdit3->SetValue("Attach .chm Info.");
//        WxEdit1->Enable(true);
//        WxEdit2->Enable(false);
//        WxEdit2->Clear();
//       // WxEdit3->Enable(true);
//        WxButton4->SetLabel("<<");
//        WxButton5->SetLabel("<<");
//        //WxButton6->SetLabel("<<");
//        WxButton4->Enable(true);
//        WxButton5->Enable(false);
//        //WxButton6->Enable(true);
//        WxButton7->Enable(true);
//     }else{
//        WxCheckBox2->SetValue(true);
//        WxEdit1->SetValue("Tools(x86).exe");
//        WxEdit2->SetValue("Tools(x64).exe");
//        WxEdit1->Enable(true);
//        WxEdit2->Enable(true);
//        //WxEdit3->Enable(true);
//        WxButton4->Enable(true);
//        WxButton5->Enable(true);
//        //WxButton6->Enable(true);
//        WxButton7->Enable(true);
//        WxButton4->SetLabel("<<");
//        WxButton5->SetLabel("<<");
//       // WxButton6->SetLabel("<<");
//
//     }
}

/*
 * WxCheckBox2Click
 */
void ImportDlg::WxCheckBox2Click(wxCommandEvent& event)
{
    //if(WxCheckBox1->IsChecked()){
//        WxCheckBox2->SetValue(true);
//            
//    }else{
//          WxCheckBox2->SetValue(false);  
//    }
   // WxListBox1->Enable(true);
//     if(WxCheckBox2->IsChecked()){
//        WxCheckBox1->SetValue(false);
//        WxCheckBox2->SetValue(true);
//        WxEdit1->SetValue("Tools(x86).exe");
//        WxEdit2->SetValue("Tools(x64).exe");
//        WxEdit1->Enable(true);
//        WxEdit2->Enable(true);
//        //WxEdit3->Enable(true);
//        WxButton4->Enable(true);
//        WxButton5->Enable(true);
//       // WxButton6->Enable(true);
//        WxButton7->Enable(true);
//        WxButton4->SetLabel("<<");
//        WxButton5->SetLabel("<<");
//       // WxButton6->SetLabel("<<");
//     }else{
//        WxCheckBox1->SetValue(true);
//        WxEdit1->SetValue("Tools.exe");
//        //WxEdit3->SetValue("Attach .chm Info.");
//        WxEdit1->Enable(true);
//        WxEdit2->Enable(false);
//        WxEdit2->Clear();
//        //WxEdit3->Enable(true);
//        WxButton4->SetLabel("<<");
//        WxButton5->SetLabel("<<");
//        //WxButton6->SetLabel("<<");
//        WxButton4->Enable(true);
//        WxButton5->Enable(false);
//        //WxButton6->Enable(true);
//        WxButton7->Enable(true);
//     }
}

/*
 * WxButton6Click
 */


/*
 * WxButton7Click
 */
void ImportDlg::WxButton7Click(wxCommandEvent& event)
{
   
    //ShellExecute(NULL,NULL,_T("cmd.exe"), _T("/c rename \""+WxStaticText10->GetLabel()+"\\"+WxStaticText9->GetLabel()+".chm\" \"CONFIG_INFO.chm\""),NULL,SW_HIDE);
                
	// insert your code here
}

/*
 * WxEdit5Enter
 */
void ImportDlg::WxEdit5Enter(wxCommandEvent& event)
{
  
}

/*
 * WxEdit3Updated
 */
void ImportDlg::WxEdit3Updated(wxCommandEvent& event)
{
    
	// insert your code here
}

/*
 * WxEdit3Enter
 */
void ImportDlg::WxEdit3Enter(wxCommandEvent& event)
{
    
	// insert your code here
}

/*
 * WxButton7Click0
 */
void ImportDlg::WxButton7Click0(wxCommandEvent& event)
{
    ReadInfoDlg* readInfo = new ReadInfoDlg(this);    
    readInfo->WxComboBox1->Clear();
    readInfo->WxComboBox2->Clear();
    wxArrayString dirList;
    wxDirectoriesEnumerator traverser(&dirList);
    wxDir dir("Data\\Programs\\");
    if(dir.IsOpened()){
    dir.Traverse(traverser);
    for(unsigned int i=0; i<dirList.GetCount(); i++) {
    readInfo->WxComboBox1->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
    readInfo->WxComboBox1->SetSelection(WxComboBox1->GetSelection());
    }};
    readInfo->WxEdit1->SetLabel("No Info. AVAILABLE.");
    readInfo->WxComboBox2->Enable(false);
    readInfo->WxComboBox1->Enable(false);
    readInfo->WxComboBox2->Append(WxEdit5->GetValue());
    readInfo->WxComboBox2->SetSelection(0);
    readInfo->WxNotebook1->ChangeSelection(2);
    readInfo->WxStaticText6->SetLabel(WxEdit4->GetValue());
    readInfo->WxEdit1->SetFocus();
    readInfo->WxEdit1->SelectAll();
    readInfo->WxEdit1->Clear();
    readInfo->WxButton10->Enable(true);
    readInfo->WxButton2->SetLabel("SAVE");
    readInfo->WxStaticText16->SetLabel("importSave");
    readInfo->WxStaticText12->SetLabel("addInfo");
    readInfo->ShowModal();
    
    
    //ReadInfoDlg* readInfo = new ReadInfoDlg(this);    
//    readInfo->WxComboBox1->Clear();
//    readInfo->WxComboBox2->Clear();
//    wxArrayString dirList;
//    wxDirectoriesEnumerator traverser(&dirList);
//    wxDir dir("Data\\Programs\\");
//    if(dir.IsOpened()){
//    dir.Traverse(traverser);
//    for(unsigned int i=0; i<dirList.GetCount(); i++) {
//    readInfo->WxComboBox1->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
//    readInfo->WxComboBox1->SetSelection(WxComboBox1->GetSelection());
//    }};
//    readInfo->WxEdit1->SetLabel("No Info. AVAILABLE.");
//    readInfo->WxComboBox2->Enable(false);
//    readInfo->WxComboBox1->Enable(false);
//    readInfo->WxComboBox2->Append(WxEdit5->GetValue());
//    readInfo->WxComboBox2->SetSelection(0);
//    readInfo->WxNotebook1->ChangeSelection(2);
//    readInfo->WxStaticText6->SetLabel(WxEdit4->GetValue());
//    readInfo->WxEdit1->SetFocus();
//    readInfo->WxEdit1->SelectAll();
//    readInfo->WxStaticText12->SetLabel("_impInfo");
//    readInfo->ShowModal();
	// insert your code here
}

/*
 * WxButton4Click0
 */
void ImportDlg::WxButton4Click0(wxCommandEvent& event)
{
    if(WxListBox1->GetSelection()==-1){
        wxMessageBox("You have not selected any tools, please select one before continuing.","FILE_NOT_VALID_ERROR",wxICON_ERROR|wxOK);
    }else{
        if(WxButton4->GetLabel()==">>"){
            int ans=wxMessageBox("Are you sure you want to change '"+WxEdit1->GetValue()+"'?","Continue?",wxICON_WARNING|wxYES_NO);
            if(ans==wxYES){
                WxEdit1->Clear();
                WxButton4->SetLabel("<<");
                WxEdit1->SetLabel("Tools(x86).exe");
            } 
        }else{
            if(WxStaticText12->GetLabel()!="exe"){
                wxMessageBox("'"+WxListBox1->GetStringSelection()+"'  is not a valid .exe FILE. \nPlease Select a valid FILE.","FILE_NOT_VALID_ERROR",wxICON_ERROR|wxOK);
            }else{
                if(WxListBox1->GetStringSelection()==WxEdit2->GetValue()){
                    wxMessageBox("'"+WxListBox1->GetStringSelection()+"'  is already SELECTED. \nPlease Select another ONE.","ALREADY_SELECTED_ERROR",wxICON_ERROR|wxOK);
                }else{
                    WxEdit1->SetLabel(WxListBox1->GetStringSelection());
                    WxButton4->SetLabel(">>");
                }
            }
        }
    }
	// insert your code here
}

/*
 * WxButton5Click0
 */
void ImportDlg::WxButton5Click0(wxCommandEvent& event)
{
    if(WxListBox1->GetSelection()==-1){
        wxMessageBox("You have not selected any tools, please select one before continuing.","FILE_NOT_VALID_ERROR",wxICON_ERROR|wxOK);
    }else{
        if(WxButton5->GetLabel()==">>"){
            int ans=wxMessageBox("Are you sure you want to change '"+WxEdit2->GetValue()+"'?","Continue?",wxICON_WARNING|wxYES_NO);
            if(ans==wxYES){
                WxEdit2->Clear();
                WxButton5->SetLabel("<<");
                WxEdit2->SetLabel("Tools(x64).exe");
            } 
        }else{
            if(WxStaticText12->GetLabel()!="exe"){
                wxMessageBox("'"+WxListBox1->GetStringSelection()+"'  is not a valid .exe FILE. \nPlease Select a valid FILE.","FILE_NOT_VALID_ERROR",wxICON_ERROR|wxOK);  
            }else{
                if(WxListBox1->GetStringSelection()==WxEdit1->GetValue()){
                    wxMessageBox("'"+WxListBox1->GetStringSelection()+"'  is already SELECTED. \nPlease Select another ONE.","ALREADY_SELECTED_ERROR",wxICON_ERROR|wxOK);
                }else{
                    WxEdit2->SetLabel(WxListBox1->GetStringSelection());
                    WxButton5->SetLabel(">>");
                }
            }
        }
    }
	// insert your code here
}

/*
 * WxButton6Click0
 */
//void ImportDlg::WxButton6Click0(wxCommandEvent& event)
//{ 
//    if(WxListBox1->GetSelection()==-1){
//        wxMessageBox("You have not selected any tools, please select one before continuing.","FILE_NOT_VALID_ERROR",wxICON_ERROR|wxOK);
//    }else{
//        if(WxButton6->GetLabel()==">>"){
//            int ans=wxMessageBox("Are you sure you want to change '"+WxEdit3->GetValue()+"'?","Continue?",wxICON_WARNING|wxYES_NO);
//            if(ans==wxYES){
//                WxEdit3->Clear();
//                WxEdit3->SetLabel("Attach .chm Info.");
//                WxButton6->SetLabel("<<");
//                WxButton7->Enable(true);
//            } 
//        }else{
//            if(WxStaticText12->GetLabel()!="chm"){
//                wxMessageBox("'"+WxListBox1->GetStringSelection()+"'  is not a valid .chm FILE. \nPlease Select a valid FILE.","FILE_NOT_VALID_ERROR",wxICON_ERROR|wxOK);
//            }else{
//                WxEdit3->SetLabel(WxListBox1->GetStringSelection());
//                WxButton6->SetLabel(">>");
//                WxButton7->Enable(false);
//            }
//        }
//    }
//	// insert your code here
//}

/*
 * WxListBox1Selected
 */
void ImportDlg::WxListBox1Selected(wxCommandEvent& event)
{
    WxStaticText12->SetLabel(WxListBox1->GetStringSelection().AfterLast('.'));
	// insert your code here
}

/*
 * WxPanel1UpdateUI
 */
void ImportDlg::WxPanel1UpdateUI(wxUpdateUIEvent& event)
{
	// insert your code here
}

/*
 * WxComboBox2Selected
 */
void ImportDlg::WxComboBox2Selected(wxCommandEvent& event )
{
    if(WxComboBox2->GetValue()=="Cross-Platform Application"){
        WxEdit1->SetValue("Tools.exe"); 
        WxEdit1->Enable(true);
        WxEdit2->Enable(false);
        WxEdit2->Clear();
        WxButton4->SetLabel("<<");
        WxButton5->SetLabel("<<");
        WxButton4->Enable(true);
        WxButton5->Enable(false);
        WxButton7->Enable(true);
    }else if(WxComboBox2->GetValue()=="32-bit Application"){
        WxEdit1->SetValue("Tools(x86).exe"); 
        WxEdit1->Enable(true);
        WxEdit2->SetValue(""); 
        WxEdit2->Enable(false);
        WxButton4->SetLabel("<<");
        WxButton5->SetLabel("<<");
        WxButton4->Enable(true);
        WxButton5->Enable(false);
        WxButton7->Enable(true);
    }else if(WxComboBox2->GetValue()=="64-bit Application"){
        WxEdit1->SetValue(""); 
        WxEdit1->Enable(false);
        WxEdit2->SetValue("Tools(x64).exe"); 
        WxEdit2->Enable(true);
        WxButton4->SetLabel("<<");
        WxButton5->SetLabel("<<");
        WxButton4->Enable(false);
        WxButton5->Enable(true);
        WxButton7->Enable(true);
    }else if(WxComboBox2->GetValue()=="Combine 32-bit & 64-bit Application"){
        WxEdit1->SetValue("Tools(x86).exe"); 
        WxEdit2->SetValue("Tools(x64).exe"); 
        WxEdit1->Enable(true);
        WxEdit2->Enable(true);
        WxButton4->SetLabel("<<");
        WxButton5->SetLabel("<<");
        WxButton4->Enable(true);
        WxButton5->Enable(true);
        WxButton7->Enable(true);
    }
	// insert your code here
}

/*
 * WxCheckBox3Click
 */
void ImportDlg::WxCheckBox3Click(wxCommandEvent& event)
{
	// insert your code here
}

/*
 * WxTimer1Timer
 */
void ImportDlg::WxTimer1Timer(wxTimerEvent& event)
{
     wxString filePath = "Data\\Programs\\"+WxComboBox1->GetValue()+"\\"+WxEdit5->GetValue()+".uha";
    if (wxFileName::FileExists(filePath)){
        WxGauge1->SetValue(0);
        WxTimer1->Stop(); 
        remove(WxEdit4->GetValue()+"\\ReadME!.txt"); 
        remove(WxEdit4->GetValue()+"\\data_config.txt"); 
        wxMessageBox("Success IMPORT.","IMPORT_SUCCESS",wxICON_INFORMATION|wxOK);  
        ShellExecute(NULL, NULL, _T("cmd.exe"), _T("/c RMDIR /S /Q \""+WxEdit4->GetValue()+"\""), NULL, SW_HIDE);
        WxButton4->Enable(true);
        WxButton5->Enable(false);
        WxEdit2->Enable(false);
        WxEdit1->Clear();
        WxEdit2->Clear();
        WxEdit4->Clear();
        WxEdit5->Clear();
        WxListBox1->Clear();
        WxButton4->SetLabel("<<");
        WxButton5->SetLabel("<<");
        WxEdit1->SetLabel("Tools.exe");
        WxComboBox1->SetSelection(0);
        WxComboBox2->SetSelection(0);      
    }else{
        int counter= 1000;
        counter++;
        WxGauge1->SetValue(counter % (WxGauge1->GetRange()+ 1));
    }
	// insert your code here
}
