#!/usr/bin/env python


class Fibonacci3:
    class FibonacciIterator:
        def __init__(self, max_n):
            self.MaxN = max_n
            self.N, self.A, self.B = 0, 0, 1

        def __iter__(self):
            return self

        def __next__(self):
            if self.N < self.MaxN:
                self.N += 1
                self.A, self.B = self.B, self.A + self.B
                return self.A
            else:
                raise StopIteration

    def __init__(self, max_n):
        self.MaxN = max_n

    def __iter__(self):
        return self.FibonacciIterator(self.MaxN)


if __name__ == "__main__":
    l = Fibonacci3(3)
    for i in l:
        for j in l:
            print(i,j, end=", ")
        print()

