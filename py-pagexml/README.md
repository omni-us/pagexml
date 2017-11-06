# PageXML library as a python module


## Dependencies

### Building

 - python-pkgconfig
 - python-setuptools
 - libxml2-dev
 - opencv-dev

### Runtime

 - libxml2
 - libxslt
 - libopencv-highgui2.4
 - libopencv-imgproc2.4
 - libopencv-core2.4


## Installation from wheel binary file

    pip3 install --user pagexml-2017.11.5-cp35-cp35m-linux_x86_64.whl


## Usage of the module in python

    import pagexml
    page = pagexml.PageXML()

    # Create a new page xml
    file = "example_image.jpg"
    width = 400
    height = 200
    page.newXml("name-and-version-of-tool", file, width, height)

    # Initialize object for setting confidence values
    conf = pagexml.ptr_double()

    # Add a text region to the Page
    reg = page.addTextRegion("//_:Page")

    # Set text region bounding box with a confidence
    conf.assign(0.8)
    page.setCoordsBBox( reg, 10, 20, 80, 60, conf )

    # Set the text for the text region
    conf.assign(0.9)
    page.setTextEquiv( reg, "lorem ipsum", conf )

    # Add property to text region
    page.setProperty( reg, "key", "value" )

    # Write XML to file
    page.write("example_image.xml")
