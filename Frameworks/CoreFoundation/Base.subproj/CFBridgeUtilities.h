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

// WINOBJC: The following functions/macros are separated into this header, so that their code can be more broadly reused among the other
// Core* (CoreText, CoreGraphics) frameworks with bridged types.

#pragma once

#if !defined(CF_PRIVATE)
#define CF_PRIVATE __attribute__((__visibility__("hidden")))
#endif

CF_EXTERN_C_BEGIN
CF_PRIVATE void _CFRuntimeBridgeTypeToClass(CFTypeID type, const void* isa);
CF_PRIVATE uintptr_t __CFISAForTypeID(CFTypeID typeID);

// WINOBJC:
// Because registration happens at runtime, static constant CFStrings don't have yet have type ids in the class table when initialized
// NSCFString thus requires explicit handling below
// The reference platform uses a special compiler option not available to us to
// get __CFConstantStringClassReferencePtr filled out with the correct "Class". Since this isn't
// an option here, use &_OBJC_CLASS__NSCFString instead.
// CF_EXPORT void * __CFConstantStringClassReferencePtrPtr;
// CF_EXPORT void *__CFConstantStringClassReferencePtr[];
CF_EXPORT Class _OBJC_CLASS__NSCFString;

// For bridged classes, which under certain circumstances, dispatch a function from C side to Objective-C side
#define CF_OBJC_FUNCDISPATCHV(type, ret, obj, ...)         \
    do {                                                   \
        if (CF_IS_OBJC(type, obj)) {                       \
            return (ret)CF_OBJC_CALLV(obj, ##__VA_ARGS__); \
        }                                                  \
    } while (0)

#define CF_OBJC_CALLV(obj, ...) [(obj)__VA_ARGS__]

// easier to read without clang-format here
// clang-format off
#define CF_IS_OBJC(typeID, obj) ( \
    (!obj) || \
    ((((CFRuntimeBase*)(obj))->_cfisa != 0) && \
    (((CFRuntimeBase*)(obj))->_cfisa != (uintptr_t)(&_OBJC_CLASS__NSCFString)) && \
    (__CFISAForTypeID(typeID) != ((CFRuntimeBase*)(obj))->_cfisa) && \
    (![(id)(((CFRuntimeBase*)(obj)))->_cfisa isSubclassOfClass:(Class)__CFISAForTypeID(typeID)])))
// clang-format on

// For debugging C-style classes
#if defined(DEBUG)
extern void __CFGenericValidateType_(CFTypeRef cf, CFTypeID type, const char* func);
#define __CFGenericValidateType(cf, type) __CFGenericValidateType_(cf, type, __PRETTY_FUNCTION__)
#else
#define __CFGenericValidateType(cf, type) ((void)0)
#endif

CF_EXTERN_C_END