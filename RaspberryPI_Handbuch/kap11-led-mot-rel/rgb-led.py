#!/usr/bin/python3
# -*- coding: utf-8 -*-
from time import sleep
import RPi.GPIO as GPIO
GPIO.setmode(GPIO.BOARD)

# GPIO-Pins mit entsprechender LED-Farbe
rot = 3                         
gruen = 5
blau = 7
GPIO.setup(gruen, GPIO.OUT)
GPIO.setup(blau, GPIO.OUT)
GPIO.setup(rot, GPIO.OUT)

# Funktion, um alle genutzten Pins auf Low zu schalten
def all_off():                 
    GPIO.output(rot,False)
    GPIO.output(gruen,False)
    GPIO.output(blau,False)
    return

# Modusauswahl
auswahl = eval(input ("[1] Mischen    [2] Auto \n"))   

# PWM festlegen mit Frequenz 100Hz
pwm_g=GPIO.PWM(gruen,100)                            
pwm_b=GPIO.PWM(blau,100) 
pwm_r=GPIO.PWM(rot,100) 

# PWM starten mit Frequenz 0 % Duty Cycle
pwm_g.start(0)                                                                  
pwm_b.start(0) 
pwm_r.start(0)

try:
    if auswahl == 1:
        while True:
            # Werte von 0-100 zulässig
            dcr= eval(input("Rotanteil [0-100]: \n" ))                            
            dcb= eval(input("Blauanteil [0-100]: \n"))
            dcg= eval(input("Gruenanteil [0-100]: \n"))

            # Duty Cycle entsprechend der Eingabe ändern
            pwm_g.ChangeDutyCycle(dcg)                                          
            pwm_b.ChangeDutyCycle(dcb)
            pwm_r.ChangeDutyCycle(dcr)

#Farbwechsel bei Modus "Auto"
    if auswahl == 2:                                                          
        while True:
            for i in range(100):
                pwm_g.ChangeDutyCycle(i)
                sleep (0.05)
                if i == 99:
                    for i in xrange(100, 0, -1):
                        sleep (0.05)
                        pwm_g.ChangeDutyCycle(i)
                
            for i in range(100):    
                pwm_b.ChangeDutyCycle(i)
                sleep (0.05)
                if i == 99:
                    for i in xrange (100,0,-1):
                        sleep (0.05)
                        pwm_b.ChangeDutyCycle(i)

            for i in range(100):
                pwm_r.ChangeDutyCycle(i)
                sleep (0.005)
                if i == 99:
                    for i in xrange(100, 0, -1):
                        sleep (0.05)
                        pwm_r.ChangeDutyCycle(i)
                    
except KeyboardInterrupt:
    all_off()
