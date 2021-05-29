from django.http import HttpResponse, Http404, HttpResponseRedirect
from django.shortcuts import render, get_object_or_404
from django.template import RequestContext, loader

from .models import Meldung, Kommentar


def meldungen(request):
    return render(request, 'news/meldungen.html',
        context={'meldungen' : Meldung.objects.all()})


def meldungen_detail(request, meldungs_id):
    meldung = get_object_or_404(Meldung, id=meldungs_id)
    
    if 'speichere_kommentar' in request.POST:
        name = request.POST.get('besuchername', '')
        text = request.POST.get('kommentartext', '')
        
        if name and text:
            kommentar = meldung.kommentar_set.create(
                autor=name, text=text)
            kommentar.save()
            return HttpResponseRedirect('.')
        
        else:
            return render(request, 'news/meldungen_detail.html',
                context={'meldung' : meldung,
                         'fehler': 'Geben Sie Ihren Namen und ' \
                                   'einen Kommentar an.',
                         'besuchername' : name, 'kommentartext' : text})
    
    return render(request, 'news/meldungen_detail.html',
        context={'meldung' : meldung})


