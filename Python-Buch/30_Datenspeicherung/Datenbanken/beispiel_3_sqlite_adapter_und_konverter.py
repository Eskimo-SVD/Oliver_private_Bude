#!/usr/bin/env python

import sqlite3


class Kreis:
    def __init__(self, mx, my, r):
        self.Mx = mx
        self.My = my
        self.R = r


def kreisadapter(k):
    return "{};{};{}".format(k.Mx, k.My, k.R)


def kreiskonverter(bytestring):
    mx, my, r = bytestring.split(b";")
    return Kreis(float(mx), float(my), float(r))


if __name__ == "__main__":
    # Adapter und Konverter registrieren
    sqlite3.register_adapter(Kreis, kreisadapter)
    sqlite3.register_converter("KREIS", kreiskonverter)

    # Hier wird eine Beispieldatenbank im Arbeitsspeicher mit
    # einer einspaltigen Tabelle für Kreise definiert
    connection = sqlite3.connect(":memory:",
                                 detect_types=sqlite3.PARSE_DECLTYPES)
    cursor = connection.cursor()
    cursor.execute("CREATE TABLE kreis_tabelle(k KREIS)")

    # Kreis in die Datenbank schreiben
    kreis = Kreis(1, 2.5, 3)
    cursor.execute("INSERT INTO kreis_tabelle VALUES (?)", (kreis,))

    # Kreis wieder auslesen
    cursor.execute("SELECT * FROM kreis_tabelle")

    gelesener_kreis = cursor.fetchall()[0][0]
    print(type(gelesener_kreis))
    print(gelesener_kreis.Mx, gelesener_kreis.My, gelesener_kreis.R)
