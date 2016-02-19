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

@class AVAssetResourceLoader;
@class AVAssetResourceLoadingRequest;
@class AVAssetResourceRenewalRequest;
@class NSURLAuthenticationChallenge;

@protocol AVAssetResourceLoaderDelegate <NSObject>
@optional
- (BOOL)resourceLoader:(AVAssetResourceLoader*)resourceLoader
    shouldWaitForLoadingOfRequestedResource:(AVAssetResourceLoadingRequest*)loadingRequest;
- (void)resourceLoader:(AVAssetResourceLoader*)resourceLoader didCancelLoadingRequest:(AVAssetResourceLoadingRequest*)loadingRequest;
- (BOOL)resourceLoader:(AVAssetResourceLoader*)resourceLoader
    shouldWaitForRenewalOfRequestedResource:(AVAssetResourceRenewalRequest*)renewalRequest;
- (void)resourceLoader:(AVAssetResourceLoader*)resourceLoader
    didCancelAuthenticationChallenge:(NSURLAuthenticationChallenge*)authenticationChallenge;
- (BOOL)resourceLoader:(AVAssetResourceLoader*)resourceLoader
    shouldWaitForResponseToAuthenticationChallenge:(NSURLAuthenticationChallenge*)authenticationChallenge;
@end
