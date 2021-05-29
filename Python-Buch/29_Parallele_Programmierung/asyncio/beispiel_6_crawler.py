#!/usr/bin/env python

import asyncio
import aiohttp
import aiofiles
import time
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


def process(html):
    time.sleep(random.random())
    return html


async def download(session, i, queue):
    loop = asyncio.get_event_loop()
    while True:
        artikel = await queue.get()
        url = f"https://de.wikipedia.org/wiki/{artikel}"
        async with session.get(url) as response:
            html = await response.text()
            html = await loop.run_in_executor(None, process, html)
            async with aiofiles.open(f"downloads/{artikel}.html", "w") as f:
                await f.write(html)
                print(f"Konsument {i} hat {artikel} heruntergeladen.")
        queue.task_done()


async def crawl():
    queue = asyncio.Queue(maxsize=3)
    producers = [
        asyncio.create_task(finde_artikel1(queue)),
        asyncio.create_task(finde_artikel2(queue))
    ]

    async with aiohttp.ClientSession() as session:
        consumers = [asyncio.create_task(download(session, i, queue)) for i in range(3)]
        await asyncio.gather(*producers)
        await queue.join()

    for c in consumers:
        c.cancel()


if __name__ == "__main__":
    asyncio.run(crawl())

