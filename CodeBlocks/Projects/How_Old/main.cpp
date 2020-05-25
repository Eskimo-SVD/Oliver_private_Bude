#include <iostream>
#include <time.h>
using namespace std;

int main()                            // Most important part of the program!
{
  int age;                            // Need a variable
  int i = 1;                          // Counter Programmdurchläufe = 1

  time_t Zeitstempel;                    //Variablen für die Zeit füllen
    tm *nun;
    Zeitstempel = time(0);
    nun = localtime(&Zeitstempel);

  int akt_year = nun->tm_year+1900;          //aktuelles Jahr errechnen

  int Tamina_GJahr = 2009;                   // Geburtsjahr declarieren -> soll später in eine SQL Datenbank
  int Laura_GJahr = 2008;
  int Viktoria_GJahr = 2002;
  int Yvonne_GJahr = 1974;
  int Oliver_GJahr =1970;

  int Tamina_Alter = akt_year - Tamina_GJahr;      // wir haben eine Geburtstagsliste
  int Laura_Alter = akt_year - Laura_GJahr;
  int Viktoria_Alter = akt_year - Viktoria_GJahr;
  int Yvonne_Alter = akt_year - Yvonne_GJahr;
  int Oliver_Alter = akt_year - Oliver_GJahr;


  cout << "Das aktuelle Jahr ist: " << akt_year << "\n";                     //aktuelles Jahr anzeigen

  cout << "\n Liste der Geburtsjahre: \n";
  cout << "Taminas   Geburtsjahr ist: " << Tamina_GJahr << "\n";                     //Taminas Geburtsjahr anzeigen
  cout << "Lauras    Geburtsjahr ist: " << Laura_GJahr << "\n";                     //Lauras Geburtsjahr anzeigen
  cout << "Viktorias Geburtsjahr ist: " << Viktoria_GJahr << "\n";                     //Viktorias Geburtsjahr anzeigen
  cout << "Yvonnes   Geburtsjahr ist: " << Yvonne_GJahr << "\n";                     //Yvonnes Geburtsjahr anzeigen
  cout << "Olivers   Geburtsjahr ist: " << Oliver_GJahr << "\n";                     //Olivers Geburtsjahr anzeigen

  cout << "\n Altersliste der Familie: \n";
  cout << "Taminas   Alter ist : " << Tamina_Alter << "\n";                     //Taminas Alter anzeigen
  cout << "Laura     wäre jetzt: " << Laura_Alter << "\n";                     //Lauras Alter anzeigen
  cout << "Viktorias Alter ist : " << Viktoria_Alter << "\n";                     //Viktorias Alter anzeigen
  cout << "Yvonnes   Alter ist : " << Yvonne_Alter << "\n";                     //Yvonnes Alter anzeigen
  cout << "Olivers   Alter ist : " << Oliver_Alter << "\n";                     //Olivers Alter anzeigen

  cout << "\n Sonstige Paramaeter: " << "\n";                     //aktuelles Jahr anzeigen
  cout << "Zeitstempel : " << Zeitstempel << "\n";
  cout << "NUN         : " << nun << "\n";
  cout << "LOCALTIME   : " << localtime << "\n";
  // cout << "NUN         : " << nun << "\n";
  // cout << "TM         : " << tm << "\n";
  cout << "\n \n";

  while (i <= 6)  {                            // Do it 10 times


  cout << "Du bist im " << i << " Durchlauf des Programs von 6.\n"
   <<"    Please input your age: ";                                       // Asks for age
  cin>> age;                                                              // The input is put in age
  i++;                                                                    //increase counter

  cin.ignore();                                  // Throw away enter
  if ( age < 30 ) {                  // If the age is less than 100
     cout<<"You are pretty young!\n"; // Just to show you it works...
  }
  else if ( age < 40 ) {            // I use else just to show an example
     cout<<"You are between 30 and 40\n";           // Just to show you it works...
  }
  else if ( age < 50 ) {            // I use else just to show an example
     cout<<"You are between 40 and 50\n";           // Just to show you it works...
  }
  else if ( age < 60 ) {            // I use else just to show an example
     cout<<"You are between 50 and 60\n";           // Just to show you it works...
  }
  else if ( age < 70 ) {            // I use else just to show an example
     cout<<"You are between 60 and 70\n";           // Just to show you it works...
  }
  else if ( age == 70 ) {            // I use else just to show an example
     cout<<"You are excatly 70\n";           // Just to show you it works...
  }
  else if ( age < 80 ) {            // I use else just to show an example
     cout<<"You are between 70 and 80\n";           // Just to show you it works...
  }
  else if ( age < 90 ) {            // I use else just to show an example
     cout<<"You are between 80 and 90\n";           // Just to show you it works...
  }
  else if ( age < 100 ) {            // I use else just to show an example
     cout<<"You are between 90 and 100\n";           // Just to show you it works...
  }
  else {
    cout<<"You are really old\n";     // Executed if no other statement is
  }
  // cout<<"You are exactly \n\n" << age << "\n\n years old\n";

  // Treffer in der Familien Geburtstagsliste


   if ( age == Tamina_Alter ) {            // I use else just to show an example
     cout<<"Du bist genauso alt wie Tamina Krüger\n";           // Just to show you it works...
  }
    else if ( age == Laura_Alter ) {            // I use else just to show an example
     cout<<"Du bist genauso alt wie Laura Krüger jetzt wäre. \n";           // Just to show you it works...
  }
    else if ( age == Viktoria_Alter ) {            // I use else just to show an example
     cout<<"Du bist genauso alt wie Viktoria Krüger\n";           // Just to show you it works...
  }
    else if ( age == Yvonne_Alter )   {            // I use else just to show an example
     cout<<"Du bist genauso alt wie Yvonne Krüger\n";           // Just to show you it works...
  }
    else if ( age == Oliver_Alter ) {            // I use else just to show an example
     cout<<"Du bist genauso alt wie Oliver Krüger\n";           // Just to show you it works...
  }
  cin.get();
}
}
