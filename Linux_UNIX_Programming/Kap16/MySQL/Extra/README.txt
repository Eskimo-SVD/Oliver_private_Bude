Nützliche Funktion in Bezug auf die MySQL-API, welche einem das Leben erleichtern.
Beide Funktionen (connect_db.c und mysql_print.c) wurden von Martin Conrad zur
freien) Verfügung (BSD Lizenz) gestellt.

-----------mysql_print()------------
Die Funktion mysql_printf() funktioniert wie normales printf(), erstes 
Argument ist ein MYSQL *mysql. Das Ding macht Speicher für die 
querys frei, quotet Sonderzeichen in den übergebenen Variablen (und 
nur da) und gibt den mysql Rückgabewert zurück. Das Teil ist für 
mich Standard geworden, weil es die Quellcodes extrem verkürzt.

Aus Konstrukten wie:
String Länge ermitteln,
Speicher anfordern,
String zusammenbauen
String quoten
query ausführen
Speicher Freimachen 

wird einfach mysql_printf()
---------------------------------------

--------connect_db.c-------------------
Zusätzlich noch eine Datei connect_db.c, die eine 
Konfigurations Datei mit MySQL Zugangsdaten liest und sich dann mit 
dem Server verbindet. Eine sichere Alternative um sich mit dem Server
zu connect'en
---------------------------------------

