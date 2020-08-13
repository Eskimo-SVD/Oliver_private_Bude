#!/usr/bin/python3
import serial
ser = serial.Serial("/dev/ttyAMA0", timeout = 10)
ser.baudrate = 9600
daten = ser.readline()
print(daten.decode('utf8'))
ser.close()