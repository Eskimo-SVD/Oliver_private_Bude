// Projektinclude -------------------------------------------------------------
#include "stdafx.h"
// Include für strcpy - Kopieren von char-Arrays ------------------------------
#include "string.h"
// Include der Klassen-Definition ---------------------------------------------
#include "C_Platine.h"
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
// Berechnungen
float C_Platine::berechneFläche()
{
	return this->breite*this->laenge;
}
float C_Platine::berechneGurtmaß()
{
   return (this->breite + 20.) * 2. + this->laenge;
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