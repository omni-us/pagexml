#!/usr/bin/env python3

import glob
import importlib
import os
import subprocess
import sys
import sysconfig
from setuptools import setup, Extension, Command


NAME = next(filter(lambda x: x.startswith('name = '), open('setup.cfg').readlines())).strip().split()[-1]
NAME_TESTS = next(filter(lambda x: x.startswith('test_suite = '), open('setup.cfg').readlines())).strip().split()[-1]
CMDCLASS = {}


## test_coverage target ##
try:
    import coverage

    class CoverageCommand(Command):
        description = 'print test coverage report'
        user_options = []  # type: ignore
        def initialize_options(self): pass
        def finalize_options(self): pass
        def run(self):
            cov = coverage.Coverage()
            cov.start()
            importlib.reload(__import__(NAME))
            __import__(NAME_TESTS+'.__main__').__main__.run_tests()
            cov.stop()
            cov.save()
            cov.report()
            cov.html_report(directory='htmlcov')
            print('\nSaved html report to htmlcov directory.')

    CMDCLASS['test_coverage'] = CoverageCommand

except Exception:
    print('warning: coverage package not found, test_coverage target will not be available.')


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


from setuptools.command.build_ext import build_ext as build_ext_orig
class build_ext(build_ext_orig):
    def run(self):
        super().run()
        subprocess.check_call(['sed', '-i', '/^# Import the low-level C.C++ module/{ N;N;N;N; s|.*\\n *import |import |; }', 'pagexml/swigPageXML.py'])
        print('info: applied circular import patch to pagexml/swigPageXML.py')
        if sys.platform == 'linux':
            so_file = glob.glob(self.build_lib + '/_swigPageXML*.so')
            subprocess.check_call(['strip', '--strip-debug'] + so_file)
            print(f'info: stripped debug symbols from extension file {so_file}')

CMDCLASS['build_ext'] = build_ext


from setuptools import Distribution as _Distribution
class Distribution(_Distribution):
    global_options = _Distribution.global_options + [('magick', None, 'Compile pagexml extension with __PAGEXML_IMG_MAGICK__')]


def build_xml_deps():
    sys.path.append(os.path.join(os.getcwd(), 'lxml'))
    os.environ['CFLAGS'] = '-O3 -fPIC'

    from buildlibxml import build_libxml2xslt  # pylint: disable=import-error

    XML2_CONFIG, XSLT_CONFIG = build_libxml2xslt(
        download_dir='download',
        build_dir='build/lxml',
        static_include_dirs=[],
        static_library_dirs=[],
        static_cflags=[],
        static_binaries=[],
    )

    compile_args = subprocess.check_output([XSLT_CONFIG, '--cflags']).decode('utf-8').split()
    link_args = subprocess.check_output([XSLT_CONFIG, '--libs']).decode('utf-8').split()

    lib_dir = 'build/lxml/libxml2/lib/'
    libs = [x.replace(lib_dir+'lib', '').replace('.a', '') for x in glob.glob(lib_dir+'*.a')]
    for lib in libs:
        if '-l'+lib in link_args:
            link_args[link_args.index('-l'+lib)] = lib_dir+'lib'+lib+'.a'

    return compile_args, link_args


def pagexml_Extension(slim, magick):
    import pkgconfig
    libs = []
    opencv = 'opencv' if sys.version_info[:2] == (3, 6) else 'opencv4'
    if not slim:
        libs = [opencv, 'gdal'] + libs
        if magick:
            libs += ['Magick++']
    compile_args = ['-std=c++11']
    link_args = []

    for lib in libs:
        if not pkgconfig.exists(lib):
            raise FileNotFoundError('pkgconfig did not find '+lib)
        compile_args += pkgconfig.cflags(lib).split()
        link_args += pkgconfig.libs(lib).split()

    xml_compile_args, xml_link_args = build_xml_deps()
    compile_args += xml_compile_args
    link_args += xml_link_args

    if slim:
        define_macros = [('__PAGEXML_SLIM__','')]
        swig_opts = ['-D__PAGEXML_SLIM__']
    else:
        defimage = '__PAGEXML_IMG_MAGICK__' if magick else '__PAGEXML_IMG_CV__'
        pageimage = 'Magick::Image' if magick else 'cv::Mat'
        define_macros = [('__PAGEXML_OGR__',''),(defimage,'')] + ( [('__PAGEXML_MAGICK__','')] if magick else [] )
        swig_opts = ['-D__PAGEXML_OGR__','-D'+defimage,'-DPageImage='+pageimage] + ( ['-D__PAGEXML_MAGICK__'] if magick else [] )
        cvinc = pkgconfig.cflags(opencv).split()[0]
        if sys.version_info[:2] == (3, 6):
            cvinc = cvinc.rsplit('/opencv',1)[0]
        swig_opts += [cvinc]

    print(f'pagexml_Extension configured with swig_opts={swig_opts}')
    return Extension('_swigPageXML',
                     define_macros = define_macros + [('SWIG_PYTHON_SILENT_MEMLEAK','')],
                     extra_compile_args = compile_args,
                     extra_link_args = link_args,
                     swig_opts = swig_opts + ['-I./opencv-swig/lib', '-keyword', '-w511', '-c++'],
                     sources = ['pagexml/PageXML.i', 'pagexml/PageXML.cc'])


def distutils_dir_name(dname):
    """Returns the name of a distutils build directory"""
    f = "{dirname}.{platform}-{version[0]}.{version[1]}"
    return f.format(dirname=dname,
                    platform=sysconfig.get_platform(),
                    version=sys.version_info)

sys.path = [ os.path.join(os.path.dirname(os.path.realpath(__file__)), 'build', distutils_dir_name('lib'))] + sys.path


name = NAME
slim = False
magick = False
if '--slim' in sys.argv:
    sys.argv = [x for x in sys.argv if x != '--slim']
    name += '_slim'
    slim = True
if '--magick' in sys.argv:
    sys.argv = [x for x in sys.argv if x != '--magick']
    name += '_magick'
    magick = True


## Run setuptools setup ##
setup(name=name,
      ext_modules=[pagexml_Extension(slim=slim, magick=magick)],
      distclass=Distribution,
      cmdclass=CMDCLASS)
