"""A class for feature extraction using the textFeats command line tool."""

import os
import tempfile
from subprocess import Popen, PIPE, STDOUT
from distutils.version import StrictVersion
import cv2

def keep_temp_dir(tempdir):
    """Renames a temporal directory adding a '_kept' suffix to prevent its automatic deletion."""
    os.rename(tempdir.name, tempdir.name+'_kept')
    try:
        tempdir.cleanup()
    except:
        pass

class LegacyTextFeatExtractor:
    """TextFeatExtractor that internally uses the textFeats command line tool."""

    def __init__(self,
                 keeptmp = False,
                 verbose = False,
                 procimgs = False,
                 stretch = True,
                 enh = True,
                 enh_win = 20,
                 enh_slp = 0.5,
                 enh_prm = 0.2,
                 enh3_prm0 = 0.0,
                 enh3_prm2 = 0.0,
                 deslope = True,
                 deslant = True,
                 normxheight = 0,
                 normheight = 64,
                 momentnorm = True,
                 compute_fpgram = True,
                 compute_fcontour = True,
                 fcontour_dilate = 4.0,
                 padding = 12):

        proc = Popen(['which', 'textFeats'], shell=False, stdin=PIPE, stdout=PIPE, stderr=PIPE, close_fds=True)
        proc_out, proc_err = proc.communicate()
        if proc.returncode != 0:
            raise Exception('Unable to locate textFeats command.')
        self.textfeat = proc_out.decode('utf-8').strip()

        proc = Popen([self.textfeat, '--version'], shell=False, stdin=PIPE, stdout=PIPE, stderr=PIPE, close_fds=True)
        proc_out, proc_err = proc.communicate()
        textfeat_version_min = '2019.01.21'
        textfeat_version = ''
        for line in [s.strip() for s in proc_err.decode('utf-8').splitlines()]:
            tokens = line.split()
            if tokens[-2] == 'TextFeatExtractor':
                textfeat_version = tokens[-1]
        if textfeat_version == '' or StrictVersion(textfeat_version) < StrictVersion(textfeat_version_min):
            raise Exception('textFeat version required to be at least '+textfeat_version_min+' but installed is '+textfeat_version)

        self.keeptmp = keeptmp
        self.tempdir = tempfile.TemporaryDirectory(prefix='textfeat_legacy_')
        self.tempdirname = self.tempdir.name
        if keeptmp:
            keep_temp_dir(self.tempdir)
            self.tempdirname += '_kept'
        self.cfgfile = os.path.join(self.tempdirname, 'textfeat.cfg')

        cfg =  'TextFeatExtractor: {\n'
        cfg += '  type = "raw";\n'
        cfg += '  format = "img";\n'
        cfg += '  verbose = ' + str(verbose).lower() + ';\n'
        cfg += '  procimgs = ' + str(procimgs).lower() + ';\n'
        cfg += '  stretch = ' + str(stretch).lower() + ';\n'
        cfg += '  enh = ' + str(enh).lower() + ';\n'
        cfg += '  enh_win = ' + str(enh_win) + ';\n'
        cfg += '  enh_slp = ' + str(enh_slp) + ';\n'
        if enh3_prm0 == 0.0 and enh3_prm2 == 0.0:
            cfg += '  enh_prm = ' + str(enh_prm) + ';\n'
        else:
            cfg += '  enh_prm = [ ' + str(enh3_prm0) + ', ' + str(enh_prm) + ', ' + str(enh3_prm2) + ' ];\n'
        cfg += '  deslope = ' + str(deslope).lower() + ';\n'
        cfg += '  deslant = ' + str(deslant).lower() + ';\n'
        cfg += '  normxheight = ' + str(normxheight) + ';\n'
        cfg += '  normheight = ' + str(normheight) + ';\n'
        cfg += '  momentnorm = ' + str(momentnorm).lower() + ';\n'
        cfg += '  fpgram = ' + str(compute_fpgram).lower() + ';\n'
        cfg += '  fcontour = ' + str(compute_fcontour).lower() + ';\n'
        cfg += '  fcontour_dilate = ' + str(fcontour_dilate) + ';\n'
        cfg += '  padding = ' + str(padding) + ';\n'
        cfg += '}\n'

        with open(self.cfgfile, 'w') as config_file:
            config_file.write(cfg)

    def extractFeats(self, fxml, xpath='//_:TextLine/_:Coords[@points and @points!="0,0 0,0"]'):
        """Extracts features for a given page xml path and Coords xpath.

        Args:
            fxml (str): Path to Page XML file.
            xpath (str): XPATH for selection Coords elements to extract. ght, variable_width).
        Returns:
            A dictionary with sample names as keys and numpy array images as values.
        """

        featdir = tempfile.TemporaryDirectory(prefix='extraction_', dir=self.tempdirname)

        cmd = [self.textfeat, '--cfg', self.cfgfile, '--outdir', featdir.name, '--featlist', '--xpath', xpath, fxml]
        proc = Popen(cmd, shell=False, stdin=PIPE, stdout=PIPE, stderr=PIPE, close_fds=True)
        proc_out, proc_err = proc.communicate()
        proc_rc = proc.returncode
        if proc.returncode != 0:
            keep_temp_dir(featdir)
            raise Exception('textFeats command returned non-zero code :: '+proc_err.decode('utf-8'))

        feats = {}

        for fname in [s.strip() for s in proc_out.decode('utf-8').splitlines()]:
            try:
                img = cv2.imread(fname)
                samp = os.path.splitext(os.path.basename(fname))[0]
                feats[samp] = img
            except:
                raise Exception('Problems reading features image '+fname)

        if self.keeptmp:
            keep_temp_dir(featdir)

        return feats
