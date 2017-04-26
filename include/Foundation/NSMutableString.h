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
#pragma once

#import <Foundation/FoundationExport.h>
#import <Foundation/NSObject.h>

#import <Foundation/NSString.h>

FOUNDATION_EXPORT_CLASS
@interface NSMutableString : NSString <NSCopying, NSMutableCopying, NSSecureCoding>
+ (NSMutableString*)stringWithCapacity:(NSUInteger)capacity;
- (NSMutableString*)initWithCapacity:(NSUInteger)capacity;
- (void)appendFormat:(NSString*)format, ... NS_FORMAT_FUNCTION(1, 2);
- (void)appendString:(NSString*)aString;
- (void)deleteCharactersInRange:(NSRange)aRange;
- (void)insertString:(NSString*)aString atIndex:(NSUInteger)anIndex;
- (void)replaceCharactersInRange:(NSRange)aRange withString:(NSString*)aString;
- (NSUInteger)replaceOccurrencesOfString:(NSString*)target
                              withString:(NSString*)replacement
                                 options:(NSStringCompareOptions)opts
                                   range:(NSRange)searchRange;
- (void)setString:(NSString*)aString;
@end
