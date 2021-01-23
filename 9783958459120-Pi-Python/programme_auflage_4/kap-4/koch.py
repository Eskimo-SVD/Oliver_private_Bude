#----------------------------------------------------------------
# Dateiname: koch.py
# Schneeflocke von Koch
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 4.12
# Michael Weigend 20. April 2016
#--------------------------------------------------------------
from turtle import *
STOP = 2
START = 200

def seite(n):
    if n <= STOP:
        fd(n)    
    else:
       seite(n/3)
       left(60)
       seite(n/3)
       right(120)
       seite(n/3)
       left(60)
       seite(n/3)
        
clear()
speed(0)
left(60)
for i in range(3):
    seite(START)
    right(120)

hideturtle()
     

