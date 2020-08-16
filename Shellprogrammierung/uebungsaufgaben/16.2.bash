#!/bin/bash

DIALOG=dialog
TEMP=$(mktemp)
DATEI=/var/log/syslog

MONAT=$($DIALOG --checklist "Monate auswählen: " 0 0 12 \
			Jan "" off\
			Feb "" off\
			Mar "" off\
			Apr "" off\
			May "" off\
			Jun "" off\
			Jul "" off\
			Aug "" off\
			Sep "" off\
			Oct "" off\
			Nov "" off\
			Dec "" off\
			3>&1 1>&2 2>&3)
$DIALOG --clear
clear
set  $MONAT
for ((count=1;count<=$#;count++))
do
	# Auswerten der Positionsparameter
	MONAT_WAHL=$(eval echo \$$count)
	# In der --checklist werden die Werte in 
	# Gaensefuesschen geschrieben.
	# Diese werden hier entfernt, sonst gibt es
	# Probleme mit grep
	MONAT_WAHL=$(echo $MONAT_WAHL | tr "\"" " ")
	ANZAHL=$(grep $MONAT_WAHL $DATEI | wc -l)
	echo "Im Monat $MONAT_WAHL gibt es $ANZAHL Einträge" >> $TEMP
done
$DIALOG --textbox "$TEMP" 0 0
rm $TEMP
clear

