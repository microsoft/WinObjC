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

#import <GameController/GameControllerExport.h>
#import <Foundation/NSObject.h>

@class GCGamepad;
@class GCControllerElement;
@class GCController;
@class GCControllerButtonInput;
@class GCControllerDirectionPad;
@class GCGamepadSnapshot;

typedef void (^GCGamepadValueChangedHandler)(GCGamepad* gamepad, GCControllerElement* element);

GAMECONTROLLER_EXPORT_CLASS
@interface GCGamepad : NSObject
@property (readonly, assign, nonatomic) GCController* controller STUB_PROPERTY;
@property (copy, nonatomic) GCGamepadValueChangedHandler valueChangedHandler STUB_PROPERTY;
@property (readonly, nonatomic) GCControllerButtonInput* leftShoulder STUB_PROPERTY;
@property (readonly, nonatomic) GCControllerButtonInput* rightShoulder STUB_PROPERTY;
@property (readonly, nonatomic) GCControllerDirectionPad* dpad STUB_PROPERTY;
@property (readonly, nonatomic) GCControllerButtonInput* buttonA STUB_PROPERTY;
@property (readonly, nonatomic) GCControllerButtonInput* buttonB STUB_PROPERTY;
@property (readonly, nonatomic) GCControllerButtonInput* buttonX STUB_PROPERTY;
@property (readonly, nonatomic) GCControllerButtonInput* buttonY STUB_PROPERTY;
- (GCGamepadSnapshot*)saveSnapshot STUB_METHOD;
@end
