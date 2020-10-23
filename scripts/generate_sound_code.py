# -*- coding: utf-8 -*-
"""
Created on Sat Jun 20 14:56:51 2020

@author: Jeff
"""

import os
import glob

###############################################################################
c3_dir = r'C:\applications\Impressions Games\Caesar3'
media_directory = 'smk'
code_directory = r'D:\code\development\applications\tiberius\source\tiberius\src\media'
header_file_name = 'videos.h'
source_file_name = 'videos.cpp'
enum_prefix = 'VIDEO_'
max_var_name = 'MAX_VIDEOS'
var_name = 'videos'
pair_name = 'VideoPair'
###############################################################################

def main():
    search_string = os.path.join(c3_dir, media_directory, '*.*')
    file_list = glob.glob(search_string)
    write_header_file(code_directory, header_file_name, file_list)
    write_source_file(code_directory, source_file_name, file_list)

def write_header_file(code_directory, header_file_name, file_list):
    header_file_path = os.path.join(code_directory, header_file_name)
    include_guard = header_file_name.replace('.', '_').upper()
    header_file = open(header_file_path, 'w')
    header_file.write('#ifndef {}\n'.format(include_guard))
    header_file.write('#define {}\n\n'.format(include_guard))
    header_file.write('#include <QString>\n')
    header_file.write('#include <utility>\n')
    header_file.write('\n')
    header_file.write('static const int {} = {};\n'.format(max_var_name, len(file_list)))
    header_file.write('using {} = std::pair<int, QString>;\n'.format(pair_name))
    header_file.write('extern {} {}[{}];\n'.format(pair_name, var_name, max_var_name))
    header_file.write('\n')
    header_file.write('enum {\n')
    
    for file in file_list:
        file_name = os.path.basename(file)
        file_title = os.path.splitext(file_name)[0]
        enum_value = enum_prefix + file_title.upper()
        header_file.write('  {},\n'.format(enum_value))
        
    header_file.write('};\n\n')
    header_file.write('#endif // {}\n'.format(include_guard))
    header_file.close()
    
def write_source_file(code_directory, source_file_name, file_list):
    source_file_path = os.path.join(code_directory, source_file_name)
    
    source_file = open(source_file_path, 'w')
    source_file.write('#include "{}.h"\n'.format(var_name))
    source_file.write('\n')
    source_file.write('{} {}[{}] = '.format(pair_name, var_name, max_var_name))
    source_file.write('{\n')
    for file in file_list:
        file_name = os.path.basename(file)
        file_title = os.path.splitext(file_name)[0]
        enum_value = enum_prefix + file_title.upper()
        file_path = "{}/".format(media_directory) + file_name
        source_file.write('  {')
        source_file.write('{}, "{}"'.format(enum_value, file_path))
        source_file.write('},\n')
        
    source_file.write('};\n')
    source_file.close()
    
if __name__ == '__main__':
    main()