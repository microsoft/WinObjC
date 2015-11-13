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

#ifndef _CAPROPERTYANIMATION_H_
#define _CAPROPERTYANIMATION_H_

#import <QuartzCore/CAAnimation.h>

@interface CAPropertyAnimation : CAAnimation {
    id _keyPath;
}

+ animationWithKeyPath:(NSString*)keyPath;
@property (copy) NSString* keyPath;
@property (getter=isAdditive) BOOL additive;
@property (getter=isCumulative) BOOL cumulative;

@end

#endif /* _CAPROPERTYANIMATION_H_ */