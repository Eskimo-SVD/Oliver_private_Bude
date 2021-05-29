#!/usr/bin/env python

import csv

if __name__ == "__main__":
    writer = csv.DictWriter(open("beispieldaten_autos.csv", "w"), ["marke", "modell", "leistung_in_ps"])
    writer.writeheader()

    daten = ({"marke" : "Volvo", "modell" : "P245", "leistung_in_ps" : "130"},
             {"marke" : "Ford", "modell" : "Focus", "leistung_in_ps" : "90"},
             {"marke" : "Mercedes", "modell" : "CLK", "leistung_in_ps" : "250"},
             {"marke" : "Audi", "modell" : "A6", "leistung_in_ps" : "350"})

    writer.writerows(daten)
