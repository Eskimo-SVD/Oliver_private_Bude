#!/usr/bin/env python

import xml.etree.ElementTree as ElementTree


typen = {
    "int" : int,
    "str" : str
    }


def lese_element(element): 
    typ = element.get("typ", "str")
    try:
        return typen[typ](element.text)
    except KeyError:
        return element.text


def lade_dict(dateiname): 
    d = {}
    baum = ElementTree.parse(dateiname) 
    tag_dict = baum.getroot()
    for eintrag in tag_dict:
        tag_schluessel = eintrag.find("schluessel")
        tag_wert = eintrag.find("wert")
        d[lese_element(tag_schluessel)] = lese_element(tag_wert) 
    return d


if __name__ == "__main__":
    print(lade_dict("dict.xml"))