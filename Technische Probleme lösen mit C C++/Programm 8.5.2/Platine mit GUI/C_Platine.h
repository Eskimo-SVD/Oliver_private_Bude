#ifndef C_PLATINE_H
#define C_PLATINE_H

class C_Platine
{
   // Attribute der Klasse (gekapselt)
   private:
      char bezeichnung[256];
      float laenge, breite;
   // Methoden der Klasse (�ffentlich)
   public:
      // Konstruktor
      C_Platine();
      // Manipulation der Attribute
      void setBezeichnung(char*);
      void setBreite(float);
      void setLaenge(float);
      // Auslesen der Attribute
      char* getBezeichnung();
      float getBreite();
      float getLaenge();
	  // Berechnungen
      float berechneFl�che();
	  float berechneGurtma�();
}; // Ende der Klasse

#endif