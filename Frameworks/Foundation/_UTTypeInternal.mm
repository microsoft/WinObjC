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

#import <StubReturn.h>
#import <ErrorHandling.h>
#import <UTTypeInternal.h>
#import <dispatch/dispatch.h>
#import <ErrorHandling.h>
#import <array>
#import <vector>

#pragma region internalMapHelpers

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

typedef struct {
    CFStringRef utiName;
    std::vector<CFStringRef> fileNameExtensions;
    std::vector<CFStringRef> mimeTypes;
} SystemUTIMapEntry;

static CFMutableDictionaryRef s_systemUTIMap;
static CFMutableDictionaryRef s_fileExtensionToSystemUTIMap;
static CFMutableDictionaryRef s_mimeTypeToSystemUTIMap;

typedef std::array<SystemUTIMapEntry, 39> SystemUTIMapEntryArray;

/**
 * Returns a static system UTI map.
 */
SystemUTIMapEntryArray& _UTGetSytemUTIMapping() {
    // clang-format off
    static SystemUTIMapEntryArray map {{
        // {
        //  UTI name
        //  File extension list
        //  MIME type list
        // }
        {
            kUTTypePlainText,
            {static_cast<const CFStringRef>(@"txt")},
            {static_cast<const CFStringRef>(@"text/plain")}
        },
        {
            kUTTypeRTF,
            {static_cast<const CFStringRef>(@"rtf")},
            {static_cast<const CFStringRef>(@"text/rtf")}
        },
        {
            kUTTypeHTML,
            {static_cast<const CFStringRef>(@"html"), static_cast<const CFStringRef>(@"htm")},
            {static_cast<const CFStringRef>(@"text/html")}
        },
        {
            kUTTypeXML,
            {static_cast<const CFStringRef>(@"xml")},
            {static_cast<const CFStringRef>(@"text/xml")}
        },
        {
            static_cast<const CFStringRef>(@"com.netscape.javascript-​source"),
            {static_cast<const CFStringRef>(@"js"), static_cast<const CFStringRef>(@"jscript"), static_cast<const CFStringRef>(@"javascript")},
            {static_cast<const CFStringRef>(@"text/javascript")}
        },
        {
            static_cast<const CFStringRef>(@"public.perl-script"),
            {static_cast<const CFStringRef>(@"pl"), static_cast<const CFStringRef>(@"pm")},
            {static_cast<const CFStringRef>(@"text/x-perl-script")}
        },
        {
            static_cast<const CFStringRef>(@"public.python-script"),
            {static_cast<const CFStringRef>(@"py")},
            {static_cast<const CFStringRef>(@"text/x-python-script")}
        },
        {
            static_cast<const CFStringRef>(@"public.ruby-script"),
            {static_cast<const CFStringRef>(@"rb"), static_cast<const CFStringRef>(@"rbw")},
            {static_cast<const CFStringRef>(@"text/ruby-script")}
        },
        {
            static_cast<const CFStringRef>(@"public.php-script"),
            {static_cast<const CFStringRef>(@"php"), static_cast<const CFStringRef>(@"php3"), static_cast<const CFStringRef>(@"php4"), static_cast<const CFStringRef>(@"ph3"), static_cast<const CFStringRef>(@"ph4"), static_cast<const CFStringRef>(@"phtml")},
            {static_cast<const CFStringRef>(@"text/x-php-script"), static_cast<const CFStringRef>(@"text/php"), static_cast<const CFStringRef>(@"application/php")}
        },
        {
            static_cast<const CFStringRef>(@"com.sun.java-web-start"),
            {static_cast<const CFStringRef>(@"jnlp")},
            {static_cast<const CFStringRef>(@"application/x-java"), static_cast<const CFStringRef>(@"application/jnlp")}
        },
        {
            static_cast<const CFStringRef>(@"com.microsoft.windows-​executable"),
            {static_cast<const CFStringRef>(@"exe")},
            {static_cast<const CFStringRef>(@"application/x-msdownload")}
        },
        {
            static_cast<const CFStringRef>(@"com.microsoft.windows-​dynamic-link-library"),
            {static_cast<const CFStringRef>(@"dll")},
            {static_cast<const CFStringRef>(@"application/x-msdownload")}
        },
        {
            static_cast<const CFStringRef>(@"com.sun.java-archive"),
            {static_cast<const CFStringRef>(@"jar")},
            {static_cast<const CFStringRef>(@"application/java-archive")}
        },
        {
            static_cast<const CFStringRef>(@"com.apple.quartz-​composer-composition"),
            {static_cast<const CFStringRef>(@"qtz")},
            {static_cast<const CFStringRef>(@"application/x-quartzcomposer")}
        },
        {
            static_cast<const CFStringRef>(@"org.gnu.gnu-tar-archive"),
            {static_cast<const CFStringRef>(@"gtar")},
            {static_cast<const CFStringRef>(@"application/x-gtar")}
        },
        {
            static_cast<const CFStringRef>(@"public.tar-archive"),
            {static_cast<const CFStringRef>(@"tar")},
            {static_cast<const CFStringRef>(@"application/x-tar"), static_cast<const CFStringRef>(@"application/tar")}
        },
        {
            static_cast<const CFStringRef>(@"org.gnu.gnu-zip-archive"),
            {static_cast<const CFStringRef>(@"gz"), static_cast<const CFStringRef>(@"gzip")},
            {static_cast<const CFStringRef>(@"application/x-gzip"), static_cast<const CFStringRef>(@"application/gzip")}
        },
        {
            static_cast<const CFStringRef>(@"com.apple.binhex-archive"),
            {static_cast<const CFStringRef>(@"hqx")},
            {static_cast<const CFStringRef>(@"application/mac-binhex40"), static_cast<const CFStringRef>(@"application/mac-binhex"), static_cast<const CFStringRef>(@"application/binhex")}
        },
        {
            static_cast<const CFStringRef>(@"com.apple.macbinary-​archive"),
            {static_cast<const CFStringRef>(@"bin")},
            {static_cast<const CFStringRef>(@"application/x-macbinary"), static_cast<const CFStringRef>(@"application/macbinary")}
        },
        {
            kUTTypeVCard,
            {static_cast<const CFStringRef>(@"vcf"), static_cast<const CFStringRef>(@"vcard")},
            {static_cast<const CFStringRef>(@"text/x-vcard"), static_cast<const CFStringRef>(@"text/directory"), static_cast<const CFStringRef>(@"text/vcard")}
        },
        {
            kUTTypeJPEG,
            {static_cast<const CFStringRef>(@"jpg"), static_cast<const CFStringRef>(@"jpeg")},
            {static_cast<const CFStringRef>(@"image/jpeg")}
        },
        {
            kUTTypeJPEG2000,
            {static_cast<const CFStringRef>(@"jp2")},
            {static_cast<const CFStringRef>(@"image/jp2")}
        },
        {
            kUTTypeTIFF,
            {static_cast<const CFStringRef>(@"tif"), static_cast<const CFStringRef>(@"tiff")},
            {static_cast<const CFStringRef>(@"image/tiff")}
        },
        {
            kUTTypePICT,
            {static_cast<const CFStringRef>(@"pic"), static_cast<const CFStringRef>(@"pct"), static_cast<const CFStringRef>(@"pict")},
            {static_cast<const CFStringRef>(@"image/pict"), static_cast<const CFStringRef>(@"image/x-pict"), static_cast<const CFStringRef>(@"image/x-macpict")}
        },
        {
            kUTTypePNG,
            {static_cast<const CFStringRef>(@"png")},
            {static_cast<const CFStringRef>(@"image/png")}
        },
        {
            static_cast<const CFStringRef>(@"public.xbitmap-image"),
            {static_cast<const CFStringRef>(@"xbm")},
            {static_cast<const CFStringRef>(@"image/x-quicktime")}
        },
        {
            kUTTypeQuickTimeImage,
            {static_cast<const CFStringRef>(@"qif"), static_cast<const CFStringRef>(@"qtif")},
            {static_cast<const CFStringRef>(@"image/x-quicktime")}
        },
        {
            kUTTypeQuickTimeMovie,
            {static_cast<const CFStringRef>(@"mov"), static_cast<const CFStringRef>(@"qt")},
            {static_cast<const CFStringRef>(@"video/quicktime")}
        },
        {
            static_cast<const CFStringRef>(@"public.avi"),
            {static_cast<const CFStringRef>(@"avi"), static_cast<const CFStringRef>(@"vfw")},
            {static_cast<const CFStringRef>(@"video/avi"), static_cast<const CFStringRef>(@"video/msvideo"), static_cast<const CFStringRef>(@"video/x-msvideo")}
        },
        {
            kUTTypeMPEG,
            {static_cast<const CFStringRef>(@"mpg"), static_cast<const CFStringRef>(@"mpeg"), static_cast<const CFStringRef>(@"m75"), static_cast<const CFStringRef>(@"m15")},
            {static_cast<const CFStringRef>(@"video/mpg"), static_cast<const CFStringRef>(@"video/mpeg"), static_cast<const CFStringRef>(@"video/x-mpg"), static_cast<const CFStringRef>(@"video/x-mpeg")}
        },
        {
            kUTTypeMPEG4,
            {static_cast<const CFStringRef>(@"mp4")},
            {static_cast<const CFStringRef>(@"video/mp4"), static_cast<const CFStringRef>(@"video/mp4v")}
        },
        {
            static_cast<const CFStringRef>(@"public.3gpp"),
            {static_cast<const CFStringRef>(@"3gp"), static_cast<const CFStringRef>(@"3gpp")},
            {static_cast<const CFStringRef>(@"video/3gpp"), static_cast<const CFStringRef>(@"audio/3gpp")}
        },
        {
            static_cast<const CFStringRef>(@"public.3gpp2"),
            {static_cast<const CFStringRef>(@"3g2"), static_cast<const CFStringRef>(@"3gp2")},
            {static_cast<const CFStringRef>(@"video/3gpp2"), static_cast<const CFStringRef>(@"audio/3gpp2")}
        },
        {
            kUTTypeMP3,
            {static_cast<const CFStringRef>(@"mp3")},
            {static_cast<const CFStringRef>(@"audio/x-mpeg"), static_cast<const CFStringRef>(@"audio/mpeg"), static_cast<const CFStringRef>(@"audio/mpeg3"), static_cast<const CFStringRef>(@"audio/mpg"), static_cast<const CFStringRef>(@"audio/x-mpeg3"), static_cast<const CFStringRef>(@"audio/x-mpg"), static_cast<const CFStringRef>(@"audio/x-mp3")}
        },
        {
            static_cast<const CFStringRef>(@"public.ulaw-audio"),
            {static_cast<const CFStringRef>(@"au"), static_cast<const CFStringRef>(@"ulw"), static_cast<const CFStringRef>(@"snd")},
            {static_cast<const CFStringRef>(@"audio/basic"), static_cast<const CFStringRef>(@"audio/au"), static_cast<const CFStringRef>(@"audio/snd")}
        },
        {
            static_cast<const CFStringRef>(@"public.aifc-audio"),
            {static_cast<const CFStringRef>(@"aifc"), static_cast<const CFStringRef>(@"aiff"), static_cast<const CFStringRef>(@"aif")},
            {static_cast<const CFStringRef>(@"audio/x-aiff"), static_cast<const CFStringRef>(@"audio/aiff")}
        },
        {
            static_cast<const CFStringRef>(@"public.aiff-audio"),
            {static_cast<const CFStringRef>(@"aiff"), static_cast<const CFStringRef>(@"aif")},
            {static_cast<const CFStringRef>(@"audio/x-aiff"), static_cast<const CFStringRef>(@"audio/aiff")}
        },
        {
            static_cast<const CFStringRef>(@"com.pkware.zip-archive"),
            {static_cast<const CFStringRef>(@"zip")},
            {static_cast<const CFStringRef>(@"application/zip")}
        },
        {
            static_cast<const CFStringRef>(@"public.x509-certificate"),
            {static_cast<const CFStringRef>(@"cer")},
            {static_cast<const CFStringRef>(@"application/x-x509-ca-cert")}
        },
    } };
    // clang-format on

    return map;
}

static dispatch_once_t onceToken;

/**
 * Initializes the system UTI map.
 */
void _UTInitializeSystemUTIMaps() {
    dispatch_once(&onceToken, ^{
        s_systemUTIMap = CFDictionaryCreateMutable(kCFAllocatorDefault, 0, &kCFTypeDictionaryKeyCallBacks, NULL);
        s_fileExtensionToSystemUTIMap = CFDictionaryCreateMutable(kCFAllocatorDefault, 0, &kCFTypeDictionaryKeyCallBacks, NULL);
        s_mimeTypeToSystemUTIMap = CFDictionaryCreateMutable(kCFAllocatorDefault, 0, &kCFTypeDictionaryKeyCallBacks, NULL);

        auto& map = _UTGetSytemUTIMapping();
        uint32_t count = 0;
        for (const SystemUTIMapEntry& entry : map) {
            // Add the UTI entry to s_systemUTIMap
            //  Key: UTI (CFStringRef)
            //  Value: SystemUTIMapEntry (struct)
            if (!CFDictionaryContainsKey(s_systemUTIMap, (const void*)entry.utiName)) {
                CFDictionaryAddValue(s_systemUTIMap, (const void*)entry.utiName, (const void*)&map[count++]);
            } else {
                assert(0);
                LOG_HR_MSG(E_FAIL, "Key (%s) collition detected in s_systemUTIMap!", [static_cast<NSString*>(entry.utiName) UTF8String]);
            }

            // Add each file name extension to the s_fileExtensionToSystemUTIMap
            //  Key: File Name Extension (CFStringRef)
            //  Value: CFMutableArray of UTI strings (CFMutableArrayRef)
            for (const auto& fileNameExtension : entry.fileNameExtensions) {
                if (!CFDictionaryContainsKey(s_fileExtensionToSystemUTIMap, (const void*)fileNameExtension)) {
                    CFMutableArrayRef systemUTIArray = CFArrayCreateMutable(kCFAllocatorDefault, 0, &kCFTypeArrayCallBacks);
                    CFArrayAppendValue(systemUTIArray, (const void*)entry.utiName);
                    CFDictionaryAddValue(s_fileExtensionToSystemUTIMap, (const void*)fileNameExtension, (const void*)systemUTIArray);
                } else {
                    CFMutableArrayRef systemUTIArray = static_cast<CFMutableArrayRef>(
                        const_cast<void*>(CFDictionaryGetValue(s_fileExtensionToSystemUTIMap, (const void*)fileNameExtension)));
                    CFArrayAppendValue(systemUTIArray, (const void*)entry.utiName);
                    CFDictionarySetValue(s_fileExtensionToSystemUTIMap, (const void*)fileNameExtension, (const void*)systemUTIArray);
                }
            }

            // Add each mime type to the s_mimeTypeToSystemUTIMap
            //  Key: Mime Type (CFStringRef)
            //  Value: CFMutableArray of UTI strings (CFMutableArrayRef)
            for (const auto& mimeType : entry.mimeTypes) {
                if (!CFDictionaryContainsKey(s_mimeTypeToSystemUTIMap, (const void*)mimeType)) {
                    CFMutableArrayRef systemUTIArray = CFArrayCreateMutable(kCFAllocatorDefault, 0, &kCFTypeArrayCallBacks);
                    CFArrayAppendValue(systemUTIArray, (const void*)entry.utiName);
                    CFDictionaryAddValue(s_mimeTypeToSystemUTIMap, (const void*)mimeType, (const void*)systemUTIArray);
                } else {
                    CFMutableArrayRef systemUTIArray = static_cast<CFMutableArrayRef>(
                        const_cast<void*>(CFDictionaryGetValue(s_mimeTypeToSystemUTIMap, (const void*)mimeType)));
                    CFArrayAppendValue(systemUTIArray, (const void*)entry.utiName);
                    CFDictionarySetValue(s_mimeTypeToSystemUTIMap, (const void*)mimeType, (const void*)systemUTIArray);
                }
            }
        }
    });
}

/**
 * Retrieves the UTI for the given file name extension.
 * @param fileNameExtension file name extension
 * @return UTI
 */
CFArrayRef _UTGetUTIsForFileNameExtension(CFStringRef fileNameExtension) {
    if (fileNameExtension == NULL) {
        return NULL;
    }

    CFArrayRef UTIs =
        static_cast<CFArrayRef>(const_cast<void*>(CFDictionaryGetValue(s_fileExtensionToSystemUTIMap, (const void*)fileNameExtension)));
    return UTIs ? CFArrayCreateCopy(kCFAllocatorDefault, UTIs) : NULL;
}

/**
 * Retrieves the UTI for the given MIME type.
 * @param mimeType MIME type
 * @return UTI
 */
CFArrayRef _UTGetUTIsForMIMEType(CFStringRef mimeType) {
    CFArrayRef UTIs = static_cast<CFArrayRef>(const_cast<void*>(CFDictionaryGetValue(s_mimeTypeToSystemUTIMap, (const void*)mimeType)));
    return CFArrayCreateCopy(kCFAllocatorDefault, UTIs);
}

/**
 * Retrieves the first file extension associated with the given UTI.
 * @param UTI UTI string
 * @return file name extension associated with the UTI
 */
CFStringRef _UTGetFileNameExtensionForUTI(CFStringRef UTI) {
    SystemUTIMapEntry* entry = static_cast<SystemUTIMapEntry*>(const_cast<void*>(CFDictionaryGetValue(s_systemUTIMap, (const void*)UTI)));
    if (entry != nullptr) {
        return entry->fileNameExtensions[0];
    }

    return NULL;
}

/**
 * Retrieves the first MIME type associated with the given UTI.
 * @param UTI UTI string
 * @return MIME type associated with the UTI
 */
CFStringRef _UTGetMimeTypeForUTI(CFStringRef UTI) {
    SystemUTIMapEntry* entry = static_cast<SystemUTIMapEntry*>(const_cast<void*>(CFDictionaryGetValue(s_systemUTIMap, (const void*)UTI)));
    if (entry != nullptr) {
        return entry->mimeTypes[0];
    }

    return NULL;
}

#pragma endregion internalMapHelpers

#pragma region directFunctionalInteropMethods
/**
 @Status Caveat
 @Notes Only a subset of System UTIs are supported and inConformingToUTI is option not supported.
*/
CFStringRef _UTTypeCreatePreferredIdentifierForTag(CFStringRef inTagClass, CFStringRef inTag, CFStringRef inConformingToUTI) {
    RETURN_NULL_IF(!inTagClass);
    RETURN_NULL_IF(!inTag);

    // Initialize System UTI.
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
CFArrayRef _UTTypeCreateAllIdentifiersForTag(CFStringRef inTagClass, CFStringRef inTag, CFStringRef inConformingToUTI) {
    RETURN_NULL_IF(!inTagClass);
    RETURN_NULL_IF(!inTag);

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
CFStringRef _UTTypeCopyPreferredTagWithClass(CFStringRef inUTI, CFStringRef inTagClass) {
    RETURN_NULL_IF(!inUTI);
    RETURN_NULL_IF(!inTagClass);

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
Boolean _UTTypeEqual(CFStringRef inUTI1, CFStringRef inUTI2) {
    // Initialize MobileCoreServices System UTI.
    _UTInitializeSystemUTIMaps();

    CFComparisonResult result = CFStringCompare(inUTI1, inUTI2, 0);
    return (result == kCFCompareEqualTo) ? true : false;
}

/**
 @Status Caveat
 @Notes UTI conformance logic is not supported.
*/
Boolean _UTTypeConformsTo(CFStringRef inUTI, CFStringRef inConformsToUTI) {
    // Initialize MobileCoreServices System UTI.
    _UTInitializeSystemUTIMaps();

    if (_UTTypeEqual(inUTI, inConformsToUTI)) {
        return true;
    } else {
        UNIMPLEMENTED_WITH_MSG("UTI conformance check is not implemented! Checking %s conformance to %s.",
                               [static_cast<NSString*>(inUTI) UTF8String],
                               [static_cast<NSString*>(inConformsToUTI) UTF8String]);
        return false;
    }
}

#pragma endregion directFunctionalInteropMethods