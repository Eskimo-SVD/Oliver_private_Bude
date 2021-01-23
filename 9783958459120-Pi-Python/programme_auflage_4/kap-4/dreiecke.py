#----------------------------------------------------------------
# Dateiname: dreiecke.py
# Spirale aus Dreiecken.
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 4.15
# Michael Weigend 20. April 2016
#--------------------------------------------------------------

from turtle import *

def dreieck(n):
    for i in range(3):
        forward(n)
        right(120)
    

def figur(n):
    if n >1:     
        dreieck(n)
        right(60)
        figur(n/2)

clear()
speed(0)
left(90)
figur(200)
hideturtle()
     

