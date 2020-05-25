#include <iostream>
#include <string>
#include <vector>

using namespace std;

class tStichwort {
public:
    string Wort;
    int ID;
};

tStichwort Stichwoerter[] = {
    {"Bruder", 1}, {"Vater", 1}, {"Sohn", 1}, {"Opa", 1},
    { "Freund", 1}, { "Mutter", 2}, {"Schwester", 2},
    { "Tochter", 2}, {"Oma", 2},
    {"Gewalt", 3}, {"Druck", 3}, {"Schweigen", 3}
                 };

class tAntwort {
public:
    long Aufrufe;
    string Antwort;
};

tAntwort Antworten[] = {
{0, "Dein $ ist Dir sehr wichtig, nicht wahr?" },
{0, "Hättest Du darüber nicht mit Deinem $ sprechen sollen?"},
{0, "Erzähle mehr über die Beziehung zu Deinem $!"},
{0, "Deine $ ist Dir sehr wichtig, nicht wahr?" },
{0, "Hättest Du darüber nicht mit Deiner $ sprechen sollen?"},
{0, "Erzähle mehr über die Beziehung zu Deiner $!"},
{0, "$ ist keine echte Lösung."},
{0, "Es ist nicht gut, mit $ zu leben."},
{0, "Sollte die Welt nicht auf $ verzichten?"},
{0, "Was bedeutet das eigentlich für Dich: $?"}
                       };

tAntwort Phrasen[] = {
    { 0, "Ich verstehe Deine Zurückhaltung." },
    { 0, "Solltest Du nicht offener von Dir reden?" },
    { 0, "Was meinst Du ist denn die Ursache von all dem?" },
    { 0, "Kannst Du etwas präziser werden?" },
    { 0, "Du solltest nicht alles in Dich hineinfressen." },
    { 0, "Fühlst Du Dich in dieser Hinsicht unsicher?" }
                       };

class tBindung {
public:
    long WortID;
    long AntwortID;
};

tBindung Bindungen[] = {
   {1, 0}, {1, 1}, {1, 2}, {2, 3}, {2, 4}, {2, 5},
   {3, 6}, {3, 7}, {3, 8}, {1, 9}, {2, 9}, {3, 9}
                       };


bool istBuchstabe(char Zeichen)
{
    if (Zeichen>='a' && Zeichen<='z') return true;
    if (Zeichen>='A' && Zeichen<='Z') return true;
    // Mit UTF-8 wird das mit den Umlauten nicht so einfach
    return false;
}

void zerlegeInWoerter(const string &Satz, vector<string> &Woerter)
{
    int Laenge = Satz.length();
    int Pos = 0;
    int Anfang;
    Woerter.clear();
    while (Pos<Laenge) {
        while (Pos<Laenge && !istBuchstabe(Satz[Pos])) Pos++;
        Anfang = Pos;
        while (Pos<Laenge && istBuchstabe(Satz[Pos])) Pos++;
        Woerter.push_back(Satz.substr(Anfang, Pos-Anfang));
    }
}

long holeAntwort(long WortID)
{
    long min=999999;
    long minID = -1;
    long AntwortID;
    long MaxBindungen=sizeof(Bindungen)/sizeof(Bindungen[0]);
    for (long bi=0; bi<MaxBindungen; ++bi) {
        if (Bindungen[bi].WortID==WortID) {
            AntwortID = Bindungen[bi].AntwortID;
            if (min>Antworten[AntwortID].Aufrufe) {
                minID=AntwortID;
                min=Antworten[AntwortID].Aufrufe;
                --Antworten[AntwortID].Aufrufe;
            }
        }
    }
    return minID;
}

void ersetzePlatzHalter(string &Antwort, const string &Wort)
{
    unsigned long pos = Antwort.find("$");
    if (pos!=string::npos) {
        Antwort.replace(pos, 1, Wort);
    }
}

long holePhrase()
{
    long min=999999;
    long minID = -1;
    long MaxPhrasen = sizeof(Phrasen)/sizeof(Phrasen[0]);
    for (long i=0; i<MaxPhrasen; ++i) {
        if (min>Phrasen[i].Aufrufe) {
            minID=i;
            min=Phrasen[i].Aufrufe;
            --Phrasen[i].Aufrufe;
        }
    }
    return minID;
}

void sucheNachAntwort(vector<string> &Woerter, string& Antwort)
{
    long MaxStichwoerter=sizeof(Stichwoerter)
                        /sizeof(Stichwoerter[0]);
    vector<string>::iterator it;
    for (it=Woerter.begin(); it!=Woerter.end(); ++it) {
        for (long wi=0; wi<MaxStichwoerter; ++wi) {
            if (*it == Stichwoerter[wi].Wort) {
                long ID = Stichwoerter[wi].ID;
                long AntwortID = holeAntwort(ID);
                // Nun sollten wir eine ID haben
                if (AntwortID>=0) {
                    Antwort = Antworten[AntwortID].Antwort;
                    ersetzePlatzHalter(Antwort, *it);
                    // Diese Antwort etwas zurückstellen
                    Antworten[AntwortID].Aufrufe+=10;
                    // wir gehen mal einfach
                    return;
                }
            }
        }
    }
    // Kein Stichwort gefunden. Wir faseln...
    long AntwortID = holePhrase();
    Antwort = Phrasen[AntwortID].Antwort;
    // Diese Antwort etwas zurückstellen
    Phrasen[AntwortID].Aufrufe+=10;
}

int main()
{
    string Aussage;
    while (true) {
        getline(cin, Aussage);
        vector<string> Woerter;
        zerlegeInWoerter(Aussage, Woerter);
        string Antwort;
        sucheNachAntwort(Woerter, Antwort);
        cout << Antwort << endl;
    }
}

