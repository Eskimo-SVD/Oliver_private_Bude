#include <iostream>

using namespace std;

int main()
{
 void getOsterdatum(const UINT uJahr, UINT & uTag, UINT & uMonat)
{
  // Berechnet f�r ein beliebiges Jahr das Osterdatum.

  // Quelle des Gauss - Algorithmus: Stefan Gerth,
  // "Die Gau�'sche Osterregel", N�rnberg, Februar 2003.
  // http://krapfen.org/content/paper/Schule/Facharbeit/Berechnung_des_Osterfestes.pdf

  UINT a = uJahr % 19;
  UINT b = uJahr %  4;
  UINT c = uJahr %  7;

  int k = uJahr / 100;
  int q = k / 4;
  int p = ((8 * k) + 13) / 25;
  UINT Egz = (38 - (k - q) + p) % 30; // Die Jahrhundertepakte
  UINT M = (53 - Egz) % 30;
  UINT N = (4 + k - q) % 7;

  UINT d = ((19 * a) + M) % 30;
  UINT e = ((2 * b) + (4 * c) + (6 * d) + N) % 7;

  // Ausrechnen des Ostertermins:
  if ((22 + d + e) <= 31)
  {
    uTag = 22 + d + e;
    uMonat = 3;
  }
  else
  {
    uTag = d + e - 9;
    uMonat = 4;

    // Zwei Ausnahmen ber�cksichtigen:
    if (uTag == 26)
      uTag = 19;
    else if ((uTag == 25) && (d == 28) && (a > 10))
      uTag = 18;
  }

  // Offsets f�r andere Feiertage:

  // Schwerdonnerstag / Weiberfastnacht -52
  // Rosenmontag -48
  // Fastnachtsdienstag -47
  // Aschermittwoch -46
  // Gr�ndonnerstag -3
  // Karfreitag -2
  // Ostersonntag 0
  // Ostermontag +1
  // Christi Himmelfahrt +39
  // Pfingstsonntag +49
  // Pfingstmontag +50
  // Fronleichnam +60

  // Mari� Himmelfahrt ist stets am 15. August (Danke an Michael Plugge!)

}
