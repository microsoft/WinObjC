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
#import <Foundation/NSObjCRuntime.h>

@class NSArray;
@class NSError;
@class NSString;
@class UIImage;

GAMEKIT_EXPORT_CLASS
@interface GKAchievementDescription : NSObject <NSCoding, NSObject, NSSecureCoding>
+ (void)loadAchievementDescriptionsWithCompletionHandler:(void (^)(NSArray*, NSError*))completionHandler STUB_METHOD;
+ (UIImage*)incompleteAchievementImage STUB_METHOD;
+ (UIImage*)placeholderCompletedAchievementImage STUB_METHOD;
- (void)loadImageWithCompletionHandler:(void (^)(UIImage*, NSError*))completionHandler STUB_METHOD;
@property (readonly, retain, nonatomic) NSString* groupIdentifier STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* identifier STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* title STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* unachievedDescription STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* achievedDescription STUB_PROPERTY;
@property (readonly, assign, nonatomic) NSInteger maximumPoints STUB_PROPERTY;
@property (readonly, retain, nonatomic) UIImage* image STUB_PROPERTY;
@property (readonly, getter=isHidden, assign, nonatomic) BOOL hidden STUB_PROPERTY;
@property (readonly, getter=isReplayable, assign, nonatomic) BOOL replayable STUB_PROPERTY;
@end
