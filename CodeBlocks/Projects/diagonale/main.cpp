#include <iostream>
#include <cmath>
using namespace std;
int main()
{
  double laenge, breite, diagonale;
  cout << "Länge (cm) : ";
  cin >> laenge;
  cout << "Breite (cm) : ";
  cin >> breite;
  diagonale=(laenge*laenge) + (breite*breite);
  diagonale=sqrt(diagonale);
  cout << "Diagonale = " << diagonale << " cm" << endl;
  return 0;
}
