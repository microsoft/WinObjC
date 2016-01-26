//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
// Copyright (c) 2006-2007 Christopher J. W. Lloyd
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
#pragma once

#import <Foundation/FoundationExport.h>
#import <Foundation/NSCoding.h>
#import <Foundation/NSCopying.h>
#import <Foundation/NSMutableCopying.h>
#import <Foundation/NSObject.h>

#import <Foundation/NSString.h>
@class NSString;
@class NSData;

#ifdef __cplusplus
namespace icu_48 {
class UnicodeSet;
}
typedef icu_48::UnicodeSet CharacterSet;
#else
typedef void* CharacterSet;
#endif

enum { NSOpenStepUnicodeReservedBase = 0xF400 };

FOUNDATION_EXPORT_CLASS
@interface NSCharacterSet : NSObject <NSCoding, NSCopying, NSMutableCopying> {
@public
    CharacterSet* _icuSet;
}

+ (NSCharacterSet*)alphanumericCharacterSet;
+ (NSCharacterSet*)capitalizedLetterCharacterSet STUB_METHOD;
+ (NSCharacterSet*)controlCharacterSet;
+ (NSCharacterSet*)decimalDigitCharacterSet;
+ (NSCharacterSet*)decomposableCharacterSet;
+ (NSCharacterSet*)illegalCharacterSet;
+ (NSCharacterSet*)letterCharacterSet;
+ (NSCharacterSet*)lowercaseLetterCharacterSet;
+ (NSCharacterSet*)newlineCharacterSet;
+ (NSCharacterSet*)nonBaseCharacterSet;
+ (NSCharacterSet*)punctuationCharacterSet;
+ (NSCharacterSet*)symbolCharacterSet;
+ (NSCharacterSet*)uppercaseLetterCharacterSet;
+ (NSCharacterSet*)whitespaceAndNewlineCharacterSet;
+ (NSCharacterSet*)whitespaceCharacterSet;
+ (NSCharacterSet*)URLFragmentAllowedCharacterSet;
+ (NSCharacterSet*)URLHostAllowedCharacterSet;
+ (NSCharacterSet*)URLPasswordAllowedCharacterSet;
+ (NSCharacterSet*)URLPathAllowedCharacterSet;
+ (NSCharacterSet*)URLQueryAllowedCharacterSet;
+ (NSCharacterSet*)URLUserAllowedCharacterSet;
+ (NSCharacterSet*)characterSetWithCharactersInString:(NSString*)aString;
+ (NSCharacterSet*)characterSetWithRange:(NSRange)aRange;
@property (readonly, copy) NSCharacterSet* invertedSet STUB_PROPERTY;
+ (NSCharacterSet*)characterSetWithBitmapRepresentation:(NSData*)data;
+ (NSCharacterSet*)characterSetWithContentsOfFile:(NSString*)path;
@property (readonly, copy) NSData* bitmapRepresentation STUB_PROPERTY;
- (BOOL)characterIsMember:(unichar)aCharacter;
- (BOOL)hasMemberInPlane:(uint8_t)thePlane;
- (BOOL)isSupersetOfSet:(NSCharacterSet*)theOtherSet;
- (BOOL)longCharacterIsMember:(UTF32Char)theLongChar;
@end
