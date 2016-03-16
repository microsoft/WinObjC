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

#ifndef _UIAPPEARANCESETTER_H_
#define _UIAPPEARANCESETTER_H_

#import <Foundation/NSObject.h>

@class UIView;

@interface UIAppearanceSetter : NSObject
+ (void)_applyAppearance:(id)view;
+ (void)_applyAppearance:(id)view withAppearanceClass:(Class)cls withBaseView:(UIView*)baseView;
+ (id)_appearanceWhenContainedIn:(id)containedClass forUIClass:(id)uiClass;
@end

#endif /* _UIAPPEARANCESETTER_H_ */
