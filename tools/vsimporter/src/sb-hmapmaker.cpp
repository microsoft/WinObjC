//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//******************************************************************************

#include "hmapmaker.h"
#include "sbassert.h"
#include "fileutils.h"

#include <iostream>
#include <fstream>

void printUsage(const char *execName, int exitCode)
{
  std::cout << execName << " <input-header-list> <output-hmap>" << std::endl;
  exit(exitCode);
}

void readStrings(const String& inputFile, StringVec& inVec)
{
  std::ifstream inFile(inputFile.c_str());
  sbValidate(inFile.is_open(), "Failed to open \"" + inputFile + "\" input file for reading.");

  String line;
  while (getline(inFile, line)) {
    inVec.push_back(line);
  }
  inFile.close();
}

void writeHMap(const String& outputFile, const StringVec& inVec)
{
  IncludeMapMaker hmap;

  std::ofstream outFile(outputFile.c_str(), std::ofstream::out | std::ofstream::binary);
  sbValidate(outFile.is_open(), "Failed to open \"" + outputFile + "\" output file for writing.");

  StringVec::const_iterator it = inVec.begin();
  for (; it != inVec.end(); ++it) {
    hmap.addMapping(sb_basename(*it), *it);
  }

  hmap.writeMap(outFile);
  outFile.close();
}

int main(int argc, const char* argv[])
{
  if (argc != 3)
    printUsage(argv[0], -1);

  String inputFile(argv[1]);
  String outputFile(argv[2]);

  // Read in the input file
  StringVec inVec;
  readStrings(inputFile, inVec);
  
  // Write header map
  writeHMap(outputFile, inVec);
}