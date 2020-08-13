#!/usr/bin/python3
import pygame, time, sys
from pygame.locals import *
from random import randrange

# Konstanten
(B, H) = (800, 500)       # Größe des Zeichenbereichs

# pygame initialisieren, Fenster erzeugen
pygame.init()
surf = pygame.display.set_mode((B, H), 0, 32)
pygame.display.set_caption('Grafikprogrammierung mit pygame')
surf.fill( (128,128,128) )    # grauer Hintergrund

# 1000 zufällige Rechtecke zeichnen
for i in range(1000):
  farbe = (randrange(256), randrange(256), randrange(256))
  x = randrange(B-50)
  y = randrange(H-50)
  b = 10+randrange(40)
  h = 10+randrange(40)
  pygame.draw.rect(surf, farbe, (x, y, b, h))

# Fensterinhalt aktualisieren, auf Tastendruck warten
pygame.display.update()
while 1:
  time.sleep(0.05)
  event = pygame.event.wait()
  if event.type == KEYDOWN or event.type == QUIT: sys.exit()
      