#!/usr/bin/env python


class Fibonacci2:
    def __init__(self, max_n):
        self.MaxN = max_n

    def __iter__(self):
        n = 0
        a, b = 0, 1
        for n in range(self.MaxN):
            a, b = b, a + b
            yield a


if __name__ == "__main__":
    for f in Fibonacci2(14):
        print(f, end=" ")
    print()

    print(list(Fibonacci2(16)))
