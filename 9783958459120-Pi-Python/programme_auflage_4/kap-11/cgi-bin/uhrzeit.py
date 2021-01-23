#! /usr/bin/python3
#----------------------------------------------------------------
# Dateiname:  uhrzeit.py 
# CGI-Skript, das eine Webseite mit der aktuellen Uhrzeit liefert.
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 4. Auflage, mitp 2018
# Kap. 11.3
# Michael Weigend 20. September 2018
#--------------------------------------------------------------

#! /usr/bin/python3

HTML = '''Content-type: text/html; char-set=utf-8

<html>
  <body>
    <h2>Wie spät ist es?</h2>
      Es ist {} Uhr und {} {}.
  </body>
</html>'''                                      #1

from time import localtime
t = localtime()                                 #2
if t.tm_min == 1:
    m_text = 'Minute'
else:
    m_text = 'Minuten'
print(HTML.format(t.tm_hour, t.tm_min, m_text))     #3
