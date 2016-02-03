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

#import <AudioUnit/AudioUnitExport.h>
#import <Foundation/NSFastEnumeration.h>
#import <Foundation/NSObject.h>
#import <Foundation/NSKeyValueObserving.h>

@class AUAudioUnit;
@class NSArray;
@class AUAudioUnitBus;
@class NSError;
@class NSString;

#import <AudioUnit/AUAudioUnit.h>

AUDIOUNIT_EXPORT_CLASS
@interface AUAudioUnitBusArray : NSObject <NSFastEnumeration>
- (instancetype)initWithAudioUnit:(AUAudioUnit*)owner busType:(AUAudioUnitBusType)busType STUB_METHOD;
- (instancetype)initWithAudioUnit:(AUAudioUnit*)owner busType:(AUAudioUnitBusType)busType busses:(NSArray*)busArray STUB_METHOD;
@property (readonly, nonatomic) NSUInteger count STUB_PROPERTY;
@property (readonly, getter=isCountChangeable, nonatomic) BOOL countChangeable STUB_PROPERTY;
@property (readonly, assign, nonatomic) AUAudioUnit* ownerAudioUnit STUB_PROPERTY;
@property (readonly, nonatomic) AUAudioUnitBusType busType STUB_PROPERTY;
- (AUAudioUnitBus*)objectAtIndexedSubscript:(NSUInteger)index STUB_METHOD;
- (BOOL)setBusCount:(NSUInteger)count error:(NSError* _Nullable*)outError STUB_METHOD;
- (void)addObserverToAllBusses:(NSObject*)observer
                    forKeyPath:(NSString*)keyPath
                       options:(NSKeyValueObservingOptions)options
                       context:(void*)context STUB_METHOD;
- (void)removeObserverFromAllBusses:(NSObject*)observer forKeyPath:(NSString*)keyPath context:(void*)context STUB_METHOD;
- (void)replaceBusses:(NSArray*)busArray STUB_METHOD;
@end
