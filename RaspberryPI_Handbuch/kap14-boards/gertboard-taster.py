#!/usr/bin/python3
import RPi.GPIO as GPIO
from time import sleep

GPIO.setmode(GPIO.BCM)
GPIO.setup(17, GPIO.IN, pull_up_down=GPIO.PUD_UP) 
GPIO.setup(27, GPIO.IN, pull_up_down=GPIO.PUD_UP) 
GPIO.setup(22, GPIO.IN, pull_up_down=GPIO.PUD_UP) 

while True:
    if not GPIO.input(17):
        print("S1")
        sleep(0.5)
    elif not GPIO.input(27):
        print("S2")
        sleep(0.5)
    elif not GPIO.input(22):
        print("S3")
        sleep(0.5)