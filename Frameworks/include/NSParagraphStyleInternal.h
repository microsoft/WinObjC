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

#pragma once

#import <UIKit/NSMutableParagraphStyle.h>
#import <CoreText/CTParagraphStyle.h>

@interface NSParagraphStyle ()

- (CTParagraphStyleRef)_createCTParagraphStyle;
- (void)_setParagraphStyle:(NSParagraphStyle*)obj;

// Redeclaring properties for read/write access in mutable subclass
@property (nonatomic, readwrite) NSTextAlignment alignment;
@property (nonatomic, readwrite) CGFloat firstLineHeadIndent;
@property (nonatomic, readwrite) CGFloat headIndent;
@property (nonatomic, readwrite) CGFloat tailIndent;
@property (nonatomic, readwrite) NSLineBreakMode lineBreakMode;
@property (nonatomic, readwrite) CGFloat maximumLineHeight;
@property (nonatomic, readwrite) CGFloat minimumLineHeight;
@property (nonatomic, readwrite) CGFloat lineSpacing;
@property (nonatomic, readwrite) CGFloat paragraphSpacing;
@property (nonatomic, readwrite) CGFloat paragraphSpacingBefore;
@property (nonatomic, readwrite) NSWritingDirection baseWritingDirection;
@property (nonatomic, readwrite) CGFloat lineHeightMultiple;
@property (copy, nonatomic, readwrite) NSArray* tabStops;
@property (nonatomic, readwrite) CGFloat defaultTabInterval;
@property (nonatomic, readwrite) float hyphenationFactor;

@end