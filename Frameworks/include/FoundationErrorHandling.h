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

#import <Foundation/NSException.h>
#import <Foundation/NSDictionary.h>
#import <Foundation/NSNumber.h>
#import <Foundation/NSString.h>
#import <Foundation/NSError.h>

// Objective-C support functions for ErrorHandling.h
// Not intended to be used directly!
FOUNDATION_EXPORT const NSString* _NSHResultErrorDictKey;
FOUNDATION_EXPORT NSString* _NSStringFromHResult(HRESULT hr);
FOUNDATION_EXPORT NSError* _NSErrorFromFailureInfo(const wil::FailureInfo& fi);
FOUNDATION_EXPORT NSException* _NSExceptionFromFailureInfo(const wil::FailureInfo& fi);

@interface NSException (errorHandlingInternal)
+ (NSString*)_exceptionNameForHRESULT:(int)errorCode;
+ (instancetype)_exceptionWithHRESULT:(int)errorCode reason:(NSString*)reason userInfo:(NSDictionary*)userInfo;
@end
