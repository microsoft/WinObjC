#!/usr/bin/env python

import argparse
import difflib
import re
import string
import subprocess
import StringIO
import sys
import os
import tempfile
import platform

is_windows = False
if platform.system() == 'Windows':
    is_windows = True

# Check whether line ending is to be fixed on Windows manually as apparently Python's universal newlines, i.e. 'rU' mode for open(), does not work
needs_line_edings_fix = False
if is_windows:
    key_value_match = re.compile(r'^\s*(.+?)\s*=\s*(.+?)\s*$')
    p = subprocess.Popen(['git', 'config', '--list'], stdout=subprocess.PIPE, stderr=None)
    stdout, stderr = p.communicate()
    if p.returncode == 0:
        lines = StringIO.StringIO(stdout).readlines()
        for line in lines:
            mo = key_value_match.search(line)
            if mo:
                key = mo.group(1)
                if key != 'core.autocrlf':
                    continue
                value = mo.group(2)
                if value == 'true':
                    needs_line_edings_fix = True

binary_name = 'clang-format'
if is_windows:
    binary_name = 'clang-format.exe'
binary = os.path.abspath(os.path.join(os.path.dirname( __file__ ), '..', '..', 'bin', binary_name))
patch_prefix = 'com.microsoft.WinObjC.codestyle.'
patch_suffix = '.patch'

def main():
    # Delete previously generated patches
    temp_folder = tempfile.gettempdir()
    for filename in os.listdir(temp_folder):
        if filename.startswith(patch_prefix) and filename.endswith(patch_suffix):
            os.remove(os.path.join(temp_folder, filename))
    
    # Retrieve changes which are to be committed
    p = subprocess.Popen(['git', 'diff', '--no-color', '--cached'], stdout=subprocess.PIPE, stderr=None)
    stdout, stderr = p.communicate()
    if p.returncode != 0:
        sys.exit(p.returncode)
    lines = StringIO.StringIO(stdout).readlines()
    
    # Extract changed lines for each file
    filename = None
    lines_by_file = {}
    for line in lines:
        match = re.search('^\+\+\+\ (.*?/){1}(\S*)', line)
        if match:
            filename = match.group(2)
        if filename == None:
            continue
            
        # Skip unnecessary files
        if not re.match('^.*\.(h|m|mm)$', filename):
            continue

        if not 'Frameworks' in filename:
            continue

        match = re.search('^@@.*\+(\d+)(,(\d+))?', line)
        if match:
            start_line = int(match.group(1))
            line_count = 1
            if match.group(3):
                line_count = int(match.group(3))
            if line_count == 0:
                continue
            end_line = start_line + line_count - 1
            lines_by_file.setdefault(filename, []).extend(['-lines', str(start_line) + ':' + str(end_line)])

    # Reformat files containing changes in place
    patch_contents = ''
    for filename, lines in lines_by_file.iteritems():
        command = [binary, '-style=file', filename]
        command.extend(lines)
        p = subprocess.Popen(command, stdout=subprocess.PIPE, stderr=None, stdin=subprocess.PIPE)
        stdout, stderr = p.communicate()
        if p.returncode != 0:
            sys.exit(p.returncode)

        with open(filename) as f:
            code = f.readlines()

        if needs_line_edings_fix:
            code_with_fixed_ending = []
            for code_line in code:
                code_line_with_fixed_ending = code_line.replace('\n', '\r\n')
                code_with_fixed_ending.append(code_line_with_fixed_ending)
            code = code_with_fixed_ending

        formatted_code = StringIO.StringIO(stdout).readlines()

        diff = difflib.unified_diff(code, formatted_code, filename, filename, '(before formatting)', '(after formatting)')
        diff_string = string.join(diff, '')
        if len(diff_string) > 0:
            patch_contents += diff_string
            if 'STOP_ON_CODESTYLE_ERROR' in os.environ:
                break

    if len(patch_contents) > 0:
        temp_patch_file = tempfile.NamedTemporaryFile(prefix=patch_prefix, suffix=patch_suffix, delete=False)
        temp_patch_file.write(patch_contents)
        temp_patch_file_path = temp_patch_file.name
        temp_patch_file.close() # Sync
        
        execute_string = 'cat ' + temp_patch_file_path + ' | patch -p0'
            
        print 'ERROR: INCORRECT CODE STYLE'
        print 'If you believe it is correct, use \'-n\' or \'--no-verify\' option to ignore this error.'
        print 'Otherwise execute \'' + execute_string + '\' to fix found issues.'
        print 'Do NOT forget to add changes to the index if needed or use \'-a\' option, otherwise they will be lost.'

        print patch_contents
        sys.exit(1)

if __name__ == '__main__':
    main()
