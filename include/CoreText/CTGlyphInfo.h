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

#import <CoreText/CoreTextExport.h>
#import <CoreText/CTFont.h>

#import <CoreFoundation/CFString.h>

#import <CoreGraphics/CGFont.h>

typedef const struct __CTGlyphInfo* CTGlyphInfoRef;
typedef uint16_t CTCharacterCollection;
enum {
    kCTIdentityMappingCharacterCollection = 0,
    kCTAdobeCNS1CharacterCollection = 1,
    kCTAdobeGB1CharacterCollection = 2,
    kCTAdobeJapan1CharacterCollection = 3,
    kCTAdobeJapan2CharacterCollection = 4,
    kCTAdobeKorea1CharacterCollection = 5
};

CORETEXT_EXPORT CFTypeID CTGlyphInfoGetTypeID() STUB_METHOD;
CORETEXT_EXPORT CTGlyphInfoRef CTGlyphInfoCreateWithGlyphName(CFStringRef glyphName, CTFontRef font, CFStringRef baseString) STUB_METHOD;
CORETEXT_EXPORT CTGlyphInfoRef CTGlyphInfoCreateWithGlyph(CGGlyph glyph, CTFontRef font, CFStringRef baseString) STUB_METHOD;
CORETEXT_EXPORT CTGlyphInfoRef CTGlyphInfoCreateWithCharacterIdentifier(CGFontIndex cid,
                                                                        CTCharacterCollection collection,
                                                                        CFStringRef baseString) STUB_METHOD;
CORETEXT_EXPORT CFStringRef CTGlyphInfoGetGlyphName(CTGlyphInfoRef glyphInfo) STUB_METHOD;
CORETEXT_EXPORT CGFontIndex CTGlyphInfoGetCharacterIdentifier(CTGlyphInfoRef glyphInfo) STUB_METHOD;
CORETEXT_EXPORT CTCharacterCollection CTGlyphInfoGetCharacterCollection(CTGlyphInfoRef glyphInfo) STUB_METHOD;
