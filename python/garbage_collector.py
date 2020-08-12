#!/usr/bin/python3

# 100 Absätze in html schreiben

s = ''
for i in range(1, 101):
    s+= '<p>Absatz ' + str(i) + '\n '
f = open('out.html ', 'w')
f.write (s)
f.close ()
