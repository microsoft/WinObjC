#!/usr/bin/python

from __future__ import print_function
import os
import sys
import errno
import argparse
import tempfile
import subprocess
import shlex
import shutil
import stat
import json

cmdLog = None

# Derived from http://stackoverflow.com/a/4417735
def execute(command):
    cmdLog.write(command + '\n')
    p = subprocess.Popen(command, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    lines_iterator = iter(p.stdout.readline, b"")
    savedOutput = []
    for line in lines_iterator:
        savedOutput.append(line.rstrip('\r\n'))
        cmdLog.write(line) # yield line
    cmdLog.write('\n')

    if p.wait() == 0:
        print('SUCCESS')
    else:
        raise ValueError('Command returned with non-zero value.')

    return savedOutput

# Derived from http://stackoverflow.com/a/22331852
def copytree(src, dst, symlinks = False, ignore = None):
  if not os.path.exists(dst):
    os.makedirs(dst)
    shutil.copystat(src, dst)
  lst = os.listdir(src)
  if ignore:
    excl = ignore(src, lst)
    lst = [x for x in lst if x not in excl]
  for item in lst:
    s = os.path.join(src, item)
    d = os.path.join(dst, item)
    if symlinks and os.path.islink(s):
      if os.path.lexists(d):
        os.remove(d)
      os.symlink(os.readlink(s), d)
      try:
        st = os.lstat(s)
        mode = stat.S_IMODE(st.st_mode)
        os.lchmod(d, mode)
      except:
        pass # lchmod not available
    elif os.path.isdir(s):
      copytree(s, d, symlinks, ignore)
    else:
      shutil.copy2(s, d)

# # Derived from http://stackoverflow.com/a/1889686
def remove_readonly(func, path, excinfo):
    os.chmod(path, stat.S_IWRITE)
    func(path)

# Wrap os.makedirs to not throw exception when directory already exists
def makedirs(path):
    try:
        os.makedirs(path)
    except OSError as e:
        if e.errno == errno.EEXIST and os.path.isdir(path):
            pass
        else:
            raise

class getsource:
    def __init__(self, globalargs, testname, actiondict):
        # Initialize attributes
        self.globalargs = globalargs
        self.testname = testname
        for k, v in actiondict.items():
            setattr(self, k, v)

        # Check for important values
        if (not self.cmd):
            raise ValueError(testname + 'test does not specify a getsource command.')
        if (not self.output):
            raise ValueError(testname + 'test does not specify an output directory.')

    def execute(self, clean):
        os.chdir(self.globalargs.srcdir)

        if (os.path.isdir(self.output) and clean):
            print('Removing ' + self.testname + ' source directory... ', end='')
            shutil.rmtree(self.output, onerror=remove_readonly)
            print('SUCCESS')

        if (not os.path.isdir(self.output)):
            print('Acquiring ' + self.testname + ' source code... ', end='')
            execute(self.cmd)

        print('Entering the ' + self.testname + ' repository directory... ', end='')
        os.chdir(self.output)
        print('SUCCESS')

class vsimport:
    def __init__(self, globalargs, testname, actiondict):
        # Initialize attributes
        self.globalargs = globalargs
        self.testname = testname
        self.args = ''
        for k, v in actiondict.items():
            setattr(self, k, v)

        if (self.dir):
            self.dir = os.path.join(globalargs.srcdir, self.dir)

    def execute(self, clean):
        if (self.dir):
            print('Entering the ' + self.testname + ' import directory... ', end='')
            os.chdir(self.dir)
            print('SUCCESS')

        print('Generating ' + self.testname + ' VS projects... ', end='')
        vsimporter = os.path.join(sys.path[0], '..\\..\\bin\\vsimporter.exe')
        output = execute(vsimporter + ' ' + self.args)

        print('Copying test signing certificates...', end='')
        for line in output:
            if not (line.startswith('Generated ') and line.endswith('.vcxproj')):
                continue

            projectDir = os.path.dirname(line[10:])
            projectName = os.path.splitext(os.path.basename(line))[0]
            if os.path.isfile(os.path.join(projectDir, 'Package.appxmanifest')):
                shutil.copyfile(os.path.join(sys.path[0], 'TemporaryKey.pfx'), os.path.join(projectDir, projectName + '_TemporaryKey.pfx'))
        print('SUCCESS')

class msbuild:
    def __init__(self, globalargs, testname, actiondict):
        # Initialize attributes
        self.globalargs = globalargs
        self.testname = testname
        self.args = ''
        self.dir = ''
        for k, v in actiondict.items():
            setattr(self, k, v)

        if (self.dir):
            self.dir = os.path.join(globalargs.srcdir, self.dir)

    def execute(self, clean):
        if (self.dir):
            print('Entering the ' + self.testname + ' build directory... ', end='')
            os.chdir(self.dir)
            print('SUCCESS')

        print('Building ' + self.testname + ' projects... ', end='')
        execute('MSBuild.exe ' + self.args)

        print('Copying ' + self.testname + ' AppX packages... ', end='')
        for root, subFolders, files in os.walk('AppPackages'):
            for file in files:
                if file.endswith('.appx'):
                    copytree(root, os.path.join(self.globalargs.appxdir, os.path.basename(root)))
                    subFolders[:] = []
                    break;
        print('SUCCESS')

def main(argv):
    # Get PATH from the environment
    envPath = os.environ.get("PATH", os.defpath)

    # Set up argument parsing
    parser = argparse.ArgumentParser(description = 'Run WinObjC tests.')
    parser.add_argument('--testfile', default = os.path.join(sys.path[0], 'AutoAppBuild-tests.json'), type = argparse.FileType('r'), help = 'Test descriptions file.')
    parser.add_argument('--clean', default = False, action='store_true', help = 'Clean git repositories before buidling.')
    parser.add_argument('--srcdir', default = "src", help = 'Directory where tests will be cloned and built.')
    parser.add_argument('--appxdir', default = "appx", help = 'Destination directory for AppX packages.')
    args = parser.parse_args()

    # Create build directory
    args.srcdir = os.path.abspath(args.srcdir)
    makedirs(args.srcdir)

    # Create AppX directory
    args.appxdir = os.path.abspath(args.appxdir)
    makedirs(args.appxdir)

    # Open log file
    global cmdLog
    cmdLog = open(os.path.join(args.srcdir, 'CmdLog.txt'), 'wb', 1)

    # Read the JSON test descriptions
    tests = json.load(args.testfile)

    # Print info
    print('Test file:', args.testfile.name)
    print('Build directory: ', args.srcdir)
    print('AppX directory: ', args.appxdir)

    # Iterate over tests
    successCount = 0
    totalCount = 0
    for test in tests:
        # Deserialize build steps into objects
        actionObjects = []
        try:
            for step in test['buildSteps']:
                actionObj = globals()[step['action']](args, test['name'], step)
                actionObjects.append(actionObj)
            totalCount += 1
        except Exception as e:
            print('Failed to parse test description: ' + str(e))
            continue

        # Execute build steps
        print()
        try:
            for action in actionObjects:
                action.execute(args.clean)
            successCount += 1
        except Exception as e:
            print('FAILURE')
            cmdLog.write(str(e))

    # Print results
    print()
    print('Results: ' + str(successCount) + '/' + str(totalCount))

if __name__ == "__main__":
    main(sys.argv)