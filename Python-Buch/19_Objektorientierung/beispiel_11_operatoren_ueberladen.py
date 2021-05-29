#!/usr/bin/env python


class Laenge:
    Umrechnung = {"m" : 1, "cm" : 0.01, "mm" : 0.001,
                  "dm" : 0.1, "km" : 1000,
                  "ft" : 0.3048,   # Fuß
                  "in" : 0.0254,   # Zoll
                  "mi" : 1609344   # Meilen
                 }

    def __init__(self, zahlenwert, einheit):
        self.Zahlenwert = zahlenwert
        self.Einheit = einheit

    def __str__(self):
        return "{:f}{}".format(self.Zahlenwert, self.Einheit)

    def __add__(self, other):
        z = self.Zahlenwert * Laenge.Umrechnung[self.Einheit]
        z += other.Zahlenwert * Laenge.Umrechnung[other.Einheit]
        z /= Laenge.Umrechnung[self.Einheit]
        return Laenge(z, self.Einheit)

    def __sub__(self, other):
        z = self.Zahlenwert * Laenge.Umrechnung[self.Einheit]
        z -= other.Zahlenwert * Laenge.Umrechnung[other.Einheit]
        z /= Laenge.Umrechnung[self.Einheit]
        return Laenge(z, self.Einheit)


if __name__ == "__main__":
    a1 = Laenge(5, "cm")
    a2 = Laenge(3, "dm")

    a3 = a1 + a2
    print(a3)

    a4 = a2 + a1
    print(a4)
