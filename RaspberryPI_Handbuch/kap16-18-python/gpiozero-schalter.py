#!/usr/bin/python3
# Beispieldatei gpiozero-schalter.py
from gpiozero import LED, Button
import datetime, time
lastTime=datetime.datetime.now()

# BCM-Nummer 7 = Pin 26 des J8-Header
myled = LED(7)        

# BCM-Nummer 9 = Pin 21 des J8-Header
# mit Pull-up-Widerstand
mybutton = Button(9, pull_up=True)  

print("Taste drücken zum Einschalten")
mybutton.wait_for_press()
myled.on()
time.sleep(1)

print("Taste nochmals drücken zum Ausschalten")
mybutton.wait_for_press()
myled.off()

def ledOnOff():
  global myled, lastTime
  now = datetime.datetime.now()
  if now-lastTime > datetime.timedelta(microseconds=250000):
    myled.toggle()
    lastTime = now

print("Jetzt können Sie die LED zehn Sekunden lang ein- und ausschalten")  
mybutton.when_pressed = ledOnOff
time.sleep(10)

print("LED aus und Programmende")
myled.off()


