#!/usr/bin/python3
import RPi.GPIO as GPIO
import time
mota = 17
motb = 18
b1 = 23
b2 = 24
GPIO.setmode(GPIO.BCM)
GPIO.setup(b1, GPIO.IN, pull_up_down=GPIO.PUD_UP)
GPIO.setup(b2, GPIO.IN, pull_up_down=GPIO.PUD_UP)
GPIO.setup(mota, GPIO.OUT)
GPIO.setup(motb, GPIO.OUT)

def mot_v( pin ):
    if GPIO.input(pin) == False:
        GPIO.output(mota, GPIO.HIGH)
        GPIO.output(motb, GPIO.LOW)    
    else:
        GPIO.output(mota, GPIO.LOW)
        GPIO.output(motb, GPIO.LOW)          
    return

def mot_z( pin ):    
    if GPIO.input(pin) == False:
        GPIO.output(mota, GPIO.LOW)
        GPIO.output(motb, GPIO.HIGH)    
    else:
        GPIO.output(mota, GPIO.LOW)
        GPIO.output(motb, GPIO.LOW)          

GPIO.add_event_detect(b1, GPIO.BOTH, bouncetime=50)
GPIO.add_event_callback(b1, mot_v)    
    
GPIO.add_event_detect(b2, GPIO.BOTH, bouncetime=50)
GPIO.add_event_callback(b2, mot_z)

try:
  while True:
    time.sleep(5)
except KeyboardInterrupt:
  GPIO.cleanup()
  sys.exit()