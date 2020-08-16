#! /bin/bash

#Interger Variablen definieren
typeset -i Z1 Z2 Z3
Z1=$1
Z2=$2
Z3=$3

#Prüfen der Variablen und eventuell
#Werte zuweisen.
if [ $Z1 -lt 5 -o $Z1 -gt 25 ]
then
	Z1=5
fi

if [ $Z2 -lt 5 -o $Z2 -gt 25 ]
then
	Z2=10
fi

if [ $Z3 -lt 5 -o $Z3 -gt 25 ]
then
	Z3=15
fi

#Berechnung des Zwischenergenis
if [ $Z1 -lt $Z2 ]
then
	SUMME=$(expr $Z1 \* $Z2)
else
	SUMME=$((Z1+Z2))
fi

if [ $SUMME -lt 40 ]
then
	SUMME=$(expr $SUMME \* $Z3)
else
	SUMME=$((SUMME+Z3))
fi

echo "Ergebnis == $SUMME"
