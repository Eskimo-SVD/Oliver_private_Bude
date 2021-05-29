from django.conf.urls import include, url
from . import views

urlpatterns = [
    url(r'^$', views.meldungen, name='meldungen'),
    url(r'^(?P<meldungs_id>\d+)/$', views.meldungen_detail,
                                name='meldungen_detail'),
]
