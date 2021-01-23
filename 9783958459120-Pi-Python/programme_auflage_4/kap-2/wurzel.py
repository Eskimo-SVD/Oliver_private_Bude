#--------------------------------------------------------------
# wurzel.py
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 2
# Michael Weigend 20. April 2016
#--------------------------------------------------------------
# Eingabe
a = float(input ("Positive Zahl: "))
genauigkeit = float(input ("Genauigkeit: "))

# Verarbeitung
alt = 2           # willkürliche Zahl > 0 
neu = 5           # willkürliche Zahl > 0

while (abs(alt - neu)) > genauigkeit:
    alt = neu
    neu = 0.5*(alt + a/alt)



# Ausgabe
print("Die Wurzel aus ", a, "ist", neu)

