#!/usr/bin/python3
# Datei oled.py
import time
import Adafruit_SSD1306
from PIL import Image
from PIL import ImageDraw
from PIL import ImageFont
import subprocess
import feedparser

# Pin-Konfiguration
RST = 24

# 128x64-I2C-Display
disp = Adafruit_SSD1306.SSD1306_128_64(rst=RST)

# Display initialisieren
disp.begin()

# leeres Bild erzeugen
width = disp.width
height = disp.height
image = Image.new('1', (width, height))
draw = ImageDraw.Draw(image)

# Konstanten zum Zeichnen definieren
padding = 2
shape_width = 0
top = padding
bottom = height-padding
x=0

# Schriften laden
font = ImageFont.load_default()
fontN = ImageFont.truetype('VCR_OSD_MONO_1.001.ttf', 16)
fontH = ImageFont.truetype('VCR_OSD_MONO_1.001.ttf', 20)

def news():
    n = feedparser.parse('http://feeds.bbci.co.uk/news/rss.xml')
    headline = n['entries'][0]['title']   
    x = 0

    for c in enumerate(headline):
        print (c)
        draw.rectangle((0, 0, width, height), outline=0, fill=0)
        draw.text((32, top), "NEWS",  font=fontH, fill=255) 
        draw.text((x, 20), headline,  font=fontN, fill=255)        
        x-=10
        disp.image(image)
        disp.display()
        time.sleep(.05)

def text(x, head, txt):
    draw.rectangle((0,0, width, height), outline=0, fill=0) 
    draw.text((30, top), str(head), font=fontH, fill=255) 
    draw.text((x, 20), str(txt), font=fontN, fill=255)
    disp.image(image)
    disp.display()

while True:    
    zeit = time.strftime("%d.%m %H:%M:%S") 
    temp = subprocess.Popen("/opt/vc/bin/vcgencmd measure_temp", 
      shell=True, stdout=subprocess.PIPE).stdout.read()
    temp = (temp[5:9])    
    temp = temp.decode("utf-8")

    text(24, "CPU-Temp ", temp)
    time.sleep(2)
    text(x, "Datum ", zeit)
    time.sleep(2)
    news()
    time.sleep(2)
