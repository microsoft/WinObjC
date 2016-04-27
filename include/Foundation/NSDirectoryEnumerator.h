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
#import <Foundation/NSFastEnumeration.h>
#import <Foundation/NSObject.h>

#import <Foundation/NSEnumerator.h>

@class NSDictionary<KeyType, ObjectType>;

FOUNDATION_EXPORT_CLASS
@interface NSDirectoryEnumerator <ObjectType> : NSEnumerator <NSFastEnumeration>
@property (readonly, copy) NSDictionary<NSString*, id>* directoryAttributes;
@property (readonly, copy) NSDictionary<NSString*, id>* fileAttributes;
@property (readonly) NSUInteger level;
- (void)skipDescendents;
- (void)skipDescendants;
@end
