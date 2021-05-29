#!/usr/bin/env python

from setuptools import setup
from Cython.Build import cythonize


setup(
    ext_modules = cythonize("sortieren_cython.pyx")
)
setup(
    ext_modules = cythonize("sortieren_cython2.pyx")
)
setup(
    ext_modules = cythonize("sortieren_cython3.pyx")
)
setup(
    ext_modules = cythonize("sortieren_cython4.pyx")
)
