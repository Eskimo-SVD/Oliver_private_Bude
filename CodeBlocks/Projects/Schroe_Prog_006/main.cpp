#include <iostream>

using namespace std;

// Mit Umlauten?

int main()
{
  double volumen;
  double laenge, breite, hoehe;
  cout << "Länge (cm) : ";
  cin >> laenge;
  cout << "Breite (cm) : ";
  cin >> breite;
  cout << "Höhe (cm) : ";
  cin >> hoehe;
  volumen = laenge * breite * hoehe;
  volumen/=1000;
  cout << "Volumen : " << volumen
       << " Liter\n";
  return 0;
}
