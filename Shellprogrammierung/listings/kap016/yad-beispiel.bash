#!/bin/bash


while true
do
	yad --button=gtk-color-picker:0 \
			--button=gtk-network:1 \
			--button=gtk-info:2 \
			--button=gtk-quit:3

	WAHL=$?

	case "$WAHL" in
	0)	FARBE=`yad --color --init-color=blue`
			yad --text="Gewählte Farbe = $FARBE" \
					--button=gtk-ok:1;;
	1)	declare IP_DEV=($(ip a | grep -v  ^" " | awk -F: '{print $2}'))
			declare IP_ADR=($(ip a | grep '\.' | awk '{print $2}' | awk -F/ '{print $1}'))
			LANG_DEV=`echo ${#IP_DEV[*]}`
			LANG_ADR=`echo ${#IP_ADR[*]}`
			yad --list \
					--width=300 \
					--height=400 \
					--column=Device \
					--column=IP-Adresse \
					$(for ((i=0; i<=$LANG_DEV; i++))
			do
				echo -n " ${IP_DEV[$i]} ${IP_ADR[$i]}"	
			done)
			;;
	2)	yad --list  \
					--width=500 \
					--height=500 \
					--column=Device \
					--column=Size \
					--column=used \
					--column=free \
					--column=% \
					--column=Mount \
					$(df |grep -e '^/dev/' )2>/dev/null
			;;
	3) yad --text="Aufwiedersehen" \
  	     --button=gtk-ok:1
		 exit;;
	*) continue
	esac
done	
