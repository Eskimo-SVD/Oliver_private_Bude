#!/bin/bash

GRUEN=$(tput setf 2)
ROT=$(tput setf 4)
RESET=$(tput sgr0)
typeset -i ZAHL1 ZAHL2
while [ -z "$ZAHL1"  ]
do
	read -p "Bitte die erste Zahl eingeben : " ZAHL1
	if [ $ZAHL1 -eq 0 ]
	then
	  echo "$ZAHL1 ist keine Zahl oder hat den Wert 0"
		exit 1
	fi	
	echo ZAHL1 = $ZAHL1
done

while [ -z "$ZAHL2" ]
do
	read -p "Bitte die zweite Zahl eingeben : " ZAHL2
	if [ $ZAHL2 -eq 0 ]
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
	echo 1
	# Die Option -l beim bc bindet die
	# Mathematischen Libraries mit ein
	SUMME=$(echo $ZAHL1 \* $ZAHL2 | bc -l)
	echo -n "Ergebnis der Multiplikation ist : "
	if [ $SUMME -lt 0 ]
	then
		echo -n ${ROT}  $SUMME  ${RESET}
	else
		echo ${GRUEN}  $SUMME ${RESET}
	fi	
	read # Wartet auf RETURN
	;;
2)
	echo 2
	# Die Option -l beim bc bindet die
	# Mathematischen Libraries mit ein
	SUMME=$(echo $ZAHL1 / $ZAHL2 | bc -l)
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
	read # Wartet auf RETURN
	;;
3)
	echo 3
	# Die Option -l beim bc bindet die
	# Mathematischen Libraries mit ein
	SUMME=$(echo $ZAHL1 + $ZAHL2 | bc -l)
	echo -n "Ergebnis der Addition ist : "
	if [ $SUMME -lt 0 ]
	then
		echo -n ${ROT}  $SUMME  ${RESET}
	else
		echo ${GRUEN}  $SUMME ${RESET}
	fi	
	read # Wartet auf RETURN
	;;
4)
	echo 4
	# Die Option -l beim bc bindet die
	# Mathematischen Libraries mit ein
	SUMME=$(echo $ZAHL1 - $ZAHL2 | bc -l)
	echo -n "Ergebnis der Subtraktion ist : "
	if [ $SUMME -lt 0 ]
	then
		echo -n ${ROT}  $SUMME  ${RESET}
	else
		echo ${GRUEN}  $SUMME ${RESET}
	fi	
	read # Wartet auf RETURN
	;;
5)
	echo Programmende
	exit 0;;
*)
	echo "Fehlerhafte Eingabe! "
	read # Wartet auf RETURN
esac

done
