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
#import <CoreImage/CISampler.h>

NSString* const kCISamplerAffineMatrix = @"kCISamplerAffineMatrix";
NSString* const kCISamplerWrapMode = @"kCISamplerWrapMode";
NSString* const kCISamplerFilterMode = @"kCISamplerFilterMode";
NSString* const kCISamplerColorSpace = @"kCISamplerColorSpace";
NSString* const kCISamplerWrapBlack = @"kCISamplerWrapBlack";
NSString* const kCISamplerWrapClamp = @"kCISamplerWrapClamp";
NSString* const kCISamplerFilterNearest = @"kCISamplerFilterNearest";
NSString* const kCISamplerFilterLinear = @"kCISamplerFilterLinear";

@implementation CISampler
/**
 @Status Stub
 @Notes
*/
+ (instancetype)samplerWithImage:(CIImage*)im {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (instancetype)samplerWithImage:(CIImage*)im keysAndValues:(id)key0 {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (instancetype)samplerWithImage:(CIImage*)im options:(NSDictionary*)dict {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithImage:(CIImage*)im {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithImage:(CIImage*)im keysAndValues:(id)key0 {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithImage:(CIImage*)im options:(NSDictionary*)dict {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (id)copyWithZone:(NSZone*)zone {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
