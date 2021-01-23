#----------------------------------------------------
# Dateiname:  verkehr.py 
# Verkehrszählung
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 4
# Michael Weigend 20. April 2016
#--------------------------------------------------------------
from RPi import GPIO
from os import system
GPIO.setmode(GPIO.BOARD)

cars = 0                                              #1
trucks = 0

for pin in [8, 10, 12]:                               #2
    GPIO.setup(pin, GPIO.IN, pull_up_down=GPIO.PUD_DOWN) 

def finish(channel):
    print ('Auf Wiedersehen.')
    GPIO.cleanup()                                    #3
    exit()

def count_vehicle(channel):
    # Zählen
    global cars, trucks                               #4
    if channel == 10:                                 #5
       cars += 1
    elif channel == 12: 
       trucks += 1
    print(cars, 'PKW und', trucks, 'LKW.')            #6

GPIO.add_event_detect(8, GPIO.RISING,
                  callback=finish, bouncetime=300)
GPIO.add_event_detect(10, GPIO.RISING,
            callback=count_vehicle, bouncetime=300)   #7
GPIO.add_event_detect(12, GPIO.RISING, 
            callback=count_vehicle, bouncetime=300)   

while True:
    pass

    
    
    
        
