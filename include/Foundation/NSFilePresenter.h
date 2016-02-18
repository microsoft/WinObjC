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

#import <Foundation/FoundationExport.h>
#import <Foundation/NSObject.h>

@class NSURL;
@class NSOperationQueue;
@class NSError;
@class NSFileVersion;

@protocol NSFilePresenter <NSObject>
@property (readonly, copy) NSURL* presentedItemURL;
@property (readonly, retain) NSOperationQueue* presentedItemOperationQueue;

@optional
- (void)relinquishPresentedItemToReader:(void (^)(void (^reacquirer)(void)))reader;
- (void)relinquishPresentedItemToWriter:(void (^)(void (^reacquirer)(void)))writer;
- (void)savePresentedItemChangesWithCompletionHandler:(void (^)(NSError* errorOrNil))completionHandler;
- (void)accommodatePresentedItemDeletionWithCompletionHandler:(void (^)(NSError* errorOrNil))completionHandler;
- (void)presentedItemDidMoveToURL:(NSURL*)newURL;
- (void)presentedItemDidChange;
- (void)presentedItemDidGainVersion:(NSFileVersion*)version;
- (void)presentedItemDidLoseVersion:(NSFileVersion*)version;
- (void)presentedItemDidResolveConflictVersion:(NSFileVersion*)version;
- (void)presentedSubitemAtURL:(NSURL*)url didGainVersion:(NSFileVersion*)version;
- (void)presentedSubitemAtURL:(NSURL*)url didLoseVersion:(NSFileVersion*)version;
- (void)presentedSubitemAtURL:(NSURL*)url didResolveConflictVersion:(NSFileVersion*)version;
- (void)accommodatePresentedSubitemDeletionAtURL:(NSURL*)url completionHandler:(void (^)(NSError* errorOrNil))completionHandler;
- (void)presentedSubitemDidAppearAtURL:(NSURL*)url;
- (void)presentedSubitemAtURL:(NSURL*)oldURL didMoveToURL:(NSURL*)newURL;
- (void)presentedSubitemDidChangeAtURL:(NSURL*)url;
@end
