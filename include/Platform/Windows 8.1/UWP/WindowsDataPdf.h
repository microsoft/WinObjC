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

// WindowsDataPdf.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WDPPdfPageRenderOptions, WDPPdfPageDimensions, WDPPdfPage, WDPPdfDocument;
@protocol WDPIPdfPageDimensions
, WDPIPdfPageRenderOptions, WDPIPdfPage, WDPIPdfDocument, WDPIPdfDocumentStatics;

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

// Windows.Data.Pdf.PdfPageRenderOptions
#ifndef __WDPPdfPageRenderOptions_DEFINED__
#define __WDPPdfPageRenderOptions_DEFINED__

WINRT_EXPORT
@interface WDPPdfPageRenderOptions : RTObject
+ (instancetype)create ACTIVATOR;
@property (copy) WFRect* sourceRect;
@property BOOL isIgnoringHighContrast;
@property unsigned destinationWidth;
@property unsigned destinationHeight;
@property WFGUID* bitmapEncoderId;
@property (copy) WUColor* backgroundColor;
@end

#endif // __WDPPdfPageRenderOptions_DEFINED__

// Windows.Data.Pdf.PdfPageDimensions
#ifndef __WDPPdfPageDimensions_DEFINED__
#define __WDPPdfPageDimensions_DEFINED__

WINRT_EXPORT
@interface WDPPdfPageDimensions : RTObject
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

#endif // __WFIClosable_DEFINED__

// Windows.Data.Pdf.PdfPage
#ifndef __WDPPdfPage_DEFINED__
#define __WDPPdfPage_DEFINED__

WINRT_EXPORT
@interface WDPPdfPage : RTObject <WFIClosable>
@property (readonly) WDPPdfPageDimensions* dimensions;
@property (readonly) unsigned index;
@property (readonly) float preferredZoom;
@property (readonly) WDPPdfPageRotation rotation;
@property (readonly) WFSize* size;
- (RTObject<WFIAsyncAction>*)renderToStreamAsync:(RTObject<WSSIRandomAccessStream>*)outputStream;
- (RTObject<WFIAsyncAction>*)renderWithOptionsToStreamAsync:(RTObject<WSSIRandomAccessStream>*)outputStream
                                                    options:(WDPPdfPageRenderOptions*)options;
- (RTObject<WFIAsyncAction>*)preparePageAsync;
- (void)close;
@end

#endif // __WDPPdfPage_DEFINED__

// Windows.Data.Pdf.PdfDocument
#ifndef __WDPPdfDocument_DEFINED__
#define __WDPPdfDocument_DEFINED__

WINRT_EXPORT
@interface WDPPdfDocument : RTObject
+ (void)loadFromFileAsync:(RTObject<WSIStorageFile>*)file success:(void (^)(WDPPdfDocument*))success failure:(void (^)(NSError*))failure;
+ (void)loadFromFileWithPasswordAsync:(RTObject<WSIStorageFile>*)file
                             password:(NSString*)password
                              success:(void (^)(WDPPdfDocument*))success
                              failure:(void (^)(NSError*))failure;
+ (void)loadFromStreamAsync:(RTObject<WSSIRandomAccessStream>*)inputStream
                    success:(void (^)(WDPPdfDocument*))success
                    failure:(void (^)(NSError*))failure;
+ (void)loadFromStreamWithPasswordAsync:(RTObject<WSSIRandomAccessStream>*)inputStream
                               password:(NSString*)password
                                success:(void (^)(WDPPdfDocument*))success
                                failure:(void (^)(NSError*))failure;
@property (readonly) BOOL isPasswordProtected;
@property (readonly) unsigned pageCount;
- (WDPPdfPage*)getPage:(unsigned)pageIndex;
@end

#endif // __WDPPdfDocument_DEFINED__
