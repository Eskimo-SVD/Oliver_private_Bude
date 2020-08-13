#!/usr/bin/python3
# -*- coding: utf-8 -*-
from time import sleep
import RPi.GPIO as GPIO

# Physikalische Bezeichnung der Pins nutzen
GPIO.setmode(GPIO.BOARD)   
                     
GPIO.setup(26,GPIO.OUT) 

# PWM-Instanz erstellen fur Pin 26 mit Frequenz 100 Hz
pwm=GPIO.PWM(26,100)
  
# PWM starten mit Duty Cyle von 50 Prozent
pwm.start(50) 

# Manuelle Eingabe des Duty Cycle in Dauerschleife
while True:
    dc= input ("DC eingeben von 0 bis 100: ")   
    pwm.ChangeDutyCycle(int(dc))

    
GPIO.cleanup