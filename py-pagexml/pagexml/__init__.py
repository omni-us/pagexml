import os
from .swigPageXML import *  # pylint: disable=import-error
try:
    import cv2
    import numpy as np
except ImportError:
    cv2 = False


__version__ = '2022.04.12'

PAGE_XSD_SEARCHINK = os.path.dirname(os.path.realpath(__file__))+'/xsd/pagecontent_searchink.xsd'
PAGE_XSD_OMNIUS = os.path.dirname(os.path.realpath(__file__))+'/xsd/pagecontent_omnius.xsd'
PAGE_XSD = PAGE_XSD_OMNIUS

def set_searchink_schema():
    """Sets the schema for validation to be pagecontent_searchink.xsd."""
    global PAGE_XSD
    PAGE_XSD = PAGE_XSD_SEARCHINK

def set_omnius_schema():
    """Sets the schema for validation to be pagecontent_omnius.xsd."""
    global PAGE_XSD
    PAGE_XSD = PAGE_XSD_OMNIUS


_PageXML = PageXML  # pylint: disable=used-before-assignment

class PageXML(_PageXML):  # pylint: disable=function-redefined
    """Python only additions to the PageXML class."""

    def __init__(self, *args, **kwargs):
        if 'schema_path' not in kwargs:
            kwargs['schema_path'] = PAGE_XSD
        super(PageXML, self).__init__(*args, **kwargs)

    def clone(self):
        # The c++ clone gives error, so reimplemented it in python
        pxml = PageXML()
        pxml.loadXmlString( self.toString(), False )
        pxml.setImagesBaseDir( self.getImagesBaseDir() )
        pxml.setXmlFilePath( self.getXmlFilePath() )
        return pxml


def imwrite(filename, img, params=[]):
    """Saves an image to a specified file.

    Args:
        filename (str): Path of file to write.
        img (pagexml.Mat): Image to write.
        params (list): Format-specific write parameters (see OpenCV imwrite documentation).

    Returns:
        Boolean indicating whether write was successful.
    """
    if not cv2:
        raise Exception('cv2 and numpy required but not available. To have optional dependencies install with `pip3 install pagexml[all]`')
    return cv2.imwrite(filename, np.asarray(img), params)


def is_slim():
    return not hasattr(_PageXML, 'selectByOverlap')
