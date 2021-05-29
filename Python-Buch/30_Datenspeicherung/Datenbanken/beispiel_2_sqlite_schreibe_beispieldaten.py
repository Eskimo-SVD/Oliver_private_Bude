#!/usr/bin/env python

import sqlite3


if __name__ == "__main__":
    connection = sqlite3.connect("lagerverwaltung.db")
    cursor = connection.cursor()

    for row in ((1, "2607871987", "Grafikkarte Typ 1", "FC", 0),
                (2, "19870109", "Prozessor Typ 13", "LPE", 57),
                (10, "06198823", "Netzteil Typ 3", "FC", 0),
                (25, "11198703", "LED-Lüfter", "FC", 57),
                (26, "19880105", "Festplatte 128GB", "LPE", 12)):
        cursor.execute("INSERT INTO lager VALUES (?,?,?,?,?)", row)


    lieferanten = (("FC", "FiboComputing Inc.", "011235813"),
                   ("LPE", "LettgenPetersErnesti", "026741337"),
                   ("GC", "Golden Computers", "016180339"))
    cursor.executemany("INSERT INTO lieferanten VALUES (?,?,?)", lieferanten)


    kunden = ((12, "Heinz Gruhle", "Turnhallenstr. 1, 3763 Sporthausen"),
              (57, "Markus Altbert", "Kämperweg 24, 2463 Duisschloss"),
              (64, "Steve Apple", "Podmacstr 2, 7467 Iwarhausen"))
    cursor.executemany("INSERT INTO kunden VALUES (?,?,?)", kunden)

    connection.commit()
