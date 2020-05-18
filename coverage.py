#!/usr/bin/python

import sys
from subprocess import call, STDOUT
from os import remove

dev_null=open('/dev/null', 'w')

coverage_command = ['./coverage']
for file in sys.argv[1:] :

    output_filename = file + '.xml'
    srcml_command = ['srcml', file, '-o', output_filename]
    call(srcml_command, stdout=dev_null, stderr=STDOUT)
    coverage_command.append(output_filename)


dev_null.close()
call(coverage_command)

for file in coverage_command[1:] :
    remove(file)


