#--------------------------------------------------------------
# Dateiname: knock.py
# Klopfzeichen erkennen
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 4. Auflage, mitp 2018
# Kap. 3.8
# Michael Weigend 20. September
#--------------------------------------------------------------

from RPi import GPIO
from time import sleep
GPIO.setwarnings(False)                              #1
GPIO.setmode(GPIO.BOARD)
GPIO.setup(8, GPIO.IN,
           pull_up_down=GPIO.PUD_DOWN)       # Schalter
GPIO.setup(10, GPIO.OUT)                     # LED
TIMEOUT = 3                                          #2
STEP = 0.01                                          #3
codes = [[1, 1, 1, 1],
    [1, 0, 0, 1, 2, 1],
    [1, 2, 1, 2, 1],
    [1, 1, 2, 0, 1, 0]]                              #4
GPIO.output(10, True)         # LED ausschalten
while True:
    knock = []
    while not GPIO.input(8):                         #5
        sleep(0.01)
    knocking = True
    while knocking:                                  #6
        t = 0
        while GPIO.input(8):                         #7
            sleep(STEP)
            t += STEP
        while not GPIO.input(8) and (t< TIMEOUT):
            sleep(STEP)                              #8
            t += STEP
        if t < TIMEOUT:                              #9
            knock.append(t)
        else:
            knocking = False
    if len(knock) > 0:                              #10
        a = knock[0]
        for i in range (len(knock)):
            knock[i] = round(knock[i] / a)          #11
        print('Klopfsignal:', knock)                #12
        if knock in codes:                          #13
            GPIO.output(10, False)
            sleep(3)
            GPIO.output(10, True)    
    
