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

@class NSData;

typedef struct {
    uint16_t version;
    uint16_t size;
    float dpadX;
    float dpadY;
    float buttonA;
    float buttonB;
    float buttonX;
    float buttonY;
    float leftShoulder;
    float rightShoulder;
} GCGamepadSnapShotDataV100;

typedef struct {
    uint16_t version;
    uint16_t size;
    float dpadX;
    float dpadY;
    float buttonA;
    float buttonB;
    float buttonX;
    float buttonY;
    float leftShoulder;
    float rightShoulder;
    float leftThumbstickX;
    float leftThumbstickY;
    float rightThumbstickX;
    float rightThumbstickY;
    float leftTrigger;
    float rightTrigger;
} GCExtendedGamepadSnapShotDataV100;

GAMECONTROLLER_EXPORT BOOL GCGamepadSnapShotDataV100FromNSData(GCGamepadSnapShotDataV100* snapshotData, NSData* data) STUB_METHOD;
GAMECONTROLLER_EXPORT BOOL GCExtendedGamepadSnapShotDataV100FromNSData(GCExtendedGamepadSnapShotDataV100* snapshotData,
                                                                       NSData* data) STUB_METHOD;
GAMECONTROLLER_EXPORT NSData* NSDataFromGCGamepadSnapShotDataV100(GCGamepadSnapShotDataV100* snapshotData) STUB_METHOD;
GAMECONTROLLER_EXPORT NSData* NSDataFromGCExtendedGamepadSnapShotDataV100(GCExtendedGamepadSnapShotDataV100* snapshotData) STUB_METHOD;
