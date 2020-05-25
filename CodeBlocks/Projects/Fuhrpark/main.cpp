#include <iostream>
using namespace std;

class Fahrzeug
{
public:
    Fahrzeug() {}
    virtual double kostet(double km, double tage) {}
};

class Cabrio : public Fahrzeug
{
public:
    Cabrio(double km) {
        this->kmPreis = km;
    }
    double kostet(double km, double tage) {
        return km * kmPreis;
    }
private:
    double kmPreis;
};

class Laster : public Fahrzeug
{
public:
    Laster(double tag) {
        this->tagesMiete = tag;
    }
    double kostet(double km, double tage) {
        return tage * tagesMiete;
    }
private:
    double tagesMiete;
};

const int FAHRZEUGZAHL = 3;
Fahrzeug *fuhrpark[FAHRZEUGZAHL];

int main()
{
    Cabrio spider(2.90);
    fuhrpark[0] = &spider;
    fuhrpark[1] = new Cabrio(3.20);
    fuhrpark[2] = new Laster(80.0);
    for (int i=0; i<FAHRZEUGZAHL; i++)
    {
        cout << fuhrpark[i]->kostet(120, 3) << endl;
    }
}
