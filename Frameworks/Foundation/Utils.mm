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

#include "Foundation/Foundation.h"
#include "Foundation/NSObjCRuntime.h"
#include "Foundation/NSArray.h"
#include "Foundation/NSPathUtilities.h"

#include <objc/encoding.h>

const double NSFoundationVersionNumber = NSFoundationVersionNumber_iOS_8_3;

/**
 @Status Interoperable
*/
Class NSClassFromString(NSString* name) {
    return objc_getClass([name UTF8String]);
}

/**
 @Status Interoperable
*/
SEL NSSelectorFromString(NSString* str) {
    return sel_registerName([str UTF8String]);
}

/**
 @Status Interoperable
*/
NSString* NSStringFromClass(Class cls) {
    if (!cls) {
        return nil;
    }
    return [NSString stringWithUTF8String:object_getClassName(cls)];
}

/**
 @Status Interoperable
*/
NSString* NSStringFromSelector(SEL sel) {
    NSString* ret = [NSString stringWithCString:sel_getName(sel)];
    return ret;
}

/**
 @Status Interoperable
*/
NSString* NSStringFromProtocol(Protocol* proto) {
    return proto ? [NSString stringWithCString:protocol_getName(proto)] : @"nil";
}

/**
 @Status Interoperable
*/
Protocol* NSProtocolFromString(NSString* name) {
    return objc_getProtocol([name UTF8String]);
}

/**
 @Status Interoperable
*/
const char* NSGetSizeAndAlignment(const char* type, NSUInteger* sizep, NSUInteger* alignp) {
    if (sizep) {
        *sizep = objc_sizeof_type(type);
    }

    if (alignp) {
        *alignp = objc_alignof_type(type);
    }

    return objc_skip_typespec(type);
}
