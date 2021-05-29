def sortiere(int[:] werte):
    cdef int tmp
    for i in range(len(werte)):
        for j in range(i):
            if werte[i] < werte[j]:
                tmp = werte[i]
                werte[i] = werte[j]
                werte[j] = tmp
