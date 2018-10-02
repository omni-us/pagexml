import os
from .pagexml import *

_PageXML = PageXML

PAGE_XSD = os.path.dirname(os.path.realpath(__file__))+'/xsd/pagecontent_searchink.xsd'

class PageXML(_PageXML):
    def __init__(self, *args, **kwargs):
        if 'schema_path' not in kwargs:
            kwargs['schema_path'] = PAGE_XSD
        super(PageXML, self).__init__(*args, **kwargs)
