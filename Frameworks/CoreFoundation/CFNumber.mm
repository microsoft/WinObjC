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

#import <CoreFoundation/CoreFoundation.h>
#import <Foundation/Foundation.h>
#import <CoreGraphics/CGAffineTransform.h>
#import <QuartzCore/CATransform3D.h>

CFNumberType CFNumberGetType(CFNumberRef self) {
    assert(0);
    return kCFNumberIntType;
}

extern "C" id _OBJC_CLASS_NSCFBoolean;

struct CFStaticNumber {
    id* isa;
    NSValueType _valueType;

    union {
        CGPoint pointValue;
        CGSize sizeValue;
        CGRect rectValue;
        CATransform3D transformValue;
        CGAffineTransform affineTransformValue;
        void* pointerValue;
        objcValue genericValue;
    } v;
    union {
        uint64_t i;
        double f;
    } val;
    NSNumberType type;
    const char* objCType;
    bool isBool;
};

static CFStaticNumber cftrue = { NULL,
                                 notSetType,
                                 {},
                                 {
                                     1,
                                 },
                                 integerType,
                                 "c",
                                 true };

static CFStaticNumber cffalse = { NULL,
                                  notSetType,
                                  {},
                                  {
                                      0,
                                  },
                                  integerType,
                                  "c",
                                  true };

const CFBooleanRef kCFBooleanTrue = (const CFBooleanRef)&cftrue;
const CFBooleanRef kCFBooleanFalse = (const CFBooleanRef)&cffalse;
