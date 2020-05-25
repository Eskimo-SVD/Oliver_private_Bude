#ifndef GAME_H
#define GAME_H

class Koord {
public:
    int x;
    int y;
};

class BahnKoord {
public:
   Koord Bahn[4];
};

enum tErfolg
    { Fliegt, Gelandet, Ueberflogen, Abgestuerzt,
      Zuschnell, Zusteil };

class Game{
public:
    static Game *getInstance();
    ~Game();
    // endet naechsterTick mit false, ist das Spiel zu Ende
    bool naechsterTick(); // wird vom Timer aufgerufen.
    // bei Spielende gibt getErfolg an, ob gewonnen.
    tErfolg getErfolg() {return Erfolg;}

    BahnKoord getBahnKoord() { return Bahn; }
    void neuesSpiel();
    void setThrottle(int T) { Throttle=T; }
    void setRuder(int R) { Hoehenruder=R; }
    long getHoehe() { return Hoehe; }
    long getDistanz() { return Distanz; }
    long getGeschwindigkeit() { return Geschwindigkeit; }
    double getAnstieg() { return Anstieg; }
protected:
    Game();
private:
    static Game* instance;
    void steuereFlugzeug();
    BahnKoord Bahn;
    double StartDistanz;
    double StartHoehe;
    long Hoehe;
    long Distanz;
    long Geschwindigkeit;
    double Anstieg;
    int Hoehenruder;
    int Throttle;
    tErfolg Erfolg;
};
#endif
