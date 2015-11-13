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

// WindowsUIXamlResources.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WUXRCustomXamlResourceLoader;
@protocol WUXRICustomXamlResourceLoader
, WUXRICustomXamlResourceLoaderOverrides, WUXRICustomXamlResourceLoaderStatics, WUXRICustomXamlResourceLoaderFactory;

#import <Foundation/Foundation.h>

// Windows.UI.Xaml.Resources.ICustomXamlResourceLoaderOverrides
#ifndef __WUXRICustomXamlResourceLoaderOverrides_DEFINED__
#define __WUXRICustomXamlResourceLoaderOverrides_DEFINED__

@protocol WUXRICustomXamlResourceLoaderOverrides
- (RTObject*)getResource:(NSString*)resourceId
              objectType:(NSString*)objectType
            propertyName:(NSString*)propertyName
            propertyType:(NSString*)propertyType;
@end

#endif // __WUXRICustomXamlResourceLoaderOverrides_DEFINED__

// Windows.UI.Xaml.Resources.CustomXamlResourceLoader
#ifndef __WUXRCustomXamlResourceLoader_DEFINED__
#define __WUXRCustomXamlResourceLoader_DEFINED__

WINRT_EXPORT
@interface WUXRCustomXamlResourceLoader : RTObject
+ (instancetype)create ACTIVATOR;
+ (WUXRCustomXamlResourceLoader*)current;
+ (void)setCurrent:(WUXRCustomXamlResourceLoader*)value;
- (RTObject*)getResource:(NSString*)resourceId
              objectType:(NSString*)objectType
            propertyName:(NSString*)propertyName
            propertyType:(NSString*)propertyType;
@end

#endif // __WUXRCustomXamlResourceLoader_DEFINED__
