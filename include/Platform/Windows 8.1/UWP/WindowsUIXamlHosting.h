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

// WindowsUIXamlHosting.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WUXHXamlUIPresenter;
@protocol WUXHIXamlUIPresenterHost
, WUXHIXamlUIPresenterHost2, WUXHIXamlUIPresenter, WUXHIXamlUIPresenterStatics, WUXHIXamlUIPresenterStatics2;

#include "WindowsUIXamlControlsPrimitives.h"
#include "WindowsUIXaml.h"
#include "WindowsFoundation.h"

// Windows.UI.Xaml.Hosting.IXamlUIPresenterHost
#ifndef __WUXHIXamlUIPresenterHost_DEFINED__
#define __WUXHIXamlUIPresenterHost_DEFINED__

@protocol WUXHIXamlUIPresenterHost
- (NSString*)resolveFileResource:(NSString*)path;
@end

#endif // __WUXHIXamlUIPresenterHost_DEFINED__

// Windows.UI.Xaml.Hosting.IXamlUIPresenterHost2
#ifndef __WUXHIXamlUIPresenterHost2_DEFINED__
#define __WUXHIXamlUIPresenterHost2_DEFINED__

@protocol WUXHIXamlUIPresenterHost2
- (NSString*)getGenericXamlFilePath;
@end

#endif // __WUXHIXamlUIPresenterHost2_DEFINED__

// Windows.UI.Xaml.Hosting.XamlUIPresenter
#ifndef __WUXHXamlUIPresenter_DEFINED__
#define __WUXHXamlUIPresenter_DEFINED__

WINRT_EXPORT
@interface WUXHXamlUIPresenter : RTObject
+ (void)setHost:(RTObject<WUXHIXamlUIPresenterHost>*)host;
+ (void)notifyWindowSizeChanged;
+ (WFRect*)getFlyoutPlacementTargetInfo:(WXFrameworkElement*)placementTarget
                     preferredPlacement:(WUXCPFlyoutPlacementMode)preferredPlacement
               targetPreferredPlacement:(WUXCPFlyoutPlacementMode*)targetPreferredPlacement
                         allowFallbacks:(BOOL*)allowFallbacks;
+ (WFRect*)getFlyoutPlacement:(WFRect*)placementTargetBounds
                  controlSize:(WFSize*)controlSize
               minControlSize:(WFSize*)minControlSize
                containerRect:(WFRect*)containerRect
     targetPreferredPlacement:(WUXCPFlyoutPlacementMode)targetPreferredPlacement
               allowFallbacks:(BOOL)allowFallbacks
              chosenPlacement:(WUXCPFlyoutPlacementMode*)chosenPlacement;
@property (copy) NSString* themeResourcesXaml;
@property (copy) NSString* themeKey;
@property (copy) WXUIElement* rootElement;
+ (BOOL)completeTimelinesAutomatically;
+ (void)setCompleteTimelinesAutomatically:(BOOL)value;
- (void)setSize:(int)width height:(int)height;
- (void)render;
- (void)present;
@end

#endif // __WUXHXamlUIPresenter_DEFINED__
