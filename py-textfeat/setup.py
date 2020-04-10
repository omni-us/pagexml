#!/usr/bin/env python3

from setuptools import setup, Extension, Command
from glob import glob
import sysconfig
import sys
import os
import re


NAME = next(filter(lambda x: x.startswith('name = '), open('setup.cfg').readlines())).strip().split()[-1]
CMDCLASS = {}


## build_sphinx target ##
try:
    from sphinx.setup_command import BuildDoc as _BuildDoc

    class BuildDoc(_BuildDoc):
        def run(self):
            __import__(NAME)
            super().run()

    CMDCLASS['build_sphinx'] = BuildDoc

except Exception:
    print('warning: sphinx package not found, build_sphinx target will not be available.')


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

CMDCLASS['build'] = build


from setuptools import Distribution as _Distribution
class Distribution(_Distribution):
    global_options = _Distribution.global_options + [('magick', None, 'Compile textfeat extension with __PAGEXML_IMG_MAGICK__')]


def textfeat_Version():
    with open("textfeat/TextFeatExtractor.h") as f:
        for line in f:
            if 'Version:' in line:
                line = re.sub(r'.*Version: (\d\d\d\d\.\d\d\.\d\d)\$.*', r'\1', line.strip())
                return re.sub(r'\.0', '.', line)


def textfeat_Extension(magick=False):
    import pkgconfig
    libs = ['opencv','libxml-2.0','Magick++']
    compile_args = ['-std=c++11']
    link_args = []
    for lib in libs:
        if not pkgconfig.exists(lib):
            raise FileNotFoundError('pkgconfig did not find '+lib)
        compile_args += pkgconfig.cflags(lib).split()
        link_args += pkgconfig.libs(lib).split()
    #compile_args += pkgconfig.cflags('opencv').split()
    #cvre = re.compile('^-L|^-lopencv_core|^-lopencv_imgproc|^-lopencv_imgcodecs|^-lopencv_flann')
    #link_args += [x for x in pkgconfig.libs('opencv').split() if cvre.match(x)]
    cvinc = pkgconfig.cflags('opencv').split()[0].rsplit('/opencv',1)[0]
    defimage = '__PAGEXML_IMG_MAGICK__' if magick else '__PAGEXML_IMG_CV__'
    pageimage = 'Magick::Image' if magick else 'cv::Mat'
    define_macros = [(defimage,''),('__PAGEXML_MAGICK__','')]
    swig_opts = ['-D'+defimage,'-DPageImage='+pageimage,'-D__PAGEXML_MAGICK__']
    print('textfeat_Extension configured with '+defimage)
    return Extension('_swigTextFeatExtractor',
                     define_macros = define_macros + [('SWIG_PYTHON_SILENT_MEMLEAK','')],
                     extra_compile_args = compile_args,
                     extra_link_args = link_args,
                     swig_opts = swig_opts + [cvinc,'-modern','-keyword','-c++'],
                     sources = ['textfeat/TextFeatExtractor.i','textfeat/TextFeatExtractor.cc','textfeat/intimg.cc','textfeat/mem.cc'])


def distutils_dir_name(dname):
    """Returns the name of a distutils build directory"""
    f = "{dirname}.{platform}-{version[0]}.{version[1]}"
    return f.format(dirname=dname,
                    platform=sysconfig.get_platform(),
                    version=sys.version_info)

sys.path = [ os.path.join(os.path.dirname(os.path.realpath(__file__)), 'build', distutils_dir_name('lib'))] + sys.path


## Run setuptools setup ##
setup(version=textfeat_Version(),
      name=NAME+('_magick' if '--magick' in sys.argv else ''),
      ext_modules=[textfeat_Extension(True if '--magick' in sys.argv else False)],
      scripts=[x for x in glob(NAME+'/bin/*.py') if not x.endswith('__.py')],
      distclass=Distribution,
      cmdclass=CMDCLASS)
