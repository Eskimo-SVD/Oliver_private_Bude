#!/usr/bin/env python

class Konto:
    def __init__(self, inhaber, kontonummer, kontostand, max_tagesumsatz=1500):
        self.Inhaber = inhaber
        self.Kontonummer = kontonummer
        self.Kontostand = kontostand
        self.MaxTagesumsatz = max_tagesumsatz
        self.UmsatzHeute = 0

    def geldtransfer(self, ziel, betrag):
        # Hier erfolgt der Test, ob der Transfer möglich ist
        if (betrag < 0 or
                self.UmsatzHeute + betrag > self.MaxTagesumsatz or
                ziel.UmsatzHeute + betrag > ziel.MaxTagesumsatz):
            # Transfer unmöglich
            return False
        else:
            # Alles OK - Auf geht's
            self.Kontostand -= betrag
            self.UmsatzHeute += betrag
            ziel.Kontostand += betrag
            ziel.UmsatzHeute += betrag
            return True

    def einzahlen(self, betrag):
        if betrag < 0 or self.UmsatzHeute + betrag > self.MaxTagesumsatz:
            # Tageslimit überschritten oder ungültiger Betrag
            return False
        else:
            self.Kontostand += betrag
            self.UmsatzHeute += betrag
            return True

    def auszahlen(self, betrag):
        if betrag < 0 or self.UmsatzHeute + betrag > self.MaxTagesumsatz:
            # Tageslimit überschritten oder ungültiger Betrag
            return False
        else:
            self.Kontostand -= betrag
            self.UmsatzHeute += betrag
            return True

    def zeige(self):
        print("Konto von {}".format(self.Inhaber))
        print("Aktueller Kontostand: {:.2f} Euro".format(self.Kontostand))
        print("(Heute schon {:.2f} von {} Euro umgesetzt)".format(self.UmsatzHeute, self.MaxTagesumsatz))


if __name__ == "__main__":
    k1 = Konto("Heinz Meier", 567123, 12350.0)
    k2 = Konto("Erwin Schmidt", 396754, 15000.0)

    k1.geldtransfer(k2, 160)
    k2.geldtransfer(k1, 1000)
    k2.geldtransfer(k1, 500)
    k2.einzahlen(500)

    k1.zeige()
    k2.zeige()

