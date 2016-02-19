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

#import <GameKit/GameKitExport.h>
#import <Foundation/NSObject.h>

@protocol GKPeerPickerControllerDelegate;

typedef NSUInteger GKPeerPickerConnectionType;
enum {
    GKPeerPickerConnectionTypeOnline = 1 << 0,
    GKPeerPickerConnectionTypeNearby = 1 << 1,
};

GAMEKIT_EXPORT_CLASS
@interface GKPeerPickerController : NSObject <NSObject>
- (void)show STUB_METHOD;
- (void)dismiss STUB_METHOD;
@property (readonly, getter=isVisible, nonatomic) BOOL visible STUB_PROPERTY;
@property (assign, nonatomic) id<GKPeerPickerControllerDelegate> delegate STUB_PROPERTY;
@property (assign, nonatomic) GKPeerPickerConnectionType connectionTypesMask STUB_PROPERTY;
@end
