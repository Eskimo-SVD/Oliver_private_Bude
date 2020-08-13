#!/usr/bin/env python3
# Datei finger-test.py
from finger import *
import RPi.GPIO as GPIO
GPIO.setmode(GPIO.BOARD)
GPIO.setup(11, GPIO.OUT)

# nur Eingabe 1, 2 oder 3 erlaubt
auswahl = int(input ('1 = Neuer Fingerabdruck\n' +
                     '2 = Zugriff geschützte Funktion\n' +
                     '3 = Fingerabdruck löschen\n'))
if auswahl == 1:
	FingerNeu()

if auswahl == 2: 
	Zugriff=FingerAbfrage()	
	# geschützter Programmteil, z. B. Schloss entriegeln
	if Zugriff == 1:
		GPIO.output(11, True)
		time.sleep(5)
		GPIO.output(11, False)
	# Ende des geschützten Bereichs
	
if auswahl == 3:
	FingerEntfernen()