#----------------------------------------------------
# Dateiname:  pythagoras_einfach.py 
# Einfacher Pythagorasbaum, ein Standardbeispiel für eine
# rekursive Funktion
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 4
# Michael Weigend 20. April 2016
#--------------------------------------------------------------
from turtle import *
from math import sqrt


def baum(c):
    a = c/sqrt(2)
    if c < 10:
        right(90)
        fd(c)
        right(90)
    else:
        fd(c)        
        left(45)
        baum(a)
        left(90)
        baum(a)
        left(45)
        fd(c)

left(90)
baum(40)


     

