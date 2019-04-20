#!/usr/bin/env python
"""Converts doxygen XMLs into swig python docstrings."""

import sys
import argparse
from lxml import etree
from collections import OrderedDict

### Main block called only when run from command line ###
if __name__ == '__main__':
    ### Parse input arguments ###
    parser = argparse.ArgumentParser(
        description='Converts doxygen XMLs into swig python docstrings.',
        formatter_class=argparse.ArgumentDefaultsHelpFormatter)
    parser.add_argument('xml', nargs='+',
                        help='Doxygen XML files.')
    parser.add_argument('--output', default='-',
                        help='Path to file where to write the result.')
    opts = parser.parse_args()

    class_xpath = '//memberdef[@kind="function" and @prot="public" and ancestor::compounddef[@kind="class" and @language="C++"]]'

    def get_node_text(node):
        if isinstance(node, list):
            if len(node) == 0:
                return ''
            node = node[0]
        return ''.join(node.itertext()).strip().replace('"','\\"')

    with sys.stdout if opts.output == '-' else open(opts.output,'w') as output_file:

        ### Loop through XML files ###
        for nth_xml in opts.xml:
            output_file.write('// File: '+nth_xml+'\n\n')

            xml = etree.parse(nth_xml)

            ### Get unique class members ###
            members = OrderedDict()
            for elem in xml.xpath('//listofallmembers/member[@prot="public"]'):
                key = elem.xpath('scope')[0].text + '::' + elem.xpath('name')[0].text
                if key not in members:
                    members[key] = []
                members[key].append(elem.get('refid'))

            ### Loop through each unique member ###
            for key in sorted(members.keys()):
                refids = members[key]
                output_file.write('%feature("docstring") '+key+' "\n')
                if len(refids) > 1:
                    output_file.write('Overloaded function with '+str(len(refids))+' signatures.\n\n')

                ### Loop through signatures ###
                for num, refid in enumerate(refids):
                    memberdef = xml.xpath('//memberdef[@id="'+refid+'"]')[0]
                    if len(refids) > 1:
                        output_file.write('**Signature '+str(num+1)+'**\n\n')
                            
                        signature = get_node_text(memberdef.xpath('definition'))+get_node_text(memberdef.xpath('argsstring'))
                        output_file.write('``'+signature+'``\n\n')

                    ### Description ###
                    for para in memberdef.xpath('detaileddescription/para[not(parameterlist or simplesect)]'):
                        output_file.write(get_node_text(para)+'\n\n')

                    ### Arguments ###
                    for pnum, param in enumerate(memberdef.xpath('param')):
                        if pnum == 0:
                            output_file.write('Arguments:\n')
                        declname = get_node_text(param.xpath('declname'))
                        ptype = get_node_text(param.xpath('type'))
                        ptype = '' if not ptype else ' ('+ptype+')'
                        output_file.write('    '+declname+ptype+': ')
                        paras = param.xpath('..//parameteritem[parameternamelist/parametername="'+declname+'"]/parameterdescription/para')
                        if len(paras) == 0:
                            output_file.write('\n')
                        else:
                            for para in paras:
                                output_file.write(get_node_text(para)+'\n')
                    output_file.write('\n')

                    ### Returns ###
                    mtype = get_node_text(memberdef.xpath('type'))
                    text = get_node_text(memberdef.xpath('.//simplesect[@kind="return"]'))
                    if (mtype or text) and mtype != 'void':
                        output_file.write('Returns:\n')
                        output_file.write('    '+mtype+': '+text+'\n\n')

                output_file.write('";\n\n')
