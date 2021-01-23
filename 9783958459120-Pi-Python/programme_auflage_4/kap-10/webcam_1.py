#----------------------------------------------------
# Dateiname:  webcam_1.py
# Bild einer Webcam anzeigen
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 10
# Michael Weigend 20. April 2016
#--------------------------------------------------------------

import io
from urllib.request import urlopen
from PIL import Image
URL = "http://lamp01.dortmund.de/webcams/friedensplatz/current.jpg"
f = urlopen(URL)                                   #1
img_text = f.read()                                #2
img = Image.open(io.BytesIO(img_text))             #3
img.show()                                         #4
