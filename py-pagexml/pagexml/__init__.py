import os
from .pagexml import *
try:
    import cv2
    import numpy as np
except ImportError:
    cv2 = False

_PageXML = PageXML

PAGE_XSD = os.path.dirname(os.path.realpath(__file__))+'/xsd/pagecontent_searchink.xsd'

class PageXML(_PageXML): #pylint: disable=function-redefined
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
        raise Exception('cv2 and numpy required but not available.')
    return cv2.imwrite(filename, np.asarray(img), params)
