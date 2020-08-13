#!/usr/bin/python3
# Beispieldatei gpiozero-led-pwm.py
from gpiozero import PWMLED
import sys, time
myled = PWMLED(7, frequency=1000)  # BCM-Nummer 7 = Pin 26 des J8-Header
                                   # Frequenz: 1000 Hz

print("LED wird langsam heller")
myled.value=0
myled.on()
for brightness in range(1, 11):
  myled.value = brightness / 10.0  
  time.sleep(0.5)

print("LED blinkt zehn Mal")
myled.blink(on_time=0.5, off_time=0.25, n=10, background=False)

print("Kurze Pause")
time.sleep(1)

print("LED blinkt dreimal langsam, halbe Helligkeit")
myled.value=0.1
myled.blink(on_time=1, off_time=1, n=3, background=False)

print("LED aus und Programmende")
myled.off()
