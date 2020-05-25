#include <iostream>
#include <iomanip>
#include <time.h>
#include <fstream>

using namespace std;


float BruttoBetrag, NettoBetrag, MwStBetrag;
const float MwStSatz = 19.0;

  int age;                            // Need a variable
  int zaehler = 1;                          // Counter Programmdurchläufe = 1
  int zaehler_soll = 5;                     // Soll_Anzahl der Durchläufe



int main()
{
    time_t Zeitstempel;                    //Variablen für die Zeit füllen
        tm *nun;
        Zeitstempel = time(0);
        nun = localtime(&Zeitstempel);

    int akt_year = nun->tm_year+1900;          //aktuelles Jahr errechnen
    int akt_month = nun->tm_mon +1;
    int akt_day = nun->tm_mday;
    int akt_hour = nun->tm_hour ;
    int akt_minute = nun->tm_min;


    fstream f;
    f.open("KRU_MWST_Protokoll.dat", ios::app);
    f << "Start des Programms Datei " << akt_year << akt_month << akt_day << akt_hour << akt_minute << endl;

    cout << "Geben Sie den Nettobetrag ein : " ;
    cin >> NettoBetrag;
    cout << endl;
    MwStBetrag = NettoBetrag * MwStSatz / 100;
    BruttoBetrag = NettoBetrag + MwStBetrag;

    std::cout << std::setprecision(2) << std::fixed;

    cout << "Ihr Netto Betrag war          : " << setw(16) << NettoBetrag << endl;
    cout << "Der Steuer Betrag ist         : " << setw(16) << MwStBetrag << endl;
    cout << "Ihr Brutto Preis ist          : " << setw(16) << BruttoBetrag << endl;

    f << "Ihr Netto Betrag war          : " << setw(16) << NettoBetrag << endl;
    f << "Der Steuer Betrag ist         : " << setw(16) << MwStBetrag << endl;
    f << "Ihr Brutto Preis ist          : " << setw(16) << BruttoBetrag << endl;

    f << "Stop  des Programms Datei " << akt_year << akt_month << akt_day << akt_hour << akt_minute << endl;
    f.close();

    return 0;
}
