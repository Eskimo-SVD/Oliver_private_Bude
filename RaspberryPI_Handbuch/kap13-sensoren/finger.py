#!/usr/bin/env python3
# Datei finger.py
import time
from pyfingerprint.pyfingerprint import PyFingerprint

try:
    # Anschluss über GPIO
    f = PyFingerprint('/dev/serial0')
    # Anschluss über USB
    # f = PyFingerprint('/dev/ttyUSB0', 57600, 
    #                   0xFFFFFFFF, 0x00000000)

except Exception as e:
    print('Der Fingerabdrucksensor konnte nicht erkannt werden.')
    print('Fehlermeldung: ' + str(e))
    exit(1)

## Fingerabdruck scannen und mit gespeicherten Werten abgleichen
def finger_abfrage():
    try:
        # warten, bis der Fingerabdruck eingelesen wurde 
        print('Warte auf Finger...')
        while(f.readImage() == False):
            pass

        ## Fingerabdruckdatenbank im Sensor durchsuchen
        f.convertImage(0x01) 
        result = f.searchTemplate()
        positionNumber = result[0]
        accuracyScore = result[1]

       if(positionNumber == -1):
            print('Keine Übereinstimmung gefunden!')
            return 0
        else:
            print('Fingerabdruck gefunden an Position: #' +
                  str(positionNumber))
            print('Die Übereinstimmung ist: ' + 
                  str(accuracyScore))
            return 1

    except Exception as e:
        print('Fehlgeschlagen!')
        print('Fehlermeldung: ' + str(e))
        exit(1)

def finger_neu():
    # neuen Finger anlernen
    try:
        # Finger einlesen
        print('Warte auf Fingerabdruck ...') 
        while(f.readImage() == False):
            pass

        ## prüfen, ob der Fingerabdruck bereits bekannt ist
        f.convertImage(0x01) 
        result = f.searchTemplate()
        positionNumber = result[0]
        if (positionNumber >= 0):
            print('Der Fingerabdruck wurde gefunden an ' + 
                  'Position: ' +  str(positionNumber))
            return 0

        print('Fingerabdruck entfernen...')
        time.sleep(2)
        print('Bitte gleichen Finger noch mal scannen...')

        # Finger zum Abgleich ein weiteres Mal scannen.
        while(f.readImage() == False):
            pass
        f.convertImage(0x02)
        f.createTemplate()

        # dem neuen Fingerabdruck eine Position in der
        # Datenbank des Sensors zuweisen
        positionNumber = f.getTemplateCount()

        if (f.storeTemplate(positionNumber) == True):
            print('Fingerabdruck erfolgreich gespeichert!')
            print('Fingerabdruck gespeichert unter Position: ' + 
                   str(positionNumber))
            return 1

    except Exception as e:
        print('Fehlgeschlagen!')
        print('Fehlermeldung: ' + str(e))
        exit(1)
        
def finger_entfernen():
    print('Aktuell gespeicherte Abdrücke: ' + 
          str(f.getTemplateCount()))
    try:
        positionNumber = raw_input('Welcher Fingerabdruck ' +
                                   'soll gelöscht werden?  ')
        positionNumber = int(positionNumber)

        if (f.deleteTemplate(positionNumber) == True):
            print('Fingerabdruck gelöscht!')
            return 1

    except Exception as e:
        print('Fehlgeschlagen!')
        print('Fehlermeldung: ' + str(e))
        exit(1)
