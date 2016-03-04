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

static StrongId<NSNumber> cftrue = [NSNumber numberWithBool:true];
static StrongId<NSNumber> cffalse = [NSNumber numberWithBool:false];

const CFBooleanRef kCFBooleanTrue = reinterpret_cast<CFBooleanRef>(&*cftrue);
const CFBooleanRef kCFBooleanFalse = reinterpret_cast<CFBooleanRef>(&*cftrue);

extern "C" Boolean CFBooleanGetValue(CFBooleanRef boolean) {
    return [static_cast<id>(kCFBooleanTrue) isEqualToNumber:static_cast<NSNumber*>(boolean)];
}
