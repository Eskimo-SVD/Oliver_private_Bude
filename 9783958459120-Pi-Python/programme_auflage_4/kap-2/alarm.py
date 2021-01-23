#----------------------------------------------------
# Dateiname:  alarm.py 
# Alarmanlage
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 2
# Michael Weigend 20. April 2016
#----------------------------------------------------
from RPi import GPIO
from time import sleep, asctime
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)
GPIO.setup(10, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)   #1
GPIO.setup(12, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
GPIO.setup(16, GPIO.OUT)
GPIO.output(16, True)                                 #2
sleep(10)
while True:
    sleep(1)
    if GPIO.input(10)and not GPIO.input(12):          #3
       print('Fenster oder Tür geöffnet:', asctime()) #4
       sleep(5)                                       #5
       if GPIO.input(10):                             #6
            print('Alarm', asctime())
            GPIO.output(16, False)                    #7
            GPIO.wait_for_edge(10, GPIO.FALLING)      #8
            GPIO.output(16, True)                     #9

        
