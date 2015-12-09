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

#include <iostream>
#include <getopt.h>
#include <dirent.h>

#include "version.h"
#include "sbassert.h"
#include "types.h"
#include "utils.h"
#include "SBLog.h"
#include "BuildSettings.h"
#include "VariableCollectionManager.h"
#include "SBWorkspace.h"

#define QUOTE(name) #name
#define STR(macro) QUOTE(macro)

enum {
  GenerateMode = 0,
  ListMode = 1
};

static void checkWinObjCSDK()
{
  const BuildSettings bs(NULL);
  String sdkRoot = bs.getValue("WINOBJC_SDK_ROOT");
  String baseErrMsg = "Invalid WINOBJC_SDK_ROOT specified: \"" + platformPath(sdkRoot) + "\". ";
  sbValidate(!sb_realpath(sdkRoot).empty(), baseErrMsg + "The SDK directory does not exist.");

  String templateDir = bs.getValue("VSIMPORTER_TEMPLATES_DIR");
  sbValidate(!sb_realpath(templateDir).empty(), baseErrMsg + "The SDK directory is missing vsimporter templates.");
}

void printVersion(const char *execName)
{
static String binaryVersion = String("1.0 (") + STR(VERSION_SHA) + ")";
  std::cout << sb_basename(execName) << " " << binaryVersion << std::endl;
  exit(EXIT_SUCCESS);
}

void printUsage(const char *execName, bool full, int exitCode)
{
  std::cout << "Usage: ";
  std::cout << "\t" << sb_basename(execName) << " ";
  std::cout << "[-project projectname] [-target targetname ...] [-configuration configurationname] ";
  std::cout << "[-interactive] [setting=value ...]";
  std::cout << std::endl;
  std::cout << "\t" << sb_basename(execName) << " ";
  std::cout << "[-project projectname] -scheme schemename [-configuration configurationname] ";
  std::cout << "[-interactive] [setting=value ...]";
  std::cout << std::endl;
  std::cout << "\t" << sb_basename(execName) << " ";
  std::cout << "-workspace workspacename -scheme schemename [-configuration configurationname] ";
  std::cout << "[-interactive] [setting=value ...]";
  std::cout << std::endl;
  std::cout << "\t" << sb_basename(execName) << " ";
  std::cout << "-list [-project projectname | -workspace workspacename]" << std::endl;

  // Don't print option descriptions if brief usage was requested
  if (!full)
    goto done;

  std::cout << std::endl;
  std::cout << "Program Options" << std::endl;
  std::cout << "    -usage" << "\t\t    print brief usage message" << std::endl;
  std::cout << "    -help" << "\t\t    print full usage message" << std::endl;
  std::cout << "    -interactive" << "\t    enable interactive mode" << std::endl;
  std::cout << "    -loglevel LEVEL" << "\t    debug | info | warning | error" << std::endl;
  std::cout << "    -list" << "\t\t    list the targets and configurations in the project" << std::endl;
  std::cout << "    -sdk SDKROOT" << "\t    specify path to WinObjC SDK root (by default calculated from binary's location)" << std::endl;
  std::cout << "    -relativepath" << "\t    write a relative WinObjC SDK path to project files" << std::endl;
  std::cout << "    -project PATH" << "\t    specify project to process" << std::endl;
  std::cout << "    -workspace PATH" << "\t    specify workspace to process" << std::endl;
  std::cout << "    -target NAME" << "\t    specify target to process" << std::endl;
  std::cout << "    -alltargets" << "\t\t    process all targets" << std::endl;
  std::cout << "    -scheme NAME" << "\t    specify scheme to process" << std::endl;
  std::cout << "    -allschemes" << "\t\t    process all schemes" << std::endl;
  std::cout << "    -configuration NAME" << "\t    specify configuration to use" << std::endl;
  std::cout << "    -xcconfig FILE" << "\t    apply build settings defined in FILE as overrides" << std::endl;
  std::cout << "    -version" << "\t\t    print the tool version" << std::endl;

done:
  exit(exitCode);
}

int main(int argc, char* argv[])
{
  StringSet targets, configurations, schemes;
  String sdkRoot, projectPath, xcconfigPath, workspacePath;
  String logVerbosity("warning");
  int projectSet = 0;
  int workspaceSet = 0;
  int interactiveFlag = 0;
  int relativeSdkFlag = 0;
  int allTargets = 0;
  int allSchemes = 0;
  int mode = GenerateMode;

  static struct option long_options[] = {
    {"version", no_argument, 0, 0},
    {"usage", no_argument, 0, 0},
    {"help", no_argument, 0, 0},
    {"interactive", no_argument, &interactiveFlag, 1},
    {"loglevel", required_argument, 0, 0},
    {"sdk", required_argument, 0, 0},
    {"list", no_argument, &mode, ListMode},
    {"project", required_argument, &projectSet, 1},
    {"target", required_argument, 0, 0},
    {"alltargets", no_argument, &allTargets, 1},
    {"configuration", required_argument, 0, 0},
    {"xcconfig", required_argument, 0, 0},
    {"workspace", required_argument, &workspaceSet, 1},
    {"scheme", required_argument, 0, 0},
    {"allschemes", required_argument, &allSchemes, 1},
    {"relativepath", no_argument, &relativeSdkFlag, 1},
    {0, 0, 0, 0}
  };

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
      printVersion(argv[0]);
      break;
    case 1:
      printUsage(argv[0], false, EXIT_SUCCESS);
      break;
    case 2:
      printUsage(argv[0], true, EXIT_SUCCESS);
      break;
    case 4:
      logVerbosity = strToLower(optarg);
      break;
    case 5:
      sdkRoot = optarg;
      break;
    case 7:
      projectPath = optarg;
      break;
    case 8:
      targets.insert(optarg);
      break;
    case 10:
      configurations.insert(optarg);
      break;
    case 11:
      xcconfigPath = optarg;
      break;
    case 12:
      workspacePath = optarg;
      break;
    case 13:
      schemes.insert(optarg);
      break;
    default:
      // Do nothing
      break;
    }
  }

  // Process non-option ARGV-elements
  VariableCollectionManager& settingsManager = VariableCollectionManager::get();
  while (optind < argc) {
    String arg = argv[optind];
    if (arg == "/?") {
      printUsage(argv[0], true, EXIT_SUCCESS);
    } else if (arg.find_first_of('=') != String::npos) {
      settingsManager.processGlobalAssignment(arg);
    } else {
      sbValidate(0, "Unsupported argument: " + arg);
    }
    optind++;
  }

  // Set output format
  settingsManager.setGlobalVar("VSIMPORTER_OUTPUT_FORMAT", "WinStore10");

  // Set logging level
  SBLogLevel logLevel;
  if (logVerbosity == "debug")
    logLevel = SB_DEBUG;
  else if (logVerbosity == "info")
    logLevel = SB_INFO;
  else if (logVerbosity == "warning")
    logLevel = SB_WARN;
  else if (logVerbosity == "error")
    logLevel = SB_ERROR;
  else if (!logVerbosity.empty())
    sbValidate(0, "Unrecognized logging verbosity: " + logVerbosity);
  SBLog::setVerbosity(logLevel);

  // Look for a project file in current directory, if one hasn't been explicitly specified 
  if (!projectSet && !workspaceSet) {
    StringList projects;
    findFiles(".", "*.xcodeproj", DT_DIR, false, projects);
    StringList workspaces;
    findFiles(".", "*.xcworkspace", DT_DIR, false, workspaces);

    if (!workspaces.empty()) {
      sbValidate(workspaces.size() == 1, "Multiple workspaces found. Select the workspace to use with the -workspace option.");
      workspacePath = workspaces.front();
      workspaceSet = 1;
    } else if (!projects.empty()) {
      sbValidate(projects.size() == 1, "Multiple projects found. Select the project to use with the -project option.");
      projectPath = projects.front();
      projectSet = 1;
    } else {
      sbValidate(0, "The current directory does not contain a project or workspace.");
    }
  }

  // Set the architecture
  String arch = "msvc";
  settingsManager.setGlobalVar("ARCHS", arch);
  settingsManager.setGlobalVar("CURRENT_ARCH", arch);

  // Make sure workspace arguments are valid
  if (workspaceSet) {
    sbValidate(!projectSet, "Cannot specify both a project and a workspace.");
    sbValidate(targets.empty(), "Cannot specify target(s) when specifying a workspace.");
  }

  // Disallow specifying schemes and targets together
  sbValidate((schemes.empty() && !allSchemes) || (targets.empty() && !allTargets), "Cannot specify schemes and targets together.");

  // Process allTargets and allSchemes flags
  if (allSchemes)
    schemes.clear();
  if (allTargets)
    targets.clear();

  // Initialize global settings
  String binaryDir = sb_dirname(getBinaryLocation());
  sbValidate(!binaryDir.empty(), "Failed to resolve binary directory.");
  settingsManager.setGlobalVar("VSIMPORTER_BINARY_DIR", binaryDir);
  settingsManager.setGlobalVar("VSIMPORTER_INTERACTIVE", interactiveFlag ? "YES" : "NO");
  settingsManager.setGlobalVar("VSIMPORTER_RELATIVE_SDK_PATH", relativeSdkFlag ? "YES" : "NO");
  if (!sdkRoot.empty()) {
    sdkRoot = joinPaths(getcwd(), sdkRoot);
  } else {
    sdkRoot = joinPaths(binaryDir, "..");
  }
  settingsManager.setGlobalVar("WINOBJC_SDK_ROOT", sdkRoot);

  // Add useful environment variables to global settings
  String username;
  sbValidate(sb_getenv("USERNAME", username), "Failed to get current username.");
  settingsManager.setGlobalVar("USER", username);

  // Read xcconfig file specified from the command line
  if (!xcconfigPath.empty())
    settingsManager.processGlobalConfigFile(xcconfigPath);

  // Read xcconfig file specified by the XCODE_XCCONFIG_FILE environment variable
  String xcconfigFile;
  if (sb_getenv("XCODE_XCCONFIG_FILE", xcconfigFile))
    settingsManager.processGlobalConfigFile(xcconfigFile);

  // Validate WinObjC SDK directory
  checkWinObjCSDK();

  // Create a workspace
  SBWorkspace *mainWorkspace;
  if (workspaceSet) {
    mainWorkspace = SBWorkspace::createFromWorkspace(workspacePath);
  } else if (projectSet) {
    mainWorkspace = SBWorkspace::createFromProject(projectPath);
  } else {
    sbAssert(0); // non-reachable
  }

  if (mode == ListMode) {
    mainWorkspace->printSummary();
  } else if (mode == GenerateMode) {
    if (allTargets) {
      mainWorkspace->queueAllTargets(configurations);
    } else if (projectSet) {
      mainWorkspace->queueTargets(targets, configurations);
    } else if (workspaceSet) {
      mainWorkspace->queueSchemes(schemes, configurations);
    } else {
      sbAssert(0); // non-reachable
    }
    mainWorkspace->generateFiles();
  } else {
    sbAssert(0); // non-reachable
  }

  return EXIT_SUCCESS;
}
