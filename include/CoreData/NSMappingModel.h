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

@class NSArray;
@class NSManagedObjectModel;
@class NSError;
@class NSURL;
@class NSDictionary;

COREDATA_EXPORT_CLASS
@interface NSMappingModel : NSObject
+ (NSMappingModel*)mappingModelFromBundles:(NSArray*)bundles
                            forSourceModel:(NSManagedObjectModel*)sourceModel
                          destinationModel:(NSManagedObjectModel*)destinationModel STUB_METHOD;
+ (NSMappingModel*)inferredMappingModelForSourceModel:(NSManagedObjectModel*)source
                                     destinationModel:(NSManagedObjectModel*)destination
                                                error:(NSError* _Nullable*)error STUB_METHOD;
- (instancetype)initWithContentsOfURL:(NSURL*)url STUB_METHOD;
@property (strong) NSArray* entityMappings STUB_PROPERTY;
@property (readonly, copy) NSDictionary* entityMappingsByName STUB_PROPERTY;
@end
