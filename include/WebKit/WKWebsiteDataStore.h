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

#import <WebKit/WebKitExport.h>
#import <Foundation/NSObject.h>

@class NSSet;
@class NSArray;
@class NSDate;

WEBKIT_EXPORT_CLASS
@interface WKWebsiteDataStore : NSObject
+ (NSSet*)allWebsiteDataTypes;
+ (WKWebsiteDataStore*)defaultDataStore;
+ (WKWebsiteDataStore*)nonPersistentDataStore;
@property (nonatomic, readonly, getter=isPersistent) BOOL persistent;
- (void)fetchDataRecordsOfTypes:(NSSet*)dataTypes completionHandler:(void (^)(NSArray*))completionHandler;
- (void)removeDataOfTypes:(NSSet*)dataTypes forDataRecords:(NSArray*)dataRecords completionHandler:(void (^)(void))completionHandler;
- (void)removeDataOfTypes:(NSSet*)websiteDataTypes modifiedSince:(NSDate*)date completionHandler:(void (^)(void))completionHandler;
@end
