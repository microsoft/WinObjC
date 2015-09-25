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
#include "Foundation/NSNull.h"

static NSNull* nullSingleton;

@implementation NSNull : NSObject
+ (void)initialize {
    if (self == [NSNull class]) {
        nullSingleton = [super allocWithZone:nil];
    }
}

- (instancetype)initWithCoder:(NSCoder*)coder {
    return self;
}

- (void)encodeWithCoder:(NSCoder*)coder {
}

- (instancetype)copyWithZone:(NSZone*)zone {
    return nullSingleton;
}

+ (instancetype)allocWithZone:(NSZone*)zone {
    return nullSingleton;
}

- (oneway void)release {
}

- (instancetype)retain {
    return self;
}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wobjc-missing-super-calls"
- (void)dealloc {
    assert(0 && "NSNull should never be deallocated");
}
#pragma clang diagnostic pop

- (NSString*)description {
    return @"<null>";
}

+ (NSNull*)null {
    return nullSingleton;
}
@end
