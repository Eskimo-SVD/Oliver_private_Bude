#----------------------------------------------------------------
# Dateiname: passwort.py
# Erzeugung eines sicheren und lesbaren Passworts
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 3.5.4
# Michael Weigend 20. April 2016
#--------------------------------------------------------------
vokale="aeiouy"
konsonanten="bdfghjklmnprstvwxz"
anfangsgruppen = ["st", "sch", "sp", "qu", "kr", "bl", "kl"]
endgruppen = ["ch", "ng", "rt", "ll", "tt", "ss", "mm", "nn"]
ziffern = "123456789"

from random import randint

print ("Sichere und lesbare Passwörter")
antwort = "j"
while antwort == "j":
    z1_vok = randint(0,len(vokale)-1)
    z2_vok = randint(0,len(vokale)-1)
    z_kons = randint(0,len(konsonanten)-1)
    z_anfang = randint(0,len(anfangsgruppen)-1)
    z_ende = randint(0,len(endgruppen)-1)
    z_ziffern = randint(0,8)
    
    pw = anfangsgruppen[z_anfang] + vokale[z1_vok] + \
         konsonanten[z_kons] + vokale[z2_vok] + \
         endgruppen[z_ende] + ziffern[z_ziffern]
    print ("Ihr Passwort: ", pw)
    antwort = input("Noch ein Passwort? (j/n): ")
print("Auf Wiedersehen.")


