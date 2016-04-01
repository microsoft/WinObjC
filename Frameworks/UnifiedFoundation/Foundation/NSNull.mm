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
#include "StubReturn.h"
#include "Foundation/NSNull.h"

static NSNull* nullSingleton;

@implementation NSNull
/**
 @Status Interoperable
*/
+ (void)initialize {
    if (self == [NSNull class]) {
        nullSingleton = [super allocWithZone:nil];
    }
}

/**
 @Status Interoperable
*/
- (instancetype)initWithCoder:(NSCoder*)coder {
    return self;
}

/**
 @Status Stub
 @Notes
 */
- (void)encodeWithCoder:(NSCoder*)coder {
    UNIMPLEMENTED();
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
+ (instancetype)allocWithZone:(NSZone*)zone {
    return nullSingleton;
}

/**
 @Status Interoperable
*/
- (oneway void)release {
}

/**
 @Status Interoperable
*/
- (instancetype)retain {
    return self;
}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wobjc-missing-super-calls"
/**
 @Status Interoperable
*/
- (void)dealloc {
    assert(0 && "NSNull should never be deallocated");
}
#pragma clang diagnostic pop

/**
 @Status Interoperable
*/
- (NSString*)description {
    return @"<null>";
}

/**
 @Status Interoperable
*/
+ (NSNull*)null {
    return nullSingleton;
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
