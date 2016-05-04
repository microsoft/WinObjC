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

#import "Starboard.h"
#import "Foundation/NSMutableCharacterSet.h"
#import "Foundation/NSMutableString.h"

#import "unicode/uniset.h"
#include "NSRaise.h"
#include "NSCFCharacterSet.h"

@implementation NSMutableCharacterSet

+ ALLOC_PROTOTYPE_SUBCLASS_WITH_ZONE(NSMutableCharacterSet, NSMutableCharacterSetPrototype);

+ (instancetype)alphanumericCharacterSet {
    return [[NSCharacterSet alphanumericCharacterSet] mutableCopy];
}

+ (instancetype)capitalizedLetterCharacterSet {
    return [[NSCharacterSet capitalizedLetterCharacterSet] mutableCopy];
}

+ (instancetype)controlCharacterSet {
    return [[NSCharacterSet controlCharacterSet] mutableCopy];
}

+ (instancetype)decimalDigitCharacterSet {
    return [[NSCharacterSet decimalDigitCharacterSet] mutableCopy];
}

+ (instancetype)decomposableCharacterSet {
    return [[NSCharacterSet decomposableCharacterSet] mutableCopy];
}

+ (instancetype)illegalCharacterSet {
    return [[NSCharacterSet illegalCharacterSet] mutableCopy];
}

+ (instancetype)letterCharacterSet {
    return [[NSCharacterSet letterCharacterSet] mutableCopy];
}

+ (instancetype)lowercaseLetterCharacterSet {
    return [[NSCharacterSet lowercaseLetterCharacterSet] mutableCopy];
}

+ (instancetype)newlineCharacterSet {
    return [[NSCharacterSet newlineCharacterSet] mutableCopy];
}

+ (instancetype)nonBaseCharacterSet {
    return [[NSCharacterSet nonBaseCharacterSet] mutableCopy];
}

+ (instancetype)punctuationCharacterSet {
    return [[NSCharacterSet punctuationCharacterSet] mutableCopy];
}

+ (instancetype)symbolCharacterSet {
    return [[NSCharacterSet symbolCharacterSet] mutableCopy];
}

+ (instancetype)uppercaseLetterCharacterSet {
    return [[NSCharacterSet uppercaseLetterCharacterSet] mutableCopy];
}

+ (instancetype)whitespaceAndNewlineCharacterSet {
    return [[NSCharacterSet whitespaceAndNewlineCharacterSet] mutableCopy];
}

+ (instancetype)whitespaceCharacterSet {
    return [[NSCharacterSet whitespaceCharacterSet] mutableCopy];
}

+ (instancetype)URLFragmentAllowedCharacterSet {
    return [[NSCharacterSet URLFragmentAllowedCharacterSet] mutableCopy];
}

+ (instancetype)URLHostAllowedCharacterSet {
    return [[NSCharacterSet URLHostAllowedCharacterSet] mutableCopy];
}

+ (instancetype)URLPasswordAllowedCharacterSet {
    return [[NSCharacterSet URLPasswordAllowedCharacterSet] mutableCopy];
}

+ (instancetype)URLPathAllowedCharacterSet {
    return [[NSCharacterSet URLPathAllowedCharacterSet] mutableCopy];
}

+ (instancetype)URLQueryAllowedCharacterSet {
    return [[NSCharacterSet URLQueryAllowedCharacterSet] mutableCopy];
}

+ (instancetype)URLUserAllowedCharacterSet {
    return [[NSCharacterSet URLUserAllowedCharacterSet] mutableCopy];
}

+ (instancetype)characterSetWithCharactersInString:(NSString*)aString {
    return [[NSCharacterSet characterSetWithCharactersInString:aString] mutableCopy];
}

+ (instancetype)characterSetWithRange:(NSRange)aRange {
    return [[NSCharacterSet characterSetWithRange:aRange] mutableCopy];
}

+ (instancetype)characterSetWithBitmapRepresentation:(NSData*)data {
    return [[NSCharacterSet characterSetWithBitmapRepresentation:data] mutableCopy];
}

+ (instancetype)characterSetWithContentsOfFile:(NSString*)path {
    return [[NSCharacterSet characterSetWithContentsOfFile:path] mutableCopy];
}

/**
 @Status Interoperable
*/
- (void)addCharactersInRange:(NSRange)range {
    // NSMutableCharacterSet is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocation();
}

/**
 @Status Interoperable
*/
- (void)removeCharactersInRange:(NSRange)range {
    // NSMutableCharacterSet is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocation();
}

/**
 @Status Interoperable
*/
- (void)invert {
    // NSMutableCharacterSet is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocation();
}

/**
 @Status Interoperable
*/
- (void)addCharactersInString:(NSString*)str {
    // NSMutableCharacterSet is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocation();
}

/**
 @Status Interoperable
*/
- (void)removeCharactersInString:(NSString*)str {
    // NSMutableCharacterSet is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocation();
}

/**
 @Status Interoperable
*/
- (void)formUnionWithCharacterSet:(NSCharacterSet*)other {
    // NSMutableCharacterSet is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocation();
}

/**
 @Status Interoperable
*/
- (void)formIntersectionWithCharacterSet:(NSCharacterSet*)other {
    // NSMutableCharacterSet is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocation();
}

@end
