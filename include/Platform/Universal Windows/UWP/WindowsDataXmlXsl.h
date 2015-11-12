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

// WindowsDataXmlXsl.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WDXXXsltProcessor;
@protocol WDXXIXsltProcessor
, WDXXIXsltProcessor2, WDXXIXsltProcessorFactory;

#include "WindowsDataXmlDom.h"

#import <Foundation/Foundation.h>

// Windows.Data.Xml.Xsl.XsltProcessor
#ifndef __WDXXXsltProcessor_DEFINED__
#define __WDXXXsltProcessor_DEFINED__

WINRT_EXPORT
@interface WDXXXsltProcessor : RTObject
+ (WDXXXsltProcessor*)createInstance:(WDXDXmlDocument*)document ACTIVATOR;
- (NSString*)transformToString:(RTObject<WDXDIXmlNode>*)inputNode;
- (WDXDXmlDocument*)transformToDocument:(RTObject<WDXDIXmlNode>*)inputNode;
@end

#endif // __WDXXXsltProcessor_DEFINED__
