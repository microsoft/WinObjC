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
#include "SBLog.h"
#include "PBXNativeTarget.h"
#include "BuildSettings.h"
#include "SBProject.h"
#include "SBNativeTarget.h"
#include "VCProject.h"
#include "VCProjectItem.h"

SBNativeTarget::~SBNativeTarget() {}

SBNativeTarget::SBNativeTarget(const PBXNativeTarget* target, const StringSet& configNames, SBProject& parentProject)
  : SBTarget(target, configNames, parentProject),
    m_target(target)
{}

SBNativeTarget* SBNativeTarget::create(const PBXTarget* target, const StringSet& configNames, SBProject& parentProject)
{
  SBNativeTarget* ret = new SBNativeTarget(dynamic_cast<const PBXNativeTarget*>(target), configNames, parentProject);
  if (!ret->init()) {
    delete ret;
    ret = NULL;
  }
  
  return ret;
}

bool SBNativeTarget::init()
{
  // Verify that target's build type is valid
  String productType = m_target->getProductType();
  if (productType == "com.apple.product-type.library.static") {
    m_type = TargetStaticLib;
  } else if (productType == "com.apple.product-type.framework") {
    m_type = TargetStaticLib;
    SBLog::warning() << "Treating \"" << getName() << "\" framework target as a static library. This is experimental behaviour." << std::endl;
  } else if (productType == "com.apple.product-type.application") {
    m_type = TargetApplication;
  } else if (productType == "com.apple.product-type.bundle") {
    m_type = TargetBundle;
  } else {
    SBLog::warning() << "Ignoring \"" << getName() << "\" target with unsupported product type \"" << productType << "\"." << std::endl;
    return false;
  }

  // Check if any custom build rules are defined
  const BuildRuleList& buildRules = m_target->getBuildRules();
  if (!buildRules.empty()) {
    SBLog::warning() << "Ignoring custom build rules for \"" << getName() << "\" target." << std::endl;
  }

  // Call super init
  return SBTarget::init();
}

class XCConfigPrinter : public VarPrintFunc {
public:
  virtual ~XCConfigPrinter() {}
  XCConfigPrinter(OFStream& out) : m_ofs(out) {}
  void print(const String& varName, const String& varValue) const {
    if (!strBeginsWith(varName, "VSIMPORTER")) {
      m_ofs << varName << " = " << trim(varValue) << std::endl;
    }
  }
private:
  OFStream& m_ofs;
};

VCProject* SBNativeTarget::constructVCProject(VSTemplateProject* projTemplate)
{
  VCProject* proj = SBTarget::constructVCProject(projTemplate);
  String vsProjDir = sb_dirname(proj->getPath());

  // Write variables file for App targets
  for (auto bs : m_buildSettings) {
    if (getProductType() == TargetApplication || getProductType() == TargetBundle) {
      String configName = bs.first;
      BuildSettings* configBS = bs.second;

      // Figure out where the file should go
      String varsFilePath = joinPaths(vsProjDir, getName() + "-" + configName + "-xcvars.txt");

      // Open a file stream to write to
      OFStream varsOut;
      openOutputFileStream(varsOut, varsFilePath);

      // Write the build settings out
      XCConfigPrinter varsPrinter(varsOut);
      configBS->print(varsPrinter);

      // Add the variables file to the project
      VCProjectItem* xcvarsFile = addRelativeFilePathToVS("Text", varsFilePath, "Xcode Variable Files", *proj, *configBS);

      // Mark the file as non-deployable
      xcvarsFile->setDefinition("DeploymentContent", "false");
    }
  }

  return proj;
}