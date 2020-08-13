#!/usr/bin/python3
import spidev
import time
import RPi.GPIO as GPIO

ce = 7
GPIO.setmode(GPIO.BCM)
GPIO.setup(ce, GPIO.OUT)
spi = spidev.SpiDev()
spi.open(0,1)

GPIO.output(ce, True)
GPIO.output(ce, False)
spi.writebytes([0b10110001, 0b00000000])
GPIO.output(ce, True)