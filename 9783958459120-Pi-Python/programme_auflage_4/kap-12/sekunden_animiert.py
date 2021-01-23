#! /usr/bin/python3
#----------------------------------------------------------------
# Dateiname: sekunden_animiert.py
# Die Sekunden einer Minute werden durch ein Kreisdiagramm
# auf dem OLED-Display dargestellt.
#  
# Michael Weigend
# Raspberry Pi programmieren mit Python, 4. Auflage, mitp 2019
# Kap. 12
# Michael Weigend 20. November 2018
#----------------------------------------------------------------

import Adafruit_GPIO.SPI as SPI
import Adafruit_SSD1306
from PIL import Image, ImageFont, ImageDraw, ImageTk
from time import *
 
    
W, H = 128, 64
RST = 0

disp = Adafruit_SSD1306.SSD1306_128_64(rst=RST)
disp.begin()
disp.clear()
disp.display()
image = Image.new('1', (W, H))
draw = ImageDraw.Draw(image)
sec = 0

while True:
    angle = -90 + sec * 6
    print (angle)
    draw.rectangle((0,0, W, H), fill=False)
    draw.pieslice((36, 4, 92, 60), -90, angle, fill=True)
    disp.image(image)
    disp.display()
    sec = (sec + 1)%60
    sleep(1)

