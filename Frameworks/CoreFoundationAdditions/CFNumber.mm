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

#import "Starboard.h"
#import <CoreFoundation/CoreFoundation.h>
#import <Foundation/Foundation.h>
#import <CoreGraphics/CGAffineTransform.h>
#import <QuartzCore/CATransform3D.h>

/**
 @Status Stub
 @Notes Asserts a failure - CF*GetType needs implementation
*/
CFNumberType CFNumberGetType(CFNumberRef self) {
    UNIMPLEMENTED();
    return kCFNumberIntType;
}

extern "C" id _OBJC_CLASS_NSCFBoolean;

// This needs to be bitwise identical to the layout of NSNumber and all its superclasses
// Static initialization order makes it so that we cannot create NSNumber instances at this time
// TODO: 5403859 - this struct can be removed at that time
struct CFStaticNumber {
    id* isa;
    NSValueType _valueType;
    union {
        uint64_t i;
        double f;
    } val;
    const char* _objCType;
    BOOL _isBool;
};

static CFStaticNumber cftrue = { NULL,
                                 NSValueTypeUnknown,
                                 {
                                     1,
                                 },
                                 "c",
                                 YES };

static CFStaticNumber cffalse = { NULL,
                                  NSValueTypeUnknown,
                                  {
                                      0,
                                  },
                                  "c",
                                  YES };

const CFBooleanRef kCFBooleanTrue = (const CFBooleanRef)&cftrue;
const CFBooleanRef kCFBooleanFalse = (const CFBooleanRef)&cffalse;

extern "C" Boolean CFBooleanGetValue(CFBooleanRef boolean) {
    return [static_cast<id>(kCFBooleanTrue) isEqualToNumber:static_cast<NSNumber*>(boolean)];
}
