#----------------------------------------------------
# Dateiname:  sierpinski.py 
# Sierpinski-Teppich
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 4
# Michael Weigend 20. April 2016
#--------------------------------------------------------------
from turtle import *
START = 200
STOP = 5

def quadrat(seitenlänge):
    """ Zeichne schwarzes Quadrat"""
    down()              
    color("black", "black")
    begin_fill()
    for i in range(4):
        fd(seitenlänge)
        right(90)
    end_fill()
    up()

def übergang(spaltenbreite):
    """Übergang zur nächsten Spalte"""
    right(90)
    forward(spaltenbreite)
    left(90)

def zurück(seitenlänge):
    """Zurück zur linken unteren Ecke"""
    left(90)
    forward(2*seitenlänge/3)
    right(90)       
    

def sierpinski(x):
    """Zeichne Sierpinski-Teppich"""
    if x <= STOP: return
    for i in range(3):  # linke Spalte
        sierpinski(x/3)
        forward(x/3)
    backward(x)         
    übergang(x/3)
    sierpinski(x/3)     # Mitte
    forward(x/3)
    quadrat(x/3)
    forward(x/3)
    sierpinski(x/3)
    backward(2*x/3)     
    übergang(x/3)
    for i in range(3):  # rechte Spalte
        sierpinski(x/3)
        forward(x/3)
    backward(x)         
    zurück(x)
    
 
clear()
speed(0)
left(90)
up()
sierpinski(START)
hideturtle()


