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

@class NSManagedObject;
@class NSDictionary;

COREDATA_EXPORT_CLASS
@interface NSMergeConflict : NSObject
- (instancetype)initWithSource:(NSManagedObject*)srcObject
                    newVersion:(NSUInteger)newvers
                    oldVersion:(NSUInteger)oldvers
                cachedSnapshot:(NSDictionary*)cachesnap
             persistedSnapshot:(NSDictionary*)persnap STUB_METHOD;
@property (readonly, retain) NSManagedObject* sourceObject STUB_PROPERTY;
@property (readonly, retain) NSDictionary* objectSnapshot STUB_PROPERTY;
@property (readonly, retain) NSDictionary* cachedSnapshot STUB_PROPERTY;
@property (readonly, retain) NSDictionary* persistedSnapshot STUB_PROPERTY;
@property (readonly) NSUInteger newVersionNumber STUB_PROPERTY;
@property (readonly) NSUInteger oldVersionNumber STUB_PROPERTY;
@end
