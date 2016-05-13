### Building vsimporter, hmapmaker, xib2nib and sb-expandvars tools
1. Check out required submodules, using Git Bash:
   ```
   cd WinObjC/tools/vsimporter
   git submodule update --init --recursive third-party/PlistCpp
   git submodule update --init --recursive third-party/sole
   ```
2. Build WinObjC/tools/tools.sln