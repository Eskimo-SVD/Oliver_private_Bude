#!/bin/bash

clear
# Erzeugt ein Temp-Verzeichnis in /tmp
TMPDIR=`mktemp -d`
# Loescht das Temp-Verzeichnis bei einem Programmabbruch und am Ende
trap "rmdir $TMPDIR; exit 9 "  0
echo
# Hier wird das Starverzeichnis festgelegt
while [ -z "$QUELLE" ]
do
  echo -n "Bitte Quelle eingeben (QUIT für Ende): "
  read QUELLE
# Wenn die Eingabe = QUIT Programmende
  if [ $QUELLE = "QUIT" ]
  then
        exit 0
        else
        continue
  fi
done
# Hier wir ueberprueft ob die Quelle ein Verzeichnis ist
if [ ! -d $QUELLE ]
then
  echo
  echo
  echo "$QUELLE ist kein Verzeichnis. Die Quelle muss ein Verzeichnis sein."
  echo
  exit 2
fi
# Jetzt wir das Zielverzeichnis eingelesen.
while [ -z "$ZIEL" ]
do
  echo -n " Bitte Ziel eingeben : "
  read ZIEL
  if [ ! -d $ZIEL ]
  then
# Wenn das Ziel eine Datei ist erfolgt ein Abbruch
    if [ -f $ZIEL ]
    then
      echo
      echo " Das Ziel $ZIEL ist eine Datei, das Ziel muss ein Verzeichnis sein!"
      exit 3
    fi
# Wenn das Ziel nicht existiert wird es angelegt
  mkdir "$ZIEL"
  fi
done
echo
# Hier wird der zu ersetzende Wert eingelesen ACHTUNG bei
# Leerzeichen "text immer" quoten
while [ -z "$ALT" ]
do
  echo -n "Bitte alten Wert eingeben : "
  read ALT
done
echo
# Das gleiche für den neuen Wert.
while [ -z "$NEU" ]
do
  echo -n "Bitte neuen Wert eingeben : "
  read NEU
done
# In einer Schleife werden rekursiv alle Dateien
# nach dem alten Wert durchsucht und geändert
for  i in `grep -lr  $ALT $QUELLE`
do
  echo "DATEI "$i" wird geändert"
# Hier wir der Pfad zur aktuellen Datei ermittelt
  DATEI=`basename "$i"`
# Hier wir der Dateiname der aktuellen Datei ermittelt
  PFAD=`dirname "$i"`
  if [ -f "$i" ]
  then
# Hier wird nun wirklich ersetzt
    sed  "s|$ALT|$NEU|g" $i > "$TMPDIR/$DATEI"
    PFADNEU=${PFAD#$QUELLE}
    PFADNEU=$ZIEL$PFADNEU #Der neu Pfad wird ermittelt
    mkdir $PFADNEU # Der neu Pfad wird angelegt
# Und an neue Ziel verschoben
    mv "$TMPDIR/$DATEI" "$PFADNEU/$DATEI"
  fi
done

