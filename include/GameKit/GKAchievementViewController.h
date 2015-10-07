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

#ifndef _GKACHIEVEMENTVIEWCONTROLLER_H_
#define _GKACHIEVEMENTVIEWCONTROLLER_H_

#import <GameKit/GameKitExport.h>
#import <UIKit/UINavigationController.h>

@protocol GKAchievementViewControllerDelegate
@end

GAMEKIT_EXPORT_CLASS
@interface GKAchievementViewController : UINavigationController

@property(nonatomic, assign) id<GKAchievementViewControllerDelegate> achievementDelegate;

@end

#endif // _GKACHIEVEMENTVIEWCONTROLLER_H_