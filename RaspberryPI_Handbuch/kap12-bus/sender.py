#!/usr/bin/python3
import serial
ser = serial.Serial("/dev/ttyAMA0")
ser.baudrate = 9600

print("Sende UART Daten...")
ser.write(b"Hallo Welt!\n")
ser.close()