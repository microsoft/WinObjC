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

// WindowsUIXamlPrinting.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WUXPAddPagesEventArgs, WUXPGetPreviewPageEventArgs, WUXPPaginateEventArgs, WUXPPrintDocument;
@protocol WUXPIAddPagesEventArgs
, WUXPIGetPreviewPageEventArgs, WUXPIPaginateEventArgs, WUXPIPrintDocument, WUXPIPrintDocumentStatics, WUXPIPrintDocumentFactory;

// Windows.UI.Xaml.Printing.PreviewPageCountType
enum _WUXPPreviewPageCountType {
    WUXPPreviewPageCountTypeFinal = 0,
    WUXPPreviewPageCountTypeIntermediate = 1,
};
typedef unsigned WUXPPreviewPageCountType;

#include "WindowsUIXaml.h"
#include "WindowsGraphicsPrinting.h"
#include "WindowsFoundation.h"
#include "WindowsUICore.h"
// Windows.UI.Xaml.DependencyPropertyChangedCallback
#ifndef __WXDependencyPropertyChangedCallback__DEFINED
#define __WXDependencyPropertyChangedCallback__DEFINED
typedef void (^WXDependencyPropertyChangedCallback)(WXDependencyObject* sender, WXDependencyProperty* dp);
#endif // __WXDependencyPropertyChangedCallback__DEFINED

// Windows.UI.Xaml.Printing.AddPagesEventHandler
#ifndef __WUXPAddPagesEventHandler__DEFINED
#define __WUXPAddPagesEventHandler__DEFINED
typedef void (^WUXPAddPagesEventHandler)(RTObject* sender, WUXPAddPagesEventArgs* e);
#endif // __WUXPAddPagesEventHandler__DEFINED

// Windows.UI.Xaml.Printing.GetPreviewPageEventHandler
#ifndef __WUXPGetPreviewPageEventHandler__DEFINED
#define __WUXPGetPreviewPageEventHandler__DEFINED
typedef void (^WUXPGetPreviewPageEventHandler)(RTObject* sender, WUXPGetPreviewPageEventArgs* e);
#endif // __WUXPGetPreviewPageEventHandler__DEFINED

// Windows.UI.Xaml.Printing.PaginateEventHandler
#ifndef __WUXPPaginateEventHandler__DEFINED
#define __WUXPPaginateEventHandler__DEFINED
typedef void (^WUXPPaginateEventHandler)(RTObject* sender, WUXPPaginateEventArgs* e);
#endif // __WUXPPaginateEventHandler__DEFINED

#import <Foundation/Foundation.h>

// Windows.UI.Xaml.Printing.AddPagesEventHandler
#ifndef __WUXPAddPagesEventHandler__DEFINED
#define __WUXPAddPagesEventHandler__DEFINED
typedef void (^WUXPAddPagesEventHandler)(RTObject* sender, WUXPAddPagesEventArgs* e);
#endif // __WUXPAddPagesEventHandler__DEFINED

// Windows.UI.Xaml.Printing.GetPreviewPageEventHandler
#ifndef __WUXPGetPreviewPageEventHandler__DEFINED
#define __WUXPGetPreviewPageEventHandler__DEFINED
typedef void (^WUXPGetPreviewPageEventHandler)(RTObject* sender, WUXPGetPreviewPageEventArgs* e);
#endif // __WUXPGetPreviewPageEventHandler__DEFINED

// Windows.UI.Xaml.Printing.PaginateEventHandler
#ifndef __WUXPPaginateEventHandler__DEFINED
#define __WUXPPaginateEventHandler__DEFINED
typedef void (^WUXPPaginateEventHandler)(RTObject* sender, WUXPPaginateEventArgs* e);
#endif // __WUXPPaginateEventHandler__DEFINED

// Windows.UI.Xaml.Printing.AddPagesEventArgs
#ifndef __WUXPAddPagesEventArgs_DEFINED__
#define __WUXPAddPagesEventArgs_DEFINED__

WINRT_EXPORT
@interface WUXPAddPagesEventArgs : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) WGPPrintTaskOptions* printTaskOptions;
@end

#endif // __WUXPAddPagesEventArgs_DEFINED__

// Windows.UI.Xaml.Printing.GetPreviewPageEventArgs
#ifndef __WUXPGetPreviewPageEventArgs_DEFINED__
#define __WUXPGetPreviewPageEventArgs_DEFINED__

WINRT_EXPORT
@interface WUXPGetPreviewPageEventArgs : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) int pageNumber;
@end

#endif // __WUXPGetPreviewPageEventArgs_DEFINED__

// Windows.UI.Xaml.Printing.PaginateEventArgs
#ifndef __WUXPPaginateEventArgs_DEFINED__
#define __WUXPPaginateEventArgs_DEFINED__

WINRT_EXPORT
@interface WUXPPaginateEventArgs : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) int currentPreviewPageNumber;
@property (readonly) WGPPrintTaskOptions* printTaskOptions;
@end

#endif // __WUXPPaginateEventArgs_DEFINED__

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
- (int64_t)registerPropertyChangedCallback:(WXDependencyProperty*)dp callback:(WXDependencyPropertyChangedCallback)callback;
- (void)unregisterPropertyChangedCallback:(WXDependencyProperty*)dp token:(int64_t)token;
@end

#endif // __WXDependencyObject_DEFINED__

// Windows.UI.Xaml.Printing.PrintDocument
#ifndef __WUXPPrintDocument_DEFINED__
#define __WUXPPrintDocument_DEFINED__

WINRT_EXPORT
@interface WUXPPrintDocument : WXDependencyObject
+ (instancetype)create ACTIVATOR;
@property (readonly) RTObject<WGPIPrintDocumentSource>* documentSource;
+ (WXDependencyProperty*)documentSourceProperty;
- (EventRegistrationToken)addAddPagesEvent:(WUXPAddPagesEventHandler)del;
- (void)removeAddPagesEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addGetPreviewPageEvent:(WUXPGetPreviewPageEventHandler)del;
- (void)removeGetPreviewPageEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPaginateEvent:(WUXPPaginateEventHandler)del;
- (void)removePaginateEvent:(EventRegistrationToken)tok;
- (void)addPage:(WXUIElement*)pageVisual;
- (void)addPagesComplete;
- (void)setPreviewPageCount:(int)count type:(WUXPPreviewPageCountType)type;
- (void)setPreviewPage:(int)pageNumber pageVisual:(WXUIElement*)pageVisual;
- (void)invalidatePreview;
@end

#endif // __WUXPPrintDocument_DEFINED__
