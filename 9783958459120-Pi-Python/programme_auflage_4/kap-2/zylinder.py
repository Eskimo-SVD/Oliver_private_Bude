#--------------------------------------------------------------
# zylinder.py
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 2
# Michael Weigend 20. April 2016
#--------------------------------------------------------------
from math import pi

# Eingabe
eingabe_durchmesser = input ("Durchmesser in m: ")
eingabe_höhe = input ("Höhe in m: ")

# Verarbeitung
d = float(eingabe_durchmesser)
h = float(eingabe_höhe)
volumen = pi * (d/2)**2 * h

# Ausgabe
print("Der Zylinder hat folgendes Volumen (Kubikmeter)")
print (round(volumen,2))
print("Der Zylinder hat ein Volumen von ", end="")
print(round (volumen, 2), end="")
print( " Kubikmetern.", end="")

