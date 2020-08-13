#!/usr/bin/python3
import pygame, time, sys
from pygame.locals import *

# Konstanten
(B, H) = (500, 300)
WHITE  = (255, 255, 255)
RED    = (255, 0, 0)
GREEN  = (0, 255, 0)
BLUE   = (0, 0, 255)

# pygame initialisieren, Fenster erzeugen
pygame.init()
surf = pygame.display.set_mode((B, H), 0, 32)
pygame.display.set_caption('Grafikprogrammierung mit pygame')

# weißer Hintergrund
surf.fill(WHITE)

# Linie, vier Pixel breit
pygame.draw.line(surf, RED, (10,10), (200, 100), 4)

# gefülltes Rechteck (x, y, b, h)
pygame.draw.rect(surf, GREEN, (350, 50, 100, 20))

# gefülltes Dreieck
pygame.draw.polygon(surf, BLUE, [(200,50), (300,200), (400,150)])

# Kreis
pygame.draw.circle(surf, RED, (200, 200), 50)

# Textausgabe
myfont = pygame.font.SysFont('FreeSerif.ttf', 24)
textsurf = myfont.render('Hello World!', 1, (0,0,0))
surf.blit(textsurf, (20, 80))

msg = u'abc äöüß'
msg = msg.encode('latin-1')
textsurf = myfont.render(msg, 1, WHITE, RED)
surf.blit(textsurf, (20, 120))

#for i in range(101):
#  n = i/100.0;
#  col = (255*n, 0, 0)
#  pygame.draw.aaline(surf, col, (1, 1+H*n), (1+B*(1-n), 1))

# Fensterinhalt aktualisieren
pygame.display.update()

# auf Tastendruck warten
while 1:
  event = pygame.event.wait()
  if event.type == KEYDOWN:
    # pygame.quit()
    sys.exit()
  time.sleep(0.05)
      