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

#pragma once

#if !defined(CF_PRIVATE)
#define CF_PRIVATE __attribute__((__visibility__("hidden")))
#endif

#include <CoreFoundation/CoreFoundation.h>
#include <Foundation/NSFastEnumeration.h>
#include <CFBridgeUtilities.h>

CF_EXTERN_C_BEGIN
CF_PRIVATE void _CFAppendPathComponent2(CFMutableStringRef path, CFStringRef component);
CF_PRIVATE Boolean _CFAppendPathExtension2(CFMutableStringRef path, CFStringRef extension);
CF_PRIVATE CFIndex _CFStartOfPathExtension2(CFStringRef path);
CF_PRIVATE CFIndex _CFStartOfLastPathComponent2(CFStringRef path);
CF_EXPORT UniChar _CFGetSlash();
CF_PRIVATE CFStringRef _CFGetSlashStr();
CF_EXPORT const char* _CFProcessPath();

// For [NSURL password], which does not unescape, unlike CFURLCopyPassword which does
CF_PRIVATE CF_EXPORT CFStringRef _CFURLCopyPasswordNotUnescaped(CFURLRef url);

// Miscellaneous - for collections.
CF_EXPORT unsigned long _CFArrayFastEnumeration(CFArrayRef array, NSFastEnumerationState* state, void* stackbuffer, unsigned long count);
CF_EXPORT unsigned long _CFDictionaryFastEnumeration(CFDictionaryRef dictionary,
                                                     NSFastEnumerationState* state,
                                                     void* stackbuffer,
                                                     unsigned long count);
CF_EXPORT unsigned long _CFSetFastEnumeration(CFSetRef set, NSFastEnumerationState* state, void* stackbuffer, unsigned long count);
CF_EXPORT Boolean _CFDictionaryIsMutable(CFDictionaryRef dictionary);
CF_EXPORT Boolean _CFArrayIsMutable(CFArrayRef array);
CF_PRIVATE Boolean __CFCharacterSetIsMutable(CFCharacterSetRef cset);
CF_EXPORT Boolean _CFDataIsMutable(CFDataRef data);
CF_EXPORT Boolean _CFDataOwnsBuffer(CFDataRef data);
CF_EXPORT Boolean _CFAttributedStringIsMutable(CFAttributedStringRef attrStr);
CF_EXPORT Boolean _CFSetIsMutable(CFSetRef hc);
CF_EXTERN_C_END

// Copied from CFFileUtilities.c
#if DEPLOYMENT_TARGET_WINDOWS
#define WINDOWS_PATH_SEMANTICS
#else
#define UNIX_PATH_SEMANTICS
#endif

#if defined(WINDOWS_PATH_SEMANTICS)
#define IS_SLASH(C) ((C) == '\\' || (C) == '/')
#elif defined(UNIX_PATH_SEMANTICS)
#define IS_SLASH(C) ((C) == '/')
#endif

// From CFRuntime.c, for object zombification.
CF_EXPORT void (*__CFZombifyNSObjectHook)(id);
CF_EXPORT void _CFEnableZombies(void);
CF_EXPORT void _CFDisableZombies(void);

// Expose current directory functionality from CFURL
CF_EXPORT CFURLRef _CFURLCreateCurrentDirectoryURL(CFAllocatorRef allocator) CF_RETURNS_RETAINED;

// Expose internal stream helper for benefit of Foundation
CF_EXPORT CFReadStreamRef CFReadStreamCreateWithData(CFAllocatorRef alloc, CFDataRef data);