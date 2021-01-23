#----------------------------------------------------
# Dateiname:  gong.py 
# Türgong
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 3.5.4
# Michael Weigend 20. April 2016
#--------------------------------------------------------------

from RPi import GPIO
from os import system
SOUND = '/opt/sonic-pi/etc/samples/drum_cymbal_open.wav'
GPIO.setmode(GPIO.BOARD)
GPIO.setup(10, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)

def play_sound(channel):
    system('aplay ' + SOUND)                      #1

GPIO.add_event_detect(10, GPIO.RISING,
                     callback=play_sound,
                     bouncetime=3000)             #2

while True:
    pass

    
    
    
        
