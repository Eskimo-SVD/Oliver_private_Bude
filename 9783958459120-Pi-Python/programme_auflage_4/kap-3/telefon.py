#----------------------------------------------------------------
# Dateiname: telefon.py
# Telefonnummern finden
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 3.8.6
# Michael Weigend 20. April 2016
#--------------------------------------------------------------
tel = [("Tom", "10552"),
       ("Max", "8110"),
       ("Tina", "23577"),
       ("Anna", "02012 4692")]

antwort = "j"
while antwort =="j":
    a = input("Anfangsbuchstabe: ")
    for (n, t) in tel:
        if n[0] == a:
            print (n, "Tel:", t)
    antwort = input("Weitere Nummern(j/n)?: ")
print ("Auf Wiedersehen!")

    
