#! /usr/bin/python3
#----------------------------------------------------------------
# Dateiname: hello_oled.py
# Die aktuelle Uhrzeit wird auf dem OLED-Display angezeigt
#  
# Raspberry Pi programmieren mit Python, 4. Auflage, mitp 2019
# Kap. 12
# Michael Weigend 20. November 2018
#----------------------------------------------------------------
import time
import Adafruit_SSD1306
from PIL import Image, ImageDraw, ImageFont

RST = 0
disp = Adafruit_SSD1306.SSD1306_128_64(rst=RST)

disp.begin()
disp.clear()

w, h = disp.width, disp.height

image = Image.new('1', (w, h)) 
draw = ImageDraw.Draw(image)
wochentag, monat, tag, zeit, jahr  = time.asctime().split()
draw.text((20,20),  text=zeit, fill=True)
disp.image(image)
disp.display()

