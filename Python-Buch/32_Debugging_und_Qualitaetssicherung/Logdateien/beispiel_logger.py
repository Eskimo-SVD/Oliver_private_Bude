#!/usr/bin/env python

import logging
import sys


if __name__ == "__main__":
    handler = logging.StreamHandler(sys.stdout)
    frm = logging.Formatter("{asctime} {levelname}: {message}", "%d.%m.%Y %H:%M:%S", style="{")
    handler.setFormatter(frm)

    logger = logging.getLogger()
    logger.addHandler(handler)
    logger.setLevel(logging.DEBUG)

    logger.critical("Ein wirklich kritischer Fehler")
    logger.warning("Und eine Warnung hinterher")
    logger.info("Dies hingegen ist nur eine Info")
