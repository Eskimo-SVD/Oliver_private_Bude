#--------------------------------------------------------------
# Zahlenraten
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 2
# Michael Weigend 20. April 2016
#--------------------------------------------------------------

from random import randint               
zufallszahl = randint(1, 100)                               #1

print("Ich habe mir eine Zahl zwischen 1 und 100 ausgedacht.")
print("Rate mal, welche Zahl das ist.")
zahl = int(input("Zahl: "))                                 #2
while zahl != zufallszahl:
    if zahl < zufallszahl:
        print("Zu klein!")
    else:
        print("Zu groß!")
    zahl = int(input("Zahl: "))

print("Richtig!")




