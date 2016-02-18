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

@class NSString;

FOUNDATION_EXPORT_CLASS
@interface NSPersonNameComponents : NSObject <NSCopying, NSSecureCoding>
@property (copy) NSString* namePrefix STUB_PROPERTY;
@property (copy) NSString* givenName STUB_PROPERTY;
@property (copy) NSString* middleName STUB_PROPERTY;
@property (copy) NSString* familyName STUB_PROPERTY;
@property (copy) NSString* nameSuffix STUB_PROPERTY;
@property (copy) NSString* nickname STUB_PROPERTY;
@property (copy) NSPersonNameComponents* phoneticRepresentation STUB_PROPERTY;
@end
