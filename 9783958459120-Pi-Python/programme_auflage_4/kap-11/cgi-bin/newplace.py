#!/usr/bin/python3
#----------------------------------------------------------------
# Dateiname:  newplace.py 
# CGI-Skript zur Eingabe einer neuen Fundstelle für Früchte.
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 4. Auflage, mitp 2016
# Kap. 11.5
# Michael Weigend 20. September 2018
#--------------------------------------------------------------

import cgi, cgitb, sqlite3
cgitb.enable()

HTML = {ord('ä'): '&auml;', ord('ö'): '&ouml;',
        ord('ü'): '&uuml;', ord('Ä'): '&Auml;',
        ord('Ö'): '&Ouml;', ord('Ü'): '&Uuml;',
        ord('ß'): '&szlig'}

RESPONSE='''Content-Type: text/html

<html>
<meta http-equiv="Content-Type" content="charset=utf-8" />
  <head>
        <title>Daten eingegeben</title>
  </head>
<body>
  <h2> Danke f&uuml;r die neue Stelle!</h2>
   Die Daten wurden gespeichert.<br/>
   Frucht: &nbsp; {}<br/>
   Ort: &nbsp; {}<br/><br/>
   <a href="http://192.168.178.42/raspberries/">Startseite</a>
  </body>
</html>'''

{}
form = cgi.FieldStorage()
place = form.getvalue('place').translate(HTML)
fruit = form.getvalue('fruit').translate(HTML)


conn=sqlite3.connect('data/fruits.db')
c = conn.cursor()
insert = 'INSERT INTO location VALUES(?, ?)' 
try:
    c.execute(insert, (fruit, place))
except:
    newTable='''CREATE TABLE
        location (fruit varchar(20), place varchar(100))'''
    c.execute(newTable)
    c.execute(insert, (fruit, place))
conn.commit()
c.close()
conn.close()

print (RESPONSE.format(fruit, place))
