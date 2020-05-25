/***************************************************************
 * Name:      wx_Hello_WorldMain.h
 * Purpose:   Defines Application Frame
 * Author:    Oliver Krüger (OK@oliver-krueger.de)
 * Created:   2019-01-09
 * Copyright: Oliver Krüger (www.oliver-krueger.de)
 * License:
 **************************************************************/

#ifndef WX_HELLO_WORLDMAIN_H
#define WX_HELLO_WORLDMAIN_H

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "wx_Hello_WorldApp.h"


#include <wx/button.h>
#include <wx/statline.h>
class wx_Hello_WorldDialog: public wxDialog
{
    public:
        wx_Hello_WorldDialog(wxDialog *dlg, const wxString& title);
        ~wx_Hello_WorldDialog();

    protected:
        enum
        {
            idBtnQuit = 1000,
            idBtnAbout
        };
        wxStaticText* m_staticText1;
        wxButton* BtnAbout;
        wxStaticLine* m_staticline1;
        wxButton* BtnQuit;

    private:
        void OnClose(wxCloseEvent& event);
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        DECLARE_EVENT_TABLE()
};

#endif // WX_HELLO_WORLDMAIN_H
