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

#import <MapKit/MapKitExport.h>
#import <Foundation/NSObject.h>

@class MKLocalSearchResponse;
@class NSError;
@class MKLocalSearchRequest;

typedef void (^MKLocalSearchCompletionHandler)(MKLocalSearchResponse* response, NSError* error);

MAPKIT_EXPORT_CLASS
@interface MKLocalSearch : NSObject
- (instancetype)initWithRequest:(MKLocalSearchRequest*)request STUB_METHOD;
- (void)startWithCompletionHandler:(MKLocalSearchCompletionHandler)completionHandler STUB_METHOD;
@property (readonly, getter=isSearching, nonatomic) BOOL searching STUB_PROPERTY;
- (void)cancel STUB_METHOD;
@end
