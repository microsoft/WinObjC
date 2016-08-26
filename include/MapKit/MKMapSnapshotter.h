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
#pragma once

#import <MapKit/MapKitExport.h>
#import <Foundation/NSObject.h>
#import <objc/runtime.h>
#import <objc/toydispatch.h>

@class MKMapSnapshot;
@class NSError;
@class MKMapSnapshotOptions;

typedef void (^MKMapSnapshotCompletionHandler)(MKMapSnapshot* snapshot, NSError* error);

MAPKIT_EXPORT_CLASS
@interface MKMapSnapshotter : NSObject <NSObject>
- (instancetype)initWithOptions:(MKMapSnapshotOptions*)options STUB_METHOD;
- (void)startWithCompletionHandler:(MKMapSnapshotCompletionHandler)completionHandler STUB_METHOD;
- (void)startWithQueue:(dispatch_queue_t)queue completionHandler:(MKMapSnapshotCompletionHandler)completionHandler STUB_METHOD;
- (void)cancel STUB_METHOD;
@property (readonly, getter=isLoading, nonatomic) BOOL loading STUB_PROPERTY;
@end
