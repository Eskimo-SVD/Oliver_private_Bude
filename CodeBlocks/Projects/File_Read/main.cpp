#include <iostream>
#include <fstream>      // Bibliothek für Filestream -> System Datei
#include <string>       // Bibliothek für die Zeichenketten
#include <sstream>      // Bibliothek für stringstream

using namespace std;

string Log_zeile;


int main()
{
    ifstream Log_datei ("ZAM_Logfile.txt");


    while (getline(Log_datei, Log_zeile));
    {

    }

    cout << "Hello world!" << endl;
    return 0;
}
