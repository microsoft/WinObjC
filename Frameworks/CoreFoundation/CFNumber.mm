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

struct CFStaticNumber {
    id* isa;
    NSValueType _valueType;
    union {
        uint64_t i;
        double f;
    } val;
    NSNumberType type;
    const char* objCType;
    bool isBool;
};

static CFStaticNumber cftrue = { NULL,
                                 NSValueTypeUnknown,
                                 {
                                     1,
                                 },
                                 integerType,
                                 "c",
                                 true };

static CFStaticNumber cffalse = { NULL,
                                  NSValueTypeUnknown,
                                  {
                                      0,
                                  },
                                  integerType,
                                  "c",
                                  true };

const CFBooleanRef kCFBooleanTrue = (const CFBooleanRef)&cftrue;
const CFBooleanRef kCFBooleanFalse = (const CFBooleanRef)&cffalse;

COREFOUNDATION_EXPORT Boolean CFBooleanGetValue(CFBooleanRef boolean) {
    return [static_cast<id>(kCFBooleanTrue) isEqualToNumber:static_cast<NSNumber*>(boolean)];
}
