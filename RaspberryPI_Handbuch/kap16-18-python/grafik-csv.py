#!/usr/bin/python3
import csv, pygame, pygame.gfxdraw, time, sys
from pygame.locals import *

# Konstanten
(B, H) = (800, 600)      # Bitmapgröße
(TMIN, TMAX) = (15, 30)  # Temperaturbereich
(ANZTAGE) = 14           # Anzahl der Messpunkte
WHITE  = (255, 255, 255)
RED    = (255, 0, 0)
GREEN  = (0, 255, 0)
BLUE   = (0, 0, 255)

# CSV-Daten in verschachtelte Liste einlesen
data = []
with open('temperaturen.csv') as f:
  cr = csv.reader(f)
  for line in cr:
    data.append(line)
# nur die Daten der letzten n Tage
data = data[-ANZTAGE:]

# pygame initialisieren, Fenster erzeugen
pygame.init()
surf = pygame.display.set_mode((B, H), 0, 32)
surf.fill(WHITE)
pygame.display.set_caption('Temperatur-Plot')
myfont = pygame.font.SysFont('FreeSerif.ttf', 14)

x=20
# Schleife über die Messdaten
for messpunkt in data:
  tmin = float(messpunkt[1])
  tmax = float(messpunkt[2])
  tavg = float(messpunkt[3])
  ymin = int(H - (tmin-TMIN) / (TMAX-TMIN) * H)
  ymax = int(H - (tmax-TMIN) / (TMAX-TMIN) * H)
  yavg = int(H - (tavg-TMIN) / (TMAX-TMIN) * H)
  # Grafikausgabe
  pygame.draw.line(surf, RED, (x, ymin), (x, ymax), 1)
  pygame.draw.line(surf, RED, (x-5, ymin), (x+5, ymin), 1)
  pygame.draw.line(surf, RED, (x-5, ymax), (x+5, ymax), 1)
  pygame.gfxdraw.aacircle(surf, x, yavg, 5, RED)
  pygame.gfxdraw.filled_circle(surf, x, yavg, 5, RED)
  # Durchschnittstemperatur als Text
  txt = u'%.1f°C' % tavg
  textsurf = myfont.render(txt.encode('latin-1'), 1, (0,0,0))
  surf.blit(textsurf, (x+5, yavg-12))
  # X-Koordinate für den nächsten Messpunkt
  x+=B // (ANZTAGE+1)

# Fensterinhalt aktualisieren, auf Tastendruck warten
pygame.display.update()
while 1:
  time.sleep(0.05)
  event = pygame.event.wait()
  if event.type == KEYDOWN or event.type == QUIT: sys.exit()
      