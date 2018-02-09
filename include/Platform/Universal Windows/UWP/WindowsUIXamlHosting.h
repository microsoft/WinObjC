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

// WindowsUIXamlHosting.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSUIXAMLHOSTINGEXPORT
#define OBJCUWPWINDOWSUIXAMLHOSTINGEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsUIXamlHosting.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WUXHElementCompositionPreview, WUXHDesignerAppExitedEventArgs, WUXHDesignerAppManager, WUXHDesignerAppView, WUXHXamlUIPresenter;
@protocol WUXHIElementCompositionPreview, WUXHIElementCompositionPreviewStatics, WUXHIElementCompositionPreviewStatics2, WUXHIXamlUIPresenterHost, WUXHIXamlUIPresenterHost2, WUXHIXamlUIPresenterHost3, WUXHIDesignerAppExitedEventArgs, WUXHIDesignerAppManager, WUXHIDesignerAppManagerFactory, WUXHIDesignerAppView, WUXHIXamlUIPresenter, WUXHIXamlUIPresenterStatics, WUXHIXamlUIPresenterStatics2;

// Windows.UI.Xaml.Hosting.DesignerAppViewState
enum _WUXHDesignerAppViewState {
    WUXHDesignerAppViewStateVisible = 0,
    WUXHDesignerAppViewStateHidden = 1,
};
typedef unsigned WUXHDesignerAppViewState;

#include "WindowsUIXamlControlsPrimitives.h"
#include "WindowsUIComposition.h"
#include "WindowsUIXaml.h"
#include "WindowsUIXamlControls.h"
#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.UI.Xaml.Hosting.IXamlUIPresenterHost
#ifndef __WUXHIXamlUIPresenterHost_DEFINED__
#define __WUXHIXamlUIPresenterHost_DEFINED__

@protocol WUXHIXamlUIPresenterHost
- (NSString *)resolveFileResource:(NSString *)path;
@end

OBJCUWPWINDOWSUIXAMLHOSTINGEXPORT
@interface WUXHIXamlUIPresenterHost : RTObject <WUXHIXamlUIPresenterHost>
@end

#endif // __WUXHIXamlUIPresenterHost_DEFINED__

// Windows.UI.Xaml.Hosting.IXamlUIPresenterHost2
#ifndef __WUXHIXamlUIPresenterHost2_DEFINED__
#define __WUXHIXamlUIPresenterHost2_DEFINED__

@protocol WUXHIXamlUIPresenterHost2
- (NSString *)getGenericXamlFilePath;
@end

OBJCUWPWINDOWSUIXAMLHOSTINGEXPORT
@interface WUXHIXamlUIPresenterHost2 : RTObject <WUXHIXamlUIPresenterHost2>
@end

#endif // __WUXHIXamlUIPresenterHost2_DEFINED__

// Windows.UI.Xaml.Hosting.IXamlUIPresenterHost3
#ifndef __WUXHIXamlUIPresenterHost3_DEFINED__
#define __WUXHIXamlUIPresenterHost3_DEFINED__

@protocol WUXHIXamlUIPresenterHost3
- (RTObject*)resolveDictionaryResource:(WXResourceDictionary*)dictionary dictionaryKey:(RTObject*)dictionaryKey suggestedValue:(RTObject*)suggestedValue;
@end

OBJCUWPWINDOWSUIXAMLHOSTINGEXPORT
@interface WUXHIXamlUIPresenterHost3 : RTObject <WUXHIXamlUIPresenterHost3>
@end

#endif // __WUXHIXamlUIPresenterHost3_DEFINED__

// Windows.UI.Xaml.Hosting.ElementCompositionPreview
#ifndef __WUXHElementCompositionPreview_DEFINED__
#define __WUXHElementCompositionPreview_DEFINED__

OBJCUWPWINDOWSUIXAMLHOSTINGEXPORT
@interface WUXHElementCompositionPreview : RTObject
+ (WUCVisual*)getElementVisual:(WXUIElement*)element;
+ (WUCVisual*)getElementChildVisual:(WXUIElement*)element;
+ (void)setElementChildVisual:(WXUIElement*)element visual:(WUCVisual*)visual;
+ (WUCCompositionPropertySet*)getScrollViewerManipulationPropertySet:(WXCScrollViewer*)scrollViewer;
+ (void)setImplicitShowAnimation:(WXUIElement*)element animation:(RTObject<WUCICompositionAnimationBase>*)animation;
+ (void)setImplicitHideAnimation:(WXUIElement*)element animation:(RTObject<WUCICompositionAnimationBase>*)animation;
+ (void)setIsTranslationEnabled:(WXUIElement*)element value:(BOOL)value;
+ (WUCCompositionPropertySet*)getPointerPositionPropertySet:(WXUIElement*)targetElement;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUXHElementCompositionPreview_DEFINED__

// Windows.UI.Xaml.Hosting.DesignerAppExitedEventArgs
#ifndef __WUXHDesignerAppExitedEventArgs_DEFINED__
#define __WUXHDesignerAppExitedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLHOSTINGEXPORT
@interface WUXHDesignerAppExitedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int exitCode;
@end

#endif // __WUXHDesignerAppExitedEventArgs_DEFINED__

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

OBJCUWPWINDOWSUIXAMLHOSTINGEXPORT
@interface WFIClosable : RTObject <WFIClosable>
@end

#endif // __WFIClosable_DEFINED__

// Windows.UI.Xaml.Hosting.DesignerAppManager
#ifndef __WUXHDesignerAppManager_DEFINED__
#define __WUXHDesignerAppManager_DEFINED__

OBJCUWPWINDOWSUIXAMLHOSTINGEXPORT
@interface WUXHDesignerAppManager : RTObject <WFIClosable>
+ (WUXHDesignerAppManager*)make:(NSString *)appUserModelId ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * appUserModelId;
- (EventRegistrationToken)addDesignerAppExitedEvent:(void(^)(WUXHDesignerAppManager*, WUXHDesignerAppExitedEventArgs*))del;
- (void)removeDesignerAppExitedEvent:(EventRegistrationToken)tok;
- (void)createNewViewAsync:(WUXHDesignerAppViewState)initialViewState initialViewSize:(WFSize*)initialViewSize success:(void (^)(WUXHDesignerAppView*))success failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)loadObjectIntoAppAsync:(NSString *)dllName classId:(WFGUID*)classId initializationData:(NSString *)initializationData;
- (void)close;
@end

#endif // __WUXHDesignerAppManager_DEFINED__

// Windows.UI.Xaml.Hosting.DesignerAppView
#ifndef __WUXHDesignerAppView_DEFINED__
#define __WUXHDesignerAppView_DEFINED__

OBJCUWPWINDOWSUIXAMLHOSTINGEXPORT
@interface WUXHDesignerAppView : RTObject <WFIClosable>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * appUserModelId;
@property (readonly) int applicationViewId;
@property (readonly) WFSize* viewSize;
@property (readonly) WUXHDesignerAppViewState viewState;
- (RTObject<WFIAsyncAction>*)updateViewAsync:(WUXHDesignerAppViewState)viewState viewSize:(WFSize*)viewSize;
- (void)close;
@end

#endif // __WUXHDesignerAppView_DEFINED__

// Windows.UI.Xaml.Hosting.XamlUIPresenter
#ifndef __WUXHXamlUIPresenter_DEFINED__
#define __WUXHXamlUIPresenter_DEFINED__

OBJCUWPWINDOWSUIXAMLHOSTINGEXPORT
@interface WUXHXamlUIPresenter : RTObject
+ (void)setHost:(RTObject<WUXHIXamlUIPresenterHost>*)host;
+ (void)notifyWindowSizeChanged;
+ (WFRect*)getFlyoutPlacementTargetInfo:(WXFrameworkElement*)placementTarget preferredPlacement:(WUXCPFlyoutPlacementMode)preferredPlacement targetPreferredPlacement:(WUXCPFlyoutPlacementMode*)targetPreferredPlacement allowFallbacks:(BOOL*)allowFallbacks;
+ (WFRect*)getFlyoutPlacement:(WFRect*)placementTargetBounds controlSize:(WFSize*)controlSize minControlSize:(WFSize*)minControlSize containerRect:(WFRect*)containerRect targetPreferredPlacement:(WUXCPFlyoutPlacementMode)targetPreferredPlacement allowFallbacks:(BOOL)allowFallbacks chosenPlacement:(WUXCPFlyoutPlacementMode*)chosenPlacement;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * themeResourcesXaml;
@property (retain) NSString * themeKey;
@property (retain) WXUIElement* rootElement;
+ (BOOL)completeTimelinesAutomatically;
+ (void)setCompleteTimelinesAutomatically:(BOOL)value;
- (void)setSize:(int)width height:(int)height;
- (void)render;
- (void)present;
@end

#endif // __WUXHXamlUIPresenter_DEFINED__

