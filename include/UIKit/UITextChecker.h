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

#import <UIKit/UIKitExport.h>
#import <Foundation/Foundation.h>

UIKIT_EXPORT_CLASS
@interface UITextChecker : NSObject
- (NSRange)rangeOfMisspelledWordInString:(NSString*)stringToCheck
                                   range:(NSRange)range
                              startingAt:(NSInteger)startingOffset
                                    wrap:(BOOL)wrapFlag
                                language:(NSString*)language STUB_METHOD;
- (NSArray*)guessesForWordRange:(NSRange)range inString:(NSString*)string language:(NSString*)language STUB_METHOD;
- (NSArray*)completionsForPartialWordRange:(NSRange)range inString:(NSString*)string language:(NSString*)language STUB_METHOD;
- (void)ignoreWord:(NSString*)wordToIgnore STUB_METHOD;
- (NSArray*)ignoredWords STUB_METHOD;
- (void)setIgnoredWords:(NSArray*)words STUB_METHOD;
+ (void)learnWord:(NSString*)word STUB_METHOD;
+ (void)unlearnWord:(NSString*)word STUB_METHOD;
+ (BOOL)hasLearnedWord:(NSString*)word STUB_METHOD;
+ (NSArray*)availableLanguages STUB_METHOD;
@end
