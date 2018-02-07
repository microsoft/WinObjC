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

// WindowsDataPdf.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSDATAPDFEXPORT
#define OBJCUWPWINDOWSDATAPDFEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsDataPdf.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WDPPdfPageRenderOptions, WDPPdfPageDimensions, WDPPdfPage, WDPPdfDocument;
@protocol WDPIPdfPageDimensions, WDPIPdfPageRenderOptions, WDPIPdfPage, WDPIPdfDocument, WDPIPdfDocumentStatics;

// Windows.Data.Pdf.PdfPageRotation
enum _WDPPdfPageRotation {
    WDPPdfPageRotationNormal = 0,
    WDPPdfPageRotationRotate90 = 1,
    WDPPdfPageRotationRotate180 = 2,
    WDPPdfPageRotationRotate270 = 3,
};
typedef unsigned WDPPdfPageRotation;

#include "WindowsUI.h"
#include "WindowsFoundation.h"
#include "WindowsStorageStreams.h"
#include "WindowsStorage.h"

#import <Foundation/Foundation.h>

// Windows.Data.Pdf.PdfPageRenderOptions
#ifndef __WDPPdfPageRenderOptions_DEFINED__
#define __WDPPdfPageRenderOptions_DEFINED__

OBJCUWPWINDOWSDATAPDFEXPORT
@interface WDPPdfPageRenderOptions : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFRect* sourceRect;
@property BOOL isIgnoringHighContrast;
@property unsigned int destinationWidth;
@property unsigned int destinationHeight;
@property WFGUID* bitmapEncoderId;
@property (retain) WUColor* backgroundColor;
@end

#endif // __WDPPdfPageRenderOptions_DEFINED__

// Windows.Data.Pdf.PdfPageDimensions
#ifndef __WDPPdfPageDimensions_DEFINED__
#define __WDPPdfPageDimensions_DEFINED__

OBJCUWPWINDOWSDATAPDFEXPORT
@interface WDPPdfPageDimensions : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFRect* artBox;
@property (readonly) WFRect* bleedBox;
@property (readonly) WFRect* cropBox;
@property (readonly) WFRect* mediaBox;
@property (readonly) WFRect* trimBox;
@end

#endif // __WDPPdfPageDimensions_DEFINED__

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

OBJCUWPWINDOWSDATAPDFEXPORT
@interface WFIClosable : RTObject <WFIClosable>
@end

#endif // __WFIClosable_DEFINED__

// Windows.Data.Pdf.PdfPage
#ifndef __WDPPdfPage_DEFINED__
#define __WDPPdfPage_DEFINED__

OBJCUWPWINDOWSDATAPDFEXPORT
@interface WDPPdfPage : RTObject <WFIClosable>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDPPdfPageDimensions* dimensions;
@property (readonly) unsigned int index;
@property (readonly) float preferredZoom;
@property (readonly) WDPPdfPageRotation rotation;
@property (readonly) WFSize* size;
- (RTObject<WFIAsyncAction>*)renderToStreamAsync:(RTObject<WSSIRandomAccessStream>*)outputStream;
- (RTObject<WFIAsyncAction>*)renderWithOptionsToStreamAsync:(RTObject<WSSIRandomAccessStream>*)outputStream options:(WDPPdfPageRenderOptions*)options;
- (RTObject<WFIAsyncAction>*)preparePageAsync;
- (void)close;
@end

#endif // __WDPPdfPage_DEFINED__

// Windows.Data.Pdf.PdfDocument
#ifndef __WDPPdfDocument_DEFINED__
#define __WDPPdfDocument_DEFINED__

OBJCUWPWINDOWSDATAPDFEXPORT
@interface WDPPdfDocument : RTObject
+ (void)loadFromFileAsync:(RTObject<WSIStorageFile>*)file success:(void (^)(WDPPdfDocument*))success failure:(void (^)(NSError*))failure;
+ (void)loadFromFileWithPasswordAsync:(RTObject<WSIStorageFile>*)file password:(NSString *)password success:(void (^)(WDPPdfDocument*))success failure:(void (^)(NSError*))failure;
+ (void)loadFromStreamAsync:(RTObject<WSSIRandomAccessStream>*)inputStream success:(void (^)(WDPPdfDocument*))success failure:(void (^)(NSError*))failure;
+ (void)loadFromStreamWithPasswordAsync:(RTObject<WSSIRandomAccessStream>*)inputStream password:(NSString *)password success:(void (^)(WDPPdfDocument*))success failure:(void (^)(NSError*))failure;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL isPasswordProtected;
@property (readonly) unsigned int pageCount;
- (WDPPdfPage*)getPage:(unsigned int)pageIndex;
@end

#endif // __WDPPdfDocument_DEFINED__

