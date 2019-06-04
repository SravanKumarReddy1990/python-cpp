# setup.py
from distutils.core import setup
from distutils.extension import Extension
#import numpy as np
 
module1 = Extension('sample', sources = ['pysample.cpp','server.cpp'])
 
setup(name='sample',
        version = '1.0',
        description = "this is a demo package",
        ext_modules = [module1]
        )

#from distutils.core import setup
#from distutils.extension import Extension

#setup(ext_modules = cythonize(Extension(
#           "sample",                 # our Cython source
#           sources=['pysample.c','server.c'],  # additional source file(s)
#           language="g++",             # generate C++ code
#      )))
