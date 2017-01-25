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

#include <Foundation/Foundation.h>
#import "URLDownloadCell.h"

static NSString* _formatSize(double size) {
    if (size < 1024.)
        return [NSString stringWithFormat:@"%.1lf b", size];
    size /= 1024.;
    if (size < 1024.)
        return [NSString stringWithFormat:@"%.1lf kb", size];
    size /= 1024.;
    return [NSString stringWithFormat:@"%.1lf mb", size];
}

@interface URLDownloadCell ()
- (void)_updateLabelColors;
@end

@implementation URLDownloadCell
@synthesize download = _download;

- (id)initWithReuseIdentifier:(NSString*)reuseIdentifier {
    if ((self = [super initWithStyle:UITableViewCellStyleDefault reuseIdentifier:reuseIdentifier]) != nil) {
        _nameLabel = [[UILabel alloc] initWithFrame:(CGRect){ 0, 0, 0, 0 }];
        _nameLabel.font = [UIFont boldSystemFontOfSize:14.f];

        _statusLabel = [[UILabel alloc] initWithFrame:(CGRect){ 0, 0, 0, 0 }];
        _statusLabel.font = [UIFont boldSystemFontOfSize:13.f];

        _sizeLabel = [[UILabel alloc] initWithFrame:(CGRect){ 0, 0, 0, 0 }];
        _sizeLabel.font = [UIFont systemFontOfSize:12.f];

        _progressLabel = [[UILabel alloc] initWithFrame:(CGRect){ 0, 0, 0, 0 }];
        _progressLabel.font = [UIFont systemFontOfSize:12.f];

        _progressView = [[UIProgressView alloc] initWithProgressViewStyle:UIProgressViewStyleDefault];

        [self.contentView addSubview:_nameLabel];
        [self.contentView addSubview:_statusLabel];
        [self.contentView addSubview:_sizeLabel];
        [self.contentView addSubview:_progressLabel];
        [self.contentView addSubview:_progressView];
        self.hidden = NO;
        self.contentView.hidden = NO;
    }
    return self;
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    [super setSelected:selected animated:animated];
    [self _updateLabelColors];
}

- (void)setHighlighted:(BOOL)highlighted animated:(BOOL)animated {
    [super setHighlighted:highlighted animated:animated];
    [self _updateLabelColors];
}

- (void)_updateLabelColors {
    if ((self.selected || self.highlighted) && self.selectionStyle != UITableViewCellSelectionStyleNone) {
        _nameLabel.textColor = [UIColor whiteColor];
        _statusLabel.textColor = [UIColor whiteColor];
        _sizeLabel.textColor = [UIColor whiteColor];
        _progressLabel.textColor = [UIColor whiteColor];
    } else {
        _nameLabel.textColor = [UIColor blackColor];
        if (_download && (_download.state == NSURLSessionTaskStateCanceling || _download.error != nil)) {
            _statusLabel.textColor = [UIColor colorWithRed:0.78f green:0.0f blue:0.0f alpha:1.0f];
        } else {
            _statusLabel.textColor = [UIColor grayColor];
        }
        _sizeLabel.textColor = [UIColor grayColor];
        _progressLabel.textColor = [UIColor grayColor];
    }
}

- (void)layoutSubviews {
    [super layoutSubviews];
    [self _updateLabelColors];

    CGRect bounds = self.contentView.bounds;
    bounds.origin.x += 6.f;
    bounds.origin.y += 6.f;
    bounds.size.width -= 12.f;
    bounds.size.height -= 12.f;

    [_nameLabel sizeToFit];
    [_statusLabel sizeToFit];
    [_sizeLabel sizeToFit];
    [_progressLabel sizeToFit];

    CGSize iconSize = (CGSize){ 24, 24 };
    CGFloat bottomOfImage = bounds.origin.x + iconSize.height;
    CGSize filenameSize = _nameLabel.frame.size;
    CGPoint nameOffset = { bounds.origin.x, (bounds.origin.y + floorf((iconSize.height - filenameSize.height) / 2.f)) };
    CGRect nameFrame = (CGRect){ nameOffset, { bounds.size.width - (nameOffset.x - bounds.origin.x), filenameSize.height } };
    CGFloat statusLineY = MAX(bottomOfImage, CGRectGetMaxY(nameFrame)) + 2.f;
    if (_download.state != NSURLSessionTaskStateCompleted) {
        if (_download.countOfBytesExpectedToReceive == NSURLSessionTransferSizeUnknown) {
            _progressLabel.hidden = YES;
        } else {
            _progressLabel.hidden = NO;
        }
        CGSize progressSize = _progressLabel.frame.size;
        _progressLabel.frame = (CGRect){ { bounds.origin.y + bounds.size.width - progressSize.width,
                                           MAX(bottomOfImage, CGRectGetMaxY(nameFrame)) - progressSize.height },
                                         progressSize };
        nameFrame.size.width -= (progressSize.width + 2.f);

        _progressView.hidden = NO;
        _progressView.frame = (CGRect){ { bounds.origin.x, statusLineY }, { bounds.size.width, _progressView.frame.size.height } };
        statusLineY = CGRectGetMaxY(_progressView.frame) + 2.f;
    } else {
        _progressLabel.hidden = YES;
        _progressView.hidden = YES;
    }

    // We do this here so the progressLabel can take its chunk before we min on the filename size.
    nameFrame.size.width = MIN(nameFrame.size.width, filenameSize.width);
    _nameLabel.frame = nameFrame;

    CGSize sizeSize = CGSizeZero;
    if (_download.countOfBytesExpectedToReceive != NSURLSessionTransferSizeUnknown) {
        _sizeLabel.hidden = NO;
        sizeSize = _sizeLabel.frame.size;
        _sizeLabel.frame = (CGRect){ { CGRectGetMaxX(bounds) - sizeSize.width, statusLineY }, sizeSize };
    } else {
        _sizeLabel.hidden = YES;
    }
    CGSize statusSize = _statusLabel.frame.size;
    _statusLabel.frame = (CGRect){ { bounds.origin.y, statusLineY },
                                   { MIN(statusSize.width, bounds.size.width - sizeSize.width - 4.f), statusSize.height } };
}

- (void)setDownload:(NSURLSessionTask*)download {
    _download = download;
    [self updateDisplay];
}

- (void)updateDisplay {
    _nameLabel.text = [[_download.currentRequest URL] absoluteString];
    _sizeLabel.text = _formatSize(_download.countOfBytesExpectedToReceive);

    [self _updateLabelColors];
    switch (_download.state) {
        case NSURLSessionTaskStateCompleted:
            if (_download.error == nil) {
                _statusLabel.text = @"Completed";
            } else {
                _statusLabel.text = @"Failed (Error)";
            }
            break;
        case NSURLSessionTaskStateCanceling:
            _statusLabel.text = @"Cancelled";
            break;
        case NSURLSessionTaskStateRunning:
            _statusLabel.text = @"";
            break;
        default:
            _statusLabel.text = @"Waiting";
            break;
    }

    [self updateProgress];
    [self setNeedsLayout];
}

- (void)updateProgress {
    if (_download.countOfBytesExpectedToReceive == 0 || _download.countOfBytesExpectedToReceive == NSURLSessionTransferSizeUnknown) {
        _progressView.progress = 0.;
    } else {
        _progressView.progress = (double)_download.countOfBytesReceived / (double)_download.countOfBytesExpectedToReceive;
    }
    _progressLabel.text = [NSString stringWithFormat:@"%u%%", (unsigned int)(_progressView.progress * 100.f)];
    if (_download.state == NSURLSessionTaskStateRunning) {
        [self setNeedsLayout];
    }
}
@end
