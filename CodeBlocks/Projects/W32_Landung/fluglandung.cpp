#include <wx/wx.h>
#include "fluglandung.h"
#include "game.h"
#include "positionen.h"

IMPLEMENT_APP(fluglandungapp);

const int TIMERTICK=250;
const wxWindowID THROTTLE_ID=12;
const wxWindowID RUDER_ID=13;
const int TIMER_ID=1;

bool fluglandungapp::OnInit()
{
	fluglandungFrame *frame = new fluglandungFrame(
            wxT("Fluglandung"), wxPoint(50,50),
            wxSize(FensterBreite,FensterHoehe));
	frame->Show(TRUE);
	SetTopWindow(frame);
	return TRUE;
} 

fluglandungFrame::fluglandungFrame( const wxString& title, const wxPoint& pos, const wxSize& size )
	: wxFrame((wxFrame *)NULL, -1, title, pos, size)
    , timer(this, TIMER_ID)
{
    // ohne ein Panel gibt es keine Tastaturereignisse
    panel = new wxPanel(this, 5, wxPoint(pos), wxSize(size));

    Throttle = new wxSlider(panel, THROTTLE_ID,
               128, 0, 255, wxPoint(ThrottleX, SliderY),
               wxSize(20, SliderLaenge),
                            wxSL_VERTICAL|wxSL_AUTOTICKS);
    Ruder = new wxSlider(panel, RUDER_ID,
                128, 0, 255, wxPoint(RuderX, SliderY),
                wxSize(20, SliderLaenge),
                            wxSL_VERTICAL|wxSL_AUTOTICKS);

    Connect(wxEVT_TIMER,
            wxTimerEventHandler(fluglandungFrame::OnTimer));
    panel->Connect(wxEVT_PAINT,
            wxPaintEventHandler(fluglandungFrame::OnPaint),
            NULL,this);
    timer.Start(TIMERTICK);

}

void fluglandungFrame::OnQuit(wxCommandEvent&)
{
    Close(TRUE);
}

#include <string>
using namespace std;

void fluglandungFrame::OnPaint(wxPaintEvent& evt)
{
    wxPaintDC dc(panel);
    Game *game = Game::getInstance();
    BahnKoord bahn = game->getBahnKoord();
    wxPoint wxBahn[4];
    for(int i=0; i<4; i++) {
       wxBahn[i] = wxPoint(bahn.Bahn[i].x + XOffsetBahn,
                           bahn.Bahn[i].y);
    }
    dc.DrawPolygon(WXSIZEOF(wxBahn), wxBahn, 0,0);

    wxString str;
    dc.DrawText(wxT("Höhe"), HoeheX, InstrY1);
    str << game->getHoehe();
    dc.DrawText(str, HoeheX, InstrY2);
    dc.DrawText(wxT("Entf"), EntfX, InstrY1);
    str = wxT(""); str << game->getDistanz();
    dc.DrawText(str, EntfX, InstrY2);
    dc.DrawText(wxT("Geschw."), GeschwX, InstrY1);
    str = wxT(""); str << game->getGeschwindigkeit();
    dc.DrawText(str, GeschwX, InstrY2);

    dc.DrawText(wxT("Steig."), SteigX, InstrY1);
    str = wxT(""); str << long(game->getAnstieg()*100);
    dc.DrawText(str, SteigX, InstrY2);
}


void fluglandungFrame::OnTimer(wxTimerEvent& event)
{
    Game *game = Game::getInstance();
    game->setThrottle(255-Throttle->GetValue());
    game->setRuder(255-Ruder->GetValue());
    if (!game->naechsterTick()) {
        timer.Stop();
        tErfolg Erfolg = game->getErfolg();
        switch (Erfolg) {
        case Gelandet:
            wxMessageBox(
            wxT( "Bravo! Gelandet! Die Passagiere klatschen." ),
            wxT( "Spielende" ),
            wxOK | wxICON_INFORMATION, this );
            break;
        case Abgestuerzt:
            wxMessageBox(
            wxT( "Absturz vor der Landebahn!" ),
            wxT( "Spielende" ),
            wxOK | wxICON_INFORMATION, this );
            break;
        case Ueberflogen:
            wxMessageBox(
            wxT( "Oh, Landebahn überflogen!" ),
            wxT( "Spielende" ),
            wxOK | wxICON_INFORMATION, this );
            break;
        case Zuschnell:
            wxMessageBox(
            wxT( "Zu schnell! Das geht in den Acker!" ),
            wxT( "Spielende" ),
            wxOK | wxICON_INFORMATION, this );
            break;
        case Zusteil:
            wxMessageBox(
            wxT( "Zu steiler Sinkflug!"
                 " Mindestens das Fahrwerk ist im Eimer." ),
            wxT( "Spielende" ),
            wxOK | wxICON_INFORMATION, this );
            break;
        default:
            wxMessageBox(
            wxT( "Spielende" ), wxT( "Fluglandung" ),
            wxOK | wxICON_INFORMATION, this );
            break;
        }
        game->neuesSpiel();
        timer.Start(TIMERTICK);
    }
    this->Refresh();
}
