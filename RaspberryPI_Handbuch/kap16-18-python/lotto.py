#!/usr/bin/python3
import random

def ziehung():
    zahlen = set()
    while len(zahlen)<6:
        zahlen = zahlen | {random.randint(1, 49)}
    return zahlen
        
meintipp = {1, 11, 21, 31, 41, 49}
zähler = 0
while 1:
  zähler+=1
  if zähler % 1000000 == 0: break
  if meintipp == ziehung(): break

print("Nach", zähler, "Ziehungen sind Ihre Glückszahlen gezogen worden.")
print("Das hat nur etwa", zähler//100, "Jahre gedauert.")
