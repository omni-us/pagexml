#!/usr/bin/env python3

import unittest
import os
import pagexml

TESTSDIR = os.path.dirname(os.path.realpath(__file__))


class TextEquivTests(unittest.TestCase):
    def test_groups(self):
        pxml = pagexml.PageXML(os.path.join(TESTSDIR, 'examples/lorem.xml'))
        elems1 = pxml.select('//*[@id="r2"]/_:TextLine')
        elems2 = pxml.select('//*[@id="r4"]/_:TextLine')
        group1 = pxml.addGroup(None, elems1)
        group2 = pxml.addGroup('grX')
        num_add2 = pxml.addToGroup(group2, elems2)
        self.assertEqual(num_add2, len(elems2))
        ids1 = [pxml.getAttr(x, 'id') for x in pxml.selectGroupElements(group1)]
        ids2 = [pxml.getAttr(x, 'id') for x in pxml.selectGroupElements(group2)]
        self.assertEqual(ids1, ['r2_l1', 'r2_l2'])
        self.assertEqual(ids2, ['r4_l1', 'r4_l2'])
        pxml.addToGroup(group1, (group2,))
        ids3 = [pxml.getAttr(x, 'id') for x in pxml.selectGroupElements(group1, False)]
        ids4 = [pxml.getAttr(x, 'id') for x in pxml.selectGroupElements(group1, True)]
        self.assertEqual(ids3, ['r2_l1', 'r2_l2', 'grX'])
        self.assertEqual(ids4, ['r2_l1', 'r2_l2', 'r4_l1', 'r4_l2'])


if __name__ == '__main__':
    unittest.main(verbosity=2)
