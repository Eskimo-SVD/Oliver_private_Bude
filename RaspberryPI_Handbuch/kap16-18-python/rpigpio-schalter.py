#!/usr/bin/python3
import RPi.GPIO as gpio, time, datetime
  
# Pins
pinLed = 26
pinButton = 21
ledStatus = 0  # LED anfänglich aus

# Initialisierung
gpio.setmode(gpio.BOARD)      # P1-Pin-Nummern
gpio.setup(pinLed, gpio.OUT)
gpio.setup(pinButton, gpio.IN)
gpio.output(pinLed, ledStatus)
lastTime=datetime.datetime.now()

# Callback-Funktion, wenn Taster gedrückt wird
def myCallback(n):
  global lastTime, ledStatus
  now = datetime.datetime.now()
  # 500 ms Entprellzeit
  if now-lastTime > datetime.timedelta(microseconds=500000):
      print('Der Taster wurde gedrückt.')
      lastTime=datetime.datetime.now()
      ledStatus = not ledStatus
      gpio.output(pinLed, ledStatus)

# Callbacks einrichten 
gpio.add_event_detect(21, gpio.FALLING)
gpio.add_event_callback(21, myCallback)

# jetzt läuft alles automatisch
print("Das Script endet in 20 Sekunden automatisch.")
time.sleep(20)
gpio.cleanup()
