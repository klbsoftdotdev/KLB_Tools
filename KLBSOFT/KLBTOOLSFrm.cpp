///-----------------------------------------------------------------
///
/// @file      KLBTOOLSFrm.cpp
/// @author    KLBTech
/// Created:   3/11/2021 7:09:38 AM
/// @section   DESCRIPTION
///            KLBTOOLSFrm class implementation
///
///------------------------------------------------------------------
#include "AddInfoDlg.h"
#include "ImportDlg.h"
#include "ReadInfoDlg.h"
#include "AboutDlg.h"
#include "KLBTOOLSFrm.h"
#include <windows.h>
#include "wx/wx.h"
#include <cstdio>
#include "wx/dir.h"
#include "wx/filename.h"
#include <time.h>
#include <wx/wfstream.h>
#include <wx/txtstrm.h>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <dirent.h>
#define INFO_BUFFER_SIZE 32767

TCHAR infoBuf[INFO_BUFFER_SIZE];
DWORD bufCharCount = INFO_BUFFER_SIZE;


using namespace std;

//Do not add custom headers between
//Header Include Start and Header Include End
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
// KLBTOOLSFrm
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(KLBTOOLSFrm,wxFrame)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(KLBTOOLSFrm::OnClose)
	EVT_ACTIVATE(KLBTOOLSFrm::KLBTOOLSFrmActivate)
	EVT_MENU(ID_MNU_IMPORTTOOLS_1003, KLBTOOLSFrm::Mnuimporttools1003Click)
	EVT_MENU(ID_MNU_EXIT_1039, KLBTOOLSFrm::Mnuexit1039Click0)
	EVT_MENU(ID_MNU_EDITTOOLS_1005, KLBTOOLSFrm::Mnuedittools1005Click)
	EVT_MENU(ID_MNU_ADDCATEGORY_1006, KLBTOOLSFrm::Mnuaddcategory1006Click)
	EVT_MENU(ID_MNU_INFO_SETTINGS_1018, KLBTOOLSFrm::Mnuinfosettings1018Click)
	EVT_MENU(ID_MNU_README_1072, KLBTOOLSFrm::Mnureadme1072Click)
	EVT_MENU(wxID_STATIC, KLBTOOLSFrm::Mnudonation1041Click)
	EVT_MENU(ID_MNU_ABOUT_1008, KLBTOOLSFrm::Mnuabout1008Click0)
	EVT_TIMER(ID_WXTIMER2,KLBTOOLSFrm::WxTimer2Timer)
	EVT_TIMER(ID_WXTIMER1,KLBTOOLSFrm::WxTimer1Timer)
	
	EVT_TEXT(ID_WXEDIT1,KLBTOOLSFrm::WxEdit1Updated)
	EVT_LISTBOX(ID_WXLISTBOX1,KLBTOOLSFrm::WxListBox1Selected0)
	EVT_UPDATE_UI(ID_WXLISTBOX1,KLBTOOLSFrm::WxListBox1UpdateUI)
	EVT_BUTTON(ID_WXBUTTON1,KLBTOOLSFrm::WxButton1Click)
	EVT_BUTTON(ID_WXBUTTON2,KLBTOOLSFrm::WxButton2Click)
	EVT_COMBOBOX(ID_WXCOMBOBOX2,KLBTOOLSFrm::WxComboBox2Selected)
	EVT_COMBOBOX(ID_WXCOMBOBOX1,KLBTOOLSFrm::WxComboBox1Selected0)
END_EVENT_TABLE()
////Event Table End

  

KLBTOOLSFrm::KLBTOOLSFrm(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

KLBTOOLSFrm::~KLBTOOLSFrm()
{
}

void KLBTOOLSFrm::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	WxPanel1 = new wxPanel(this, ID_WXPANEL1, wxPoint(-8, -2), wxSize(522, 311));

	WxStaticText7 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT7, _("importnow"), wxPoint(719, 6), wxDefaultSize, 0, _("WxStaticText7"));

	WxStaticBox2 = new wxStaticBox(WxPanel1, ID_WXSTATICBOX2, _("Select Tools"), wxPoint(16, 59), wxSize(320, 199));

	WxStaticText3 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT3, _("WxStaticText3"), wxPoint(732, 74), wxDefaultSize, 0, _("WxStaticText3"));

	WxStaticText4 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT4, _("WxStaticText4"), wxPoint(723, 35), wxDefaultSize, 0, _("WxStaticText4"));

	WxStaticText5 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT5, _("WxStaticText5"), wxPoint(727, 55), wxDefaultSize, 0, _("WxStaticText5"));

	WxStaticBox4 = new wxStaticBox(WxPanel1, ID_WXSTATICBOX4, _("Select Tools Category"), wxPoint(16, 3), wxSize(321, 54));

	wxArrayString arrayStringFor_WxComboBox1;
	WxComboBox1 = new wxComboBox(WxPanel1, ID_WXCOMBOBOX1, _(""), wxPoint(29, 24), wxSize(295, 23), arrayStringFor_WxComboBox1, wxSTATIC_BORDER | wxVSCROLL | wxCB_DROPDOWN | wxCB_READONLY | wxCB_SORT, wxDefaultValidator, _("WxComboBox1"));

	WxStaticBox1 = new wxStaticBox(WxPanel1, ID_WXSTATICBOX1, _("Advance Options"), wxPoint(343, 3), wxSize(153, 169));

	wxArrayString arrayStringFor_WxComboBox2;
	arrayStringFor_WxComboBox2.Add(_("Normal"));
	arrayStringFor_WxComboBox2.Add(_("Administrator"));
	WxComboBox2 = new wxComboBox(WxPanel1, ID_WXCOMBOBOX2, _("Normal"), wxPoint(355, 108), wxSize(130, 23), arrayStringFor_WxComboBox2, wxSTATIC_BORDER | wxCB_READONLY, wxDefaultValidator, _("WxComboBox2"));

	WxButton2 = new wxButton(WxPanel1, ID_WXBUTTON2, _("RUN PROGRAM"), wxPoint(343, 228), wxSize(155, 29), wxSTATIC_BORDER, wxDefaultValidator, _("WxButton2"));

	WxButton1 = new wxButton(WxPanel1, ID_WXBUTTON1, _("VIEW INFO"), wxPoint(343, 195), wxSize(154, 29), wxSTATIC_BORDER, wxDefaultValidator, _("WxButton1"));

	wxArrayString arrayStringFor_WxListBox1;
	WxListBox1 = new wxListBox(WxPanel1, ID_WXLISTBOX1, wxPoint(29, 106), wxSize(295, 127), arrayStringFor_WxListBox1, wxLB_SINGLE | wxSTATIC_BORDER | wxLB_SORT);
	WxListBox1->SetForegroundColour(wxColour(0,0,255));
	WxListBox1->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, _("Segoe UI Semibold")));

	WxStaticText8 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT8, _("Run Mode:"), wxPoint(355, 85), wxDefaultSize, 0, _("WxStaticText8"));

	WxStaticText15 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT15, _(" Tools:"), wxPoint(518, 195), wxSize(68, 19), wxSTATIC_BORDER | wxST_NO_AUTORESIZE, _("WxStaticText15"));

	WxGauge1 = new wxGauge(WxPanel1, ID_WXGAUGE1, 100, wxPoint(-14, 261), wxSize(535, 17), wxGA_HORIZONTAL, wxDefaultValidator, _("WxGauge1"));
	WxGauge1->SetRange(100);
	WxGauge1->SetValue(0);

	WxStaticText16 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT16, _("WxStaticText16"), wxPoint(633, 57), wxDefaultSize, 0, _("WxStaticText16"));

	WxStaticText17 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT17, _("Temporary Folder(*):"), wxPoint(355, 29), wxDefaultSize, 0, _("WxStaticText17"));

	wxArrayString arrayStringFor_WxComboBox3;
	arrayStringFor_WxComboBox3.Add(_("KLBSoft Temp Dir"));
	arrayStringFor_WxComboBox3.Add(_("Windows Temp Dir"));
	WxComboBox3 = new wxComboBox(WxPanel1, ID_WXCOMBOBOX3, _("KLBSoft Temp Dir"), wxPoint(355, 52), wxSize(130, 23), arrayStringFor_WxComboBox3, wxCB_DROPDOWN | wxCB_READONLY, wxDefaultValidator, _("WxComboBox3"));

	WxStaticText18 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT18, _("WxStaticText18"), wxPoint(515, 111), wxDefaultSize, 0, _("WxStaticText18"));

	WxStaticText19 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT19, _("btnString"), wxPoint(634, 42), wxDefaultSize, 0, _("WxStaticText19"));

	WxStaticText20 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT20, _("WxStaticText20"), wxPoint(549, 201), wxDefaultSize, 0, _("WxStaticText20"));

	WxStaticText21 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT21, _("WxStaticText21"), wxPoint(551, 220), wxDefaultSize, 0, _("WxStaticText21"));

	WxStaticText1 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT1, _("WxStaticText1"), wxPoint(633, 28), wxDefaultSize, 0, _("WxStaticText1"));

	WxStaticText6 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT6, _("WxStaticText6"), wxPoint(551, 186), wxDefaultSize, 0, _("WxStaticText6"));

	WxStaticText2 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT2, _("WxStaticText2"), wxPoint(635, 8), wxDefaultSize, 0, _("WxStaticText2"));

	WxStaticText9 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT9, _("OnActive"), wxPoint(634, 88), wxDefaultSize, 0, _("WxStaticText9"));

	WxStaticText14 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT14, _("onRun"), wxPoint(700, 99), wxDefaultSize, 0, _("WxStaticText14"));

	WxStaticText10 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT10, _("onView"), wxPoint(637, 106), wxDefaultSize, 0, _("WxStaticText10"));

	WxCheckBox1 = new wxCheckBox(WxPanel1, ID_WXCHECKBOX1, _("sysArchi"), wxPoint(355, 144), wxSize(123, 17), 0, wxDefaultValidator, _("WxCheckBox1"));

	WxEdit1 = new wxTextCtrl(WxPanel1, ID_WXEDIT1, _(""), wxPoint(30, 81), wxSize(295, 19), wxSTATIC_BORDER, wxDefaultValidator, _("WxEdit1"));

	WxStaticText11 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT11, _(""), wxPoint(72, 236), wxSize(252, 19), wxSTATIC_BORDER | wxST_NO_AUTORESIZE, _("WxStaticText11"));

	WxStaticText12 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT12, _("  Tools:"), wxPoint(30, 236), wxSize(41, 19), wxSTATIC_BORDER | wxST_NO_AUTORESIZE, _("WxStaticText12"));

	WxStatusBar1 = new wxStatusBar(this, ID_WXSTATUSBAR1);
	WxStatusBar1->SetFieldsCount(3);
	WxStatusBar1->SetStatusText(_(""),0);
	WxStatusBar1->SetStatusText(_(""),1);
	WxStatusBar1->SetStatusText(_("    (c) 2020-2024, KLBSoft."),2);
	int WxStatusBar1_Widths[3];
	WxStatusBar1_Widths[0] = 25;
	WxStatusBar1_Widths[1] = 294;
	WxStatusBar1_Widths[2] = -1;
	WxStatusBar1->SetStatusWidths(3,WxStatusBar1_Widths);

	WxTimer1 = new wxTimer();
	WxTimer1->SetOwner(this, ID_WXTIMER1);

	WxTimer2 = new wxTimer();
	WxTimer2->SetOwner(this, ID_WXTIMER2);

	WxMenuBar1 = new wxMenuBar();
	wxMenu *ID_MNU_FILE_1002_Mnu_Obj = new wxMenu();
	ID_MNU_FILE_1002_Mnu_Obj->Append(ID_MNU_IMPORTTOOLS_1003, _("Import Tools"), _(""), wxITEM_NORMAL);
	ID_MNU_FILE_1002_Mnu_Obj->AppendSeparator();
	ID_MNU_FILE_1002_Mnu_Obj->Append(ID_MNU_EXIT_1039, _("Exit"), _(""), wxITEM_NORMAL);
	WxMenuBar1->Append(ID_MNU_FILE_1002_Mnu_Obj, _("File"));
	
	wxMenu *ID_MNU_SETTINGS_1004_Mnu_Obj = new wxMenu();
	ID_MNU_SETTINGS_1004_Mnu_Obj->Append(ID_MNU_EDITTOOLS_1005, _("Edit Tools"), _(""), wxITEM_NORMAL);
	ID_MNU_SETTINGS_1004_Mnu_Obj->Append(ID_MNU_ADDCATEGORY_1006, _("Edit Category"), _(""), wxITEM_NORMAL);
	ID_MNU_SETTINGS_1004_Mnu_Obj->Append(ID_MNU_INFO_SETTINGS_1018, _("Information Settings"), _(""), wxITEM_NORMAL);
	WxMenuBar1->Append(ID_MNU_SETTINGS_1004_Mnu_Obj, _("Options"));
	
	wxMenu *ID_MNU_HELP_1007_Mnu_Obj = new wxMenu();
	ID_MNU_HELP_1007_Mnu_Obj->Append(ID_MNU_README_1072, _("View ReadMe"), _(""), wxITEM_NORMAL);
	ID_MNU_HELP_1007_Mnu_Obj->AppendSeparator();
	ID_MNU_HELP_1007_Mnu_Obj->Append(ID_MNU_ABOUT_1008, _("About"), _(""), wxITEM_NORMAL);
	WxMenuBar1->Append(ID_MNU_HELP_1007_Mnu_Obj, _("Help"));
	SetMenuBar(WxMenuBar1);

	SetStatusBar(WxStatusBar1);
	SetTitle(_(" KLBSoft: KLB Tools v2.0 (BETA)"));
	SetIcon(wxIcon("C:/Users/Joselle anne/Desktop/WIP 2021/dd.ico", wxBITMAP_TYPE_ICO));
	SetSize(8,8,518,349);
	Center();
	
	////GUI Items Creation End
}

void KLBTOOLSFrm::OnClose(wxCloseEvent& event)
{
    remove("Data\\Resources\\klbsoft.temp\\.tmpKLBSoft040194$.tmp");
    remove("Data\\Resources\\klbsoft.temp\\ReadME!.txt");
    remove("Data\\Resources\\klbsoft.temp\\data_config.txt");
    ShellExecute(NULL, NULL, _T("cmd.exe"), _T("/c DEL /S /Q Data\\Resources\\klbsoft.temp\\*.* && for /D %i in (Data\\Resources\\klbsoft.temp\\*) do rd /s /q \"%i\""), NULL, SW_HIDE);
	Destroy();
}

/*
 * Mnuabout1008Click
 */
void KLBTOOLSFrm::Mnuabout1008Click(wxCommandEvent& event)
{
    
}
/*
 * Mnuimporttools1003Click
 */
void KLBTOOLSFrm::Mnuimporttools1003Click(wxCommandEvent& event)
{ 
    remove("Data\\Resources\\klbsoft.temp\\.tmp$MenuFile");  
    WxTimer2->Start(100);
    ImportDlg *importDlg = new  ImportDlg(this);
    importDlg->WxEdit1->SetValue("Tools.exe"); 
    importDlg->WxEdit1->Enable(true);
    importDlg->WxEdit2->Enable(false);
    importDlg->WxEdit2->Clear();
    importDlg->WxButton4->SetLabel("<<");
    importDlg->WxButton5->SetLabel("<<");
    importDlg->WxButton4->Enable(true);
    importDlg->WxButton5->Enable(false);
    importDlg->WxButton7->Enable(false);
    importDlg->WxComboBox1->Enable(false);
    importDlg->WxComboBox2->Enable(false);
    importDlg->ShowModal();
    
    
    //remove("Data\\Resources\\klbsoft.temp\\.tmp$MenuFile");  
//    WxTimer2->Start(100);
//    ReadInfoDlg *readinfo= new ReadInfoDlg(this);
//    wxArrayString dirList;
//    wxDirectoriesEnumerator traverser(&dirList);
//    wxDir dir("Data\\Programs\\");
//    if(dir.IsOpened()){
//    dir.Traverse(traverser);
//    for(unsigned int i=0; i<dirList.GetCount(); i++) {
//    readinfo->WxComboBox1->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
//    readinfo->WxComboBox1->SetStringSelection(WxComboBox1->GetValue());
//    readinfo->WxListBox2->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
//    readinfo->WxComboBox3->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
//    readinfo->WxComboBox3->SetStringSelection(WxComboBox1->GetValue());
//    readinfo->WxComboBox4->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
//    readinfo->WxComboBox4->SetStringSelection(WxComboBox1->GetValue());
//    }};
//    
//    wxArrayString dirList2;
//    wxDirectoriesEnumerator traverser2(&dirList2);
//    wxDir fils("Data\\Programs\\"+WxComboBox1->GetValue()+"\\");
//    if(fils.IsOpened()){
//    fils.Traverse(traverser2);
//    for(unsigned int i=0; i<dirList2.GetCount(); i++) {
//    readinfo->WxListBox1->Append(dirList2.Item(i).AfterLast('\\').AfterLast('/').BeforeLast('.'));
//    readinfo->WxComboBox4->SetStringSelection(WxComboBox1->GetValue());
//    readinfo->WxComboBox2->Append(dirList2.Item(i).AfterLast('\\').AfterLast('/').BeforeLast('.'));
//    if(WxListBox1->GetStringSelection().IsEmpty()){
//        readinfo->WxComboBox2->SetSelection(0);
//    }else{
//        readinfo->WxComboBox2->SetStringSelection(WxListBox1->GetStringSelection());
//    }
//    }};
//    
//    readinfo->WxEdit1->SetValue("No Info. loaded. Click 'VIEW INFO' button to load ("+readinfo->WxComboBox2->GetValue()+") Info.");
//    readinfo->WxEdit1->Enable(false);
//    readinfo->WxButton2->SetLabel("VIEW INFO");
//    readinfo->WxNotebook1->ChangeSelection(2);
//    readinfo->WxButton3->SetLabel("UPDATE");
//    readinfo->WxButton3->Enable(false);
//    readinfo->WxButton4->SetLabel("OK");
//    readinfo->WxButton4->Enable(false);
//    readinfo->WxButton5->SetLabel("CLOSE");
//    readinfo->WxButton1->SetLabel("CLOSE");
//    readinfo->WxButton1->Enable(true); 
//    readinfo->WxButton8->SetLabel("ADD");
//    readinfo->WxButton6->SetLabel("CLOSE");
//    readinfo->WxButton7->SetLabel("OK");
//    readinfo->WxButton7->Enable(false);
//    readinfo->WxComboBox4->Enable(false);
//    readinfo->WxButton3->Enable(false);
//    readinfo->WxButton3->SetLabel("UPDATE");
//    readinfo->WxButton4->Enable(false);
//    readinfo->WxButton4->SetLabel("OK");
//    readinfo->WxButton5->Enable(true);
//    readinfo->WxButton5->SetLabel("CLOSE");
//    readinfo->SetLabel("Settings");
//    readinfo->Show();
//    
    
}
	// insert your code here
std::string getLastLine(std::ifstream& in)
{
    std::string line;
    while(in >> std::ws && std::getline(in, line));
    return line;
}

void KLBTOOLSFrm::KLBTOOLSFrmActivate(wxActivateEvent& event)
{    
    if(WxStaticText9->GetLabel()=="OnActive"){ 
        
        int itemCount = WxListBox1->GetCount();
        wxString itemCountStr = wxString::Format("%d", itemCount);
        WxStaticText15->SetLabel(itemCountStr);
        wxString CountStr = wxString::Format(" %d", itemCount);
        WxStaticText11->SetLabel(CountStr);
        
        WxEdit1->SetHint("Search Tools");
        WxGauge1->Hide();
        
        ifstream sysArchi;
        sysArchi.open("C:\\Windows\\SysWOW64\\wdscore.dll");
        if(sysArchi){
            WxCheckBox1->SetLabel("Run 32-bit Version");
        }else{
            WxCheckBox1->SetLabel("Run 64-bit Version");
        }
    
        remove("Data\\Resources\\klbsoft.temp\\ReadME!.txt"); 
        remove("Data\\Resources\\klbsoft.temp\\.tmpKLBSoft040194$.tmp");  
        WxComboBox1->Clear();
        WxListBox1->Clear();
        
        wxArrayString dirList;
        wxDirectoriesEnumerator traverser(&dirList);
        wxDir dir("Data\\Programs\\");
        if(dir.IsOpened()){
        dir.Traverse(traverser);
        for(unsigned int i=0; i<dirList.GetCount(); i++) {
        WxComboBox1->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
        WxComboBox1->SetSelection(0);
        }};
        
        WxStaticText1->SetLabel(WxComboBox1->GetString(0));
        wxArrayString dirList2;
        wxDirectoriesEnumerator traverser2(&dirList2);
        wxDir fils("Data\\Programs\\"+WxComboBox1->GetString(0)+"\\");
        if(fils.IsOpened()){
        fils.Traverse(traverser2);
        for(unsigned int i=0; i<dirList2.GetCount(); i++) {
        WxListBox1->Append(dirList2.Item(i).AfterLast('\\').AfterLast('/').BeforeLast('.'));
        }};
        
        
    }else{
    }

    WxStaticText9->SetLabel("");
    WxStaticText2->SetLabel("");  
   
}


void KLBTOOLSFrm::WxButton1Click(wxCommandEvent& event)
{
    WxStaticText18->SetLabel("viewInfo_btn");
    if(WxStaticText10->GetLabel()!="onView"){
    }else{
        if(WxListBox1->GetSelection()==-1){
            wxMessageBox("Please select tools first.","SELECT_TOOLS_ERROR",wxICON_ERROR|wxOK);
        }else{
            WxStaticText16->SetLabel("viewInfo");
            std::ifstream readME("Data\\Resources\\klbsoft.temp\\ReadME!.txt");
            if(!readME){
                if(WxStaticText19->GetLabel()=="runProg_btn"){
                   ReadInfoDlg *readinfo= new ReadInfoDlg(this);
                   readinfo->WxEdit1->Clear();
                   readinfo->WxEdit1->SetValue("No info. AVAILABLE.");
                   wxArrayString dirList;
                   wxDirectoriesEnumerator traverser(&dirList);
                   wxDir dir("Data\\Programs\\");
                   if(dir.IsOpened()){
                   dir.Traverse(traverser);
                   for(unsigned int i=0; i<dirList.GetCount(); i++) {
                   readinfo->WxComboBox1->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
                   readinfo->WxComboBox1->SetStringSelection(WxComboBox1->GetValue());
                   readinfo->WxListBox2->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
                   readinfo->WxComboBox3->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
                   readinfo->WxComboBox3->SetStringSelection(WxComboBox1->GetValue());
                   readinfo->WxComboBox4->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
                   readinfo->WxComboBox4->SetStringSelection(WxComboBox1->GetValue());
                   }};
                   
                   wxArrayString dirList2;
                   wxDirectoriesEnumerator traverser2(&dirList2);
                   wxDir fils("Data\\Programs\\"+WxComboBox1->GetValue()+"\\");
                   if(fils.IsOpened()){
                   fils.Traverse(traverser2);
                   for(unsigned int i=0; i<dirList2.GetCount(); i++) {
                   readinfo->WxListBox1->Append(dirList2.Item(i).AfterLast('\\').AfterLast('/').BeforeLast('.'));
                   readinfo->WxComboBox4->SetStringSelection(WxComboBox1->GetValue());
                   readinfo->WxComboBox2->Append(dirList2.Item(i).AfterLast('\\').AfterLast('/').BeforeLast('.'));
                   readinfo->WxComboBox2->SetStringSelection(WxListBox1->GetStringSelection());
                   }};
               
                   readinfo->WxNotebook1->ChangeSelection(2);
                   readinfo->WxComboBox1->Enable(false);
                   readinfo->WxComboBox2->Enable(false);
                   readinfo->WxButton3->SetLabel("UPDATE");
                   readinfo->WxButton3->Enable(false);
                   readinfo->WxButton4->SetLabel("OK");
                   readinfo->WxButton2->Enable(false);
                   readinfo->WxButton2->SetLabel("OK");
                   readinfo->WxButton4->Enable(false);
                   readinfo->WxButton5->SetLabel("CLOSE");
                   readinfo->WxButton1->SetLabel("CLOSE");
                   readinfo->WxButton1->Enable(true); 
                   readinfo->WxButton8->SetLabel("ADD");
                   readinfo->WxButton6->SetLabel("CLOSE");
                   readinfo->WxButton7->SetLabel("OK");
                   readinfo->WxButton7->Enable(false);
                   readinfo->WxComboBox4->Enable(false);
                   readinfo->WxButton3->Enable(false);
                   readinfo->WxButton3->SetLabel("UPDATE");
                   readinfo->WxButton4->Enable(false);
                   readinfo->WxButton4->SetLabel("OK");
                   readinfo->WxButton5->Enable(true);
                   readinfo->WxButton5->SetLabel("CLOSE");
                   readinfo->WxEdit1->Enable(true);
                   readinfo->WxEdit1->SetEditable(false);
                   readinfo->WxButton2->SetLabel("EDIT");
                   readinfo->WxButton2->Enable(true);
                   readinfo->SetLabel("About - ("+WxListBox1->GetStringSelection()+")");
                   WxStaticText10->SetLabel("onView");
                   readinfo->ShowModal();  
                }else{
                    wxString filePath = "Data\\Programs\\"+WxComboBox1->GetValue()+"\\"+WxListBox1->GetStringSelection()+".uha";

                    if (!filePath.IsEmpty())
                    {
                        wxFileName fileName(filePath);
            
                        if (fileName.FileExists())
                        {
                            wxFile file(filePath);
            
                            if (file.IsOpened())
                            {
                                wxFileOffset fileSize = file.Length();
                                wxString fileSizeString;
                                if (fileSize < 1024)
                                    fileSizeString = wxString::Format("%llu Bytes", static_cast<unsigned long long>(fileSize));
                                else if (fileSize < 1024 * 1024)
                                    fileSizeString = wxString::Format("%.2f KB", static_cast<double>(fileSize) / 1024);
                                else if (fileSize < 1024 * 1024 * 1024)
                                    fileSizeString = wxString::Format("%.2f MB", static_cast<double>(fileSize) / (1024 * 1024));
                                else
                                    fileSizeString = wxString::Format("%.2f GB", static_cast<double>(fileSize) / (1024 * 1024 * 1024));
            
                                WxStatusBar1->SetStatusText("Selected,  "+WxListBox1->GetStringSelection()+" ("+ fileSizeString+")", 1);
                                WxStatusBar1->SetStatusText("Extracting.. "+WxListBox1->GetStringSelection()+" ("+ fileSizeString+")", 1); 
                            }
                            else
                            {
                                wxMessageBox("Failed to open the file.", "Error", wxICON_ERROR | wxOK);
                            }
                        }
                        else
                        {
                            wxMessageBox("File not found.", "Error", wxICON_ERROR | wxOK);
                        }
                    }
                    else
                    {
                        wxMessageBox("Please enter a file path.", "Error", wxICON_ERROR | wxOK);
                    }
                    
                    WxButton1->Enable(false);
                    WxButton2->Enable(false);
                    WxListBox1->Enable(false);
                    
                    WxStaticText10->SetLabel(" ");
                    WxTimer1->Start(100);
                    ShellExecute(NULL,NULL,_T("cmd.exe"), _T("/c Data\\uharc.exe x -pw@@!!klbSoft$$2020!!@@ -t""Data\\Resources\\klbsoft.temp\\"" -y+ \"Data\\Programs\\"+WxStaticText1->GetLabel()+"\\"+WxListBox1->GetStringSelection()+".uha\" & echo WARNING!!! DO NOT DELETE!!! MASISIRA ANG BUHAY MO :)!!! - (c) 2020-2021 KLBSoft. All Rights Reserve.> Data\\Resources\\klbsoft.temp\\.tmpKLBSoft040194$.tmp"),NULL,SW_HIDE);        
                
                }
            }else{
               WxStaticText10->SetLabel(" ");
               ReadInfoDlg *readinfo= new ReadInfoDlg(this);
               readinfo->WxEdit1->Clear();
               wxFileInputStream input(wxT("Data\\Resources\\klbsoft.temp\\ReadME!.txt"));
               wxTextInputStream text(input,wxT("\x09"),wxConvUTF8);
               while(input.IsOk()&& !input.Eof()){
               wxString line=text.ReadLine();
               readinfo->WxEdit1->AppendText(line+"\n"); } 
               readinfo->WxComboBox1->Clear();
               readinfo->WxComboBox2->Clear();
               readinfo->WxComboBox3->Clear();
               wxArrayString dirList;
               wxDirectoriesEnumerator traverser(&dirList);
               wxDir dir("Data\\Programs\\");
               if(dir.IsOpened()){
               dir.Traverse(traverser);
               for(unsigned int i=0; i<dirList.GetCount(); i++) {
               readinfo->WxComboBox1->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
               readinfo->WxComboBox1->SetStringSelection(WxComboBox1->GetValue());
               readinfo->WxListBox2->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
               readinfo->WxComboBox3->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
               readinfo->WxComboBox3->SetStringSelection(WxComboBox1->GetValue());
               readinfo->WxComboBox4->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
               readinfo->WxComboBox4->SetStringSelection(WxComboBox1->GetValue());
               }};
               
               wxArrayString dirList2;
               wxDirectoriesEnumerator traverser2(&dirList2);
               wxDir fils("Data\\Programs\\"+WxComboBox1->GetValue()+"\\");
               if(fils.IsOpened()){
               fils.Traverse(traverser2);
               for(unsigned int i=0; i<dirList2.GetCount(); i++) {
               readinfo->WxListBox1->Append(dirList2.Item(i).AfterLast('\\').AfterLast('/').BeforeLast('.'));
               readinfo->WxComboBox4->SetStringSelection(WxComboBox1->GetValue());
               readinfo->WxComboBox2->Append(dirList2.Item(i).AfterLast('\\').AfterLast('/').BeforeLast('.'));
               readinfo->WxComboBox2->SetStringSelection(WxListBox1->GetStringSelection());
               }};
           
               readinfo->WxNotebook1->ChangeSelection(2);
               readinfo->WxComboBox1->Enable(false);
               readinfo->WxComboBox2->Enable(false);
               readinfo->WxButton3->SetLabel("UPDATE");
               readinfo->WxButton3->Enable(false);
               readinfo->WxButton4->SetLabel("OK");
               readinfo->WxButton2->Enable(false);
               readinfo->WxButton2->SetLabel("OK");
               readinfo->WxButton4->Enable(false);
               readinfo->WxButton5->SetLabel("CLOSE");
               readinfo->WxButton1->SetLabel("CLOSE");
               readinfo->WxButton1->Enable(true); 
               readinfo->WxButton8->SetLabel("ADD");
               readinfo->WxButton6->SetLabel("CLOSE");
               readinfo->WxButton7->SetLabel("OK");
               readinfo->WxButton7->Enable(false);
               readinfo->WxComboBox4->Enable(false);
               readinfo->WxButton3->Enable(false);
               readinfo->WxButton3->SetLabel("UPDATE");
               readinfo->WxButton4->Enable(false);
               readinfo->WxButton4->SetLabel("OK");
               readinfo->WxButton5->Enable(true);
               readinfo->WxButton5->SetLabel("CLOSE"); 
               readinfo->WxEdit1->Enable(true);
               readinfo->WxEdit1->SetEditable(false);
               readinfo->WxButton2->SetLabel("EDIT");
               readinfo->WxButton2->Enable(true);
               readinfo->SetLabel("About - ("+WxListBox1->GetStringSelection()+")");
               WxStaticText10->SetLabel("onView");
               readinfo->ShowModal();    
            }
            
        }
    }     
}

void KLBTOOLSFrm::WxButton2Click(wxCommandEvent& event)
{
    WxStaticText19->SetLabel("runProg_btn");
    
    if(WxStaticText14->GetLabel()!="onRun"){   
    }else{  
        if(WxListBox1->GetSelection()==-1){
            wxMessageBox("Please select tools first.","SELECT_TOOLS_ERROR",wxICON_ERROR|wxOK);
        }else{
            
            WxStaticText14->SetLabel("");
            wxString filePath = "Data\\Resources\\klbsoft.temp\\data_config.txt";
            if (wxFileName::FileExists(filePath)){
                ifstream sysArchi;
                sysArchi.open("C:\\Windows\\SysWOW64\\wdscore.dll");
                if(sysArchi){//////////////////////////////////64bit Achitecture/////////////////////////////
                    WxStaticText16->SetLabel("runProg64");
                    WxTimer1->Start(100);
                }else{////////////////////////////////////32bit achitecture/////////////////////
                    WxStaticText16->SetLabel("runProg32");
                    WxTimer1->Start(100);
                }  
            }else{
                
                wxString filePath = "Data\\Programs\\"+WxComboBox1->GetValue()+"\\"+WxListBox1->GetStringSelection()+".uha";

                    if (!filePath.IsEmpty())
                    {
                        wxFileName fileName(filePath);
            
                        if (fileName.FileExists())
                        {
                            wxFile file(filePath);
            
                            if (file.IsOpened())
                            {
                                wxFileOffset fileSize = file.Length();
                                wxString fileSizeString;
                                if (fileSize < 1024)
                                    fileSizeString = wxString::Format("%llu Bytes", static_cast<unsigned long long>(fileSize));
                                else if (fileSize < 1024 * 1024)
                                    fileSizeString = wxString::Format("%.2f KB", static_cast<double>(fileSize) / 1024);
                                else if (fileSize < 1024 * 1024 * 1024)
                                    fileSizeString = wxString::Format("%.2f MB", static_cast<double>(fileSize) / (1024 * 1024));
                                else
                                    fileSizeString = wxString::Format("%.2f GB", static_cast<double>(fileSize) / (1024 * 1024 * 1024));
                                    WxStatusBar1->SetStatusText("Extracting.. "+WxListBox1->GetStringSelection()+" ("+ fileSizeString+")", 1); 
                            }
                            else
                            {
                                wxMessageBox("Failed to open the file.", "Error", wxICON_ERROR | wxOK);
                            }
                        }
                        else
                        {
                            wxMessageBox("File not found.", "Error", wxICON_ERROR | wxOK);
                        }
                    }
                    else
                    {
                        wxMessageBox("Please enter a file path.", "Error", wxICON_ERROR | wxOK);
                    }
                
                ifstream sysArchi;
                sysArchi.open("C:\\Windows\\SysWOW64\\wdscore.dll");
                if(sysArchi){//////////////////////////////////64bit Achitecture/////////////////////////////
                    WxStaticText16->SetLabel("runProg64");
                    WxTimer1->Start(100);
                    wxString filePath = "Data\\Programs\\"+WxComboBox1->GetValue()+"\\"+WxListBox1->GetStringSelection()+".uha";

                    if (!filePath.IsEmpty())
                    {
                        wxFileName fileName(filePath);
            
                        if (fileName.FileExists())
                        {
                            wxFile file(filePath);
            
                            if (file.IsOpened())
                            {
                                wxFileOffset fileSize = file.Length();
                                wxString fileSizeString;
                                if (fileSize < 1024)
                                    fileSizeString = wxString::Format("%llu Bytes", static_cast<unsigned long long>(fileSize));
                                else if (fileSize < 1024 * 1024)
                                    fileSizeString = wxString::Format("%.2f KB", static_cast<double>(fileSize) / 1024);
                                else if (fileSize < 1024 * 1024 * 1024)
                                    fileSizeString = wxString::Format("%.2f MB", static_cast<double>(fileSize) / (1024 * 1024));
                                else
                                    fileSizeString = wxString::Format("%.2f GB", static_cast<double>(fileSize) / (1024 * 1024 * 1024));
            
                                WxStatusBar1->SetStatusText("Selected,  "+WxListBox1->GetStringSelection()+" ("+ fileSizeString+")", 1);
                                WxStatusBar1->SetStatusText("Extracting.. "+WxListBox1->GetStringSelection()+" ("+ fileSizeString+")", 1); 
                            }
                            else
                            {
                                wxMessageBox("Failed to open the file.", "Error", wxICON_ERROR | wxOK);
                            }
                        }
                        else
                        {
                            wxMessageBox("File not found.", "Error", wxICON_ERROR | wxOK);
                        }
                    }
                    else
                    {
                        wxMessageBox("Please enter a file path.", "Error", wxICON_ERROR | wxOK);
                    }
                    WxButton1->Enable(false);
                    WxButton2->Enable(false);
                    WxListBox1->Enable(false);
                    ShellExecute(NULL,NULL,_T("cmd.exe"), _T("/c Data\\uharc.exe x -pw@@!!klbSoft$$2020!!@@ -t""Data\\Resources\\klbsoft.temp\\"" -y+ \"Data\\Programs\\"+WxStaticText1->GetLabel()+"\\"+WxListBox1->GetStringSelection()+".uha\" & echo WARNING!!! DO NOT DELETE!!! MASISIRA ANG BUHAY MO :)!!! - (c) 2020-2021 KLBSoft. All Rights Reserve.> Data\\Resources\\klbsoft.temp\\.tmpKLBSoft040194$.tmp"),NULL,SW_HIDE);      
                }else{////////////////////////////////////32bit achitecture/////////////////////
                    WxStaticText16->SetLabel("runProg32");
                    WxTimer1->Start(100);
                    wxString filePath = "Data\\Programs\\"+WxComboBox1->GetValue()+"\\"+WxListBox1->GetStringSelection()+".uha";

                    if (!filePath.IsEmpty())
                    {
                        wxFileName fileName(filePath);
            
                        if (fileName.FileExists())
                        {
                            wxFile file(filePath);
            
                            if (file.IsOpened())
                            {
                                wxFileOffset fileSize = file.Length();
                                wxString fileSizeString;
                                if (fileSize < 1024)
                                    fileSizeString = wxString::Format("%llu Bytes", static_cast<unsigned long long>(fileSize));
                                else if (fileSize < 1024 * 1024)
                                    fileSizeString = wxString::Format("%.2f KB", static_cast<double>(fileSize) / 1024);
                                else if (fileSize < 1024 * 1024 * 1024)
                                    fileSizeString = wxString::Format("%.2f MB", static_cast<double>(fileSize) / (1024 * 1024));
                                else
                                    fileSizeString = wxString::Format("%.2f GB", static_cast<double>(fileSize) / (1024 * 1024 * 1024));
            
                                WxStatusBar1->SetStatusText("Selected,  "+WxListBox1->GetStringSelection()+" ("+ fileSizeString+")", 1);
                                WxStatusBar1->SetStatusText("Extracting.. "+WxListBox1->GetStringSelection()+" ("+ fileSizeString+")", 1); 
                            }
                            else
                            {
                                wxMessageBox("Failed to open the file.", "Error", wxICON_ERROR | wxOK);
                            }
                        }
                        else
                        {
                            wxMessageBox("File not found.", "Error", wxICON_ERROR | wxOK);
                        }
                    }
                    else
                    {
                        wxMessageBox("Please enter a file path.", "Error", wxICON_ERROR | wxOK);
                    }
                    WxButton1->Enable(false);
                    WxButton2->Enable(false);
                    WxListBox1->Enable(false);
                    ShellExecute(NULL,NULL,_T("cmd.exe"), _T("/c Data\\uharc.exe x -pw@@!!klbSoft$$2020!!@@ -t""Data\\Resources\\klbsoft.temp\\"" -y+ \"Data\\Programs\\"+WxStaticText1->GetLabel()+"\\"+WxListBox1->GetStringSelection()+".uha\" & echo WARNING!!! DO NOT DELETE!!! MASISIRA ANG BUHAY MO :)!!! - (c) 2020-2021 KLBSoft. All Rights Reserve.> Data\\Resources\\klbsoft.temp\\.tmpKLBSoft040194$.tmp"),NULL,SW_HIDE);         
                    
                } 
            } 
        }
    }
}

void KLBTOOLSFrm::Mnuinfosettings1018Click(wxCommandEvent& event)
{
    remove("Data\\Resources\\klbsoft.temp\\.tmp$MenuFile");  
    WxTimer2->Start(100);
    ReadInfoDlg *readinfo= new ReadInfoDlg(this);
    wxArrayString dirList;
    wxDirectoriesEnumerator traverser(&dirList);
    wxDir dir("Data\\Programs\\");
    if(dir.IsOpened()){
    dir.Traverse(traverser);
    for(unsigned int i=0; i<dirList.GetCount(); i++) {
    readinfo->WxComboBox1->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
    readinfo->WxComboBox1->SetStringSelection(WxComboBox1->GetValue());
    readinfo->WxListBox2->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
    readinfo->WxComboBox3->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
    readinfo->WxComboBox3->SetStringSelection(WxComboBox1->GetValue());
    readinfo->WxComboBox4->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
    readinfo->WxComboBox4->SetStringSelection(WxComboBox1->GetValue());
    }};
    
    wxArrayString dirList2;
    wxDirectoriesEnumerator traverser2(&dirList2);
    wxDir fils("Data\\Programs\\"+WxComboBox1->GetValue()+"\\");
    if(fils.IsOpened()){
    fils.Traverse(traverser2);
    for(unsigned int i=0; i<dirList2.GetCount(); i++) {
    readinfo->WxListBox1->Append(dirList2.Item(i).AfterLast('\\').AfterLast('/').BeforeLast('.'));
    readinfo->WxComboBox4->SetStringSelection(WxComboBox1->GetValue());
    readinfo->WxComboBox2->Append(dirList2.Item(i).AfterLast('\\').AfterLast('/').BeforeLast('.'));
    if(WxListBox1->GetStringSelection().IsEmpty()){
        readinfo->WxComboBox2->SetSelection(0);
    }else{
        readinfo->WxComboBox2->SetStringSelection(WxListBox1->GetStringSelection());
    }
    }};
    
    readinfo->WxEdit1->SetValue("No Info. loaded. Click 'VIEW INFO' button to load ("+readinfo->WxComboBox2->GetValue()+") Info.");
    readinfo->WxEdit1->Enable(false);
    readinfo->WxButton2->SetLabel("VIEW INFO");
    readinfo->WxNotebook1->ChangeSelection(2);
    readinfo->WxButton3->SetLabel("UPDATE");
    readinfo->WxButton3->Enable(false);
    readinfo->WxButton4->SetLabel("OK");
    readinfo->WxButton4->Enable(false);
    readinfo->WxButton5->SetLabel("CLOSE");
    readinfo->WxButton1->SetLabel("CLOSE");
    readinfo->WxButton1->Enable(true); 
    readinfo->WxButton8->SetLabel("ADD");
    readinfo->WxButton6->SetLabel("CLOSE");
    readinfo->WxButton7->SetLabel("OK");
    readinfo->WxButton7->Enable(false);
    readinfo->WxComboBox4->Enable(false);
    readinfo->WxButton3->Enable(false);
    readinfo->WxButton3->SetLabel("UPDATE");
    readinfo->WxButton4->Enable(false);
    readinfo->WxButton4->SetLabel("OK");
    readinfo->WxButton5->Enable(true);
    readinfo->WxButton5->SetLabel("CLOSE");
    readinfo->SetLabel("Settings");
    readinfo->Show();
}

/*
 * Mnuedittools1005Click
 */
void KLBTOOLSFrm::Mnuedittools1005Click(wxCommandEvent& event)
{  
    remove("Data\\Resources\\klbsoft.temp\\.tmp$MenuFile");  
    WxTimer2->Start(100);
    ReadInfoDlg *readinfo= new ReadInfoDlg(this);
    readinfo->WxEdit1->Enable(false);
    readinfo->WxEdit1->SetValue("No Info. loaded. Click 'VIEW INFO' button to load ("+WxListBox1->GetStringSelection()+") Info.");
    wxArrayString dirList;
    wxDirectoriesEnumerator traverser(&dirList);
    wxDir dir("Data\\Programs\\");
    if(dir.IsOpened()){
    dir.Traverse(traverser);
    for(unsigned int i=0; i<dirList.GetCount(); i++) {
    readinfo->WxComboBox1->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
    readinfo->WxComboBox1->SetStringSelection(WxComboBox1->GetValue());
    readinfo->WxListBox2->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
    readinfo->WxComboBox3->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
    readinfo->WxComboBox3->SetStringSelection(WxComboBox1->GetValue());
    readinfo->WxComboBox4->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
    readinfo->WxComboBox4->SetStringSelection(WxComboBox1->GetValue());
    }};
    
    wxArrayString dirList2;
    wxDirectoriesEnumerator traverser2(&dirList2);
    wxDir fils("Data\\Programs\\"+WxComboBox1->GetValue()+"\\");
    if(fils.IsOpened()){
    fils.Traverse(traverser2);
    for(unsigned int i=0; i<dirList2.GetCount(); i++) {
    readinfo->WxListBox1->Append(dirList2.Item(i).AfterLast('\\').AfterLast('/').BeforeLast('.'));
    readinfo->WxComboBox4->SetStringSelection(WxComboBox1->GetValue());
    readinfo->WxComboBox2->Append(dirList2.Item(i).AfterLast('\\').AfterLast('/').BeforeLast('.'));
    readinfo->WxComboBox2->SetStringSelection(WxListBox1->GetStringSelection());
    }};
        if(readinfo->WxComboBox2->GetValue().IsEmpty()){
            readinfo->WxButton3->SetLabel("UPDATE");
            readinfo->WxButton3->Enable(false);
            readinfo->WxButton4->SetLabel("OK");
            readinfo->WxButton4->Enable(false);
            readinfo->WxButton5->SetLabel("CLOSE");            
            readinfo->WxEdit1->SetValue("");
            readinfo->WxEdit1->Enable(false);
            //readinfo->WxStaticText5->SetLabel(" Empty. ");
            readinfo->WxButton2->SetLabel("OK");
            readinfo->WxButton2->Enable(false);
        }else{
            readinfo->WxListBox1->SetStringSelection(WxListBox1->GetStringSelection());
            readinfo->WxStaticBox2->SetLabel("Edit Tools ("+readinfo->WxListBox1->GetStringSelection()+" )");
            readinfo->WxEdit3->SetValue(readinfo->WxListBox1->GetStringSelection());
            readinfo->WxStaticText9->SetLabel(readinfo->WxListBox1->GetStringSelection());
            readinfo->WxEdit3->SetFocus();
            readinfo->WxEdit3->SelectAll();
            readinfo->WxButton3->Enable(true);
            readinfo->WxButton3->SetLabel("UPDATE");
            readinfo->WxButton4->Enable(true);
            readinfo->WxButton4->SetLabel("DELETE");
            readinfo->WxButton5->SetLabel("CANCEL");
            readinfo->WxEdit1->SetValue("No Info. loaded. Click 'VIEW INFO' button to load ("+readinfo->WxComboBox2->GetValue()+") Info.");
            readinfo->WxEdit1->Enable(false);
            //readinfo->WxStaticText5->SetLabel(" Ready... "+readinfo->WxComboBox2->GetValue()+" ");
            readinfo->WxButton2->SetLabel("VIEW INFO");
        }
        
    readinfo->WxNotebook1->ChangeSelection(1);
    readinfo->WxButton1->SetLabel("CLOSE");
    readinfo->WxButton1->Enable(true); 
    readinfo->WxButton8->SetLabel("ADD");
    readinfo->WxButton6->SetLabel("CLOSE");
    readinfo->WxButton7->SetLabel("OK");
    readinfo->WxButton7->Enable(false);
    readinfo->WxComboBox4->Enable(false);
    readinfo->WxButton5->Enable(true);
    readinfo->SetLabel("Settings");
    readinfo->Show();
}

/*
 * Mnuaddcategory1006Click
 */
void KLBTOOLSFrm::Mnuaddcategory1006Click(wxCommandEvent& event)
{
    try{
    remove("Data\\Resources\\klbsoft.temp\\.tmp$MenuFile");  
    WxTimer2->Start(100);
    ReadInfoDlg *readinfo= new ReadInfoDlg(this);
    readinfo->WxEdit1->Enable(false);
    readinfo->WxEdit1->SetValue("No Info. loaded. Click 'VIEW INFO' button to load ("+WxListBox1->GetStringSelection()+") Info.");
    wxArrayString dirList;
    wxDirectoriesEnumerator traverser(&dirList);
    wxDir dir("Data\\Programs\\");
    if(dir.IsOpened()){
    dir.Traverse(traverser);
    for(unsigned int i=0; i<dirList.GetCount(); i++) {
    readinfo->WxComboBox1->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
    readinfo->WxComboBox1->SetSelection(0);
    readinfo->WxListBox2->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
    
    readinfo->WxComboBox3->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
    readinfo->WxComboBox4->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
    readinfo->WxComboBox3->SetStringSelection(WxComboBox1->GetValue());
    readinfo->WxComboBox4->SetSelection(0);
    }};
    
    wxArrayString dirList2;
    wxDirectoriesEnumerator traverser2(&dirList2);
    wxDir fils("Data\\Programs\\"+readinfo->WxComboBox3->GetValue()+"\\");
    if(dir.IsOpened()){
    fils.Traverse(traverser2);
    for(unsigned int i=0; i<dirList2.GetCount(); i++) {
        //readinfo->WxListBox1->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
    readinfo->WxListBox1->Append(dirList2.Item(i).AfterLast('\\').AfterLast('/').BeforeLast('.'));
    readinfo->WxComboBox2->Append(dirList2.Item(i).AfterLast('\\').AfterLast('/').BeforeLast('.'));
    readinfo->WxComboBox2->SetSelection(0);
    }};
    readinfo->WxNotebook1->ChangeSelection(0);
    readinfo->WxButton3->SetLabel("UPDATE");
    readinfo->WxButton3->Enable(false);
    readinfo->WxButton4->SetLabel("OK");
    readinfo->WxButton4->Enable(false);
    readinfo->WxButton5->SetLabel("CLOSE");
    readinfo->WxButton2->Enable(true);
    readinfo->WxButton2->SetLabel("VIEW INFO");
    readinfo->WxButton8->SetLabel("ADD");
    readinfo->WxButton6->SetLabel("CLOSE");
    readinfo->WxButton7->SetLabel("OK");
    readinfo->WxButton7->Enable(false);
    readinfo->WxComboBox4->Enable(false);
    readinfo->WxEdit4->SetFocus();
    readinfo->SetLabel("Settings");
    readinfo->ShowModal();
    
    } catch (const std::exception& e) {
    wxMessageBox(wxString::Format("Exception: %s", e.what()), "Error", wxICON_ERROR);
}
}

/*
 * WxComboBox2Selected
 */
void KLBTOOLSFrm::WxComboBox2Selected(wxCommandEvent& event )
{
    if(WxComboBox2->GetStringSelection()=="Administrator"){
        WxStaticText18->SetLabel("");
    }else{
    }
}

/*
 * Mnuexit1021Click
 */
void KLBTOOLSFrm::Mnuexit1021Click(wxCommandEvent& event)
{
	// insert your code here
}

/*
 * Mnuexit1022Click
 */
void KLBTOOLSFrm::Mnuexit1022Click(wxCommandEvent& event)
{
	// insert your code here
}

/*
 * Mnuexit1026Click
 */
void KLBTOOLSFrm::Mnuexit1026Click(wxCommandEvent& event)
{
	// insert your code here
}

/*
 * WxButton3Click
 */
void KLBTOOLSFrm::WxButton3Click(wxCommandEvent& event)
{
    
   
}

/*
 * Mnuimporttoolsconfig1036Click
 */
void KLBTOOLSFrm::Mnuimporttoolsconfig1036Click(wxCommandEvent& event)
{ 
    AddInfoDlg *import = new  AddInfoDlg(this);
    import->WxStaticText1->SetLabel(WxComboBox1->GetStringSelection());
    import->WxStaticText2->SetLabel(WxListBox1->GetStringSelection());
    import->ShowModal();
}

/*
 * Mnuexporttoolsconfig1037Click
 */
void KLBTOOLSFrm::Mnuexporttoolsconfig1037Click(wxCommandEvent& event)
{
	// insert your code here
}

/*
 * Mnuexit1039Click
 */
void KLBTOOLSFrm::Mnuexit1039Click(wxCommandEvent& event)
{
	// insert your code here
}

/*
 * Mnudonation1041Click
 */
void KLBTOOLSFrm::Mnudonation1041Click(wxCommandEvent& event)
{
    AddInfoDlg *donate = new AddInfoDlg(this);
    donate->ShowModal();
	// insert your code here
}

/*
 * WxListCtrl1Selected
 */


/*
 * WxListBox1Selected0
 */
void KLBTOOLSFrm::WxListBox1Selected0(wxCommandEvent& event)
{  
    wxString filePath = "Data\\Programs\\"+WxComboBox1->GetValue()+"\\"+WxListBox1->GetStringSelection()+".uha";

        if (!filePath.IsEmpty())
        {
            wxFileName fileName(filePath);

            if (fileName.FileExists())
            {
                wxFile file(filePath);

                if (file.IsOpened())
                {
                    wxFileOffset fileSize = file.Length();
                    wxString fileSizeString;
                    if (fileSize < 1024)
                        fileSizeString = wxString::Format("%llu Bytes", static_cast<unsigned long long>(fileSize));
                    else if (fileSize < 1024 * 1024)
                        fileSizeString = wxString::Format("%.2f KB", static_cast<double>(fileSize) / 1024);
                    else if (fileSize < 1024 * 1024 * 1024)
                        fileSizeString = wxString::Format("%.2f MB", static_cast<double>(fileSize) / (1024 * 1024));
                    else
                        fileSizeString = wxString::Format("%.2f GB", static_cast<double>(fileSize) / (1024 * 1024 * 1024));

                    //WxStaticText22->SetLabel(" Tools Size: "+ fileSizeString);
                    WxStatusBar1->SetStatusText("Selected,  "+WxListBox1->GetStringSelection()+" ("+ fileSizeString+")", 1);
                }
                else
                {
                    wxMessageBox("Failed to open the file.", "Error", wxICON_ERROR | wxOK);
                }
            }
            else
            {
                wxMessageBox("File not found.", "Error", wxICON_ERROR | wxOK);
            }
        }
        else
        {
            wxMessageBox("Please enter a file path.", "Error", wxICON_ERROR | wxOK);
        }
    
    ShellExecute(NULL, NULL, _T("cmd.exe"), _T("/c DEL /S /Q Data\\Resources\\klbsoft.temp\\*.* && for /D %i in (Data\\Resources\\klbsoft.temp\\*) do rd /s /q \"%i\""), NULL, SW_HIDE);
    WxStaticText19->SetLabel("");
    WxComboBox2->Enable(true);
    WxButton1->Enable(true);
}

/*
 * WxComboBox1Selected0
 */
void KLBTOOLSFrm::WxComboBox1Selected0(wxCommandEvent& event )
{
    remove("Data\\Resources\\klbsoft.temp\\.tmpKLBSoft040194$.tmp");
    remove("Data\\Resources\\klbsoft.temp\\.tmpMCrProg.tmp"); 
    WxStaticText1->SetLabel(WxComboBox1->GetStringSelection());
    
    wxArrayString dirList;
    wxDirectoriesEnumerator traverser(&dirList);
    wxDir dir("Data\\Programs\\"+WxComboBox1->GetStringSelection()+"\\");
    if(dir.IsOpened()){
    dir.Traverse(traverser);
    WxListBox1->Clear();
    for(unsigned int i=0; i<dirList.GetCount(); i++) {
    WxListBox1->Append(dirList.Item(i).AfterLast('\\').AfterLast('/').BeforeLast('.'));
    }};
    if(WxListBox1->GetStrings().IsEmpty()){
    }else{
        WxComboBox2->SetSelection(0);
        WxListBox1->SetSelection(0);
    }
    
    int itemCount = WxListBox1->GetCount();
    wxString itemCountStr = wxString::Format("%d", itemCount);
    WxStaticText15->SetLabel(itemCountStr);
    wxString CountStr = wxString::Format(" %d", itemCount);
    WxStaticText11->SetLabel(CountStr);
    WxEdit1->Clear();
}

/*
 * Mnuexit1039Click0
 */
void KLBTOOLSFrm::Mnuexit1039Click0(wxCommandEvent& event)
{
    Destroy();
	// insert your code here
}

/*
 * WxButton3Click0
 */
void KLBTOOLSFrm::WxButton3Click0(wxCommandEvent& event)
{
    WxListBox1->Clear();
    wxArrayString dirList2;
    wxDirectoriesEnumerator traverser2(&dirList2);
    wxDir fils("Data\\Programs\\"+WxComboBox1->GetValue()+"\\");
    if(fils.IsOpened()){
    fils.Traverse(traverser2);
    for(unsigned int i=0; i<dirList2.GetCount(); i++) {
    WxListBox1->Append(dirList2.Item(i).AfterLast('\\').AfterLast('/').BeforeLast('.'));
    }};
   
	// insert your code here
}

/*
 * Mnureadme1072Click
 */
void KLBTOOLSFrm::Mnureadme1072Click(wxCommandEvent& event)
{
    ReadInfoDlg *readinfo= new ReadInfoDlg(this);
    wxFileInputStream input(wxT("Data\\.klbSoft\\readme.txt"));
    wxTextInputStream text(input,wxT("\x09"),wxConvUTF8);
    while(input.IsOk()&& !input.Eof()){
    wxString line=text.ReadLine();
    readinfo->WxEdit1->AppendText(line+"\n"); } 
    readinfo->WxComboBox1->Clear();
    readinfo->WxComboBox2->Clear();
    readinfo->WxComboBox3->Clear();
    wxArrayString dirList;
    wxDirectoriesEnumerator traverser(&dirList);
    wxDir dir("Data\\Programs\\");
    if(dir.IsOpened()){
    dir.Traverse(traverser);
    for(unsigned int i=0; i<dirList.GetCount(); i++) {
    readinfo->WxComboBox1->Append("ReadMe");
    readinfo->WxComboBox1->SetSelection(0);
    readinfo->WxListBox2->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
    readinfo->WxComboBox3->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
    readinfo->WxComboBox3->SetStringSelection(WxComboBox1->GetValue());
    readinfo->WxComboBox4->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
    readinfo->WxComboBox4->SetStringSelection(WxComboBox1->GetValue());
    }};
    
    wxArrayString dirList2;
    wxDirectoriesEnumerator traverser2(&dirList2);
    wxDir fils("Data\\Programs\\"+WxComboBox1->GetValue()+"\\");
    if(fils.IsOpened()){
    fils.Traverse(traverser2);
    for(unsigned int i=0; i<dirList2.GetCount(); i++) {
    readinfo->WxListBox1->Append(dirList2.Item(i).AfterLast('\\').AfterLast('/').BeforeLast('.'));
    readinfo->WxComboBox4->SetStringSelection(WxComboBox1->GetValue());
    readinfo->WxComboBox2->Append("readme.txt");
    readinfo->WxComboBox2->SetSelection(0);
    }};

    readinfo->WxNotebook1->ChangeSelection(2);
    readinfo->WxComboBox1->Enable(false);
    readinfo->WxComboBox2->Enable(false);
    readinfo->WxButton3->SetLabel("UPDATE");
    readinfo->WxButton3->Enable(false);
    readinfo->WxButton4->SetLabel("OK");
    readinfo->WxButton2->Enable(false);
    readinfo->WxButton2->SetLabel("OK");
    readinfo->WxButton4->Enable(false);
    readinfo->WxButton5->SetLabel("CLOSE");
    readinfo->WxButton1->SetLabel("CLOSE");
    readinfo->WxButton1->Enable(true); 
    readinfo->WxButton8->SetLabel("ADD");
    readinfo->WxButton6->SetLabel("CLOSE");
    readinfo->WxButton7->SetLabel("OK");
    readinfo->WxButton7->Enable(false);
    readinfo->WxComboBox4->Enable(false);
    readinfo->WxButton3->Enable(false);
    readinfo->WxButton3->SetLabel("UPDATE");
    readinfo->WxButton4->Enable(false);
    readinfo->WxButton4->SetLabel("OK");
    readinfo->WxButton5->Enable(true);
    readinfo->WxButton5->SetLabel("CLOSE");    
    readinfo->SetLabel("KLB Tools Launcher (ReadMe)");  
    //readinfo->WxStaticBox7->SetLabel("Document Type");
   // readinfo->WxStaticBox8->SetLabel("File Name");
    //readinfo->WxStaticText5->SetLabel(" Author:");
   // readinfo->WxStaticText13->SetLabel(" KIM BILLANTE (Code358)");
    readinfo->ShowModal();
	// insert your code here
}

/*
 * Mnuabout1008Click0
 */
void KLBTOOLSFrm::Mnuabout1008Click0(wxCommandEvent& event)
{
    AboutDlg *about = new AboutDlg(this);
    about->ShowModal();
    
    //Untitled1Dlg *about = new Untitled1Dlg(this);
//    about->ShowModal();
	// insert your code here
}

/*
 * Mnuviewliscenseagreement1094Click
 */
void KLBTOOLSFrm::Mnuviewliscenseagreement1094Click(wxCommandEvent& event)
{
    ReadInfoDlg *readinfo= new ReadInfoDlg(this);
    wxFileInputStream input(wxT("Data\\.klbSoft\\license.txt"));
    wxTextInputStream text(input,wxT("\x09"),wxConvUTF8);
    while(input.IsOk()&& !input.Eof()){
    wxString line=text.ReadLine();
    readinfo->WxEdit1->AppendText(line+"\n"); } 
    readinfo->WxComboBox1->Clear();
    readinfo->WxComboBox2->Clear();
    readinfo->WxComboBox3->Clear();
    wxArrayString dirList;
    wxDirectoriesEnumerator traverser(&dirList);
    wxDir dir("Data\\Programs\\");
    if(dir.IsOpened()){
    dir.Traverse(traverser);
    for(unsigned int i=0; i<dirList.GetCount(); i++) {
    readinfo->WxComboBox1->Append("License Agreement");
    readinfo->WxComboBox1->SetSelection(0);
    readinfo->WxListBox2->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
    readinfo->WxComboBox3->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
    readinfo->WxComboBox3->SetStringSelection(WxComboBox1->GetValue());
    readinfo->WxComboBox4->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
    readinfo->WxComboBox4->SetStringSelection(WxComboBox1->GetValue());
    }};
    
    wxArrayString dirList2;
    wxDirectoriesEnumerator traverser2(&dirList2);
    wxDir fils("Data\\Programs\\"+WxComboBox1->GetValue()+"\\");
    if(fils.IsOpened()){
    fils.Traverse(traverser2);
    for(unsigned int i=0; i<dirList2.GetCount(); i++) {
    readinfo->WxListBox1->Append(dirList2.Item(i).AfterLast('\\').AfterLast('/').BeforeLast('.'));
    readinfo->WxComboBox4->SetStringSelection(WxComboBox1->GetValue());
    readinfo->WxComboBox2->Append("license.txt");
    readinfo->WxComboBox2->SetSelection(0);
    }};

    readinfo->WxNotebook1->ChangeSelection(2);
    readinfo->WxComboBox1->Enable(false);
    readinfo->WxComboBox2->Enable(false);
    readinfo->WxButton3->SetLabel("UPDATE");
    readinfo->WxButton3->Enable(false);
    readinfo->WxButton4->SetLabel("OK");
    readinfo->WxButton2->Enable(false);
    readinfo->WxButton2->SetLabel("OK");
    readinfo->WxButton4->Enable(false);
    readinfo->WxButton5->SetLabel("CLOSE");
    readinfo->WxButton1->SetLabel("CLOSE");
    readinfo->WxButton1->Enable(true); 
    readinfo->WxButton8->SetLabel("ADD");
    readinfo->WxButton6->SetLabel("CLOSE");
    readinfo->WxButton7->SetLabel("OK");
    readinfo->WxButton7->Enable(false);
    readinfo->WxComboBox4->Enable(false);
    readinfo->WxButton3->Enable(false);
    readinfo->WxButton3->SetLabel("UPDATE");
    readinfo->WxButton4->Enable(false);
    readinfo->WxButton4->SetLabel("OK");
    readinfo->WxButton5->Enable(true);
    readinfo->WxButton5->SetLabel("CLOSE");    
    readinfo->SetLabel("KLB Tools Launcher (License Agreement)");  
    //readinfo->WxStaticBox7->SetLabel("Document Type");
    //readinfo->WxStaticBox8->SetLabel("File Name");
  //  readinfo->WxStaticText5->SetLabel(" Author:");
   // readinfo->WxStaticText13->SetLabel(" KIM BILLANTE (Code358)");
    readinfo->ShowModal();
	// insert your code here
}

/*
 * Mnuuserlogs1096Click
 */
void KLBTOOLSFrm::Mnuuserlogs1096Click(wxCommandEvent& event)
{
    ReadInfoDlg *readinfo= new ReadInfoDlg(this);
    wxFileInputStream input(wxT("Data\\.klbSoft\\user.txt"));
    wxTextInputStream text(input,wxT("\x09"),wxConvUTF8);
    while(input.IsOk()&& !input.Eof()){
    wxString line=text.ReadLine();
    readinfo->WxEdit1->AppendText(line+"\n"); } 
    readinfo->WxComboBox1->Clear();
    readinfo->WxComboBox2->Clear();
    readinfo->WxComboBox3->Clear();
    wxArrayString dirList;
    wxDirectoriesEnumerator traverser(&dirList);
    wxDir dir("Data\\Programs\\");
    if(dir.IsOpened()){
    dir.Traverse(traverser);
    for(unsigned int i=0; i<dirList.GetCount(); i++) {
    readinfo->WxComboBox1->Append("User Logs");
    readinfo->WxComboBox1->SetSelection(0);
    readinfo->WxListBox2->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
    readinfo->WxComboBox3->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
    readinfo->WxComboBox3->SetStringSelection(WxComboBox1->GetValue());
    readinfo->WxComboBox4->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
    readinfo->WxComboBox4->SetStringSelection(WxComboBox1->GetValue());
    }};
    
    wxArrayString dirList2;
    wxDirectoriesEnumerator traverser2(&dirList2);
    wxDir fils("Data\\Programs\\"+WxComboBox1->GetValue()+"\\");
    if(fils.IsOpened()){
    fils.Traverse(traverser2);
    for(unsigned int i=0; i<dirList2.GetCount(); i++) {
    readinfo->WxListBox1->Append(dirList2.Item(i).AfterLast('\\').AfterLast('/').BeforeLast('.'));
    readinfo->WxComboBox4->SetStringSelection(WxComboBox1->GetValue());
    readinfo->WxComboBox2->Append("user.txt");
    readinfo->WxComboBox2->SetSelection(0);
    }};

    readinfo->WxNotebook1->ChangeSelection(2);
    readinfo->WxComboBox1->Enable(false);
    readinfo->WxComboBox2->Enable(false);
    readinfo->WxButton3->SetLabel("UPDATE");
    readinfo->WxButton3->Enable(false);
    readinfo->WxButton4->SetLabel("OK");
    readinfo->WxButton2->Enable(false);
    readinfo->WxButton2->SetLabel("OK");
    readinfo->WxButton4->Enable(false);
    readinfo->WxButton5->SetLabel("CLOSE");
    readinfo->WxButton1->SetLabel("CLOSE");
    readinfo->WxButton1->Enable(true); 
    readinfo->WxButton8->SetLabel("ADD");
    readinfo->WxButton6->SetLabel("CLOSE");
    readinfo->WxButton7->SetLabel("OK");
    readinfo->WxButton7->Enable(false);
    readinfo->WxComboBox4->Enable(false);
    readinfo->WxButton3->Enable(false);
    readinfo->WxButton3->SetLabel("UPDATE");
    readinfo->WxButton4->Enable(false);
    readinfo->WxButton4->SetLabel("OK");
    readinfo->WxButton5->Enable(true);
    readinfo->WxButton5->SetLabel("CLOSE");    
    readinfo->SetLabel("KLB Tools Launcher (User Logs)");  
    //readinfo->WxStaticBox7->SetLabel("Document Type");
    //readinfo->WxStaticBox8->SetLabel("File Name");
    //readinfo->WxStaticText5->SetLabel(" Author:");
    //readinfo->WxStaticText13->SetLabel(" KIM BILLANTE (Code358)");
    readinfo->ShowModal();
	// insert your code here
}

/*
 * WxListBox1UpdateUI
 */
void KLBTOOLSFrm::WxListBox1UpdateUI(wxUpdateUIEvent& event)
{
    
	// insert your code here
}

/*
 * WxTimer1Timer
 */
void KLBTOOLSFrm::WxTimer1Timer(wxTimerEvent& event)
{
    if(WxStaticText16->GetLabel()=="viewInfo"){
        
        wxString filePath = "Data\\Resources\\klbsoft.temp\\.tmpKLBSoft040194$.tmp";
        if (wxFileName::FileExists(filePath)){
            WxGauge1->SetValue(0);
            WxTimer1->Stop();
            WxGauge1->Hide();
            
            WxButton1->Enable(true);
            WxButton2->Enable(true);
            WxListBox1->Enable(true);
            
            std::ifstream readME("Data\\Resources\\klbsoft.temp\\ReadME!.txt");
            if(!readME){
               ReadInfoDlg *readinfo= new ReadInfoDlg(this);
               readinfo->WxEdit1->Clear();
               readinfo->WxEdit1->SetValue("No info. AVAILABLE.");
               wxArrayString dirList;
               wxDirectoriesEnumerator traverser(&dirList);
               wxDir dir("Data\\Programs\\");
               if(dir.IsOpened()){
               dir.Traverse(traverser);
               for(unsigned int i=0; i<dirList.GetCount(); i++) {
               readinfo->WxComboBox1->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
               readinfo->WxComboBox1->SetStringSelection(WxComboBox1->GetValue());
               readinfo->WxListBox2->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
               readinfo->WxComboBox3->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
               readinfo->WxComboBox3->SetStringSelection(WxComboBox1->GetValue());
               readinfo->WxComboBox4->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
               readinfo->WxComboBox4->SetStringSelection(WxComboBox1->GetValue());
               }};
               
               wxArrayString dirList2;
               wxDirectoriesEnumerator traverser2(&dirList2);
               wxDir fils("Data\\Programs\\"+WxComboBox1->GetValue()+"\\");
               if(fils.IsOpened()){
               fils.Traverse(traverser2);
               for(unsigned int i=0; i<dirList2.GetCount(); i++) {
               readinfo->WxListBox1->Append(dirList2.Item(i).AfterLast('\\').AfterLast('/').BeforeLast('.'));
               readinfo->WxComboBox4->SetStringSelection(WxComboBox1->GetValue());
               readinfo->WxComboBox2->Append(dirList2.Item(i).AfterLast('\\').AfterLast('/').BeforeLast('.'));
               readinfo->WxComboBox2->SetStringSelection(WxListBox1->GetStringSelection());
               }};
               
           
               readinfo->WxNotebook1->ChangeSelection(2);
               readinfo->WxComboBox1->Enable(false);
               readinfo->WxComboBox2->Enable(false);
               readinfo->WxButton3->SetLabel("UPDATE");
               readinfo->WxButton3->Enable(false);
               readinfo->WxButton4->SetLabel("OK");
               readinfo->WxButton2->Enable(false);
               readinfo->WxButton2->SetLabel("OK");
               readinfo->WxButton4->Enable(false);
               readinfo->WxButton5->SetLabel("CLOSE");
               readinfo->WxButton1->SetLabel("CLOSE");
               readinfo->WxButton1->Enable(true); 
               readinfo->WxButton8->SetLabel("ADD");
               readinfo->WxButton6->SetLabel("CLOSE");
               readinfo->WxButton7->SetLabel("OK");
               readinfo->WxButton7->Enable(false);
               readinfo->WxComboBox4->Enable(false);
               readinfo->WxButton3->Enable(false);
               readinfo->WxButton3->SetLabel("UPDATE");
               readinfo->WxButton4->Enable(false);
               readinfo->WxButton4->SetLabel("OK");
               readinfo->WxButton5->Enable(true);
               readinfo->WxButton5->SetLabel("CLOSE");
               readinfo->WxEdit1->Enable(true);
               readinfo->WxEdit1->SetEditable(false);
               readinfo->WxButton2->SetLabel("EDIT");
               readinfo->WxButton2->Enable(true);
               readinfo->SetLabel("About - ("+WxListBox1->GetStringSelection()+")");
               WxStaticText10->SetLabel("onView");
               readinfo->ShowModal();  
            }else{
               ReadInfoDlg *readinfo= new ReadInfoDlg(this);
               readinfo->WxEdit1->Clear();
               wxFileInputStream input(wxT("Data\\Resources\\klbsoft.temp\\ReadME!.txt"));
               wxTextInputStream text(input,wxT("\x09"),wxConvUTF8);
               while(input.IsOk()&& !input.Eof()){
               wxString line=text.ReadLine();
               readinfo->WxEdit1->AppendText(line+"\n"); } 
               readinfo->WxComboBox1->Clear();
               readinfo->WxComboBox2->Clear();
               readinfo->WxComboBox3->Clear();
               wxArrayString dirList;
               wxDirectoriesEnumerator traverser(&dirList);
               wxDir dir("Data\\Programs\\");
               if(dir.IsOpened()){
               dir.Traverse(traverser);
               for(unsigned int i=0; i<dirList.GetCount(); i++) {
               readinfo->WxComboBox1->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
               readinfo->WxComboBox1->SetStringSelection(WxComboBox1->GetValue());
               readinfo->WxListBox2->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
               readinfo->WxComboBox3->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
               readinfo->WxComboBox3->SetStringSelection(WxComboBox1->GetValue());
               readinfo->WxComboBox4->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
               readinfo->WxComboBox4->SetStringSelection(WxComboBox1->GetValue());
               }};
               
               wxArrayString dirList2;
               wxDirectoriesEnumerator traverser2(&dirList2);
               wxDir fils("Data\\Programs\\"+WxComboBox1->GetValue()+"\\");
               if(fils.IsOpened()){
               fils.Traverse(traverser2);
               for(unsigned int i=0; i<dirList2.GetCount(); i++) {
               readinfo->WxListBox1->Append(dirList2.Item(i).AfterLast('\\').AfterLast('/').BeforeLast('.'));
               readinfo->WxComboBox4->SetStringSelection(WxComboBox1->GetValue());
               readinfo->WxComboBox2->Append(dirList2.Item(i).AfterLast('\\').AfterLast('/').BeforeLast('.'));
               readinfo->WxComboBox2->SetStringSelection(WxListBox1->GetStringSelection());
               }};
           
               readinfo->WxNotebook1->ChangeSelection(2);
               readinfo->WxComboBox1->Enable(false);
               readinfo->WxComboBox2->Enable(false);
               readinfo->WxButton3->SetLabel("UPDATE");
               readinfo->WxButton3->Enable(false);
               readinfo->WxButton4->SetLabel("OK");
               readinfo->WxButton2->Enable(false);
               readinfo->WxButton2->SetLabel("OK");
               readinfo->WxButton4->Enable(false);
               readinfo->WxButton5->SetLabel("CLOSE");
               readinfo->WxButton1->SetLabel("CLOSE");
               readinfo->WxButton1->Enable(true); 
               readinfo->WxButton8->SetLabel("ADD");
               readinfo->WxButton6->SetLabel("CLOSE");
               readinfo->WxButton7->SetLabel("OK");
               readinfo->WxButton7->Enable(false);
               readinfo->WxComboBox4->Enable(false);
               readinfo->WxButton3->Enable(false);
               readinfo->WxButton3->SetLabel("UPDATE");
               readinfo->WxButton4->Enable(false);
               readinfo->WxButton4->SetLabel("OK");
               readinfo->WxButton5->Enable(true);
               readinfo->WxButton5->SetLabel("CLOSE"); 
               readinfo->WxEdit1->Enable(true);
               readinfo->WxEdit1->SetEditable(false);
               readinfo->WxButton2->SetLabel("EDIT");
               readinfo->WxButton2->Enable(true);
               readinfo->SetLabel("About - ("+WxListBox1->GetStringSelection()+")");
               WxStaticText10->SetLabel("onView");
               readinfo->ShowModal();
            }   
            
        }else{
            WxGauge1->Show();
            int counter= 1000;
            counter++;
            WxGauge1->SetValue(counter % (WxGauge1->GetRange()+ 1)); 
        } 
    }else if(WxStaticText16->GetLabel()=="runProg64"){
    
        
        wxString filePath = "Data\\Resources\\klbsoft.temp\\.tmpKLBSoft040194$.tmp";
        if (wxFileName::FileExists(filePath)){
            WxGauge1->SetValue(0);
            WxTimer1->Stop(); 
            WxGauge1->Hide();
            WxButton1->Enable(true);
            WxButton2->Enable(true);
            WxListBox1->Enable(true);
            
            wxString filePath = "Data\\Programs\\"+WxComboBox1->GetValue()+"\\"+WxListBox1->GetStringSelection()+".uha";

        if (!filePath.IsEmpty())
        {
            wxFileName fileName(filePath);

            if (fileName.FileExists())
            {
                wxFile file(filePath);

                if (file.IsOpened())
                {
                    wxFileOffset fileSize = file.Length();
                    wxString fileSizeString;
                    if (fileSize < 1024)
                        fileSizeString = wxString::Format("%llu Bytes", static_cast<unsigned long long>(fileSize));
                    else if (fileSize < 1024 * 1024)
                        fileSizeString = wxString::Format("%.2f KB", static_cast<double>(fileSize) / 1024);
                    else if (fileSize < 1024 * 1024 * 1024)
                        fileSizeString = wxString::Format("%.2f MB", static_cast<double>(fileSize) / (1024 * 1024));
                    else
                        fileSizeString = wxString::Format("%.2f GB", static_cast<double>(fileSize) / (1024 * 1024 * 1024));

                    //WxStaticText22->SetLabel(" Tools Size: "+ fileSizeString);
                    WxStatusBar1->SetStatusText("Selected,  "+WxListBox1->GetStringSelection()+" ("+ fileSizeString+")", 1);
                }
                else
                {
                    wxMessageBox("Failed to open the file.", "Error", wxICON_ERROR | wxOK);
                }
            }
            else
            {
                wxMessageBox("File not found.", "Error", wxICON_ERROR | wxOK);
            }
        }
        else
        {
            wxMessageBox("Please enter a file path.", "Error", wxICON_ERROR | wxOK);
        }
            
            
            
            if(WxComboBox2->GetValue()=="Administrator"){////////administrator
                std::ifstream lineNum("Data\\Resources\\klbsoft.temp\\data_config.txt");
    
                    if (lineNum.is_open()) {
                        std::string lineData;
                        for (int i = 0; i < 4 && getline(lineNum, lineData); i++) {
                            if (i == 0) {
                            } else if (i == 1) {
                                WxStaticText20->SetLabel(lineData);
                            } else if (i == 2) {
                                WxStaticText21->SetLabel(lineData);
                            } else if (i == 3) {
                                WxStaticText6->SetLabel(lineData);
                            }
                        }
                        lineNum.close();
                    }
                    
                    if(WxStaticText6->GetLabel()=="cpa"){
                       if(WxCheckBox1->IsChecked()){
                           ShellExecuteA(NULL, "runas",_T("Data\\Resources\\klbsoft.temp\\"+WxStaticText20->GetLabel()), NULL, NULL, SW_SHOWNORMAL); 
                            WxStaticText18->SetLabel("");
                       }else{
                            ShellExecuteA(NULL, "runas",_T("Data\\Resources\\klbsoft.temp\\"+WxStaticText20->GetLabel()), NULL, NULL, SW_SHOWNORMAL);}
                    }else if(WxStaticText6->GetLabel()=="combine"){
                       if(WxCheckBox1->IsChecked()){
                           ShellExecuteA(NULL, "runas",_T("Data\\Resources\\klbsoft.temp\\"+WxStaticText20->GetLabel()), NULL, NULL, SW_SHOWNORMAL); 
                       }else{
                            ShellExecuteA(NULL, "runas",_T("Data\\Resources\\klbsoft.temp\\"+WxStaticText21->GetLabel()), NULL, NULL, SW_SHOWNORMAL);
                       }
                    }else if(WxStaticText6->GetLabel()=="32bit"){
                       if(WxCheckBox1->IsChecked()){
                           ShellExecuteA(NULL, "runas",_T("Data\\Resources\\klbsoft.temp\\"+WxStaticText20->GetLabel()), NULL, NULL, SW_SHOWNORMAL); 
                       }else{
                            wxMessageBox("'"+WxListBox1->GetStringSelection()+"' is not compatible with the version of Windows you're running.","Error",wxICON_ERROR|wxOK);
                       }
                    }else if(WxStaticText6->GetLabel()=="64bit"){
                        if (WxCheckBox1->IsChecked()) {
                            wxMessageBox(wxString::Format("'%s' doesn't have a 32-bit version.", WxListBox1->GetStringSelection()), "Error", wxICON_ERROR | wxOK);
                        } else {
                            ShellExecuteA(NULL, "runas", _T("Data\\Resources\\klbsoft.temp\\") + WxStaticText21->GetLabel(), NULL, NULL, SW_SHOWNORMAL);
                        }
                    }
                    WxStaticText14->SetLabel("onRun");
                 
            }else{ //////////if not administrator
            
                 std::ifstream lineNum("Data\\Resources\\klbsoft.temp\\data_config.txt");

                if (lineNum.is_open()) {
                    std::string lineData;
                    for (int i = 0; i < 4 && getline(lineNum, lineData); i++) {
                        if (i == 0) {
                        } else if (i == 1) {
                            WxStaticText20->SetLabel(lineData);
                        } else if (i == 2) {
                            WxStaticText21->SetLabel(lineData);
                        } else if (i == 3) {
                            WxStaticText6->SetLabel(lineData);
                        }
                    }
                    lineNum.close();
                }
                
                if(WxStaticText6->GetLabel()=="cpa"){
                   if(WxCheckBox1->IsChecked()){
                       wxString filePath = wxString::Format(_T("Data\\Resources\\klbsoft.temp\\%s"), WxStaticText20->GetLabel());
                        ShellExecute(NULL, _T("open"), filePath.c_str(), NULL, NULL, SW_SHOWNORMAL);
                   }else{
                        wxString filePath = wxString::Format(_T("Data\\Resources\\klbsoft.temp\\%s"), WxStaticText20->GetLabel());
                        ShellExecute(NULL, _T("open"), filePath.c_str(), NULL, NULL, SW_SHOWNORMAL);
                        //ShellExecuteA(GetDesktopWindow(), "open","C:\\Windows\\klbsoft.temp\\"+WxStaticText20->GetLabel(), NULL, NULL, SW_SHOWNORMAL);                        
                   }
                }else if(WxStaticText6->GetLabel()=="combine"){
                   if(WxCheckBox1->IsChecked()){
                       wxString filePath = wxString::Format(_T("Data\\Resources\\klbsoft.temp\\%s"), WxStaticText20->GetLabel());
                        ShellExecute(NULL, _T("open"), filePath.c_str(), NULL, NULL, SW_SHOWNORMAL);
                   }else{
                        wxString filePath = wxString::Format(_T("Data\\Resources\\klbsoft.temp\\%s"), WxStaticText21->GetLabel());
                        ShellExecute(NULL, _T("open"), filePath.c_str(), NULL, NULL, SW_SHOWNORMAL);
                    }
                }else if(WxStaticText6->GetLabel()=="32bit"){
                   if(WxCheckBox1->IsChecked()){
                        wxString filePath = wxString::Format(_T("Data\\Resources\\klbsoft.temp\\%s"), WxStaticText20->GetLabel());
                        ShellExecute(NULL, _T("open"), filePath.c_str(), NULL, NULL, SW_SHOWNORMAL);
                   }else{
                        wxMessageBox("'"+WxListBox1->GetStringSelection()+"' is not compatible with the version of Windows you're running.","Error",wxICON_ERROR|wxOK);
                   }
                }else if(WxStaticText6->GetLabel()=="64bit"){
                    if (WxCheckBox1->IsChecked()) {
                        wxMessageBox(wxString::Format("'%s' doesn't have a 32-bit version.", WxListBox1->GetStringSelection()), "Error", wxICON_ERROR | wxOK);
                    } else {
                        wxString filePath = wxString::Format(_T("Data\\Resources\\klbsoft.temp\\%s"), WxStaticText21->GetLabel());
                        ShellExecute(NULL, _T("open"), filePath.c_str(), NULL, NULL, SW_SHOWNORMAL);
                    }
                }
                WxStaticText14->SetLabel("onRun");
            }  
        }else{
            WxGauge1->Show();
            int counter= 1000;
            counter++;
            WxGauge1->SetValue(counter % (WxGauge1->GetRange()+ 1)); 
        } 
    }else if(WxStaticText16->GetLabel()=="runProg32"){
        wxString filePath = "Data\\Resources\\klbsoft.temp\\.tmpKLBSoft040194$.tmp";
        if (wxFileName::FileExists(filePath)){
            WxGauge1->SetValue(0);
            WxTimer1->Stop(); 
            WxGauge1->Hide();
            WxButton1->Enable(true);
            WxButton2->Enable(true);
            WxListBox1->Enable(true);
            
            wxString filePath = "Data\\Programs\\"+WxComboBox1->GetValue()+"\\"+WxListBox1->GetStringSelection()+".uha";

        if (!filePath.IsEmpty())
        {
            wxFileName fileName(filePath);

            if (fileName.FileExists())
            {
                wxFile file(filePath);

                if (file.IsOpened())
                {
                    wxFileOffset fileSize = file.Length();
                    wxString fileSizeString;
                    if (fileSize < 1024)
                        fileSizeString = wxString::Format("%llu Bytes", static_cast<unsigned long long>(fileSize));
                    else if (fileSize < 1024 * 1024)
                        fileSizeString = wxString::Format("%.2f KB", static_cast<double>(fileSize) / 1024);
                    else if (fileSize < 1024 * 1024 * 1024)
                        fileSizeString = wxString::Format("%.2f MB", static_cast<double>(fileSize) / (1024 * 1024));
                    else
                        fileSizeString = wxString::Format("%.2f GB", static_cast<double>(fileSize) / (1024 * 1024 * 1024));

                    //WxStaticText22->SetLabel(" Tools Size: "+ fileSizeString);
                    WxStatusBar1->SetStatusText("Selected,  "+WxListBox1->GetStringSelection()+" ("+ fileSizeString+")", 1);
                }
                else
                {
                    wxMessageBox("Failed to open the file.", "Error", wxICON_ERROR | wxOK);
                }
            }
            else
            {
                wxMessageBox("File not found.", "Error", wxICON_ERROR | wxOK);
            }
        }
        else
        {
            wxMessageBox("Please enter a file path.", "Error", wxICON_ERROR | wxOK);
        }
            
     
            if(WxComboBox2->GetValue()=="Administrator"){////////administrator
            
                std::ifstream lineNum("Data\\Resources\\klbsoft.temp\\data_config.txt");

                if (lineNum.is_open()) {
                    std::string lineData;
                    for (int i = 0; i < 4 && getline(lineNum, lineData); i++) {
                        if (i == 0) {
                        } else if (i == 1) {
                            WxStaticText20->SetLabel(lineData);
                        } else if (i == 2) {
                            WxStaticText21->SetLabel(lineData);
                        } else if (i == 3) {
                            WxStaticText6->SetLabel(lineData);
                        }
                    }
                    lineNum.close();
                }
                
                if(WxStaticText6->GetLabel()=="cpa"){
                   if(WxCheckBox1->IsChecked()){
                       ShellExecuteA(NULL, "runas",_T("Data\\Resources\\klbsoft.temp\\"+WxStaticText21->GetLabel()), NULL, NULL, SW_SHOWNORMAL); 
                   }else{
                        ShellExecuteA(NULL, "runas",_T("Data\\Resources\\klbsoft.temp\\"+WxStaticText20->GetLabel()), NULL, NULL, SW_SHOWNORMAL);}
                }else if(WxStaticText6->GetLabel()=="combine"){
                   if(WxCheckBox1->IsChecked()){
                       ShellExecuteA(NULL, "runas",_T("Data\\Resources\\klbsoft.temp\\"+WxStaticText21->GetLabel()), NULL, NULL, SW_SHOWNORMAL); 
                   }else{
                        ShellExecuteA(NULL, "runas",_T("Data\\Resources\\klbsoft.temp\\"+WxStaticText20->GetLabel()), NULL, NULL, SW_SHOWNORMAL);
                   }
                }else if(WxStaticText6->GetLabel()=="32bit"){
                   if(WxCheckBox1->IsChecked()){
                         wxMessageBox("'"+WxListBox1->GetStringSelection()+"' is not compatible with the version of Windows you're running.","Error",wxICON_ERROR|wxOK);
                   }else{
                        ShellExecuteA(NULL, "runas",_T("Data\\Resources\\klbsoft.temp\\"+WxStaticText20->GetLabel()), NULL, NULL, SW_SHOWNORMAL);
                   }
                }else if(WxStaticText6->GetLabel()=="64bit"){
                    if (WxCheckBox1->IsChecked()) {
                        ShellExecuteA(NULL, "runas",_T("Data\\Resources\\klbsoft.temp\\"+WxStaticText21->GetLabel()), NULL, NULL, SW_SHOWNORMAL);
                    } else {
                        wxMessageBox(wxString::Format("'%s' doesn't have a 32-bit version.", WxListBox1->GetStringSelection()), "Error", wxICON_ERROR | wxOK);
                    }
                }
                WxStaticText14->SetLabel("onRun");
                 
            }else{ //////////if not administrator
            
                 std::ifstream lineNum("Data\\Resources\\klbsoft.temp\\data_config.txt");

                if (lineNum.is_open()) {
                    std::string lineData;
                    for (int i = 0; i < 4 && getline(lineNum, lineData); i++) {
                        if (i == 0) {
                        } else if (i == 1) {
                            WxStaticText20->SetLabel(lineData);
                        } else if (i == 2) {
                            WxStaticText21->SetLabel(lineData);
                        } else if (i == 3) {
                            WxStaticText6->SetLabel(lineData);
                        }
                    }
                    lineNum.close();
                }
                
                if(WxStaticText6->GetLabel()=="cpa"){
                   if(WxCheckBox1->IsChecked()){
                       wxString filePath = wxString::Format(_T("Data\\Resources\\klbsoft.temp\\%s"), WxStaticText21->GetLabel());
                        ShellExecute(NULL, _T("open"), filePath.c_str(), NULL, NULL, SW_SHOWNORMAL);
                   }else{
                        wxString filePath = wxString::Format(_T("Data\\Resources\\klbsoft.temp\\%s"), WxStaticText20->GetLabel());
                        ShellExecute(NULL, _T("open"), filePath.c_str(), NULL, NULL, SW_SHOWNORMAL);
                        //ShellExecuteA(GetDesktopWindow(), "open","C:\\Windows\\klbsoft.temp\\"+WxStaticText20->GetLabel(), NULL, NULL, SW_SHOWNORMAL);                        
                   }
                }else if(WxStaticText6->GetLabel()=="combine"){
                   if(WxCheckBox1->IsChecked()){
                       wxString filePath = wxString::Format(_T("Data\\Resources\\klbsoft.temp\\%s"), WxStaticText21->GetLabel());
                       ShellExecute(NULL, _T("open"), filePath.c_str(), NULL, NULL, SW_SHOWNORMAL);
                   }else{
                        wxString filePath = wxString::Format(_T("Data\\Resources\\klbsoft.temp\\%s"), WxStaticText20->GetLabel());
                        ShellExecute(NULL, _T("open"), filePath.c_str(), NULL, NULL, SW_SHOWNORMAL);
                    }
                }else if(WxStaticText6->GetLabel()=="32bit"){
                   if(WxCheckBox1->IsChecked()){
                        wxMessageBox("'"+WxListBox1->GetStringSelection()+"' is not compatible with the version of Windows you're running.","Error",wxICON_ERROR|wxOK);
                   }else{
                         wxString filePath = wxString::Format(_T("Data\\Resources\\klbsoft.temp\\%s"), WxStaticText20->GetLabel());
                        ShellExecute(NULL, _T("open"), filePath.c_str(), NULL, NULL, SW_SHOWNORMAL);
                  }
                }else if(WxStaticText6->GetLabel()=="64bit"){
                    if (WxCheckBox1->IsChecked()) {
                        wxString filePath = wxString::Format(_T("Data\\Resources\\klbsoft.temp\\%s"), WxStaticText21->GetLabel());
                        ShellExecute(NULL, _T("open"), filePath.c_str(), NULL, NULL, SW_SHOWNORMAL);
                    } else {
                        wxMessageBox("'"+WxListBox1->GetStringSelection()+"' is not compatible with the version of Windows you're running.","Error",wxICON_ERROR|wxOK);
                    }
                }
                WxStaticText14->SetLabel("onRun");
            } 
             
        }else{
            WxGauge1->Show();
            int counter= 1000;
            counter++;
            WxGauge1->SetValue(counter % (WxGauge1->GetRange()+ 1)); 
        } 
    }else{
    }
	// insert your code here
}

/*
 * WxTimer2Timer
 */
void KLBTOOLSFrm::WxTimer2Timer(wxTimerEvent& event)
{
   
    wxString filePath = "Data\\Resources\\klbsoft.temp\\.tmp$MenuFile";
    if (wxFileName::FileExists(filePath)){
        WxTimer2->Stop();
        
        string txtsEXE;
        ifstream sEXE("Data\\Resources\\klbsoft.temp\\tmpSettings.txt");
        for (int i = 0; i < 2 ; i++){   
        getline(sEXE , txtsEXE);}   
        WxStaticText18->SetLabel(txtsEXE);


        WxComboBox1->Clear();
        wxArrayString dirList;
        wxDirectoriesEnumerator traverser(&dirList);
        wxDir dir("Data\\Programs\\");
        if(dir.IsOpened()){
        dir.Traverse(traverser);
        for(unsigned int i=0; i<dirList.GetCount(); i++) {
        WxComboBox1->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
        WxComboBox1->SetStringSelection(WxStaticText18->GetLabel());
        }};
        
        WxListBox1->Clear();
        wxArrayString dirList2;
        wxDirectoriesEnumerator traverser2(&dirList2);
        wxDir fils("Data\\Programs\\"+WxComboBox1->GetValue()+"\\");
        if(fils.IsOpened()){
        fils.Traverse(traverser2);
        for(unsigned int i=0; i<dirList2.GetCount(); i++) {
        WxListBox1->Append(dirList2.Item(i).AfterLast('\\').AfterLast('/').BeforeLast('.'));
        }};
        
    }else{ 
    } 
    
	// insert your code here
}

/*
 * WxEdit1Updated
 */
void KLBTOOLSFrm::WxEdit1Updated(wxCommandEvent& event)
{
    //WxStaticText22->SetLabel(" Tools Size: 0 KB");
    wxString searchText = WxEdit1->GetValue();
    wxString folderPath = "Data\\Programs\\"+WxComboBox1->GetValue()+"\\"; 

    WxListBox1->Clear();
    wxDir dir(folderPath);
    wxString filename;

    if (dir.IsOpened()) {
        bool cont = dir.GetFirst(&filename, wxEmptyString, wxDIR_FILES);
        while (cont) {
            if (filename.Lower().Contains(searchText.Lower())) {
                wxFileName wxFile(folderPath + filename);
                wxString baseName = wxFile.GetName();
                WxListBox1->Append(baseName);
            }
            cont = dir.GetNext(&filename);
        }
    }

    if (searchText.IsEmpty()) {
        int itemCount = WxListBox1->GetCount();
        wxString CountStr = wxString::Format(" %d", itemCount);
        WxStaticText11->SetLabel(CountStr);
    } else {
        int sCount = WxListBox1->GetCount();
        WxStaticText11->SetLabel(wxString::Format(" %d out of "+WxStaticText15->GetLabel()+" Matches Found.", sCount));
    }
}

/*
 * WxButton3Click1
 */
void KLBTOOLSFrm::WxButton3Click1(wxCommandEvent& event)
{
    AddInfoDlg *import = new  AddInfoDlg(this);
    import->WxStaticText1->SetLabel(WxComboBox1->GetStringSelection());
    import->WxStaticText2->SetLabel(WxListBox1->GetStringSelection());
    import->ShowModal();
	// insert your code here
}
