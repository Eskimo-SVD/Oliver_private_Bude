#!/usr/bin/env python

import asyncio
import aiohttp


def finde_artikel(queue):
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
        queue.put_nowait(artikel_name)


async def download(session, i, queue, html_dict):
    while True:
        artikel_name = await queue.get()
        url = f"https://de.wikipedia.org/wiki/{artikel_name}"
        async with session.get(url) as response:
            html_dict[artikel_name] = await response.text()
            print(f"Konsument {i} hat {artikel_name} heruntergeladen.")
        queue.task_done()


async def crawl():
    queue = asyncio.Queue()
    finde_artikel(queue)

    html_dict = {}
    async with aiohttp.ClientSession() as session:
        consumers = [asyncio.create_task(download(session, i, queue, html_dict)) for i in range(3)]
        await queue.join()

    for c in consumers:
        c.cancel()
    return html_dict


if __name__ == "__main__":
    html_dict = asyncio.run(crawl())

    for name, html in html_dict.items():
        with open(f"downloads/{name}.html", "w") as f_html:
            f_html.write(html)

