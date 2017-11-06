#!/usr/bin/env python

from setuptools import setup, Extension

#https://stackoverflow.com/questions/17666018/using-distutils-where-swig-interface-file-is-in-src-folder
from distutils.command.build import build as _build
#Define custom build order, so that the python interface module
#created by SWIG is staged in build_py.
class build(_build):
    # different order: build_ext *before* build_py
    sub_commands = [('build_ext',     _build.has_ext_modules),
                    ('build_py',      _build.has_pure_modules),
                    ('build_clib',    _build.has_c_libraries),
                    ('build_scripts', _build.has_scripts)]

def pagexml_Extension():
    import pkgconfig
    libs = ['opencv','libxml-2.0']
    compile_args = ['-std=c++11']
    link_args = []
    for lib in libs:
        compile_args += pkgconfig.cflags(lib).split()
        link_args += pkgconfig.libs(lib).split()
    return Extension('_pagexml',
                     define_macros = [('__PAGEXML_CVIMG__',''),('SWIG_PYTHON_SILENT_MEMLEAK','')],
                     extra_compile_args = compile_args,
                     extra_link_args = link_args,
                     swig_opts = ['-modern','-c++'],
                     sources = ['pagexml/PageXML.i','pagexml/PageXML.cc'])

def pagexml_Version():
    import re
    with open("pagexml/PageXML.h") as f:
        for line in f:
            if "$Version:" in line:
                line = re.sub(r'.*Version: (\d\d\d\d\.\d\d\.\d\d)\$.*', r'\1', line.strip())
                return re.sub(r'\.0', '.', line)

setup(name = 'pagexml',
      version = pagexml_Version(),
      description = 'Wrapper for PageXML C++ library',
      author = 'Mauricio Villegas',
      author_email = 'mauricio@searchink.com',
      long_description = 'Library for handling of Page XML files.',
      #setup_requires = ['pkgconfig'], # does not install when missing?
      cmdclass = {'build': build}, #Use your own build class
      py_modules = ['pagexml'],
      package_dir = {'' : 'pagexml'},
      ext_modules = [pagexml_Extension()])
