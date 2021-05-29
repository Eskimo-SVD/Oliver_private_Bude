#!/usr/bin/env python

while True:
    zahl = int(input("Geben Sie eine Zahl ein: "))

    if zahl < 0:
        print("Negative Zahlen sind nicht erlaubt")
        continue

    ergebnis = 1
    for i in range(2, zahl+1):
        ergebnis = ergebnis * i

    print("Ergebnis: ", ergebnis)
