#!/usr/bin/env python

geheimnis = 1337
versuch = -1
zaehler = 0

while versuch != geheimnis:
    versuch = int(input("Raten Sie: "))
    
    if versuch == 0:
        print("Das Spiel wird beendet")
        break

    if versuch < geheimnis:
        print("Zu klein")
    if versuch > geheimnis:
        print("Zu groß")

    zaehler = zaehler + 1

print("Sie haben es geschafft!")
