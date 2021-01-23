#! /usr/bin/python3
#----------------------------------------------------------------
# Dateiname: oled_uhr.py
# Die aktuelle Uhrzeit wird auf dem OLED-Display angezeigt
#  
# Michael Weigend
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

font = ImageFont.truetype("/usr/share/fonts/truetype/freefont/FreeSans.ttf", size=30)

while True:
    #disp.clear()
    wochentag, monat, tag, zeit, jahr  = time.asctime().split()
    draw.rectangle((0, 0, w, h),fill=False) 
    draw.text((0,0),  zeit,  font=font, fill=True)
    disp.image(image)
    disp.display()
    time.sleep(0.1)
