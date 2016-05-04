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

#include "StubReturn.h"
#include "Foundation/Foundation.h"
#include "Foundation/NSObjCRuntime.h"
#include "Foundation/NSArray.h"
#include "Foundation/NSPathUtilities.h"

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
 @Status Stub
 @Notes
*/
NSString* NSStringFromProtocol(Protocol* proto) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
Protocol* NSProtocolFromString(NSString* namestr) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
const char* NSGetSizeAndAlignment(const char* typePtr, NSUInteger* sizep, NSUInteger* alignp) {
    UNIMPLEMENTED();
    return StubReturn();
}
