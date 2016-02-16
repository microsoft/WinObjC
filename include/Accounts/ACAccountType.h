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

#import <Foundation/Foundation.h>
#import <Accounts/ACAccountExport.h>

ACCOUNTS_EXPORT NSString* const ACAccountTypeIdentifierFacebook;
ACCOUNTS_EXPORT NSString* const ACAccountTypeIdentifierSinaWeibo;
ACCOUNTS_EXPORT NSString* const ACAccountTypeIdentifierTwitter;
ACCOUNTS_EXPORT NSString* const ACAccountTypeIdentifierTencentWeibo;

ACCOUNTS_EXPORT_CLASS
@interface ACAccountType : NSObject
@property (readonly, nonatomic) BOOL accessGranted STUB_PROPERTY;
@property (readonly, nonatomic) NSString* accountTypeDescription STUB_PROPERTY;
@property (readonly, nonatomic) NSString* identifier STUB_PROPERTY;
@end