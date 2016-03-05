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

@class NSManagedObjectID;
@class NSDictionary;
@class NSPropertyDescription;

COREDATA_EXPORT_CLASS
@interface NSIncrementalStoreNode : NSObject
- (instancetype)initWithObjectID:(NSManagedObjectID*)objectID withValues:(NSDictionary*)values version:(uint64_t)version STUB_METHOD;
@property (readonly, nonatomic, strong) NSManagedObjectID* objectID STUB_PROPERTY;
- (void)updateWithValues:(NSDictionary*)values version:(uint64_t)version STUB_METHOD;
- (id)valueForPropertyDescription:(NSPropertyDescription*)prop STUB_METHOD;
@property (readonly, nonatomic) uint64_t version STUB_PROPERTY;
@end
