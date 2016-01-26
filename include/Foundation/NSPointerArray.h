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
#import <Foundation/NSCoding.h>
#import <Foundation/NSCopying.h>
#import <Foundation/NSFastEnumeration.h>
#import <Foundation/NSObject.h>

#import <Foundation/NSPointerFunctions.h>

@class NSPointerFunctions;
@class NSArray;

FOUNDATION_EXPORT_CLASS
@interface NSPointerArray : NSObject <NSCoding, NSCopying, NSFastEnumeration>
- (instancetype)initWithOptions:(NSPointerFunctionsOptions)options STUB_METHOD;
- (instancetype)initWithPointerFunctions:(NSPointerFunctions*)functions STUB_METHOD;
+ (NSPointerArray*)pointerArrayWithOptions:(NSPointerFunctionsOptions)options STUB_METHOD;
+ (NSPointerArray*)pointerArrayWithPointerFunctions:(NSPointerFunctions*)functions STUB_METHOD;
+ (NSPointerArray*)strongObjectsPointerArray STUB_METHOD;
+ (NSPointerArray*)weakObjectsPointerArray STUB_METHOD;
@property NSUInteger count STUB_PROPERTY;
@property (readonly, copy) NSArray* allObjects STUB_PROPERTY;
- (void*)pointerAtIndex:(NSUInteger)index STUB_METHOD;
- (void)addPointer:(void*)pointer STUB_METHOD;
- (void)removePointerAtIndex:(NSUInteger)index STUB_METHOD;
- (void)insertPointer:(void*)item atIndex:(NSUInteger)index STUB_METHOD;
- (void)replacePointerAtIndex:(NSUInteger)index withPointer:(void*)item STUB_METHOD;
- (void)compact STUB_METHOD;
@property (readonly, copy) NSPointerFunctions* pointerFunctions STUB_PROPERTY;
@end
