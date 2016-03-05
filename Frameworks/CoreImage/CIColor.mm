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

#import <StubReturn.h>
#import <CoreImage/CIColor.h>

@implementation CIColor

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
*/
+ (CIColor*)colorWithCGColor:(CGColorRef)cgColor {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (CGColorSpaceRef)colorSpace {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (const CGFloat*)components {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (instancetype)initWithCGColor:(CGColorRef)cgColor {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
- (instancetype)initWithRed:(CGFloat)red green:(CGFloat)green blue:(CGFloat)blue {
    return [self initWithRed:red green:green blue:blue alpha:1.0f];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithRed:(CGFloat)red green:(CGFloat)green blue:(CGFloat)blue alpha:(CGFloat)alpha {
    self->_red = red;
    self->_green = green;
    self->_blue = blue;
    self->_alpha = alpha;
    return self;
}

/**
 @Status Interoperable
*/
+ (instancetype)colorWithRed:(CGFloat)red green:(CGFloat)green blue:(CGFloat)blue {
    return [CIColor colorWithRed:red green:green blue:blue alpha:1.0f];
}

/**
 @Status Interoperable
*/
+ (instancetype)colorWithRed:(CGFloat)red green:(CGFloat)green blue:(CGFloat)blue alpha:(CGFloat)alpha {
    CIColor* ret = [[self alloc] initWithRed:red green:green blue:blue alpha:alpha];

    return [ret autorelease];
}

/**
 @Status Stub
*/
- (size_t)numberOfComponents {
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
*/
+ (BOOL)supportsSecureCoding {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (instancetype)initWithCoder:(NSCoder*)decoder {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (void)encodeWithCoder:(NSCoder*)encoder {
    UNIMPLEMENTED();
}

@end
