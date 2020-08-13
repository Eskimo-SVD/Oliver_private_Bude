#!/usr/bin/python3
# coding=utf-8
# Datei auto.py, Teil 1
from time import sleep
import RPi.GPIO as GPIO
import sys
GPIO.setmode(GPIO.BOARD)

EnableA = 13
EnableB = 15
Input1 = 3
Input2 = 5
Input3 = 7
Input4 = 11

# die beiden Line-Follower (r)echts und (l)inks
lf_r=18
lf_l=22

GPIO.setup(EnableA,GPIO.OUT)
GPIO.setup(EnableB,GPIO.OUT)
GPIO.setup(Input1,GPIO.OUT)
GPIO.setup(Input2,GPIO.OUT)
GPIO.setup(Input3,GPIO.OUT)
GPIO.setup(Input4,GPIO.OUT)
GPIO.setup(lf_l, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
GPIO.setup(lf_r, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)

pwmA=GPIO.PWM(EnableA,100)
pwmB=GPIO.PWM(EnableB,100)

# Funktion zum Geradeausfahren
def vor():
        pwmA.start(90)
        GPIO.output(Input3, True)
        GPIO.output(Input4, False)
        
        pwmB.start(90)
        GPIO.output(Input1, True)
        GPIO.output(Input2, False)

# Funktion zum Linksabbiegen
def links():
        pwmA.start(90)
        GPIO.output(Input1, True)
        GPIO.output(Input2, False)
        
        pwmB.start(90)
        GPIO.output(Input3, False)
        GPIO.output(Input4, True)
        
# Funktion zum Rechtsabbiegen
def rechts():
        pwmB.start(90)
        GPIO.output(Input3, True)
        GPIO.output(Input4, False)
        
        pwmA.start(90)
        GPIO.output(Input1, False)
        GPIO.output(Input2, True)

# Datei auto.py, Teil 2
while True:
   try: 
     if GPIO.input(lf_l) == False and GPIO.input(lf_r) == True:
        rechts()


     elif GPIO.input(lf_r) == False and GPIO.input(lf_l) == True:
        links()
     else:
        vor()
     sleep(0.01)

   except KeyboardInterrupt:
     GPIO.cleanup()
     sys.exit()