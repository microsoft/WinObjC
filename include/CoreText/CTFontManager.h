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
#pragma once

#import <CoreText/CoreTextExport.h>

#import <CoreFoundation/CFArray.h>
#import <CoreFoundation/CFString.h>
#import <CoreFoundation/CFURL.h>

#import <CoreGraphics/CGFont.h>

typedef uint32_t CTFontManagerScope;
typedef uint32_t CTFontManagerAutoActivationSetting;
typedef CFIndex CTFontManagerError;

enum { kCTFontManagerScopeNone = 0, kCTFontManagerScopeProcess = 1, kCTFontManagerScopeUser = 2, kCTFontManagerScopeSession = 3 };
enum {
    kCTFontManagerAutoActivationDefault = 0,
    kCTFontManagerAutoActivationDisabled = 1,
    kCTFontManagerAutoActivationEnabled = 2,
    kCTFontManagerAutoActivationPromptUser = 3
};

enum {
    kCTFontManagerErrorFileNotFound = 101,
    kCTFontManagerErrorInsufficientPermissions = 102,
    kCTFontManagerErrorUnrecognizedFormat = 103,
    kCTFontManagerErrorInvalidFontData = 104,
    kCTFontManagerErrorAlreadyRegistered = 105,
};

enum {
    kCTFontManagerErrorNotRegistered = 201,
    kCTFontManagerErrorInUse = 202,
    kCTFontManagerErrorSystemRequired = 202,
};

CORETEXT_EXPORT const CFStringRef kCTFontManagerRegisteredFontsChangedNotification;
CORETEXT_EXPORT const CFStringRef kCTFontManagerErrorDomain;
CORETEXT_EXPORT const CFStringRef kCTFontManagerErrorFontURLsKey;

// TODO: Anything in the original CTFontManager.h that isn't here???

CORETEXT_EXPORT CFArrayRef CTFontManagerCreateFontDescriptorsFromURL(CFURLRef fileURL) STUB_METHOD;
CORETEXT_EXPORT bool CTFontManagerRegisterFontsForURL(CFURLRef fontURL, CTFontManagerScope scope, CFErrorRef _Nullable* error);
CORETEXT_EXPORT bool CTFontManagerUnregisterFontsForURL(CFURLRef fontURL, CTFontManagerScope scope, CFErrorRef _Nullable* error);
CORETEXT_EXPORT bool CTFontManagerRegisterFontsForURLs(CFArrayRef fontURLs, CTFontManagerScope scope, CFArrayRef _Nullable* errors);
CORETEXT_EXPORT bool CTFontManagerUnregisterFontsForURLs(CFArrayRef fontURLs, CTFontManagerScope scope, CFArrayRef _Nullable* errors);
CORETEXT_EXPORT bool CTFontManagerRegisterGraphicsFont(CGFontRef font, CFErrorRef _Nullable* error);
CORETEXT_EXPORT bool CTFontManagerUnregisterGraphicsFont(CGFontRef font, CFErrorRef _Nullable* error);
CORETEXT_EXPORT bool CTFontManagerIsSupportedFont(CFURLRef fontURL) STUB_METHOD;
