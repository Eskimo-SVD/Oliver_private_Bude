#--------------------------------------------------------------
# Dateiname:  haeufigster.py.py 
# 
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 4
# Michael Weigend 20. April 2016
#--------------------------------------------------------------

def häufigster (sammlung):
    items = set(sammlung)
    häufigkeitsliste = [(sammlung.count(i), i) for i in items]
    häufigkeit, item = max(häufigkeitsliste)
    return item, häufigkeit

s = ["Conny", "Monika", "Valentina", "Mike", "Michael",
     "Marion", "Doris", "Monika", "Klaus", "Vanessa"]

n, h = häufigster(s)

print (n, h, "Mal")
