#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    string name;
    double d_1, d_2, e_3;

    cout << "Gib deinen Vornamen ein: ";
    cin >> name;

    cout << "Hallo " << name << "!" << endl;

    cout << "Gib den ersten Wert ein: ";
    cin >> d_1;
    cout << "Gib den zweiten Wert ein: ";
    cin >> d_2;

    cout << "Ausgabe der Werte: " << d_1 + d_2 << endl;

    e_3 = d_1 * d_2;

    cout << "Ergebnis " << d_1 << " mal " << d_2 << " ist gleich " << e_3 << endl;
    cout << d_1 << " hoch 2 ist gleich " << pow(d_1, 2) << endl;
    cout << d_1 << " hoch 3 ist gleich " << pow(d_1, 3) << endl;
    cout << d_1 << " hoch 4 ist gleich " << pow(d_1, 4) << endl;
    cout << d_2 << " hoch 2 ist gleich " << pow(d_2, 2) << endl;
    cout << d_2 << " hoch 3 ist gleich " << pow(d_2, 3) << endl;
    cout << d_2 << " hoch 4 ist gleich " << pow(d_2, 4) << endl;

    return 0;
}
