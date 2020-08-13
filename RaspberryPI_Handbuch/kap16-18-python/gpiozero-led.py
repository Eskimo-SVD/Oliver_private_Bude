#!/usr/bin/python3
# Beispieldatei gpiozero-led.py
from gpiozero import LED
import time
myled = LED(7)  # BCM-Nummer 7 = Pin 26 des J8-Header
print("LED ein")
myled.on()
time.sleep(1)
print("LED aus und Programmende")
myled.off()
