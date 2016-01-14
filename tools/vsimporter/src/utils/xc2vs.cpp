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
#include "xc2vs.h"
#include "clangoptparser.h"
#include "PBXVariantGroup.h"
#include "PBXBuildFile.h"
#include "BuildSettings.h"
#include "VCProject.h"
#include "VCProjectItem.h"

static String getVSItemType(const String& xcodeType)
{
  if (xcodeType == "sourcecode.c.c" || xcodeType == "sourcecode.cpp.cpp")
    return "ClangCompile";
  else if (xcodeType == "sourcecode.c.objc" || xcodeType == "sourcecode.cpp.objcpp")
    return "ClangCompile";
  else if (xcodeType == "sourcecode.c.h" || xcodeType == "sourcecode.cpp.h")
    return "ClInclude";
  else if (xcodeType == "file.xib")
    return "XibCompile";
  else if (xcodeType == "file.storyboard")
    return "StoryboardCompile";
  else if (xcodeType == "wrapper.xcdatamodel" || xcodeType == "wrapper.xcdatamodeld")
    return "DataModelCompile";
  else if (xcodeType == "folder.assetcatalog")
    return "AssetCatalogCompile";
  else
    return "Unknown";
}

static String getVSCompileAsType(const String& xcodeType)
{
  if (xcodeType == "sourcecode.c.c")
    return "CompileAsObjC";   // Force C to compile as ObjC to avoid #import problems
  else if (xcodeType == "sourcecode.cpp.cpp")
    return "CompileAsObjCpp"; // Force C++ to compile as ObjC++ to avoid #import problems
  else if (xcodeType == "sourcecode.c.objc")
    return "CompileAsObjC";
  else if (xcodeType == "sourcecode.cpp.objcpp")
    return "CompileAsObjCpp";
  else
    return "";
}

static VCProjectItem* addFileToVSInternal(const PBXFile* file, VCProject& proj, const BuildSettings& bs, bool isVariant, const VCItemHint* itemHint)
{
  // Add all children of any PBXVariantGroup
  const PBXVariantGroup* variantGroup = dynamic_cast<const PBXVariantGroup*>(file);
  if (variantGroup) {
    const ConstFileList& children = variantGroup->getChildren();
    for (auto child : children) {
      addFileToVSInternal(child, proj, bs, true, itemHint);
    }
    return NULL;
  }

  // Get the real and virtual paths for the file in Xcode
  String realPath = file->getFullPath();
  String virtualPath = file->getVirtualPath();

  // Fix up virtual path for variant files
  // Resources/MainStoryboard.storyboard/en => Resources/en/MainStoryboard.storyboard
  if (isVariant) {
    String variantLang = sb_basename(virtualPath);
    String filePath = sb_dirname(virtualPath);
    String fixedDir = joinPaths(sb_dirname(filePath), variantLang);
    virtualPath = joinPaths(fixedDir, sb_basename(filePath));
  }

  // Compute the VS ItemType for the file
  String fileType = file->getFileType();
  String vsType = getVSItemType(fileType);
  if (vsType == "Unknown") {
    if (itemHint && !itemHint->defaultType.empty()) {
      vsType = itemHint->defaultType;
    }
  }

  // Add the item to the project, taking into account path overrides
  VCProjectItem* item = NULL;
  if (itemHint && !itemHint->pathOverride.empty()) {
    sbAssert(!isVariant, "Unexpected path override for variant file: " + realPath);
    item = proj.addItem(vsType, itemHint->pathOverride, sb_dirname(virtualPath));
  } else {
    item = addRelativeFilePathToVS(vsType, realPath, sb_dirname(virtualPath), proj, bs);
  }

  // Handle Variant files
  if (isVariant) {
    String variantDir = sb_basename(sb_dirname(realPath));
    item->setDefinition("VariantDir", variantDir);
  }

  return item;
}

void addFileToVS(const PBXFile* file, VCProject& proj, const BuildSettings& bs, const VCItemHint* itemHint)
{
  addFileToVSInternal(file, proj, bs, false, itemHint);
}

VCProjectItem* addRelativeFilePathToVS(const String& itemName, const String& filePath, const String& filterPath, VCProject& proj, const BuildSettings& bs)
{
  // Get relative path to file
  String xcProjectDir = bs.getValue("PROJECT_DIR");
  String vsProjectDir = sb_dirname(proj.getPath());
  String absFilePath = joinPaths(xcProjectDir, bs.expand(filePath));
  String relPath = getRelativePath(vsProjectDir, absFilePath);
  relPath = winPath(relPath);
  return proj.addItem(itemName, relPath, filterPath);
}

void addBuildFileToVS(const PBXBuildFile* buildFile, VCProject& proj, const BuildSettings& bs, const VCItemHint* itemHint)
{
  const String& compilerFlags = buildFile->getCompilerFlags();
  int attribs = buildFile->getAttributes();
  const PBXFile* file = buildFile->getFile();
  if (!file)
    return;

  VCProjectItem* item = addFileToVSInternal(file, proj, bs, false, itemHint);

  // If the filetype doesn't match the file extension, specify the actual type
  String filePath = file->getFullPath();
  String fileType = file->getFileType();
  String inferredType = PBXFile::getFileType(filePath);
  String compileAs = getVSCompileAsType(fileType);
  if (item && !compileAs.empty() &&
       (fileType != inferredType || fileType == "sourcecode.c.c" || fileType == "sourcecode.cpp.cpp")) {
    item->setDefinition("CompileAs", compileAs);
  }

  // Record file compiler flags
  if (item && !compilerFlags.empty()) {
    String fixedFlags = "$(AdditionalOptions) " + compilerFlags;
    String xcProjectDir = bs.getValue("PROJECT_DIR");
    String vsProjectDir = sb_dirname(proj.getPath());
    processClangFlags(fixedFlags, xcProjectDir, vsProjectDir);
    item->setDefinition("AdditionalOptions", fixedFlags);
  }

  // Ignore attributes
  if (attribs)
    SBLog::warning() << "Ignoring attributes for \"" << filePath << "\" file." << std::endl;
}