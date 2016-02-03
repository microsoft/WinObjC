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
@class WKPreferences;
@class WKProcessPool;
@class WKUserContentController;
@class WKWebsiteDataStore;

typedef NS_ENUM(NSInteger, WKSelectionGranularity) { WKSelectionGranularityDynamic, WKSelectionGranularityCharacter };

WEBKIT_EXPORT_CLASS
@interface WKWebViewConfiguration : NSObject <NSCopying>
@property (nonatomic, copy) NSString* applicationNameForUserAgent;
@property (nonatomic, strong) WKPreferences* preferences;
@property (nonatomic, strong) WKProcessPool* processPool;
@property (nonatomic, strong) WKUserContentController* userContentController;
@property (nonatomic, strong) WKWebsiteDataStore* websiteDataStore;
@property (nonatomic) BOOL suppressesIncrementalRendering;
@property (nonatomic) BOOL allowsInlineMediaPlayback;
@property (nonatomic) BOOL allowsAirPlayForMediaPlayback;
@property (nonatomic) BOOL mediaPlaybackAllowsAirPlay;
@property (nonatomic) BOOL requiresUserActionForMediaPlayback;
@property (nonatomic) BOOL mediaPlaybackRequiresUserAction;
@property (nonatomic) BOOL allowsPictureInPictureMediaPlayback;
@property (nonatomic) WKSelectionGranularity selectionGranularity;
@end
