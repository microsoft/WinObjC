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

// WindowsUIXamlData.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WUXDCurrentChangingEventArgs, WUXDPropertyChangedEventArgs, WUXDBindingBase, WUXDBinding, WUXDBindingExpressionBase,
    WUXDBindingExpression, WUXDCollectionViewSource, WUXDRelativeSource, WUXDBindingOperations;
@class WUXDLoadMoreItemsResult;
@protocol WUXDIBinding
, WUXDIValueConverter, WUXDIBindingFactory, WUXDIBinding2, WUXDIBindingBase, WUXDIBindingBaseFactory, WUXDIBindingExpression,
    WUXDIBindingExpressionFactory, WUXDIBindingExpressionBase, WUXDIBindingExpressionBaseFactory, WUXDICollectionViewSource,
    WUXDICollectionView, WUXDICollectionViewSourceStatics, WUXDICurrentChangingEventArgs, WUXDICurrentChangingEventArgsFactory,
    WUXDICollectionViewGroup, WUXDICustomProperty, WUXDICustomPropertyProvider, WUXDINotifyPropertyChanged, WUXDIPropertyChangedEventArgs,
    WUXDIPropertyChangedEventArgsFactory, WUXDIRelativeSource, WUXDIRelativeSourceFactory, WUXDIBindingOperations,
    WUXDIBindingOperationsStatics, WUXDISupportIncrementalLoading, WUXDICollectionViewFactory;

// Windows.UI.Xaml.Data.BindingMode
enum _WUXDBindingMode {
    WUXDBindingModeOneWay = 1,
    WUXDBindingModeOneTime = 2,
    WUXDBindingModeTwoWay = 3,
};
typedef unsigned WUXDBindingMode;

// Windows.UI.Xaml.Data.RelativeSourceMode
enum _WUXDRelativeSourceMode {
    WUXDRelativeSourceModeNone = 0,
    WUXDRelativeSourceModeTemplatedParent = 1,
    WUXDRelativeSourceModeSelf = 2,
};
typedef unsigned WUXDRelativeSourceMode;

// Windows.UI.Xaml.Data.UpdateSourceTrigger
enum _WUXDUpdateSourceTrigger {
    WUXDUpdateSourceTriggerDefault = 0,
    WUXDUpdateSourceTriggerPropertyChanged = 1,
    WUXDUpdateSourceTriggerExplicit = 2,
};
typedef unsigned WUXDUpdateSourceTrigger;

#include "WindowsUIXaml.h"
#include "WindowsUIXamlInterop.h"
#include "WindowsFoundationCollections.h"
#include "WindowsFoundation.h"
#include "WindowsUICore.h"
// Windows.UI.Xaml.Data.CurrentChangingEventHandler
#ifndef __WUXDCurrentChangingEventHandler__DEFINED
#define __WUXDCurrentChangingEventHandler__DEFINED
typedef void (^WUXDCurrentChangingEventHandler)(RTObject* sender, WUXDCurrentChangingEventArgs* e);
#endif // __WUXDCurrentChangingEventHandler__DEFINED

// Windows.UI.Xaml.Data.PropertyChangedEventHandler
#ifndef __WUXDPropertyChangedEventHandler__DEFINED
#define __WUXDPropertyChangedEventHandler__DEFINED
typedef void (^WUXDPropertyChangedEventHandler)(RTObject* sender, WUXDPropertyChangedEventArgs* e);
#endif // __WUXDPropertyChangedEventHandler__DEFINED

// [struct] Windows.UI.Xaml.Data.LoadMoreItemsResult
WINRT_EXPORT
@interface WUXDLoadMoreItemsResult : NSObject
+ (instancetype) new;
@property unsigned count;
@end

// Windows.UI.Xaml.Data.CurrentChangingEventHandler
#ifndef __WUXDCurrentChangingEventHandler__DEFINED
#define __WUXDCurrentChangingEventHandler__DEFINED
typedef void (^WUXDCurrentChangingEventHandler)(RTObject* sender, WUXDCurrentChangingEventArgs* e);
#endif // __WUXDCurrentChangingEventHandler__DEFINED

// Windows.UI.Xaml.Data.PropertyChangedEventHandler
#ifndef __WUXDPropertyChangedEventHandler__DEFINED
#define __WUXDPropertyChangedEventHandler__DEFINED
typedef void (^WUXDPropertyChangedEventHandler)(RTObject* sender, WUXDPropertyChangedEventArgs* e);
#endif // __WUXDPropertyChangedEventHandler__DEFINED

// Windows.UI.Xaml.Data.IValueConverter
#ifndef __WUXDIValueConverter_DEFINED__
#define __WUXDIValueConverter_DEFINED__

@protocol WUXDIValueConverter
- (RTObject*)convert:(RTObject*)value targetType:(WUXITypeName*)targetType parameter:(RTObject*)parameter language:(NSString*)language;
- (RTObject*)convertBack:(RTObject*)value targetType:(WUXITypeName*)targetType parameter:(RTObject*)parameter language:(NSString*)language;
@end

#endif // __WUXDIValueConverter_DEFINED__

// Windows.UI.Xaml.Data.ICollectionView
#ifndef __WUXDICollectionView_DEFINED__
#define __WUXDICollectionView_DEFINED__

@protocol WUXDICollectionView
// Failed to generate property CollectionGroups (Can't marshal Windows.Foundation.Collections.IObservableVector`1<System.Object>)
@property (readonly) RTObject* currentItem;
@property (readonly) int currentPosition;
@property (readonly) BOOL hasMoreItems;
@property (readonly) BOOL isCurrentAfterLast;
@property (readonly) BOOL isCurrentBeforeFirst;
- (EventRegistrationToken)addCurrentChangedEvent:(void (^)(RTObject*, RTObject*))del;
- (void)removeCurrentChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addCurrentChangingEvent:(WUXDCurrentChangingEventHandler)del;
- (void)removeCurrentChangingEvent:(EventRegistrationToken)tok;
// Failed to generate member get_CollectionGroups (Can't marshal Windows.Foundation.Collections.IObservableVector`1<System.Object>)
- (BOOL)moveCurrentTo:(RTObject*)item;
- (BOOL)moveCurrentToPosition:(int)index;
- (BOOL)moveCurrentToFirst;
- (BOOL)moveCurrentToLast;
- (BOOL)moveCurrentToNext;
- (BOOL)moveCurrentToPrevious;
- (void)loadMoreItemsAsync:(unsigned)count success:(void (^)(WUXDLoadMoreItemsResult*))success failure:(void (^)(NSError*))failure;
// Could not find base class Windows.Foundation.Collections.IObservableVector`1<System.Object> type information
@end

#endif // __WUXDICollectionView_DEFINED__

// Windows.UI.Xaml.Data.ICollectionViewGroup
#ifndef __WUXDICollectionViewGroup_DEFINED__
#define __WUXDICollectionViewGroup_DEFINED__

@protocol WUXDICollectionViewGroup
@property (readonly) RTObject* group;
// Failed to generate property GroupItems (Can't marshal Windows.Foundation.Collections.IObservableVector`1<System.Object>)
// Failed to generate member get_GroupItems (Can't marshal Windows.Foundation.Collections.IObservableVector`1<System.Object>)
@end

#endif // __WUXDICollectionViewGroup_DEFINED__

// Windows.UI.Xaml.Data.ICustomProperty
#ifndef __WUXDICustomProperty_DEFINED__
#define __WUXDICustomProperty_DEFINED__

@protocol WUXDICustomProperty
@property (readonly) BOOL canRead;
@property (readonly) BOOL canWrite;
@property (readonly) NSString* name;
@property (readonly) WUXITypeName* type;
- (RTObject*)getValue:(RTObject*)target;
- (void)setValue:(RTObject*)target value:(RTObject*)value;
- (RTObject*)getIndexedValue:(RTObject*)target index:(RTObject*)index;
- (void)setIndexedValue:(RTObject*)target value:(RTObject*)value index:(RTObject*)index;
@end

#endif // __WUXDICustomProperty_DEFINED__

// Windows.UI.Xaml.Data.ICustomPropertyProvider
#ifndef __WUXDICustomPropertyProvider_DEFINED__
#define __WUXDICustomPropertyProvider_DEFINED__

@protocol WUXDICustomPropertyProvider
@property (readonly) WUXITypeName* type;
- (RTObject<WUXDICustomProperty>*)getCustomProperty:(NSString*)name;
- (RTObject<WUXDICustomProperty>*)getIndexedProperty:(NSString*)name type:(WUXITypeName*)type;
- (NSString*)getStringRepresentation;
@end

#endif // __WUXDICustomPropertyProvider_DEFINED__

// Windows.UI.Xaml.Data.INotifyPropertyChanged
#ifndef __WUXDINotifyPropertyChanged_DEFINED__
#define __WUXDINotifyPropertyChanged_DEFINED__

@protocol WUXDINotifyPropertyChanged
- (EventRegistrationToken)addPropertyChangedEvent:(WUXDPropertyChangedEventHandler)del;
- (void)removePropertyChangedEvent:(EventRegistrationToken)tok;
@end

#endif // __WUXDINotifyPropertyChanged_DEFINED__

// Windows.UI.Xaml.Data.ISupportIncrementalLoading
#ifndef __WUXDISupportIncrementalLoading_DEFINED__
#define __WUXDISupportIncrementalLoading_DEFINED__

@protocol WUXDISupportIncrementalLoading
@property (readonly) BOOL hasMoreItems;
- (void)loadMoreItemsAsync:(unsigned)count success:(void (^)(WUXDLoadMoreItemsResult*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WUXDISupportIncrementalLoading_DEFINED__

// Windows.UI.Xaml.Data.ICollectionViewFactory
#ifndef __WUXDICollectionViewFactory_DEFINED__
#define __WUXDICollectionViewFactory_DEFINED__

@protocol WUXDICollectionViewFactory
- (RTObject<WUXDICollectionView>*)createView;
@end

#endif // __WUXDICollectionViewFactory_DEFINED__

// Windows.UI.Xaml.Data.CurrentChangingEventArgs
#ifndef __WUXDCurrentChangingEventArgs_DEFINED__
#define __WUXDCurrentChangingEventArgs_DEFINED__

WINRT_EXPORT
@interface WUXDCurrentChangingEventArgs : RTObject
+ (instancetype)create ACTIVATOR;
@property BOOL cancel;
@property (readonly) BOOL isCancelable;
@end

#endif // __WUXDCurrentChangingEventArgs_DEFINED__

// Windows.UI.Xaml.Data.PropertyChangedEventArgs
#ifndef __WUXDPropertyChangedEventArgs_DEFINED__
#define __WUXDPropertyChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUXDPropertyChangedEventArgs : RTObject
@property (readonly) NSString* propertyName;
@end

#endif // __WUXDPropertyChangedEventArgs_DEFINED__

// Windows.UI.Xaml.DependencyObject
#ifndef __WXDependencyObject_DEFINED__
#define __WXDependencyObject_DEFINED__

WINRT_EXPORT
@interface WXDependencyObject : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) WUCCoreDispatcher* dispatcher;
- (RTObject*)getValue:(WXDependencyProperty*)dp;
- (void)setValue:(WXDependencyProperty*)dp value:(RTObject*)value;
- (void)clearValue:(WXDependencyProperty*)dp;
- (RTObject*)readLocalValue:(WXDependencyProperty*)dp;
- (RTObject*)getAnimationBaseValue:(WXDependencyProperty*)dp;
@end

#endif // __WXDependencyObject_DEFINED__

// Windows.UI.Xaml.Data.BindingBase
#ifndef __WUXDBindingBase_DEFINED__
#define __WUXDBindingBase_DEFINED__

WINRT_EXPORT
@interface WUXDBindingBase : WXDependencyObject
+ (instancetype)create ACTIVATOR;
@end

#endif // __WUXDBindingBase_DEFINED__

// Windows.UI.Xaml.Data.Binding
#ifndef __WUXDBinding_DEFINED__
#define __WUXDBinding_DEFINED__

WINRT_EXPORT
@interface WUXDBinding : WUXDBindingBase
+ (instancetype)create ACTIVATOR;
@property WUXDUpdateSourceTrigger updateSourceTrigger;
@property (copy) RTObject* targetNullValue;
@property (copy) RTObject* fallbackValue;
@property (copy) RTObject* source;
@property (copy) WUXDRelativeSource* relativeSource;
@property (copy) WXPropertyPath* path;
@property WUXDBindingMode mode;
@property (copy) NSString* elementName;
@property (copy) RTObject* converterParameter;
@property (copy) NSString* converterLanguage;
@property (copy) RTObject<WUXDIValueConverter>* converter;
@end

#endif // __WUXDBinding_DEFINED__

// Windows.UI.Xaml.Data.BindingExpressionBase
#ifndef __WUXDBindingExpressionBase_DEFINED__
#define __WUXDBindingExpressionBase_DEFINED__

WINRT_EXPORT
@interface WUXDBindingExpressionBase : RTObject
@end

#endif // __WUXDBindingExpressionBase_DEFINED__

// Windows.UI.Xaml.Data.BindingExpression
#ifndef __WUXDBindingExpression_DEFINED__
#define __WUXDBindingExpression_DEFINED__

WINRT_EXPORT
@interface WUXDBindingExpression : WUXDBindingExpressionBase
@property (readonly) RTObject* dataItem;
@property (readonly) WUXDBinding* parentBinding;
- (void)updateSource;
@end

#endif // __WUXDBindingExpression_DEFINED__

// Windows.UI.Xaml.Data.CollectionViewSource
#ifndef __WUXDCollectionViewSource_DEFINED__
#define __WUXDCollectionViewSource_DEFINED__

WINRT_EXPORT
@interface WUXDCollectionViewSource : WXDependencyObject
+ (instancetype)create ACTIVATOR;
@property (copy) RTObject* source;
@property (copy) WXPropertyPath* itemsPath;
@property BOOL isSourceGrouped;
@property (readonly) RTObject<WUXDICollectionView>* view;
+ (WXDependencyProperty*)isSourceGroupedProperty;
+ (WXDependencyProperty*)itemsPathProperty;
+ (WXDependencyProperty*)sourceProperty;
+ (WXDependencyProperty*)viewProperty;
@end

#endif // __WUXDCollectionViewSource_DEFINED__

// Windows.UI.Xaml.Data.RelativeSource
#ifndef __WUXDRelativeSource_DEFINED__
#define __WUXDRelativeSource_DEFINED__

WINRT_EXPORT
@interface WUXDRelativeSource : WXDependencyObject
+ (instancetype)create ACTIVATOR;
@property WUXDRelativeSourceMode mode;
@end

#endif // __WUXDRelativeSource_DEFINED__

// Windows.UI.Xaml.Data.BindingOperations
#ifndef __WUXDBindingOperations_DEFINED__
#define __WUXDBindingOperations_DEFINED__

WINRT_EXPORT
@interface WUXDBindingOperations : RTObject
+ (void)setBinding:(WXDependencyObject*)target dp:(WXDependencyProperty*)dp binding:(WUXDBindingBase*)binding;
@end

#endif // __WUXDBindingOperations_DEFINED__
