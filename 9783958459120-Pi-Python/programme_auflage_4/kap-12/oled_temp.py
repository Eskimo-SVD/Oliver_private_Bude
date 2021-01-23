#! /usr/bin/python3
#----------------------------------------------------------------
# Dateiname: oled_temp.py
# Die aktuelle Temperatur wird auf dem OLED-Display angezeigt.
# Angeschlossen ist ein DS1820 Temperatursensor.
#  
# Michael Weigend
# Raspberry Pi programmieren mit Python, 4. Auflage, mitp 2019
# Kap. 12
# Michael Weigend 20. November 2018
#----------------------------------------------------------------
import time

import Adafruit_GPIO.SPI as SPI
import Adafruit_SSD1306
from PIL import Image, ImageDraw, ImageFont
from temp import readTemp


RST = 0

disp = Adafruit_SSD1306.SSD1306_128_64(rst=RST)


disp.begin()
disp.clear()
disp.display()

width = disp.width
height = disp.height
image = Image.new('1', (width, height))
draw = ImageDraw.Draw(image)
font = ImageFont.truetype("/usr/share/fonts/truetype/freefont/FreeSans.ttf", size=30)

while True:
    ppm = round(readTemp(), 1)
    text = "{} °C".format(ppm)
    draw.rectangle((0,0,width,height), outline=0, fill=False) # Löschen
    draw.text((0,0),  text,  font=font, fill=255)
    disp.image(image)
    disp.display()
    time.sleep(1)
