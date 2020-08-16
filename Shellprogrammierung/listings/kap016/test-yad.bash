#! /bin/bash
array=($(yad \
--item-separator="," \
--separator="\\n" \
--form \
--field="Vorname:CBE" Text \
--field="Nachname:CBE" Text \
--field="Wähle einen Wert":NUM 5,1..10,1))

yad --info --text="Der Wert ist ${array[*]}"

