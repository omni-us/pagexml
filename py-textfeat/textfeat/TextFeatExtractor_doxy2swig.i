// File: xml/class_text_feat_extractor.xml

%feature("docstring") TextFeatExtractor::TextFeatExtractor "
Arguments:
    featype (int): 
    format (int): 
    verbose (bool): 
    procimgs (bool): 
    stretch (bool): 
    enh (bool): 
    enh_type (int): 
    enh_win (int): 
    enh_slp (float): 
    enh_prm (float): 
    enh_prm_randmin (float): 
    enh_prm_randmax (float): 
    enh3_prm0 (float): 
    enh3_prm2 (float): 
    deslope (bool): 
    deslant (bool): 
    deslant_min (float): 
    deslant_max (float): 
    deslant_step (float): 
    deslant_hsteps (int): 
    slant_rand (float): 
    scale_rand (float): 
    normxheight (int): 
    normheight (int): 
    momentnorm (bool): 
    compute_fpgram (bool): 
    compute_fcontour (bool): 
    fcontour_dilate (float): 
    padding (int): 

";

%feature("docstring") TextFeatExtractor::estimateAngles "
Estimates slope and slant angles for an image.

Arguments:
    cvimg (PageImage &): 
    _slope (float *): Estimated slope angle in degrees.
    _slant (float *): Estimated slant angle in degrees.
    rotate (float): 

";

%feature("docstring") TextFeatExtractor::extract "
Arguments:
    image (PageImage &): 
    rotate (float): 
    _slope (float *): 
    _slant (float *): 
    _fpgram (std::vector< cv::Point2f > *): 
    _fcontour (std::vector< cv::Point > *): 

Returns:
    cv::Mat: 

";

%feature("docstring") TextFeatExtractor::extractFeats "
Extracts features for the given image already preprocessed image.

Arguments:
    feaimg (PageImage &): Image to process.
    slope (float): Slope angle in degrees.
    slant (float): Slant angle in degrees.
    xheight (int): 
    _fpgram (std::vector< cv::Point2f > *): Output features parallelogram coordinates.
    randomize (bool): Whether to do a random perturbation of extraction parameters.
    rotate (float): 
    direction (int): 

Returns:
    cv::Mat: Features matrix.

";

%feature("docstring") TextFeatExtractor::featTypes "

Returns:
    const char *: 

";

%feature("docstring") TextFeatExtractor::formatNames "

Returns:
    const char *: 

";

%feature("docstring") TextFeatExtractor::isImageFormat "
Whether the configured output format is image.


Returns:
    bool: 

";

%feature("docstring") TextFeatExtractor::preprocess "
Pre-processes a text image, optionally computing the connected components contour.

Arguments:
    cvimg (PageImage &): 
    _fcontour (std::vector< cv::Point > *): Output contour points, set to NULL to skip computation.
    randomize (bool): Whether to do a random perturbation of preprocessing parameters.

";

%feature("docstring") TextFeatExtractor::printConf "
Prints the current configuration.

Arguments:
    file (FILE *): File to print to.

";

%feature("docstring") TextFeatExtractor::version "
Returns the class version.


Returns:
    char *: 

";

%feature("docstring") TextFeatExtractor::write "
Overloaded function with 2 signatures.

**Signature 1**

``void TextFeatExtractor::write(const cv::Mat &feats, FILE *file=stdout)``

Prints features to a file stream using the configured output format.

Arguments:
    feats (const cv::Mat &): OpenCV matrix containing the features.
    file (FILE *): File stream to write the features.

**Signature 2**

``void TextFeatExtractor::write(const cv::Mat &feats, const char *fname)``

Writes features to a file using the configured output format.

Arguments:
    feats (const cv::Mat &): OpenCV matrix containing the features.
    fname (const char *): File name of where to write the features.

";

