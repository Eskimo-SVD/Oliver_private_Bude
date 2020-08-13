#!/usr/bin/python3
import math, pygame, time, sys
from pygame.locals import *

# Konstanten
(B, H) = (1000, 700)       # Größe des Zeichenbereichs
bhalbe = (B-30)/2
hhalbe = (H-20)/2

# pygame initialisieren, Fenster erzeugen
pygame.init()
surf = pygame.display.set_mode((B, H), 0, 32)
pygame.display.set_caption('Grafikprogrammierung mit pygame')

for i in range(1500):
  winkel = 0.05 + 2 * math.pi * i / 1500
  farbe = (100+math.sin(winkel)*100, 
           100+math.sin(winkel+math.pi/2)*100, 
           100+math.sin(winkel+math.pi)*100)
  x = bhalbe + math.sin(winkel*5) * bhalbe
  y = hhalbe + math.sin(winkel*4) * hhalbe
  b = 30
  h = 20
  pygame.draw.rect(surf, farbe, (x, y, b, h))
  pygame.draw.rect(surf, (255, 255, 255), (x, y, b, h), 1)

# Fensterinhalt aktualisieren, auf Tastendruck warten
pygame.display.update()
while 1:
  time.sleep(0.05)
  event = pygame.event.wait()
  if event.type == KEYDOWN or event.type == QUIT: sys.exit()
      