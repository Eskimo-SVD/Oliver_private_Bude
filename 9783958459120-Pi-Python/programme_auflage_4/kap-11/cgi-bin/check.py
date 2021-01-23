#!/usr/bin/python3
#----------------------------------------------------------------
# Dateiname:  check.py 
# CGI-Skript zur Auswertung eines Tests.
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 4. Auflage, mitp 2018
# Kap. 11
# Michael Weigend 20. September 2018
#--------------------------------------------------------------

import cgi, cgitb, sqlite3
cgitb.enable()

RESPONSE='''Content-Type: text/html

<html>
  <body>
     <h3> {} </h3>
  </body>
</html>'''


form = cgi.FieldStorage()
statements = form.getvalue('statement',[])
if set(statements) == {'probleme', 'kreuzwort'}:
    text = 'Jawohl, Sie sind ein Optimist!'
elif 'regen' in statements:
    text = 'Sie sind ein bisschen vorsichtig.'
else:
    text = 'Sie sind ein Pessimist.'
                       

print (RESPONSE.format(text))
