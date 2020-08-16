#!/bin/bash

TEMP=$(mktemp)
DIALOG=dialog

NAME=$($DIALOG --inputbox "Wie heißen Sie : " 0 0 3>&1 1>&2 2>&3)
$DIALOG --clear
$DIALOG --msgbox "Hallo $NAME " 5 30
ls -l $HOME > $TEMP
$DIALOG --textbox "$TEMP" 0 0
$DIALOG --clear
rm $TEMP
clear
