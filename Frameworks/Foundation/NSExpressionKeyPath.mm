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

#import "NSExpressionKeyPath.h"
#import <Foundation/NSCoder.h>
#import <Foundation/NSKeyValueCoding.h>

@implementation NSExpressionKeyPath {
    NSString* _keyPath;
}

// Prevent compiler from auto synthesizing this property.
@dynamic keyPath;

/**
 @Status Interoperable
*/
- (id)initWithKeyPath:(NSString*)keyPath {
    if (self = [super initWithExpressionType:NSKeyPathExpressionType]) {
        _keyPath = [keyPath copy];
    }

    return self;
}

/**
 @Status Interoperable
*/
- (id)expressionValueWithObject:(id)object context:(NSMutableDictionary*)context {
    return [object valueForKeyPath:_keyPath];
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
- (void)encodeWithCoder:(NSCoder*)encoder {
    [encoder encodeObject:_keyPath forKey:@"keyPath"];
    [super encodeWithCoder:encoder];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithCoder:(NSCoder*)decoder {
    if (self = [super initWithCoder:decoder]) {
        _keyPath = [[decoder decodeObjectOfClass:[NSString class] forKey:@"keyPath"] retain];
    }
    return self;
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    [_keyPath release];
    [super dealloc];
}

@end