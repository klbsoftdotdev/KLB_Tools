///-----------------------------------------------------------------
///
/// @file      ImportDlg.h
/// @author    KLBTech
/// Created:   3/11/2021 7:57:11 PM
/// @section   DESCRIPTION
///            ImportDlg class declaration
///
///------------------------------------------------------------------

#ifndef __IMPORTDLG_H__
#define __IMPORTDLG_H__

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
#include <wx/filedlg.h>
#include <wx/dirdlg.h>
#include <wx/stattext.h>
#include <wx/gauge.h>
#include <wx/listbox.h>
#include <wx/combobox.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/statbox.h>
#include <wx/panel.h>
////Header Include End

////Dialog Style Start
#undef ImportDlg_STYLE
#define ImportDlg_STYLE wxCAPTION | wxSYSTEM_MENU | wxDIALOG_NO_PARENT | wxCLOSE_BOX
////Dialog Style End

class ImportDlg : public wxDialog
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		ImportDlg(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("ImportDlg"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = ImportDlg_STYLE);
		virtual ~ImportDlg();
		void WxButton3Click(wxCommandEvent& event);
		void WxButton2Click(wxCommandEvent& event);
		void WxButton1Click(wxCommandEvent& event);
		void ImportDlgActivate(wxActivateEvent& event);
		void WxCheckBox1Click(wxCommandEvent& event);
		void WxButton4Click(wxCommandEvent& event);
		void WxButton5Click(wxCommandEvent& event);
		void WxRadioButton1Click(wxCommandEvent& event);
		void WxRadioButton2Click(wxCommandEvent& event);
		void WxCheckBox1Click0(wxCommandEvent& event);
		void WxCheckBox2Click(wxCommandEvent& event);
		void WxButton6Click(wxCommandEvent& event);
		void WxButton7Click(wxCommandEvent& event);
		void WxEdit5Enter(wxCommandEvent& event);
		void WxEdit3Updated(wxCommandEvent& event);
		void WxButton7Click0(wxCommandEvent& event);
		void WxEdit3Enter(wxCommandEvent& event);
		void WxButton4Click0(wxCommandEvent& event);
		void WxButton5Click0(wxCommandEvent& event);
		void WxButton6Click0(wxCommandEvent& event);
		void WxListBox1Selected(wxCommandEvent& event);
		void WxPanel1UpdateUI(wxUpdateUIEvent& event);
	
	public:
		//Do not add custom control declarations between 
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxStaticText *WxStaticText3;
		wxTimer *WxTimer1;
		wxFileDialog *WxOpenFileDialog1;
		wxDirDialog *WxDirDialog1;
		wxStaticText *WxStaticText14;
		wxStaticText *WxStaticText13;
		wxStaticText *WxStaticText12;
		wxStaticText *WxStaticText11;
		wxStaticText *WxStaticText10;
		wxStaticText *WxStaticText9;
		wxStaticText *WxStaticText8;
		wxStaticText *WxStaticText5;
		wxStaticText *WxStaticText4;
		wxStaticText *WxStaticText2;
		wxStaticText *WxStaticText1;
		wxGauge *WxGauge1;
		wxButton *WxButton7;
		wxButton *WxButton5;
		wxTextCtrl *WxEdit2;
		wxListBox *WxListBox1;
		wxButton *WxButton4;
		wxTextCtrl *WxEdit1;
		wxComboBox *WxComboBox2;
		wxStaticBox *WxStaticBox1;
		wxTextCtrl *WxEdit5;
		wxStaticBox *WxStaticBox4;
		wxComboBox *WxComboBox1;
		wxStaticBox *WxStaticBox3;
		wxTextCtrl *WxEdit4;
		wxButton *WxButton1;
		wxButton *WxButton3;
		wxButton *WxButton2;
		wxStaticBox *WxStaticBox2;
		wxPanel *WxPanel1;
		////GUI Control Declaration End
		void WxComboBox2Selected(wxCommandEvent& event );
		void WxCheckBox3Click(wxCommandEvent& event);
		void WxTimer1Timer(wxTimerEvent& event);
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_WXSTATICTEXT3 = 1086,
			ID_WXTIMER1 = 1085,
			ID_WXSTATICTEXT14 = 1065,
			ID_WXSTATICTEXT13 = 1062,
			ID_WXSTATICTEXT12 = 1061,
			ID_WXSTATICTEXT11 = 1034,
			ID_WXSTATICTEXT10 = 1033,
			ID_WXSTATICTEXT9 = 1032,
			ID_WXSTATICTEXT8 = 1030,
			ID_WXSTATICTEXT5 = 1021,
			ID_WXSTATICTEXT4 = 1020,
			ID_WXSTATICTEXT2 = 1014,
			ID_WXSTATICTEXT1 = 1013,
			ID_WXGAUGE1 = 1084,
			ID_WXBUTTON7 = 1083,
			ID_WXBUTTON5 = 1078,
			ID_WXEDIT2 = 1077,
			ID_WXLISTBOX1 = 1076,
			ID_WXBUTTON4 = 1073,
			ID_WXEDIT1 = 1072,
			ID_WXCOMBOBOX2 = 1071,
			ID_WXSTATICBOX1 = 1070,
			ID_WXEDIT5 = 1042,
			ID_WXSTATICBOX4 = 1041,
			ID_WXCOMBOBOX1 = 1040,
			ID_WXSTATICBOX3 = 1039,
			ID_WXEDIT4 = 1035,
			ID_WXBUTTON1 = 1011,
			ID_WXBUTTON3 = 1010,
			ID_WXBUTTON2 = 1009,
			ID_WXSTATICBOX2 = 1004,
			ID_WXPANEL1 = 1002,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
	
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
};

#endif
