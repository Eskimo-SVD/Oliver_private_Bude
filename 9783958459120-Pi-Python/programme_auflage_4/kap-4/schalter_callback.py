#----------------------------------------------------
# Dateiname:  schalter_callback.py 
# Wird der Schalter gedrückt, wird eine Callback-Funktion
# aufgerufen.
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 4
# Michael Weigend 20. April 2016
#--------------------------------------------------------------
from RPi import GPIO
GPIO.setmode(GPIO.BOARD)
GPIO.setup(10, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)   #1

def print_record(channel):                            #2
    print('Schalter 1 gedrückt.')

GPIO.add_event_detect(10, GPIO.RISING,
                     callback=print_record,
                     bouncetime=300)                  #3
while True:
    pass                                              #4
        
