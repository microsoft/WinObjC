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

// WindowsGlobalizationCollation.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSGLOBALIZATIONCOLLATIONEXPORT
#define OBJCUWPWINDOWSGLOBALIZATIONCOLLATIONEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsGlobalizationCollation.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WGCCharacterGrouping, WGCCharacterGroupings;
@protocol WGCICharacterGrouping, WGCICharacterGroupingsFactory, WGCICharacterGroupings;

#import <Foundation/Foundation.h>

// Windows.Globalization.Collation.CharacterGrouping
#ifndef __WGCCharacterGrouping_DEFINED__
#define __WGCCharacterGrouping_DEFINED__

OBJCUWPWINDOWSGLOBALIZATIONCOLLATIONEXPORT
@interface WGCCharacterGrouping : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * first;
@property (readonly) NSString * label;
@end

#endif // __WGCCharacterGrouping_DEFINED__

// Windows.Globalization.Collation.CharacterGroupings
#ifndef __WGCCharacterGroupings_DEFINED__
#define __WGCCharacterGroupings_DEFINED__

OBJCUWPWINDOWSGLOBALIZATIONCOLLATIONEXPORT
@interface WGCCharacterGroupings : RTObject
+ (WGCCharacterGroupings*)make:(NSString *)language ACTIVATOR;
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int size;
- (unsigned int)count;
- (id)objectAtIndex:(unsigned)idx;
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state
                                  objects:(id __unsafe_unretained [])buffer
                                    count:(NSUInteger)len;

- (NSString *)lookup:(NSString *)text;
@end

#endif // __WGCCharacterGroupings_DEFINED__

