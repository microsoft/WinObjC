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
    return [[[NSCharacterSet alphanumericCharacterSet] mutableCopy] autorelease];
}

+ (instancetype)capitalizedLetterCharacterSet {
    return [[[NSCharacterSet capitalizedLetterCharacterSet] mutableCopy] autorelease];
}

+ (instancetype)controlCharacterSet {
    return [[[NSCharacterSet controlCharacterSet] mutableCopy] autorelease];
}

+ (instancetype)decimalDigitCharacterSet {
    return [[[NSCharacterSet decimalDigitCharacterSet] mutableCopy] autorelease];
}

+ (instancetype)decomposableCharacterSet {
    return [[[NSCharacterSet decomposableCharacterSet] mutableCopy] autorelease];
}

+ (instancetype)illegalCharacterSet {
    return [[[NSCharacterSet illegalCharacterSet] mutableCopy] autorelease];
}

+ (instancetype)letterCharacterSet {
    return [[[NSCharacterSet letterCharacterSet] mutableCopy] autorelease];
}

+ (instancetype)lowercaseLetterCharacterSet {
    return [[[NSCharacterSet lowercaseLetterCharacterSet] mutableCopy] autorelease];
}

+ (instancetype)newlineCharacterSet {
    return [[[NSCharacterSet newlineCharacterSet] mutableCopy] autorelease];
}

+ (instancetype)nonBaseCharacterSet {
    return [[[NSCharacterSet nonBaseCharacterSet] mutableCopy] autorelease];
}

+ (instancetype)punctuationCharacterSet {
    return [[[NSCharacterSet punctuationCharacterSet] mutableCopy] autorelease];
}

+ (instancetype)symbolCharacterSet {
    return [[[NSCharacterSet symbolCharacterSet] mutableCopy] autorelease];
}

+ (instancetype)uppercaseLetterCharacterSet {
    return [[[NSCharacterSet uppercaseLetterCharacterSet] mutableCopy] autorelease];
}

+ (instancetype)whitespaceAndNewlineCharacterSet {
    return [[[NSCharacterSet whitespaceAndNewlineCharacterSet] mutableCopy] autorelease];
}

+ (instancetype)whitespaceCharacterSet {
    return [[[NSCharacterSet whitespaceCharacterSet] mutableCopy] autorelease];
}

+ (instancetype)URLFragmentAllowedCharacterSet {
    return [[[NSCharacterSet URLFragmentAllowedCharacterSet] mutableCopy] autorelease];
}

+ (instancetype)URLHostAllowedCharacterSet {
    return [[[NSCharacterSet URLHostAllowedCharacterSet] mutableCopy] autorelease];
}

+ (instancetype)URLPasswordAllowedCharacterSet {
    return [[[NSCharacterSet URLPasswordAllowedCharacterSet] mutableCopy] autorelease];
}

+ (instancetype)URLPathAllowedCharacterSet {
    return [[[NSCharacterSet URLPathAllowedCharacterSet] mutableCopy] autorelease];
}

+ (instancetype)URLQueryAllowedCharacterSet {
    return [[[NSCharacterSet URLQueryAllowedCharacterSet] mutableCopy] autorelease];
}

+ (instancetype)URLUserAllowedCharacterSet {
    return [[[NSCharacterSet URLUserAllowedCharacterSet] mutableCopy] autorelease];
}

+ (instancetype)characterSetWithCharactersInString:(NSString*)aString {
    return [[[NSCharacterSet characterSetWithCharactersInString:aString] mutableCopy] autorelease];
}

+ (instancetype)characterSetWithRange:(NSRange)aRange {
    return [[[NSCharacterSet characterSetWithRange:aRange] mutableCopy] autorelease];
}

+ (instancetype)characterSetWithBitmapRepresentation:(NSData*)data {
    return [[[NSCharacterSet characterSetWithBitmapRepresentation:data] mutableCopy] autorelease];
}

+ (instancetype)characterSetWithContentsOfFile:(NSString*)path {
    return [[[NSCharacterSet characterSetWithContentsOfFile:path] mutableCopy] autorelease];
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
