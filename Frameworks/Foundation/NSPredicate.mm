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

#import <Starboard.h>
#import <Foundation/NSPredicate.h>
#import "NSBooleanPredicate.h"

@implementation NSPredicate {
    BOOL (^_evaluationBlock)(id evaluatedObject, NSDictionary* bindings);
}

/**
 @Status Stub
*/
+ (NSPredicate*)predicateWithFormat:(NSString*)format, ... {
    va_list args;
    va_start(args, format);
    NSPredicate* predicate = [self predicateWithFormat:format arguments:args];
    va_end(args);

    return predicate;
}

/**
 @Status Stub
*/
+ (NSPredicate*)predicateWithFormat:(NSString*)format argumentArray:(NSArray*)arguments {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Stub
*/
+ (NSPredicate*)predicateWithFormat:(NSString*)format arguments:(va_list)arguments {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Interoperable
*/
+ (NSPredicate*)predicateWithValue:(BOOL)value {
    return [[[NSBooleanPredicate alloc] initWithValue:value] autorelease];
}

/**
 @Status Interoperable
*/
+ (NSPredicate*)predicateWithBlock:(BOOL (^)(id evaluatedObject, NSDictionary* bindings))block {
    return [[[NSPredicate alloc] _initWithBlock:block] autorelease];
}

- (instancetype)_initWithBlock:(BOOL (^)(id evaluatedObject, NSDictionary* bindings))block {
    if (self = [super init]) {
        _evaluationBlock = [block copy];
    }
    return self;
}

/**
 @Status Caveat
 @Notes: Only block evaluation is supported.
*/
- (BOOL)evaluateWithObject:(id)object {
    return [self evaluateWithObject:object substitutionVariables:nil];
}

/**
 @Status Caveat
 @Notes: Only block evaluation is supported.
*/
- (BOOL)evaluateWithObject:(id)object substitutionVariables:(NSDictionary*)variables {
    if (_evaluationBlock) {
        return _evaluationBlock(object, variables);
    }
    return NO;
}

/**
 @Status Stub
*/
- (instancetype)predicateWithSubstitutionVariables:(NSDictionary*)variables {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Stub
*/
- (void)allowEvaluation {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
- (id)copyWithZone:(NSZone*)zone {
    return [self retain];
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
- (instancetype)initWithCoder:(NSCoder*)decoder {
    if (self = [super init]) {
        _predicateFormat = [[decoder decodeObjectOfClass:[NSString class] forKey:@"predicateFormat"] retain];
    }

    return self;
}

/**
 @Status Interoperable
*/
- (void)encodeWithCoder:(NSCoder*)encoder {
    if (_evaluationBlock) {
        THROW_NS_HR_MSG(E_FAIL, "NSPredicate with a block cannot be encoded.");
    }
    if (_predicateFormat) {
        [encoder encodeObject:_predicateFormat forKey:@"predicateFormat"];
    }
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    [_predicateFormat release];
    [_evaluationBlock release];
    [super dealloc];
}

@end
