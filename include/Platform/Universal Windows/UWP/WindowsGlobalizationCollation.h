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

// WindowsGlobalizationCollation.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WGCCharacterGrouping, WGCCharacterGroupings;
@class RTArray_C_WGCCharacterGrouping;
@protocol WGCICharacterGrouping
, WGCICharacterGroupings;

#include "WindowsFoundationCollections.h"

#import <Foundation/Foundation.h>

// Windows.Globalization.Collation.CharacterGrouping
#ifndef __WGCCharacterGrouping_DEFINED__
#define __WGCCharacterGrouping_DEFINED__

WINRT_EXPORT
@interface WGCCharacterGrouping : RTObject
@property (readonly) NSString* first;
@property (readonly) NSString* label;
@end

#endif // __WGCCharacterGrouping_DEFINED__

// Windows.Globalization.Collation.CharacterGroupings
#ifndef __WGCCharacterGroupings_DEFINED__
#define __WGCCharacterGroupings_DEFINED__

WINRT_EXPORT
@interface WGCCharacterGroupings : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) unsigned int size;
- (unsigned int)count;
- (id)objectAtIndex:(unsigned)idx;
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState*)state objects:(id __unsafe_unretained[])buffer count:(NSUInteger)len;

- (NSString*)lookup:(NSString*)text;
@end

#endif // __WGCCharacterGroupings_DEFINED__
