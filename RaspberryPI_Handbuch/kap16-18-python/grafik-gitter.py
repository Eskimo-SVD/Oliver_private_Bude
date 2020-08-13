#!/usr/bin/python3
import pygame, time, sys
from pygame.locals import *

# Konstanten
(B, H) = (900, 600)       # Größe des Zeichenbereichs
WHITE  = (255, 255, 255)
BLAU   = (0,0,180)

# pygame initialisieren, Fenster erzeugen
pygame.init()
surf = pygame.display.set_mode((B, H), 0, 32)
pygame.display.set_caption('Grafikprogrammierung mit pygame')
surf.fill(WHITE)

# Gitter zeichnen
(xmin, xmax, ymin, ymax) = (1, B-2, 1, H-2)
for i in range(0,101):
  n = i/100.0
  x1=xmin+(xmax-xmin)*n
  x2=xmax-(xmax-xmin)*n
  y1=ymin+(ymax-ymin)*n
  y2=ymax-(ymax-ymin)*n
  pygame.draw.aaline(surf, BLAU, (xmin, y2), (x1, ymin))
  pygame.draw.aaline(surf, BLAU, (xmin, y1), (x1, ymax))
  pygame.draw.aaline(surf, BLAU, (x2, ymin), (xmax, y2))
  pygame.draw.aaline(surf, BLAU, (x2, ymax), (xmax, y1))

# Fensterinhalt aktualisieren, auf Tastendruck warten
pygame.display.update()
while 1:
  time.sleep(0.05)
  event = pygame.event.wait()
  if event.type == KEYDOWN or event.type == QUIT: sys.exit()
      