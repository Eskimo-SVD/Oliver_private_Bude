#!/usr/bin/python3
# Datei servo-hat.py

import Adafruit_PCA9685
import time

pwm = Adafruit_PCA9685.PCA9685()
servoMin = 150
servoMax = 600
pwm.set_pwm_freq(60)

while (True):
  pwm.set_pwm(5, 0, servoMin)  # Minimale Endlage
  time.sleep(1)
  pwm.set_pwm(5, 0, servoMax)  # Maximale Endlage
  time.sleep(1)