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
#import <AudioUnit/AudioUnitTypes.h>

@class AUParameter;
@class NSString;
@class AUParameterNode;

typedef void (^AUParameterObserver)(AUParameterAddress address, AUValue value);
typedef void (^AUParameterRecordingObserver)(NSInteger numberEvents, const AURecordedParameterEvent* events);
typedef void (^AUImplementorValueObserver)(AUParameter* param, AUValue value);
typedef AUValue (^AUImplementorValueProvider)(AUParameter* param);
typedef NSString* _Nonnull (^AUImplementorStringFromValueCallback)(AUParameter* param, const AUValue* __nullable value);
typedef AUValue (^AUImplementorValueFromStringCallback)(AUParameter* param, NSString* string);
typedef NSString* _Nonnull (^AUImplementorDisplayNameWithLengthCallback)(AUParameterNode* node, NSInteger desiredLength);

AUDIOUNIT_EXPORT_CLASS
@interface AUParameterNode : NSObject
@property (readonly, copy, nonatomic) NSString* identifier STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* keyPath STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* displayName STUB_PROPERTY;
- (NSString*)displayNameWithLength:(NSInteger)maximumLength STUB_METHOD;
- (AUParameterObserverToken)tokenByAddingParameterObserver:(AUParameterObserver)observer STUB_METHOD;
- (AUParameterObserverToken)tokenByAddingParameterRecordingObserver:(AUParameterRecordingObserver)observer STUB_METHOD;
- (void)removeParameterObserver:(AUParameterObserverToken)token STUB_METHOD;
@property (copy, nonatomic) AUImplementorValueObserver implementorValueObserver STUB_PROPERTY;
@property (copy, nonatomic) AUImplementorValueProvider implementorValueProvider STUB_PROPERTY;
@property (copy, nonatomic) AUImplementorStringFromValueCallback implementorStringFromValueCallback STUB_PROPERTY;
@property (copy, nonatomic) AUImplementorValueFromStringCallback implementorValueFromStringCallback STUB_PROPERTY;
@property (copy, nonatomic) AUImplementorDisplayNameWithLengthCallback implementorDisplayNameWithLengthCallback STUB_PROPERTY;
@end