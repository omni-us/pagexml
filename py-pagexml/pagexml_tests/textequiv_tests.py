#!/usr/bin/env python3

import unittest
import os
import pagexml

TESTSDIR = os.path.dirname(os.path.realpath(__file__))


class TextEquivTests(unittest.TestCase):
    def test_get_textequiv(self):
        pxml = pagexml.PageXML(os.path.join(TESTSDIR, 'examples/lorem.xml'))
        text = pxml.getTextEquiv(pxml.selectByID('r1_l1'))
        self.assertEqual(text, 'Lorem ipsum')

    def test_get_textequiv_grandchildren(self):
        pxml = pagexml.PageXML(os.path.join(TESTSDIR, 'examples/lorem.xml'))
        text = pxml.getTextEquiv(pxml.selectByID('r2'), xpath='_:TextLine/_:TextEquiv', separator='\n')
        self.assertEqual(text, 'dolor sit amet, in per iusto\nnostrud,')

    def test_set_textequiv(self):
        pxml = pagexml.PageXML(os.path.join(TESTSDIR, 'examples/lorem.xml'))
        elem = pxml.selectByID('r1_l1')
        text = 'new text'
        pxml.setTextEquiv(elem, text)
        self.assertEqual(text, pxml.getTextEquiv(elem))

    def test_multiple_typed_textequivs(self):
        pxml = pagexml.PageXML(os.path.join(TESTSDIR, 'examples/lorem.xml'))
        elem = pxml.selectByID('r1_l1')
        text1 = 'first typed text'
        text2 = 'second typed text'
        text3 = 'new type1 text'
        conf1 = 0.9
        conf2 = 0.4
        pxml.setTextEquiv(elem, text1, conf1, 'type1')
        pxml.setTextEquiv(elem, text2, conf2, 'type2')
        self.assertEqual('Lorem ipsum', pxml.getTextEquiv(elem, type=''))
        self.assertEqual(text1, pxml.getTextEquiv(elem, type='type1'))
        self.assertEqual(text2, pxml.getTextEquiv(elem, type='type2'))
        self.assertEqual(conf1, float(pxml.getValue('_:TextEquiv[@type="type1"]/@conf', elem)))
        self.assertEqual(conf2, float(pxml.getValue('_:TextEquiv[@type="type2"]/@conf', elem)))
        pxml.setTextEquiv(elem, text3, None, 'type1')
        self.assertEqual(text3, pxml.getTextEquiv(elem, type='type1'))
        self.assertEqual('', pxml.getValue('_:TextEquiv[@type="type1"]/@conf', elem))


if __name__ == '__main__':
    unittest.main(verbosity=2)
