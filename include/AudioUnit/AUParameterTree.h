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
#import <AudioUnit/AUParameterGroup.h>
#import <AudioUnit/AudioUnitTypes.h>
#import <AudioUnit/AudioUnitComponent.h>
#import <AudioUnit/AUParameterNode.h>
#import <AudioUnit/AudioUnitProperties.h>

@class AUParameter;
@class NSString;
@class NSArray;

AUDIOUNIT_EXPORT_CLASS
@interface AUParameterTree : AUParameterGroup <NSSecureCoding>
- (AUParameter*)parameterWithAddress:(AUParameterAddress)address STUB_METHOD;
- (AUParameter*)parameterWithID:(AudioUnitParameterID)paramID scope:(AudioUnitScope)scope element:(AudioUnitElement)element STUB_METHOD;
+ (AUParameter*)createParameterWithIdentifier:(NSString*)identifier
                                         name:(NSString*)name
                                      address:(AUParameterAddress)address
                                          min:(AUValue)min
                                          max:(AUValue)max
                                         unit:(AudioUnitParameterUnit)unit
                                     unitName:(NSString*)unitName
                                        flags:(AudioUnitParameterOptions)flags
                                 valueStrings:(NSArray*)valueStrings
                          dependentParameters:(NSArray*)dependentParameters STUB_METHOD;
+ (AUParameterGroup*)createGroupWithIdentifier:(NSString*)identifier name:(NSString*)name children:(NSArray*)children STUB_METHOD;
+ (AUParameterGroup*)createGroupTemplate:(NSArray*)children STUB_METHOD;
+ (AUParameterGroup*)createGroupFromTemplate:(AUParameterGroup*)templateGroup
                                  identifier:(NSString*)identifier
                                        name:(NSString*)name
                               addressOffset:(AUParameterAddress)addressOffset STUB_METHOD;
+ (AUParameterTree*)createTreeWithChildren:(NSArray*)children STUB_METHOD;
@end
