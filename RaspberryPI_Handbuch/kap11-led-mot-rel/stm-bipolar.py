#!/usr/bin/python3
# -*- coding: utf-8 -*-
# Teil 1

from time import sleep
import RPi.GPIO as GPIO
GPIO.setmode(GPIO.BOARD)

# verwendete Pins am Raspberry Pi
EnableA = 13                            
EnableB = 15
a1 = 3
a2 = 5
b1 = 7
b2 = 11
# Pause zwischen den Schritten (beliebig veränderbar)
time = 0.005
# alle genutzten GPIO-Pins als Ausgang deklarieren
GPIO.setup(EnableA,GPIO.OUT)            
GPIO.setup(EnableB,GPIO.OUT)
GPIO.setup(a1,GPIO.OUT)
GPIO.setup(a2,GPIO.OUT)
GPIO.setup(b1,GPIO.OUT)
GPIO.setup(b2,GPIO.OUT)
GPIO.output(EnableA, True) 
GPIO.output(EnableB, True)
  
# Fortsetzung / Teil 2
z = 0
schritte = 0

# Sequenz für Vollschritt
steps1 = []
steps1 = list(range(0,4))
steps1[0] = [a1,b1]
steps1[1] = [a1,b2]
steps1[2] = [a2,b2]
steps1[3] = [a2,b1]
zaehler1 = 4
# Sequenz für Halbschritt
steps2 = []
steps2 = list(range(0,8))
steps2[0] = [a1,b1]
steps2[1] = [a1,0]
steps2[2] = [a1,b2]
steps2[3] = [b2,0]
steps2[4] = [a2,b2]
steps2[5] = [a2,0]
steps2[6] = [a2,b1]
steps2[7] = [b1,0]
zaehler2 = 8

# Fortsetzung / Teil 3
# Sequenzauswahl
Auswahl =  eval(input("Druecken Sie [1] = Vollschritt  [2] = Halbschritt: "))

if Auswahl == 1:
    steps = steps1
    zaehler = zaehler1
if Auswahl == 2:
    steps = steps2
    zaehler = zaehler2

# Schleife zum Durchlaufen der Sequenzen
while schritte < (zaehler * 50) :
    for i in range (0,zaehler):
        if (z == zaehler):
            z = 0

        GPIO.output(steps[z][0], True)
        if steps[z][1] != 0:
            GPIO.output(steps[z][1], True)
        sleep(time)
        GPIO.output(steps[z][0], False)
        if steps[z][1] != 0:
            GPIO.output(steps[z][1], False)
        schritte +=1
        print (z)
        z += 1
        print ("Aktueller Schritt: ", schritte)

GPIO.output(EnableA, False) 
GPIO.output(EnableB, False)
