#!/usr/bin/python3
import pifacedigitalio as pf
import sys, time
pf.init()
pfc = pf.PiFaceDigital()

def an(event):
    pf.digital_write(0, 1)

def aus(event):
    pf.digital_write(0,0)
       
listener = pf.InputEventListener(chip=pfc)  
listener.register(0, pf.IODIR_FALLING_EDGE, an)
listener.register(3, pf.IODIR_RISING_EDGE, aus)
listener.activate()

try:
    while True:
        time.sleep(5)
except KeyboardInterrupt:
    listener.deactivate()
    sys.exit()
