#--------------------------------------------------------------
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 3
# Michael Weigend 20. April 2016
#--------------------------------------------------------------
a = int(input("Anzahl der Iterationen: "))
e = 1
z = 1
for i in range(1, a+1):
    z *= i
    e += 1/z
    print (e)

    
   
