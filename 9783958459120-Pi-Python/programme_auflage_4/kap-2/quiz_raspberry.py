#--------------------------------------------------------------
# quiz.py
# Michael Weigend
# Raspberry Pi programmieren mit Python, 3. Auflage, mitp 2016
# Kap. 2
# Michael Weigend 20. April 2016
#--------------------------------------------------------------


punkte=0                                                    #1

print("Wofür steht das \"Pi\" des Raspberry Pi")
print("(P)ython Interpreter")
print("(K)reiszahl Pi")
print("Public (I)nternet")
antwort = input("Antwort: ")
if (antwort == "p") or (antwort == "P"):
    punkte += 1
    print("Richtig.")
else:
    print("Falsch. Richtig ist: Python Interpreter")

print("Welches Betriebssystem funktioniert auf dem RPi nicht?")
print("(R)ISC 0S")
print("(W)indows 8")
print("(A)rch Linux")
antwort = input("Antwort: ")
if (antwort == "w") or (antwort == "W"):
    punkte += 1
    print("Richtig.")
else:
    print("Falsch. Richtig ist: Windows 8")

print("In welchem Land wurde der RPi entwickelt?")
print("(D)eutschland")
print("(E)ngland")
print("(U)SA")
antwort = input("Antwort: ")
if (antwort == "e") or (antwort == "E"):
    punkte += 1
    print("Richtig.")
else:
    print("Falsch. Richtig ist: England")
if punkte == 3:
    print ("Sie haben alles richtig beantwortet. ", end="")
print("Danke für's Mitmachen!")


