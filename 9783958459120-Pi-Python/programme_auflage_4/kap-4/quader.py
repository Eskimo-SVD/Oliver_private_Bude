#----------------------------------------------------
# Dateiname:  qudaer.py 
# Funktion zur Quaderberechnung mit Testaufrufen.
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 4
# Michael Weigend 20. April 2016
#--------------------------------------------------------------
def quader(länge, breite, höhe):
    assert type(länge) in [type(1), type(1.0)]
    assert type(breite) in [type(1), type(1.0)]
    assert type(höhe) in [type(1), type(1.0)]
    assert (länge > 0) and (breite > 0) and (höhe > 0)
    volumen = länge * breite * höhe
    return volumen

print (quader(5, 2, 10))
print (quader(5, 2, "10"))

    

    

