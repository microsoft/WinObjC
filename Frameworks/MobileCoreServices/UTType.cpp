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

#include <MobileCoreServices/MobileCoreServices.h>
#include <Starboard/SmartTypes.h>
#include <UTTypeInternal.h>
#include <ErrorHandling.h>
#include <StubReturn.h>

// Type Declaration Dictionary Keys
const CFStringRef kUTExportedTypeDeclarationsKey = CFSTR("UTExportedTypeDeclarations");
const CFStringRef kUTImportedTypeDeclarationsKey = CFSTR("UTImportedTypeDeclarations");
const CFStringRef kUTTypeIdentifierKey = CFSTR("UTTypeIdentifierKey");
const CFStringRef kUTTypeTagSpecificationKey = CFSTR("UTTypeTagSpecificationKey");
const CFStringRef kUTTypeConformsToKey = CFSTR("UTTypeConformsToKey");
const CFStringRef kUTTypeDescriptionKey = CFSTR("UTTypeDescriptionKey");
const CFStringRef kUTTypeIconFileKey = CFSTR("UTTypeIconFileKey");
const CFStringRef kUTTypeReferenceURLKey = CFSTR("UTTypeReferenceURLKey");
const CFStringRef kUTTypeVersionKey = CFSTR("UTTypeVersionKey");

// Type Tag Classes
const CFStringRef kUTTagClassFilenameExtension = CFSTR("public.filename-extension");
const CFStringRef kUTTagClassMIMEType = CFSTR("public.mime-type");

// UTI Abstract Types
const CFStringRef kUTTypeItem = CFSTR("public.item");
const CFStringRef kUTTypeContent = CFSTR("public.content");
const CFStringRef kUTTypeCompositeContent = CFSTR("public.composite-content");
const CFStringRef kUTTypeApplication = CFSTR("com.apple.application");
const CFStringRef kUTTypeMessage = CFSTR("public.message");
const CFStringRef kUTTypeContact = CFSTR("public.contact");
const CFStringRef kUTTypeArchive = CFSTR("public.archive");
const CFStringRef kUTTypeDiskImage = CFSTR("public.disk-image");

// UTI Concrete Types
const CFStringRef kUTTypeData = CFSTR("public.data");
const CFStringRef kUTTypeDirectory = CFSTR("public.directory");
const CFStringRef kUTTypeResolvable = CFSTR("com.apple.resolvable");
const CFStringRef kUTTypeSymLink = CFSTR("public.symlink");
const CFStringRef kUTTypeMountPoint = CFSTR("com.apple.mount-point");
const CFStringRef kUTTypeAliasFile = CFSTR("com.apple.alias-file");
const CFStringRef kUTTypeAliasRecord = CFSTR("com.apple.alias-record");
const CFStringRef kUTTypeURL = CFSTR("public.url");
const CFStringRef kUTTypeFileURL = CFSTR("public.file-url");

// UTI Text Types
const CFStringRef kUTTypeText = CFSTR("public.text");
const CFStringRef kUTTypePlainText = CFSTR("public.plain-text");
const CFStringRef kUTTypeUTF8PlainText = CFSTR("public.utf8-plain-text");
const CFStringRef kUTTypeUTF16ExternalPlainText = CFSTR("public.utf16-external-plain-text");
const CFStringRef kUTTypeUTF16PlainText = CFSTR("public.utf16-plain-text");
const CFStringRef kUTTypeRTF = CFSTR("public.rtf");
const CFStringRef kUTTypeHTML = CFSTR("public.html");
const CFStringRef kUTTypeXML = CFSTR("public.xml");
const CFStringRef kUTTypeSourceCode = CFSTR("public.source-code");
const CFStringRef kUTTypeCSource = CFSTR("public.c-source");
const CFStringRef kUTTypeObjectiveCSource = CFSTR("public.objective-c-source");
const CFStringRef kUTTypeCPlusPlusSource = CFSTR("public.c-plus-plus-source");
const CFStringRef kUTTypeObjectiveCPlusPlusSource = CFSTR("public.objective-c-plus-plus-source");
const CFStringRef kUTTypeCHeader = CFSTR("public.c-header");
const CFStringRef kUTTypeCPlusPlusHeader = CFSTR("public.c-plus-plus-header");
const CFStringRef kUTTypeJavaSource = CFSTR("public.java-source");

// UTI Composite Content Types
const CFStringRef kUTTypePDF = CFSTR("com.adobe.pdf");
const CFStringRef kUTTypeRTFD = CFSTR("com.apple.rtfd");
const CFStringRef kUTTypeFlatRTFD = CFSTR("com.apple.flat-rtfd");
const CFStringRef kUTTypeTXNTextAndMultimediaData = CFSTR("com.apple.txn.text-multimedia-data");
const CFStringRef kUTTypeWebArchive = CFSTR("com.apple.webarchive");

// UTI Image Content Types
const CFStringRef kUTTypeImage = CFSTR("public.image");
const CFStringRef kUTTypeJPEG = CFSTR("public.jpeg");
const CFStringRef kUTTypeJPEG2000 = CFSTR("public.jpeg-2000");
const CFStringRef kUTTypeTIFF = CFSTR("public.tiff");
const CFStringRef kUTTypePICT = CFSTR("com.apple.pict");
const CFStringRef kUTTypeGIF = CFSTR("com.compuserve.gif");
const CFStringRef kUTTypePNG = CFSTR("public.png");
const CFStringRef kUTTypeQuickTimeImage = CFSTR("com.apple.quicktime-image");
const CFStringRef kUTTypeAppleICNS = CFSTR("com.apple.icns");
const CFStringRef kUTTypeBMP = CFSTR("com.microsoft.bmp");
const CFStringRef kUTTypeICO = CFSTR("com.microsoft.ico");

// UTI Audio Visual Content Types
const CFStringRef kUTTypeAudiovisualContent = CFSTR("public.audiovisual-content");
const CFStringRef kUTTypeMovie = CFSTR("public.movie");
const CFStringRef kUTTypeVideo = CFSTR("public.video");
const CFStringRef kUTTypeAudio = CFSTR("public.audio");
const CFStringRef kUTTypeQuickTimeMovie = CFSTR("com.apple.quicktime-movie");
const CFStringRef kUTTypeMPEG = CFSTR("public.mpeg");
const CFStringRef kUTTypeMPEG4 = CFSTR("public.mpeg-4");
const CFStringRef kUTTypeMP3 = CFSTR("public.mp");
const CFStringRef kUTTypeMPEG4Audio = CFSTR("public.mpeg-4-audio");
const CFStringRef kUTTypeAppleProtectedMPEG4Audio = CFSTR("com.apple.protected-mpeg-4-audio");

// UTI Directory Types
const CFStringRef kUTTypeFolder = CFSTR("public.folder");
const CFStringRef kUTTypeVolume = CFSTR("public.volume");
const CFStringRef kUTTypePackage = CFSTR("com.apple.package");
const CFStringRef kUTTypeBundle = CFSTR("com.apple.bundle");
const CFStringRef kUTTypeFramework = CFSTR("com.apple.framework");

// UTI Miscellaneous Types
const CFStringRef kUTTypeApplicationBundle = CFSTR("com.apple.application-bundle");
const CFStringRef kUTTypeApplicationFile = CFSTR("com.apple.application-file");
const CFStringRef kUTTypeVCard = CFSTR("public.vcard");
const CFStringRef kUTTypeInkText = CFSTR("com.apple.ink.inktext");

static inline CFStringRef _CFStringRetain(CFStringRef cfString) {
    CFRetain(cfString);
    return cfString;
}

/**
 @Status Caveat
 @Notes Only a subset of System UTIs are supported and inConformingToUTI is option not supported.
*/
CFStringRef UTTypeCreatePreferredIdentifierForTag(CFStringRef inTagClass, CFStringRef inTag, CFStringRef inConformingToUTI) {
    RETURN_NULL_IF(!inTagClass);
    RETURN_NULL_IF(!inTag);

    // Initialize System UTI.
    _UTInitializeSystemUTIMaps();

    if (inConformingToUTI != NULL) {
        UNIMPLEMENTED_WITH_MSG("inConformingToUTI (%s) is not currently supported for UTTypeCreatePreferredIdentifierForTag",
                               CFStringGetCStringPtr(inConformingToUTI, kCFStringEncodingUTF8));
    }

    CFComparisonResult result;

    result = CFStringCompare(inTagClass, kUTTagClassFilenameExtension, 0);
    if (result == kCFCompareEqualTo) {
        woc::unique_cf<CFArrayRef> fileNameExtensions{ _UTCreateUTIsForFileNameExtension(inTag) };
        return _CFStringRetain(static_cast<CFStringRef>(CFArrayGetValueAtIndex(fileNameExtensions.get(), 0)));
    }

    result = CFStringCompare(inTagClass, kUTTagClassMIMEType, 0);
    if (result == kCFCompareEqualTo) {
        woc::unique_cf<CFArrayRef> mimeTypes{ _UTCreateUTIsForMIMEType(inTag) };
        return _CFStringRetain(static_cast<CFStringRef>(CFArrayGetValueAtIndex(mimeTypes.get(), 0)));
    }

    return NULL;
}

/**
 @Status Caveat
 @Notes Only a subset of System UTIs are supported and inConformingToUTI is option not supported.
*/
CFArrayRef UTTypeCreateAllIdentifiersForTag(CFStringRef inTagClass, CFStringRef inTag, CFStringRef inConformingToUTI) {
    RETURN_NULL_IF(!inTagClass);
    RETURN_NULL_IF(!inTag);

    // Initialize MobileCoreServices System UTI.
    _UTInitializeSystemUTIMaps();

    if (inConformingToUTI != NULL) {
        UNIMPLEMENTED_WITH_MSG("inConformingToUTI (%s) is not currently supported for UTTypeCreatePreferredIdentifierForTag",
                               CFStringGetCStringPtr(inConformingToUTI, kCFStringEncodingUTF8));
    }

    CFComparisonResult result;

    result = CFStringCompare(inTagClass, kUTTagClassFilenameExtension, 0);
    if (result == kCFCompareEqualTo) {
        return _UTCreateUTIsForFileNameExtension(inTag);
    }

    result = CFStringCompare(inTagClass, kUTTagClassMIMEType, 0);
    if (result == kCFCompareEqualTo) {
        return _UTCreateUTIsForMIMEType(inTag);
    }

    return NULL;
}

/**
 @Status Caveat
 @Notes Only a subset of System UTIs are supported.
*/
CFStringRef UTTypeCopyPreferredTagWithClass(CFStringRef inUTI, CFStringRef inTagClass) {
    RETURN_NULL_IF(!inUTI);
    RETURN_NULL_IF(!inTagClass);

    // Initialize MobileCoreServices System UTI.
    _UTInitializeSystemUTIMaps();

    CFComparisonResult result;

    result = CFStringCompare(inTagClass, kUTTagClassMIMEType, 0);
    if (result == kCFCompareEqualTo) {
        return _UTCopyMimeTypeForUTI(inUTI);
    }

    result = CFStringCompare(inTagClass, kUTTagClassFilenameExtension, 0);
    if (result == kCFCompareEqualTo) {
        return _UTCopyFileNameExtensionForUTI(inUTI);
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
                               CFStringGetCStringPtr(inUTI, kCFStringEncodingUTF8),
                               CFStringGetCStringPtr(inConformsToUTI, kCFStringEncodingUTF8));
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
