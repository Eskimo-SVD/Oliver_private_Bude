from django.http import HttpResponse, Http404
from django.shortcuts import render

from news.models import Meldung, Kommentar


def meldungen(request):
    zeilen = []
    for m in Meldung.objects.all():
        zeilen.append("Meldung: '{}' vom {}".format(
            m.titel, m.zeitstempel.strftime('%d.%m.%Y um %H:%M')))
        zeilen.append('Text: {}'.format(m.text))
        zeilen += ['', '-' * 30, '']
    antwort = HttpResponse('\n'.join(zeilen))
    antwort['Content-Type'] = 'text/plain'
    return antwort


def meldungen_detail(request, meldungs_id):
    try:
        m = Meldung.objects.get(id=meldungs_id)
    except Meldung.DoesNotExist:
        raise Http404
        
    zeilen = [
        "Titel: '{}' vom {}".format(
            m.titel, m.zeitstempel.strftime('%d.%m.%Y um %H:%M')),
        'Text: {}'.format(m.text),
        '', '-' * 30,
        'Kommentare:', '']
    zeilen += ['{}: {}'.format(k.autor, k.text) 
               for k in m.kommentar_set.all()]
    antwort = HttpResponse('\n'.join(zeilen))
    antwort['Content-Type'] = 'text/plain'
    return antwort

