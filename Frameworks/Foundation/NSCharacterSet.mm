//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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
#import "StubReturn.h"
#import "Foundation/NSCharacterSet.h"
#import "Foundation/NSMutableCharacterSet.h"
#import "Foundation/NSMutableString.h"
#import "CoreFoundation/CoreFoundation.h"
#import "NSCFCharacterSet.h"
#import "NSRaise.h"

@implementation NSCharacterSet

BASE_CLASS_REQUIRED_IMPLS(NSCharacterSet, NSMutableCharacterSetPrototype, CFCharacterSetGetTypeID);

/**
 @Status Interoperable
*/
+ (instancetype)alphanumericCharacterSet {
    return static_cast<NSCharacterSet*>(CFCharacterSetGetPredefined(kCFCharacterSetAlphaNumeric));
}

/**
 @Status Interoperable
*/
+ (instancetype)capitalizedLetterCharacterSet {
    return static_cast<NSCharacterSet*>(CFCharacterSetGetPredefined(kCFCharacterSetCapitalizedLetter));
}

/**
 @Status Interoperable
*/
+ (instancetype)controlCharacterSet {
    return static_cast<NSCharacterSet*>(CFCharacterSetGetPredefined(kCFCharacterSetControl));
}

/**
 @Status Interoperable
*/
+ (instancetype)decimalDigitCharacterSet {
    return static_cast<NSCharacterSet*>(CFCharacterSetGetPredefined(kCFCharacterSetDecimalDigit));
}

/**
 @Status Interoperable
*/
+ (instancetype)decomposableCharacterSet {
    return static_cast<NSCharacterSet*>(CFCharacterSetGetPredefined(kCFCharacterSetDecomposable));
}

/**
 @Status Interoperable
*/
+ (instancetype)illegalCharacterSet {
    return static_cast<NSCharacterSet*>(CFCharacterSetGetPredefined(kCFCharacterSetIllegal));
}

/**
 @Status Interoperable
*/
+ (instancetype)letterCharacterSet {
    return static_cast<NSCharacterSet*>(CFCharacterSetGetPredefined(kCFCharacterSetLetter));
}

/**
 @Status Interoperable
*/
+ (instancetype)lowercaseLetterCharacterSet {
    return static_cast<NSCharacterSet*>(CFCharacterSetGetPredefined(kCFCharacterSetLowercaseLetter));
}

/**
 @Status Interoperable
*/
+ (instancetype)newlineCharacterSet {
    return static_cast<NSCharacterSet*>(CFCharacterSetGetPredefined(kCFCharacterSetNewline));
}

/**
 @Status Interoperable
*/
+ (instancetype)nonBaseCharacterSet {
    return static_cast<NSCharacterSet*>(CFCharacterSetGetPredefined(kCFCharacterSetNonBase));
}

/**
 @Status Interoperable
*/
+ (instancetype)punctuationCharacterSet {
    return static_cast<NSCharacterSet*>(CFCharacterSetGetPredefined(kCFCharacterSetPunctuation));
}

/**
 @Status Interoperable
*/
+ (instancetype)symbolCharacterSet {
    return static_cast<NSCharacterSet*>(CFCharacterSetGetPredefined(kCFCharacterSetSymbol));
}

/**
 @Status Interoperable
*/
+ (instancetype)uppercaseLetterCharacterSet {
    return static_cast<NSCharacterSet*>(CFCharacterSetGetPredefined(kCFCharacterSetUppercaseLetter));
}

/**
 @Status Interoperable
*/
+ (instancetype)whitespaceAndNewlineCharacterSet {
    return static_cast<NSCharacterSet*>(CFCharacterSetGetPredefined(kCFCharacterSetWhitespaceAndNewline));
}

/**
 @Status Interoperable
*/
+ (instancetype)whitespaceCharacterSet {
    return static_cast<NSCharacterSet*>(CFCharacterSetGetPredefined(kCFCharacterSetWhitespace));
}

/**
 @Status Interoperable
*/
+ (instancetype)URLFragmentAllowedCharacterSet {
    return static_cast<NSCharacterSet*>(_CFURLComponentsGetURLFragmentAllowedCharacterSet());
}

/**
 @Status Interoperable
*/
+ (instancetype)URLHostAllowedCharacterSet {
    return static_cast<NSCharacterSet*>(_CFURLComponentsGetURLHostAllowedCharacterSet());
}

/**
 @Status Interoperable
*/
+ (instancetype)URLPasswordAllowedCharacterSet {
    return static_cast<NSCharacterSet*>(_CFURLComponentsGetURLPasswordAllowedCharacterSet());
}

/**
 @Status Interoperable
*/
+ (instancetype)URLPathAllowedCharacterSet {
    return static_cast<NSCharacterSet*>(_CFURLComponentsGetURLPathAllowedCharacterSet());
}

/**
 @Status Interoperable
*/
+ (instancetype)URLQueryAllowedCharacterSet {
    return static_cast<NSCharacterSet*>(_CFURLComponentsGetURLQueryAllowedCharacterSet());
}

/**
 @Status Interoperable
*/
+ (instancetype)URLUserAllowedCharacterSet {
    return static_cast<NSCharacterSet*>(_CFURLComponentsGetURLUserAllowedCharacterSet());
}

/**
 @Status Interoperable
*/
+ (instancetype)characterSetWithCharactersInString:(NSString*)aString {
    return
        [static_cast<NSCharacterSet*>(CFCharacterSetCreateWithCharactersInString(nullptr, static_cast<CFStringRef>(aString))) autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)characterSetWithRange:(NSRange)aRange {
    return [static_cast<NSCharacterSet*>(CFCharacterSetCreateWithCharactersInRange(nullptr, CFRange{ aRange.location, aRange.length }))
        autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)characterSetWithBitmapRepresentation:(NSData* _Nonnull)data {
    return [static_cast<NSCharacterSet*>(CFCharacterSetCreateWithBitmapRepresentation(nullptr, static_cast<CFDataRef>(data))) autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)characterSetWithContentsOfFile:(NSString* _Nonnull)path {
    return [NSCharacterSet characterSetWithBitmapRepresentation:[NSData dataWithContentsOfFile:path]];
}

/**
 @Status Interoperable
*/
- (BOOL)characterIsMember:(unichar)member {
    // NSCharacterSet is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (BOOL)isSupersetOfSet:(NSCharacterSet*)set {
    // NSCharacterSet is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (instancetype)copyWithZone:(NSZone*)zone {
    return [self retain];
}

/**
 @Status Interoperable
*/
- (instancetype)mutableCopyWithZone:(NSZone*)zone {
    NSMutableCharacterSet* toRet = [NSMutableCharacterSet new];
    [toRet formUnionWithCharacterSet:self];

    return toRet;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithCoder:(NSCoder*)coder {
    if (self = [super init]) {
        self = [[NSCharacterSet
            characterSetWithBitmapRepresentation:[coder decodeObjectOfClass:[NSData class] forKey:@"bitmapRepresentation"]] retain];
    }
    return self;
}

/**
 @Status Interoperable
*/
- (void)encodeWithCoder:(NSCoder*)coder {
    [coder encodeObject:[self bitmapRepresentation] forKey:@"bitmapRepresentation"];
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
- (BOOL)longCharacterIsMember:(UTF32Char)theLongChar {
    // NSCharacterSet is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Stub
*/
- (BOOL)hasMemberInPlane:(uint8_t)thePlane {
    // NSCharacterSet is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
 */
- (NSCharacterSet*)invertedSet {
    NSMutableCharacterSet* toRet = [self mutableCopy];
    [toRet invert];

    return toRet;
}

/**
 @Status Interoperable
*/
- (NSData*)bitmapRepresentation {
    // NSCharacterSet is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocationReturn();
}

@end
