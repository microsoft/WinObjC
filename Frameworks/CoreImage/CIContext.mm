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

#include "Starboard.h"
#import <StubReturn.h>
#import <CoreImage/CIContext.h>
#import "CIImageInternal.h"

@implementation CIContext {
    CGContextRef _cgContext;
    CGRect _rect;
}

- (instancetype)init {
    self->_cgContext = nil;
    self->_rect = CGRectInfinite;
    return self;
}

/**
 @Status Stub
*/
+ (CIContext*)contextWithCGContext:(CGContextRef)cgContext options:(NSDictionary*)options {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Caveat
 @Notes parameter dict is ignored.
*/
+ (CIContext*)contextWithOptions:(NSDictionary*)dict {
    CIContext* context = [[CIContext alloc] init];
    return context;
}

/**
 @Status Caveat
 @Notes The options on CIContext are ignored.
*/
- (CGImageRef)createCGImage:(CIImage*)image fromRect:(CGRect)rect {
    return static_cast<CGImageRef>([image _CGImageFromRect:rect]);
}

/**
 @Status Stub
*/
- (void)drawImage:(CIImage*)image atPoint:(CGPoint)atPoint fromRect:(CGRect)fromRect {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)drawImage:(CIImage*)image inRect:(CGRect)inRect fromRect:(CGRect)fromRect {
    UNIMPLEMENTED();
}

@end