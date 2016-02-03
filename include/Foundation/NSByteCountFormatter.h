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

#import <Foundation/NSFormatter.h>

@class NSString;

typedef NSUInteger NSByteCountFormatterUnits;
typedef NSInteger NSByteCountFormatterCountStyle;
enum {
    NSByteCountFormatterUseDefault = 0,
    NSByteCountFormatterUseBytes = 1UL << 0,
    NSByteCountFormatterUseKB = 1UL << 1,
    NSByteCountFormatterUseMB = 1UL << 2,
    NSByteCountFormatterUseGB = 1UL << 3,
    NSByteCountFormatterUseTB = 1UL << 4,
    NSByteCountFormatterUsePB = 1UL << 5,
    NSByteCountFormatterUseEB = 1UL << 6,
    NSByteCountFormatterUseZB = 1UL << 7,
    NSByteCountFormatterUseYBOrHigher = 0x0FFUL << 8,
    NSByteCountFormatterUseAll = 0x0FFFFUL
};

enum {
    NSByteCountFormatterCountStyleFile = 0,
    NSByteCountFormatterCountStyleMemory = 1,
    NSByteCountFormatterCountStyleDecimal = 2,
    NSByteCountFormatterCountStyleBinary = 3
};

FOUNDATION_EXPORT_CLASS
@interface NSByteCountFormatter : NSFormatter <NSCoding, NSCopying>
+ (NSString*)stringFromByteCount:(long long)byteCount countStyle:(NSByteCountFormatterCountStyle)countStyle STUB_METHOD;
- (NSString*)stringFromByteCount:(long long)byteCount STUB_METHOD;
@property NSFormattingContext formattingContext STUB_PROPERTY;
@property NSByteCountFormatterCountStyle countStyle STUB_PROPERTY;
@property BOOL allowsNonnumericFormatting STUB_PROPERTY;
@property BOOL includesActualByteCount STUB_PROPERTY;
@property (getter=isAdaptive) BOOL adaptive STUB_PROPERTY;
@property NSByteCountFormatterUnits allowedUnits STUB_PROPERTY;
@property BOOL includesCount STUB_PROPERTY;
@property BOOL includesUnit STUB_PROPERTY;
@property BOOL zeroPadsFractionDigits STUB_PROPERTY;
@end
