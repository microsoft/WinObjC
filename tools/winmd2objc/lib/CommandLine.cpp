//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

#include "Precompiled.h"
#include <CommandLine.h>
#include <Misc.h>
#include <ObjectModel.h>

using namespace std;

struct CommandLineTemplate {
    wstring sw;
    wstring arg;
    wstring desc;
};

static CommandLineTemplate gCmds[] =
    { { L"refer", L"winmd file which should be used as reference", L"Winmd file which is to be used as a reference" },
      { L"r", L"api.version.file.txt", L"specify response file for API exclusion" },
      { L"v", L"WinRT directory", L"generate API verification source" },
      { L"inc", L"Directory for additional include headers", L"Adds the directory to additional include headers path." },
      { L"i", L"metadata reference directory", L"specify directory for reference resolution" },
      { L"p", L"generate projects", L"generate new .vcxproj files for ObjCUWP" },
      { L"name", L"Solution Name", L"Name for the solution" },
      { L"merge", L"", L"merge all namespaces in the current input file" },
      { L"nuget", L"Name of nuget package:Version Number", L"Name and version of Nuget package" },
      { L"output", L"", L"Path to output directory" } };

static unsigned int gNCmds = sizeof(gCmds) / sizeof(gCmds[0]);

void printUsage(wchar_t* execName) {
    wprintf(L"  Usage:\n");
    wprintf(L"    %s [Name of winmd file]", execName);
    for (unsigned int i = 0; i < gNCmds; i++) {
        wprintf(L" [-%s (%s)]", gCmds[i].sw.c_str(), gCmds[i].arg.c_str());
    }
    wprintf(L"\n");
    for (unsigned int i = 0; i < gNCmds; i++) {
        wprintf(L"        -%s  %s\n", gCmds[i].sw.c_str(), gCmds[i].desc.c_str());
    }
}

bool parseCommandLine(int argc, wchar_t** argv, CommandLineOptions& options) {
    options.executable = argv[0];
    wstring opt = L"";

    for (int i = 1; i < argc; i++) {
        wstring wArg = argv[i];
        bool consumed = false;
        if (wArg[0] == L'/' || wArg[0] == L'-') {
            if (opt != L"") {
                wprintf(L"Option -%s expecting argument\n", opt.c_str());
                printUsage(argv[0]);
                return false;
            }
            for (unsigned int n = 0; n < gNCmds; n++) {
                if (wArg.substr(1, gCmds[n].sw.length()) == gCmds[n].sw) {
                    if (wArg.length() > gCmds[n].sw.length() + 1) {
                        options.optMap[gCmds[n].sw].push_back(wArg.substr(gCmds[n].sw.length() + 1));
                    } else {
                        opt = gCmds[n].sw;
                    }
                    consumed = true;
                    break;
                }
            }
            if (!consumed) {
                wprintf(L"Unknown argument: %s\n", wArg.c_str());
                printUsage(argv[0]);
                return false;
            }
        }
        if (!consumed) {
            if (opt == L"") {
                replaceAll(wArg, L"/", L"\\");
                options.metaDataFileInfo = { wArg, false };
            } else if (opt == L"merge") {
                replaceAll(wArg, L"/", L"\\");
                options.metaDataFileInfo = { wArg, true };
                opt = L"";
            } else {
                options.optMap[opt].push_back(wArg);
                opt = L"";
            }
        }
    }

    for (auto& nugetInfo : options.optMap[L"nuget"]) {
        size_t pos = nugetInfo.find(L":");
        if (pos == nugetInfo.npos) {
            wprintf(L"Invalid nuget package and version specified\n");
            printUsage(argv[0]);
            return false;
        }
        wstring prefix = L"<PackageReference Include=\"" + nugetInfo.substr(0, pos) + L"\" Version=";
        wstring version = L"\"" + nugetInfo.substr(pos + 1) + L"\"";
        nugetInfo = prefix + version + L" />";
    }

    if (opt != L"") {
        wprintf(L"Option -%s expecting argument\n", opt.c_str());
        printUsage(argv[0]);
        return false;
    }

    if (options.metaDataFileInfo.first.length() == 0) {
        wprintf(L"No source meta data file specified!\n");
        printUsage(argv[0]);
        return false;
    }

    return true;
}