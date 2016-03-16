//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#import <StubReturn.h>
#import <CoreImage/CIColor.h>

#import "CIImageInternal.h"

@implementation CIColor

/**
 @Status Interoperable
*/
- (CIColor*)init {
    if (self = [super init]) {
        self->_red = 0.0f;
        self->_green = 0.0f;
        self->_blue = 0.0f;
        self->_alpha = 1.0f;
    }

    return self;
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithCGColor:(CGColorRef)c {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithColor:(UIColor*)color {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
- (instancetype)initWithRed:(CGFloat)r green:(CGFloat)g blue:(CGFloat)b {
    return [self initWithRed:r green:g blue:b alpha:1.0f];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithRed:(CGFloat)r green:(CGFloat)g blue:(CGFloat)b alpha:(CGFloat)a {
    self->_red = r;
    self->_green = g;
    self->_blue = b;
    self->_alpha = a;
    return self;
}

/**
 @Status Stub
 @Notes
*/
+ (instancetype)colorWithCGColor:(CGColorRef)c {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
+ (instancetype)colorWithRed:(CGFloat)r green:(CGFloat)g blue:(CGFloat)b {
    return [CIColor colorWithRed:r green:g blue:b alpha:1.0f];
}

/**
 @Status Interoperable
*/
+ (instancetype)colorWithRed:(CGFloat)r green:(CGFloat)g blue:(CGFloat)b alpha:(CGFloat)a {
    CIColor* ret = [[self alloc] initWithRed:r green:g blue:b alpha:a];
    return [ret autorelease];
}

/**
 @Status Stub
 @Notes
*/
+ (instancetype)colorWithString:(NSString*)representation {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Caveat
 @ Notes Currently does not have complete implementation for CIColor class.
         We simply copy what is currently implemented.
*/
- (id)copyWithZone:(NSZone*)zone {
    return [[[CIColor class] allocWithZone:zone] initWithRed:_red green:_green blue:_blue alpha:_alpha];
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithCoder:(NSCoder*)decoder {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)encodeWithCoder:(NSCoder*)encoder {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
+ (BOOL)supportsSecureCoding {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
