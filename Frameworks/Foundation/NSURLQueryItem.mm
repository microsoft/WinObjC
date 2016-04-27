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
#import <Foundation/NSURLQueryItem.h>
#import <Foundation/NSCoder.h>

@implementation NSURLQueryItem
/**
 @Status Interoperable
 @Notes
*/
+ (instancetype)queryItemWithName:(NSString*)name value:(NSString*)value {
    return [[[NSURLQueryItem alloc] initWithName:name value:value] autorelease];
}

/**
 @Status Interoperable
 @Notes
*/
- (instancetype)initWithName:(NSString*)name value:(NSString*)value {
    if (self = [super init]) {
        _name = [name copy];
        _value = [value copy];
    }

    return self;
}

/**
 @Status Interoperable
 @Notes
*/
- (id)copyWithZone:(NSZone*)zone {
    // NSURLQueryItem is immutable
    return [self retain];
}

/**
 @Status Interoperable
 @Notes
*/
+ (BOOL)supportsSecureCoding {
    return YES;
}

/**
 @Status Interoperable
 @Notes
*/
- (id)initWithCoder:(NSCoder*)decoder {
    NSString* name = [decoder decodeObjectOfClass:[NSString class] forKey:@"name"];
    NSString* value = [decoder decodeObjectOfClass:[NSString class] forKey:@"value"];

    return [self initWithName:name value:value];
}

/**
 @Status Interoperable
 @Notes
*/
- (void)encodeWithCoder:(NSCoder*)coder {
    [coder encodeObject:_name forKey:@"name"];
    [coder encodeObject:_value forKey:@"value"];
}

/**
 @Status Interoperable
 @Notes
*/
- (NSString*)description {
    return [NSString stringWithFormat:@"%@=%@", _name, _value];
}

- (void)dealloc {
    [_name release];
    [_value release];
    [super dealloc];
}

@end
