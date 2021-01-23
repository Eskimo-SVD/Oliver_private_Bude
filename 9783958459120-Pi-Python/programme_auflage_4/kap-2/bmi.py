#--------------------------------------------------------------
# bmi.py
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 2
# Michael Weigend 20. April 2016
#--------------------------------------------------------------

# Eingabe
print("Haben Sie Ihr Idealgewicht?")
masse = float(input ("Ihr Gewicht in kg: "))
größe = float (input("Ihre Größe in m: "))

# Verarbeitung
bmi = masse/größe**2

# Ausgabe
print ("Ihr Body Mass Index beträgt:", round(bmi, 2))
if bmi < 18.5:
    print("Sie haben Untergewicht.")
if 18.5 <= bmi <= 25:
    print ("Sie haben Normalgewicht.")
if 25 < bmi <= 30:
    print ("Sie haben Übergewicht.")
if bmi > 30:
    print ("Sie leiden unter Adipositas.")


if bmi <=25:
    if bmi < 18.5:
        print("Sie haben Untergewicht.")
    else: 
        print ("Sie haben Normalgewicht.")
else:
    if bmi <= 30:
        print ("Sie haben Übergewicht.")
    else:
        print ("Sie leiden unter Adipositas.")


if bmi < 18.5:
    print("Sie haben Untergewicht.")
elif bmi <= 25:
    print ("Sie haben Normalgewicht.")
elif bmi <= 30:
    print ("Sie haben Übergewicht.")
else:
    print ("Sie leiden unter Adipositas.")
