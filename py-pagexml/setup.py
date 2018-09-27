#!/usr/bin/env python

from setuptools import setup, find_packages, Extension, Command
import subprocess
import sysconfig
import sys
import os

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


def pagexml_Extension():
    import pkgconfig
    libs = ['opencv','libxml-2.0','libxslt','gdal']
    compile_args = ['-std=c++11']
    link_args = []
    for lib in libs:
        compile_args += pkgconfig.cflags(lib).split()
        link_args += pkgconfig.libs(lib).split()
    if not pkgconfig.cflags('opencv'):
        raise FileNotFoundError('pkgconfig did not find opencv development')
    cvinc = pkgconfig.cflags('opencv').split()[0].rsplit('/opencv',1)[0]
    return Extension('_pagexml',
                     define_macros = [('__PAGEXML_CVIMG__',''),('__PAGEXML_OGR__',''),('SWIG_PYTHON_SILENT_MEMLEAK','')],
                     extra_compile_args = compile_args,
                     extra_link_args = link_args,
                     swig_opts = [cvinc,'-I./opencv-swig/lib','-modern','-outdir','.','-c++'],
                     sources = ['swig/PageXML.i','swig/PageXML.cc'])


def distutils_dir_name(dname):
    """Returns the name of a distutils build directory"""
    f = "{dirname}.{platform}-{version[0]}.{version[1]}"
    return f.format(dirname=dname,
                    platform=sysconfig.get_platform(),
                    version=sys.version_info)

sys.path = [ os.path.join(os.path.dirname(os.path.realpath(__file__)), 'build', distutils_dir_name('lib'))] + sys.path


def pagexml_Version():
    import re
    with open("swig/PageXML.h") as f:
        for line in f:
            if 'Version:' in line:
                line = re.sub(r'.*Version: (\d\d\d\d\.\d\d\.\d\d)\$.*', r'\1', line.strip())
                return re.sub(r'\.0', '.', line)


NAME = 'pagexml'
DESCRIPTION = 'Wrapper for PageXML C++ library'
LONG_DESCRIPTION = 'Library for handling of Page XML files.'
__version__ = pagexml_Version()


class CoverageCommand(Command):
    """Custom command to print test coverage report."""
    description = 'print test coverage report'
    user_options = []

    def initialize_options(self):
        """init options"""
        pass

    def finalize_options(self):
        """finalize options"""
        pass

    def run(self):
        """run commands"""
        subprocess.check_call(['python', '-m', 'coverage', 'run', '--source', NAME, 'setup.py', 'test'])
        #subprocess.check_call(['python', '-m', 'coverage', 'report', '-m'])
        subprocess.check_call(['python', '-m', 'coverage', 'report'])


CMDCLASS = {'build': build, 'test_coverage': CoverageCommand}
if BuildDoc:
    class BuildDocPageXML(BuildDoc):
        def run(self):
            import pagexml
            super().run()

    CMDCLASS['build_sphinx'] = BuildDocPageXML

setup(name=NAME,
      version=__version__,
      description=DESCRIPTION,
      long_description=LONG_DESCRIPTION,
      author='Mauricio Villegas',
      author_email='mauricio@omnius.com',
      #setup_requires=['pkgconfig'], # does not install when missing?
      test_suite=NAME+'_tests',
      cmdclass=CMDCLASS,
      py_modules=[NAME],
      packages=find_packages(),
      ext_modules=[pagexml_Extension()],
      command_options={
          'build_sphinx': {
              'project': ('setup.py', NAME),
              'version': ('setup.py', __version__),
              'release': ('setup.py', __version__),
              'build_dir': ('setup.py', 'docs/_build'),
              'source_dir': ('setup.py', 'docs')}})
