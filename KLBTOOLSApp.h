//---------------------------------------------------------------------------
//
// Name:        KLBTOOLSApp.h
// Author:      KLBTech
// Created:     3/11/2021 7:09:37 AM
// Description: 
//
//---------------------------------------------------------------------------

#ifndef __KLBTOOLSFRMApp_h__
#define __KLBTOOLSFRMApp_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#else
	#include <wx/wxprec.h>
#endif

class KLBTOOLSFrmApp : public wxApp
{
	public:
		bool OnInit();
		int OnExit();
};

#endif
