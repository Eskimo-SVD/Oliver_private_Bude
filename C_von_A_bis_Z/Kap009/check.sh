# R�ckgabewert �berpr�fen
# Name: check.sh

# Programm starten
./exit_code

# R�ckgabewert in ret
ret=$?

# R�ckgabewert: 0
if [ ret -eq 0 ] 
then
   echo "Alles Ok: R�ckgabewert war 0"
fi

# R�ckgabewert: 1
if [ ret -eq 1 ] 
then
   echo "Fehler: R�ckgabewert war 1"
fi
