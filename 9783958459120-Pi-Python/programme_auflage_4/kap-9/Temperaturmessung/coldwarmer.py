#--------------------------------------------------------------
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 9
# Michael Weigend 20. April 2016
#--------------------------------------------------------------
import time, pickle
from temperature import TempDevices
from RPi import GPIO       

class LED:
    def __init__(self, pin):
        GPIO.setup(pin, GPIO.OUT)
        self.pin = pin 

    def on(self):
        GPIO.output(self.pin, False)

    def off(self):
        GPIO.output(self.pin, True)


class Search:
    def __init__(self):
        GPIO.setmode(GPIO.BOARD)
        self.red = LED(8)
        self.green = LED(10)
        self.t = TempDevices()[0]
        self.oldTemp = self.t.read()
        self.run()

    def run(self):
        while True:
           newTemp =  self.t.read()
           if newTemp < self.oldTemp:
               self.green.on()
               self.red.off()
           elif newTemp > self.oldTemp:
               self.green.off()
               self.red.on()
           else:
               self.green.off()
               self.red.off()
           self.oldTemp = newTemp
 
Search()
