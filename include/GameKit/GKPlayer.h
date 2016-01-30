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

#import <Foundation/NSObjCRuntime.h>
#import <Foundation/NSObject.h>

@class NSArray;
@class NSError;
@class NSString;
@class UIImage;

typedef NSInteger GKPhotoSize;
enum {
    GKPhotoSizeSmall = 0,
    GKPhotoSizeNormal,
};

GAMEKIT_EXPORT_CLASS
@interface GKPlayer : NSObject <NSObject>
+ (void)loadPlayersForIdentifiers:(NSArray*)identifiers withCompletionHandler:(void (^)(NSArray*, NSError*))completionHandler STUB_METHOD;
- (void)loadPhotoForSize:(GKPhotoSize)size withCompletionHandler:(void (^)(UIImage*, NSError*))completionHandler STUB_METHOD;
+ (instancetype)anonymousGuestPlayerWithIdentifier:(NSString*)guestIdentifier STUB_METHOD;
@property (readonly, retain, nonatomic) NSString* playerID STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* alias STUB_PROPERTY;
@property (readonly, nonatomic) NSString* displayName STUB_PROPERTY;
@property (readonly, nonatomic) BOOL isFriend STUB_PROPERTY;
@property (readonly, nonatomic) NSString* guestIdentifier STUB_PROPERTY;
@end
