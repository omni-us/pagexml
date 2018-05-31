#!/usr/bin/env python

import unittest
from pagexml import pagexml

class MainTest(unittest.TestCase):
    def test_page_size(self):
        pxml = pagexml.PageXML()
        pxml.newXml('test', 'test.jpg', 24, 32)
        self.assertEqual(pxml.getPageWidth(0), 24)
        self.assertEqual(pxml.getPageHeight(0), 32)

if __name__ == '__main__':
    unittest.main()
