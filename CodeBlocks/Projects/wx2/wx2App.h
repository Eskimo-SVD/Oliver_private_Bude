/***************************************************************
 * Name:      wx2App.h
 * Purpose:   Defines Application Class
 * Author:    Oliver Krüger (OK@oliver-krueger.de)
 * Created:   2019-01-10
 * Copyright: Oliver Krüger (www.oliver-krueger.de)
 * License:
 **************************************************************/

#ifndef WX2APP_H
#define WX2APP_H

#include <wx/app.h>

class wx2App : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // WX2APP_H
