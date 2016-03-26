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

#import <MobileCoreServices/UTType.h>
#import <UTTypeInternalMap.h>
#import <dispatch/dispatch.h>
#import <ErrorHandling.h>
#import <array>
#import <vector>

typedef struct {
    CFStringRef utiName;
    std::vector<CFStringRef> fileNameExtensions;
    std::vector<CFStringRef> mimeTypes;
} SystemUTIMapEntry;

static CFMutableDictionaryRef s_systemUTIMap;
static CFMutableDictionaryRef s_fileExtensionToSystemUTIMap;
static CFMutableDictionaryRef s_mimeTypeToSystemUTIMap;

typedef std::array<SystemUTIMapEntry, 38> SystemUTIMapEntryArray;

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
            {CFSTR(".txt")},
            {CFSTR("text/plain")}
        },
        {
            kUTTypeRTF,
            {CFSTR(".rtf")},
            {CFSTR("text/rtf")}
        },
        {
            kUTTypeHTML,
            {CFSTR(".html"), CFSTR(".htm")},
            {CFSTR("text/html")}
        },
        {
            kUTTypeXML,
            {CFSTR(".xml")},
            {CFSTR("text/xml")}
        },
        {
            CFSTR("com.netscape.javascript-​source"),
            {CFSTR(".js"), CFSTR(".jscript"), CFSTR(".javascript")},
            {CFSTR("text/javascript")}
        },
        {
            CFSTR("public.perl-script"),
            {CFSTR(".pl"), CFSTR(".pm")},
            {CFSTR("text/x-perl-script")}
        },
        {
            CFSTR("public.python-script"),
            {CFSTR(".py")},
            {CFSTR("text/x-python-script")}
        },
        {
            CFSTR("public.ruby-script"),
            {CFSTR(".rb"), CFSTR(".rbw")},
            {CFSTR("text/ruby-script")}
        },
        {
            CFSTR("public.php-script"),
            {CFSTR(".php"), CFSTR(".php3"), CFSTR(".php4"), CFSTR(".ph3"), CFSTR(".ph4"), CFSTR(".phtml")},
            {CFSTR("text/x-php-script"), CFSTR("text/php"), CFSTR("application/php")}
        },
        {
            CFSTR("com.sun.java-web-start"),
            {CFSTR(".jnlp")},
            {CFSTR("application/x-java"), CFSTR("application/jnlp")}
        },
        {
            CFSTR("com.microsoft.windows-​executable"),
            {CFSTR(".exe")},
            {CFSTR("application/x-msdownload")}
        },
        {
            CFSTR("com.microsoft.windows-​dynamic-link-library"),
            {CFSTR(".dll")},
            {CFSTR("application/x-msdownload")}
        },
        {
            CFSTR("com.sun.java-archive"),
            {CFSTR(".jar")},
            {CFSTR("application/java-archive")}
        },
        {
            CFSTR("com.apple.quartz-​composer-composition"),
            {CFSTR(".qtz")},
            {CFSTR("application/x-quartzcomposer")}
        },
        {
            CFSTR("org.gnu.gnu-tar-archive"),
            {CFSTR(".gtar")},
            {CFSTR("application/x-gtar")}
        },
        {
            CFSTR("public.tar-archive"),
            {CFSTR(".tar")},
            {CFSTR("application/x-tar"), CFSTR("application/tar")}
        },
        {
            CFSTR("org.gnu.gnu-zip-archive"),
            {CFSTR(".gz"), CFSTR(".gzip")},
            {CFSTR("application/x-gzip"), CFSTR("application/gzip")}
        },
        {
            CFSTR("com.apple.binhex-archive"),
            {CFSTR(".hqx")},
            {CFSTR("application/mac-binhex40"), CFSTR("application/mac-binhex"), CFSTR("application/binhex")}
        },
        {
            CFSTR("com.apple.macbinary-​archive"),
            {CFSTR(".bin")},
            {CFSTR("application/x-macbinary"), CFSTR("application/macbinary")}
        },
        {
            kUTTypeVCard,
            {CFSTR(".vcf"), CFSTR(".vcard")},
            {CFSTR("text/x-vcard"), CFSTR("text/directory"), CFSTR("text/vcard")}
        },
        {
            kUTTypeJPEG,
            {CFSTR(".jpg"), CFSTR(".jpeg")},
            {CFSTR("image/jpeg")}
        },
        {
            kUTTypeJPEG2000,
            {CFSTR(".jp2")},
            {CFSTR("image/jp2")}
        },
        {
            kUTTypeTIFF,
            {CFSTR(".tif"), CFSTR(".tiff")},
            {CFSTR("image/tiff")}
        },
        {
            kUTTypePICT,
            {CFSTR(".pic"), CFSTR(".pct"), CFSTR(".pict")},
            {CFSTR("image/pict"), CFSTR("image/x-pict"), CFSTR("image/x-macpict")}
        },
        {
            kUTTypePNG,
            {CFSTR(".png")},
            {CFSTR("image/png")}
        },
        {
            CFSTR("public.xbitmap-image"),
            {CFSTR(".xbm")},
            {CFSTR("image/x-quicktime")}
        },
        {
            kUTTypeQuickTimeImage,
            {CFSTR(".qif"), CFSTR(".qtif")},
            {CFSTR("image/x-quicktime")}
        },
        {
            kUTTypeQuickTimeMovie,
            {CFSTR(".mov"), CFSTR(".qt")},
            {CFSTR("video/quicktime")}
        },
        {
            CFSTR("public.avi"),
            {CFSTR(".avi"), CFSTR(".vfw")},
            {CFSTR("video/avi"), CFSTR("video/msvideo"), CFSTR("video/x-msvideo")}
        },
        {
            kUTTypeMPEG,
            {CFSTR(".mpg"), CFSTR(".mpeg"), CFSTR(".m75"), CFSTR(".m15")},
            {CFSTR("video/mpg"), CFSTR("video/mpeg"), CFSTR("video/x-mpg"), CFSTR("video/x-mpeg")}
        },
        {
            kUTTypeMPEG4,
            {CFSTR(".mp4")},
            {CFSTR("video/mp4"), CFSTR("video/mp4v")}
        },
        {
            CFSTR("public.3gpp"),
            {CFSTR(".3gp"), CFSTR(".3gpp")},
            {CFSTR("video/3gpp"), CFSTR("audio/3gpp")}
        },
        {
            CFSTR("public.3gpp2"),
            {CFSTR(".3g2"), CFSTR(".3gp2")},
            {CFSTR("video/3gpp2"), CFSTR("audio/3gpp2")}
        },
        {
            kUTTypeMP3,
            {CFSTR(".mp3")},
            {CFSTR("audio/x-mpeg"), CFSTR("audio/mpeg"), CFSTR("audio/mpeg3"), CFSTR("audio/mpg"), CFSTR("audio/x-mpeg3"), CFSTR("audio/x-mpg"), CFSTR("audio/x-mp3")}
        },
        {
            CFSTR("public.ulaw-audio"),
            {CFSTR(".au"), CFSTR(".ulw"), CFSTR(".snd")},
            {CFSTR("audio/basic"), CFSTR("audio/au"), CFSTR("audio/snd")}
        },
        {
            CFSTR("public.aifc-audio"),
            {CFSTR(".aifc"), CFSTR(".aiff"), CFSTR(".aif")},
            {CFSTR("audio/x-aiff"), CFSTR("audio/aiff")}
        },
        {
            CFSTR("public.aiff-audio"),
            {CFSTR(".aiff"), CFSTR(".aif")},
            {CFSTR("audio/x-aiff"), CFSTR("audio/aiff")}
        },
        {
            CFSTR("com.pkware.zip-archive"),
            {CFSTR(".zip")},
            {CFSTR("application/zip")}
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
    dispatch_once(&onceToken,
                  ^{
                      s_systemUTIMap = CFDictionaryCreateMutable(kCFAllocatorDefault, 0, &kCFTypeDictionaryKeyCallBacks, NULL);
                      s_fileExtensionToSystemUTIMap =
                          CFDictionaryCreateMutable(kCFAllocatorDefault, 0, &kCFTypeDictionaryKeyCallBacks, NULL);
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
                              LOG_HR_MSG(E_FAIL,
                                         "Key (%s) collition detected in s_systemUTIMap!",
                                         [static_cast<NSString*>(entry.utiName) UTF8String]);
                          }

                          // Add each file name extension to the s_fileExtensionToSystemUTIMap
                          //  Key: File Name Extension (CFStringRef)
                          //  Value: CFMutableArray of UTI strings (CFMutableArrayRef)
                          for (const auto& fileNameExtension : entry.fileNameExtensions) {
                              if (!CFDictionaryContainsKey(s_fileExtensionToSystemUTIMap, (const void*)fileNameExtension)) {
                                  CFMutableArrayRef systemUTIArray = CFArrayCreateMutable(kCFAllocatorDefault, 0, &kCFTypeArrayCallBacks);
                                  CFArrayAppendValue(systemUTIArray, (const void*)entry.utiName);
                                  CFDictionaryAddValue(s_fileExtensionToSystemUTIMap,
                                                       (const void*)fileNameExtension,
                                                       (const void*)systemUTIArray);
                              } else {
                                  CFMutableArrayRef systemUTIArray = static_cast<CFMutableArrayRef>(const_cast<void*>(
                                      CFDictionaryGetValue(s_fileExtensionToSystemUTIMap, (const void*)fileNameExtension)));
                                  CFArrayAppendValue(systemUTIArray, (const void*)entry.utiName);
                                  CFDictionarySetValue(s_fileExtensionToSystemUTIMap,
                                                       (const void*)fileNameExtension,
                                                       (const void*)systemUTIArray);
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