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

// WindowsMediaContentRestrictions.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WMCRatedContentDescription, WMCContentRestrictionsBrowsePolicy, WMCRatedContentRestrictions;
@protocol WMCIRatedContentDescription
, WMCIRatedContentDescriptionFactory, WMCIContentRestrictionsBrowsePolicy, WMCIRatedContentRestrictions,
    WMCIRatedContentRestrictionsFactory;

// Windows.Media.ContentRestrictions.RatedContentCategory
enum _WMCRatedContentCategory {
    WMCRatedContentCategoryGeneral = 0,
    WMCRatedContentCategoryApplication = 1,
    WMCRatedContentCategoryGame = 2,
    WMCRatedContentCategoryMovie = 3,
    WMCRatedContentCategoryTelevision = 4,
    WMCRatedContentCategoryMusic = 5,
};
typedef unsigned WMCRatedContentCategory;

// Windows.Media.ContentRestrictions.ContentAccessRestrictionLevel
enum _WMCContentAccessRestrictionLevel {
    WMCContentAccessRestrictionLevelAllow = 0,
    WMCContentAccessRestrictionLevelWarn = 1,
    WMCContentAccessRestrictionLevelBlock = 2,
    WMCContentAccessRestrictionLevelHide = 3,
};
typedef unsigned WMCContentAccessRestrictionLevel;

#include "WindowsFoundationCollections.h"
#include "WindowsStorageStreams.h"
#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.Media.ContentRestrictions.RatedContentDescription
#ifndef __WMCRatedContentDescription_DEFINED__
#define __WMCRatedContentDescription_DEFINED__

WINRT_EXPORT
@interface WMCRatedContentDescription : RTObject
+ (WMCRatedContentDescription*)create:(NSString*)id title:(NSString*)title category:(WMCRatedContentCategory)category ACTIVATOR;
@property (copy) NSString* title;
@property (copy) NSMutableArray* ratings;
@property (copy) RTObject<WSSIRandomAccessStreamReference>* image;
@property (copy) NSString* id;
@property WMCRatedContentCategory category;
@end

#endif // __WMCRatedContentDescription_DEFINED__

// Windows.Media.ContentRestrictions.ContentRestrictionsBrowsePolicy
#ifndef __WMCContentRestrictionsBrowsePolicy_DEFINED__
#define __WMCContentRestrictionsBrowsePolicy_DEFINED__

WINRT_EXPORT
@interface WMCContentRestrictionsBrowsePolicy : RTObject
@property (readonly) NSString* geographicRegion;
@property (readonly) id maxBrowsableAgeRating;
@property (readonly) id preferredAgeRating;
@end

#endif // __WMCContentRestrictionsBrowsePolicy_DEFINED__

// Windows.Media.ContentRestrictions.RatedContentRestrictions
#ifndef __WMCRatedContentRestrictions_DEFINED__
#define __WMCRatedContentRestrictions_DEFINED__

WINRT_EXPORT
@interface WMCRatedContentRestrictions : RTObject
+ (instancetype)create ACTIVATOR;
+ (WMCRatedContentRestrictions*)createWithMaxAgeRating:(unsigned int)maxAgeRating ACTIVATOR;
- (EventRegistrationToken)addRestrictionsChangedEvent:(void (^)(RTObject*, RTObject*))del;
- (void)removeRestrictionsChangedEvent:(EventRegistrationToken)tok;
- (void)getBrowsePolicyAsyncWithSuccess:(void (^)(WMCContentRestrictionsBrowsePolicy*))success failure:(void (^)(NSError*))failure;
- (void)getRestrictionLevelAsync:(WMCRatedContentDescription*)RatedContentDescription
                         success:(void (^)(WMCContentAccessRestrictionLevel))success
                         failure:(void (^)(NSError*))failure;
- (void)requestContentAccessAsync:(WMCRatedContentDescription*)RatedContentDescription
                          success:(void (^)(BOOL))success
                          failure:(void (^)(NSError*))failure;
@end

#endif // __WMCRatedContentRestrictions_DEFINED__
