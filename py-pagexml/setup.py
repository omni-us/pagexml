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


from setuptools import Distribution as _Distribution
class Distribution(_Distribution):
    global_options = _Distribution.global_options + [('magick', None, 'Compile textfeat extension with __PAGEXML_IMG_MAGICK__')]


def pagexml_Extension(magick):
    import pkgconfig
    libs = ['opencv','libxml-2.0','libxslt','gdal']
    if magick:
        libs += ['Magick++']
    compile_args = ['-std=c++11']
    link_args = []
    for lib in libs:
        if not pkgconfig.exists(lib):
            raise FileNotFoundError('pkgconfig did not find '+lib)
        compile_args += pkgconfig.cflags(lib).split()
        link_args += pkgconfig.libs(lib).split()
    #compile_args += pkgconfig.cflags('opencv').split()
    #cvre = re.compile('^-L|^-lopencv_core|^-lopencv_imgproc|^-lopencv_imgcodecs|^-lopencv_highgui')
    #link_args += [x for x in pkgconfig.libs('opencv').split() if cvre.match(x)]
    cvinc = pkgconfig.cflags('opencv').split()[0].rsplit('/opencv',1)[0]
    defimage = '__PAGEXML_IMG_MAGICK__' if magick else '__PAGEXML_IMG_CV__'
    pageimage = 'Magick::Image' if magick else 'cv::Mat'
    define_macros = [('__PAGEXML_OGR__',''),(defimage,'')] + ( [('__PAGEXML_MAGICK__','')] if magick else [] )
    swig_opts = ['-D__PAGEXML_OGR__','-D'+defimage,'-DPageImage='+pageimage] + ( ['-D__PAGEXML_MAGICK__'] if magick else [] )
    print('pagexml_Extension configured with '+defimage)
    return Extension('_pagexml',
                     define_macros = define_macros + [('SWIG_PYTHON_SILENT_MEMLEAK','')],
                     extra_compile_args = compile_args,
                     extra_link_args = link_args,
                     swig_opts = swig_opts + [cvinc,'-I./opencv-swig/lib','-modern','-keyword','-w511','-c++'],
                     sources = ['pagexml/PageXML.i','pagexml/PageXML.cc'])


def distutils_dir_name(dname):
    """Returns the name of a distutils build directory"""
    f = "{dirname}.{platform}-{version[0]}.{version[1]}"
    return f.format(dirname=dname,
                    platform=sysconfig.get_platform(),
                    version=sys.version_info)

sys.path = [ os.path.join(os.path.dirname(os.path.realpath(__file__)), 'build', distutils_dir_name('lib'))] + sys.path


def pagexml_Version():
    with open("pagexml/PageXML.h") as f:
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

setup(name=NAME+('_magick' if '--magick' in sys.argv else ''),
      version=__version__,
      description=DESCRIPTION,
      long_description=LONG_DESCRIPTION,
      author='Mauricio Villegas',
      author_email='mauricio@omnius.com',
      url='https://github.com/omni-us/pagexml',
      license='MIT',
      #setup_requires=['pkgconfig'], # does not install when missing?
      test_suite=NAME+'_tests',
      cmdclass=CMDCLASS,
      packages=find_packages(),
      distclass=Distribution,
      ext_modules=[pagexml_Extension(True if '--magick' in sys.argv else False)],
      package_data={NAME: ['xsd/*.xsd'], NAME+'_tests': ['examples/*.xml', 'examples/*.png']},
      command_options={
          'build_sphinx': {
              'project': ('setup.py', NAME),
              'version': ('setup.py', __version__),
              'release': ('setup.py', __version__),
              'build_dir': ('setup.py', 'docs/_build'),
              'source_dir': ('setup.py', 'docs')}})
