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
#import <Foundation/NSFastEnumeration.h>
#import <Foundation/NSObject.h>

#import <Foundation/NSPointerFunctions.h>

@class NSPointerFunctions;
@class NSArray;

FOUNDATION_EXPORT_CLASS
@interface NSPointerArray : NSObject <NSCoding, NSCopying, NSFastEnumeration>
- (instancetype)initWithOptions:(NSPointerFunctionsOptions)options;
- (instancetype)initWithPointerFunctions:(NSPointerFunctions*)functions;
+ (NSPointerArray*)pointerArrayWithOptions:(NSPointerFunctionsOptions)options;
+ (NSPointerArray*)pointerArrayWithPointerFunctions:(NSPointerFunctions*)functions;
+ (NSPointerArray*)strongObjectsPointerArray;
+ (NSPointerArray*)weakObjectsPointerArray;
@property NSUInteger count;
@property (readonly, copy) NSArray* allObjects;
- (void*)pointerAtIndex:(NSUInteger)index;
- (void)addPointer:(void*)pointer;
- (void)removePointerAtIndex:(NSUInteger)index;
- (void)insertPointer:(void*)item atIndex:(NSUInteger)index;
- (void)replacePointerAtIndex:(NSUInteger)index withPointer:(void*)item;
- (void)compact;
@property (readonly, copy) NSPointerFunctions* pointerFunctions;
@end
