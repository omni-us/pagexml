import os
from .pagexml import *

_PageXML = PageXML

PAGEXMLDIR = os.path.dirname(os.path.realpath(__file__))

class PageXML(_PageXML):
    def __init__(self, schema_path = PAGEXMLDIR+'/xsd/pagecontent_searchink.xsd'):
        super(PageXML, self).__init__(schema_path)
