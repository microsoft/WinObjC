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

@class GKPlayer;
@class NSString;

GAMEKIT_EXPORT_CLASS
@interface GKInvite : NSObject <NSObject>
@property (readonly, getter=isHosted, nonatomic) BOOL hosted STUB_PROPERTY;
@property (readonly, nonatomic) uint32_t playerAttributes STUB_PROPERTY;
@property (readonly, nonatomic) NSUInteger playerGroup STUB_PROPERTY;
@property (readonly, retain, nonatomic) GKPlayer* sender STUB_PROPERTY;
@property (readonly, retain, nonatomic) NSString* inviter STUB_PROPERTY;
@end
