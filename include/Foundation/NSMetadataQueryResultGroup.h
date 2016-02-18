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
@class NSArray;

FOUNDATION_EXPORT_CLASS
@interface NSMetadataQueryResultGroup : NSObject
@property (readonly, copy) NSString* attribute STUB_PROPERTY;
@property (readonly, retain) id value STUB_PROPERTY;
@property (readonly, copy) NSArray* results STUB_PROPERTY;
@property (readonly) NSUInteger resultCount STUB_PROPERTY;
- (id)resultAtIndex:(NSUInteger)index STUB_METHOD;
@property (readonly, copy) NSArray* subgroups STUB_PROPERTY;
@end
