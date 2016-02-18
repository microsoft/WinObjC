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

#import <StoreKit/StoreKitExport.h>
#import <Foundation/NSObject.h>

@class NSString;
@class NSDecimalNumber;
@class NSLocale;
@class NSArray;

STOREKIT_EXPORT_CLASS
@interface SKProduct : NSObject <NSObject>
@property (readonly, nonatomic) NSString* localizedDescription STUB_PROPERTY;
@property (readonly, nonatomic) NSString* localizedTitle STUB_PROPERTY;
@property (readonly, nonatomic) NSDecimalNumber* price STUB_PROPERTY;
@property (readonly, nonatomic) NSLocale* priceLocale STUB_PROPERTY;
@property (readonly, nonatomic) NSString* productIdentifier STUB_PROPERTY;
@property (readonly, getter=isDownloadable, nonatomic) BOOL downloadable STUB_PROPERTY;
@property (readonly, nonatomic) NSArray* downloadContentLengths STUB_PROPERTY;
@property (readonly, nonatomic) NSString* downloadContentVersion STUB_PROPERTY;
@end
