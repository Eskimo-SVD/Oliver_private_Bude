#!/usr/bin/python3
import spidev
import time
import RPi.GPIO as GPIO
spi = spidev.SpiDev()
spi.open(0,1)
spi.xfer([0x00, 0x80])