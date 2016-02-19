//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#pragma once

#import <UIKit/UIKitExport.h>
#import <Foundation/Foundation.h>

typedef enum : NSInteger {
    UIPrinterJobTypeUnknown = 0,
    UIPrinterJobTypeDocument = 1 << 0,
    UIPrinterJobTypeEnvelope = 1 << 1,
    UIPrinterJobTypeLabel = 1 << 2,
    UIPrinterJobTypePhoto = 1 << 3,
    UIPrinterJobTypeReceipt = 1 << 4,
    UIPrinterJobTypeRoll = 1 << 5,
    UIPrinterJobTypeLargeFormat = 1 << 6,
    UIPrinterJobTypePostcard = 1 << 7
} UIPrinterJobTypes;

UIKIT_EXPORT_CLASS
@interface UIPrinter : NSObject
+ (UIPrinter*)printerWithURL:(NSURL*)url STUB_METHOD;
@property (readonly, copy) NSURL* URL STUB_PROPERTY;
@property (readonly, copy) NSString* displayName STUB_PROPERTY;
@property (readonly, copy) NSString* displayLocation STUB_PROPERTY;
@property (readonly, copy) NSString* makeAndModel STUB_PROPERTY;
@property (readonly) UIPrinterJobTypes supportedJobTypes STUB_PROPERTY;
@property (readonly) BOOL supportsColor STUB_PROPERTY;
@property (readonly) BOOL supportsDuplex STUB_PROPERTY;
- (void)contactPrinter:(void (^)(BOOL))completionHandler STUB_METHOD;
@end
