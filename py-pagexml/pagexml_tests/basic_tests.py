#!/usr/bin/env python

import unittest
import pagexml

class MainTest(unittest.TestCase):
    def test_pages_sizes(self):
        pxml = pagexml.PageXML()
        pxml.newXml('test', 'test1.jpg', 24, 32)
        pxml.addPage("test2.jpg", 48, 64)
        sizes = pxml.getPagesSize()
        self.assertEqual(pxml.getPageWidth(0), 24)
        self.assertEqual(pxml.getPageHeight(0), 32)
        self.assertEqual(pxml.getPageWidth(1), 48)
        self.assertEqual(pxml.getPageHeight(1), 64)
        self.assertEqual(sizes[0].width, 24)
        self.assertEqual(sizes[0].height, 32)
        self.assertEqual(sizes[1].width, 48)
        self.assertEqual(sizes[1].height, 64)
        self.assertEqual(len(sizes), 2)
        self.assertEqual(pxml.count('//_:Page'), 2)
        self.assertEqual(pxml.getPageImageFilename(0), 'test1.jpg')
        self.assertEqual(pxml.getPageImageFilename(1), 'test2.jpg')

if __name__ == '__main__':
    unittest.main()
