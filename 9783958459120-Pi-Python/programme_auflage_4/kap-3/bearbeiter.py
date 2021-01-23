#----------------------------------------------------------------
# Dateiname: bearbeiter.py
# Interaktives Programm zur Ermittlung des zuständigen Bearbeiters
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 3.3
# Michael Weigend 20. April 2016
#--------------------------------------------------------------

print ("Herzlich willkommen bei der Bürgerberatung")
name = input("Nachname: ")
if name[0] in "abcdefghijkABCDEFGHIJK":
    bearbeiter = "Simone Meier"
else:
    bearbeiter = "Frank Kabus"
print ("Für Sie ist", bearbeiter, "zuständig.")
