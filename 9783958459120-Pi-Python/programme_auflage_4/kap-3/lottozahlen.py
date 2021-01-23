#----------------------------------------------------------------
# Dateiname: lotto.py
# Ziehung der Lottozahlen.
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 3
# Michael Weigend 20. April 2016
#--------------------------------------------------------------
from random import choice
zahlen = list(range(1,50))                        #1
gezogen = []                                      #2

for i in range(6):                                #3
    zahl = choice(zahlen)                         #4
    zahlen.remove(zahl)
    gezogen.append(zahl)

gezogen.sort()
print("Ziehung der Lottozahlen")
for z in gezogen:
    print(z, end="  ")

    



    
