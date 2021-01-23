#--------------------------------------------------------------
# zylinder_mehrmals.py
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 2
# Michael Weigend 20. April 2016
#--------------------------------------------------------------
from math import pi
antwort = "j"
while antwort == "j":
    eingabe_durchmesser = input ("Durchmesser in m: ")
    eingabe_höhe = input ("Höhe in m: ")
    d = float(eingabe_durchmesser)
    h = float(eingabe_höhe)
    volumen = pi * (d/2)**2 * h      
    print("Der Zylinder hat ein Volumen von ",
          round (volumen, 2), " Kubikmetern.")
    antwort = input("Noch eine Rechnung (j/n)? ")
print ("Auf Wiedersehen.")


