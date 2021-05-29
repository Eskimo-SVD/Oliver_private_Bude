#!/usr/bin/env python

from concurrent import futures
import sys
import time


def naehere_pi_an(n):
    pi_halbe = 1
    zaehler, nenner = 2.0, 1.0
    
    for i in range(n):
        pi_halbe *= zaehler / nenner
        if i % 2:
            zaehler += 2
        else:
            nenner += 2
            
    return 2*pi_halbe


if __name__ == "__main__":
    start = time.perf_counter()
    N = (34567890, 5432198, 44444444, 22222222, 56565656,
         43236653, 23545353, 32425262)

    if len(sys.argv) != 2:
        print("Missing Parameter: threads, processes or map")
        sys.exit(-1)
    elif sys.argv[1] == "threads":
        with futures.ThreadPoolExecutor(max_workers=4) as e:
            res = e.map(naehere_pi_an, N)
    elif sys.argv[1] == "processes":
        with futures.ProcessPoolExecutor(max_workers=4) as e:
            res = e.map(naehere_pi_an, N)
    else:
        res = map(naehere_pi_an, N)

    print(list(res))
    print(time.perf_counter() - start)
