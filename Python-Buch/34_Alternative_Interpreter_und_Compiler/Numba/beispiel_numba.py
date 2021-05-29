#!/usr/bin/env python

import timeit
import numba


def naehere_pi_an(n):
    pi_halbe = 1
    zaehler, nenner = 2.0, 1.0
    for i in range(n):
        pi_halbe *= zaehler / nenner
        if i % 2:
            zaehler += 2
        else:
            nenner += 2
    return 2 * pi_halbe


@numba.jit
def naehere_pi_an_jit(n):
    pi_halbe = 1
    zaehler, nenner = 2.0, 1.0
    for i in range(n):
        pi_halbe *= zaehler / nenner
        if i % 2:
            zaehler += 2
        else:
            nenner += 2
    return 2 * pi_halbe


@numba.njit
def naehere_pi_an_njit(n):
    pi_halbe = 1
    zaehler, nenner = 2.0, 1.0
    for i in range(n):
        pi_halbe *= zaehler / nenner
        if i % 2:
            zaehler += 2
        else:
            nenner += 2
    return 2 * pi_halbe


if __name__ == "__main__":
    t1 = timeit.timeit("naehere_pi_an(1000)", globals=globals(), number=10000)
    t2 = timeit.timeit("naehere_pi_an_jit(1000)", setup="naehere_pi_an_jit(1000)", globals=globals(), number=10000)
    t3 = timeit.timeit("naehere_pi_an_njit(1000)", setup="naehere_pi_an_njit(1000)", globals=globals(), number=10000)

    print("Laufzeit ohne Numba:", t1)

    print("Laufzeit mit Numba (jit): ", t2)
    print("Speedup:", t1/t2)

    print("Laufzeit mit Numba (njit): ", t3)
    print("Speedup:", t1/t3)
