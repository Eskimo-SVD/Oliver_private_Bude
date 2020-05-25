#include <iostream>
#include <locale>
#include <cstdlib>

using namespace std;

int main()
{
    locale loc;                                              // Objekt erstellen
    // Die Zeile funzt nicht
    // std::locale::global(std::locale("de_DE.UTF-8"));         // mit der Kultur initialisieren

  cout << "Elefanten können nicht fliegen,\n";
  cout << "aber Schrödinger kann programmieren\n";

  system("Pause");
  return 0;
}


