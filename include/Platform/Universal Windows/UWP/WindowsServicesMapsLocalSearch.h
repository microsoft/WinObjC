//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

// WindowsServicesMapsLocalSearch.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSSERVICESMAPSLOCALSEARCHEXPORT
#define OBJCUWPWINDOWSSERVICESMAPSLOCALSEARCHEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsServicesMapsLocalSearch.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WSMLLocalLocation, WSMLLocalLocationFinderResult, WSMLLocalLocationRatingInfo, WSMLLocalLocationHoursOfOperationItem, WSMLLocalLocationFinder, WSMLLocalCategories, WSMLPlaceInfoHelper;
@protocol WSMLILocalLocation, WSMLILocalLocationFinderResult, WSMLILocalLocationFinderStatics, WSMLILocalCategoriesStatics, WSMLILocalLocationHoursOfOperationItem, WSMLILocalLocationRatingInfo, WSMLILocalLocation2, WSMLIPlaceInfoHelperStatics;

// Windows.Services.Maps.LocalSearch.LocalLocationFinderStatus
enum _WSMLLocalLocationFinderStatus {
    WSMLLocalLocationFinderStatusSuccess = 0,
    WSMLLocalLocationFinderStatusUnknownError = 1,
    WSMLLocalLocationFinderStatusInvalidCredentials = 2,
    WSMLLocalLocationFinderStatusInvalidCategory = 3,
    WSMLLocalLocationFinderStatusInvalidSearchTerm = 4,
    WSMLLocalLocationFinderStatusInvalidSearchArea = 5,
    WSMLLocalLocationFinderStatusNetworkFailure = 6,
    WSMLLocalLocationFinderStatusNotSupported = 7,
};
typedef unsigned WSMLLocalLocationFinderStatus;

#include "WindowsServicesMaps.h"
#include "WindowsGlobalization.h"
#include "WindowsDevicesGeolocation.h"
#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.Services.Maps.LocalSearch.LocalLocation
#ifndef __WSMLLocalLocation_DEFINED__
#define __WSMLLocalLocation_DEFINED__

OBJCUWPWINDOWSSERVICESMAPSLOCALSEARCHEXPORT
@interface WSMLLocalLocation : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSMMapAddress* address;
@property (readonly) NSString * dataAttribution;
@property (readonly) NSString * Description;
@property (readonly) NSString * displayName;
@property (readonly) NSString * identifier;
@property (readonly) NSString * phoneNumber;
@property (readonly) WDGGeopoint* point;
@property (readonly) NSString * category;
@property (readonly) NSArray* /* WSMLLocalLocationHoursOfOperationItem* */ hoursOfOperation;
@property (readonly) WSMLLocalLocationRatingInfo* ratingInfo;
@end

#endif // __WSMLLocalLocation_DEFINED__

// Windows.Services.Maps.LocalSearch.LocalLocationFinderResult
#ifndef __WSMLLocalLocationFinderResult_DEFINED__
#define __WSMLLocalLocationFinderResult_DEFINED__

OBJCUWPWINDOWSSERVICESMAPSLOCALSEARCHEXPORT
@interface WSMLLocalLocationFinderResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* WSMLLocalLocation* */ localLocations;
@property (readonly) WSMLLocalLocationFinderStatus status;
@end

#endif // __WSMLLocalLocationFinderResult_DEFINED__

// Windows.Services.Maps.LocalSearch.LocalLocationRatingInfo
#ifndef __WSMLLocalLocationRatingInfo_DEFINED__
#define __WSMLLocalLocationRatingInfo_DEFINED__

OBJCUWPWINDOWSSERVICESMAPSLOCALSEARCHEXPORT
@interface WSMLLocalLocationRatingInfo : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) id /* double */ aggregateRating;
@property (readonly) NSString * providerIdentifier;
@property (readonly) id /* int */ ratingCount;
@end

#endif // __WSMLLocalLocationRatingInfo_DEFINED__

// Windows.Services.Maps.LocalSearch.LocalLocationHoursOfOperationItem
#ifndef __WSMLLocalLocationHoursOfOperationItem_DEFINED__
#define __WSMLLocalLocationHoursOfOperationItem_DEFINED__

OBJCUWPWINDOWSSERVICESMAPSLOCALSEARCHEXPORT
@interface WSMLLocalLocationHoursOfOperationItem : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WGDayOfWeek day;
@property (readonly) WFTimeSpan* span;
@property (readonly) WFTimeSpan* start;
@end

#endif // __WSMLLocalLocationHoursOfOperationItem_DEFINED__

// Windows.Services.Maps.LocalSearch.LocalLocationFinder
#ifndef __WSMLLocalLocationFinder_DEFINED__
#define __WSMLLocalLocationFinder_DEFINED__

OBJCUWPWINDOWSSERVICESMAPSLOCALSEARCHEXPORT
@interface WSMLLocalLocationFinder : RTObject
+ (void)findLocalLocationsAsync:(NSString *)searchTerm searchArea:(WDGGeocircle*)searchArea localCategory:(NSString *)localCategory maxResults:(unsigned int)maxResults success:(void (^)(WSMLLocalLocationFinderResult*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSMLLocalLocationFinder_DEFINED__

// Windows.Services.Maps.LocalSearch.LocalCategories
#ifndef __WSMLLocalCategories_DEFINED__
#define __WSMLLocalCategories_DEFINED__

OBJCUWPWINDOWSSERVICESMAPSLOCALSEARCHEXPORT
@interface WSMLLocalCategories : RTObject
+ (NSString *)all;
+ (NSString *)bankAndCreditUnions;
+ (NSString *)eatDrink;
+ (NSString *)hospitals;
+ (NSString *)hotelsAndMotels;
+ (NSString *)parking;
+ (NSString *)seeDo;
+ (NSString *)shop;
@end

#endif // __WSMLLocalCategories_DEFINED__

// Windows.Services.Maps.LocalSearch.PlaceInfoHelper
#ifndef __WSMLPlaceInfoHelper_DEFINED__
#define __WSMLPlaceInfoHelper_DEFINED__

OBJCUWPWINDOWSSERVICESMAPSLOCALSEARCHEXPORT
@interface WSMLPlaceInfoHelper : RTObject
+ (WSMPlaceInfo*)createFromLocalLocation:(WSMLLocalLocation*)location;
@end

#endif // __WSMLPlaceInfoHelper_DEFINED__

