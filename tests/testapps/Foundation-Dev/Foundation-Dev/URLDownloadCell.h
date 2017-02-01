//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

#include <Foundation/Foundation.h>
#include <UIKit/UIKit.h>

@class NSURLSessionTask;

@interface URLDownloadCell : UITableViewCell {
    NSURLSessionTask* _download;
    UIProgressView* _progressView;
    UILabel* _nameLabel;
    UILabel* _statusLabel;
    UILabel* _sizeLabel;
    UILabel* _progressLabel;
    UIImageView* _iconImageView;
}
@property (nonatomic, retain) NSURLSessionTask* download;
- (id)initWithReuseIdentifier:(NSString*)reuseIdentifier;
- (void)updateDisplay;
- (void)updateProgress;
@end
