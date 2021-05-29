#!/usr/bin/env python

import timeit


def fak1(n):
    res = 1
    for i in range(2, n+1):
        res *= i
    return res


def fak2(n):
    if n > 0:
        return fak2(n-1)*n
    else:
        return 1


if __name__ == "__main__":
    t1 = timeit.Timer("fak1(50)", globals=globals())
    t2 = timeit.Timer("fak2(50)", globals=globals())

    print("Iterativ: ", t1.timeit())
    print("Rekursiv: ", t2.timeit())

    print("Iterativ: ", min(t1.repeat(100, 10000)))
    print("Rekursiv: ", min(t2.repeat(100, 10000)))
