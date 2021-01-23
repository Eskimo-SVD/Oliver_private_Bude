#----------------------------------------------------
# Dateiname:  morsen.py 
# Morsen durch Ein- und Ausschalten einer LED.
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 4
# Michael Weigend 20. April 2016
#--------------------------------------------------------------
from RPi import GPIO
from time import sleep
PIN = 10
DIT = 0.2


def initGPIO():
    # Initiali
    GPIO.setmode(GPIO.BOARD)
    GPIO.setup(PIN, GPIO.OUT)
    GPIO.output(PIN, True)

def blink (länge):
    # Das Argument länge ist ein Zeitintervall (float).
    # Die LED wid für diese Zeit zum Leuchten gebracht
    # Danach kommt eine kurze Pause der Länge DIT
    GPIO.output(PIN, False)
    sleep(länge)
    GPIO.output(PIN, True)
    sleep(DIT)
    

def morsen(text):
    # Das Argument text st ein String aus Punkten,
    # Strichen und Leerzeichen. Diese Morsesymbole
    # werden durch kurze und lange Lichtzeichen bzw.
    # eine Pause dargestellt
    for zeichen in text:
        if zeichen == ".":
            blink(DIT)
        elif zeichen == "-":
            blink(3*DIT)  
        else:
            sleep(3*DIT)
    
# Hauptprogramm
initGPIO()
text = input("Morsezeichen: ")
while text:
    morsen(text)
    text = input("Morsezeichen: ")
