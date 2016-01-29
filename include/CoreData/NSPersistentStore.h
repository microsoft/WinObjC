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

#import <CoreData/CoreDataExport.h>
#import <Foundation/NSObject.h>

@class NSPersistentStoreCoordinator;
@class NSString;
@class NSURL;
@class NSDictionary;
@class NSError;

COREDATA_EXPORT_CLASS
@interface NSPersistentStore : NSObject
- (instancetype)initWithPersistentStoreCoordinator:(NSPersistentStoreCoordinator*)coordinator
                                 configurationName:(NSString*)configurationName
                                               URL:(NSURL*)url
                                           options:(NSDictionary*)options STUB_METHOD;
@property (readonly, copy) NSString* type STUB_PROPERTY;
@property (readonly, nonatomic, assign) NSPersistentStoreCoordinator* persistentStoreCoordinator STUB_PROPERTY;
@property (readonly, copy) NSString* configurationName STUB_PROPERTY;
@property (readonly, strong) NSDictionary* options STUB_PROPERTY;
@property (strong) NSURL* URL STUB_PROPERTY;
@property (copy) NSString* identifier STUB_PROPERTY;
@property (getter=isReadOnly) BOOL readOnly STUB_PROPERTY;
+ (NSDictionary*)metadataForPersistentStoreWithURL:(NSURL*)url error:(NSError* _Nullable*)error STUB_METHOD;
+ (BOOL)setMetadata:(NSDictionary*)metadata forPersistentStoreWithURL:(NSURL*)url error:(NSError* _Nullable*)error STUB_METHOD;
@property (nonatomic, strong) NSDictionary* metadata STUB_PROPERTY;
- (BOOL)loadMetadata:(NSError* _Nullable*)error STUB_METHOD;
- (void)didAddToPersistentStoreCoordinator:(NSPersistentStoreCoordinator*)coordinator STUB_METHOD;
- (void)willRemoveFromPersistentStoreCoordinator:(NSPersistentStoreCoordinator*)coordinator STUB_METHOD;
+ (Class)migrationManagerClass STUB_METHOD;
@end
