#!/usr/bin/env python3

import unittest
import os
import pagexml

TESTSDIR = os.path.dirname(os.path.realpath(__file__))


@unittest.skipIf(pagexml.is_slim(), 'not available in pagexml_slim')
class OrderingTests(unittest.TestCase):
    def test_getLeftRightTopBottomReadingOrder(self):
        pxml = pagexml.PageXML(os.path.join(TESTSDIR, 'examples/lorem_tess.xml'))
        xlines = pxml.select('//_:TextLine')
        order, groups = pxml.getLeftRightTopBottomReadingOrder(xlines)
        self.assertEqual(order, (4, 2, 3, 5, 6, 7, 8, 0, 1))
        self.assertEqual(groups, (1, 1, 1, 1, 1, 1, 1, 1, 1))

        xpage = pxml.selectNth('//_:Page')
        xlines = list(xlines)
        xlines = [xlines[n] for n in order]
        for xline in xlines:
            pxml.moveElem(xline, xpage)
        line_ids = [pxml.getAttr(x, 'id') for x in pxml.select('//_:TextLine')]
        self.assertEqual(line_ids, ['b1_p1_l1', 'b2_p1_l1', 'b2_p1_l2', 'b3_p1_l1', 'b3_p1_l2', 'b3_p1_l3', 'b3_p1_l4', 'b4_p1_l1', 'b4_p1_l2'])


if __name__ == '__main__':
    unittest.main(verbosity=2)
