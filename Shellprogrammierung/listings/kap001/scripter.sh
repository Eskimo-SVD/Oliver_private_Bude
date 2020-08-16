# Ein Script zum Script erstellen ...

# Bitte entsprechend anpassen
#
# Verzeichnis wo sich das Script befindet
dir=$HOME
# Editor, der verwendet werden soll
editor=vi  

# erstes Argument muss der Scriptname sein ...
[ -z "$1" ] && exit 1

# Editor starten und Script laden (oder erzeugen)
$editor $dir/$1

# Ausführrechte für User setzen ...
chmod u+x $dir/$1

# Script gleich ausführen? Nein, dann auskommentieren ...
$dir/$1