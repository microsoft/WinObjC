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

#ifndef _UIDOCUMENT_H_
#define _UIDOCUMENT_H_

#import <Foundation/NSObject.h>

@class NSUndoManager;
@class NSURL;
@class NSError;

enum {
    UIDocumentSaveForCreating,
    UIDocumentSaveForOverwriting
};
typedef uint32_t UIDocumentSaveOperation;

extern NSString *const UIDocumentStateChangedNotification;

enum {
    UIDocumentStateNormal = 0,
    UIDocumentStateClosed = 1,
    UIDocumentStateInConflict = 2,
    UIDocumentStateSavingError = 4,
    UIDocumentStateEditingDisabled = 8
};
typedef uint32_t UIDocumentState;

enum {
   UIDocumentChangeDone,
   UIDocumentChangeUndone,
   UIDocumentChangeRedone,
   UIDocumentChangeCleared
};
typedef int32_t UIDocumentChangeKind;

@interface UIDocument : NSObject

@property (readonly) NSURL *fileURL;
@property (retain) NSUndoManager *undoManager;
@property (readonly) UIDocumentState documentState;
@property (readonly, copy) NSString *fileType;

- (id)initWithFileURL:(NSURL *)url;
- (void)saveToURL:(NSURL *)url forSaveOperation:(UIDocumentSaveOperation)saveOperation completionHandler:(void (^)(BOOL success))completionHandler;
- (void)openWithCompletionHandler:(void (^)(BOOL success))completionHandler;
- (void)closeWithCompletionHandler:(void (^)(BOOL success))completionHandler;
- (BOOL)writeContents:(id)contents toURL:(NSURL *)url forSaveOperation:(UIDocumentSaveOperation)saveOperation originalContentsURL:(NSURL *)originalContentsURL error:(NSError **)outError;
- (void)handleError:(NSError *)error userInteractionPermitted:(BOOL)userInteractionPermitted;
- (void)updateChangeCount:(UIDocumentChangeKind)change;
- (BOOL)hasUnsavedChanges;

@end

#endif /* _UIDOCUMENT_H_ */