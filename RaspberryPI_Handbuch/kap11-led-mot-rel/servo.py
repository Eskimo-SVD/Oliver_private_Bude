#!/usr/bin/python3
# -*- coding: utf-8 -*
# servo.py

import time
import pigpio
import sys

servo = 3
pos = sys.argv[1] #  1000 bis 2000
pi = pigpio.pi()  # Verbindung zum pigpio-Dämon

pi.set_mode(servo, pigpio.OUTPUT)
pi.set_servo_pulsewidth(servo, pos) 
time.sleep(5)
pi.set_servo_pulsewidth(servo, 0) 
pi.stop()