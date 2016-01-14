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

#include "Foundation/NSPredicate.h"

@implementation NSPredicate

/**
 @Status Stub
*/
+ (NSPredicate*)predicateWithFormat:(NSString*)format, ... {
    UNIMPLEMENTED();
    return nil;
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
 @Status Stub
*/
+ (NSPredicate*)predicateWithValue:(BOOL)value {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Stub
*/
+ (NSPredicate*)predicateWithBlock:(BOOL (^)(id evaluatedObject, NSDictionary* bindings))block {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Stub
*/
- (BOOL)evaluateWithObject:(id)objecc {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Stub
*/
- (BOOL)evaluateWithObject:(id)object substitutionVariables:(NSDictionary*)variables {
    UNIMPLEMENTED();
    return nil;
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
- (NSString*)predicateFormat {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Stub
*/
- (void)allowEvaluation {
    UNIMPLEMENTED();
}

@end
