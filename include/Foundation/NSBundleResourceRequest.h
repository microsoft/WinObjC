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

#import <Foundation/FoundationExport.h>
#import <Foundation/NSObject.h>
#import <Foundation/NSProgressReporting.h>

@class NSSet;
@class NSBundle;
@class NSError;
@class NSProgress;

FOUNDATION_EXPORT const double NSBundleResourceRequestLoadingPriorityUrgent;
enum {
    NSBundleOnDemandResourceOutOfSpaceError = 4992,
    NSBundleOnDemandResourceExceededMaximumSizeError = 4993,
    NSBundleOnDemandResourceInvalidTagError = 4994,
}; // Missing declaration of //apple_ref/c/data/NSBundleResourceRequestLowDiskSpaceNotification

FOUNDATION_EXPORT_CLASS
@interface NSBundleResourceRequest : NSObject <NSProgressReporting>
- (instancetype)initWithTags:(NSSet*)tags STUB_METHOD;
- (instancetype)initWithTags:(NSSet*)tags bundle:(NSBundle*)bundle STUB_METHOD;
@property (readonly, strong) NSBundle* bundle STUB_PROPERTY;
@property (readonly, copy) NSSet* tags STUB_PROPERTY;
- (void)beginAccessingResourcesWithCompletionHandler:(void (^)(NSError*))completionHandler STUB_METHOD;
- (void)conditionallyBeginAccessingResourcesWithCompletionHandler:(void (^)(BOOL))completionHandler STUB_METHOD;
- (void)endAccessingResources STUB_METHOD;
@property double loadingPriority STUB_PROPERTY;
@property (readonly, strong) NSProgress* progress STUB_PROPERTY;
@end
