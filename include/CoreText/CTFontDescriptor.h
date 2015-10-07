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

#ifndef _CTFONTDESCRIPTOR_H_
#define _CTFONTDESCRIPTOR_H_

#import <StarboardExport.h>
#import <CoreFoundation/CFString.h>

typedef const struct __CTFontDescriptor *CTFontDescriptorRef;

SB_EXPORT const CFStringRef kCTFontURLAttribute;
SB_EXPORT const CFStringRef kCTFontNameAttribute;
SB_EXPORT const CFStringRef kCTFontDisplayNameAttribute;
SB_EXPORT const CFStringRef kCTFontFamilyNameAttribute;
SB_EXPORT const CFStringRef kCTFontStyleNameAttribute;
SB_EXPORT const CFStringRef kCTFontTraitsAttribute;
SB_EXPORT const CFStringRef kCTFontVariationAttribute;
SB_EXPORT const CFStringRef kCTFontSizeAttribute;
SB_EXPORT const CFStringRef kCTFontMatrixAttribute;
SB_EXPORT const CFStringRef kCTFontCascadeListAttribute;
SB_EXPORT const CFStringRef kCTFontCharacterSetAttribute;
SB_EXPORT const CFStringRef kCTFontLanguagesAttribute;
SB_EXPORT const CFStringRef kCTFontBaselineAdjustAttribute;
SB_EXPORT const CFStringRef kCTFontMacintoshEncodingsAttribute;
SB_EXPORT const CFStringRef kCTFontFeaturesAttribute;
SB_EXPORT const CFStringRef kCTFontFeatureSettingsAttribute;
SB_EXPORT const CFStringRef kCTFontFixedAdvanceAttribute;
SB_EXPORT const CFStringRef kCTFontOrientationAttribute;
SB_EXPORT const CFStringRef kCTFontFormatAttribute;
SB_EXPORT const CFStringRef kCTFontRegistrationScopeAttribute;
SB_EXPORT const CFStringRef kCTFontPriorityAttribute;
SB_EXPORT const CFStringRef kCTFontEnabledAttribute;

SB_EXPORT CTFontDescriptorRef CTFontDescriptorCreateWithAttributes(CFDictionaryRef attributes);
SB_EXPORT CTFontDescriptorRef CTFontDescriptorCreateCopyWithAttributes(CTFontDescriptorRef original, CFDictionaryRef attributes);

#endif /* _CTFONTDESCRIPTOR_H_ */