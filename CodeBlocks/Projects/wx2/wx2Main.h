/***************************************************************
 * Name:      wx2Main.h
 * Purpose:   Defines Application Frame
 * Author:    Oliver Krüger (OK@oliver-krueger.de)
 * Created:   2019-01-10
 * Copyright: Oliver Krüger (www.oliver-krueger.de)
 * License:
 **************************************************************/

#ifndef WX2MAIN_H
#define WX2MAIN_H

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "wx2App.h"


#include <wx/button.h>
#include <wx/statline.h>
class wx2Dialog: public wxDialog
{
    public:
        wx2Dialog(wxDialog *dlg, const wxString& title);
        ~wx2Dialog();

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

#endif // WX2MAIN_H
