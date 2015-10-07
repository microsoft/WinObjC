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

#ifndef _GKACHIEVEMENTDESCRIPTION_H_
#define _GKACHIEVEMENTDESCRIPTION_H_

#import <Foundation/NSObject.h>

@class NSArray;
@class NSError;

@interface GKAchievementDescription : NSObject

@property(nonatomic, retain, readonly) NSString *identifier;
@property(nonatomic, retain, readonly) NSString *title;
@property(nonatomic, retain, readonly) NSString *achievedDescription;

+ (void)loadAchievementDescriptionsWithCompletionHandler:(void (^)(NSArray *descriptions, NSError *error))completionHandler;

@end

#endif /* _GKACHIEVEMENTDESCRIPTION_H_ */