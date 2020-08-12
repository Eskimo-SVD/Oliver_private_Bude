// Projektinclude -------------------------------------------------------------
#include "stdafx.h"
// Standardincludes -----------------------------------------------------------
#include "stdlib.h"
#include "stdio.h"
#include "conio.h"
// Include für strcpy - Kopieren von char-Arrays ------------------------------
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
// set-Methoden für die Attribute ---------------------------------------------
void C_Platine::setBezeichnung(char* dummy)
{
   // Übertragung der eingegebenen Bezeichnung
   strcpy(this->bezeichnung,dummy);
}
void C_Platine::setBreite(float neueBreite)
{
   // Übertragung der eingegebenen Breite
   this->breite = neueBreite;
}
void C_Platine::setLaenge(float neueLaenge)
{
   // Übertragung der eingegebenen Tiefe
   this->laenge = neueLaenge;
}
// Dokumentation auf Konsole mit Ergebnissen (incl.Berechnung) ----------------
void C_Platine::ausgabeKonsole()
{
   float flaeche = this->breite*this->laenge;
   float gurtmaß = (this->breite + 10.) * 2. + this->laenge;
   int länge = printf("\n\n\tPlatinen-Dokumentation:\n\t");
   for(int i = 1; i <= länge-5;i++) printf("-");
   printf("\n\n\tBezeichnung: %s",this->bezeichnung);
   printf("\n\n\tBreite:      %11.2f mm",this->breite);
   printf("\n\tL%cenge:      %11.2f mm",char(132),this->laenge);
   printf("\n\n\tFl%cche:      %11.2f mm%c",char(132),flaeche,char(253));
   printf("\n\n\tGurtma%c:     %11.2f mm",char(225),gurtmaß);

}
// get-Methoden für die Attribute ---------------------------------------------
char* C_Platine::getBezeichnung()
{
   // Rückgabe aktuelle Bezeichnung
   return this->bezeichnung;
}
float C_Platine::getBreite()
{
   // Rückgabe aktuelle Breite
   return this->breite;
}
float C_Platine::getLaenge()
{
   // Rückgabe aktuelle Tiefe
   return this->laenge;
}