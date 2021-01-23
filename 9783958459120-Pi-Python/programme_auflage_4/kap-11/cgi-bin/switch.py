#!/usr/bin/pythonRoot3.5
#----------------------------------------------------------------
# Dateiname:  switch.py 
# Das Interface PiFace ist angeschlossen. Das CGI-Skript dient
# der Steuerung des Relais Nr. 0 des PiFace. ROOT-Rechte erforderlich!
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 4. Auflage, mitp 2018
# Kap. 11.4
# Michael Weigend 20. September 2018
#--------------------------------------------------------------

import cgi, cgitb
from RPi import GPIO
from time import sleep
GPIO.setmode(GPIO.BOARD)
GPIO.setup(10, GPIO.OUT)
cgitb.enable()

RESPONSE='''Content-Type: text/html

<html >
  <body>
    <h1> Scheinwerfer</h1>
    <form action="http://192.168.178.42/cgi-bin/switch.py"
     method="GET">
      <input type="hidden" name="switch" value="on">
      <input type="submit" value="Einschalten"/>
    </form>
    <form action="http://192.168.178.42/cgi-bin/switch.py"
     method="GET">
      <input type="hidden" name="switch" value="off">
      <input type="submit" value="Ausschalten"/>
    </form>
   </body>
</html>'''

form = cgi.FieldStorage()
switch = form.getvalue('switch','off')
if switch =='on':
   GPIO.output(10, False)
else:
   GPIO.output(10, False) 



print(RESPONSE) 
