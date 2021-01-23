#!/usr/bin/pythonRoot3.5
#----------------------------------------------------------------
# Dateiname:  inter_webcam.py 
# CGI-Skript fuer interaktive Webcam
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 4. Auflage, mitp 2018
# Kap. 11
# Michael Weigend 20. September 2018
#--------------------------------------------------------------

import cgi, cgitb, os, subprocess, io
from PIL import Image

PATTERN='''Content-Type: text/html

<html>
  <head>
        <title>Interaktive Webcam</title>
  </head>
<body>
  <h2> Interaktive Webcam</h2>
   <img src="http://192.168.178.42/image.jpg" alt="Bild der Webcam"><br/>
   W&auml;hlen Sie den Bildausschnitt!
   <form action="http://localhost/cgi-bin/inter_webcam.py"
     method="GET">
      <input type="Radio" name="zoom" value="weit" {}/>
          &nbsp;Weit entfernt<br/>
      <input type="Radio" name="zoom" value="naeher" {}/>
          &nbsp;N&auml;her<br/>
      <input type="Radio" name="zoom" value="nah" {}/>
         &nbsp;Nah<br><br/>
      <input type="Submit" value="Bild anfordern"/>
    </form>
  </body>
</html>'''                                            #1

PATH = 'image.jpg'     
COMMAND = 'raspistill -t 500 -w {}  -h {} -o {} -n '                                #2

def takePhoto (width, height, bbox):
    imageData = io.BytesIO()
    command = COMMAND.format(width, height,'-')               #3
    try:
        imageData.write(subprocess.check_output(command, shell=True))                                          #4
        imageData.seek(0)
        image = Image.open(imageData).crop(bbox)          #5
        image.save(PATH)
    except: pass

form = cgi.FieldStorage()
zoom = form.getvalue('zoom', 'nah')
if zoom == 'nah':                                     #6
    takePhoto(1600, 1200, (600, 450, 1000, 750))
    response = PATTERN.format('', '', 'checked="checked"')
elif zoom == 'naeher':
    takePhoto(800, 600, (200, 150, 600, 450))         #7
    response = PATTERN.format('', 'checked="checked"', '')
else:
    takePhoto(400, 300, (0, 0, 400, 300))             #8
    response = PATTERN.fortmat('checked="checked"', '', '')

print(response)

