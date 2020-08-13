#!/usr/bin/env python3
# Datei: PaperDisplay.py

from papirus import Papirus
import subprocess
import RPi.GPIO as GPIO
import time
import socket
from PIL import Image
from PIL import ImageFont
from PIL import ImageDraw

# Tastenbelegung (BCM)
SW1 = 21
SW2 = 16
SW3 = 20
SW4 = 19
SW5 = 26

# GPIO-Setup
GPIO.setmode(GPIO.BCM)
GPIO.setup(SW1, GPIO.IN)
GPIO.setup(SW2, GPIO.IN)
GPIO.setup(SW3, GPIO.IN)
GPIO.setup(SW4, GPIO.IN)

# Die Darstellung auf dem Bildschirm kann rotiert werden.
# Werte 0,90,180,270
screen = Papirus(rotation = 180)

# Daten aufbereiten
def InfoData():
	Datum = time.strftime("%d.%m %H:%M:%S")
	temp = subprocess.Popen("/opt/vc/bin/vcgencmd measure_temp",
      shell=True,
      stdout=subprocess.PIPE).stdout.read()
	temp = (temp[5:9])
	temp = temp.decode("utf-8")
	hostname = socket.gethostname()
	ip = subprocess.Popen("hostname -I",
                          shell=True,
                          stdout=subprocess.PIPE).stdout.read()
	ip = ip.decode("utf-8")

# Bild bearbeiten und Hintergrund bearbeiten
	hg =Image.open("RPiLogo.bmp")
	draw = ImageDraw.Draw(hg)
	font = ImageFont.truetype("FreeMonoBold.ttf", 15)
	draw.text((0, 5), Datum, (0, 0, 0), font=font)
	draw.text((0, 20), str(ip[:-1]), (0, 0, 0), font=font)
	draw.text((0, 35), "CPU-Temp: %s*C" % (str(temp)),
              (0, 0, 0), font=font)
	draw.text((0, 50), "Hostname: %s" %(hostname),
              (0, 0, 0), font=font)
	hg.save("hg.bmp")

# Bild darstellen
	screen.display(hg)
	screen.partial_update()
	return

# Taster 1: komplette Aktualisierung
def Refresh(pin):
	screen.update()

# Interrupt festlegen
GPIO.add_event_detect(SW1, GPIO.RISING, callback=Refresh,
                      bouncetime = 100)

while True:
	InfoData()
	time.sleep(1)
