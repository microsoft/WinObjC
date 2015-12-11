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

#include "sbassert.h"
#include "utils.h"
#include "SBLog.h"
#include "SimpleVariableCollection.h"
#include "VariableCollectionHierarchy.h"
#include "BuildSettingsInfo.h"

static bool compare_nocase_breadth_first(const String& first, const String& second)
{
  // Check "path depth" first
  unsigned firstPathDepth = std::count(first.begin(), first.end(), '/');
  unsigned secondPathDepth = std::count(second.begin(), second.end(), '/');
  if (firstPathDepth < secondPathDepth)
    return true;
  else if (firstPathDepth > secondPathDepth)
    return false;
      
  unsigned i = 0;
  while ((i < first.length()) && (i < second.length()) ) {
    if (tolower(first[i]) < tolower(second[i]))
      return true;
    else if (tolower(first[i]) > tolower(second[i]))
      return false;
    ++i;
  }
  
  if (first.length() < second.length())
    return true;
  else
    return false;
}

static String addPrefixQuoted(const String& val, const String& prefix, const VariableCollectionHierarchy& vch)
{
  return prefix + quoteIfNeeded(val);
}

static String expandRecursivePath(const String& path, const String& prefix, const VariableCollectionHierarchy& vch)
{
  // Check if recursive expansion is necessary
  if (!strEndsWith(path, "/**"))
    return addPrefixQuoted(path, prefix, vch);
  
  // Remove the pesky /** ending
  String fixedPath = path.substr(0, path.length() - 3);
  
  // Expand the path and get an absolute project path
  String expandedPath = vch.expand(fixedPath);
  String projectPath = vch.getValue("PROJECT_DIR");
  
  // Make an absolute path
  String absPath = joinPaths(projectPath, expandedPath);
  
  // Get a list of subdirectories to ignore
  StringVec ignoreList;
  vch.getValue("EXCLUDED_RECURSIVE_SEARCH_PATH_SUBDIRECTORIES", ignoreList);

  // Get recursive paths
  StringVec dirVec;
  getRecursiveDirList(absPath, dirVec, ignoreList);
  
  // Sort the paths such that they are in breadth-first, alphabetic order
  std::sort(dirVec.begin(), dirVec.end(), compare_nocase_breadth_first);

  // Substitute back the original form of the path (which likely contains variables)
  String ret;
  for (unsigned i = 0; i < dirVec.size(); i++) {
    dirVec[i].replace(0, absPath.length(), fixedPath);
    ret += addPrefixQuoted(dirVec[i], prefix, vch);
  }

  // Check that the recursive expansion succeeded
  if (dirVec.empty()) {
    SBLog::info() << "Failed recursive expansion of \"" << absPath << "\". Path does not exist." << std::endl;
    return "";
  } else { 
    return ret;
  }
}

static String expandUserHeaderPath(const String& path, const String& prefix, const VariableCollectionHierarchy& vch)
{
  String searchUserPaths = vch.getValue("ALWAYS_SEARCH_USER_PATHS");
  if (searchUserPaths == "YES")
    return expandRecursivePath(path, "-I", vch);
  else
    return expandRecursivePath(path, prefix, vch);
}

static String modifyCXXStandard(const String& val, const String& prefix, const VariableCollectionHierarchy& vch)
{
  return prefix + sb_replace(val, "++0x", "++11", -1);
}

static String overrideDeploymentTarget(const String& val, const String& prefix, const VariableCollectionHierarchy& vch)
{
  // Fix IPHONEOS_DEPLOYMENT_TARGET for really old projects
  String fixedVal = atof(val.c_str()) < 4.3 ? "4.3" : val;
  return addPrefixQuoted(fixedVal, prefix, vch);
}

static String overrideCxxLibrary(const String& val, const String& prefix, const VariableCollectionHierarchy& vch)
{
  // We only support libc++
  return addPrefixQuoted("libc++", prefix, vch);
}

static SettingDesc _settings[] = {
// Common variables
  {"CLANG_ENABLE_OBJC_ARC", "NO", BoolValue, new ParamDesc("-fobjc-arc", "-fno-objc-arc"), UniversalSetting},
  {"GCC_UNROLL_LOOPS", "NO", BoolValue, new ParamDesc("-funroll-loops", ""), UniversalSetting},
  {"DEAD_CODE_STRIPPING", "YES", BoolValue, new ParamDesc("-dead_strip", ""), UniversalSetting},
  {"GCC_STRICT_ALIASING", "YES", BoolValue, new ParamDesc("-fstrict-aliasing", "-fno-strict-aliasing"), UniversalSetting},
  {"GCC_DYNAMIC_NO_PIC", "NO", BoolValue, new ParamDesc("-mdynamic-no-pic", ""), UniversalSetting},
  {"GCC_REUSE_STRINGS", "YES", BoolValue, new ParamDesc("-fwritable-strings", ""), UniversalSetting},
  {"LINK_WITH_STANDARD_LIBRARIES", "NO", BoolValue, new ParamDesc("", "-nostdlib"), UniversalSetting}, // Starboard Default
  {"LD_NO_PIE", "NO", BoolValue, new ParamDesc("-no_pie", ""), UniversalSetting},
  {"ALWAYS_SEARCH_USER_PATHS", "YES", BoolValue, NULL, UniversalSetting},
  {"USE_HEADERMAP", "YES", BoolValue, NULL, UniversalSetting},
  {"HEADERMAP_INCLUDES_FLAT_ENTRIES_FOR_TARGET_BEING_BUILT", "YES", BoolValue, NULL, UniversalSetting},
  {"HEADERMAP_INCLUDES_FRAMEWORK_ENTRIES_FOR_ALL_PRODUCT_TYPES", "YES", BoolValue, NULL, UniversalSetting},
  {"HEADERMAP_INCLUDES_PROJECT_HEADERS", "YES", BoolValue, NULL, UniversalSetting},
  {"GCC_OPTIMIZATION_LEVEL", "s", StringValue, new ParamDesc("-O", NULL, &addPrefixQuoted), UniversalSetting},
  {"INFOPLIST_FILE", "Info.plist", PathValue, NULL, UniversalSetting},
  {"GCC_PREFIX_HEADER", "", PathValue, new ParamDesc("-include ", NULL, &addPrefixQuoted), UniversalSetting},
  {"GCC_PREPROCESSOR_DEFINITIONS", "", StringListValue, new ParamDesc("-D", NULL, &addPrefixQuoted), UniversalSetting},
  {"IPHONEOS_DEPLOYMENT_TARGET", "5.0", StringValue, new ParamDesc("-miphoneos-version-min=", NULL, &overrideDeploymentTarget), UniversalSetting},
  {"SDKROOT", "", PathValue, new ParamDesc("-isysroot ", NULL, &addPrefixQuoted), UniversalSetting},
  {"TARGET_SDKVERSION", "5.0", StringValue, NULL, UniversalSetting},
  {"GCC_C_LANGUAGE_STANDARD", "", StringValue, new ParamDesc("-std=", NULL, &addPrefixQuoted), UniversalSetting},
  {"CLANG_CXX_LANGUAGE_STANDARD", "", StringValue, new ParamDesc("-std=", NULL, &modifyCXXStandard), UniversalSetting},
  {"CLANG_CXX_LIBRARY", "libc++", StringValue, new ParamDesc("-stdlib=", NULL, &addPrefixQuoted), UniversalSetting},
  {"HEADER_SEARCH_PATHS", "", PathListValue, new ParamDesc("-I", NULL, &expandRecursivePath), UniversalSetting},
  {"USER_HEADER_SEARCH_PATHS", "", PathListValue, new ParamDesc("-iquote", NULL, &expandUserHeaderPath), UniversalSetting},
  {"FRAMEWORK_SEARCH_PATHS", "", PathListValue, new ParamDesc("-F", NULL, &expandRecursivePath), UniversalSetting},
  {"LIBRARY_SEARCH_PATHS", "", PathListValue, new ParamDesc("-L", NULL, &expandRecursivePath), UniversalSetting},
  {"OTHER_LDFLAGS", "", StringListValue, NULL, UniversalSetting},
  {"OTHER_CFLAGS", "", StringListValue, NULL, UniversalSetting},
  {"WARNING_CFLAGS", "", StringListValue, NULL, UniversalSetting},
  {"WARNING_LDFLAGS", "", StringListValue, NULL, UniversalSetting},
  {"OTHER_CPLUSPLUSFLAGS", "${OTHER_CFLAGS}", StringListValue, NULL, UniversalSetting},
  {"CURRENT_ARCH", "", StringValue, new ParamDesc("-arch ", NULL, &addPrefixQuoted), UniversalSetting},
  {"ARCHS_STANDARD", "armv6", StringListValue, NULL, UniversalSetting}, // Strarboard Default
  {"ARCHS", "armv6", StringListValue, NULL, UniversalSetting}, // Starboard Default
  {"ARCHS_STANDARD_32_BIT", "armv6", StringListValue, NULL, UniversalSetting}, // Starboard Default
  {"ARCHS_STANDARD_INCLUDING_64_BIT", "armv6", StringListValue, NULL, UniversalSetting}, // Strarboard Default
  {"PLATFORM_NAME", "iphoneos", StringValue, NULL, UniversalSetting},
  {"SYMROOT", "sbuild", PathValue, NULL, UniversalSetting},
  {"OBJROOT", "${SYMROOT}", PathValue, NULL, UniversalSetting},
  {"BUILT_PRODUCTS_DIR", "${CONFIGURATION_BUILD_DIR}", PathValue, NULL, UniversalSetting},
  {"CONFIGURATION_BUILD_DIR", "${BUILD_DIR}/${CONFIGURATION}${EFFECTIVE_PLATFORM_NAME}", PathValue, NULL, UniversalSetting},
  {"BUILD_DIR", "${SYMROOT}", PathValue, NULL, UniversalSetting},
  {"EFFECTIVE_PLATFORM_NAME", "-iphoneos", StringValue, NULL, UniversalSetting},
  {"SOURCE_ROOT", "${SRCROOT}", PathValue, NULL, UniversalSetting},
  {"SRCROOT", "${PROJECT_DIR}", PathValue, NULL, UniversalSetting},
  {"PROJECT", "${PROJECT_NAME}", PathValue, NULL, UniversalSetting},
  {"TARGETNAME", "${TARGET_NAME}", StringValue, NULL, UniversalSetting},
  {"TARGET_BUILD_DIR", "${CONFIGURATION_BUILD_DIR}", PathValue, NULL, UniversalSetting},
  {"CONFIGURATION_TEMP_DIR", "${PROJECT_TEMP_DIR}/${CONFIGURATION}${EFFECTIVE_PLATFORM_NAME}", PathValue, NULL, UniversalSetting},
  {"PROJECT_TEMP_DIR", "${PROJECT_TEMP_ROOT}/${PROJECT_NAME}.sbuild", PathValue, NULL, UniversalSetting},
  {"PROJECT_TEMP_ROOT", "${OBJROOT}", PathValue, NULL, UniversalSetting},
  {"DERIVED_FILES_DIR", "${DERIVED_FILE_DIR}", PathValue, NULL, UniversalSetting},
  {"DERIVED_FILE_DIR", "${TEMP_DIR}/DerivedSources", PathValue, NULL, UniversalSetting},
  {"TEMP_DIR", "${TARGET_TEMP_DIR}", PathValue, NULL, UniversalSetting},
  {"TARGET_TEMP_DIR", "${CONFIGURATION_TEMP_DIR}/${TARGET_NAME}.sbuild", PathValue, NULL, UniversalSetting},
  {"DERIVED_SOURCES_DIR", "${DERIVED_FILE_DIR}", PathValue, NULL, UniversalSetting},
  {"OBJECT_FILE_DIR", "$(TEMP_DIR)/Objects/${CURRENT_ARCH}", PathValue, NULL, UniversalSetting},
  {"EXCLUDED_RECURSIVE_SEARCH_PATH_SUBDIRECTORIES", "*.nib *.lproj *.framework *.gch (*) .DS_Store CVS .svn .git .hg *.xcodeproj *.xcode *.pbproj *.pbxproj", StringListValue, NULL, UniversalSetting},
  {"LINK_FILE_LIST", "${OBJECT_FILE_DIR}/${TARGET_NAME}.LinkFileList", PathValue, NULL, UniversalSetting},
  {"ASSETCATALOG_COMPILER_APPICON_NAME", "", StringValue, NULL, UniversalSetting},
  {"ASSETCATALOG_COMPILER_LAUNCHIMAGE_NAME", "", StringValue, NULL, UniversalSetting},
  {"TARGET_SDKVERSION", "5.0", StringValue, NULL, UniversalSetting},
// Platform-specific
#if defined(_MSC_VER)
  {"USER", "${USERNAME}", StringValue, NULL, UniversalSetting},
#endif
// VS Importer variables
  {"VSIMPORTER_OUTPUT_DIR", "${PROJECT_FILE_PATH:dir}/${PROJECT_NAME}.vsimporter", PathValue, NULL, UniversalSetting},
  {"VSIMPORTER_TEMPLATES_DIR", "${WINOBJC_SDK_ROOT}/msvc/vsimporter-templates", PathValue, NULL, UniversalSetting},
// Application variables
  {"CODESIGNING_FOLDER_PATH", "${CONFIGURATION_BUILD_DIR}/${FULL_PRODUCT_NAME}", PathValue, NULL, AppSetting},
  {"PUBLIC_HEADERS_FOLDER_PATH", "${EXECUTABLE_FOLDER_PATH}/Public", PathValue, NULL, AppSetting},
  {"PRIVATE_HEADERS_FOLDER_PATH", "${EXECUTABLE_FOLDER_PATH}/Private", PathValue, NULL, AppSetting},
  {"EXECUTABLE_PATH", "${EXECUTABLE_FOLDER_PATH}/${EXECUTABLE_NAME}", PathValue, NULL, AppSetting},
  {"UNLOCALIZED_RESOURCES_FOLDER_PATH", "${FULL_PRODUCT_NAME}", PathValue, NULL, AppSetting},
  {"LOCALIZED_RESOURCES_FOLDER_PATH", "${UNLOCALIZED_RESOURCES_FOLDER_PATH}/English.lproj", PathValue, NULL, AppSetting},
  {"APPFOLDER", "${CODESIGNING_FOLDER_PATH}", PathValue, NULL, AppSetting},
  {"INFOPLIST_PATH", "${EXECUTABLE_FOLDER_PATH}/Info.plist", PathValue, NULL, AppSetting},
// Static library variables
  {"PUBLIC_HEADERS_FOLDER_PATH", "/usr/local/include", PathValue, NULL, StaticLibSetting},
  {"PRIVATE_HEADERS_FOLDER_PATH", "/usr/local/include", PathValue, NULL, StaticLibSetting}
};

void getDefaultSettingValues(VariableCollection& vc, ProductMask mask)
{
  for (unsigned i = 0; i < sizeof(_settings) / sizeof(SettingDesc); i++) {
    if (_settings[i].mask == mask)
      vc.insert(_settings[i].name, _settings[i].defaultValue);
  }
}

typedef std::map<String, const SettingDesc*> SettingDescMap;

const SettingDesc& getSettingDescription(const String& name)
{
  static SettingDescMap settingDesc;

  if (settingDesc.empty()) {
    for (unsigned i = 0; i < sizeof(_settings) / sizeof(SettingDesc); i++) {
      settingDesc[_settings[i].name] = &_settings[i];
    }
  }

  SettingDescMap::iterator it = settingDesc.find(name);
  if (it != settingDesc.end()) {
    return *it->second;
  } else {
    static SettingDesc defaultDesc = {"", "", StringValue, NULL, UniversalSetting};
    return defaultDesc;
  }
}
