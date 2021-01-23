#----------------------------------------------------------------
# Dateiname: zufallsnamen.py
# Zufällige Auswahl
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 3.8
# Michael Weigend 20. April 2016
#--------------------------------------------------------------

from random import *
namen = ["Simon", "Karla", "Maike", "Tom"]
shuffle(namen)
while namen:
    input("Drücken Sie ENTER!")
    print("Der/die nächste ist", namen.pop()+".")
    
    
