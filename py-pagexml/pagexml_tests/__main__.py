"""Run all unit tests in package."""

import os
import sys
import unittest


def run_tests():
    package = os.path.basename(os.path.dirname(os.path.realpath(__file__)))
    tests = unittest.defaultTestLoader.discover(package, pattern='*_tests.py')
    return unittest.TextTestRunner(verbosity=2).run(tests)


if __name__ == '__main__':
    sys.exit(not run_tests().wasSuccessful())
