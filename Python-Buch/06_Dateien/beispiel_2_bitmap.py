#!/usr/bin/env python

def bytes2int(b):
    res = 0
    for x in b[::-1]:
        res = (res << 8) + x
    return res

f = open("kaffee.bmp", "rb")
f.seek(18)
print("Breite:", bytes2int(f.read(4)), "px")
print("Höhe:", bytes2int(f.read(4)), "px")

f.seek(2, 1)
print("Farbtiefe:", bytes2int(f.read(2)), "bpp")
f.close()
