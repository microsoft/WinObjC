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
#include "tokenizer.h"
#include "SBLog.h"
#include "SimpleVariableCollection.h"
#include "xcconfigparser.h"

static String extractIncludeName(const String& includeLine) {
    // Tokenize the line
    StringVec tokens;
    tokenize(includeLine, tokens, " \t", "", "\"", "\"", "", true);

    // Sanity check
    if (tokens.size() < 2 || tokens.front() != "#include")
        return "";

    // Get the name of the included file
    String includeName = tokens[1];
    unsigned includeNameSize = includeName.size();

    // Sanity check on the include name, which must be at least 3 characters - "A"
    if (includeNameSize < 3 || includeName[0] != '"' || includeName[includeNameSize - 1] != '"')
        return "";

    return includeName.substr(1, includeNameSize - 2);
}

static String getAbsIncludePath(const String& includeName, const StringList& searchPaths) {
    // Sanity check
    if (includeName.empty())
        return "";

    // Create a list of include names to search for
    StringList includeNames;
    includeNames.push_back(includeName);

    // If the include name doesn't have an extension, add .xcconfig to it
    if (sb_fextension(includeName).empty())
        includeNames.push_back(includeName + ".xcconfig");

    StringList::const_iterator pathsIt = searchPaths.begin();
    StringList::const_iterator namesIt = includeNames.begin();
    for (; namesIt != includeNames.end(); namesIt++) {
        for (; pathsIt != searchPaths.end(); pathsIt++) {
            String absPath = joinPaths(*pathsIt, *namesIt);

            // Try to open the file, to see if it exists
            std::ifstream cfile(absPath.c_str());
            if (cfile.is_open())
                return absPath;
        }
    }

    return "";
}

static bool parseFile(const String& absFilePath, VariableCollection& variables, StringList& searchPaths) {
    // Open the file
    std::ifstream cfile(absFilePath.c_str());
    if (!cfile.is_open()) {
        SBLog::warning() << "Failed to open \"" << absFilePath << "\" configuration file." << std::endl;
        return false;
    }

    String line;
    unsigned lineNumber = 1;
    bool status = true;
    while (cfile.good() && status) {
        // Read next line from the file
        getline(cfile, line);

        // Trim the line of whitespace
        line = trim(line, " \t");

        // Process the line
        if (line.empty() || strBeginsWith(line, "//")) {
            // Ignore comments and empty lines
        } else if (strBeginsWith(line, "#include")) {
            // Extract the include name
            String includeName = extractIncludeName(line);
            if (includeName.empty()) {
                SBLog::warning() << "Failed to parse include line " << lineNumber << " in \"" << absFilePath << "\"." << std::endl;
                continue;
            }

            // Find an absolute path to the included file
            searchPaths.push_front(sb_dirname(absFilePath));
            String absIncludePath = getAbsIncludePath(includeName, searchPaths);
            searchPaths.pop_front();
            if (absIncludePath.empty()) {
                SBLog::warning() << "Failed to find \"" << includeName << "\" file, included from \"" << absFilePath << ":" << lineNumber
                                 << "\"" << std::endl;
                continue;
            }

            // Parse the file
            status = parseFile(absIncludePath, variables, searchPaths);
        } else {
            status = processVariableAssignment(line, ASSIGN_MAKE, variables);
            if (!status)
                SBLog::warning() << "Failed to parse line " << lineNumber << " in \"" << absFilePath << "\"." << std::endl;
        }

        lineNumber++;
    }

    return status;
}

VariableCollection* parseXCConfigFile(const String& absFilePath, const String& projectDir) {
    // Create a VariableCollection to read settings into
    SimpleVariableCollection* ret = new SimpleVariableCollection;

    // Set up a list of search paths for includes
    StringList searchPaths;
    searchPaths.push_back(projectDir);

    // Parse the specified xcconfig file
    if (!parseFile(absFilePath, *ret, searchPaths)) {
        delete ret;
        ret = NULL;
    }

    return ret;
}

bool processVariableAssignment(const String& assignStr, AssignStyle style, VariableCollection& vc) {
    if (assignStr.empty())
        return true;

    // Extract the variable name
    std::size_t posn = assignStr.find_first_of('=');
    String varName = trim(assignStr.substr(0, posn));

    // Check that this looks to be a valid assignment
    if (posn == std::string::npos || varName.empty()) {
        SBLog::warning() << "Failed to parse variable assignment: " << assignStr << std::endl;
        return false;
    }

    // Get the assigned value, which could be empty
    String varValue;
    if (posn + 1 < assignStr.length())
        varValue = assignStr.substr(posn + 1);

    // Trim whitespace from the value, if this is a make assignment
    if (style == ASSIGN_MAKE)
        varValue = trim(varValue);

    // Save the value in the map
    vc.insert(varName, varValue);
    return true;
}
