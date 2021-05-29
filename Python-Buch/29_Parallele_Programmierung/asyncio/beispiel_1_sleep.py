#!/usr/bin/env python

import asyncio


async def sleep_print(n):
    print(f"Ich warte {n} Sekunden ...")
    await asyncio.sleep(n)
    print(f"... ich bin wieder da (nach {n} Sekunden)!")
    return n


async def programm1():
    await sleep_print(5)
    await sleep_print(2)
    await sleep_print(1)


async def programm2():
    task1 = asyncio.create_task(sleep_print(5))
    task2 = asyncio.create_task(sleep_print(2))
    task3 = asyncio.create_task(sleep_print(1))

    await task1
    await task2
    await task3


async def programm3():
    await asyncio.gather(
        sleep_print(5),
        sleep_print(2),
        sleep_print(1)
    )


if __name__ == "__main__":
    print("Programm 1:")
    asyncio.run(programm1())

    print("Programm 2:")
    asyncio.run(programm2())

    print("Programm 3:")
    asyncio.run(programm3())
