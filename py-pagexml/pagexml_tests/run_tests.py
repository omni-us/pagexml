#!/usr/bin/env python3
"""Run all unit tests in package."""

import sys
import unittest

tests = unittest.defaultTestLoader.discover('pagexml_tests', pattern='*_tests.py')

def run_tests():
    return unittest.TextTestRunner(verbosity=2).run(tests)

if __name__ == '__main__':
    sys.exit(not run_tests().wasSuccessful())
