///-----------------------------------------------------------------
///
/// @file      AboutDlg.cpp
/// @author    KLBSoft.
/// Created:   12/21/2021 7:43:10 AM
/// @section   DESCRIPTION
///            AboutDlg class implementation
///
///------------------------------------------------------------------

#include "AboutDlg.h"

//Do not add custom headers
//wxDev-C++ designer will remove them
////Header Include Start
#include "Images/AboutDlg_WxStaticBitmap1_XPM.xpm"
////Header Include End

//----------------------------------------------------------------------------
// AboutDlg
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(AboutDlg,wxDialog)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(AboutDlg::OnClose)
	EVT_BUTTON(ID_WXBUTTON1,AboutDlg::WxButton1Click)
	EVT_HYPERLINK(ID_WXHYPERLINKCTRL1,AboutDlg::WxHyperLinkCtrl1HyperLink)
END_EVENT_TABLE()
////Event Table End

AboutDlg::AboutDlg(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxDialog(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

AboutDlg::~AboutDlg()
{
} 

void AboutDlg::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End.
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	wxInitAllImageHandlers();   //Initialize graphic format handlers

	WxPanel1 = new wxPanel(this, ID_WXPANEL1, wxPoint(0, -1), wxSize(349, 129));

	WxHyperLinkCtrl1 = new wxHyperlinkCtrl(WxPanel1, ID_WXHYPERLINKCTRL1, _("http://www.klbsoft-358.com/"), _("http://wxdsgn.sf.net"), wxPoint(98, 54), wxSize(212, 17), wxNO_BORDER | wxHL_ALIGN_LEFT, _("WxHyperLinkCtrl1"));
	WxHyperLinkCtrl1->SetHoverColour(wxColour(0,0,160));
	WxHyperLinkCtrl1->SetNormalColour(wxColour(0,0,0));
	WxHyperLinkCtrl1->SetVisitedColour(wxColour(255,0,0));
	WxHyperLinkCtrl1->SetFont(wxFont(10, wxSWISS, wxNORMAL, wxNORMAL, true));

	WxButton1 = new wxButton(WxPanel1, ID_WXBUTTON1, _("OK"), wxPoint(256, 89), wxSize(75, 25), 0, wxDefaultValidator, _("WxButton1"));

	wxBitmap WxStaticBitmap1_BITMAP(AboutDlg_WxStaticBitmap1_XPM);
	WxStaticBitmap1 = new wxStaticBitmap(WxPanel1, ID_WXSTATICBITMAP1, WxStaticBitmap1_BITMAP, wxPoint(16, 12), wxSize(67, 62));

	WxStaticText1 = new wxStaticText(this, ID_WXSTATICTEXT1, _("KLB Tools Launcher v1.0"), wxPoint(98, 11), wxDefaultSize, 0, _("WxStaticText1"));

	WxStaticText2 = new wxStaticText(this, ID_WXSTATICTEXT2, _("(c) 2020-2021 KLBSoft. All Rights Reserved."), wxPoint(98, 32), wxDefaultSize, 0, _("WxStaticText2"));

	WxStaticText4 = new wxStaticText(this, ID_WXSTATICTEXT4, _("Donate @ GCash: 09552540757"), wxPoint(14, 97), wxDefaultSize, 0, _("WxStaticText4"));
	WxStaticText4->SetForegroundColour(wxColour(0,0,255));
	WxStaticText4->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxBOLD, false));

	SetTitle(_("KLB Tools Launcher"));
	SetIcon(wxNullIcon);
	SetSize(8,8,349,151);
	Center();
	
	////GUI Items Creation End
}

void AboutDlg::OnClose(wxCloseEvent& /*event*/)
{
	Destroy();
}

/*
 * WxButton1Click
 */
void AboutDlg::WxButton1Click(wxCommandEvent& event)
{
    Close();
	// insert your code here
}

/*
 * WxHyperLinkCtrl1HyperLink
 */
void AboutDlg::WxHyperLinkCtrl1HyperLink(wxHyperlinkEvent& event)
{
	// insert your code here
}
