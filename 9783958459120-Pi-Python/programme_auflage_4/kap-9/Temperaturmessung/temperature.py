#----------------------------------------------------------------
# Dateiname: temperature.py
# Modul zut Temperaturmessung
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 9.4
# Michael Weigend 20. April 2016
#--------------------------------------------------------------
import os, time

os.system("modprobe w1-gpio")
os.system("modprobe w1-therm")

class Thermometer:
    def __init__(self, deviceFile):
        self.file = deviceFile

    def read(self):
        ok = False
        while not ok:
            f = open(self.file, "r")
            first, second = f.readlines()
            f.close()
            if first.find("YES") != -1:
                ok = True
            else: time.sleep(0.05)
        tempString = second.split('=')[1]
        return int(tempString)/1000

class TempDevices(list):
    def __init__(self):
        list.__init__(self)
        for d in os.listdir("/sys/bus/w1/devices/w1_bus_master1"):
            if d.startswith("10") or d.startswith("28"):
                deviceFile = "/sys/bus/w1/devices/w1_bus_master1/" + d + "/w1_slave"
                th = Thermometer(deviceFile)
                self.append(th)

if __name__ == "__main__":
    d = TempDevices()
    while True:
        for t in d:
            if t.file.startswith("/sys/bus/w1/devices/w1_bus_master1/10"):
                tType = "DS18S20"
            else:
                tType = "DS18B20"
            print(tType, t.read(), "Grad Celsius")
    time.sleep(1)

