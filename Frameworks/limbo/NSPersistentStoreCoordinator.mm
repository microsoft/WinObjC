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

#include "CoreData/NSPersistentStoreCoordinator.h"

NSString* const NSStoreTypeKey = @"NSStoreTypeKey";
NSString* const NSStoreUUIDKey = @"NSStoreUUIDKey";

NSString* const NSXMLStoreType = @"NSXMLStoreType";
NSString* const NSInMemoryStoreType = @"NSInMemoryStoreType";
NSString* const NSMigratePersistentStoresAutomaticallyOption = @"NSMigratePersistentStoresAutomaticallyOption";

NSString* const NSPersistentStoreCoordinatorStoresDidChangeNotification = @"NSPersistentStoreCoordinatorStoresDidChangeNotification";
NSString* const NSAddedPersistentStoresKey = @"NSAddedPersistentStoresKey";
NSString* const NSRemovedPersistentStoresKey = @"NSRemovedPersistentStoresKey";
NSString* const NSUUIDChangedPersistentStoresKey = @"NSUUIDChangedPersistentStoresKey";

NSString* const NSPersistentStoreDidImportUbiquitousContentChangesNotification =
    @"NSPersistentStoreDidImportUbiquitousContentChangesNotification";

NSString* const NSReadOnlyPersistentStoreOption = @"NSReadOnlyPersistentStoreOption";
NSString* const NSPersistentStoreTimeoutOption = @"NSPersistentStoreTimeoutOption";
NSString* const NSSQLitePragmasOption = @"NSSQLitePragmasOption";
NSString* const NSSQLiteAnalyzeOption = @"NSSQLiteAnalyzeOption";
NSString* const NSSQLiteManualVacuumOption = @"NSSQLiteManualVacuumOption";
NSString* const NSPersistentStoreUbiquitousContentNameKey = @"NSPersistentStoreUbiquitousContentNameKey";
NSString* const NSPersistentStoreUbiquitousContentURLKey = @"NSPersistentStoreUbiquitousContentURLKey";
NSString* const NSPersistentStoreFileProtectionKey = @"NSPersistentStoreFileProtectionKey";

NSString* const NSIgnorePersistentStoreVersioningOption = @"NSIgnorePersistentStoreVersioningOption";
NSString* const NSInferMappingModelAutomaticallyOption = @"NSInferMappingModelAutomaticallyOption";

NSString* const NSSQLiteStoreType = @"NSSQLiteStoreType";
NSString* const NSBinaryStoreType = @"NSBinaryStoreType";

@implementation NSPersistentStoreCoordinator

@end