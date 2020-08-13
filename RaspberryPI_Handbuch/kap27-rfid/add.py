#!/usr/bin/python3
# Datei add.py
import RPi.GPIO as GPIO
from functions import *
db = DB()
print("Neuer Zugangsberechtigter\n")
print("Transponder einlesen...\n")
id = read_rfid()
name = input("Name eingeben: ")
try:
    db.add_user(id,name)
    print ("Neuer Datensatz angelegt")
except:
    print ("Fehler beim Schreiben")  
    
db.close_db()