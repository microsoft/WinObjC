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
#import <QuartzCore/CAAnimation.h>

@class NSString;

CA_EXPORT NSString* const kCATransitionFade;
CA_EXPORT NSString* const kCATransitionMoveIn;
CA_EXPORT NSString* const kCATransitionPush;
CA_EXPORT NSString* const kCATransitionReveal;
CA_EXPORT NSString* const kCATransitionFromRight;
CA_EXPORT NSString* const kCATransitionFromLeft;
CA_EXPORT NSString* const kCATransitionFromTop;
CA_EXPORT NSString* const kCATransitionFromBottom;

CA_EXPORT_CLASS
@interface CATransition : CAAnimation <CAAction, CAMediaTiming, NSCoding, NSCopying> {
    NSString* _type;
    NSString* _subtype;
}

@property float startProgress;
@property float endProgress;
@property (copy) NSString* type;
@property (copy) NSString* subtype;
@property (strong) id filter STUB_PROPERTY;

@end
