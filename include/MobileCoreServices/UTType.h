//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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
#pragma once

#include <MobileCoreServices/MobileCoreServicesExport.h>
#include <CoreFoundation/CFString.h>
#include <CoreFoundation/CFArray.h>
#include <CoreFoundation/CFDictionary.h>
#include <CoreFoundation/CFURL.h>

MOBILECORESERVICES_EXPORT CFStringRef UTTypeCreatePreferredIdentifierForTag(CFStringRef inTagClass,
                                                                            CFStringRef inTag,
                                                                            CFStringRef inConformingToUTI);
MOBILECORESERVICES_EXPORT CFArrayRef UTTypeCreateAllIdentifiersForTag(CFStringRef inTagClass,
                                                                      CFStringRef inTag,
                                                                      CFStringRef inConformingToUTI);
MOBILECORESERVICES_EXPORT CFStringRef UTTypeCopyPreferredTagWithClass(CFStringRef inUTI, CFStringRef inTagClass);
MOBILECORESERVICES_EXPORT Boolean UTTypeEqual(CFStringRef inUTI1, CFStringRef inUTI2);
MOBILECORESERVICES_EXPORT Boolean UTTypeConformsTo(CFStringRef inUTI, CFStringRef inConformsToUTI);
MOBILECORESERVICES_EXPORT CFStringRef UTTypeCopyDescription(CFStringRef inUTI) STUB_METHOD;
MOBILECORESERVICES_EXPORT CFDictionaryRef UTTypeCopyDeclaration(CFStringRef inUTI) STUB_METHOD;
MOBILECORESERVICES_EXPORT CFURLRef UTTypeCopyDeclaringBundleURL(CFStringRef inUTI) STUB_METHOD;

MOBILECORESERVICES_EXPORT const CFStringRef kUTExportedTypeDeclarationsKey;
MOBILECORESERVICES_EXPORT const CFStringRef kUTImportedTypeDeclarationsKey;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeIdentifierKey;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeTagSpecificationKey;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeConformsToKey;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeDescriptionKey;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeIconFileKey;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeReferenceURLKey;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeVersionKey;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTagClassFilenameExtension;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTagClassMIMEType;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeItem;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeContent;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeCompositeContent;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeApplication;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeMessage;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeContact;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeArchive;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeDiskImage;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeData;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeDirectory;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeResolvable;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeSymLink;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeMountPoint;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeAliasFile;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeAliasRecord;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeURL;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeFileURL;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeText;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypePlainText;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeUTF8PlainText;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeUTF16ExternalPlainText;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeUTF16PlainText;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeRTF;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeHTML;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeXML;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeSourceCode;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeCSource;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeObjectiveCSource;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeCPlusPlusSource;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeObjectiveCPlusPlusSource;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeCHeader;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeCPlusPlusHeader;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeJavaSource;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypePDF;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeRTFD;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeFlatRTFD;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeTXNTextAndMultimediaData;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeWebArchive;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeImage;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeJPEG;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeJPEG2000;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeTIFF;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypePICT;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeGIF;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypePNG;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeQuickTimeImage;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeAppleICNS;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeBMP;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeICO;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeAudiovisualContent;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeMovie;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeVideo;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeAudio;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeQuickTimeMovie;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeMPEG;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeMPEG4;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeMP3;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeMPEG4Audio;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeAppleProtectedMPEG4Audio;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeFolder;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeVolume;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypePackage;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeBundle;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeFramework;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeApplicationBundle;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeApplicationFile;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeVCard;
MOBILECORESERVICES_EXPORT const CFStringRef kUTTypeInkText;
