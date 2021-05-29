#!/usr/bin/env python

import asyncio
import aiohttp


async def crawl(artikel):
    async with aiohttp.ClientSession() as session:
        koroutinen = [download(session, art) for art in artikel]
        return await asyncio.gather(*koroutinen)


async def download(session, artikel_name):
    url = f"https://de.wikipedia.org/wiki/{artikel_name}"
    async with session.get(url) as response:
        html = await response.text()
        print(f"Ich habe {artikel_name} heruntergeladen.")
        return html


if __name__ == "__main__":
    artikel = [
        "Konrad_Adenauer",
        "Ludwig_Erhard",
        "Kurt_Georg_Kiesinger",
        "Willy_Brandt",
        "Walter_Scheel",
        "Helmut_Schmidt",
        "Helmut_Kohl",
        "Gerhard_Schröder",
        "Angela_Merkel"
    ]
    htmls = asyncio.run(crawl(artikel))

    for artikel_name, html in zip(artikel, htmls):
        with open(f"downloads/{artikel_name}.html", "w") as f_html:
            f_html.write(html)

