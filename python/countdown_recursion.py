#!/usr/bin/python3
#
#
# countdown_recursion.py
#
#
n = 10

def count(n):
  if n > 0:
    print(n)
    count(n-1)
  else:
    print("Blast off!")

count(n)