#include <iostream>

using namespace std;

// Mit Umlauten?

int main()
{
  double volumen;
  double laenge, breite, hoehe;
  cout << "L�nge (cm) : ";
  cin >> laenge;
  cout << "Breite (cm) : ";
  cin >> breite;
  cout << "H�he (cm) : ";
  cin >> hoehe;
  volumen = laenge * breite * hoehe;
  volumen/=1000;
  cout << "Volumen : " << volumen
       << " Liter\n";
  return 0;
}
