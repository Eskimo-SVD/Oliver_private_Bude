#!/bin/bash

pause(){ echo -n "Weiter mit RETURN"; read;  }
TEMPFILE=$(mktemp)
trap "rm $TEMPFILE; exit 9 "  0
#Pruefen ob ein Skriptname mit angegeben wurde
if [ $# -ne 1 ]
then
	echo "usage: $0 skriptname"
	echo
	pause
	clear
	exit 1
fi
if [ ! -e $1 ]
then
# Hier wird der Header erstellt
#beim ersten öffnen der Datei
cat >$1 <<END
#! /bin/bash

####Skriptheader Start####
#Skriptname: $1
#
# Erstellt am : $(date +%d.%m.%Y)
#
# Uhrzeit : $(date +%H:%M)
#
# Ersteller $LOGNAME
#
##geaendert##

##### Skriptheader Ende #####


END
	#Rechte so setzen, dass der Besitzer das Skript ausführen kann
	chmod u+x $1
	#Oeffne den vi, Cursor steht in der letzten Zeile
	vi -c \$ $1
	exit 0
fi
#Hier geht es los, wenn die Datei bereits vorhanden ist.
if [ -e $1 ] 
then
	if [ -d $1 ] #Wenn ein Verzeichnis angegeben wurde FEHLER und exit
	then
		echo "FEHLER! Eintrag $1 existiert und ist ein Verzeichnis"
		pause
		clear
		exit 2
	fi
	if [ -f $1 ] # Wenn die Datei vorhanden ist pruefen ob  
	then				 # der Header vorhanden ist
    PRUEF=$(sed -n '12{/##geaendert##/p; }' $1)
		if [ -z "$PRUEF" ] #Wenn kein Header vorhanden ist dann FEHLER und exit
		then
			echo "Das ist kein Skript mit einem Header"
			pause
			clear
			exit 3
		else
			# Datum und Uhrzeit der Aenderung in variablen speichern
			GEAENDERT_ZEIT=$(date +%H:%M)
			GEAENDERT_TAG=$(date +%d.%m.%Y)
			#Jetzt wird eingefuegt und in der temporaeren Datei gespeichert
			sed  -e "/\#\#geaendert\#\#/ a \ ##########"  -e "/\#\#geaendert\#\#/ a \ # Am: $GEAENDERT_TAG" -e "/\#\#geaendert\#\#/ a \ # Um: $GEAENDERT_ZEIT"  -e "/\#\#geaendert\#\#/ a \ # Durch $LOGNAME" -e "/\#\#geaendert\#\#/ a \ ##########"  $1 > $TEMPFILE
			#Hier wird die temporaere Datei zurueckgeschrieben
			cp -f $TEMPFILE $1
			vi $1
		fi
	fi
fi
