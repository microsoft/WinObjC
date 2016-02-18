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

#import <AVFoundation/AVFoundationExport.h>
#import <Foundation/NSObject.h>

@class NSURLRequest;
@class NSData;
@class NSDictionary;
@class NSError;
@class AVAssetResourceLoadingContentInformationRequest;
@class AVAssetResourceLoadingDataRequest;
@class NSURLResponse;

AVFOUNDATION_EXPORT_CLASS
@interface AVAssetResourceLoadingRequest : NSObject
@property (readonly, nonatomic) NSURLRequest* request STUB_PROPERTY;
- (NSData*)streamingContentKeyRequestDataForApp:(NSData*)appIdentifier
                              contentIdentifier:(NSData*)contentIdentifier
                                        options:(NSDictionary*)options
                                          error:(NSError* _Nullable*)outError STUB_METHOD;
@property (readonly, nonatomic) AVAssetResourceLoadingContentInformationRequest* contentInformationRequest STUB_PROPERTY;
@property (readonly, nonatomic) AVAssetResourceLoadingDataRequest* dataRequest STUB_PROPERTY;
@property (copy, nonatomic) NSURLRequest* redirect STUB_PROPERTY;
@property (copy, nonatomic) NSURLResponse* response STUB_PROPERTY;
- (void)finishLoadingWithResponse:(NSURLResponse*)response data:(NSData*)data redirect:(NSURLRequest*)redirect STUB_METHOD;
- (void)finishLoading STUB_METHOD;
@property (readonly, getter=isCancelled, nonatomic) BOOL cancelled STUB_PROPERTY;
- (void)finishLoadingWithError:(NSError*)error STUB_METHOD;
@property (readonly, getter=isFinished, nonatomic) BOOL finished STUB_PROPERTY;
@end
