#!/usr/bin/python3
import spidev
import time
import RPi.GPIO as GPIO
ce = 5
GPIO.setmode(GPIO.BOARD)
GPIO.setup(ce, GPIO.OUT)
spi = spidev.SpiDev()
spi.open(0, 0)
GPIO.output(ce, True)
GPIO.output(ce, False)
spi.writebytes([0b00110001, 0b00000000])
GPIO.output(ce, True)