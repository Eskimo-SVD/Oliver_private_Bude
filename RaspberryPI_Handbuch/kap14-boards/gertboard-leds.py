#!/usr/bin/python3
import RPi.GPIO as GPIO
from time import sleep

GPIO.setmode(GPIO.BCM)
GPIO.setup(17, GPIO.IN, pull_up_down=GPIO.PUD_UP) 
GPIO.setup(22, GPIO.OUT) 

while True:
    if not GPIO.input(17):
        GPIO.output(22, True)
    else:
        GPIO.output(22, False)
    sleep (0.1)