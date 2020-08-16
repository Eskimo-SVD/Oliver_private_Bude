#!/bin/bash

#Funktion ohne Parameter
pause(){ echo "Weiter mit RETURN"; read;  }

#Funktion mit lokaler Variable
multi()
{
	local ERG=$(echo $1 \* $2 | bc -l)
	echo $ERG
}
#Funktion mit globler Variable 
divi()
{
	SUMME=$(echo $1 / $2 | bc -l)
}

#Funktion mit lokaler Variable
addi()
{
	local ERG=$(echo $1 + $2 | bc -l)
	echo $ERG
}

#Funktion mit globaler Variable
subi()
{
	SUMME=$(echo $1 - $2 | bc -l)
}
pruef()
{
	echo "Wert == $1"
	if [ $1 -eq 0 ]
	then
		return 1
	else
		return 0
	fi	
}

GRUEN=$(tput setf 2)
ROT=$(tput setf 4)
RESET=$(tput sgr0)
typeset -i ZAHL1 ZAHL2
while [ -z "$ZAHL1"  ]
do
	read -p "Bitte die erste Zahl eingeben : " ZAHL1
	pruef $ZAHL1 
	#$? enthaelt den Returnwert der Funktion pruef()
	if [ $? -eq 1 ]
	then
	  echo "$ZAHL1 ist keine Zahl oder hat den Wert 0"
		exit 1
	fi	
done

while [ -z "$ZAHL2" ]
do
	read -p "Bitte die zweite Zahl eingeben : " ZAHL2
	pruef $ZAHL2
	#$? enthaelt den Returnwert der Funktion pruef()
	if [ $? -eq 1 ]
	then
	  echo "$ZAHL2 ist keine Zahl oder hat den Wert 0"
		exit 2
	fi	
done

while true
do
clear
#WAHL an dieser Stelle leeren da sonst
#beim zweiten Durchlauf die Variabel
#schon belegt ist.
WAHL=""
cat <<ENDE
Multiplikation........1
Division..............2
Addition..............3
Subtraktion...........4
Ende..................5
ENDE
read -p "Auswahl : " WAHL

case "$WAHL" in
1)
	#Aufruf der Funktion multi()
	SUMME=$(multi $ZAHL1 $ZAHL2)
	echo -n "Ergebnis der Multiplikation ist : "
	if [ $SUMME -lt 0 ]
	then
		echo -n ${ROT}  $SUMME  ${RESET}
	else
		echo ${GRUEN}  $SUMME ${RESET}
	fi	
	pause # Aufruf der Funktion "pause"
	;;
2)
	#Aufruf der Funktion divi()
	divi $ZAHL1  $ZAHL2 
	echo -n "Ergebnis der Division ist : "
	#ein -lt wuerde bie Gleitkommazahlen eine
	#Fehlermeldung generieren deshalb die
	#Umleitung der Fehlermeldung
	if [ $SUMME -lt 0 2>/dev/null ]
	then
		echo -n ${ROT}  $SUMME  ${RESET}
	else
		echo ${GRUEN}  $SUMME ${RESET}
	fi	
	pause # Aufruf der Funktion "pause"
	;;
3)
	#Aufruf der Funktion addi()
	SUMME=$(addi $ZAHL1  $ZAHL2) 
	echo -n "Ergebnis der Addition ist : "
	if [ $SUMME -lt 0 ]
	then
		echo -n ${ROT}  $SUMME  ${RESET}
	else
		echo ${GRUEN}  $SUMME ${RESET}
	fi	
	pause # Aufruf der Funktion "pause"
	;;
4) 
	#Aufruf der Funktion subi()
	subi $ZAHL1 $ZAHL2
	echo -n "Ergebnis der Subtraktion ist : "
	if [ $SUMME -lt 0 ]
	then
		echo -n ${ROT}  $SUMME  ${RESET}
	else
		echo ${GRUEN}  $SUMME ${RESET}
	fi	
	pause # Aufruf der Funktion "pause"
	;;
5)
	echo Programmende
	exit 0;;
*)
	echo "Fehlerhafte Eingabe! "
	pause # Aufruf der Funktion "pause"
esac

done
