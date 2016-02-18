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

#include "Starboard.h"

#import <StubReturn.h>
#import "UIKit/UIDocument.h"

NSString* const UIDocumentStateChangedNotification = @"UIDocumentStateChangedNotification";
NSString* const NSUserActivityDocumentURLKey = @"NSUserActivityDocumentURLKey";

@implementation UIDocument
/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithFileURL:(NSURL*)url {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)closeWithCompletionHandler:(void (^)(BOOL))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (id)contentsForType:(NSString*)typeName error:(NSError* _Nullable*)outError {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)saveToURL:(NSURL*)url forSaveOperation:(UIDocumentSaveOperation)saveOperation completionHandler:(void (^)(BOOL))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)writeContents:(id)contents
        andAttributes:(NSDictionary*)additionalFileAttributes
          safelyToURL:(NSURL*)url
     forSaveOperation:(UIDocumentSaveOperation)saveOperation
                error:(NSError* _Nullable*)outError {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)writeContents:(id)contents
                toURL:(NSURL*)url
     forSaveOperation:(UIDocumentSaveOperation)saveOperation
  originalContentsURL:(NSURL*)originalContentsURL
                error:(NSError* _Nullable*)outError {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSString*)savingFileType {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSDictionary*)fileAttributesToWriteToURL:(NSURL*)url
                           forSaveOperation:(UIDocumentSaveOperation)saveOperation
                                      error:(NSError* _Nullable*)outError {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSString*)fileNameExtensionForType:(NSString*)typeName saveOperation:(UIDocumentSaveOperation)saveOperation {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)openWithCompletionHandler:(void (^)(BOOL))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)loadFromContents:(id)contents ofType:(NSString*)typeName error:(NSError* _Nullable*)outError {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)readFromURL:(NSURL*)url error:(NSError* _Nullable*)outError {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)performAsynchronousFileAccessUsingBlock:(void (^)(void))block {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)revertToContentsOfURL:(NSURL*)url completionHandler:(void (^)(BOOL))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)disableEditing {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)enableEditing {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)hasUnsavedChanges {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)updateChangeCount:(UIDocumentChangeKind)change {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (id)changeCountTokenForSaveOperation:(UIDocumentSaveOperation)saveOperation {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)updateChangeCountWithToken:(id)changeCountToken forSaveOperation:(UIDocumentSaveOperation)saveOperation {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)autosaveWithCompletionHandler:(void (^)(BOOL))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)restoreUserActivityState:(NSUserActivity*)activity {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)updateUserActivityState:(NSUserActivity*)activity {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)handleError:(NSError*)error userInteractionPermitted:(BOOL)userInteractionPermitted {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)finishedHandlingError:(NSError*)error recovered:(BOOL)recovered {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)userInteractionNoLongerPermittedForError:(NSError*)error {
    UNIMPLEMENTED();
}

@end