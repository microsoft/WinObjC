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
#include <Foundation/NSMutableAttributedString.h>
#import "BridgeHelpers.h"

@interface NSMutableAttributedStringConcrete : NSMutableAttributedString

BRIDGED_CLASS_REQUIRED_DECLS

- (NSString*)string;
- (id)attribute:(NSString*)name atIndex:(NSUInteger)location effectiveRange:(NSRange*)range;
- (NSDictionary*)attributesAtIndex:(NSUInteger)location effectiveRange:(NSRange*)range;
- (NSMutableString*)mutableString;
- (void)addAttribute:(NSString*)name value:(id)value range:(NSRange)range;
- (void)removeAttribute:(NSString*)name range:(NSRange)range;
- (void)setAttributes:(NSDictionary*)attributes range:(NSRange)range;
- (void)replaceCharactersInRange:(NSRange)range withString:(NSString*)string;
- (void)beginEditing;
- (void)endEditing;

@end