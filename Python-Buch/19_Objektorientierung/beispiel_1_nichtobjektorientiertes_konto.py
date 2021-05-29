#!/usr/bin/env python

def neues_konto(inhaber, kontonummer, kontostand, max_tagesumsatz=1500):
    return {
        "Inhaber" : inhaber,
        "Kontonummer" : kontonummer,
        "Kontostand" : kontostand,
        "MaxTagesumsatz" : max_tagesumsatz,
        "UmsatzHeute" : 0
        }

def geldtransfer(quelle, ziel, betrag):
    # Hier erfolgt der Test, ob der Transfer möglich ist
    if (betrag < 0 or
            quelle["UmsatzHeute"] + betrag > quelle["MaxTagesumsatz"] or
            ziel["UmsatzHeute"] + betrag > ziel["MaxTagesumsatz"]):
       # Transfer unmöglich
       return False
    else:
        # Alles OK - Auf geht's
        quelle["Kontostand"] -= betrag
        quelle["UmsatzHeute"] += betrag
        ziel["Kontostand"] += betrag
        ziel["UmsatzHeute"] += betrag
        return True

def einzahlen(konto, betrag):
    if betrag < 0 or konto["UmsatzHeute"] + betrag > konto["MaxTagesumsatz"]:
        # Tageslimit überschritten oder ungültiger Betrag
        return False
    else:
        konto["Kontostand"] += betrag
        konto["UmsatzHeute"] += betrag
        return True

def auszahlen(konto, betrag):
    if betrag < 0 or konto["UmsatzHeute"] + betrag > konto["MaxTagesumsatz"]:
        # Tageslimit überschritten oder ungültiger Betrag
        return False
    else:
        konto["Kontostand"] -= betrag
        konto["UmsatzHeute"] += betrag
        return True

def zeige_konto(konto):
    print("Konto von {}".format(konto["Inhaber"]))
    print("Aktueller Kontostand: {:.2f} Euro".format(konto["Kontostand"]))
    print("(Heute schon {:.2f} von {} Euro umgesetzt)".format(konto["UmsatzHeute"], konto["MaxTagesumsatz"]))


if __name__ == "__main__":
    k1 = neues_konto("Heinz Meier", 567123, 12350.0)
    k2 = neues_konto("Erwin Schmidt", 396754, 15000.0)
    geldtransfer(k1, k2, 160)
    geldtransfer(k2, k1, 1000)
    geldtransfer(k2, k1, 500)
    einzahlen(k2, 500)
    zeige_konto(k1)
    zeige_konto(k2)
