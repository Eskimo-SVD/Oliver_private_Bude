#----------------------------------------------------------------
# Dateiname: kuerzester_pfad.py
# Berechnung des kürzesten Pfads zwisxchen zwei Knoten
#
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 3.3
# Michael Weigend 20. April 2016
#-------------------------------------------------------------------
G = {"A":[("B", 2), ("C", 5)],
     "B":[("C", 1), ("D", 5)],
     "C":[("A", 5), ("E", 1)],
     "D":[("C", 1), ("E", 2)],
     "E":[]}
     
start = input("Start: ")
ziel = input ("Ziel: ")

nicht_besucht = G.keys()                     # Menge von  Knoten
entfernung = {k:1000000 for k in G.keys()}      # Dictionary für Entfernungen
entfernung[start] = 0          
vorgänger = dict()
          
while nicht_besucht:   
    weglänge, knoten = min([(entfernung[k], k)
                            for k in nicht_besucht])
    nicht_besucht -= {knoten}  
    for nachbar, distanz in G[knoten]:
        
        if (nachbar in nicht_besucht) and \
           (weglänge + distanz < entfernung[nachbar]):          
                vorgänger[nachbar] = knoten
                entfernung[nachbar] = weglänge + distanz

# Weg berechnen
knoten = ziel
weg = []
while knoten in vorgänger.keys():
    weg = [knoten] + weg
    knoten = vorgänger[knoten]

# Ausgabe
print(start, end=" ")
for k in weg:
    print ("-->", k, end=" ")
print ("Entfernung:", entfernung[ziel])

    


    



    
