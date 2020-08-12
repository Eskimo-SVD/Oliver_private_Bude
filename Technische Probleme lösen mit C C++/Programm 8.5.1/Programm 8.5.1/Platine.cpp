// Projektinclude -------------------------------------------------------------
#include "stdafx.h"
// Standardincludes -----------------------------------------------------------
#include "stdlib.h"
#include "stdio.h"
#include "conio.h"
// Include f�r strcpy - Kopieren von char-Arrays ------------------------------
#include "string.h"
// Include der Klassen-Definition ---------------------------------------------
#include "Platine.h"
// Konstruktor ----------------------------------------------------------------
C_Platine::C_Platine()
{
// alle Attribute werden mit Startwerten belegt
   strcpy(bezeichnung," ");
   this->breite = 0.0;
   this->laenge = 0.0;
}
// set-Methoden f�r die Attribute ---------------------------------------------
void C_Platine::setBezeichnung(char* dummy)
{
   // �bertragung der eingegebenen Bezeichnung
   strcpy(this->bezeichnung,dummy);
}
void C_Platine::setBreite(float neueBreite)
{
   // �bertragung der eingegebenen Breite
   this->breite = neueBreite;
}
void C_Platine::setLaenge(float neueLaenge)
{
   // �bertragung der eingegebenen Tiefe
   this->laenge = neueLaenge;
}
// Dokumentation auf Konsole mit Ergebnissen (incl.Berechnung) ----------------
void C_Platine::ausgabeKonsole()
{
   float flaeche = this->breite*this->laenge;
   float gurtma� = (this->breite + 10.) * 2. + this->laenge;
   int l�nge = printf("\n\n\tPlatinen-Dokumentation:\n\t");
   for(int i = 1; i <= l�nge-5;i++) printf("-");
   printf("\n\n\tBezeichnung: %s",this->bezeichnung);
   printf("\n\n\tBreite:      %11.2f mm",this->breite);
   printf("\n\tL%cenge:      %11.2f mm",char(132),this->laenge);
   printf("\n\n\tFl%cche:      %11.2f mm%c",char(132),flaeche,char(253));
   printf("\n\n\tGurtma%c:     %11.2f mm",char(225),gurtma�);

}
// get-Methoden f�r die Attribute ---------------------------------------------
char* C_Platine::getBezeichnung()
{
   // R�ckgabe aktuelle Bezeichnung
   return this->bezeichnung;
}
float C_Platine::getBreite()
{
   // R�ckgabe aktuelle Breite
   return this->breite;
}
float C_Platine::getLaenge()
{
   // R�ckgabe aktuelle Tiefe
   return this->laenge;
}