//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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
// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2015 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See http://swift.org/LICENSE.txt for license information
// See http://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//

#pragma once

#import <Foundation/NSString.h>

@class NSArray;
@class NSData;
@class NSMutableArray;

// Helper that returns the path separator character
static NSString* _NSGetSlashStr();

// Below helpers are based off of helpers from Foundation/NSPathUtilities.swift
using FilePathPredicate = bool (^)(NSString*);

static NSString* _stringFromDataWithEncoding(NSString* self, NSData* data, NSStringEncoding encoding);
static NSString* _longestCommonPrefix(NSArray* strings, BOOL caseSensitive);
static NSString* _ensureLastPathSeparator(NSString* path);
static NSString* _ensureLastPathSeparator(NSString* path);
static BOOL _stringIsPathToDirectory(NSString* path);
static FilePathPredicate _getFileNamePredicate(NSString* thePrefix, BOOL caseSensitive);
static FilePathPredicate _getExtensionPredicate(NSArray* exts, BOOL caseSensitive);
static NSMutableArray* _getNamesAtURL(NSURL* filePathURL,
                                      NSString* prependWith,
                                      FilePathPredicate namePredicate,
                                      FilePathPredicate typePredicate);