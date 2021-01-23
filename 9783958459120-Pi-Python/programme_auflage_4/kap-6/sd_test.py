#!/usr/bin/python3
#----------------------------------------------------------------
# Dateiname: sd_test.py
# Wie viel Zeit wird zum Schreiben von 10 MB benötigt?
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 6.2
# Michael Weigend 20. April 2016
#--------------------------------------------------------------
from time import time 

data = 1000000*b"qwertzuiop"
intervals=[]

for i in range(10):
    startTime =  time()
    f=open("test.dat", "wb")
    f.write(data)
    f.close()
    intervals.append(time() - startTime)


for t in intervals:
    print(t)


    
