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

#import <MobileCoreServices/MobileCoreServices.h>
#import <StubReturn.h>
#import <ErrorHandling.h>
#import <UTTypeInternalMap.h>

// Type Declaration Dictionary Keys
const CFStringRef kUTExportedTypeDeclarationsKey = static_cast<const CFStringRef>(@"UTExportedTypeDeclarations");
const CFStringRef kUTImportedTypeDeclarationsKey = static_cast<const CFStringRef>(@"UTImportedTypeDeclarations");
const CFStringRef kUTTypeIdentifierKey = static_cast<const CFStringRef>(@"UTTypeIdentifierKey");
const CFStringRef kUTTypeTagSpecificationKey = static_cast<const CFStringRef>(@"UTTypeTagSpecificationKey");
const CFStringRef kUTTypeConformsToKey = static_cast<const CFStringRef>(@"UTTypeConformsToKey");
const CFStringRef kUTTypeDescriptionKey = static_cast<const CFStringRef>(@"UTTypeDescriptionKey");
const CFStringRef kUTTypeIconFileKey = static_cast<const CFStringRef>(@"UTTypeIconFileKey");
const CFStringRef kUTTypeReferenceURLKey = static_cast<const CFStringRef>(@"UTTypeReferenceURLKey");
const CFStringRef kUTTypeVersionKey = static_cast<const CFStringRef>(@"UTTypeVersionKey");

// Type Tag Classes
const CFStringRef kUTTagClassFilenameExtension = static_cast<const CFStringRef>(@"public.filename-extension");
const CFStringRef kUTTagClassMIMEType = static_cast<const CFStringRef>(@"public.mime-type");

// UTI Abstract Types
const CFStringRef kUTTypeItem = static_cast<const CFStringRef>(@"public.item");
const CFStringRef kUTTypeContent = static_cast<const CFStringRef>(@"public.content");
const CFStringRef kUTTypeCompositeContent = static_cast<const CFStringRef>(@"public.composite-content");
const CFStringRef kUTTypeApplication = static_cast<const CFStringRef>(@"com.apple.application");
const CFStringRef kUTTypeMessage = static_cast<const CFStringRef>(@"public.message");
const CFStringRef kUTTypeContact = static_cast<const CFStringRef>(@"public.contact");
const CFStringRef kUTTypeArchive = static_cast<const CFStringRef>(@"public.archive");
const CFStringRef kUTTypeDiskImage = static_cast<const CFStringRef>(@"public.disk-image");

// UTI Concrete Types
const CFStringRef kUTTypeData = static_cast<const CFStringRef>(@"public.data");
const CFStringRef kUTTypeDirectory = static_cast<const CFStringRef>(@"public.directory");
const CFStringRef kUTTypeResolvable = static_cast<const CFStringRef>(@"com.apple.resolvable");
const CFStringRef kUTTypeSymLink = static_cast<const CFStringRef>(@"public.symlink");
const CFStringRef kUTTypeMountPoint = static_cast<const CFStringRef>(@"com.apple.mount-point");
const CFStringRef kUTTypeAliasFile = static_cast<const CFStringRef>(@"com.apple.alias-file");
const CFStringRef kUTTypeAliasRecord = static_cast<const CFStringRef>(@"com.apple.alias-record");
const CFStringRef kUTTypeURL = static_cast<const CFStringRef>(@"public.url");
const CFStringRef kUTTypeFileURL = static_cast<const CFStringRef>(@"public.file-url");

// UTI Text Types
const CFStringRef kUTTypeText = static_cast<const CFStringRef>(@"public.text");
const CFStringRef kUTTypePlainText = static_cast<const CFStringRef>(@"public.plain-text");
const CFStringRef kUTTypeUTF8PlainText = static_cast<const CFStringRef>(@"public.utf8-plain-text");
const CFStringRef kUTTypeUTF16ExternalPlainText = static_cast<const CFStringRef>(@"public.utf16-external-plain-text");
const CFStringRef kUTTypeUTF16PlainText = static_cast<const CFStringRef>(@"public.utf16-plain-text");
const CFStringRef kUTTypeRTF = static_cast<const CFStringRef>(@"public.rtf");
const CFStringRef kUTTypeHTML = static_cast<const CFStringRef>(@"public.html");
const CFStringRef kUTTypeXML = static_cast<const CFStringRef>(@"public.xml");
const CFStringRef kUTTypeSourceCode = static_cast<const CFStringRef>(@"public.source-code");
const CFStringRef kUTTypeCSource = static_cast<const CFStringRef>(@"public.c-source");
const CFStringRef kUTTypeObjectiveCSource = static_cast<const CFStringRef>(@"public.objective-c-source");
const CFStringRef kUTTypeCPlusPlusSource = static_cast<const CFStringRef>(@"public.c-plus-plus-source");
const CFStringRef kUTTypeObjectiveCPlusPlusSource = static_cast<const CFStringRef>(@"public.objective-c-plus-plus-source");
const CFStringRef kUTTypeCHeader = static_cast<const CFStringRef>(@"public.c-header");
const CFStringRef kUTTypeCPlusPlusHeader = static_cast<const CFStringRef>(@"public.c-plus-plus-header");
const CFStringRef kUTTypeJavaSource = static_cast<const CFStringRef>(@"public.java-source");

// UTI Composite Content Types
const CFStringRef kUTTypePDF = static_cast<const CFStringRef>(@"com.adobe.pdf");
const CFStringRef kUTTypeRTFD = static_cast<const CFStringRef>(@"com.apple.rtfd");
const CFStringRef kUTTypeFlatRTFD = static_cast<const CFStringRef>(@"com.apple.flat-rtfd");
const CFStringRef kUTTypeTXNTextAndMultimediaData = static_cast<const CFStringRef>(@"com.apple.txn.text-multimedia-data");
const CFStringRef kUTTypeWebArchive = static_cast<const CFStringRef>(@"com.apple.webarchive");

// UTI Image Content Types
const CFStringRef kUTTypeImage = static_cast<const CFStringRef>(@"public.image");
const CFStringRef kUTTypeJPEG = static_cast<const CFStringRef>(@"public.jpeg");
const CFStringRef kUTTypeJPEG2000 = static_cast<const CFStringRef>(@"public.jpeg-2000");
const CFStringRef kUTTypeTIFF = static_cast<const CFStringRef>(@"public.tiff");
const CFStringRef kUTTypePICT = static_cast<const CFStringRef>(@"com.apple.pict");
const CFStringRef kUTTypeGIF = static_cast<const CFStringRef>(@"com.compuserve.gif");
const CFStringRef kUTTypePNG = static_cast<const CFStringRef>(@"public.png");
const CFStringRef kUTTypeQuickTimeImage = static_cast<const CFStringRef>(@"com.apple.quicktime-image");
const CFStringRef kUTTypeAppleICNS = static_cast<const CFStringRef>(@"com.apple.icns");
const CFStringRef kUTTypeBMP = static_cast<const CFStringRef>(@"com.microsoft.bmp");
const CFStringRef kUTTypeICO = static_cast<const CFStringRef>(@"com.microsoft.ico");

// UTI Audio Visual Content Types
const CFStringRef kUTTypeAudiovisualContent = static_cast<const CFStringRef>(@"public.audiovisual-content");
const CFStringRef kUTTypeMovie = static_cast<const CFStringRef>(@"public.movie");
const CFStringRef kUTTypeVideo = static_cast<const CFStringRef>(@"public.video");
const CFStringRef kUTTypeAudio = static_cast<const CFStringRef>(@"public.audio");
const CFStringRef kUTTypeQuickTimeMovie = static_cast<const CFStringRef>(@"com.apple.quicktime-movie");
const CFStringRef kUTTypeMPEG = static_cast<const CFStringRef>(@"public.mpeg");
const CFStringRef kUTTypeMPEG4 = static_cast<const CFStringRef>(@"public.mpeg-4");
const CFStringRef kUTTypeMP3 = static_cast<const CFStringRef>(@"public.mp");
const CFStringRef kUTTypeMPEG4Audio = static_cast<const CFStringRef>(@"public.mpeg-4-audio");
const CFStringRef kUTTypeAppleProtectedMPEG4Audio = static_cast<const CFStringRef>(@"com.apple.protected-mpeg-4-audio");

// UTI Directory Types
const CFStringRef kUTTypeFolder = static_cast<const CFStringRef>(@"public.folder");
const CFStringRef kUTTypeVolume = static_cast<const CFStringRef>(@"public.volume");
const CFStringRef kUTTypePackage = static_cast<const CFStringRef>(@"com.apple.package");
const CFStringRef kUTTypeBundle = static_cast<const CFStringRef>(@"com.apple.bundle");
const CFStringRef kUTTypeFramework = static_cast<const CFStringRef>(@"com.apple.framework");

// UTI Miscellaneous Types
const CFStringRef kUTTypeApplicationBundle = static_cast<const CFStringRef>(@"com.apple.application-bundle");
const CFStringRef kUTTypeApplicationFile = static_cast<const CFStringRef>(@"com.apple.application-file");
const CFStringRef kUTTypeVCard = static_cast<const CFStringRef>(@"public.vcard");
const CFStringRef kUTTypeInkText = static_cast<const CFStringRef>(@"com.apple.ink.inktext");

/**
 @Status Caveat
 @Notes Only a subset of System UTIs are supported and inConformingToUTI is option not supported.
*/
CFStringRef UTTypeCreatePreferredIdentifierForTag(CFStringRef inTagClass, CFStringRef inTag, CFStringRef inConformingToUTI) {
    // Initialize MobileCoreServices System UTI.
    _UTInitializeSystemUTIMaps();

    if (inConformingToUTI != NULL) {
        UNIMPLEMENTED_WITH_MSG("inConformingToUTI (%s) is not currently supported for UTTypeCreatePreferredIdentifierForTag",
                               [static_cast<NSString*>(inConformingToUTI) UTF8String]);
    }

    CFComparisonResult result;

    result = CFStringCompare(inTagClass, kUTTagClassFilenameExtension, 0);
    if (result == kCFCompareEqualTo) {
        CFArrayRef fileNameExtensions = _UTGetUTIsForFileNameExtension(inTag);
        return fileNameExtensions ? static_cast<CFStringRef>(CFArrayGetValueAtIndex(fileNameExtensions, 0)) : NULL;
    }

    result = CFStringCompare(inTagClass, kUTTagClassMIMEType, 0);
    if (result == kCFCompareEqualTo) {
        CFArrayRef mimeTypes = _UTGetUTIsForMIMEType(inTag);
        return static_cast<CFStringRef>(CFArrayGetValueAtIndex(mimeTypes, 0));
    }

    return NULL;
}

/**
 @Status Caveat
 @Notes Only a subset of System UTIs are supported and inConformingToUTI is option not supported.
*/
CFArrayRef UTTypeCreateAllIdentifiersForTag(CFStringRef inTagClass, CFStringRef inTag, CFStringRef inConformingToUTI) {
    // Initialize MobileCoreServices System UTI.
    _UTInitializeSystemUTIMaps();

    if (inConformingToUTI != NULL) {
        UNIMPLEMENTED_WITH_MSG("inConformingToUTI (%s) is not currently supported for UTTypeCreatePreferredIdentifierForTag",
                               [static_cast<NSString*>(inConformingToUTI) UTF8String]);
    }

    CFComparisonResult result;

    result = CFStringCompare(inTagClass, kUTTagClassFilenameExtension, 0);
    if (result == kCFCompareEqualTo) {
        return _UTGetUTIsForFileNameExtension(inTag);
    }

    result = CFStringCompare(inTagClass, kUTTagClassMIMEType, 0);
    if (result == kCFCompareEqualTo) {
        return _UTGetUTIsForMIMEType(inTag);
    }

    return NULL;
}

/**
 @Status Caveat
 @Notes Only a subset of System UTIs are supported.
*/
CFStringRef UTTypeCopyPreferredTagWithClass(CFStringRef inUTI, CFStringRef inTagClass) {
    // Initialize MobileCoreServices System UTI.
    _UTInitializeSystemUTIMaps();

    CFComparisonResult result;

    result = CFStringCompare(inTagClass, kUTTagClassMIMEType, 0);
    if (result == kCFCompareEqualTo) {
        return _UTGetMimeTypeForUTI(inUTI);
    }

    result = CFStringCompare(inTagClass, kUTTagClassFilenameExtension, 0);
    if (result == kCFCompareEqualTo) {
        return _UTGetFileNameExtensionForUTI(inUTI);
    }

    return NULL;
}

/**
 @Status Caveat
 @Notes UTI conformance logic is not supported.
*/
Boolean UTTypeEqual(CFStringRef inUTI1, CFStringRef inUTI2) {
    // Initialize MobileCoreServices System UTI.
    _UTInitializeSystemUTIMaps();

    CFComparisonResult result = CFStringCompare(inUTI1, inUTI2, 0);
    return (result == kCFCompareEqualTo) ? true : false;
}

/**
 @Status Caveat
 @Notes UTI conformance logic is not supported.
*/
Boolean UTTypeConformsTo(CFStringRef inUTI, CFStringRef inConformsToUTI) {
    // Initialize MobileCoreServices System UTI.
    _UTInitializeSystemUTIMaps();

    if (UTTypeEqual(inUTI, inConformsToUTI)) {
        return true;
    } else {
        UNIMPLEMENTED_WITH_MSG("UTI conformance check is not implemented! Checking %s conformance to %s.",
                               [static_cast<NSString*>(inUTI) UTF8String],
                               [static_cast<NSString*>(inConformsToUTI) UTF8String]);
        return false;
    }
}

/**
 @Status Stub
 @Notes
*/
CFStringRef UTTypeCopyDescription(CFStringRef inUTI) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFDictionaryRef UTTypeCopyDeclaration(CFStringRef inUTI) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFURLRef UTTypeCopyDeclaringBundleURL(CFStringRef inUTI) {
    UNIMPLEMENTED();
    return StubReturn();
}
