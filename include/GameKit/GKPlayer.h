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

#ifndef _GKPLAYER_H_
#define _GKPLAYER_H_

#import <Foundation/NSObject.h>

@class NSArray;
@class NSError;

@interface GKPlayer : NSObject

@property (nonatomic, readonly, retain) NSString *playerID;
@property (nonatomic, readonly, copy) NSString *alias;

+ (void)loadPlayersForIdentifiers:(NSArray *)identifiers withCompletionHandler:(void (^)(NSArray *players, NSError *error))completionHandler;

@end

#endif /* _GKPLAYER_H_ */