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

@class NSString;
@class NSSet;

WEBKIT_EXPORT NSString* const WKWebsiteDataTypeDiskCache;
WEBKIT_EXPORT NSString* const WKWebsiteDataTypeMemoryCache;
WEBKIT_EXPORT NSString* const WKWebsiteDataTypeOfflineWebApplicationCache;
WEBKIT_EXPORT NSString* const WKWebsiteDataTypeCookies;
WEBKIT_EXPORT NSString* const WKWebsiteDataTypeSessionStorage;
WEBKIT_EXPORT NSString* const WKWebsiteDataTypeLocalStorage;
WEBKIT_EXPORT NSString* const WKWebsiteDataTypeWebSQLDatabases;
WEBKIT_EXPORT NSString* const WKWebsiteDataTypeIndexedDBDatabases;

WEBKIT_EXPORT_CLASS
@interface WKWebsiteDataRecord : NSObject
@property (nonatomic, readonly, copy) NSSet* dataTypes;
@property (nonatomic, readonly, copy) NSString* displayName;
@end
