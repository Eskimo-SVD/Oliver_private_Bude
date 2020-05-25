/***************************************************************
 * Name:      wx_Hello_WorldApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Oliver Krüger (OK@oliver-krueger.de)
 * Created:   2019-01-09
 * Copyright: Oliver Krüger (www.oliver-krueger.de)
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "wx_Hello_WorldApp.h"
#include "wx_Hello_WorldMain.h"

IMPLEMENT_APP(wx_Hello_WorldApp);

bool wx_Hello_WorldApp::OnInit()
{
    
    wx_Hello_WorldDialog* dlg = new wx_Hello_WorldDialog(0L, _("wxWidgets Application Template"));
    dlg->SetIcon(wxICON(aaaa)); // To Set App Icon
    dlg->Show();
    return true;
}
