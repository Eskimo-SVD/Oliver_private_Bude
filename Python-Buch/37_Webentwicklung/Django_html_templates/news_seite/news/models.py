from django.db import models


class Meldung(models.Model):
    titel = models.CharField(max_length=100)
    zeitstempel = models.DateTimeField()
    text = models.TextField('Meldungstext')

    def __str__(self):
        return self.titel


class Kommentar(models.Model):
    meldung = models.ForeignKey(Meldung, on_delete=models.CASCADE)
    autor = models.CharField(max_length=70)
    text = models.TextField('Kommentartext')

    def __str__(self):
        return "{} sagt '{}'".format(self.autor, self.text)
