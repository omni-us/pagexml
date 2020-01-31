#!/usr/bin/env python3
"""Command line tool for extracting text features."""

import os
import argparse
import json
import logging
from collections import namedtuple
import numpy as np
import pagexml
import textfeat
import cv2


NamedImage = namedtuple('NamedImage', 'id name image')


### Function for parsing command line arguments ###
def parse_args():
    """Command line argument parsing for textfeats.py."""

    def raise_(ex):
        """Raise that works within lambda functions."""
        raise ex

    ### Parse input arguments ###
    parser = argparse.ArgumentParser(
        description='Tool for extraction of textual features.',
        formatter_class=argparse.ArgumentDefaultsHelpFormatter)
    parser.add_argument('input', nargs='+',
                        help='Path(s) to input page xml(s).')
    parser.add_argument('--verbose', default=False, action='store_true',
                        help='Whether to be verbose.')
    parser.add_argument('--threads', default=1, type=lambda x: int(x) if int(x) > 0 else raise_(ValueError),
                        help='Number of parallel threads.')
    parser.add_argument('--cfg', default=None,
                        help='Path to the feature extraction configuration file in json format.')
    parser.add_argument('--outdir', default='.',
                        help='Output directory.')
    parser.add_argument('--featlist', default=False, action='store_true',
                        help='Print list of extracted feature files to stdout.')
    parser.add_argument('--xpath', default='//_:TextLine/_:Coords[@points and @points!="0,0 0,0"]',
                        help='Selector for elements to extract.')
    parser.add_argument('--savexml', default=False, action='store_true',
                        help='Save XML with extraction information.')
    parser.add_argument('--regproc', default=True, type=bool,
                        help='Register process in extraction XML.')
    parser.add_argument('--fpoints', default=True, type=bool,
                        help='Store feature contours in points attribute.')
    parser.add_argument('--legacy-feats', default=False, action='store_true',
                        help='Whether to use the textFeats tool to extract the features.')

    return parser.parse_args()


### Main block called only when run from command line ###
if __name__ == '__main__':
    opts = parse_args()

    ### Setup logger ###
    logger = logging.getLogger('textfeats')
    handler = logging.StreamHandler()
    handler.setFormatter(logging.Formatter('%(asctime)s - %(name)s - %(levelname)s - %(message)s'))
    logger.addHandler(handler)
    logger.setLevel(logging.INFO)

    ### Load configuration ###
    cfg = {}
    if opts.cfg is not None:
        with open(opts.cfg) as json_config:
            cfg = json.load(json_config)['feats']
        logger.info('Loaded configuration.')
    if opts.legacy_feats:
        if opts.savexml:
            cfg['savexml'] = opts.outdir
        extractor = textfeat.LegacyTextFeatExtractor(**cfg)
    else:
        extractor = textfeat.TextFeatExtractor(**cfg)

    ### Loop through input page xmls ###
    for fpxml in opts.input:
        logger.info('Processing page xml: '+fpxml)
        pxml = pagexml.PageXML(fpxml)

        if opts.legacy_feats:
            feats = extractor.extractFeats(fpxml, xpath=opts.xpath)
        else:
            cropped = pxml.crop(opts.xpath)
            feats = []
            for crop in cropped:
                image = crop.image
                extractor.preprocess(image)
                slope = textfeat.ptr_float()
                slant = textfeat.ptr_float()
                extractor.estimateAngles(image, slope, slant, crop.rotation)
                image = extractor.extractFeats(image, slope.value(), slant.value(), rotate=crop.rotation)
                feat = NamedImage(id=crop.id, name=crop.name, image=np.asarray(image))
                feats.append(feat)
                if opts.savexml:
                    elem = pxml.selectByID(crop.id)
                    pxml.setProperty(elem, 'rotation', crop.rotation)
                    pxml.setProperty(elem, 'slope', slope.value())
                    pxml.setProperty(elem, 'slant', slant.value())

        if not opts.legacy_feats and opts.savexml:
            pxml.write(os.path.join(opts.outdir, os.path.basename(fpxml)))

        for feat in feats:
            cv2.imwrite(os.path.join(opts.outdir, feat.name+'.png'), feat.image)
            if opts.featlist:
                print(os.path.join(opts.outdir, feat.name+'.png'))

        logger.info('Extracted '+str(len(feats))+' feature images out of '+str(pxml.count(opts.xpath))+' requested')
