#!/usr/bin/python3
import pifacedigitalio as pf
from time import sleep

pf.init()
while True:
    if pf.digital_read(0):
        pf.digital_write(0, 1)
    else:
        pf.digital_write(0, 0)
    sleep(0.1)