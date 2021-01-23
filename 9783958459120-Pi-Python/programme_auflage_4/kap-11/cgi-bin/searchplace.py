#!/usr/bin/python3

#----------------------------------------------------------------
# Dateiname:  searchplace.py 
# CGI-Skript zur Suche einer Fundstelle für Früchte.
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 4. Auflage, mitp 2018
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
        <title>Suchergebnisse</title>
  </head>
<body>
  <h2> Wo darf man kostenlos ernten?</h2>
   <p> {} </p>
   <a href="http://192.168.178.42/raspberries/">Startseite</a>
  </body>
</html>'''

form = cgi.FieldStorage()
fruit = form.getvalue('fruit', '').translate(HTML)

try:
    conn=sqlite3.connect('data/fruits.db')
    c = conn.cursor()
    query = '''SELECT place
           FROM location
           WHERE fruit=?'''
    c.execute(query, (fruit,))
    rows = list(c)
    if len(rows) > 0:
        results ='<h3>Hier findest du {}</h3>' % fruit
        for row in rows:
               results += ('<p> {} </p>'.format(row[0]))
        print (RESPONSE.format(results))
    else:
        print (RESPONSE.format('Leider habe ich keine passenden Fundstellen.'))
except:
    print (RESPONSE.format('Leider sind keine Daten vorhanden.'))
           
