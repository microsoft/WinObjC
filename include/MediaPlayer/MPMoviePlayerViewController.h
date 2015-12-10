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

#ifndef _MPMOVIEPLAYERVIEWCONTROLLER_H_
#define _MPMOVIEPLAYERVIEWCONTROLLER_H_

#import <UIKit/UIViewController.h>

@class MPMoviePlayerController;

UIKIT_EXPORT_CLASS
@interface MPMoviePlayerViewController : UIViewController <NSCoding, NSObject, UIAppearanceContainer>

- (instancetype)initWithContentURL:(NSURL *)contentURL;
@property(nonatomic, readonly) MPMoviePlayerController *moviePlayer;
- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation;

@end

#endif /* _MPMOVIEPLAYERVIEWCONTROLLER_H_ */