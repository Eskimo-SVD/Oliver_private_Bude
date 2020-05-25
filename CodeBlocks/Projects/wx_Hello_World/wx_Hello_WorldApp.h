/***************************************************************
 * Name:      wx_Hello_WorldApp.h
 * Purpose:   Defines Application Class
 * Author:    Oliver Krüger (OK@oliver-krueger.de)
 * Created:   2019-01-09
 * Copyright: Oliver Krüger (www.oliver-krueger.de)
 * License:
 **************************************************************/

#ifndef WX_HELLO_WORLDAPP_H
#define WX_HELLO_WORLDAPP_H

#include <wx/app.h>

class wx_Hello_WorldApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // WX_HELLO_WORLDAPP_H
