#! /usr/bin/python3
#----------------------------------------------------------------
# Dateiname: temp.py
# Temperaturmessung mit dem Temperatursensor von Dallas
#  
# Michael Weigend
# Raspberry Pi programmieren mit Python, 4. Auflage, mitp 2019
# Kap. 12
# Michael Weigend 20. November 2018
#----------------------------------------------------------------
import os, time

os.system('modprobe w1-gpio')
os.system("modprobe w1-therm")

PATH = "/sys/bus/w1/devices/{}/w1_slave"

for d in os.listdir("/sys/bus/w1/devices/"):
    if d.startswith("10") or d.startswith("28"):
        path = PATH.format(d)


def readTemp():
    ok = False                                 
    while not ok:
        f = open(path, 'r')                    
        first, second = f.readlines()       
        f.close()                           
        if 'YES' in first:                   
            ok = True
    a, b = second.split('=')        
    return int(b)/1000                    


if __name__ == "__main__":
    print("Pfad zur Daten-Datei des Thermosensors:", path)
    while True:
        print(readTemp(),'Grad Celsius')
        time.sleep(1)
                            

           
        
   
