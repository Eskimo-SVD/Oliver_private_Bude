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


if __name__ == "__main__":
    for f in Fibonacci(14):
        print(f, end=" ")
    print()

    print(list(Fibonacci(16)))
