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

#ifndef _GKSCORE_H_
#define _GKSCORE_H_

#import <GameKit/GameKitExport.h>
#import <Foundation/NSObject.h>

@class NSDate;
@class NSError;

GAMEKIT_EXPORT_CLASS
@interface GKScore : NSObject

@property (nonatomic, assign) int64_t value;
@property (nonatomic, readonly, assign) NSInteger rank;
@property (nonatomic, readonly, retain) NSString* playerID;
@property (nonatomic, readonly, retain) NSDate* date;
@property (nonatomic, readonly, retain) NSString* formattedValue;
@property (nonatomic, assign) uint64_t context;
@property (nonatomic, retain) NSString* category;
@property (copy, nonatomic) NSString* leaderboardIdentifier;

- (id)initWithCategory:(NSString*)category;
- (void)reportScoreWithCompletionHandler:(void (^)(NSError* error))completionHandler;

@end

#endif /* _GKSCORE_H_ */