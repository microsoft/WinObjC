### Building vsimporter, hmapmaker, xib2nib and sb-expandvars tools
1. Download and install CMake from the official website [here](https://cmake.org/download/).
2. Check out required submodules, using Git Bash:
   ```
   cd WinObjC/tools/vsimporter
   git submodule update --init --recursive third-party/PlistCpp
   git submodule update --init --recursive third-party/sole
   ```
3. Run cmake from the Command Prompt to generate a Visual Studio solution:
   ```
   cd WinObjC\tools\vsimporter
   md build
   cd build
   cmake ..
   ```
4. Open VSImporter.sln from the build directory.
5. Build the appropriate tool project.