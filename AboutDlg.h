///-----------------------------------------------------------------
///
/// @file      AboutDlg.h
/// @author    KLBSoft.
/// Created:   12/21/2021 7:43:10 AM
/// @section   DESCRIPTION
///            AboutDlg class declaration
///
///------------------------------------------------------------------

#ifndef __ABOUTDLG_H__
#define __ABOUTDLG_H__

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
#include <wx/statbmp.h>
#include <wx/button.h>
#include <wx/hyperlink.h>
#include <wx/panel.h>
////Header Include End

////Dialog Style Start
#undef AboutDlg_STYLE
#define AboutDlg_STYLE wxCAPTION | wxSYSTEM_MENU | wxDIALOG_NO_PARENT | wxCLOSE_BOX
////Dialog Style End

class AboutDlg : public wxDialog
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		void WxButton1Click(wxCommandEvent& event);
		AboutDlg(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("AboutDlg"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = AboutDlg_STYLE);
		virtual ~AboutDlg();
		void WxHyperLinkCtrl1HyperLink(wxHyperlinkEvent& event);
	
	private:
		//Do not add custom control declarations between 
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxStaticText *WxStaticText4;
		wxStaticText *WxStaticText2;
		wxStaticText *WxStaticText1;
		wxStaticBitmap *WxStaticBitmap1;
		wxButton *WxButton1;
		wxHyperlinkCtrl *WxHyperLinkCtrl1;
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
			ID_WXSTATICTEXT4 = 1009,
			ID_WXSTATICTEXT2 = 1003,
			ID_WXSTATICTEXT1 = 1002,
			ID_WXSTATICBITMAP1 = 1008,
			ID_WXBUTTON1 = 1007,
			ID_WXHYPERLINKCTRL1 = 1006,
			ID_WXPANEL1 = 1004,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
	
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
};

#endif
