///-----------------------------------------------------------------
///
/// @file      ReadInfoDlg.h
/// @author    KLBTech
/// Created:   3/13/2021 6:04:32 AM
/// @section   DESCRIPTION
///            ReadInfoDlg class declaration
///
///------------------------------------------------------------------

#ifndef __READINFODLG_H__
#define __READINFODLG_H__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/dialog.h>
#else
	#include <wx/wxprec.h>
#endif

//Do not add custom headers between 
//Header Include Start and Header Include End.
//wxDev-C++ designer will remove them. Add custom headers after the block.
////Header Include Start
#include <wx/timer.h>
#include <wx/gauge.h>
#include <wx/checkbox.h>
#include <wx/combobox.h>
#include <wx/listbox.h>
#include <wx/button.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/statbox.h>
#include <wx/notebook.h>
#include <wx/panel.h>
////Header Include End

////Dialog Style Start
#undef ReadInfoDlg_STYLE
#define ReadInfoDlg_STYLE wxCAPTION | wxSYSTEM_MENU | wxDIALOG_NO_PARENT | wxCLOSE_BOX
////Dialog Style End

class ReadInfoDlg : public wxDialog
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		ReadInfoDlg(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("ReadInfoDlg"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = ReadInfoDlg_STYLE);
		virtual ~ReadInfoDlg();
	
	public:
		//Do not add custom control declarations between 
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxStaticText *WxStaticText16;
		wxTimer *WxTimer1;
		wxStaticText *WxStaticText12;
		wxStaticText *WxStaticText11;
		wxStaticText *WxStaticText10;
		wxStaticText *WxStaticText9;
		wxStaticText *WxStaticText6;
		wxStaticText *WxStaticText4;
		wxStaticText *WxStaticText1;
		wxStaticText *WxStaticText2;
		wxStaticText *WxStaticText3;
		wxStaticText *WxStaticText14;
		wxStaticText *WxStaticText15;
		wxGauge *WxGauge1;
		wxStaticText *WxStaticText13;
		wxStaticText *WxStaticText5;
		wxButton *WxButton10;
		wxTextCtrl *WxEdit2;
		wxTextCtrl *WxEdit1;
		wxComboBox *WxComboBox2;
		wxComboBox *WxComboBox1;
		wxButton *WxButton2;
		wxButton *WxButton1;
		wxPanel *WxNoteBookPage3;
		wxListBox *WxListBox1;
		wxStaticBox *WxStaticBox5;
		wxComboBox *WxComboBox3;
		wxStaticBox *WxStaticBox4;
		wxCheckBox *WxCheckBox1;
		wxStaticText *WxStaticText8;
		wxComboBox *WxComboBox4;
		wxTextCtrl *WxEdit3;
		wxStaticBox *WxStaticBox2;
		wxButton *WxButton5;
		wxButton *WxButton4;
		wxButton *WxButton3;
		wxPanel *WxNoteBookPage2;
		wxListBox *WxListBox2;
		wxStaticBox *WxStaticBox6;
		wxButton *WxButton8;
		wxButton *WxButton7;
		wxButton *WxButton6;
		wxStaticText *WxStaticText7;
		wxTextCtrl *WxEdit4;
		wxStaticBox *WxStaticBox3;
		wxPanel *WxNoteBookPage1;
		wxNotebook *WxNotebook1;
		wxPanel *WxPanel1;
		////GUI Control Declaration End
		void WxComboBox1Selected(wxCommandEvent& event );
		void WxComboBox2Selected(wxCommandEvent& event );
		void ReadInfoDlgActivate(wxActivateEvent& event);
		void WxButton2Click(wxCommandEvent& event);
		void WxButton1Click(wxCommandEvent& event);
		void WxEdit2Enter(wxCommandEvent& event);
		void WxEdit2Updated(wxCommandEvent& event);
		void WxListBox1Selected(wxCommandEvent& event);
		void WxComboBox3Selected(wxCommandEvent& event );
		void WxButton5Click(wxCommandEvent& event);
		void WxButton3Click(wxCommandEvent& event);
		void WxListBox2Selected(wxCommandEvent& event);
		void WxButton6Click(wxCommandEvent& event);
		void WxButton8Click(wxCommandEvent& event);
		void WxButton7Click(wxCommandEvent& event);
		void WxNotebook1PageChanging(wxNotebookEvent& event);
		void WxCheckBox1Click(wxCommandEvent& event);
		void WxButton4Click(wxCommandEvent& event);
		void WxNotebook1PageChanged(wxNotebookEvent& event);
		void WxEdit1Updated(wxCommandEvent& event);
		void WxPanel1UpdateUI(wxUpdateUIEvent& event);
		void WxCheckBox2Click(wxCommandEvent& event);
		void WxEdit1Updated0(wxCommandEvent& event);
		void WxComboBox2Selected0(wxCommandEvent& event );
		void WxComboBox2Updated(wxCommandEvent& event );
		void WxButton9Click(wxCommandEvent& event);
		void WxTimer1Timer(wxTimerEvent& event);
		void WxButton10Click(wxCommandEvent& event);
		void WxButton9Click0(wxCommandEvent& event);
		void WxComboBox2Selected1(wxCommandEvent& event );
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_WXSTATICTEXT16 = 1094,
			ID_WXTIMER1 = 1089,
			ID_WXSTATICTEXT12 = 1075,
			ID_WXSTATICTEXT11 = 1074,
			ID_WXSTATICTEXT10 = 1065,
			ID_WXSTATICTEXT9 = 1062,
			ID_WXSTATICTEXT6 = 1034,
			ID_WXSTATICTEXT4 = 1010,
			ID_WXSTATICTEXT1 = 1009,
			ID_WXSTATICTEXT2 = 1008,
			ID_WXSTATICTEXT3 = 1007,
			ID_WXSTATICTEXT14 = 1093,
			ID_WXSTATICTEXT15 = 1092,
			ID_WXGAUGE1 = 1084,
			ID_WXSTATICTEXT13 = 1088,
			ID_WXSTATICTEXT5 = 1087,
			ID_WXBUTTON10 = 1086,
			ID_WXEDIT2 = 1085,
			ID_WXEDIT1 = 1080,
			ID_WXCOMBOBOX2 = 1070,
			ID_WXCOMBOBOX1 = 1067,
			ID_WXBUTTON2 = 1025,
			ID_WXBUTTON1 = 1024,
			ID_WXNOTEBOOKPAGE3 = 1022,
			ID_WXLISTBOX1 = 1061,
			ID_WXSTATICBOX5 = 1060,
			ID_WXCOMBOBOX3 = 1059,
			ID_WXSTATICBOX4 = 1058,
			ID_WXCHECKBOX1 = 1057,
			ID_WXSTATICTEXT8 = 1048,
			ID_WXCOMBOBOX4 = 1047,
			ID_WXEDIT3 = 1044,
			ID_WXSTATICBOX2 = 1042,
			ID_WXBUTTON5 = 1039,
			ID_WXBUTTON4 = 1038,
			ID_WXBUTTON3 = 1037,
			ID_WXNOTEBOOKPAGE2 = 1014,
			ID_WXLISTBOX2 = 1064,
			ID_WXSTATICBOX6 = 1063,
			ID_WXBUTTON8 = 1056,
			ID_WXBUTTON7 = 1055,
			ID_WXBUTTON6 = 1054,
			ID_WXSTATICTEXT7 = 1053,
			ID_WXEDIT4 = 1051,
			ID_WXSTATICBOX3 = 1050,
			ID_WXNOTEBOOKPAGE1 = 1013,
			ID_WXNOTEBOOK1 = 1012,
			ID_WXPANEL1 = 1001,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
	
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
};

#endif
