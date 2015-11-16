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

#import <CoreFoundation/CFBase.h>
#import <CoreFoundation/CFString.h>
#import <CoreFoundation/CFDictionary.h>

ENABLE_IMPLICIT_BRIDGING
COREFOUNDATION_EXTERNC_BEGIN

typedef struct __CFMutableAttributedString* CFAttributedStringRef;
typedef struct __CFMutableAttributedString* CFMutableAttributedStringRef;

COREFOUNDATION_EXPORT CFTypeID CFAttributedStringGetTypeID(void);

COREFOUNDATION_EXPORT CFAttributedStringRef _CFAttributedStringCreateEmpty(void);

COREFOUNDATION_EXPORT CFAttributedStringRef CFAttributedStringCreate(CFAllocatorRef allocator,
                                                                     CFStringRef string,
                                                                     CFDictionaryRef attributes);
COREFOUNDATION_EXPORT CFAttributedStringRef CFAttributedStringCreateWithSubstring(CFAllocatorRef allocator,
                                                                                  CFAttributedStringRef self,
                                                                                  CFRange range);

COREFOUNDATION_EXPORT CFAttributedStringRef CFAttributedStringCreateCopy(CFAllocatorRef allocator, CFAttributedStringRef self);

COREFOUNDATION_EXPORT CFIndex CFAttributedStringGetLength(CFAttributedStringRef self);
COREFOUNDATION_EXPORT CFStringRef CFAttributedStringGetString(CFAttributedStringRef self);

COREFOUNDATION_EXPORT CFTypeRef CFAttributedStringGetAttribute(CFAttributedStringRef self,
                                                               CFIndex location,
                                                               CFStringRef name,
                                                               CFRange* effectiveRange);
COREFOUNDATION_EXPORT CFTypeRef CFAttributedStringGetAttributeAndLongestEffectiveRange(
    CFAttributedStringRef self, CFIndex location, CFStringRef name, CFRange range, CFRange* longestEffectiveRange);
COREFOUNDATION_EXPORT CFDictionaryRef CFAttributedStringGetAttributes(CFAttributedStringRef self,
                                                                      CFIndex location,
                                                                      CFRange* effectiveRange);
COREFOUNDATION_EXPORT CFDictionaryRef CFAttributedStringGetAttributesAndLongestEffectiveRange(CFAttributedStringRef self,
                                                                                              CFIndex location,
                                                                                              CFRange range,
                                                                                              CFRange* longestEffectiveRange);
// mutable

COREFOUNDATION_EXPORT CFMutableAttributedStringRef CFAttributedStringCreateMutable(CFAllocatorRef allocator, CFIndex maxLength);

COREFOUNDATION_EXPORT CFMutableAttributedStringRef CFAttributedStringCreateMutableCopy(CFAllocatorRef allocator,
                                                                                       CFIndex maxLength,
                                                                                       CFAttributedStringRef self);

COREFOUNDATION_EXPORT CFMutableStringRef CFAttributedStringGetMutableString(CFMutableAttributedStringRef self);

COREFOUNDATION_EXPORT void CFAttributedStringRemoveAttribute(CFMutableAttributedStringRef self, CFRange range, CFStringRef name);
COREFOUNDATION_EXPORT void CFAttributedStringReplaceAttributedString(CFMutableAttributedStringRef self,
                                                                     CFRange range,
                                                                     CFAttributedStringRef replacement);
COREFOUNDATION_EXPORT void CFAttributedStringReplaceString(CFMutableAttributedStringRef self, CFRange range, CFStringRef replacement);
COREFOUNDATION_EXPORT void CFAttributedStringSetAttribute(CFMutableAttributedStringRef self,
                                                          CFRange range,
                                                          CFStringRef name,
                                                          CFTypeRef value);
COREFOUNDATION_EXPORT void CFAttributedStringSetAttributes(CFMutableAttributedStringRef self,
                                                           CFRange range,
                                                           CFDictionaryRef replacement,
                                                           Boolean clearPreviousAttributes);

COREFOUNDATION_EXPORT void CFAttributedStringBeginEditing(CFMutableAttributedStringRef self);
COREFOUNDATION_EXPORT void CFAttributedStringEndEditing(CFMutableAttributedStringRef self);

COREFOUNDATION_EXTERNC_END
DISABLE_IMPLICIT_BRIDGING
