def fak(n):
    if n < 0:
        raise ValueError("Keine negativen Zahlen!")

    res = 1
    for i in range(2, n+1):
        res *= i
    return res
