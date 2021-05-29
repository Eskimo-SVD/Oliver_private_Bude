import random


def verwirble_text(text):
    liste = []
    for wort in text.split():
        w = list(wort[1:-1])
        random.shuffle(w)
        liste.append(wort[0] + "".join(w) + wort[-1])
    return " ".join(liste)
