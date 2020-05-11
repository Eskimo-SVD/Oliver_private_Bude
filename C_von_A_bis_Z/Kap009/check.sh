# Rückgabewert Überprüfen
# Name: check.sh

# Programm starten
./exit_code

# Rückgabewert in ret
ret=$?

# Rückgabewert: 0
if [ ret -eq 0 ] 
then
   echo "Alles Ok: Rückgabewert war 0"
fi

# Rückgabewert: 1
if [ ret -eq 1 ] 
then
   echo "Fehler: Rückgabewert war 1"
fi
