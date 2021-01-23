#----------------------------------------------------------------
# Dateiname: absorption.py
# Absorptionsspektrometer mit dem tst2561 Lichtsensor
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 4. Auflage, mitp 2019
# Kap. 9
# 22.November 2018
#----------------------------------------------------------------


from tsl2561 import TSL2561
from time import sleep
from math import log10
import matplotlib
matplotlib.use("TKAgg")
import matplotlib.pyplot as plt

def messen(tsl):
    print("Schalte die Lampe auf Blau.")
    input("Weiter mit <Enter>.")
    blau = tsl.lux()
    print("Schalte die Lampe auf Grün.")
    input("Weiter mit <Enter>.")
    grün = tsl.lux()
    print("Schalte die Lampe auf Rot.")
    input("Weiter mit <Enter>.")
    rot = tsl.lux()
    return blau, grün, rot

# Hauptprogramm

tsl = TSL2561()

print("Zuerst musst du kalibrieren")
print("Gib ein Reagenzglas mit Wasser in das Spektrometer.")
I0blau, I0grün, I0rot = messen(tsl)
print("""Das Gerät ist kalibriert.
Jetzt kannst du ein Absorptionsdiagramm erstellen.
Gib ein Reagenzglas mit einer Farbprobe
in das Photometer.""")
Iblau, Igrün, Irot = messen(tsl)

absorption = [log10(I0blau/Iblau),
              log10(I0grün/Igrün),
              log10(I0rot/Irot)]
wellenlänge = [450, 530, 640]

plt.plot(wellenlänge, absorption, "sb")
plt.title("Absorptionsdiagramm")
plt.xlabel("Wellenlänge (nm)")
plt.ylabel("Absorption")
plt.grid(True)
plt.show()





