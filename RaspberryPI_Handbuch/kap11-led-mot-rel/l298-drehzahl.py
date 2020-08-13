#!/usr/bin/python3
# -*- coding: utf-8 -*
# Teil 1 des Codes

from time import sleep
import RPi.GPIO as GPIO
GPIO.setmode(GPIO.BOARD)

# Funktion, um alle genutzten Pins auf Low zu schalten
def all_off():                                                                  
    GPIO.output(EnableA, False)
    GPIO.output(EnableB,False)
    GPIO.output(Input1,False)
    GPIO.output(Input2,False)
    GPIO.output(Input3,False)
    GPIO.output(Input4,False)
    return

# Den GPIO-Pins werden die Namen der L298-Eingänge zugewiesen.
EnableA = 13                                                                    
EnableB = 15
Input1 = 3
Input2 = 5
Input3 = 7
Input4 = 11

# Alle genutzten GPIO-Pins als Ausgang deklarieren.
GPIO.setup(EnableA,GPIO.OUT)                                                    
GPIO.setup(EnableB,GPIO.OUT)
GPIO.setup(Input1,GPIO.OUT)
GPIO.setup(Input2,GPIO.OUT)
GPIO.setup(Input3,GPIO.OUT)
GPIO.setup(Input4,GPIO.OUT)

# Funktion "all_off" aufrufen
all_off()                                                                       

# Teil 2 des Codes für Drehzahländerung

# PWM-Signal auf Pins 13 und 15 mit 100 Hz
pwmA=GPIO.PWM(EnableA,100)    
pwmB=GPIO.PWM(EnableB,100)   

try:
  while True:
    # Eingabefeld zur Motorauswahl
    motor = input ("Wählen Sie den Motor: 'A' oder 'B': ")                
    
    # Eingabefeld zur Richtungsauswahl
    richtung = 
      input ("Wählen Sie die Drehrichtung: 'V' oder 'Z': ") 
    
    # Duty Cycle eingeben
    geschwindigkeit = 
      input ("Wählen Sie die Geschwindigkeit: '1 - 100': ")

    if motor == "A" and richtung == "V":                                        
        # PWM starten mit 100 Hz und dem eingegebenen Duty Cycle
        pwmA.start(float(geschwindigkeit))                                      
        GPIO.output(Input1, True)
        GPIO.output(Input2, False)
        sleep (5) 
        GPIO.output(EnableA, False)
        GPIO.output(Input1, False)
    
    if motor == "A" and richtung == "Z":        
        pwmA.start(float(geschwindigkeit)) 
        GPIO.output(Input1, False)
        GPIO.output(Input2, True)
        sleep (5)   
        GPIO.output(EnableA, False)
        GPIO.output(Input2, False)
    
    if motor == "B" and richtung == "V":        
        pwmB.start(float(geschwindigkeit))  
        GPIO.output(Input3, True)
        GPIO.output(Input4, False)
        sleep (5)
        GPIO.output(EnableB, False)
        GPIO.output(Input3, False)

    
    if motor == "B" and richtung == "Z":        
        pwmB.start(float(geschwindigkeit)) 
        GPIO.output(Input3, False)
        GPIO.output(Input4, True)
        sleep (5)
        GPIO.output(EnableB, False)
        GPIO.output(Input4, False)   

# Beim Beenden des Programms durch Strg+C wird 
# all_off() ausgeführt.
except KeyboardInterrupt:                                                       
    all_off()