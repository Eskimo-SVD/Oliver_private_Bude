# anpeilen.py
# Michael Weigend
# Raspberry Pi programmieren mit Python 3. Auflage, mitp 2016
# Kap. 2
# Michael Weigend 20. April 2016
#----------------------------------------------------

from math import tan, radians

# Eingabe                                                 

höhe = input("Höhe des Winkelmessers gegenüber dem Boden (m): ")
entfernung = input("Entfernung vom Gebäude (m): ")
winkel = input("Winkel (Grad): ")

# Verarbeitung
h = float(höhe)
e = float(entfernung)
alpha = radians(float(winkel))
gebäudehöhe = h + e*tan(alpha)

# Ausgabe
print("Das Gebäude ist", round(gebäudehöhe, 2), "m hoch.")


