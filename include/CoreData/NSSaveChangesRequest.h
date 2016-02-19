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
#import <CoreData/NSPersistentStoreRequest.h>

@class NSSet;

COREDATA_EXPORT_CLASS
@interface NSSaveChangesRequest : NSPersistentStoreRequest <NSCopying>
- (instancetype)initWithInsertedObjects:(NSSet*)insertedObjects
                         updatedObjects:(NSSet*)updatedObjects
                         deletedObjects:(NSSet*)deletedObjects
                          lockedObjects:(NSSet*)lockedObjects STUB_METHOD;
@property (readonly, strong) NSSet* insertedObjects STUB_PROPERTY;
@property (readonly, strong) NSSet* updatedObjects STUB_PROPERTY;
@property (readonly, strong) NSSet* deletedObjects STUB_PROPERTY;
@property (readonly, strong) NSSet* lockedObjects STUB_PROPERTY;
@end
