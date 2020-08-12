#!/usr/bin/python3

import sys
print( '1 wird von Python ', sys.getrefcount (1) ,
'-mal verwendet ')
print( '15 wird von Python ', sys.getrefcount (15) ,
'-mal verwendet ')
print(" ' ' wird von Python " , sys.getrefcount (' '),
'-mal verwendet ')
# Ergebnisse im Python -Interpreter 3.7 unter Raspbian
# 1 wird von Python 149 -mal verwendet
# 15 wird von Python 15-mal verwendet
# ' ' wird von Python 7-mal verwendet
