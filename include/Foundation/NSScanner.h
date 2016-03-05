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
#import <Foundation/NSLocale.h>
#import <Foundation/NSDecimal.h>

@class NSString;
@class NSCharacterSet;

FOUNDATION_EXPORT_CLASS
@interface NSScanner : NSObject <NSCopying> {
    NSString* _string;
    NSUInteger _location;
    NSUInteger _len;
    NSCharacterSet* _skipSet;
    BOOL _isCaseSensitive;
    NSLocale* _locale;
}

+ (instancetype)scannerWithString:(NSString*)aString;
+ (id)localizedScannerWithString:(NSString*)aString STUB_METHOD;
- (instancetype)initWithString:(NSString*)aString;
@property (readonly, copy) NSString* string;
@property NSUInteger scanLocation;
@property BOOL caseSensitive;
@property (copy) NSCharacterSet* charactersToBeSkipped;
@property (retain) id locale STUB_PROPERTY;
- (BOOL)scanCharactersFromSet:(NSCharacterSet*)scanSet intoString:(NSString* _Nullable*)stringValue;
- (BOOL)scanUpToCharactersFromSet:(NSCharacterSet*)stopSet intoString:(NSString* _Nullable*)stringValue;
- (BOOL)scanDecimal:(NSDecimal*)decimalValue STUB_METHOD;
- (BOOL)scanDouble:(double*)doubleValue;
- (BOOL)scanFloat:(float*)floatValue;
- (BOOL)scanHexDouble:(double*)result STUB_METHOD;
- (BOOL)scanHexFloat:(float*)result STUB_METHOD;
- (BOOL)scanHexInt:(unsigned int*)intValue;
- (BOOL)scanHexLongLong:(unsigned long long*)result;
- (BOOL)scanInteger:(NSInteger*)value;
- (BOOL)scanInt:(int*)intValue;
- (BOOL)scanLongLong:(long long*)longLongValue;
- (BOOL)scanString:(NSString*)string intoString:(NSString* _Nullable*)stringValue;
- (BOOL)scanUnsignedLongLong:(unsigned long long*)unsignedLongLongValue;
- (BOOL)scanUpToString:(NSString*)stopString intoString:(NSString* _Nullable*)stringValue;
@property (readonly, getter=isAtEnd) BOOL atEnd;
@end
