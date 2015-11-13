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

#import <Foundation/NSObject.h>

@class NSPersistentStoreCoordinator, NSURL, NSDictionary, NSError;

@interface NSPersistentStore : NSObject

+ (NSDictionary*)metadataForPersistentStoreWithURL:(NSURL*)url error:(NSError**)error;
+ (BOOL)setMetadata:(NSDictionary*)metadata forPersistentStoreWithURL:(NSURL*)url error:(NSError**)error;

+ (Class)migrationManagerClass;

- initWithPersistentStoreCoordinator:(NSPersistentStoreCoordinator*)root
                   configurationName:(NSString*)name
                                 URL:(NSURL*)url
                             options:(NSDictionary*)options;

- (NSString*)type;
- (NSPersistentStoreCoordinator*)persistentStoreCoordinator;
- (NSString*)configurationName;
- (NSURL*)URL;
- (NSDictionary*)options;

- (BOOL)isReadOnly;
- (NSString*)identifier;
- (NSDictionary*)metadata;

- (void)setURL:(NSURL*)value;
- (void)setReadOnly:(BOOL)value;
- (void)setIdentifier:(NSString*)value;
- (void)setMetadata:(NSDictionary*)value;

- (BOOL)loadMetadata:(NSError**)error;

- (void)willRemoveFromPersistentStoreCoordinator:(NSPersistentStoreCoordinator*)coordinator;
- (void)didAddToPersistentStoreCoordinator:(NSPersistentStoreCoordinator*)coordinator;

@end
