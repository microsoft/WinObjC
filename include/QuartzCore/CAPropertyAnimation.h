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
#pragma once

#import <QuartzCore/CoreAnimationExport.h>
#import <QuartzCore/CAAction.h>
#import <QuartzCore/CAMediaTiming.h>
#import <QuartzCore/CAAnimation.h>

@class NSString;
@class CAValueFunction;

CA_EXPORT_CLASS
@interface CAPropertyAnimation : CAAnimation <CAAction, CAMediaTiming, NSCoding, NSCopying> {
    id _keyPath;
}

@property (copy) NSString* keyPath;
@property (getter=isCumulative) BOOL cumulative;
@property (getter=isAdditive) BOOL additive;
@property (strong) CAValueFunction* valueFunction STUB_PROPERTY;
+ (instancetype)animationWithKeyPath:(NSString*)keyPath;

@end
