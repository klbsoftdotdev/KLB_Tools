///-----------------------------------------------------------------
///
/// @file      KLBTOOLSFrm.h
/// @author    KLBTech
/// Created:   3/11/2021 7:09:38 AM
/// @section   DESCRIPTION
///            KLBTOOLSFrm class declaration
///
///------------------------------------------------------------------

#ifndef __KLBTOOLSFRM_H__
#define __KLBTOOLSFRM_H__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/frame.h>
#else
	#include <wx/wxprec.h>
#endif

//Do not add custom headers between 
//Header Include Start and Header Include End.
//wxDev-C++ designer will remove them. Add custom headers after the block.
////Header Include Start
#include <wx/menu.h>
#include <wx/timer.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/gauge.h>
#include <wx/listbox.h>
#include <wx/button.h>
#include <wx/combobox.h>
#include <wx/statbox.h>
#include <wx/stattext.h>
#include <wx/panel.h>
////Header Include End

////Dialog Style Start
#undef KLBTOOLSFrm_STYLE
#define KLBTOOLSFrm_STYLE wxCAPTION | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class KLBTOOLSFrm : public wxFrame
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		KLBTOOLSFrm(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("KLBTOOLS"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = KLBTOOLSFrm_STYLE);
		virtual ~KLBTOOLSFrm();
		void Mnuabout1008Click(wxCommandEvent& event);
		void KLBTOOLSFrmActivate(wxActivateEvent& event);
		void Mnuimporttools1003Click(wxCommandEvent& event);
		void WxComboBox1Selected(wxCommandEvent& event );
		void WxListBox1Selected(wxCommandEvent& event);
		void WxButton1Click(wxCommandEvent& event);
		void WxButton2Click(wxCommandEvent& event);
		void Mnuinfosettings1018Click(wxCommandEvent& event);
		void Mnuedittools1005Click(wxCommandEvent& event);
		void Mnuaddcategory1006Click(wxCommandEvent& event);
		void WxComboBox2Selected(wxCommandEvent& event );
		void Mnuexit1021Click(wxCommandEvent& event);
		void Mnuexit1026Click(wxCommandEvent& event);
		void Mnuexit1022Click(wxCommandEvent& event);
		void WxButton3Click(wxCommandEvent& event);
		void Mnuimporttoolsconfig1036Click(wxCommandEvent& event);
		void Mnuexporttoolsconfig1037Click(wxCommandEvent& event);
		void Mnudonation1041Click(wxCommandEvent& event);
		void Mnuexit1039Click(wxCommandEvent& event);
		void WxListBox1Selected0(wxCommandEvent& event);
		void WxComboBox1Selected0(wxCommandEvent& event );
		void Mnuexit1039Click0(wxCommandEvent& event);
		void WxButton3Click0(wxCommandEvent& event);
		void Mnureadme1072Click(wxCommandEvent& event);
		void Mnuabout1008Click0(wxCommandEvent& event);
		void Mnuviewliscenseagreement1094Click(wxCommandEvent& event);
		void Mnuuserlogs1096Click(wxCommandEvent& event);
		void WxListBox1UpdateUI(wxUpdateUIEvent& event);
		void WxTimer1Timer(wxTimerEvent& event);
		void WxTimer2Timer(wxTimerEvent& event);
		void WxEdit1Updated(wxCommandEvent& event);
		void WxButton3Click1(wxCommandEvent& event);
		
		
	private:
		//Do not add custom control declarations between
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxMenuBar *WxMenuBar1;
		wxTimer *WxTimer2;
		wxTimer *WxTimer1;
		wxStatusBar *WxStatusBar1;
		wxStaticText *WxStaticText12;
		wxStaticText *WxStaticText11;
		wxTextCtrl *WxEdit1;
		wxCheckBox *WxCheckBox1;
		wxStaticText *WxStaticText10;
		wxStaticText *WxStaticText14;
		wxStaticText *WxStaticText9;
		wxStaticText *WxStaticText2;
		wxStaticText *WxStaticText6;
		wxStaticText *WxStaticText1;
		wxStaticText *WxStaticText21;
		wxStaticText *WxStaticText20;
		wxStaticText *WxStaticText19;
		wxStaticText *WxStaticText18;
		wxComboBox *WxComboBox3;
		wxStaticText *WxStaticText17;
		wxStaticText *WxStaticText16;
		wxGauge *WxGauge1;
		wxStaticText *WxStaticText15;
		wxStaticText *WxStaticText8;
		wxListBox *WxListBox1;
		wxButton *WxButton1;
		wxButton *WxButton2;
		wxComboBox *WxComboBox2;
		wxStaticBox *WxStaticBox1;
		wxComboBox *WxComboBox1;
		wxStaticBox *WxStaticBox4;
		wxStaticText *WxStaticText5;
		wxStaticText *WxStaticText4;
		wxStaticText *WxStaticText3;
		wxStaticBox *WxStaticBox2;
		wxStaticText *WxStaticText7;
		wxPanel *WxPanel1;
		////GUI Control Declaration End
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_MNU_FILE_1002 = 1002,
			ID_MNU_IMPORTTOOLS_1003 = 1003,
			ID_MNU_EXIT_1039 = 1039,
			ID_MNU_SETTINGS_1004 = 1004,
			ID_MNU_EDITTOOLS_1005 = 1005,
			ID_MNU_ADDCATEGORY_1006 = 1006,
			ID_MNU_INFO_SETTINGS_1018 = 1018,
			ID_MNU_HELP_1007 = 1007,
			ID_MNU_README_1072 = 1072,
			ID_MNU_ABOUT_1008 = 1008,
			
			ID_WXTIMER2 = 1103,
			ID_WXTIMER1 = 1102,
			ID_WXSTATUSBAR1 = 1118,
			ID_WXSTATICTEXT12 = 1123,
			ID_WXSTATICTEXT11 = 1120,
			ID_WXEDIT1 = 1119,
			ID_WXCHECKBOX1 = 1117,
			ID_WXSTATICTEXT10 = 1116,
			ID_WXSTATICTEXT14 = 1115,
			ID_WXSTATICTEXT9 = 1114,
			ID_WXSTATICTEXT2 = 1113,
			ID_WXSTATICTEXT6 = 1111,
			ID_WXSTATICTEXT1 = 1110,
			ID_WXSTATICTEXT21 = 1109,
			ID_WXSTATICTEXT20 = 1108,
			ID_WXSTATICTEXT19 = 1107,
			ID_WXSTATICTEXT18 = 1106,
			ID_WXCOMBOBOX3 = 1105,
			ID_WXSTATICTEXT17 = 1104,
			ID_WXSTATICTEXT16 = 1101,
			ID_WXGAUGE1 = 1100,
			ID_WXSTATICTEXT15 = 1099,
			ID_WXSTATICTEXT8 = 1062,
			ID_WXLISTBOX1 = 1060,
			ID_WXBUTTON1 = 1055,
			ID_WXBUTTON2 = 1054,
			ID_WXCOMBOBOX2 = 1053,
			ID_WXSTATICBOX1 = 1051,
			ID_WXCOMBOBOX1 = 1050,
			ID_WXSTATICBOX4 = 1034,
			ID_WXSTATICTEXT5 = 1033,
			ID_WXSTATICTEXT4 = 1032,
			ID_WXSTATICTEXT3 = 1031,
			ID_WXSTATICBOX2 = 1010,
			ID_WXSTATICTEXT7 = 1065,
			ID_WXPANEL1 = 1001,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
		
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
};

#endif
