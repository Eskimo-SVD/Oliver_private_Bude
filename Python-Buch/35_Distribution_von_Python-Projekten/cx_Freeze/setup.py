#!/usr/bin/env python

from cx_Freeze import setup, Executable

setup(
     name = "calc",
     version = "1.0",
     executables = [Executable("calc.py")]
     )
