#----------------------------------------------------
# Dateiname:  pythagoras_gefuellt.py 
# Grüner Pythagorasbaum
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 4
# Michael Weigend 20. April 2016
#--------------------------------------------------------------
from turtle import *
from math import sqrt

def baum(x):
    if x < 4:
        fd(x)
        right(90)
        fd (x)
        right(90)
        fd(x)
        return
    else:
        fd(x)
        x_neu = x/sqrt(2)
        left(45)
        baum(x_neu)
        left(90)
        baum(x_neu)
        left(45)
        fd(x)


x = 40
color("green", "green")
speed(0)
clear()
right(180)
begin_fill()
fd(x)
right(90)
baum(x)
end_fill()
ht()
    
    

