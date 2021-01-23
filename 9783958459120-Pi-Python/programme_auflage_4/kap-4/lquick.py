#--------------------------------------------------------------
# Dateiname:  lquick.py 
# Quicksort
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 4
# Michael Weigend 20. April 2016
#--------------------------------------------------------------
import random
def qsort(s):
    if s == []: return []
    else:
        p = s[0]
        s1 = [x for x in s[1:] if x < p]
        s2 = [x for x in s[1:] if x >= p]
        return qsort(s1) + [p] + qsort(s2)  

# Hauptprogramm
s = list(range(16))
random.shuffle(s)
print("Unsortierte Liste:")
print(s)
print("Sortierte Liste:")
print(qsort(s))



