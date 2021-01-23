#! /usr/bin/python3
#----------------------------------------------------------------
# Dateiname: move_pixel.py
# Der RPi trägt einen SenseHat.
# Mit dem Joystick kann ein Pixel bewegt werden.
#  
# Michael Weigend
# Raspberry Pi programmieren mit Python, 4. Auflage, mitp 2019
# Kap. 12
# Michael Weigend 20. November 2018
#----------------------------------------------------------------
import sense_hat
from time import sleep

def move_up(event):
    global y
    if event.action != "released":
        y = (y - 1) % 8

def move_down(event):
    global y
    if event.action != "released":
        y = (y + 1) % 8


def move_left(event):
    global x
    if event.action != "released":
        x = (x - 1) % 8

def move_right(event):
    global x
    if event.action != "released":
        x = (x + 1) % 8

def refresh():
    sh.clear()
    sh.set_pixel(x, y, (255, 0, 0))


x = y = 0
sh = sense_hat.SenseHat()
refresh()
sh.stick.direction_any = refresh
sh.stick.direction_up = move_up
sh.stick.direction_down = move_down
sh.stick.direction_left = move_left
sh.stick.direction_right = move_right
                 
