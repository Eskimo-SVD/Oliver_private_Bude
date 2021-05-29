#!/usr/bin/env python

import re


if __name__ == "__main__":
    with open("rheinwerk-verlag.html", "r") as f:
        html = f.read()

    it = re.finditer(r"<a .*?href=[\"\'](.*?)[\"\'].*?>(.*?)</a>", html, re.I)
    for n, m in enumerate(it):
        print("#{} Name: {}, Link: {}".format(n, m.group(2), m.group(1)))
