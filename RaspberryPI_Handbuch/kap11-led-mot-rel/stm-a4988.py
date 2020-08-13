#!/usr/bin/python3
# -*- coding: utf-8 -*
# Teil 1

from time import sleep
import RPi.GPIO as GPIO
GPIO.setmode(GPIO.BOARD)
step = 5
dir = 7
enable = 3

GPIO.setmode(GPIO.BOARD)
GPIO.setup(step,GPIO.OUT)
GPIO.setup(dir,GPIO.OUT)
GPIO.setup(enable,GPIO.OUT)

GPIO.output(step, False)
GPIO.output(dir, True)
GPIO.output(enable, True)

# Fortsetzung, Teil 2
# Funktion zur A4988-Steuerung
def turn(speed, steps, direction):   
    if direction == 1:
        GPIO.output(dir, True)
    else:
        GPIO.output(dir, False)

    GPIO.output(enable, False)
    for i in range(0,steps):        
        GPIO.output(step, True) 
        sleep (speed)      
        GPIO.output(step, False)
        
    GPIO.output(enable, True)           
    return

turn(0.005,200,1)
GPIO.cleanup()
