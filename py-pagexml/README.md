# PageXML C++ library as a python module


## Dependencies

### Building

 - python-pkgconfig
 - python-setuptools
 - libxml2-dev
 - opencv-dev
 - libgdal-dev

### Runtime

 - libxml2
 - libxslt
 - libopencv-highgui2.4
 - libopencv-imgproc2.4
 - libopencv-core2.4
 - libgdal1i


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

    # Initialize object for setting confidence values
    conf = pagexml.ptr_double()

    # Add a text region to the Page
    page = pxml.selectNth("//_:Page",0)
    reg = pxml.addTextRegion(page)

    # Set text region bounding box with a confidence
    conf.assign(0.8)
    pxml.setCoordsBBox( reg, 10, 20, 80, 60, conf )

    # Set the text for the text region
    conf.assign(0.9)
    pxml.setTextEquiv( reg, "lorem ipsum", conf )

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
