#include <iostream>
#include <complex>
#include <cmath>
using namespace std;

int main()
{
  complex<double> lex001(2.3, 3.4);
  complex<double> lex002(1.1, 2.2);
  complex<double> vollex = lex001 + lex002;
  cout << vollex << endl;
  double real = vollex.real();
  double imag = vollex.imag();
  complex<double> neulex(real, imag);
  cout << neulex << endl;
  double pi = 4.0 * atan(1.0);
  cout << pi << endl;
  double phase = pi/4.0; // 45°
  double magnitude = 2.0;
  complex<double> vollplex = polar(magnitude, phase);
  cout << vollplex << endl;
  complex<double> inlex;
  cout << "Komplexe Zahl eingeben: ";
  cin >> inlex;
  cout << inlex << endl;
  return 0;
}
