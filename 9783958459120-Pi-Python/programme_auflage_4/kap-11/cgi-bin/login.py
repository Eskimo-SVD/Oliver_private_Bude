#!/usr/bin/python3
#----------------------------------------------------------------
# Dateiname:  login.py 
# Einfaches CGI-Skript, das Eingabedaten verarbeitet.
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 4. Auflage, mitp 2018
# Kap. 11.3
# Michael Weigend 20. September 2018
#--------------------------------------------------------------

import cgi, cgitb
cgitb.enable()


RESPONSE = '''Content-type: text/html; charset=utf-8

<html>
  <head>
    <title> Login-Seite </title>
  </head>     
  <body>
    <h3> {} </h3>
   </body>
</html>'''

form = cgi.FieldStorage()                               #2
language = form.getvalue('language')                      #3
name = form.getvalue('name')

if language == 'English':
    text = 'Welcome back, {}!'
else:
    text = 'Willkommen zur&uuml;ck, {}!'


greeting = text.format(name)
print (RESPONSE.format(greeting))


