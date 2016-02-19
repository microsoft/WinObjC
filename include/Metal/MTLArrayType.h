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

#import <Foundation/NSObject.h>
#import <Metal/MetalExport.h>
#import <Metal/MTLArgument.h>

@class MTLStructType;

METAL_EXPORT_CLASS
@interface MTLArrayType : NSObject

@property (readonly) NSUInteger arrayLength STUB_PROPERTY;
@property (readonly) MTLDataType elementType STUB_PROPERTY;
@property (readonly) NSUInteger stride STUB_PROPERTY;

- (MTLArrayType*)elementArrayType STUB_METHOD;
- (MTLStructType*)elementStructType STUB_METHOD;

@end
