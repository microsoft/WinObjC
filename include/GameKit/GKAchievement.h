//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#ifndef _GKACHIEVEMENT_H_
#define _GKACHIEVEMENT_H_

#import <GameKit/GameKitExport.h>
#import <Foundation/NSObject.h>

@class NSArray;
@class NSError;

GAMEKIT_EXPORT_CLASS
@interface GKAchievement : NSObject

+ (void)loadAchievementsWithCompletionHandler:(void (^)(NSArray* achievements, NSError* error))completionHandler;
+ (void)resetAchievementsWithCompletionHandler:(void (^)(NSError* error))completionHandler;

- (id)initWithIdentifier:(NSString*)identifier;

- (void)reportAchievementWithCompletionHandler:(void (^)(NSError* error))completionHandler;

@property (nonatomic, retain) NSString* identifier;
@property (nonatomic, assign) double percentComplete;
@property (nonatomic, assign) BOOL showsCompletionBanner;

@end

#endif /* _GKACHIEVEMENT_H_ */