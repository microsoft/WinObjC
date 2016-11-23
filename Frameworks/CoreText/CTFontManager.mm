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

#import <CoreText/CTFontManager.h>
#import <StubReturn.h>
#import <Starboard.h>
#import <CoreGraphics/DWriteWrapper.h>
#import <CoreGraphics/CGFontInternal.h>

const CFStringRef kCTFontManagerRegisteredFontsChangedNotification =
    static_cast<CFStringRef>(@"kCTFontManagerRegisteredFontsChangedNotification");
const CFStringRef kCTFontManagerErrorDomain = static_cast<CFStringRef>(@"kCTFontManagerErrorDomain");
const CFStringRef kCTFontManagerErrorFontURLsKey = static_cast<CFStringRef>(@"kCTFontManagerErrorFontURLsKey");

/**
 @Status Stub
 @Notes
*/
CFArrayRef CTFontManagerCreateFontDescriptorsFromURL(CFURLRef fileURL) {
    UNIMPLEMENTED();
    return StubReturn();
}

// Helper functions to reduce code duplication, as (un)registering fonts have almost identical path
// (Un)Registers font by creating temporary CFArray and calling into function for multiple fonts
template <typename TLambda>
static bool __CTFontManagerUpdateWithFont(CFURLRef fontURL, CTFontManagerScope scope, CFErrorRef _Nullable* error, const TLambda&& func) {
    woc::unique_cf<CFArrayRef> fontURLs{ CFArrayCreate(nullptr, (const void**)&fontURL, 1, &kCFTypeArrayCallBacks) };
    if (error) {
        CFArrayRef errors = nil;
        bool ret = func(fontURLs.get(), scope, &errors);
        if (errors != nil) {
            *error = (CFErrorRef)CFRetain(CFArrayGetValueAtIndex(errors, 0));
        }

        CFRelease(errors);
        return ret;
    }

    return func(fontURLs.get(), scope, nullptr);
}

// Converts CFURLs to CFDatas which are passed into DWriteWrapper methods
template <typename TLambda>
static bool __CTFontManagerUpdateWithFonts(CFArrayRef fontURLs,
                                           CTFontManagerScope scope,
                                           CFArrayRef _Nullable* errors,
                                           const TLambda&& func) {
    CFIndex count = CFArrayGetCount(fontURLs);
    woc::unique_cf<CFMutableArrayRef> fontDatas{ CFArrayCreateMutable(nullptr, 0, &kCFTypeArrayCallBacks) };
    for (size_t i = 0; i < count; ++i) {
        NSData* data = [NSData dataWithContentsOfURL:static_cast<NSURL*>(CFArrayGetValueAtIndex(fontURLs, i))];
        if (data != nullptr) {
            CFArrayAppendValue(fontDatas.get(), (CFDataRef)data);
        }
    }

    return SUCCEEDED(func(fontDatas.get(), errors));
}

/**
 @Status Caveat
 @Notes scope unsupported
*/
bool CTFontManagerRegisterFontsForURL(CFURLRef fontURL, CTFontManagerScope scope, CFErrorRef _Nullable* error) {
    return __CTFontManagerUpdateWithFont(fontURL, scope, error, &CTFontManagerRegisterFontsForURLs);
}

/**
 @Status Caveat
 @Notes scope unsupported
*/
bool CTFontManagerUnregisterFontsForURL(CFURLRef fontURL, CTFontManagerScope scope, CFErrorRef _Nullable* error) {
    return __CTFontManagerUpdateWithFont(fontURL, scope, error, &CTFontManagerUnregisterFontsForURLs);
}

/**
 @Status Caveat
 @Notes scope unsupported
*/
bool CTFontManagerRegisterFontsForURLs(CFArrayRef fontURLs, CTFontManagerScope scope, CFArrayRef _Nullable* errors) {
    return __CTFontManagerUpdateWithFonts(fontURLs, scope, errors, &_DWriteRegisterFontsWithDatas);
}

/**
 @Status Caveat
 @Notes scope unsupported
*/
bool CTFontManagerUnregisterFontsForURLs(CFArrayRef fontURLs, CTFontManagerScope scope, CFArrayRef _Nullable* errors) {
    return __CTFontManagerUpdateWithFonts(fontURLs, scope, errors, &_DWriteUnregisterFontsWithDatas);
}

/**
 @Status Interoperable
 @Notes
*/
bool CTFontManagerRegisterGraphicsFont(CGFontRef font, CFErrorRef* error) {
    CFDataRef data = _CGFontGetData(font);
    if (data == nullptr) {
        // Font was created from registered font, so it must already be registered
        if (error) {
            *error = CFErrorCreate(nullptr, kCFErrorDomainCocoa, kCTFontManagerErrorAlreadyRegistered, nullptr);
        }

        return false;
    }

    woc::unique_cf<CFArrayRef> fontDatas{ CFArrayCreate(nullptr, (const void**)&data, 1, &kCFTypeArrayCallBacks) };
    if (error) {
        CFArrayRef errors = nil;
        bool ret = SUCCEEDED(_DWriteRegisterFontsWithDatas(fontDatas.get(), &errors));
        if (errors != nil) {
            *error = (CFErrorRef)CFRetain(CFArrayGetValueAtIndex(errors, 0));
        }

        CFRelease(errors);
        return ret;
    }

    return SUCCEEDED(_DWriteRegisterFontsWithDatas(fontDatas.get(), nullptr));
}

/**
 @Status Stub
 @Notes
*/
bool CTFontManagerUnregisterGraphicsFont(CGFontRef font, CFErrorRef _Nullable* error) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
bool CTFontManagerIsSupportedFont(CFURLRef fontURL) {
    UNIMPLEMENTED();
    return StubReturn();
}
