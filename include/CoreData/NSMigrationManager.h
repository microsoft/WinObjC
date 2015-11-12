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

#ifndef _NSMIGRATIONMANAGER_H_
#define _NSMIGRATIONMANAGER_H_

#import <Foundation/NSObject.h>

@class NSMappingModel;
@class NSManagedObjectModel;
@class NSURL;
@class NSDictionary;
@class NSError;

@interface NSMigrationManager : NSObject

- (id)initWithSourceModel:(NSManagedObjectModel*)sourceModel destinationModel:(NSManagedObjectModel*)destinationModel;
- (BOOL)migrateStoreFromURL:(NSURL*)sourceURL
                       type:(NSString*)sStoreType
                    options:(NSDictionary*)sOptions
           withMappingModel:(NSMappingModel*)mappings
           toDestinationURL:(NSURL*)dURL
            destinationType:(NSString*)dStoreType
         destinationOptions:(NSDictionary*)dOptions
                      error:(NSError**)error;

@end

#endif /* _NSMIGRATIONMANAGER_H_ */