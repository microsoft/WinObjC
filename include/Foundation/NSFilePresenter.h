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
@class NSURL;
@class NSOperationQueue;
@class NSError;
@class NSFileVersion;

@protocol NSFilePresenter

@property (readonly, copy) NSURL* presentedItemURL;

@property (readonly, retain) NSOperationQueue* presentedItemOperationQueue;

@optional
- (void)relinquishPresentedItemToReader:(void (^)(void (^reacquirer)(void)))reader;

@optional
- (void)relinquishPresentedItemToWriter:(void (^)(void (^reacquirer)(void)))writer;

@optional
- (void)savePresentedItemChangesWithCompletionHandler:(void (^)(NSError* errorOrNil))completionHandler;

@optional
- (void)accommodatePresentedItemDeletionWithCompletionHandler:(void (^)(NSError* errorOrNil))completionHandler;

@optional
- (void)presentedItemDidMoveToURL:(NSURL*)newURL;

@optional
- (void)presentedItemDidChange;

@optional
- (void)presentedItemDidGainVersion:(NSFileVersion*)version;

@optional
- (void)presentedItemDidLoseVersion:(NSFileVersion*)version;

@optional
- (void)presentedItemDidResolveConflictVersion:(NSFileVersion*)version;

@optional
- (void)presentedSubitemAtURL:(NSURL*)url didGainVersion:(NSFileVersion*)version;

@optional
- (void)presentedSubitemAtURL:(NSURL*)url didLoseVersion:(NSFileVersion*)version;

@optional
- (void)presentedSubitemAtURL:(NSURL*)url didResolveConflictVersion:(NSFileVersion*)version;

@optional
- (void)accommodatePresentedSubitemDeletionAtURL:(NSURL*)url completionHandler:(void (^)(NSError* errorOrNil))completionHandler;

@optional
- (void)presentedSubitemDidAppearAtURL:(NSURL*)url;

@optional
- (void)presentedSubitemAtURL:(NSURL*)oldURL didMoveToURL:(NSURL*)newURL;

@optional
- (void)presentedSubitemDidChangeAtURL:(NSURL*)url;

@end
