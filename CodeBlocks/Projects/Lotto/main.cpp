/* 20200525 - Berechnung der Zusatzzahl soll noch besser eingebaut werden */

#include <iostream>   // die Bildschirmausgabe
#include <cstdlib>    // die Zufallsfunktionen
using namespace std;

int main()
{
    int lotto[6];
    int i, j;
    bool neueZahl;

    srand(0);
    for(i=0; i<6; i++) // ziehe nacheinander sechs Zahlen
    {
        do  // wiederhole die Ziehung, bis die neue Zahl
        {   // nicht mit einer der vorigen identisch ist.
            lotto[i] = rand() % 49 + 1;
            neueZahl = true; // positive Grundeinstellung
            for (j=0; j<i; j++)
            {  // durchlaufe alle bisher gezogenen Kugeln
                if (lotto[j]==lotto[i])
                { // Hier wurde ein Doppelter entdeckt
                    neueZahl = false;
                }
            }
        } while (!neueZahl);
        cout << lotto[i] << endl;
    }

    for(i=0; i<1; i++) // ziehe die Zusatzzahl
    {
        do  // wiederhole die Ziehung, bis die neue Zahl
        {   // nicht mit einer der vorigen identisch ist.
            lotto[i] = rand() % 49 + 1;
            neueZahl = true; // positive Grundeinstellung
            for (j=0; j<i; j++)
            {  // durchlaufe alle bisher gezogenen Kugeln
                if (lotto[j]==lotto[i])
                { // Hier wurde ein Doppelter entdeckt
                    neueZahl = false;
                }
            }
        } while (!neueZahl);
        cout << "Zusatzzahl : "<< lotto[i] << endl;
    }

}
