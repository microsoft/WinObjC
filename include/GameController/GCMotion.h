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

typedef struct {
    double x;
    double y;
    double z;
} GCQuaternion;

typedef struct {
    double x;
    double y;
    double z;
} GCAcceleration;

typedef struct {
    double x;
    double y;
    double z;
} GCRotationRate;

typedef void (^GCMotionValueChangedHandler)(GCGamepad* gamepad, GCControllerElement* element);

GAMECONTROLLER_EXPORT_CLASS
@interface GCMotion : NSObject
@property (readonly, assign, nonatomic) GCController* controller STUB_PROPERTY;
@property (copy, nonatomic) GCMotionValueChangedHandler valueChangedHandler STUB_PROPERTY;
@property (readonly, assign, nonatomic) GCAcceleration gravity STUB_PROPERTY;
@property (readonly, assign, nonatomic) GCAcceleration userAcceleration STUB_PROPERTY;
@property (readonly, assign, nonatomic) GCQuaternion attitude STUB_PROPERTY;
@property (readonly, assign, nonatomic) GCRotationRate rotationRate STUB_PROPERTY;
@end
