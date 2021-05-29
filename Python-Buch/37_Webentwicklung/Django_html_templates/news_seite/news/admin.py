from django.contrib import admin
from .models import Meldung, Kommentar


class KommentarInline(admin.TabularInline):
    model = Kommentar
    extra = 1


class MeldungAdmin(admin.ModelAdmin):    
    inlines = [KommentarInline]


admin.site.register(Meldung, MeldungAdmin)
