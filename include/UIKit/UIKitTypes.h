//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#import <Foundation/Foundation.h>
#import <CoreText/CoreText.h>

// This is the home for enums that are shared by more than one interface

enum {
    NSLineBreakByWordWrapping = kCTLineBreakByWordWrapping,
    NSLineBreakByCharWrapping = kCTLineBreakByCharWrapping,
    NSLineBreakByClipping = kCTLineBreakByClipping,
    NSLineBreakByTruncatingHead = kCTLineBreakByTruncatingHead,
    NSLineBreakByTruncatingTail = kCTLineBreakByTruncatingTail,
    NSLineBreakByTruncatingMiddle = kCTLineBreakByTruncatingMiddle
};
typedef NSUInteger NSLineBreakMode;

enum {
    UILineBreakModeWordWrap = NSLineBreakByWordWrapping,
    UILineBreakModeCharacterWrap = NSLineBreakByCharWrapping,
    UILineBreakModeClip = NSLineBreakByClipping,
    UILineBreakModeHeadTruncation = NSLineBreakByTruncatingHead,
    UILineBreakModeTailTruncation = NSLineBreakByTruncatingTail,
    UILineBreakModeMiddleTruncation = NSLineBreakByTruncatingMiddle
};
typedef NSUInteger UILineBreakMode;

typedef NS_ENUM(NSUInteger, NSWritingDirection) {
    NSWritingDirectionNatural = -1,
    NSWritingDirectionLeftToRight = 0,
    NSWritingDirectionRightToLeft = 1
};

enum {
    UITextAlignmentLeft = 0,
    UITextAlignmentCenter,
    UITextAlignmentRight,
};
typedef NSUInteger UITextAlignment;

enum {
    NSTextAlignmentLeft = 0,
    NSTextAlignmentCenter = 1,
    NSTextAlignmentRight = 2,
    NSTextAlignmentJustified = 3,
    NSTextAlignmentNatural = 4,
};
typedef NSUInteger NSTextAlignment;

typedef enum {
    UIBaselineAdjustmentAlignBaselines,
    UIBaselineAdjustmentAlignCenters,
    UIBaselineAdjustmentNone,
} UIBaselineAdjustment;

typedef enum : NSInteger {
    NSUnderlineStyleNone = 0x00,
    NSUnderlineStyleSingle = 0x01,
    NSUnderlineStyleThick = 0x02,
    NSUnderlineStyleDouble = 0x09,
    NSUnderlinePatternSolid = 0x0000,
    NSUnderlinePatternDot = 0x0100,
    NSUnderlinePatternDash = 0x0200,
    NSUnderlinePatternDashDot = 0x0300,
    NSUnderlinePatternDashDotDot = 0x0400,
    NSUnderlineByWord = 0x8000
} NSUnderlineStyle;

typedef enum : NSInteger {
    NSTextWritingDirectionEmbedding = (0 << 1),
    NSTextWritingDirectionOverride = (1 << 1),
} NSTextWritingDirection;

enum {
    NSStringDrawingTruncatesLastVisibleLine = 1 << 5,
    NSStringDrawingUsesLineFragmentOrigin = 1 << 0,
    NSStringDrawingUsesFontLeading = 1 << 1,
    NSStringDrawingUsesDeviceMetrics = 1 << 3,
};

typedef enum : NSInteger {
    UIBarMetricsDefault,
    UIBarMetricsCompact,
    UIBarMetricsDefaultPrompt = 101,
    UIBarMetricsCompactPrompt,
    UIBarMetricsLandscapePhone, // Deprecated
    UIBarMetricsLandscapePhonePrompt, // Deprecated.
} UIBarMetrics;

typedef NS_ENUM(NSInteger, UIUserInterfaceSizeClass) {
    UIUserInterfaceSizeClassUnspecified = 0,
    UIUserInterfaceSizeClassCompact = 1,
    UIUserInterfaceSizeClassRegular = 2,
};
