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
#import <CoreImage/CIImageAccumulator.h>

@implementation CIImageAccumulator
/**
 @Status Stub
 @Notes
*/
+ (instancetype)imageAccumulatorWithExtent:(CGRect)extent format:(CIFormat)format {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (instancetype)imageAccumulatorWithExtent:(CGRect)extent format:(CIFormat)format colorSpace:(CGColorSpaceRef)colorSpace {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithExtent:(CGRect)extent format:(CIFormat)format {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithExtent:(CGRect)extent format:(CIFormat)format colorSpace:(CGColorSpaceRef)colorSpace {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)setImage:(CIImage*)im {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)setImage:(CIImage*)im dirtyRect:(CGRect)r {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (CIImage*)image {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)clear {
    UNIMPLEMENTED();
}

@end
