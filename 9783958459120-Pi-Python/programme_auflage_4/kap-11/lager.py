#!/usr/bin/python3
#----------------------------------------------------------------
# Dateiname:  lager.py 
# Das Skript legt eine kleine SQLite-Datenbank an.
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 11.5
# Michael Weigend 20. April 2016
#--------------------------------------------------------------
import sqlite3
conn = sqlite3.connect('/tmp/lager.db')
c = conn.cursor()
c.execute('''CREATE TABLE lager(artikel VARCHAR(50),
                                stueck INT,
                                preis FLOAT)''')
statement = ''' INSERT INTO lager VALUES(?, ?, ?)'''
c.execute(statement, ("AD-Wandler MCP3008", 120, 1.52))
c.execute(statement, ("Temperatursensor DS18S20", 34, 0.73))
conn.commit()
c.close()
conn.close()
