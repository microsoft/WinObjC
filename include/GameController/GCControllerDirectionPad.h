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
#import <GameController/GCControllerElement.h>

@class GCControllerDirectionPad;
@class GCControllerAxisInput;
@class GCControllerButtonInput;

typedef void (^GCControllerDirectionPadValueChangedHandler)(GCControllerDirectionPad* dpad, float xValue, float yValue);

GAMECONTROLLER_EXPORT_CLASS
@interface GCControllerDirectionPad : GCControllerElement
@property (readonly, nonatomic) GCControllerAxisInput* xAxis STUB_PROPERTY;
@property (readonly, nonatomic) GCControllerAxisInput* yAxis STUB_PROPERTY;
@property (readonly, nonatomic) GCControllerButtonInput* up STUB_PROPERTY;
@property (readonly, nonatomic) GCControllerButtonInput* down STUB_PROPERTY;
@property (readonly, nonatomic) GCControllerButtonInput* left STUB_PROPERTY;
@property (readonly, nonatomic) GCControllerButtonInput* right STUB_PROPERTY;
@property (copy, nonatomic) GCControllerDirectionPadValueChangedHandler valueChangedHandler STUB_PROPERTY;
@end
