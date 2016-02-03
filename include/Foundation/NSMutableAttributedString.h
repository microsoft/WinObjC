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

#import <Foundation/NSAttributedString.h>

@class NSMutableString;
@class NSString;
@class NSDictionary;

FOUNDATION_EXPORT_CLASS
@interface NSMutableAttributedString : NSAttributedString <NSCopying, NSMutableCopying, NSSecureCoding>
@property (readonly, retain) NSMutableString* mutableString;
- (void)replaceCharactersInRange:(NSRange)aRange withString:(NSString*)aString;
- (void)deleteCharactersInRange:(NSRange)aRange;
- (void)setAttributes:(NSDictionary*)attributes range:(NSRange)aRange;
- (void)addAttribute:(NSString*)name value:(id)value range:(NSRange)aRange;
- (void)addAttributes:(NSDictionary*)attributes range:(NSRange)aRange;
- (void)removeAttribute:(NSString*)name range:(NSRange)aRange;
- (void)appendAttributedString:(NSAttributedString*)attributedString;
- (void)insertAttributedString:(NSAttributedString*)attributedString atIndex:(NSUInteger)index;
- (void)replaceCharactersInRange:(NSRange)aRange withAttributedString:(NSAttributedString*)attributedString;
- (void)setAttributedString:(NSAttributedString*)attributedString;
- (void)beginEditing;
- (void)endEditing;
@end
