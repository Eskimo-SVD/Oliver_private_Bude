from libc.stdlib cimport qsort

cdef int compare(const void* a, const void* b) nogil:
   return (<int*>a)[0] - (<int*>b)[0]

cpdef sortiere(int[:] werte):
    qsort(&werte[0], len(werte), sizeof(int), compare)

