#!/usr/bin/env python

import asyncio
import random


async def async_range(n):
    for i in range(n):
        await asyncio.sleep(random.random())
        yield i


async def koroutine(name, n):
    async for i in async_range(n):
        print(f"Aktuelles Element von {name}: {i}")


async def main():
    await asyncio.gather(
        koroutine("Iterator 1", 10),
        koroutine("Iterator 2", 10)
    )


if __name__ == "__main__":
    asyncio.run(main())
