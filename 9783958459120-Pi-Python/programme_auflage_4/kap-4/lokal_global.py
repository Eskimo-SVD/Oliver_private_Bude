#----------------------------------------------------
# Dateiname:  lokal_global.py.py 
# Testprogramm globale Variable und Seiteneffekt 
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 4
# Michael Weigend 20. April 2016
#--------------------------------------------------------------
def f():
    global n
    n += 1           # Seiteneffekt

# Hauptprogramm
n = 1
f()
print(n)   # n wurde von f() geändert

