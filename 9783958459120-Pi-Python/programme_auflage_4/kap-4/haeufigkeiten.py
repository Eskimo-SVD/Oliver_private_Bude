#----------------------------------------------------------------
# Dateiname: haeufigkeiten.py
# Häufigkeitsverteilung von Buchstaben in einem Text
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 3.5.4
# Michael Weigend 20. April 2016
#--------------------------------------------------------------

def anteilZeichen(text, zeichen):
    n = text.count(zeichen)
    a = n/len(text)
    return a
# Hauptprogramm
t = input("Bitte geben Sie einen Text ein: ")
for z in set(t):                                  #1
    a = anteilZeichen(t, z)                       #2
    print(z, "Häufigkeit:", round(a, 2))          #3
    
    
