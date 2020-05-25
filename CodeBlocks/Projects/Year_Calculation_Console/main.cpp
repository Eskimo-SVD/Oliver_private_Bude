#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    bool istEinSchaltjahr(const UINT uJahr)


{
  // Die Regel lautet: Alles, was durch 4 teilbar ist, ist ein Schaltjahr.
  // Es sei denn, das Jahr ist durch 100 teilbar, dann ist es keins.
  // Aber wenn es durch 400 teilbar ist, ist es doch wieder eins.

  if ((uJahr % 400) == 0)
    return true;
  else if ((uJahr % 100) == 0)
    return false;
  else if ((uJahr % 4) == 0)
    return true;

  return false;
}

short getAnzahlTageImMonat(const UINT uMonat, const UINT uJahr)
{
  //                     ung�lt,Jan,Feb,Mrz,Apr,Mai,Jun,Jul,Aug,Sep,Okt,Nov,Dez
  int arrTageImMonat[13] = {  0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

  if (uMonat == 2)
  {
    // Februar: Schaltjahr unterscheiden
    if (istEinSchaltjahr(uJahr))
      return 29;
    else
      return 28;
  }

  if ((uMonat >= 1) && (uMonat <= 12))
    return arrTageImMonat[uMonat];
  else
  {
    _ASSERT(0); // ung�ltiger Monat !
    return 0;
  }
}

short getWochentag(const UINT uTag, const UINT uMonat, const UINT uJahr)
{
//                       ung�lt Jan Feb Mrz Apr Mai Jun Jul Aug Sep Okt Nov Dez
BYTE arrMonatsOffset[13] = {  0,  0,  3,  3,  6,  1,  4,  6,  2,  5,  0,  3,  5};

  short nErgebnis = 0;

  _ASSERT(uTag > 0);
  _ASSERT(uTag <= 31);
  _ASSERT(uMonat > 0);
  _ASSERT(uMonat <= 12);

  // Monat / Tag - Plausi pr�fen:
  if ((uTag > 31) || (uMonat > 12) || (uMonat <= 0)
      || (uTag <= 0) || (uJahr <= 0))
  {
    return -1;
  }

  BYTE cbTagesziffer = (uTag % 7);
  BYTE cbMonatsziffer = arrMonatsOffset[uMonat];
  BYTE cbJahresziffer = ((uJahr % 100) + ((uJahr % 100) / 4)) % 7;
  BYTE cbJahrhundertziffer = (3 - ((uJahr / 100) % 4)) * 2;

  // Schaltjahreskorrektur:
  if ((uMonat <= 2) && (istEinSchaltjahr(uJahr))
    cbTagesziffer = cbTagesziffer + 6;

  nErgebnis = (cbTagesziffer + cbMonatsziffer + cbJahresziffer + cbJahrhundertziffer) % 7;

  // Ergebnis:
  // 0 = Sonntag
  // 1 = Montag
  // 2 = Dienstag
  // 3 = Mittwoch
  // 4 = Donnerstag
  // 5 = Freitag
  // 6 = Samstag
  return nErgebnis;
}

short getTagDesJahres(const UINT uTag, const UINT uMonat, const UINT uJahr)
{
  // Der wievielte Tag des Jahres ist dieser Tag
  if ((uMonat == 0) || (uMonat > 12))
  {
    _ASSERT(0);
    return -1;
  }

  UINT uLokalTag = uTag;
  UINT uLokalMonat = uMonat;

  while (uLokalMonat > 1)
  {
    uLokalMonat--;
    uLokalTag += getAnzahlTageImMonat(uLokalMonat, uJahr);
  }

  return uLokalTag;
}

short getKalenderwoche(short uTag, short uMonat, short uJahr)
{
  // Berechnung erfolgt analog DIN 1355, welche besagt:
  // Der erste Donnerstag im neuen Jahr liegt immer in der KW 1.
  // "Woche" ist dabei definiert als [Mo, ..., So].

  short nTagDesJahres = getTagDesJahres(uTag, uMonat, uJahr);

  // Berechnen des Wochentags des 1. Januar:
  short nWochentag1Jan = getWochentag(1, 1, uJahr);

  // Sonderf�lle Freitag und Samstag
  if (nWochentag1Jan >= 5)
    nWochentag1Jan = nWochentag1Jan - 7;

  // Sonderf�lle "Jahresanfang mit KW - Nummer aus dem Vorjahr"
  if ( (nTagDesJahres + nWochentag1Jan) <= 1)
  {
    return getKalenderwoche(31, 12, uJahr - 1);
  }

  short nKalenderWoche = ((nTagDesJahres + nWochentag1Jan + 5) / 7);

  _ASSERT(nKalenderWoche >= 1);
  _ASSERT(nKalenderWoche <= 53);

  // 53 Kalenderwochen hat grunds�tzlich nur ein Jahr,
  // welches mit einem Donnerstag anf�ngt !
  // In Schaltjahren ist es auch mit einem Mittwoch m�glich, z.B. 1992
  // Andernfalls ist diese KW schon die KW1 des Folgejahres.
  if (nKalenderWoche == 53)
  {
    bool bIstSchaltjahr = istEinSchaltjahr(uJahr);

    if (  (nWochentag1Jan  ==  4) // Donnerstag
      ||  (nWochentag1Jan  == -3) // auch Donnerstag
      ||  ((nWochentag1Jan ==  3) && bIstSchaltjahr)
      ||  ((nWochentag1Jan == -4) && bIstSchaltjahr)
      )
    {
      ; // Das ist korrekt und erlaubt
    }
    else
      nKalenderWoche = 1; // Korrektur des Wertes
  }

  return nKalenderWoche;
}

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



 // Hier noch die Bestimmung der Adventssonntage und des Buß- und Bettages, danke an Andy Grothe f�r den Hinweis:

void getViertenAdvent(const UINT uJahr, UINT & uTag, UINT & uMonat)
{
  // Berechnet für ein beliebiges Jahr das Datum des 4. Advents-Sonntags.
  // Der 4. Adventssonntag ist stets der Sonntag vor dem 1. Weihnachtsfeiertag,
  // mu� also stets in der Periode [18. - 24.12.] liegen:

  uMonat = 12; // Das steht jedes Jahr fest :-)

  short nWoTag = getWochentag(24, 12, uJahr); // Wochentag des 24.12. ermitteln

  uTag = 24 - nWoTag;

  // Offsets: Der Bu�- und Bettag liegt stets 32 Tage vor dem  4. Advent
}


long ZeitDifferenzInJahren(const SYSTEMTIME & Startzeit,
                           const SYSTEMTIME & Endezeit) const
{
  if (Endezeit.wMonth > Startzeit.wMonth)
    return Endezeit.wYear - Startzeit.wYear;

  if (Endezeit.wMonth < Startzeit.wMonth)
    return Endezeit.wYear - Startzeit.wYear - 1;

  // Monate sind identisch.

  if (Endezeit.wDay > Startzeit.wDay)
    return Endezeit.wYear - Startzeit.wYear;

  if (Endezeit.wDay < Startzeit.wDay)
    return Endezeit.wYear - Startzeit.wYear - 1;

  // Tag ist bei beiden identisch.

  if (Endezeit.wHour > Startzeit.wHour)
    return Endezeit.wYear - Startzeit.wYear;

  if (Endezeit.wHour < Startzeit.wHour)
    return Endezeit.wYear - Startzeit.wYear - 1;

  // Stunde ist identisch.

  if (Endezeit.wMinute > Startzeit.wMinute)
    return Endezeit.wYear - Startzeit.wYear;

  if (Endezeit.wMinute < Startzeit.wMinute)
    return Endezeit.wYear - Startzeit.wYear - 1;

  if (Endezeit.wSecond > Startzeit.wSecond)
    return Endezeit.wYear - Startzeit.wYear;

  if (Endezeit.wSecond < Startzeit.wSecond)
    return Endezeit.wYear - Startzeit.wYear - 1;

  if (Endezeit.wMilliseconds >= Startzeit.wMilliseconds)
    return Endezeit.wYear - Startzeit.wYear;
  else
    return Endezeit.wYear - Startzeit.wYear - 1;
}

//////////////////////////////////////////////////////////////////////////////
// Die Zeitdifferenz in Monaten l��t sich nicht exakt ausrechnen,
// weil ein Monat nicht immer gleich lang ist. Beispiel:
// Zwischen dem 28.2. und dem 28.3. liegen nur 28 Tage.
// Ist das schon ein Monat (28. bis 28.) ????
// Der M�rz ist erst am 31.3. zu Ende ! Ist das ein Monat (28.2. - 31.3.) ????
//////////////////////////////////////////////////////////////////////////////

long ZeitDifferenzInTagen(const SYSTEMTIME & Startzeit,
                          const SYSTEMTIME & Endezeit)
{
  // Ist die Ende-Uhrzeit auch hinter der Startuhrzeit ? Das ist der Normalfall.
  // Andernfalls m�ssen wir nachher noch eins abziehen!

  long lAbzug = 0;

  if (  (Endezeit.wHour < Startzeit.wHour)
    ||  ((Endezeit.wHour == Startzeit.wHour)
          && (Endezeit.wMinute  < Startzeit.wMinute))
    ||  ((Endezeit.wHour == Startzeit.wHour)
          && (Endezeit.wMinute == Startzeit.wMinute)
          && (Endezeit.wSecond  < Startzeit.wSecond))
    ||  ((Endezeit.wHour == Startzeit.wHour)
          && (Endezeit.wMinute == Startzeit.wMinute)
          && (Endezeit.wSecond == Startzeit.wSecond)
          && (Endezeit.wMilliseconds < Startzeit.wMilliseconds))
     )
  {
    lAbzug = 1;
  }

  // Im gleichen Jahr ? Dann nutzen wir "getTagDesJahres":
  if (Endezeit.wYear == Startzeit.wYear)
    return getTagDesJahres(Endezeit.wDay, Endezeit.wMonth, Endezeit.wYear)
           - getTagDesJahres(Startzeit.wDay, Startzeit.wMonth, Startzeit.wYear)
           - lAbzug;

  else if (Endezeit.wYear > Startzeit.wYear)
  {
    // Wir starten mit der Anzahl Tage im Endejahr:
    long lErgebnis = getTagDesJahres(Endezeit.wDay, Endezeit.wMonth,
                                       Endezeit.wYear) - lAbzug;

    UINT uJahr = Endezeit.wYear - 1;

    // Jetzt summieren wir alle dazwischenliegenden Jahre:
    while (uJahr > Startzeit.wYear)
    {
      lErgebnis += getAnzahlTageImJahr(uJahr);
      uJahr--;
    }

    // und addieren schlie�lich noch die Anzahl der Tage aus dem Start - Jahr:
    lErgebnis += (getAnzahlTageImJahr(Startzeit.wYear)
                  - getTagDesJahres(Startzeit.wDay,
                                    Startzeit.wMonth, Startzeit.wYear));

    return lErgebnis;
  }

  else
    return -1; // Die Endezeit liegt vor der Startzeit !
}

long ZeitDifferenzInSekunden(const SYSTEMTIME & Startzeit, const SYSTEMTIME & Endezeit)
{
  __int64 lErgebnis = Endezeit.wSecond - Startzeit.wSecond;
  // lErgebnis kann durchaus negativ sein ! Wird aber gleich korrigiert.
  lErgebnis += (Endezeit.wMinute - Startzeit.wMinute) * 60;
  lErgebnis += (Endezeit.wHour - Startzeit.wHour) * 3600;

  // Im gleichen Jahr ? Dann nutzen wir "getTagDesJahres":
  if (Endezeit.wYear == Startzeit.wYear)
    return (long)
      (((getTagDesJahres(Endezeit.wDay, Endezeit.wMonth, Endezeit.wYear)
      - getTagDesJahres(Startzeit.wDay, Startzeit.wMonth, Startzeit.wYear)) * 86400)
      + lErgebnis);

  else if (Endezeit.wYear > Startzeit.wYear)
  {
    // Wir starten mit der Anzahl Tage im Endejahr
    lErgebnis += getTagDesJahres(Endezeit.wDay, Endezeit.wMonth, Endezeit.wYear) * 86400;

    UINT uJahr = Endezeit.wYear - 1;

    // Jetzt summieren wir alle dazwischenliegenden Jahre:
    while (uJahr > Startzeit.wYear)
    {
      lErgebnis += (getAnzahlTageImJahr(uJahr) * 86400);
      uJahr--;
    }

    // und addieren schlie�lich noch die Anzahl der Tage aus dem Start - Jahr:
    lErgebnis += ((getAnzahlTageImJahr(Startzeit.wYear)
            - getTagDesJahres(Startzeit.wDay,
                    Startzeit.wMonth, Startzeit.wYear)) * 86400);

    return (long) lErgebnis;
  }

  else
    return -1; // Die Endezeit liegt vor der Startzeit !
}

    return 0;
}
