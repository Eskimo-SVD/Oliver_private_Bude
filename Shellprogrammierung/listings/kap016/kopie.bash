#!/bin/bash
# Ein zenity-Skript um eine Datei zu kopieren

#Einlesen der Quelldatei
QUELLE=`zenity --file-selection --title="Wählen Sie die zu kopierende Datei"` 2>/dev/null
if [ -z "$QUELLE" ]
then
	zenity --notification --window-icon="error" --text="Es wurde keine Datei ausgewählt" 2>/dev/null
	exit 1
fi

#Einelesen des Zielverzeichnis
ZIEL=`zenity --file-selection --directory --title="Wählen Sie das Zielverzeichnis"` 2>/dev/null
if [ -z "$ZIEL" ]
then
	zenity --notification --window-icon="error" --text="Es wurde keine Verzeichnis ausgewählt" 2>/dev/null
	exit 2
fi

# Prüfen ob der Anwender die Quelldatei lesen darf
if [ ! -r "$QUELLE" ]
then
	zenity --notification --window-icon="error" --text="Sie haben kein Leserecht an $QUELLE" 2>/dev/null
	exit 3
fi

# Prüfen ob der Anwender Schreibrecht am Zielverzeichnis hat
if [ ! -w "$ZIEL" ]
then
	zenity --notification --window-icon="error" --text="Sie haben kein Schreibrecht an $ZIEL" 2>/dev/null
	exit 4
else
	cp $QUELLE $ZIEL
fi
	
	
