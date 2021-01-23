#----------------------------------------------------------------
# Dateiname: thermShow.py
# Darstellung gesammelter Temperatur-Daten
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 9.6
# Michael Weigend 20. April 2016
#--------------------------------------------------------------
import pickle
DATAFILE = "data.dat"
f = open (DATAFILE, "rb")
data = pickle.load(f)
f.close()
for i in range(len(data)):
    print (i, data[i], "°C")
