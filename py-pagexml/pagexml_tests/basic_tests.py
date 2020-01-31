#!/usr/bin/env python3

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

    def test_coords_resize(self):
        pxml = pagexml.PageXML()
        pxml.newXml('test', 'test1.jpg', 24, 32)
        sizes = pxml.getPagesSize()
        reg = pxml.addTextRegion(pxml.selectNth('//_:Page'))
        pxml.setCoordsBBox( reg, 2, 10, 5, 20, 0.8 )
        pxml.resize(2.0)
        self.assertEqual(pxml.getPageWidth(0), 48)
        self.assertEqual(pxml.getPageHeight(0), 64)
        pts = pxml.getPoints(reg)
        self.assertListEqual([p.x for p in pts], [4.0, 12.0, 12.0, 4.0])
        self.assertListEqual([p.y for p in pts], [20.0, 20.0, 58.0, 58.0])
        sizes[0].width = 12
        sizes[0].height = 16
        pxml.resize(sizes)
        self.assertEqual(pxml.getPageWidth(0), 12)
        self.assertEqual(pxml.getPageHeight(0), 16)


if __name__ == '__main__':
    unittest.main(verbosity=2)
