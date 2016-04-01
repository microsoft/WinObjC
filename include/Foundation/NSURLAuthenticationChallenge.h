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

#import <Foundation/FoundationExport.h>
#import <Foundation/NSObject.h>

@protocol NSURLAuthenticationChallengeSender;
@class NSURLProtectionSpace;
@class NSURLCredential;
@class NSURLResponse;
@class NSError;

enum {
    NSURLSessionAuthChallengeUseCredential = 0,
    NSURLSessionAuthChallengePerformDefaultHandling = 1,
    NSURLSessionAuthChallengeCancelAuthenticationChallenge = 2,
    NSURLSessionAuthChallengeRejectProtectionSpace = 3,
};

typedef NSInteger NSURLSessionAuthChallengeDisposition;

FOUNDATION_EXPORT_CLASS
@interface NSURLAuthenticationChallenge : NSObject <NSSecureCoding>
- (instancetype)initWithAuthenticationChallenge:(NSURLAuthenticationChallenge*)challenge
                                         sender:(id<NSURLAuthenticationChallengeSender>)sender STUB_METHOD;
- (instancetype)initWithProtectionSpace:(NSURLProtectionSpace*)space
                     proposedCredential:(NSURLCredential*)credential
                   previousFailureCount:(NSInteger)count
                        failureResponse:(NSURLResponse*)response
                                  error:(NSError*)error
                                 sender:(id<NSURLAuthenticationChallengeSender>)sender STUB_METHOD;
@property (readonly, copy) NSError* error;
@property (readonly, copy) NSURLResponse* failureResponse;
@property (readonly) NSInteger previousFailureCount;
@property (readonly, copy) NSURLCredential* proposedCredential;
@property (readonly, copy) NSURLProtectionSpace* protectionSpace;
@property (readonly, retain) id<NSURLAuthenticationChallengeSender> sender;
@end

@protocol NSURLAuthenticationChallengeSender <NSObject>
- (void)cancelAuthenticationChallenge:(NSURLAuthenticationChallenge*)challenge;
- (void)continueWithoutCredentialForAuthenticationChallenge:(NSURLAuthenticationChallenge*)challenge;
- (void)useCredential:(NSURLCredential*)credential forAuthenticationChallenge:(NSURLAuthenticationChallenge*)challenge;

@optional
- (void)performDefaultHandlingForAuthenticationChallenge:(NSURLAuthenticationChallenge*)challenge;
- (void)rejectProtectionSpaceAndContinueWithChallenge:(NSURLAuthenticationChallenge*)challenge;
@end
