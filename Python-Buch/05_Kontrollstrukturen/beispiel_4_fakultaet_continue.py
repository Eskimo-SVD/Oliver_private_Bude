#!/usr/bin/env python

while True:
    zahl = int(input("Geben Sie eine Zahl ein: "))

    if zahl < 0:
        print("Negative Zahlen sind nicht erlaubt")
        continue

    ergebnis = 1
    while zahl > 0:
        ergebnis = ergebnis * zahl
        zahl = zahl - 1

    print("Ergebnis: ", ergebnis)
