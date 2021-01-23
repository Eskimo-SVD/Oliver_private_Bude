#----------------------------------------------------------------
# Dateiname: thermCollect.py
# Darstellung von Temperatur-Zeit-DiagrammenTemperaturdaten sammeln
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 9.6
# Michael Weigend 20. April 2016
#--------------------------------------------------------------
import time, pickle
from temperature import TempDevices
from tkinter import *
from RPi import GPIO

DATAFILE = "data.dat"

class Switch:
    def __init__(self, pin):
        GPIO.setup(pin, GPIO.IN,pull_up_down=GPIO.PUD_DOWN)
        self.pin = pin

    def waitUntilClicked(self):
        while not GPIO.input(self.pin):
            time.sleep(0.05)
        while GPIO.input(self.pin):
            time.sleep(0.05)
        time.sleep(0.2)
            
    def isPressed(self):
        return GPIO.input(self.pin)
        

class LED:
    def __init__(self, pin):
        GPIO.setup(pin, GPIO.OUT)
        self.pin = pin 

    def on(self):
        GPIO.output(self.pin, False)

    def off(self):
        GPIO.output(self.pin, True)


class Collector:
    def __init__(self):
        GPIO.setmode(GPIO.BOARD)
        self.s = Switch(8)
        self.led = LED(10)
        self.t = TempDevices()[0]
        self.data = []
        self.run()



    def run(self):
        self.s.waitUntilClicked()
        self.led.on()
        while not self.s.isPressed():
            self.data.append(self.t.read())
            time.sleep(0.1)
        self.led.off()
        f = open(DATAFILE, "wb")
        pickle.dump(self.data, f)
        f.close()
                 
Collector()
