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
#import <QuartzCore/CAValueFunction.h>

NSString* const kCAValueFunctionRotateX = @"kCAValueFunctionRotateX";
NSString* const kCAValueFunctionRotateY = @"kCAValueFunctionRotateY";
NSString* const kCAValueFunctionRotateZ = @"kCAValueFunctionRotateZ";
NSString* const kCAValueFunctionScale = @"kCAValueFunctionScale";
NSString* const kCAValueFunctionScaleX = @"kCAValueFunctionScaleX";
NSString* const kCAValueFunctionScaleY = @"kCAValueFunctionScaleY";
NSString* const kCAValueFunctionScaleZ = @"kCAValueFunctionScaleZ";
NSString* const kCAValueFunctionTranslate = @"kCAValueFunctionTranslate";
NSString* const kCAValueFunctionTranslateX = @"kCAValueFunctionTranslateX";
NSString* const kCAValueFunctionTranslateY = @"kCAValueFunctionTranslateY";
NSString* const kCAValueFunctionTranslateZ = @"kCAValueFunctionTranslateZ";

@implementation CAValueFunction
/**
 @Status Stub
 @Notes
*/
+ (instancetype)functionWithName:(NSString*)name {
    UNIMPLEMENTED();
    return StubReturn();
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

@end
