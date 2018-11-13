#!/usr/bin/env python

from setuptools import setup, find_packages, Extension, Command
import subprocess
import sysconfig
import sys
import os
import re

try:
    from sphinx.setup_command import BuildDoc
except ImportError:
    BuildDoc = False
    print('warning: sphinx not found, build_sphinx target will not be available.')

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


def textfeat_Extension():
    import pkgconfig
    libs = ['Magick++','libxml-2.0']
    compile_args = ['-std=c++11']
    link_args = []
    for lib in libs:
        compile_args += pkgconfig.cflags(lib).split()
        link_args += pkgconfig.libs(lib).split()
    if not pkgconfig.cflags('opencv'):
        raise FileNotFoundError('pkgconfig did not find opencv development')
    compile_args += pkgconfig.cflags('opencv').split()
    cvre = re.compile('^-L|^-lopencv_core|^-lopencv_imgproc|^-lopencv_imgcodecs|^-lopencv_flann')
    link_args += [x for x in pkgconfig.libs('opencv').split() if cvre.match(x)]
    cvinc = pkgconfig.cflags('opencv').split()[0].rsplit('/opencv',1)[0]
    return Extension('_textfeat',
                     define_macros = [('__PAGEXML_IMG_CV__',''),('__PAGEXML_MAGICK__',''),('SWIG_PYTHON_SILENT_MEMLEAK','')],
                     extra_compile_args = compile_args,
                     extra_link_args = link_args,
                     swig_opts = [cvinc,'-modern','-keyword','-c++'],
                     sources = ['textfeat/TextFeatExtractor.i','textfeat/TextFeatExtractor.cc','textfeat/intimg.cc','textfeat/mem.cc'])


def distutils_dir_name(dname):
    """Returns the name of a distutils build directory"""
    f = "{dirname}.{platform}-{version[0]}.{version[1]}"
    return f.format(dirname=dname,
                    platform=sysconfig.get_platform(),
                    version=sys.version_info)

sys.path = [ os.path.join(os.path.dirname(os.path.realpath(__file__)), 'build', distutils_dir_name('lib'))] + sys.path


def textfeat_Version():
    with open("textfeat/TextFeatExtractor.h") as f:
        for line in f:
            if 'Version:' in line:
                line = re.sub(r'.*Version: (\d\d\d\d\.\d\d\.\d\d)\$.*', r'\1', line.strip())
                return re.sub(r'\.0', '.', line)


NAME = 'textfeat'
DESCRIPTION = 'Wrapper for TextFeatExtractor C++ library'
LONG_DESCRIPTION = 'Library for extracting features for text recognition.'
__version__ = textfeat_Version()


CMDCLASS = {'build': build}
if BuildDoc:
    class BuildDocTextFeatExtractor(BuildDoc):
        def run(self):
            import textfeat
            super().run()

    CMDCLASS['build_sphinx'] = BuildDocTextFeatExtractor


setup(name=NAME,
      version=__version__,
      description=DESCRIPTION,
      long_description=LONG_DESCRIPTION,
      author='Mauricio Villegas',
      author_email='mauricio@omnius.com',
      url='https://github.com/omni-us/pagexml',
      license='MIT',
      cmdclass=CMDCLASS,
      packages=find_packages(),
      ext_modules=[textfeat_Extension()],
      command_options={
          'build_sphinx': {
              'project': ('setup.py', NAME),
              'version': ('setup.py', __version__),
              'release': ('setup.py', __version__),
              'build_dir': ('setup.py', 'docs/_build'),
              'source_dir': ('setup.py', 'docs')}})
