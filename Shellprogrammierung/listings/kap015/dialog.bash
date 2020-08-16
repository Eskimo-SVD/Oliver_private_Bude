#!/bin/bash
DIALOG=dialog
while true
do
DATEINAME=""
KOMMANDO=""
DATEI=""
STARTPUNKT=""
QUELLE=""
ZIEL=""
TEMPDAT=""
MUSTER=""
SUCHDATEI=""
PARAMETER=""
DIR_QUELLE=""
ANTWORT=""
#Hier wird das Menue aufgebaut
MENU=`$DIALOG --menu \
"Was wollen Sie tun ?"  0 0 0 \
"Datei suchen" "" \
"Datei kopieren" "" \
"Text suchen" "" \
"Datei verschieben" "" \
"Ende" "" 3>&1 1>&2 2>&3`
$DIALOG --clear
#clear
# In der folgenden case-Abfrage werden die 
# Werte eingelesen
case "$MENU" in
"Datei suchen") 
		#Einlesen des zu suchenden Eintrags
		while [ -z "$DATEINAME" ]
		do
			DATEINAME=`$DIALOG --inputbox \
							"Dateiname eingeben" 0 0 "" 3>&1 1>&2 2>&3`
		done					
		#Einlesen des Stratpunkts fuer find
		#Defaultwert ist $HOME
		while [ -z "$STARTPUNKT" ]
		do
			STARTPUNKT=`$DIALOG --inputbox \
				"Startpunkt der Suche" 0 0 "$HOME" 3>&1 1>&2 2>&3`
		done
		#Hier werden die Parameter fuer find zusammengestellt
		KOMMANDO="$STARTPUNKT -name $DATEINAME" 
		if [ ! -d $STARTPUNKT ]
		then
			$DIALOG --msgbox "$STARTPUNKT ist kein Verzeichnis" 5 40
			continue
		fi	
		#Temp-Datei fuer --textbox erstellen
		DATEI=$(mktemp)
		find $KOMMANDO -print 2>/dev/null >$DATEI
		ls -l $DATEI
		cat $DATEI
		$DIALOG --textbox "$DATEI" 0 0
		$DIALOG --clear
		rm $DATEI # und Temp-Datei wieder löschen
		;;
"Datei kopieren") 
		# Quelle einlesen
		while [ -z "$QUELLE" ]
		do
			QUELLE=`$DIALOG --inputbox \
						"Quelle eingeben" 0 0 "" 3>&1 1>&2 2>&3`
		done
		if [ ! -e "$QUELLE" ]
		then
			$DIALOG --msgbox "$QUELLE ist nicht vorhanden" 5 40
			continue
		fi	
		#Ziel einlesen
		while [ -z "$ZIEL" ]
		do
			ZIEL=`$DIALOG --inputbox \
						"Ziel eingeben" 0 0 "" 3>&1 1>&2 2>&3`
		done				
		if [ ! -d "$ZIEL"  ] #Wenn Ziel kein Verz. ist
		then
			$DIALOG --msgbox "$ZIEL ist kein Verzeichnis" 5 40
			continue
		fi
		if [ ! -w "$ZIEL"  ] #Wenn das Schreibrecht am Ziel fehlt
		then
			$DIALOG --msgbox "Kein Schreibrecht an $ZIEL" 5 40
			continue
		fi
		cp $QUELLE $ZIEL #Hier wird kopiert
		if [ $? -eq 0 ]
		then
			$DIALOG --msgbox "$QUELLE erfolgreich nach $ZIEL kopiert" 5 70
			continue
		else
			$DIALOG --msgbox "Kopieren von $QUELLE nach  $ZIEL fehlgeschlagen" 5 70
			continue
		fi	
		;;
"Text suchen")
		# Anlegen der TEMP-Datei für das Suchergebnis	
	  TEMPDAT=`mktemp`
	  MUSTER=`$DIALOG --inputbox \
		 	    "Suchmuster eingeben" 0 0 "" 3>&1 1>&2 2>&3`
	  SUCHDATEI=`$DIALOG --inputbox \
				      "Datei eingeben" 0 0 "" 3>&1 1>&2 2>&3`
	  PARAMETER=`$DIALOG --checklist "FLags für die Suche" 10 40 2 \
	 						-v "nicht vorhanden" off \
							-i "Groß- Kleinschreibung off" off \
							3>&1 1>&2 2>&3`
		 $DIALOG --clear

		 if [ -n "$PARAMETER" ]
		 then
		  	echo $PARAMETER > para.txt
			# Bei --inputbox werden die Werte in "" geschrieben
			# diese muessen hier entfernt werden
			PARAMETER=`echo $PARAMETER | tr '\"' " "`
		 	 grep $PARAMETER $MUSTER $SUCHDATEI > $TEMPDAT
		 else
			 grep $MUSTER $SUCHDATEI > $TEMPDAT
		 fi
		 $DIALOG --textbox "$TEMPDAT" 0 0
		 $DIALOG --clear
		 rm $TEMDAT
		 ;;
"Datei verschieben") 
		 #Quelle einlesen
		 while [ -z "$QUELLE" ]
		 do
		 QUELLE=`$DIALOG --inputbox \
		        "Quelle eingeben" 0 0 "" 3>&1 1>&2 2>&3`
		 done
		 #Verzeichnis der Quelle ermitteln
		 DIR_QUELLE=`dirname $QUELLE`
		 if [ ! -e $QUELLE ]
		 then
		 	 $DIALOG --msgbox "$QUELLE ist nicht vorhanden! " 5 70
			 continue
		 fi 
		 #Pruefen ob Quelle gelöscht werden kann
		 if [ ! -w "$DIR_QUELLE" ]
		 then
		 	 $DIALOG --msgbox "Es fehlt das Recht zum Verschieben an $QUELLE" 5 70
		 	 continue
		 fi
		 # Fragen ob auch Verz. verschoben werden soll
		 if [ -d $QUELLE ]
		 then
		 	 $DIALOG --yesno "$QUELLE ist ein Verzeichnis trotzdem verschieben?" 0 0
			 ANTWORT=$?
		 fi
		 if [ $ANTWORT -eq 1 ]
		 then
		 	 continue
		 fi	 
		 #Ziel einlesen
		 while [ -z "$ZIEL" ]
		 do
		 ZIEL=`$DIALOG --inputbox \
		        "Ziel eingeben" 0 0 "" 3>&1 1>&2 2>&3`
		 done
		 #Wenn Ziel kein Verzeichnis
		 if [ ! -d "$ZIEL" ]
		 then
		 	 $DIALOG --msgbox "$ZIEL ist kein Verzeichnis" 5 70
			 continue
		 fi
		 #Wenn am Ziel das Schreibrecht fehlt
		 if [ ! -w "$ZIEL" ]
		 then
		 	 $DIALOG --msgbox "Es fehlt das Schreibrecht an $ZIEL" 5 70
			 continue
		 fi
		 # Hier wird verschoben
		 mv $QUELLE $ZIEL
		 if [ $? -eq 0 ]
		 then
		 	 $DIALOG --msgbox "Datei $QUELLE nach $ZIEL verschoben" 5 70
		 else
		   $DIALOG --msgbox "Datei $QUELLE konnte nicht nach $ZIEL verschoben werden" 5 70
		 fi
	   ;;
"Ende") clear
				exit 0;;
esac
clear
done
