#--------------------------------------------------------------
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 4
# Michael Weigend 20. April 2016
#--------------------------------------------------------------
from turtle import *

def quadrat(n):
    for i in range(4):
        forward(n)
        right(90)
    

def spirale(n):
    if n >5:
        quadrat(n)
        right(15)
        spirale(n*0.9)

clear()
spirale(100)
     

