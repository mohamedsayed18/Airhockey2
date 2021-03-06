#!/usr/bin/env python
"""
This file belong to https://github.com/snolfi/evorobotpy
Author: Stefano Nolfi, stefano.nolfi@istc.cnr.it

setupErPredprey.py, python wrapper for predprey.cpp

This file is part of the python module ErPredprey.so that include the following files:
predprey.cpp, predprey.h, robot-env.cpp, robot-env.h, utilities.cpp, utilities.h, ErPredprey.pxd, ErPredprey.pyx and setupErPredprey.py
And can be compiled with cython and installed with the commands: cd ./evorobotpy/lib; python3 setupErPredprey.py build_ext –inplace; cp ErPredprey*.so ../bin
"""

from distutils.core import setup
from distutils.extension import Extension
from Cython.Build import cythonize
from Cython.Distutils import build_ext
import numpy

# linux
#include_gsl_dir = "/usr/include/gsl"
#lib_gsl_dir = "/usr/lib/x86_64-linux-gnu"

# mac os
#include_gsl_dir = "/usr/local/Cellar/gsl/2.4/lib"
#lib_gsl_dir = "/usr/local/Cellar/gsl/2.4/include"

# including the box2d
include_gsl_dir = "/usr/include/box2d"
lib_gsl_dir = "/usr/lib/x86_64-linux-gnu"


setup(
    cmdclass = {'build_ext': build_ext},
    ext_modules = [Extension("ErPredprey",
                             sources=["ErPredprey.pyx"],
                             language="c++",
                             include_dirs=[numpy.get_include(), include_gsl_dir],
			     libraries=["gsl", "gslcblas"],
                 extra_compile_args=['-std=c++11'],
			     library_dirs=[lib_gsl_dir])],
                 runtime_library_dirs=[lib_gsl_dir]
)



