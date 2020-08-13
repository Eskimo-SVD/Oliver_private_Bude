#!/usr/bin/python3

import csv
with open('/var/log/temp.csv') as csvfile, \
     open('temperaturen.txt', 'w') as txtout, \
     open('temperaturen.csv', 'w') as csvout:
  cr = csv.reader(csvfile, delimiter=',')
  cw = csv.writer(csvout)
  datumvorher=''
  temperaturen=[]
  # Schleife über alle Zeilen der CSV-Datei
  for line in cr:
    try:
      datum = line[0][:10]  # 1. Spalte, die ersten 10 Zeichen
      temp  = int(line[1][2:]) / 1000 # 2. Spalte, ab dem 2. Zeichen
      if datum==datumvorher:
        # Temperaturwerte in Liste sammeln
        temperaturen.append(temp)
      else:
        if len(temperaturen)>0:
          # Temperaturen ausgeben
          txt = '%s  Minimum: %.1f°C  Maximum: %.1f°C  Durchschnitt: %.1f°C \n'
          tmin =   min(temperaturen)
          tmax =   max(temperaturen)
          tdurch = sum(temperaturen) / len(temperaturen)
          txtout.write(txt % (datumvorher, tmin, tmax, tdurch))
          cw.writerow([datum, '%.1f' % tmin, '%.1f' % tmax, 
                       '%.1f' % tdurch])
        # neue Liste für den nächsten Tag
        temperaturen=[temp]
        datumvorher=datum
    except:
      print('Syntaxfehler in CSV-Datei, die fehlerhafte Zeile lautet:')
      print(line)
      