///-----------------------------------------------------------------
///
/// @file      AddInfoDlg.h
/// @author    KLBTech
/// Created:   3/12/2021 3:56:13 AM
/// @section   DESCRIPTION
///            AddInfoDlg class declaration
///
///------------------------------------------------------------------

#ifndef __ADDINFODLG_H__
#define __ADDINFODLG_H__

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
#include <wx/stattext.h>
#include <wx/listbox.h>
#include <wx/combobox.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/statbox.h>
#include <wx/panel.h>
////Header Include End

////Dialog Style Start
#undef AddInfoDlg_STYLE
#define AddInfoDlg_STYLE wxCAPTION | wxSYSTEM_MENU | wxDIALOG_NO_PARENT | wxCLOSE_BOX
////Dialog Style End

class AddInfoDlg : public wxDialog
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		AddInfoDlg(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("AddInfoDlg"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = AddInfoDlg_STYLE);
		virtual ~AddInfoDlg();
		void WxButton1Click(wxCommandEvent& event);
	
	public:
		//Do not add custom control declarations between 
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxStaticText *WxStaticText2;
		wxStaticText *WxStaticText1;
		wxButton *WxButton3;
		wxButton *WxButton2;
		wxListBox *WxListBox1;
		wxComboBox *WxComboBox1;
		wxTextCtrl *WxEdit1;
		wxButton *WxButton1;
		wxStaticBox *WxStaticBox2;
		wxStaticBox *WxStaticBox1;
		wxPanel *WxPanel1;
		////GUI Control Declaration End
		void WxPanel1UpdateUI(wxUpdateUIEvent& event);
		void AddInfoDlgActivate(wxActivateEvent& event);
		void WxButton2Click(wxCommandEvent& event);
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_WXSTATICTEXT2 = 1011,
			ID_WXSTATICTEXT1 = 1010,
			ID_WXBUTTON3 = 1009,
			ID_WXBUTTON2 = 1008,
			ID_WXLISTBOX1 = 1007,
			ID_WXCOMBOBOX1 = 1006,
			ID_WXEDIT1 = 1005,
			ID_WXBUTTON1 = 1004,
			ID_WXSTATICBOX2 = 1003,
			ID_WXSTATICBOX1 = 1002,
			ID_WXPANEL1 = 1001,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
	
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
};

#endif
