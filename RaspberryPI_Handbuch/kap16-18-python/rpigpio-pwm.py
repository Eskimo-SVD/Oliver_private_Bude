#!/usr/bin/python3

import RPi.GPIO as gpio, sys, time

# Initialisierung
pinLed = 26
gpio.setmode(gpio.BOARD)      # P1-Pin-Nummern
gpio.setup(pinLed, gpio.OUT)
gpio.output(pinLed, 0)        # LED aus

try:
  print("Frequenz: 2 Hertz, Duty: 50%")
  pwm = gpio.PWM(pinLed, 2)   # Frequenz: 2 Hertz
  pwm.start(50)               # Duty: 50%
  time.sleep(5)
  
  print("Frequenz: 0,5 Hertz, Duty: 10%")
  pwm.ChangeFrequency(0.5)    # Frequenz: 0,5 Hertz
  pwm.ChangeDutyCycle(10)     # Duty: 10%
  time.sleep(5)
finally:
  pwm.stop()
  print("Ende, LED aus")
  gpio.output(pinLed, 0)
  gpio.cleanup()
