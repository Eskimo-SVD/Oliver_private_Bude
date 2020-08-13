#!/usr/bin/python3
def f(a, b, **c):
  print(a, b, c)

dict = {'a': 1, 'b': 2, 'x': 3, 'y': 4, 'z': 5}
f(**dict)