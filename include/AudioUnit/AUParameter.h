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
#import <Foundation/NSObject.h>
#import <AudioUnit/AUParameterNode.h>
#import <AudioUnit/AudioUnitProperties.h>
#import <AudioUnit/AudioUnitTypes.h>

@class NSString;
@class NSArray;

AUDIOUNIT_EXPORT_CLASS
@interface AUParameter : AUParameterNode <NSSecureCoding>
@property (readonly, nonatomic) AUValue minValue STUB_PROPERTY;
@property (readonly, nonatomic) AUValue maxValue STUB_PROPERTY;
@property (readonly, nonatomic) AudioUnitParameterUnit unit STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* unitName STUB_PROPERTY;
@property (readonly, nonatomic) AudioUnitParameterOptions flags STUB_PROPERTY;
@property (readonly, nonatomic) AUParameterAddress address STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSArray* valueStrings STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSArray* dependentParameters STUB_PROPERTY;
@property (nonatomic) AUValue value STUB_PROPERTY;
- (void)setValue:(AUValue)value originator:(AUParameterObserverToken)originator STUB_METHOD;
- (void)setValue:(AUValue)value originator:(AUParameterObserverToken)originator atHostTime:(uint64_t)hostTime STUB_METHOD;
- (NSString*)stringFromValue:(const AUValue*)value STUB_METHOD;
- (AUValue)valueFromString:(NSString*)string STUB_METHOD;
@end
