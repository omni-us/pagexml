py-pagexml: Python wrapper for the PageXML C++ library
======================================================

The py-pagexml python package is a library of functions that eases working with
omni:us Pages Format XML files (referred to as OPF XML files). It allows you
from python to read an OPF file, extract information contained within, modify or
add content, create an OPF from scratch, crop parts for page images, etc.

By default OPF XML files are validated against the XSD schema when reading,
saving, or on request by calling a function. The documentation the XSD schema
and the schema itself included in py-pagexml can be found at:

- `XSD schema documentation <https://omni-us.github.io/pageformat/pagecontent_omnius.html>`_.
- `pagecontent_omnius.xsd <https://omni-us.github.io/pageformat/pagecontent_omnius.xsd>`_.

The official online documentation of py-pagexml is available at `<https://omni-us.github.io/pagexml/py-pagexml>`_.

The py-pagexml package can be built with two modes: normal and slim. As the name
implies, the slim build is smaller but more importantly it has less library
dependencies. This also means that there are some features which are not
available, namely: functions related to images, e.g.
``PageXML.crop``; and functions that perform intersections of polygons, e.g.
``PageXML.selectByOverlap``.


Software dependencies
---------------------

The core of py-pagexml is a compiled C++ library that links with a few
libraries, so it requires installation of dependencies that cannot be
automatically obtained from pypi servers.

There are `docker images available at docker hub
<https://hub.docker.com/r/mauvilsa/pagexml/tags>`_ which include both the
runtime and the build dependencies already installed. In particular the runtime
docker images are intended to be used as base images for applications that use
pagexml. The specific list of dependencies both for runtime and building are
listed below.

Runtime dependencies
~~~~~~~~~~~~~~~~~~~~

Slim:
 - python3

Normal (in addition to the previous):
 - libopencv-imgcodecs (Ubuntu 18.04/20.04) | libopencv-highgui (Ubuntu 16.04)
 - libopencv-imgproc
 - libopencv-core
 - libgdal

Building dependencies
~~~~~~~~~~~~~~~~~~~~~

Slim:
 - python3-setuptools
 - python3-pkgconfig
 - python3-wheel
 - python3-dev
 - swig

Normal (in addition to the previous):
 - libopencv-dev
 - libgdal-dev
 - libboost-all-dev


Installation from wheel binary file
-----------------------------------

If you have configured a pypi server that includes pagexml, installation is as
simple as:

.. code-block:: bash

    pip3 install pagexml

The slim build has a different name, thus the install comand would be:

.. code-block:: bash

    pip3 install pagexml_slim

Otherwise you can install it from a github `release
<https://github.com/omni-us/pagexml/releases>`_. Each release includes multiple
wheel files. One for python 3.5 which is built for Ubuntu 16.04, another for
python 3.6 built for Ubuntu 18.04 and another for python 3.8 built for Ubuntu
20.04. Once you have located the appropriate wheel file, copy the link and run
as follows replacing the URL with the one you copied:

.. code-block:: bash

    pip3 install https://github.com/omni-us/pagexml/releases/download/20*/pagexml-20*-linux_x86_64.whl


Building the wheel file from source
-----------------------------------

Clone the github repository `<https://github.com/omni-us/pagexml.git>`_, go to
the py-pagexml directory and then run:

.. code-block:: bash

    pip3 install --editable .[dev]
    ./setup.py bdist_wheel

To build the slim package, give the ``--slim`` command line option, e.g.:

.. code-block:: bash

    ./setup.py bdist_wheel --slim


Simple usage examples
---------------------

Create a new Page XML adding regions, text and properties
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: python

    import pagexml
    pxml = pagexml.PageXML()

    # Create a new page xml
    file = 'example_image.jpg'
    width = 400
    height = 200
    pxml.newXml('name-and-version-of-tool', file, width, height)

    # Add a text region to the Page
    page = pxml.selectNth('//_:Page', 0)
    reg = pxml.addTextRegion(page)

    # Set text region bounding box with a confidence
    pxml.setCoordsBBox(reg, 10, 20, 80, 60, 0.8)

    # Set the text for the text region with a confidence
    pxml.setTextEquiv(reg, 'lorem ipsum', 0.9)

    # Add property to text region
    pxml.setProperty(reg, 'key', 'value')

    # Add a second page with a text region and specific id
    page = pxml.addPage('example_image_2.jpg', 300, 300)
    reg = pxml.addTextRegion(page, 'regA')
    pxml.setCoordsBBox(reg, 15, 12, 76, 128)

    # Write XML to file
    pxml.write('example_image.xml')


Modify an existing Page XML
~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: python

    # Load an existing XML
    import pagexml
    pxml = pagexml.PageXML('example_image.xml')

    # Add content to loaded XML
    pxml.setProperty(pxml.selectNth('//_:Page', 0), 'key', 'value')

    # Write XML to file
    pxml.write('example_image_2.xml')


Crop an element and save image to disk
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: python

    # Load an existing XML
    import pagexml
    pxml = pagexml.PageXML('examples/lorem.xml')

    # Crop element with specific ID
    cropped = pxml.crop('//*[@id="r1_l1"]/_:Coords')[0]

    # Save image to disk
    pagexml.imwrite(cropped.name+'.png', cropped.image)
