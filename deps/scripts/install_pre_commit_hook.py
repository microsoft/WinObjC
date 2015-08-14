#!/usr/bin/python

import os
import platform
import shutil

f = os.path.abspath(__file__) 
scripts_dir = os.path.split(f)[0]
git_hooks_dir = os.path.abspath(os.path.join(scripts_dir, '../../.git/hooks'))

pre_commit_hook_dst = os.path.join(git_hooks_dir, 'pre-commit')
if os.path.islink(pre_commit_hook_dst) or os.path.isfile(pre_commit_hook_dst):
    print 'Removed previously installed hook'
    os.remove(pre_commit_hook_dst)
    
pre_commit_hook_src = os.path.join(scripts_dir,   'pre_commit.py')
if platform.system() == 'Windows':
	shutil.copy(pre_commit_hook_src, pre_commit_hook_dst)
	print 'Installed git hook into', pre_commit_hook_dst
else:
	os.symlink(pre_commit_hook_src, pre_commit_hook_dst)
	print 'Installed git hook into', pre_commit_hook_dst, '~>', pre_commit_hook_src
