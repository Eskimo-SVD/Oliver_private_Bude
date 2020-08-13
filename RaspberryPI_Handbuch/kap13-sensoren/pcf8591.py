#!/usr/bin/python3
# Datei pcf8591.py
import smbus
import time
bus = smbus.SMBus(1)
adresse = 0x48

def read(control):
    write = bus.write_byte_data(adresse, control, 0)
    read = bus.read_byte(adresse)
    return read

while True:
    poti = read(0x40) 
    licht = read(0x41)
    temp = read (0x42)     
    ain2 = read (0x43)   
    print("Temperatur: ", temp, "Licht: ", licht, "Spannung-Poti: ", poti)
    time.sleep (0.5)