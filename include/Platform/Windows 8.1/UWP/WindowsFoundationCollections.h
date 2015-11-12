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

// WindowsFoundationCollections.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WFCPropertySet;
@protocol WFCIVectorChangedEventArgs
, WFCIPropertySet, WFCIIterable, WFCIIterator, WFCIVectorView, WFCIVector, WFCIKeyValuePair, WFCIMap, WFCIMapView, WFCIObservableVector,
    WFCIMapChangedEventArgs, WFCIObservableMap;

// Windows.Foundation.Collections.CollectionChange
enum _WFCCollectionChange {
    WFCCollectionChangeReset = 0,
    WFCCollectionChangeItemInserted = 1,
    WFCCollectionChangeItemRemoved = 2,
    WFCCollectionChangeItemChanged = 3,
};
typedef unsigned WFCCollectionChange;

#include "WindowsFoundation.h"

// Windows.Foundation.Collections.VectorChangedEventHandler`1
// Could not generate delegate: Can't marshal Windows.Foundation.Collections.IObservableVector`1<0>
// Windows.Foundation.Collections.MapChangedEventHandler`2
// Could not generate delegate: Can't marshal Windows.Foundation.Collections.IObservableMap`2<0,1>
// Windows.Foundation.Collections.IVectorChangedEventArgs
#ifndef __WFCIVectorChangedEventArgs_DEFINED__
#define __WFCIVectorChangedEventArgs_DEFINED__

@protocol WFCIVectorChangedEventArgs
@property (readonly) WFCCollectionChange collectionChange;
@property (readonly) unsigned index;
@end

#endif // __WFCIVectorChangedEventArgs_DEFINED__

// Windows.Foundation.Collections.IPropertySet
#ifndef __WFCIPropertySet_DEFINED__
#define __WFCIPropertySet_DEFINED__

@protocol WFCIPropertySet
// Could not find base class Windows.Foundation.Collections.IObservableMap`2<String,System.Object> type information
// Could not find base class Windows.Foundation.Collections.IMap`2<String,System.Object> type information
@end

#endif // __WFCIPropertySet_DEFINED__

// Windows.Foundation.Collections.PropertySet
#ifndef __WFCPropertySet_DEFINED__
#define __WFCPropertySet_DEFINED__

WINRT_EXPORT
@interface WFCPropertySet : RTObject <WFCIPropertySet>
+ (instancetype)create ACTIVATOR;
@property (readonly) unsigned size;
// Could not generate add_MapChanged (Can't marshal Windows.Foundation.Collections.MapChangedEventHandler`2<String,System.Object>)
- (void)removeMapChangedEvent:(EventRegistrationToken)tok;
// Could not find base class Windows.Foundation.Collections.IObservableMap`2<String,System.Object> type information
// Could not find base class Windows.Foundation.Collections.IMap`2<String,System.Object> type information
// Could not find base class Windows.Foundation.Collections.IObservableMap`2<String,System.Object> type information
// Could not find base class Windows.Foundation.Collections.IMap`2<String,System.Object> type information
@end

#endif // __WFCPropertySet_DEFINED__
