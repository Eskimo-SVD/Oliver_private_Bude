#!/usr/bin/env python
#Datei gps-output.py
# -*- coding: utf-8 -*-
import serial
import sys
import os
import time

# UART öffnen
UART = serial.Serial("/dev/gps0", 9600)
UART.open()

while True:
 GPSChar = 0
 GPSArray = []
 GPSArrayLen = 0
 Hoehe = 0
 Breitengrad = 0
 Laengengrad = 0
 SatDATA = ""
 Zeitstempel = ""
        
 GPSChar = UART.read() 
        
 # nur weitermachen, wenn Daten empfangen werden
 if GPSChar == "$":
 
  # nur Zeilen verwenden, in deren ersten
  # fünf Zeichen "GPGGA" steht
  for Counter in range(5):

    GPSChar = 0
    GPSChar = UART.read()
    SatDATA = SatDATA + str(GPSChar)
    
    if SatDATA == "GPGGA":
      while GPSChar != "\n":
        GPSChar = 0
        GPSChar = UART.read()
        SatDATA = SatDATA + str(GPSChar)
      
      SatDATA = SatDATA.replace("\r\n", "")
      GPSArray = []
      
      # kommaseparierte Liste in Array speichern 
      GPSArray = SatDATA.split(",")
      GPSArrayLen = len(SatDATA)

      # Zeitstempel 
      Zeitstempel = GPSArray[1]
      Zeitstempel = Zeitstempel[0:2] + ":" + Zeitstempel[2:4] + 
                    ":" + Zeitstempel[4:6]

      # Position 
      GPSArray = []
      # kommaseparierte Liste in Array speichern 
      GPSArray = SatDATA.split(",")
      GPSArrayLen = len(SatDATA)

      # Zeitstempel 
      Zeitstempel = GPSArray[1]
      Zeitstempel = Zeitstempel[0:2] + ":" + Zeitstempel[2:4] + 
                    ":" + Zeitstempel[4:6]

      # Position 
      Breitengrad = float(GPSArray[2])
      Breitengrad = Breitengrad / 100

      Laengengrad = float(GPSArray[4])
      Laengengrad = Laengengrad / 100

      # Höhe ueber NN
      Hoehe = float(GPSArray[9])

      # Ausgabe
      print SatDATA
      print ""
      print "Zeitstempel:", Zeitstempel, "GMT"
      print "Position   :", Breitengrad, GPSArray[3], ",", 
            Laengengrad, GPSArray[5]
      print "Hoehe      :", Hoehe, GPSArray[10],"ue. NN"
      
      # GPS-Postition in Datei schreiben
      Position = (str(Breitengrad) + str(GPSArray[3]) + " " + 
                  str(Laengengrad) + str(GPSArray[5]))
      fobj = open("position.txt", "w") 
      fobj.write(Position) 
      fobj.close()

      # Bild von der Raspberry-Kamera aufnehmen
      os.system("raspistill -n -w 640 -h 480 -o gpscam.jpg")
      os.system("convert gpscam.jpg  -pointsize 20 -fill white " +
                "-annotate +470+465 '" + Position + 
                "' gpscam-pos.jpg" )
      sys.exit(0)      
      # Ende

