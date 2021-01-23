#----------------------------------------------------
# Dateiname:  pythagoras_zufall.py 
# Pythagorasbaum mit Zufallselementen
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 4
# Michael Weigend 20. April 2016
#--------------------------------------------------------------
from turtle import *
from math import sqrt
from random import random
START = 80
STOP = 5

def baum(c):
    a = c/sqrt(2)
    if c < STOP:
        right(90)
        fd(c)
        right(90)
    else:
        zufall = c*(0.8 + random())
        fd(zufall)        
        left(45)
        baum(a)
        left(90)
        baum(a)
        left(45)
        fd(zufall)

speed(0)
left(90)
color("blue", "blue")
begin_fill()
baum(START)
right(90)
fd(START)
end_fill()
ht()


     

