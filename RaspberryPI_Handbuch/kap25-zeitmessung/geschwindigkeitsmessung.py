#!/usr/bin/python3
# coding=utf-8
# Datei geschwindigkeitsmessung.py
import time, sys
import pigpio

pi = pigpio.pi() 
pi.set_mode(23, pigpio.INPUT) 
pi.set_mode(24, pigpio.INPUT) 
pi.set_pull_up_down(23, pigpio.PUD_UP)
pi.set_pull_up_down(24, pigpio.PUD_UP)

# Callback-Funktion zum Start der Stoppuhr
def start(pin,status,tick):
    global tick_start
    tick_start = tick
    print ("Start") 
    
# Callback-Funktion, um die Uhr zu stoppen
def ende (pin,status,tick_end):
    diff = (pigpio.tickDiff(tick_start, tick_end) * 10 ** (-6))
    print (diff, "Sekunden") 
    # 1000 = 1 m. Entspricht der Bahnlänge.
    v = (1000 / diff) * 0.0036 
    print (v, "km/h")
    return

# Start des Hauptprogramms
event_start = pi.callback(24, pigpio.FALLING_EDGE, start)  
event_ende = pi.callback(23, pigpio.FALLING_EDGE, ende)

try:
  while True:
    time.sleep(5)
except KeyboardInterrupt:
  pi.stop()
  sys.exit()
