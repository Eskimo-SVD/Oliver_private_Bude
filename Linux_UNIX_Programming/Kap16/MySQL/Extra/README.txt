N�tzliche Funktion in Bezug auf die MySQL-API, welche einem das Leben erleichtern.
Beide Funktionen (connect_db.c und mysql_print.c) wurden von Martin Conrad zur
freien) Verf�gung (BSD Lizenz) gestellt.

-----------mysql_print()------------
Die Funktion mysql_printf() funktioniert wie normales printf(), erstes 
Argument ist ein MYSQL *mysql. Das Ding macht Speicher f�r die 
querys frei, quotet Sonderzeichen in den �bergebenen Variablen (und 
nur da) und gibt den mysql R�ckgabewert zur�ck. Das Teil ist f�r 
mich Standard geworden, weil es die Quellcodes extrem verk�rzt.

Aus Konstrukten wie:
String L�nge ermitteln,
Speicher anfordern,
String zusammenbauen
String quoten
query ausf�hren
Speicher Freimachen 

wird einfach mysql_printf()
---------------------------------------

--------connect_db.c-------------------
Zus�tzlich noch eine Datei connect_db.c, die eine 
Konfigurations Datei mit MySQL Zugangsdaten liest und sich dann mit 
dem Server verbindet. Eine sichere Alternative um sich mit dem Server
zu connect'en
---------------------------------------

