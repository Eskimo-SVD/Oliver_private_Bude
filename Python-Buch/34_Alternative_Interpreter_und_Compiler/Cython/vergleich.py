#!/usr/bin/env python

import sortieren_python
import sortieren_cython
import sortieren_cython2
import sortieren_cython3
import sortieren_cython4

import timeit
import random
import array


def erzeuge_liste():
    werte = array.array("i", range(1000))
    random.shuffle(werte)
    return werte


if __name__ == "__main__":
    t_py  = min(timeit.repeat("sortieren_python.sortiere(werte)", globals=globals(), setup="werte = erzeuge_liste()", number=1, repeat=100))
    t_cy1 = min(timeit.repeat("sortieren_cython.sortiere(werte)", globals=globals(), setup="werte = erzeuge_liste()", number=1, repeat=100))
    t_cy2 = min(timeit.repeat("sortieren_cython2.sortiere(werte)", globals=globals(), setup="werte = erzeuge_liste()", number=1, repeat=100))
    t_cy3 = min(timeit.repeat("sortieren_cython3.sortiere(werte)", globals=globals(), setup="werte = erzeuge_liste()", number=1, repeat=100))
    t_cy4 = min(timeit.repeat("sortieren_cython4.sortiere(werte)", globals=globals(), setup="werte = erzeuge_liste()", number=1, repeat=100))

    print("Python:", t_py)

    print("Cython #1:", t_cy1)
    print("Speedup 1:", t_py / t_cy1)

    print("Cython #2:", t_cy2)
    print("Speedup 2:", t_py / t_cy2)

    print("Cython #3:", t_cy3)
    print("Speedup 3:", t_py / t_cy3)

    print("Cython #4:", t_cy4)
    print("Speedup 4:", t_py / t_cy4)
