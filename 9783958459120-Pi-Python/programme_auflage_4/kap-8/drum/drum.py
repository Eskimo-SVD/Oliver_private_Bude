#----------------------------------------------------------------
# Dateiname: drum.pyw
# Modul mit Klasse Drum zur Simulation eines Schlagzeugs
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 8, Aufgabe 2
# Michael Weigend 20. April 2016
#--------------------------------------------------------------
from RPi import GPIO
from time import sleep

GPIO.setmode(GPIO.BOARD)
BEAT = 0.1    # Länge eines Schlages in Sekunden
PIN = 10      # Pinnummer des GPIO 

class Drum:
    def __init__ (self, bpm):
        GPIO.setup(PIN, GPIO.OUT)
        GPIO.output(PIN, True)
        self.time = 60 / bpm                  
        self.running = False

    def play(self, pattern):
        self.running = True
        while self.running:
            for note  in  pattern:
               if note:
                   GPIO.output(PIN, False)
                   sleep(BEAT)
                   GPIO.output(PIN, True)
                   sleep(self.time * note - BEAT)

    def stop(self):
        self.running = False
            

        
        
        
        
    
