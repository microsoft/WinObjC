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

#import <MediaPlayer/MediaPlayerExport.h>
#import <Foundation/NSObject.h>

@class MPContentItem;
@class NSIndexPath;
@class NSError;

@protocol MPPlayableContentDataSource <NSObject>

- (MPContentItem*)contentItemAtIndexPath:(NSIndexPath*)indexPath;
- (NSInteger)numberOfChildItemsAtIndexPath:(NSIndexPath*)indexPath;

@optional
- (void)beginLoadingChildItemsAtIndexPath:(NSIndexPath*)indexPath completionHandler:(void (^)(NSError*))completionHandler;
- (BOOL)childItemsDisplayPlaybackProgressAtIndexPath:(NSIndexPath*)indexPath;

@end
