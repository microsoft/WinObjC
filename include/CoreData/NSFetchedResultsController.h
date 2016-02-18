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

@class NSFetchRequest;
@class NSManagedObjectContext;
@class NSString;
@class NSError;
@class NSArray;
@class NSIndexPath;

@protocol NSFetchedResultsControllerDelegate;

typedef NS_ENUM(NSUInteger, NSFetchedResultsChangeType) {
    NSFetchedResultsChangeInsert = 1,
    NSFetchedResultsChangeDelete = 2,
    NSFetchedResultsChangeMove = 3,
    NSFetchedResultsChangeUpdate = 4
};

COREDATA_EXPORT_CLASS
@interface NSFetchedResultsController : NSObject
- (instancetype)initWithFetchRequest:(NSFetchRequest*)fetchRequest
                managedObjectContext:(NSManagedObjectContext*)context
                  sectionNameKeyPath:(NSString*)sectionNameKeyPath
                           cacheName:(NSString*)name STUB_METHOD;
- (BOOL)performFetch:(NSError* _Nullable*)error STUB_METHOD;
@property (readonly, nonatomic) NSFetchRequest* fetchRequest STUB_PROPERTY;
@property (readonly, nonatomic) NSManagedObjectContext* managedObjectContext STUB_PROPERTY;
@property (readonly, nonatomic) NSString* sectionNameKeyPath STUB_PROPERTY;
@property (readonly, nonatomic) NSString* cacheName STUB_PROPERTY;
@property (assign, nonatomic) id<NSFetchedResultsControllerDelegate> delegate STUB_PROPERTY;
+ (void)deleteCacheWithName:(NSString*)name STUB_METHOD;
@property (readonly, nonatomic) NSArray* fetchedObjects STUB_PROPERTY;
- (id)objectAtIndexPath:(NSIndexPath*)indexPath STUB_METHOD;
- (NSIndexPath*)indexPathForObject:(id)object STUB_METHOD;
@property (readonly, nonatomic) NSArray* sections STUB_PROPERTY;
- (NSInteger)sectionForSectionIndexTitle:(NSString*)title atIndex:(NSInteger)sectionIndex STUB_METHOD;
- (NSString*)sectionIndexTitleForSectionName:(NSString*)sectionName STUB_METHOD;
@property (readonly, nonatomic) NSArray* sectionIndexTitles STUB_PROPERTY;
@end

@protocol NSFetchedResultsSectionInfo
@required
@property (nonatomic, readonly) NSUInteger numberOfObjects;
@property (nonatomic, readonly) NSArray* objects;
@property (nonatomic, readonly) NSString* name;
@property (nonatomic, readonly) NSString* indexTitle;
@end

@protocol NSFetchedResultsControllerDelegate <NSObject>
@optional
- (void)controllerWillChangeContent:(NSFetchedResultsController*)controller;
- (void)controller:(NSFetchedResultsController*)controller
   didChangeObject:(id)anObject
       atIndexPath:(NSIndexPath*)indexPath
     forChangeType:(NSFetchedResultsChangeType)type
      newIndexPath:(NSIndexPath*)newIndexPath;
- (void)controller:(NSFetchedResultsController*)controller
  didChangeSection:(id<NSFetchedResultsSectionInfo>)sectionInfo
           atIndex:(NSUInteger)sectionIndex
     forChangeType:(NSFetchedResultsChangeType)type;
- (void)controllerDidChangeContent:(NSFetchedResultsController*)controller;
- (NSString*)controller:(NSFetchedResultsController*)controller sectionIndexTitleForSectionName:(NSString*)sectionName;
@end
