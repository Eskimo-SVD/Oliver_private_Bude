
#include "game.h"

#include <stdlib.h>
#include <time.h>

const int MaxY=400;
const int MaxX=600;
const int RollbahnLaenge=4000;
const int MinHoehe=5;

Game *Game::instance = 0;

Game *Game::getInstance()
{
    if (instance==0) {
        instance = new Game();
    }
    return instance;
}

Game::Game()
{
    neuesSpiel();
}

void Game::neuesSpiel()
{
    srand(time(0));
    Distanz=20000 + rand()%20000;
    Hoehe=1000 + rand()%1000;
    StartDistanz = Distanz;
    StartHoehe = Hoehe;
    Geschwindigkeit=100;
    Erfolg = Fliegt;
}

Game::~Game()  {}

const double MinGeschwindigkeit=60;

void Game::steuereFlugzeug()
{
    Geschwindigkeit = 0.6*Geschwindigkeit
            + 0.3*Throttle
            - 0.1*Anstieg*Anstieg;
    Anstieg = 0.8*Anstieg
         + 0.2*(0.1*Hoehenruder - Geschwindigkeit/1000
         - 0.1*Throttle);
    Hoehe=Hoehe+Anstieg;
    Distanz=Distanz-Geschwindigkeit;
    // Abschmieren bei zu geringer Geschwindigkeit
    if (Geschwindigkeit<MinGeschwindigkeit) {
        Anstieg=-20;
        // Verhindert, dass das Flugzeug rückwärts fliegt
        if (Geschwindigkeit<10) {
            Geschwindigkeit = 10;
        }
    }
}

void getProjektion(long Distanz, double StartDistanz,
                   long RollbahnLaenge, long Hoehe,
                   long &BildY, long &BildXVorn,
                   long &BildXHinten)
{
    double ProzAbstand = (Distanz+RollbahnLaenge)
                         /(StartDistanz+RollbahnLaenge);

    // Prozentualer Abstand mal Aufloesung des Bildschirms
    BildY = (1-ProzAbstand)*(double(Hoehe)/Distanz) * MaxY;

    BildXVorn = (1-ProzAbstand)*(1-ProzAbstand) * MaxX;
    // Abfang des Ueberlaufs
    if (BildY>=MaxY) {
        BildY=MaxY-1;
    }
    if (BildXVorn>=MaxX) BildXVorn=MaxX-1;
    BildXHinten = double(Hoehe)
                  / (Distanz+RollbahnLaenge)
                  * BildXVorn;
    if (BildXHinten>BildXVorn) {
        BildXHinten = BildXVorn;
    }
}

bool Game::naechsterTick()
{
    if (Hoehe<MinHoehe) {
        if (Distanz>100) {
            Erfolg = Abgestuerzt;
        } else {
            if (Geschwindigkeit>100) {
                Erfolg = Zuschnell;
            } else if (Anstieg<-50) {
                Erfolg = Zusteil;
            } else {
                Erfolg = Gelandet;
            }
        }
        return false;
    }

    if (Distanz<0) {
        Erfolg = Ueberflogen;
        return false;
    }

    long BildY;
    long BildXVorn;
    long BildXHinten;
    getProjektion(Distanz, StartDistanz, RollbahnLaenge,
                  Hoehe, BildY, BildXVorn, BildXHinten);

    Bahn.Bahn[0].x=(MaxX - BildXVorn) / 2;
    Bahn.Bahn[0].y=(MaxY - BildY) / 2 + BildY;
    Bahn.Bahn[1].x=(MaxX - BildXHinten) / 2;
    Bahn.Bahn[1].y=(MaxY - BildY) / 2;
    Bahn.Bahn[2].x=Bahn.Bahn[1].x + BildXHinten;
    Bahn.Bahn[2].y=Bahn.Bahn[1].y;
    Bahn.Bahn[3].x=Bahn.Bahn[0].x + BildXVorn;
    Bahn.Bahn[3].y=Bahn.Bahn[0].y;
    steuereFlugzeug();
    return true;
}
