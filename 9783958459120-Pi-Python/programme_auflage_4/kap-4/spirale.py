#---------------------------------------------------------------
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 4
# Michael Weigend 20. April 2016
#--------------------------------------------------------------
from turtle import *
MAX = 200


def spirale(n):
    if n < MAX:
        forward(n)
        right(90)
        spirale(n+5)
        
        
spirale(5)

     

