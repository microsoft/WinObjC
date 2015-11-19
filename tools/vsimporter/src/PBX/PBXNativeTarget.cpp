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

#include "PlistFuncs.h"
#include "utils.h"
#include "PBXNativeTarget.h"
#include "PBXFileReference.h"
#include "PBXBuildRule.h"
#include "PBXObjectIdConvert.h"
#include "VariableCollection.h"

PBXNativeTarget::~PBXNativeTarget() {}

PBXNativeTarget::PBXNativeTarget() {}

PBXNativeTarget* PBXNativeTarget::createFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc)
{
  PBXNativeTarget* ret = new PBXNativeTarget;
  ret->initFromPlist(id, plist, pbxDoc);
  return ret;
}

void PBXNativeTarget::initFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc)
{
  // Call super init
  PBXTarget::initFromPlist(id, plist, pbxDoc);

  // Get productReference
  getStringForKey(plist, "productReference", m_productReferenceId, VALUE_REQUIRED, m_parseER);
  
  // Get productType
  getStringForKey(plist, "productType", m_productType, VALUE_REQUIRED, m_parseER);
  
  // Get buildRules
  getStringVectorForKey(plist, "buildRules", m_buildRuleIds, VALUE_OPTIONAL, m_parseER);
}

void PBXNativeTarget::resolvePointers()
{
  // Call super resolve
  PBXTarget::resolvePointers();
  
  // Resolve productReference ptr
  convertObjectId(m_pbxDoc, m_productReferenceId, m_productReferencePtr);
  
  // Resolve buildRules ptrs
  convertObjectIdList(m_pbxDoc, m_buildRuleIds, m_buildRulePtrs);
}

String PBXNativeTarget::getProductFileName() const
{
  if (m_productReferencePtr)
    return m_productReferencePtr->getFullPath();
  else
    return "";
}

String PBXNativeTarget::getProductFileType() const
{
  if (m_productReferencePtr)
    return m_productReferencePtr->getFileType();
  else
    return "";
}

void PBXNativeTarget::getBuildSettings(VariableCollection& settings) const
{
  PBXTarget::getBuildSettings(settings);

  String productFileType = getProductFileType();
  String productPath = getProductFileName();
  String productNameFull = sb_basename(productPath);
  String productName = sb_fname(productNameFull);

  if (m_productType == "com.apple.product-type.library.static") {
    if (productFileType != "archive.ar")
      SBLog::warning() << "Unexpected product file type \"" << productFileType << "\" for \"" << getName() << "\" static lib target." << std::endl;

    settings.insert("EXECUTABLE_NAME", productNameFull);
    settings.insert("EXECUTABLE_PATH", productNameFull);
  } else if (m_productType == "com.apple.product-type.application") {
    // Fix up product name, when necessary
    if (productFileType == "compiled.mach-o.executable")
      productNameFull = productName + ".app";
    else if (productFileType != "wrapper.application")
      SBLog::warning() << "Unexpected product file type \"" << productFileType << "\" for \"" << getName() << "\" app target." << std::endl;

    settings.insert("EXECUTABLE_NAME", productName);
    settings.insert("EXECUTABLE_FOLDER_PATH", productNameFull);
  } else if (m_productType == "com.apple.product-type.bundle") {
    if (productFileType != "wrapper.cfbundle") {
      SBLog::warning() << "Unexpected product file type \"" << productFileType << "\" for \"" << getName() << "\" bundle target." << std::endl;
    }

    settings.insert("EXECUTABLE_NAME", productName);
    settings.insert("EXECUTABLE_FOLDER_PATH", productNameFull);
  }

  settings.insert("PRODUCT_NAME", productName);
  settings.insert("FULL_PRODUCT_NAME", productNameFull);
  settings.insert("PRODUCT_TYPE", m_productType);
}
