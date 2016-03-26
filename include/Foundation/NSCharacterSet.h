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
#import <Foundation/NSObject.h>

#import <Foundation/NSString.h>
@class NSString;
@class NSData;

enum { NSOpenStepUnicodeReservedBase = 0xF400 };

FOUNDATION_EXPORT_CLASS
@interface NSCharacterSet : NSObject <NSCoding, NSCopying, NSMutableCopying>
+ (instancetype)alphanumericCharacterSet;
+ (instancetype)capitalizedLetterCharacterSet;
+ (instancetype)controlCharacterSet;
+ (instancetype)decimalDigitCharacterSet;
+ (instancetype)decomposableCharacterSet;
+ (instancetype)illegalCharacterSet;
+ (instancetype)letterCharacterSet;
+ (instancetype)lowercaseLetterCharacterSet;
+ (instancetype)newlineCharacterSet;
+ (instancetype)nonBaseCharacterSet;
+ (instancetype)punctuationCharacterSet;
+ (instancetype)symbolCharacterSet;
+ (instancetype)uppercaseLetterCharacterSet;
+ (instancetype)whitespaceAndNewlineCharacterSet;
+ (instancetype)whitespaceCharacterSet;
+ (instancetype)URLFragmentAllowedCharacterSet;
+ (instancetype)URLHostAllowedCharacterSet;
+ (instancetype)URLPasswordAllowedCharacterSet;
+ (instancetype)URLPathAllowedCharacterSet;
+ (instancetype)URLQueryAllowedCharacterSet;
+ (instancetype)URLUserAllowedCharacterSet;
+ (instancetype)characterSetWithCharactersInString:(NSString*)aString;
+ (instancetype)characterSetWithRange:(NSRange)aRange;
+ (instancetype)characterSetWithBitmapRepresentation:(NSData*)data;
+ (instancetype)characterSetWithContentsOfFile:(NSString*)path;
- (BOOL)characterIsMember:(unichar)aCharacter;
- (BOOL)hasMemberInPlane:(uint8_t)thePlane;
- (BOOL)isSupersetOfSet:(NSCharacterSet*)theOtherSet;
- (BOOL)longCharacterIsMember:(UTF32Char)theLongChar;
@property (readonly, copy) NSCharacterSet* invertedSet;
@property (readonly, copy) NSData* bitmapRepresentation;

@end
