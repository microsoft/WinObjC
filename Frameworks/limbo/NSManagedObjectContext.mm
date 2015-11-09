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

#import <CoreData/NSManagedObjectContext.h>

NSString* const NSManagedObjectContextWillSaveNotification = @"NSManagedObjectContextWillSaveNotification";
NSString* const NSManagedObjectContextDidSaveNotification = @"NSManagedObjectContextDidSaveNotification";
NSString* const NSManagedObjectContextObjectsDidChangeNotification = @"NSManagedObjectContextObjectsDidChangeNotification";

NSString* const NSInsertedObjectsKey = @"NSInsertedObjectsKey";
NSString* const NSUpdatedObjectsKey = @"NSUpdatedObjectsKey";
NSString* const NSDeletedObjectsKey = @"NSDeletedObjectsKey";
NSString* const NSRefreshedObjectsKey = @"NSRefreshedObjectsKey";
NSString* const NSInvalidatedObjectsKey = @"NSInvalidatedObjectsKey";
NSString* const NSInvalidatedAllObjectsKey = @"NSInvalidatedAllObjectsKey";

@implementation NSManagedObjectContext

@end