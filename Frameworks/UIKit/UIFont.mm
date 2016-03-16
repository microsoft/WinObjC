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

#import <StubReturn.h>
#include "Starboard.h"
#include "CGFontInternal.h"
#include "Foundation/NSString.h"
#include "Foundation/NSMutableDictionary.h"
#include "Foundation/NSData.h"
#include "Foundation/NSArray.h"
#include "Foundation/NSFileManager.h"
#include "UIKit/UIFont.h"
#include "UIKit/UIFontDescriptor.h"
#include "UIFontDescriptorInternal.h"
#include "CoreText/CTFont.h"

extern "C" {
#include <ft2build.h>
#include FT_FREETYPE_H
#include <ftglyph.h>
#include <tttables.h>
#include <ftadvanc.h>
#include <ftsizes.h>
#include <ftmodapi.h>

}

#include "LoggingNative.h"

static const wchar_t* g_logTag = L"UIFont";

FT_Library _fontLib;
FT_MemoryRec_ _fontMemory;
NSMutableDictionary* _fontList;
CFMutableDictionaryRef _fontInstance, _fontSizingInstance;
NSMutableDictionary* g_fontCache;
NSMutableDictionary* _fontDataCache;

void* FTAllocFunc(FT_Memory memory, long size) {
    return IwMalloc(size);
}

void FTFreeFunc(FT_Memory memory, void* ptr) {
    IwFree(ptr);
}

void* FTReallocFunc(FT_Memory memory, long curSize, long newSize, void* ptr) {
    return IwRealloc(ptr, newSize);
}

@implementation UIFont {
@public
    void *_font, *_sizingFont;
    idretaintype(NSString) _name;
    UIFontDescriptor* _descriptor;
    idretain _fileName;
    float _size;
    float _horizontalScale;

    bool _cachedCapHeight, _cachedXHeight;
    float _capHeight, _xHeight;
}

static FT_Face getFace(id faceName, bool sizing, UIFont* fontInfo = nil) {
    FT_Error err;

    //  Look it up in our cache
    FT_Face val;

    _CGFontLock();
    auto unlock = wil::ScopeExit([] () {
        _CGFontUnlock();
    });

    if (!sizing) {
        val = (FT_Face)CFDictionaryGetValue(_fontInstance, (void*)faceName);
        if (val != 0) {
            return val;
        }
    } else {
        val = (FT_Face)CFDictionaryGetValue(_fontSizingInstance, (void*)faceName);
        if (val != 0) {
            return val;
        }
    }

    //  Lookup the filename
    char* _faceName = (char*)[faceName UTF8String];
    id filename = [_fontList objectForKey:faceName];
    if (filename == nil)
        filename = @"C:/Windows/Fonts/SegoeUI.ttf";

    if (filename == nil) {
        if (strcmp(_faceName, "Helvetica")) {
            TraceVerbose(g_logTag, L"*** FONT NOT FOUND: %hs -- falling back to Helvetica. ***", _faceName);
            filename = [_fontList objectForKey:@"Helvetica"];
        }

        if (filename == nil)
            return nullptr;
    }

#if defined(USE_ROBOTO_FONT)
    if ((strstr(_faceName, "Bold") != NULL || strstr(_faceName, "Heavy") != NULL) &&
        (strstr(_faceName, "Italic") != NULL || strstr(_faceName, "Oblique") != NULL)) {
        filename = @"/fonts/Roboto-BoldItalic.ttf";
    } else if (strstr(_faceName, "Bold") != NULL || strstr(_faceName, "Heavy") != NULL) {
        filename = @"/fonts/Roboto-Bold.ttf";
    } else if ((strstr(_faceName, "Italic") != NULL || strstr(_faceName, "Oblique") != NULL)) {
        filename = @"/fonts/Roboto-Italic.ttf";
    } else {
        filename = @"/fonts/Roboto-Regular.ttf";
    }
    if (![[NSFileManager defaultManager] fileExistsAtPath:filename]) {
        filename = @"/fonts/Helvetica.ttf";
    }
    if (strstr(_faceName, "Condensed") != NULL) {
        if (fontInfo != nil) {
            fontInfo->_horizontalScale = 0.85f;
        }
    }
#endif

    id cachedData = [_fontDataCache objectForKey:filename];
    if (!cachedData) {
        TraceVerbose(g_logTag, L"Loading font %hs", [filename UTF8String]);

        cachedData = [[NSData alloc] initWithContentsOfFile:filename];
        [_fontDataCache setObject:cachedData forKey:filename];
    }

    FT_Face ret;
    char* pFont = (char*)[cachedData bytes];
    DWORD fontLen = [cachedData length];

    err = FT_New_Memory_Face(_fontLib, (const FT_Byte*)pFont, fontLen, 0, &ret);
    assert(err == 0);

    if (!sizing) {
        CFDictionarySetValue(_fontInstance, (const void*)faceName, (void*)ret);
    } else {
        CFDictionarySetValue(_fontSizingInstance, (const void*)faceName, (void*)ret);
    }

    return ret;
}

/**
 @Status Stub
*/
+ (NSArray*)familyNames {
    // The actual implementation may need a lock here if it
    // does end up accessing the global font lists or caches.
    UNIMPLEMENTED();
    return StubReturn();
}

+ (UIFont*)fontWithData:(NSData*)data {
    //  Load the font
    char* pFont = (char*)[data bytes];
    DWORD fontLen = [data length];

    UIFont* ret = [self alloc];

    ret->_name = @"Custom font";
    ret->_size = 0.0f;
    ret->_horizontalScale = 1.0f;

    FT_Error err;

    char* pCopy = (char*)IwMalloc(fontLen);
    memcpy(pCopy, pFont, fontLen);

    _CGFontLock();
    auto unlock = wil::ScopeExit([] () {
        _CGFontUnlock();
    });

    err = FT_New_Memory_Face(_fontLib, (const FT_Byte*)pCopy, fontLen, 0, (FT_Face*)&ret->_font);
    err = FT_New_Memory_Face(_fontLib, (const FT_Byte*)pCopy, fontLen, 0, (FT_Face*)&ret->_sizingFont);

    if (err != 0) {
        TraceError(g_logTag, L"Error loading font");
        ret->_font = getFace(@"Helvetica", false);
        ret->_sizingFont = getFace(@"Helvetica", true);
    }
    // assert(err == 0);

    if ([data respondsToSelector:@selector(_fileName)]) {
        ret->_fileName = [[data _fileName] lastPathComponent];
        if (ret->_fileName) {
            CFDictionarySetValue(_fontInstance, (const void*)(id)ret->_fileName, (void*)ret->_font);
            CFDictionarySetValue(_fontSizingInstance, (const void*)(id)ret->_fileName, (void*)ret->_sizingFont);
        }
    }

    return [ret autorelease];
}

/**
 @Status Interoperable
*/
+ (UIFont*)fontWithName:(NSString*)name size:(float)size {
    UIFont* ret = [self alloc];

    if (size == 0.0f) {
        size = [self systemFontSize];
    }

    ret->_name = name;
    ret->_size = size;
    ret->_horizontalScale = 1.0f;

    _CGFontLock();
    auto unlock = wil::ScopeExit([] () {
        _CGFontUnlock();
    });

    id cached = [g_fontCache objectForKey:(id)ret];
    if (cached != nil) {
        [ret release];
        return cached;
    }

    if (name == nil) {
        TraceWarning(g_logTag, L"Warning: Font name is nil!");
        ret->_font = getFace(@"Helvetica", false, ret);
        ret->_sizingFont = getFace(@"Helvetica", true, ret);
    } else {
        ret->_font = getFace(name, false, ret);
        ret->_sizingFont = getFace(name, true, ret);
    }

    if (ret->_font == nil) {
        return nil;
    }

    [g_fontCache setObject:(id)ret forKey:(id)ret];

    return [ret autorelease];
}

/**
 @Status Interoperable
 @Tags          Font
 @Public        Yes
*/
+ (UIFont*)fontWithDescriptor:(UIFontDescriptor*)descriptor size:(CGFloat)fontSize {
    UIFont* font = [UIFont fontWithName:[descriptor _getFontName] size:fontSize];
    font->_descriptor = [descriptor retain];
    return font;
}

+ (UIFont*)messageFont {
    static id mFont = [[self systemFontOfSize:15.0f] retain];
    return mFont;
}

+ (UIFont*)titleFont {
    static id tFont = [[self systemFontOfSize:20.0f] retain];
    return tFont;
}

+ (UIFont*)defaultFont {
    static id dFont = [[self systemFontOfSize:10.0f] retain];
    return dFont;
}

+ (UIFont*)buttonFont {
    static id dFont = [[self systemFontOfSize:17.0f] retain];
    return dFont;
}

/**
 @Status Interoperable
*/
+ (UIFont*)systemFontOfSize:(float)size {
    // TODO 5785385: Using clumsy fontWithDescriptor to initialize here, so that _descriptor is initialized
    // Clean this up a bit once fontDescriptor gets better support
    UIFont* ret = [self fontWithDescriptor:[UIFontDescriptor fontDescriptorWithName:@"Helvetica" size:size] size:size];

    return ret;
}

/**
 @Status Interoperable
*/
+ (void)initialize {
    if (self == [UIFont class]) {
        g_fontCache = [NSMutableDictionary new];
        _fontDataCache = [NSMutableDictionary new];
        _fontList = [[NSDictionary dictionaryWithContentsOfFile:@"/fonts/fontmap.xml"] retain];
        if (!_fontList) {
            _fontList = [NSMutableDictionary new];
        }
        _fontInstance = CFDictionaryCreateMutable(NULL, 128, &kCFTypeDictionaryKeyCallBacks, NULL);
        _fontSizingInstance = CFDictionaryCreateMutable(NULL, 128, &kCFTypeDictionaryKeyCallBacks, NULL);
        _fontMemory.user = nullptr;
        _fontMemory.alloc = FTAllocFunc;
        _fontMemory.free = FTFreeFunc;
        _fontMemory.realloc = FTReallocFunc;
        FT_Error error = FT_New_Library(&_fontMemory, &(_fontLib));
        if (!error) {
            FT_Add_Default_Modules(_fontLib);
        } else {
            TraceWarning(g_logTag, L"Failed to instantiate FreeType library");
        }
    }
}

/**
 @Status Interoperable
*/
+ (UIFont*)boldSystemFontOfSize:(float)size {
    // TODO 5785385: Using clumsy fontWithDescriptor to initialize here, so that _descriptor is initialized
    // Clean this up a bit once fontDescriptor gets better support
    UIFontDescriptor* fontDes =
        [[UIFontDescriptor fontDescriptorWithName:@"Helvetica Bold" size:size] fontDescriptorWithSymbolicTraits:UIFontDescriptorTraitBold];
    UIFont* ret = [self fontWithDescriptor:fontDes size:size];

    return ret;
}

/**
 @Status Interoperable
*/
+ (UIFont*)italicSystemFontOfSize:(float)size {
    // TODO 5785385: Using clumsy fontWithDescriptor to initialize here, so that _descriptor is initialized
    // Clean this up a bit once fontDescriptor gets better support
    UIFontDescriptor* fontDes = [[UIFontDescriptor fontDescriptorWithName:@"Helvetica Oblique" size:size]
        fontDescriptorWithSymbolicTraits:UIFontDescriptorTraitItalic];
    UIFont* ret = [self fontWithDescriptor:fontDes size:size];

    return ret;
}

/**
 @Status Stub
*/
+ (NSArray*)fontNamesForFamilyName:(NSArray*)name {
    UNIMPLEMENTED();
    return [NSArray arrayWithObject:name];
}

void loadFont(UIFont* self) {
    self->_font = getFace(self->_name, false, self);
    self->_sizingFont = getFace(self->_name, true, self);
}

- (NSObject*)initWithCoder:(NSCoder*)coder {
    _name = [coder decodeObjectForKey:@"UIFontName"];
    _size = [coder decodeFloatForKey:@"UIFontPointSize"];
    _horizontalScale = 1.0f;

    loadFont(self);

    if (_font == nil) {
        return nil;
    }

    return self;
}

/**
 @Status Interoperable
*/
- (UIFont*)fontWithSize:(float)size {
    UIFont* ret = [UIFont alloc];

    ret->_font = _font;
    ret->_sizingFont = _sizingFont;
    ret->_name = _name;
    ret->_size = size;
    ret->_horizontalScale = _horizontalScale;

    _CGFontLock();
    auto unlock = wil::ScopeExit([] () {
        _CGFontUnlock();
    });

    id cached = [g_fontCache objectForKey:(id)ret];
    if (cached != nil) {
        [ret release];
        return cached;
    }

    [g_fontCache setObject:(id)ret forKey:(id)ret];

    return [ret autorelease];
}

/**
 @Status Interoperable
*/
- (NSString*)fontName {
    return _name;
}

/**
 @Status Caveat
 @Notes Supports only English language and limited encodings.
*/
- (NSString*)familyName {
    CFStringRef name = CTFontCopyName(static_cast<CTFontRef>(self), kCTFontFamilyNameKey);
    return static_cast<NSString*>(name);
}
/**
 @Status Interoperable
*/
- (float)descender {
    FT_Face face = (FT_Face)_sizingFont;
    if (face == NULL)
        return 1.f;

    CGFontSetFTFontSize(self, face, _size);
    return ((float)(face->size->metrics.descender)) / 64.0f;
}

/**
 @Status Interoperable
*/
- (float)ascender {
    FT_Face face = (FT_Face)_sizingFont;
    if (face == NULL)
        return 1.f;

    _CGFontLock();
    CGFontSetFTFontSize(self, face, _size);
    float ret = ((float)(face->size->metrics.ascender)) / 64.0f;
    _CGFontUnlock();

    return ret;
}

/**
 @Status Interoperable
*/
- (float)lineHeight {
    FT_Face face = (FT_Face)_sizingFont;
    if (face == NULL)
        return 1.f;

    _CGFontLock();
    CGFontSetFTFontSize(self, face, _size);
    float ret = ((float)(face->size->metrics.height)) / 64.0f;
    _CGFontUnlock();

    return ret;
}

/**
 @Status Interoperable
*/
- (float)capHeight {
    if (!_cachedCapHeight) {
        FT_Face face = (FT_Face)_sizingFont;
        if (face == NULL)
            return 1.f;

        _CGFontLock();
        CGFontSetFTFontSize(self, face, _size);

        char string[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int length = strlen(string);
        int ret = 0;
        FT_Error error;
        FT_GlyphSlot slot = face->glyph;

        //  Lookup each glyph
        for (int i = 0; i < length; i++) {
            WORD index = FT_Get_Char_Index(face, string[i]);

            FT_Glyph glyph;

            error = FT_Load_Glyph(face, index, FT_LOAD_NO_HINTING);
            assert(error == 0);
            error = FT_Get_Glyph(slot, &glyph);

            //  Get the controlbox
            FT_BBox bbox;
            FT_Glyph_Get_CBox(glyph, FT_GLYPH_BBOX_SUBPIXELS, &bbox);

            if (bbox.yMax > ret)
                ret = bbox.yMax;

            FT_Done_Glyph(glyph);
        }
        _CGFontUnlock();

        _capHeight = (float)ret / 64.0f;
        _cachedCapHeight = true;
    }

    return _capHeight;
}

/**
 @Status Interoperable
*/
- (float)xHeight {
    if (!_cachedXHeight) {
        FT_Face face = (FT_Face)_sizingFont;
        if (face == NULL)
            return 1.f;

        _CGFontLock();
        CGFontSetFTFontSize(self, face, _size);

        char string[] = "x";
        int length = strlen(string);
        int ret = 0;
        FT_Error error;
        FT_GlyphSlot slot = face->glyph;

        //  Lookup each glyph
        for (int i = 0; i < length; i++) {
            WORD index = FT_Get_Char_Index(face, string[i]);

            FT_Glyph glyph;

            error = FT_Load_Glyph(face, index, FT_LOAD_NO_HINTING);
            assert(error == 0);
            error = FT_Get_Glyph(slot, &glyph);

            //  Get the controlbox
            FT_BBox bbox;
            FT_Glyph_Get_CBox(glyph, FT_GLYPH_BBOX_SUBPIXELS, &bbox);

            if (bbox.yMax > ret)
                ret = bbox.yMax;

            FT_Done_Glyph(glyph);
        }
        _CGFontUnlock();

        _xHeight = (float)ret / 64.0f;
        _cachedXHeight = true;
    }

    return _xHeight;
}

/**
 @Status Interoperable
*/
- (float)pointSize {
    return _size;
}

/**
 @Status Interoperable
*/
- (float)leading {
    return 0.0f;
}

/**
 @Status Interoperable
 @Tags          Font
 @Public        Yes
*/
- (UIFontDescriptor*)fontDescriptor {
    return self->_descriptor;
}

/**
 @Status Interoperable
 @Tags          Font
 @Public        Yes
*/
+ (float)smallSystemFontSize {
    return [UIFontDescriptor _getSystemSmallFontSize];
}

/**
 @Status Interoperable
 @Tags          Font
 @Public        Yes
*/
+ (float)systemFontSize {
    return [UIFontDescriptor _getSystemFontSize];
}

/**
 @Status Interoperable
 @Tags          Font
 @Public        Yes
*/
+ (float)labelFontSize {
    return [UIFontDescriptor _getLabelFontSize];
}

/**
 @Status Interoperable
 @Tags          Font
 @Public        Yes
*/
+ (float)buttonFontSize {
    return [UIFontDescriptor _getButtonFontSize];
}

- (NSUInteger)hash {
    NSUInteger ret = [_name hash];
    ret += (NSUInteger)(_size * 100.0f);

    return ret;
}

- (BOOL)isEqual:(UIFont*)other {
    if (![other isKindOfClass:[UIFont class]])
        return FALSE;
    if (_size != other->_size)
        return FALSE;
    if (![_name isEqual:(id)other->_name])
        return FALSE;
    if (![_descriptor isEqual:(id)other->_descriptor])
        return FALSE;

    return TRUE;
}

- (NSObject*)copyWithZone:(NSZone*)zone {
    return [self retain];
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    _fileName = nil;
    _name = nil;
    _descriptor = nil;
    [super dealloc];
}

- (void)_setName:(NSString*)name {
    _fileName = name;
}

- (uint32_t)_fontHandle {
    return (uint32_t)_font;
}

- (uint32_t)_sizingFontHandle {
    return (uint32_t)_sizingFont;
}

// Internal methods

// Private message sent from CTFontManager for the implementation of CTFontManagerRegisterGraphicsFont
- (bool)_CTFontManagerRegisterGraphicsFont:(CGFontRef)font withError:(CFErrorRef*)error {
    if (error) {
        *error = nullptr;
    }

    UIFont* fnt = font;
    if (((FT_Face)fnt->_font)->family_name == NULL) {
        return FALSE;
    }

    FT_Face fntFace = (FT_Face)fnt->_font;

    id faceName = [NSString stringWithCString:((FT_Face)fnt->_font)->family_name];

    [font retain];

    _CGFontLock();
    auto unlock = wil::ScopeExit([] () {
        _CGFontUnlock();
    });

    CFDictionarySetValue(_fontInstance, (const void*)faceName, (void*)fnt->_font);
    CFDictionarySetValue(_fontSizingInstance, (const void*)faceName, (void*)fnt->_sizingFont);
    if (fnt->_fileName) {
        CFDictionarySetValue(_fontInstance, (const void*)(id)fnt->_fileName, (void*)fnt->_font);
        CFDictionarySetValue(_fontSizingInstance, (const void*)(id)fnt->_fileName, (void*)fnt->_sizingFont);
    }

    return true;
}

// Internal methods
// Private message sent from CTFontManager for the implementation of CTFontManagerRegisterFontsForURL in CTFontManager
+ (bool)_CTFontManagerRegisterFontsForURL:(CFURLRef)fontURL withScope:(CTFontManagerScope)scope withError:(CFErrorRef*)error {
    NSURL* url = static_cast<NSURL*>(fontURL);
    if (![url isFileURL]) {
        TraceInfo(g_logTag, L"Only file urls supported");
        if (error) {
            *error = nil;
        }
        return false;
    }

    NSString* fileName = [url path];

    _CGFontLock();
    auto unlock = wil::ScopeExit([] () {
        _CGFontUnlock();
    });

    if ([[_fontList allValues] containsObject:fileName]) {
        // this font is already registered
        return true;
    }

    NSData* data = [NSData dataWithContentsOfURL:url];
    FT_Face face;
    char* pFont = (char*)[data bytes];
    DWORD fontLen = [data length];

    FT_Error err = FT_New_Memory_Face(_fontLib, (const FT_Byte*)pFont, fontLen, 0, &face);

    if (err) {
        if (!error) {
            error = nil;
        }
        return false;
    }

    NSString* faceName = [NSString stringWithCString:face->family_name];
    [_fontList setObject:fileName forKey:faceName];
    [_fontDataCache setObject:data forKey:fileName];
    CFDictionarySetValue(_fontInstance, (const void*)faceName, (void*)face);

    return true;
}

@end
