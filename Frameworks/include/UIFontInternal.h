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

#import <CoreFoundation/CoreFoundation.h>
#import <UIKit/UIFont.h>

#include <COMIncludes.h>
#import <DWrite_3.h>
#include <COMIncludes_End.h>

@interface UIFont ()
+ (UIFont*)defaultFont;
+ (UIFont*)titleFont;
+ (UIFont*)messageFont;
+ (UIFont*)buttonFont;
- (NSString*)_compatibleFamilyName;
- (DWRITE_FONT_WEIGHT)_fontWeight;
- (DWRITE_FONT_STRETCH)_fontStretch;
- (DWRITE_FONT_STYLE)_fontStyle;
@end