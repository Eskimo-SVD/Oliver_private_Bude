#----------------------------------------------------
# Dateiname:  lsumme.py 
# Rekursive Berechnung der Summe von Zahlen in einer Liste.
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 4
# Michael Weigend 20. April 2016
#--------------------------------------------------------------
import random
def summe(s):
    if len(s) == 0:                   #1
        return 0
    elif len(s) == 1:
        return s[0]            
    else:
        mitte = len(s)//2             #2
        s1 = s[:mitte]
        s2 = s[mitte:]
        return summe(s1) + summe(s2)  #3

# Hauptprogramm

s = [random.randint(0, 100) for i in range(10)]
print ("Zufällige Zahlenliste:")
print (s)
print("Summe:", summe(s))



