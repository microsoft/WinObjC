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
#import <dispatch/dispatch.h>
#import <Foundation/NSObject.h>

@class NSArray;
@class GCGamepad;
@class GCExtendedGamepad;
@class GCMotion;
@class NSString;

typedef enum GCControllerPlayerIndex : NSInteger {
    GCControllerPlayerIndexUnset = -1,
    GCControllerPlayerIndex1 = 0,
    GCControllerPlayerIndex2,
    GCControllerPlayerIndex3,
    GCControllerPlayerIndex4,
} GCControllerPlayerIndex;

GAMECONTROLLER_EXPORT NSString* const GCControllerDidConnectNotification;
GAMECONTROLLER_EXPORT NSString* const GCControllerDidDisconnectNotification;

GAMECONTROLLER_EXPORT_CLASS
@interface GCController : NSObject
+ (void)startWirelessControllerDiscoveryWithCompletionHandler:(void (^)(void))completionHandler STUB_METHOD;
+ (void)stopWirelessControllerDiscovery STUB_METHOD;
+ (NSArray*)controllers STUB_METHOD;
@property (readonly, retain, nonatomic) GCGamepad* gamepad STUB_PROPERTY;
@property (readonly, retain, nonatomic) GCExtendedGamepad* extendedGamepad STUB_PROPERTY;
@property (readonly, retain, nonatomic) GCMotion* motion STUB_PROPERTY;
@property (copy, nonatomic, nonnull) void (^controllerPausedHandler)(GCController*) STUB_PROPERTY;
@property (readonly, getter=isAttachedToDevice, nonatomic) BOOL attachedToDevice STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* vendorName STUB_PROPERTY;
@property (nonatomic) GCControllerPlayerIndex playerIndex STUB_PROPERTY;
// TODO::
// bug-nithishm-02012016 - VSO 6338199 should fix this.
// @property (retain) dispatch_queue_t handlerQueue STUB_PROPERTY;
@property dispatch_queue_t handlerQueue STUB_PROPERTY;
@end
