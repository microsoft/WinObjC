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

#ifndef _SLCOMPOSEVIEWCONTROLLER_H_
#define _SLCOMPOSEVIEWCONTROLLER_H_

#import <Social/SocialExport.h>
#import <UIKit/UIViewController.h>

enum {
    SLComposeViewControllerResultCancelled,
    SLComposeViewControllerResultDone
};
typedef uint32_t SLComposeViewControllerResult;

typedef void (^SLComposeViewControllerCompletionHandler) (SLComposeViewControllerResult result);

SOCIAL_EXPORT_CLASS
@interface SLComposeViewController : UIViewController

+ (SLComposeViewController *)composeViewControllerForServiceType:(NSString *)serviceType;
+ (BOOL)isAvailableForServiceType:(NSString *)serviceType;

- (BOOL)setInitialText:(NSString *)text;
- (BOOL)addURL:(NSURL *)url;
- (BOOL)addImage:(UIImage *)image;

@property (nonatomic, copy) SLComposeViewControllerCompletionHandler completionHandler;

@end

#endif /* _SLCOMPOSEVIEWCONTROLLER_H_ */