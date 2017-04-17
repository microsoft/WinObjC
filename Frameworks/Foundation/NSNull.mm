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

#import <Foundation/NSNull.h>

static NSNull* nullSingleton;

@implementation NSNull
/**
 @Status Interoperable
*/
+ (void)initialize {
    if (self == [NSNull class]) {
        nullSingleton = [super allocWithZone:nullptr];
    }
}

/**
 @Status Interoperable
*/
+ (instancetype)allocWithZone:(NSZone*)zone {
    return nullSingleton;
}

/**
 @Status Interoperable
*/
+ (NSNull*)null {
    return nullSingleton;
}

/**
 @Status Interoperable
*/
+ (BOOL)supportsSecureCoding {
    return YES;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithCoder:(NSCoder*)coder {
    return self;
}

/**
 @Status Interoperable
 @Notes This method encodes nothing as there's nothing to encode.
 */
- (void)encodeWithCoder:(NSCoder*)coder {
}

/**
 @Status Interoperable
*/
- (instancetype)copyWithZone:(NSZone*)zone {
    return nullSingleton;
}

/**
 @Status Interoperable
*/
- (instancetype)retain {
    return self;
}

/**
 @Status Interoperable
*/
- (oneway void)release {
}

- (NSUInteger)retainCount {
    return NSUIntegerMax;
}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wobjc-missing-super-calls"
/**
 @Status Interoperable
*/
- (void)dealloc {
    // This method was found to be a no-op on the reference platform.
}
#pragma clang diagnostic pop

/**
 @Status Interoperable
*/
- (NSString*)description {
    return @"<null>";
}
@end
