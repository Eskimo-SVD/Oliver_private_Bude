cdef extern from "<stdlib.h>" nogil:
    void qsort (void *array, size_t count, size_t size, int (*compare)(const void *, const void *))

cdef int compare(const void* a, const void* b) nogil:
   return (<int*>a)[0] - (<int*>b)[0]

def sortiere(int[:] werte):
    qsort(&werte[0], len(werte), sizeof(int), compare)

