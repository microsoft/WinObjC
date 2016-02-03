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

@class UIImage;
@class NSError;
@class NSArray;
@class NSString;

GAMEKIT_EXPORT_CLASS
@interface GKLeaderboardSet : NSObject <NSCoding, NSObject, NSSecureCoding>
- (void)loadImageWithCompletionHandler:(void (^)(UIImage*, NSError*))completionHandler STUB_METHOD;
+ (void)loadLeaderboardSetsWithCompletionHandler:(void (^)(NSArray*, NSError*))completionHandler STUB_METHOD;
- (void)loadLeaderboardsWithCompletionHandler:(void (^)(NSArray*, NSError*))completionHandler STUB_METHOD;
@property (readonly, copy, nonatomic) NSString* title STUB_PROPERTY;
@property (copy, nonatomic) NSString* identifier STUB_PROPERTY;
@property (readonly, retain, nonatomic) NSString* groupIdentifier STUB_PROPERTY;
@end
