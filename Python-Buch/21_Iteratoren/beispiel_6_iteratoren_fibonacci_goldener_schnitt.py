#!/usr/bin/env python


class Fibonacci:
    def __init__(self, max_n):
        self.MaxN = max_n
        self.N = 0
        self.A = 0
        self.B = 0

    def __iter__(self):
        self.N = 0
        self.A = 0
        self.B = 1
        return self

    def __next__(self):
        if self.N < self.MaxN:
            self.N += 1
            self.A, self.B = self.B, self.A + self.B
            return self.A
        else:
            raise StopIteration


class GoldenerSchnitt(Fibonacci):
    def __next__(self):
        Fibonacci.__next__(self)
        return self.B / self.A


if __name__ == "__main__":
    for g in GoldenerSchnitt(14):
        print("{:.6f}".format(g), end=" ")
    print()
