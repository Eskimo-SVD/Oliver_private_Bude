#!/bin/sh

# Script-Name: prozdat
# Listet Prozessinformationen auf

echo "Anzahl lauferner Prozesse:"
# ... wc -l zählt alle Zeilen die ps -ef ausgeben würde
ps -ef | wc -l

echo "Prozessinformationen unserer Shell:"
# ... die Shellvariable $$ enthält die eigene Prozessnummer
ps $$