#!/usr/bin/env python

class VerwalteterGeldbetrag:
    def __init__(self, anfangsbetrag):
        self.Betrag = anfangsbetrag

    def einzahlenMoeglich(self, betrag):
        return True

    def auszahlenMoeglich(self, betrag):
        return True

    def einzahlen(self, betrag):
        if betrag < 0 or not self.einzahlenMoeglich(betrag):
            return False
        else:
            self.Betrag += betrag
            return True

    def auszahlen(self, betrag):
        if betrag < 0 or not self.auszahlenMoeglich(betrag):
            return False
        else:
            self.Betrag -= betrag
            return True

    def zeige(self):
        print("Betrag: {:.2f}".format(self.Betrag))


class VerwalteterBargeldbetrag(VerwalteterGeldbetrag):
    def __init__(self, bargeldbetrag):
        if bargeldbetrag < 0:
            bargeldbetrag = 0

        super().__init__(bargeldbetrag)

    def auszahlenMoeglich(self, betrag):
        return (self.Betrag >= betrag)


class Geldboerse(VerwalteterBargeldbetrag):
    # TODO: Spezielle Methoden für eine Geldbörse
    pass


class Tresor(VerwalteterBargeldbetrag):
    # TODO: Spezielle Methoden für einen Tresor
    pass


class AllgemeinesKonto(VerwalteterGeldbetrag):
    def __init__(self, kundendaten, kontostand):
        super().__init__(kontostand)
        self.Kundendaten = kundendaten

    def geldtransfer(self, ziel, betrag):
        if self.auszahlenMoeglich(betrag) and ziel.einzahlenMoeglich(betrag):
            self.auszahlen(betrag)
            ziel.einzahlen(betrag)
            return True
        else:
            return False

    def zeige(self):
        self.Kundendaten.zeige()
        VerwalteterGeldbetrag.zeige(self)


class AllgemeinesKontoMitTagesumsatz(AllgemeinesKonto):
    def __init__(self, kundendaten, kontostand, max_tagesumsatz=1500):
        super().__init__(kundendaten, kontostand)
        self.MaxTagesumsatz = max_tagesumsatz
        self.UmsatzHeute = 0.0

    def transferMoeglich(self, betrag):
        return (self.UmsatzHeute + betrag <= self.MaxTagesumsatz)

    def auszahlenMoeglich(self, betrag):
        return (self.transferMoeglich(betrag))

    def einzahlenMoeglich(self, betrag):
        return self.transferMoeglich(betrag)

    def einzahlen(self, betrag):
        if AllgemeinesKonto.einzahlen(self, betrag):
            self.UmsatzHeute += betrag
            return True
        else:
            return False

    def auszahlen(self, betrag):
        if AllgemeinesKonto.auszahlen(self, betrag):
            self.UmsatzHeute += betrag
            return True
        else:
            return False

    def zeige(self):
        AllgemeinesKonto.zeige(self)
        print("Heute schon {:.2f} von {:.2f} Euro umgesetzt".format(self.UmsatzHeute, self.MaxTagesumsatz))


class GirokontoKundendaten:
    def __init__(self, inhaber, kontonummer):
        self.Inhaber = inhaber
        self.Kontonummer = kontonummer

    def zeige(self):
        print("Inhaber:", self.Inhaber)
        print("Kontonummer:", self.Kontonummer)


class NummernkontoKundendaten:
    def __init__(self, identifikationsnummer):
        self.Identifikationsnummer = identifikationsnummer

    def zeige(self):
        print("Identifikationsnummer:", self.Identifikationsnummer)


class Girokonto(AllgemeinesKonto):
    def __init__(self, inhaber, kontonummer, kontostand):
        kundendaten = GirokontoKundendaten(inhaber, kontonummer)
        super().__init__(kundendaten, kontostand)


class Nummernkonto(AllgemeinesKonto):
    def __init__(self, identifikationsnummer, kontostand):
        kundendaten = NummernkontoKundendaten(identifikationsnummer)
        super().__init__(kundendaten, kontostand)


class GirokontoMitTagesUmsatz(AllgemeinesKontoMitTagesumsatz):
    def __init__(self, inhaber, kontonummer, kontostand, max_tagesumsatz=1500):
        kundendaten = GirokontoKundendaten(inhaber, kontonummer)
        super().__init__(kundendaten, kontostand, max_tagesumsatz)


class NummernkontoMitTagesumsatz(AllgemeinesKontoMitTagesumsatz):
    def __init__(self, kontonummer, kontostand, max_tagesumsatz):
        kundendaten = NummernkontoKundendaten(kontonummer)
        super().__init__(kundendaten, kontostand, max_tagesumsatz)


if __name__ == "__main__":
    print("### Beispiel für Girokonto und Nummernkonto ###")
    gk = Girokonto("Heinrich Merkel", 427613185, 5000)
    nk = Nummernkonto(45657364234, 3000)
    gk.auszahlen(1000)
    nk.auszahlen(4000)
    gk.geldtransfer(nk, 2000)
    gk.zeige()
    nk.zeige()

    print()

    print("### Beispiel für ein Nummernkonto ###")
    nk = NummernkontoMitTagesumsatz(123456789, 500, 2000)
    nk.zeige()
    print("---")
    nk.auszahlen(600)
    nk.einzahlen(800)
    nk.zeige()

    print()

    print("#### Beispiel vom Anfang des Kapitels ###")
    k1 = GirokontoMitTagesUmsatz("Heinz Meier", 567123, 12350.0)
    k2 = GirokontoMitTagesUmsatz("Erwin Schmidt", 396754, 15000.0)
    k1.zeige()
    k2.zeige()

    print("---")
    k1.geldtransfer(k2, 160)
    k2.geldtransfer(k1, 1000)
    k2.geldtransfer(k1, 500)

    k2.einzahlen(500)

    k1.zeige()
    k2.zeige()
