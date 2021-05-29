#!/usr/bin/env python

class A:
    def __init__(self):
        self.X = 1337
        print("Konstruktor von A")
        
    def m(self):
        print("Methode m von A. Es ist self.X =", self.X)
        
        
class B(A):
    def __init__(self):
        super().__init__()
        self.Y = 10000
        print("Konstruktor von B")
        
    def n(self):
        print("Methode n von B. Es ist self.Y =", self.Y)


if __name__ == "__main__":
    b = B()
    b.n()
    b.m()
