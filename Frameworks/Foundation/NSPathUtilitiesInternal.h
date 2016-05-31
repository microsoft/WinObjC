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
extern NSString* _NSGetSlashStr();

// Below helpers are based off of helpers from Foundation/NSPathUtilities.swift
using FilePathPredicate = bool (^)(NSString*);

extern NSString* _stringFromDataWithEncoding(NSString* self, NSData* data, NSStringEncoding encoding);
extern NSString* _stringFromDataByDeterminingEncoding(NSString* self, NSData* data, NSStringEncoding* usedEncoding);
extern NSString* _longestCommonPrefix(NSArray* strings, BOOL caseSensitive);
extern NSString* _ensureLastPathSeparator(NSString* path);
extern NSString* _ensureLastPathSeparator(NSString* path);
extern BOOL _stringIsPathToDirectory(NSString* path);
extern BOOL _stringLooksLikeOrIsPathToDirectory(NSString* path);
extern FilePathPredicate _getFileNamePredicate(NSString* thePrefix, BOOL caseSensitive);
extern FilePathPredicate _getExtensionPredicate(NSArray* exts, BOOL caseSensitive);
extern NSMutableArray* _getNamesAtURL(NSURL* filePathURL,
                                      NSString* prependWith,
                                      FilePathPredicate namePredicate,
                                      FilePathPredicate typePredicate);
extern BOOL _isLetter(unichar character);