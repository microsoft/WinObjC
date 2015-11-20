//******************************************************************************
//
//  UICollectionViewLayout+Internals.h
//  FMUICollectionView
//
// Created by Scott Talbot on 27/02/13.
// Copyright (c) 2013 Scott Talbot. All rights reserved.
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

#pragma once

#import <UIKit/UICollectionViewLayout.h>

@interface UICollectionViewLayout (Internals)

@property (nonatomic, copy, readonly) NSDictionary* decorationViewClassDict;
@property (nonatomic, copy, readonly) NSDictionary* decorationViewNibDict;
@property (nonatomic, copy, readonly) NSDictionary* decorationViewExternalObjectsTables;

@end

@interface UICollectionViewLayoutAttributes (Internals)

@property (readonly) BOOL isPinnedSupplementaryView;
-(void)setPinned:(BOOL)isPinned;

@end
