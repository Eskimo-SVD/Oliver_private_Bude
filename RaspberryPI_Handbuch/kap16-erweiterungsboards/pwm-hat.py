#!/usr/bin/python3
# Datei pwm-hat.py
import Adafruit_PCA9685
import time

pwm = Adafruit_PCA9685.PCA9685()
pwm.set_pwm_freq(60) # 60 Hz
pwm.set_pwm(15, 0, 410) # 10 % Duty Cycle
pwm.set_pwm(8, 0, 1024) # 25 % Duty Cycle
pwm.set_pwm(4, 0, 2048) # 50 % Duty Cycle
time.sleep(2)
pwm.set_all_pwm(0, 0)