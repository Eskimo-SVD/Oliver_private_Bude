#!/usr/bin/python3
#----------------------------------------------------------------
# Einfaches Programm zum Finden der Namen aller JPEG-Bilddateien
# in einem html-Dokument
# 
# Michael Weigend
# Raspberry Pi programmieren mit Python, 4. Auflage, mitp 2016
# Kap. 10
# Michael Weigend 20. September 2018
#--------------------------------------------------------------
from urllib.request import urlopen
import re

URL = "https://www.hessenschau.de/verkehr/verkehrskameras/b43-frankfurt-stadion-100.html"

f = urlopen(URL)
data = f.read()
f.close()
text = str(data)
elements = text.split("\"")
bilder = [w for w in elements
          if w.endswith(".jpg")]
print(bilder)
