#!/usr/bin/env python3

from gpiozero import Button
from signal import pause
import os

def hat_geklingelt():
 #hier können beliebige Aktionen
 #ausgeloest werden, wenn es an 
 #der Tuer geklingelt hat
 os.system("/usr/local/shellscripts/klingel.sh")

button = Button(21, bounce_time=2)

button.when_pressed = hat_geklingelt
pause()

