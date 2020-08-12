// Projektinclude -------------------------------------------------------------
#include "stdafx.h"
// Include f�r strcpy - Kopieren von char-Arrays ------------------------------
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
// Berechnungen
float C_Platine::berechneFl�che()
{
	return this->breite*this->laenge;
}
float C_Platine::berechneGurtma�()
{
   return (this->breite + 20.) * 2. + this->laenge;
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