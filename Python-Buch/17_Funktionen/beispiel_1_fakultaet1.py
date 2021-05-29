#!/usr/bin/env python

def fak(zahl):
    if zahl < 0:
        return None
        
    ergebnis = 1
    for i in range(2, zahl+1):
        ergebnis *= i
    return ergebnis
    
while True:
    eingabe = int(input("Geben Sie eine Zahl ein: "))
    ergebnis = fak(eingabe)
    if ergebnis is None:
        print("Fehler bei der Berechnung")
    else:
        print(ergebnis)
