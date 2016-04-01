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

#import <UIKit/UIKitExport.h>
#import <Foundation/NSFilePresenter.h>
#import <Foundation/NSObject.h>
#import <Foundation/NSProgressReporting.h>

@class NSString, NSURL, NSDate, NSError, NSDictionary, NSUndoManager, NSUserActivity;

typedef NSInteger UIDocumentChangeKind;
enum {
    UIDocumentChangeDone,
    UIDocumentChangeUndone,
    UIDocumentChangeRedone,
    UIDocumentChangeCleared,
};

typedef NSInteger UIDocumentSaveOperation;
enum {
    UIDocumentSaveForCreating,
    UIDocumentSaveForOverwriting,
};

typedef NSInteger UIDocumentState;
enum {
    UIDocumentStateNormal = 0,
    UIDocumentStateClosed = 1 << 0,
    UIDocumentStateInConflict = 1 << 1,
    UIDocumentStateSavingError = 1 << 2,
    UIDocumentStateEditingDisabled = 1 << 3,
    UIDocumentStateProgressAvailable = 1 << 4,
};

UIKIT_EXPORT NSString* const NSUserActivityDocumentURLKey;
UIKIT_EXPORT NSString* const UIDocumentStateChangedNotification;

UIKIT_EXPORT_CLASS
@interface UIDocument : NSObject <NSFilePresenter, NSObject, NSProgressReporting>
- (instancetype)initWithFileURL:(NSURL*)url STUB_METHOD;
@property (readonly) NSURL* fileURL STUB_PROPERTY;
@property (readonly, copy) NSString* localizedName STUB_PROPERTY;
@property (readonly, copy) NSString* fileType STUB_PROPERTY;
@property (copy) NSDate* fileModificationDate STUB_PROPERTY;
@property (readonly) UIDocumentState documentState STUB_PROPERTY;
- (void)closeWithCompletionHandler:(void (^)(BOOL))completionHandler STUB_METHOD;
- (id)contentsForType:(NSString*)typeName error:(NSError* _Nullable*)outError STUB_METHOD;
- (void)saveToURL:(NSURL*)url
 forSaveOperation:(UIDocumentSaveOperation)saveOperation
completionHandler:(void (^)(BOOL))completionHandler STUB_METHOD;
- (BOOL)writeContents:(id)contents
        andAttributes:(NSDictionary*)additionalFileAttributes
          safelyToURL:(NSURL*)url
     forSaveOperation:(UIDocumentSaveOperation)saveOperation
                error:(NSError* _Nullable*)outError STUB_METHOD;
- (BOOL)writeContents:(id)contents
                toURL:(NSURL*)url
     forSaveOperation:(UIDocumentSaveOperation)saveOperation
  originalContentsURL:(NSURL*)originalContentsURL
                error:(NSError* _Nullable*)outError STUB_METHOD;
- (NSString*)savingFileType STUB_METHOD;
- (NSDictionary*)fileAttributesToWriteToURL:(NSURL*)url
                           forSaveOperation:(UIDocumentSaveOperation)saveOperation
                                      error:(NSError* _Nullable*)outError STUB_METHOD;
- (NSString*)fileNameExtensionForType:(NSString*)typeName saveOperation:(UIDocumentSaveOperation)saveOperation STUB_METHOD;
- (void)openWithCompletionHandler:(void (^)(BOOL))completionHandler STUB_METHOD;
- (BOOL)loadFromContents:(id)contents ofType:(NSString*)typeName error:(NSError* _Nullable*)outError STUB_METHOD;
- (BOOL)readFromURL:(NSURL*)url error:(NSError* _Nullable*)outError STUB_METHOD;
- (void)performAsynchronousFileAccessUsingBlock:(void (^)(void))block STUB_METHOD;
- (void)revertToContentsOfURL:(NSURL*)url completionHandler:(void (^)(BOOL))completionHandler STUB_METHOD;
- (void)disableEditing STUB_METHOD;
- (void)enableEditing STUB_METHOD;
- (BOOL)hasUnsavedChanges STUB_METHOD;
- (void)updateChangeCount:(UIDocumentChangeKind)change STUB_METHOD;
@property (strong) NSUndoManager* undoManager STUB_PROPERTY;
- (id)changeCountTokenForSaveOperation:(UIDocumentSaveOperation)saveOperation STUB_METHOD;
- (void)updateChangeCountWithToken:(id)changeCountToken forSaveOperation:(UIDocumentSaveOperation)saveOperation STUB_METHOD;
- (void)autosaveWithCompletionHandler:(void (^)(BOOL))completionHandler STUB_METHOD;
@property (nonatomic, strong) NSUserActivity* userActivity STUB_PROPERTY;
- (void)restoreUserActivityState:(NSUserActivity*)activity STUB_METHOD;
- (void)updateUserActivityState:(NSUserActivity*)activity STUB_METHOD;
- (void)handleError:(NSError*)error userInteractionPermitted:(BOOL)userInteractionPermitted STUB_METHOD;
- (void)finishedHandlingError:(NSError*)error recovered:(BOOL)recovered STUB_METHOD;
- (void)userInteractionNoLongerPermittedForError:(NSError*)error STUB_METHOD;

@property (readonly, copy) NSURL* presentedItemURL STUB_PROPERTY;
@property (readonly, retain) NSOperationQueue* presentedItemOperationQueue STUB_PROPERTY;
@property (readonly) NSProgress* progress STUB_PROPERTY;

@end
