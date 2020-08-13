#!/usr/bin/python3

from RPi_AS3935 import RPi_AS3935
import RPi.GPIO as GPIO
import time
import os
from datetime import datetime
 
GPIO.setmode(GPIO.BCM)
 
sensor = RPi_AS3935(address=0x03, bus=1)
sensor.reset()
sensor.set_indoors(True)
sensor.set_noise_floor(0)
sensor.calibrate(tun_cap=0x07)
sensor.set_disp_lco(False)

def handle_interrupt(channel):
  now = datetime.now().strftime('%H:%M:%S - %Y/%m/%d')
  time.sleep(0.004)
  global sensor
  reason = sensor.get_interrupt()
  if reason == 0x01:
    noise = sensor.raise_noise_floor()
    print(now + ": Noise level too high,")
    print("adjusting to level %s") % noise
    f = open("/var/log/noise.log","a+")
    f.write(now + ": Noise level too high,")
    f.write(("adjusting to level %s") % noise + "\n")
    f.close()
  elif reason == 0x04:
    print (now + ": Disturber detected - masking")
    f = open("/var/log/lightning.log","a+")
    f.write(now + ": Disturber detected - masking\n")
    f.close()
    sensor.set_mask_disturber(True)
  elif reason == 0x08:
    distance = sensor.get_distance()
    print("lightning detected, distance: %s km at %s" \
          % (str(distance), now))
    f = open("/var/log/lightning.log","a+")
    f.write("lightning detected, distance: %s km at %s" \
            % (str(distance), now) + "\n")
    f.close()
 
pin = 17
GPIO.setup(pin, GPIO.IN)
GPIO.add_event_detect(pin, GPIO.RISING, 
                      callback=handle_interrupt)
 
print("Waiting for lightning - or at")
print("least something that looks like it")
counter = 0
while True:
  now = datetime.now().strftime('%H:%M:%S - %Y/%m/%d')
  noise = sensor.get_noise_floor()
  # uncomment for information about noise level
  # print("noise floor: %s") % (noise)
  # f = open("/var/log/noise.log","a+")
  # f.write("noise floor: %s" % (noise) + "\n")
  # f.close()
   
  # every 60s, we try to decrease the noise floor
  if counter > 10:
    if noise > 0:
      noise = sensor.lower_noise_floor()
      sensor.calibrate(tun_cap=0x07)
      print(now + ": Noise floor reduced to: %s") \
            % noise
      f = open("/var/log/noise.log","a+")
      f.write((now + ": Noise floor reduced to: %s") \
              % noise + "\n") 
      f.close()
      counter = 0
   
  counter = counter + 1
  time.sleep(5.0)
