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

// WindowsUIXamlInterop.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WUXINotifyCollectionChangedEventArgs;
@class WUXITypeName;
@protocol WUXIIBindableIterable
, WUXIIBindableIterator, WUXIIBindableVector, WUXIIBindableVectorView, WUXIINotifyCollectionChanged, WUXIINotifyCollectionChangedEventArgs,
    WUXIINotifyCollectionChangedEventArgsFactory, WUXIIBindableObservableVector;

// Windows.UI.Xaml.Interop.NotifyCollectionChangedAction
enum _WUXINotifyCollectionChangedAction {
    WUXINotifyCollectionChangedActionAdd = 0,
    WUXINotifyCollectionChangedActionRemove = 1,
    WUXINotifyCollectionChangedActionReplace = 2,
    WUXINotifyCollectionChangedActionMove = 3,
    WUXINotifyCollectionChangedActionReset = 4,
};
typedef unsigned WUXINotifyCollectionChangedAction;

// Windows.UI.Xaml.Interop.TypeKind
enum _WUXITypeKind {
    WUXITypeKindPrimitive = 0,
    WUXITypeKindMetadata = 1,
    WUXITypeKindCustom = 2,
};
typedef unsigned WUXITypeKind;

#include "WindowsFoundation.h"
// Windows.UI.Xaml.Interop.BindableVectorChangedEventHandler
#ifndef __WUXIBindableVectorChangedEventHandler__DEFINED
#define __WUXIBindableVectorChangedEventHandler__DEFINED
typedef void (^WUXIBindableVectorChangedEventHandler)(RTObject<WUXIIBindableObservableVector>* vector, RTObject* e);
#endif // __WUXIBindableVectorChangedEventHandler__DEFINED

// Windows.UI.Xaml.Interop.NotifyCollectionChangedEventHandler
#ifndef __WUXINotifyCollectionChangedEventHandler__DEFINED
#define __WUXINotifyCollectionChangedEventHandler__DEFINED
typedef void (^WUXINotifyCollectionChangedEventHandler)(RTObject* sender, WUXINotifyCollectionChangedEventArgs* e);
#endif // __WUXINotifyCollectionChangedEventHandler__DEFINED

// [struct] Windows.UI.Xaml.Interop.TypeName
WINRT_EXPORT
@interface WUXITypeName : NSObject
+ (instancetype) new;
@property (copy) NSString* name;
@property WUXITypeKind kind;
@end

// Windows.UI.Xaml.Interop.NotifyCollectionChangedEventHandler
#ifndef __WUXINotifyCollectionChangedEventHandler__DEFINED
#define __WUXINotifyCollectionChangedEventHandler__DEFINED
typedef void (^WUXINotifyCollectionChangedEventHandler)(RTObject* sender, WUXINotifyCollectionChangedEventArgs* e);
#endif // __WUXINotifyCollectionChangedEventHandler__DEFINED

// Windows.UI.Xaml.Interop.BindableVectorChangedEventHandler
#ifndef __WUXIBindableVectorChangedEventHandler__DEFINED
#define __WUXIBindableVectorChangedEventHandler__DEFINED
typedef void (^WUXIBindableVectorChangedEventHandler)(RTObject<WUXIIBindableObservableVector>* vector, RTObject* e);
#endif // __WUXIBindableVectorChangedEventHandler__DEFINED

// Windows.UI.Xaml.Interop.IBindableIterable
#ifndef __WUXIIBindableIterable_DEFINED__
#define __WUXIIBindableIterable_DEFINED__

@protocol WUXIIBindableIterable
- (RTObject<WUXIIBindableIterator>*)first;
@end

#endif // __WUXIIBindableIterable_DEFINED__

// Windows.UI.Xaml.Interop.IBindableIterator
#ifndef __WUXIIBindableIterator_DEFINED__
#define __WUXIIBindableIterator_DEFINED__

@protocol WUXIIBindableIterator
@property (readonly) RTObject* current;
@property (readonly) BOOL hasCurrent;
- (BOOL)moveNext;
@end

#endif // __WUXIIBindableIterator_DEFINED__

// Windows.UI.Xaml.Interop.IBindableVector
#ifndef __WUXIIBindableVector_DEFINED__
#define __WUXIIBindableVector_DEFINED__

@protocol WUXIIBindableVector <WUXIIBindableIterable>
@property (readonly) unsigned size;
- (RTObject*)getAt:(unsigned)index;
- (RTObject<WUXIIBindableVectorView>*)getView;
- (BOOL)indexOf:(RTObject*)value index:(unsigned*)index;
- (void)setAt:(unsigned)index value:(RTObject*)value;
- (void)insertAt:(unsigned)index value:(RTObject*)value;
- (void)removeAt:(unsigned)index;
- (void)append:(RTObject*)value;
- (void)removeAtEnd;
- (void)clear;
- (RTObject<WUXIIBindableIterator>*)first;
@end

#endif // __WUXIIBindableVector_DEFINED__

// Windows.UI.Xaml.Interop.IBindableVectorView
#ifndef __WUXIIBindableVectorView_DEFINED__
#define __WUXIIBindableVectorView_DEFINED__

@protocol WUXIIBindableVectorView <WUXIIBindableIterable>
@property (readonly) unsigned size;
- (RTObject*)getAt:(unsigned)index;
- (BOOL)indexOf:(RTObject*)value index:(unsigned*)index;
- (RTObject<WUXIIBindableIterator>*)first;
@end

#endif // __WUXIIBindableVectorView_DEFINED__

// Windows.UI.Xaml.Interop.INotifyCollectionChanged
#ifndef __WUXIINotifyCollectionChanged_DEFINED__
#define __WUXIINotifyCollectionChanged_DEFINED__

@protocol WUXIINotifyCollectionChanged
- (EventRegistrationToken)addCollectionChangedEvent:(WUXINotifyCollectionChangedEventHandler)del;
- (void)removeCollectionChangedEvent:(EventRegistrationToken)tok;
@end

#endif // __WUXIINotifyCollectionChanged_DEFINED__

// Windows.UI.Xaml.Interop.IBindableObservableVector
#ifndef __WUXIIBindableObservableVector_DEFINED__
#define __WUXIIBindableObservableVector_DEFINED__

@protocol WUXIIBindableObservableVector <WUXIIBindableVector, WUXIIBindableIterable>
- (EventRegistrationToken)addVectorChangedEvent:(WUXIBindableVectorChangedEventHandler)del;
- (void)removeVectorChangedEvent:(EventRegistrationToken)tok;
- (RTObject*)getAt:(unsigned)index;
- (RTObject<WUXIIBindableVectorView>*)getView;
- (BOOL)indexOf:(RTObject*)value index:(unsigned*)index;
- (void)setAt:(unsigned)index value:(RTObject*)value;
- (void)insertAt:(unsigned)index value:(RTObject*)value;
- (void)removeAt:(unsigned)index;
- (void)append:(RTObject*)value;
- (void)removeAtEnd;
- (void)clear;
- (RTObject<WUXIIBindableIterator>*)first;
@end

#endif // __WUXIIBindableObservableVector_DEFINED__

// Windows.UI.Xaml.Interop.NotifyCollectionChangedEventArgs
#ifndef __WUXINotifyCollectionChangedEventArgs_DEFINED__
#define __WUXINotifyCollectionChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUXINotifyCollectionChangedEventArgs : RTObject
@property (readonly) WUXINotifyCollectionChangedAction action;
@property (readonly) RTObject<WUXIIBindableVector>* newItems;
@property (readonly) int newStartingIndex;
@property (readonly) RTObject<WUXIIBindableVector>* oldItems;
@property (readonly) int oldStartingIndex;
@end

#endif // __WUXINotifyCollectionChangedEventArgs_DEFINED__
