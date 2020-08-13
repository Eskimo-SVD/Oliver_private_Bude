#!/usr/bin/python3
import RPi.GPIO as gpio
import time

# Pin-Nummern verwenden (nicht GPIO-Nummern)
gpio.setmode(gpio.BOARD)

# Pin 26 (= GPIO 7) zur Datenausgabe verwenden
gpio.setup(26, gpio.OUT)

# LED über Pin 26 zehnmal ein- und ausschalten
for i in range(1, 10):
    print("LED ein")
    gpio.output(26, gpio.HIGH)
    time.sleep(1)
    print("LED aus")
    gpio.output(26, gpio.LOW)
    time.sleep(1)

# alle vom Script benutzten GPIOs/Pins wieder freigeben
gpio.cleanup()
