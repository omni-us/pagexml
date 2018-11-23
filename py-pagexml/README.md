# PageXML C++ library as a python module


## Dependencies

### Building

 - python3-setuptools
 - python3-pkgconfig
 - python3-wheel
 - python3-dev
 - swig
 - libxml2-dev
 - libxslt1-dev
 - opencv-dev
 - libgdal-dev
 - libboost-all-dev

### Runtime

 - python3
 - libxml2
 - libxslt1.1
 - libopencv-highgui
 - libopencv-imgproc
 - libopencv-core
 - libgdal


## Installation from wheel binary file

    pip3 install --user pagexml-2017.11.5-cp35-cp35m-linux_x86_64.whl

## Documentation

A doxygen+moxygen generated API documentation for the C++ PageXML library can be found at [../doc/PageXML-API.md](../doc/PageXML-API.md).


## Usage examples of the module in python

### Create a new Page XML adding regions, text and properties

    import pagexml
    pxml = pagexml.PageXML()

    # Create a new page xml
    file = "example_image.jpg"
    width = 400
    height = 200
    pxml.newXml("name-and-version-of-tool", file, width, height)

    # Add a text region to the Page
    page = pxml.selectNth("//_:Page",0)
    reg = pxml.addTextRegion(page)

    # Set text region bounding box with a confidence
    pxml.setCoordsBBox( reg, 10, 20, 80, 60, 0.8 )

    # Set the text for the text region with a confidence
    pxml.setTextEquiv( reg, "lorem ipsum", 0.9 )

    # Add property to text region
    pxml.setProperty( reg, "key", "value" )

    # Add a second page with a text region and specific id
    page = pxml.addPage("example_image_2.jpg", 300, 300)
    reg = pxml.addTextRegion( page, "regA" )
    pxml.setCoordsBBox( reg, 15, 12, 76, 128 )

    # Write XML to file
    pxml.write("example_image.xml")

### Modify an existing Page XML

    # Load an existing XML
    pxml.loadXml("example_image.xml")

    # Add content to loaded XML
    pxml.setProperty( pxml.selectNth("//_:Page",0), "key", "value" )

    # Write XML to file
    pxml.write("example_image_2.xml")


## Build wheel file from source

    python setup.py build
    python setup.py bdist_wheel
