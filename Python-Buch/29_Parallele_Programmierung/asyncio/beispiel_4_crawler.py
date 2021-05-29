#!/usr/bin/env python

import asyncio
import aiohttp
import random


async def finde_artikel1(queue):
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
    for artikel_name in artikel:
        await queue.put(artikel_name)
        await asyncio.sleep(random.random())


async def finde_artikel2(queue):
    artikel = [
        "Theodor_Heuss",
        "Heinrich_Lübke",
        "Gustav_Heinemann",
        "Walter_Sheel",
        "Karl_Carstens",
        "Richard_von_Weizsäcker",
        "Roman_Herzog",
        "Johannes_Rau",
        "Horst_Köhler",
        "Christian_Wulff",
        "Joachim_Gauck",
        "Frank-Walter_Steinmeier"
    ]
    for artikel_name in artikel:
        await queue.put(artikel_name)
        await asyncio.sleep(random.random())


async def download(session, i, queue, html_dict):
    while True:
        artikel_name = await queue.get()
        url = f"https://de.wikipedia.org/wiki/{artikel_name}"
        async with session.get(url) as response:
            html_dict[artikel_name] = await response.text()
            print(f"Konsument {i} hat {artikel_name} heruntergeladen.")
        queue.task_done()


async def crawl():
    queue = asyncio.Queue(maxsize=3)
    html_dict = {}

    producers = [
        asyncio.create_task(finde_artikel1(queue)),
        asyncio.create_task(finde_artikel2(queue))
    ]

    async with aiohttp.ClientSession() as session:
        consumers = [asyncio.create_task(download(session, i, queue, html_dict)) for i in range(3)]
        await asyncio.gather(*producers)
        await queue.join()

    for c in consumers:
        c.cancel()
    return html_dict


if __name__ == "__main__":
    html_dict = asyncio.run(crawl())

    for name, html in html_dict.items():
        with open(f"downloads/{name}.html", "w") as f_html:
            f_html.write(html)

