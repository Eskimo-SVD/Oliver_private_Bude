#! /usr/bin/python3
#----------------------------------------------------------------
# Dateiname: diffusion_diagramm.py
# Diagramm mit CO2-Konzentration
# Michael Weigend
# Raspberry Pi programmieren mit Python, 4. Auflage, mitp 2019
# Kap. 9
# Michael Weigend 20. November 2018
#--------------------------------------------------------------

from ndir import get_ppm        #1
from time  import sleep

import matplotlib
matplotlib.use("TKAgg")
import matplotlib.pyplot as plt


print("Diffusion von Kohlendioxid.")
print("Wie groß ist Zeitabstand zwischen zwei Messungen (Sekunden)?")
dt = int(input("Zeitabstand(Sekunden): "))      
print("Wie viele Messwerte möchten Sie aufnehmen?")
nr = int(input("Anzahl Messwerte: "))
print("Drücken Sie die ENTER-Taste um die Messreihe zu starten.")
print("Hauchen Sie auf den Kohlendioxid-Sensor.")
input()
print("Messung läuft ..." )

zeiten = []
werte = []

zeit = 0
for i in range(nr):              
    c = get_ppm()
    werte.append(c)
    zeiten.append(zeit)
    print(zeit, c)
    zeit += dt
    sleep(dt)

print("Ende der Messung nach {} Sekunden".format(zeit) )


plt.plot(zeiten, werte)

plt.xlabel("Zeit (s)")
plt.ylabel("Kohlendioxidgehalt (ppm)")
plt.title("Diffusion von Kohlendioxid")
plt.grid(True)
plt.savefig("messung.png")
print("ok")
plt.show()
