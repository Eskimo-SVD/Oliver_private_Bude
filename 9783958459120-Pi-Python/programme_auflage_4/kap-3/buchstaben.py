#--------------------------------------------------------------
# buchstaben.py
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 3.3
# Michael Weigend 20. April 2016
#--------------------------------------------------------------
text = input("Geben Sie einen Text ein: ")
buchstaben = set(text)
liste = list(buchstaben)
liste.sort()
for c in liste:
    print("Häufigkeit von " + c + ":", text.count(c))


    
