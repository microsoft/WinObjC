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

#include "utils.h"
#include "sbassert.h"
#include "xcconfigparser.h"
#include "VariableCollectionHierarchy.h"
#include "EnvironmentVariableCollection.h"

#include <iostream>
#include <getopt.h>
#include <fstream>

void printVersion(const char *execName)
{
  static String binaryVersion = "1.0";
  std::cout << sb_basename(execName) << " " << binaryVersion << std::endl;
  exit(EXIT_SUCCESS);
}

void readStrings(const String& inputFile, StringVec& inVec)
{
  ifstream inFile(inputFile.c_str());
  sbValidate(inFile.is_open(), "Failed to open \"" + inputFile + "\" input file for reading.");

  String line;
  while (getline(inFile, line)) {
    inVec.push_back(line);
  }
  inFile.close();
}

void writeExpandedStrings(const String& outputFile, const VariableCollectionHierarchy& vch, const StringVec& inVec)
{
  ofstream outFile(outputFile.c_str());
  sbValidate(outFile.is_open(), "Failed to open \"" + outputFile + "\" output file for writing.");

  StringVec::const_iterator it = inVec.begin();
  for (; it != inVec.end(); ++it) {
    outFile << vch.expand(*it) << std::endl;
  }
  outFile.close();
}

void printUsage(const char *execName, bool full, int exitCode)
{
  std::cout << "Usage: ";
  std::cout << "\t" << sb_basename(execName) << " ";
  std::cout << "-input inFile -output outFile [-xcconfig xcVarsFile]";

  // Don't print option descriptions if brief usage was requested
  if (!full)
    goto done;

  std::cout << std::endl;
  std::cout << "Options:" << std::endl;
  std::cout << "    -usage" << "\t\t    print brief usage message" << std::endl;
  std::cout << "    -help" << "\t\t    print full usage message" << std::endl;
  std::cout << "    -input FILE" << "\t\t    source file with unexpanded variables" << std::endl;
  std::cout << "    -output FILE" << "\t\t    destination file to write, with all variables replaced" << std::endl;
  std::cout << "    -xcconfig FILE" << "\t    variables file" << std::endl;
  std::cout << "    -version" << "\t\t    print the tool version" << std::endl;

done:
  exit(exitCode);
}

int main(int argc, char* argv[])
{
  static struct option long_options[] = {
    {"usage", no_argument, 0, 0},
    {"help", no_argument, 0, 0},
    {"input", required_argument, 0, 0},
    {"output", required_argument, 0, 0},
    {"xcconfig", required_argument, 0, 0},
    {"version", no_argument, 0, 0},
    {0, 0, 0, 0}
  };

  String inputFile, outputFile, varsFile;

  int numOptions = sizeof(long_options) / sizeof(struct option) - 1;
  while (1) {
    int option_index = 0;
    int c = getopt_long_only(argc, argv, "", long_options, &option_index);

    if (c == -1)
      break;
    else if (c || option_index < 0 || option_index >= numOptions)
      printUsage(argv[0], false, EXIT_FAILURE);

    // Process options
    switch (option_index) {
    case 0:
      printUsage(argv[0], false, EXIT_SUCCESS);
      break;
    case 1:
      printUsage(argv[0], true, EXIT_SUCCESS);
      break;
    case 2:
      inputFile = optarg;
      break;
    case 3:
      outputFile = optarg;
      break;
    case 4:
      varsFile = optarg;
      break;
    case 5:
      printVersion(argv[0]);
      break;
    default:
      // Do nothing
      break;
    }
  }

  // Process extra ARGV-elements
  StringVec extraArgs;
  for (; optind < argc; optind++)
    extraArgs.push_back(argv[optind]);
  sbValidate(extraArgs.empty(), "Unsupported arguments: " + joinStrings(extraArgs, " "));

  // Check that input and output files are specified
  sbValidate(!inputFile.empty(), "Input file not specified.");
  sbValidate(!outputFile.empty(), "Output file not specified.");

  // Read in the input file
  StringVec inVec;
  readStrings(inputFile, inVec);

  // Set up variable hierarchy
  VariableCollectionHierarchy vch;
  if (!varsFile.empty()) {
    VariableCollection* vc = parseXCConfigFile(varsFile, ".");
    sbValidate(vc);
    vch.push_back(*vc);
  } else {
    vch.push_back(EnvironmentVariableCollection::get());
  }

  // Write expanded strings
  writeExpandedStrings(outputFile, vch, inVec);

  return EXIT_SUCCESS;
}
