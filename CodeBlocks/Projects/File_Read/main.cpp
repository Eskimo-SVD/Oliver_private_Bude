#include <iostream>
#include <fstream>      // Bibliothek f�r Filestream -> System Datei
#include <string>       // Bibliothek f�r die Zeichenketten
#include <sstream>      // Bibliothek f�r stringstream

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
