//---------------------------------------------------------------------------
//
// Name:        KLBTOOLSApp.cpp
// Author:      KLBTech
// Created:     3/11/2021 7:09:37 AM
// Description: 
//
//---------------------------------------------------------------------------

#include "KLBTOOLSApp.h"
#include "KLBTOOLSFrm.h"


IMPLEMENT_APP(KLBTOOLSFrmApp)

bool KLBTOOLSFrmApp::OnInit()
{
    KLBTOOLSFrm* frame = new KLBTOOLSFrm(NULL);
    SetTopWindow(frame);
    frame->Show();
    return true;
}
 
int KLBTOOLSFrmApp::OnExit()
{
	return 0;
}
