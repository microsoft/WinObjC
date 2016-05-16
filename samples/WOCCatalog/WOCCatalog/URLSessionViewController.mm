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

#import "URLSessionViewController.h"
#import "URLDownloadCell.h"

@interface URLSessionViewController () <UITableViewDataSource,
                                        UITableViewDelegate,
                                        NSURLSessionDelegate,
                                        NSURLSessionTaskDelegate,
                                        NSURLSessionDownloadDelegate> {
    NSURLSession* _urlSession;

    UITextField* _urlTextField;
    UITextView* _delegateOutputTextView;
    UISwitch* _blockSwitch;

    NSURLSessionTask* _lastTask;
    NSData* _lastResumeData;
    UITableView* _tableView;
    NSMutableArray* _tasks;
    NSOperationQueue* _delegateQueue;

    UIView* _blockSwitchContainer;
}
@end

@implementation URLSessionViewController
- (id)init {
    if (self = [super init]) {
        _delegateQueue = [[NSOperationQueue alloc] init];
        [_delegateQueue setMaxConcurrentOperationCount:5];
        _urlSession = [NSURLSession sessionWithConfiguration:nil delegate:self delegateQueue:_delegateQueue];
        _tasks = [NSMutableArray new];
    }
    return self;
}

- (NSString*)title {
    return @"URL Session";
}

#define URL_BAR_HEIGHT 44.f
#define BUTTON_ROW_Y (44.f + 4.f)
#define BUTTON_ROW_ITEM_WIDTH (80.f)
#define BUTTON_ROW_HEIGHT 34.f
#define BUTTON_ROW_ITEM_X(n) ((float)((BUTTON_ROW_ITEM_WIDTH + 4.f) * (n)))
#define BUTTON_ROW_ITEM_Y(n) ((float)(BUTTON_ROW_Y + (BUTTON_ROW_HEIGHT + 4.f) * (n)))
#define BUTTON_NUM_IN_ROW 4

- (void)loadView {
    [super loadView];
    self.edgesForExtendedLayout = UIRectEdgeNone;
    self.view.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    self.view.backgroundColor = [UIColor whiteColor];

    _urlTextField = [[UITextField alloc] initWithFrame:(CGRect){ 0, 0, 0, URL_BAR_HEIGHT }];
    _urlTextField.placeholder = @"URL (https://...)";
    _urlTextField.font = [UIFont systemFontOfSize:17.];
    _urlTextField.text = @"https://httpbin.org/cookies/set?winobjc=awesome";
    _urlTextField.borderStyle = UITextBorderStyleBezel;
    [self.view addSubview:_urlTextField];

    int nbuttons = 0;

    UIButton* dataTaskButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    dataTaskButton.frame = (CGRect){ BUTTON_ROW_ITEM_X(nbuttons % BUTTON_NUM_IN_ROW), BUTTON_ROW_ITEM_Y(nbuttons++ / BUTTON_NUM_IN_ROW), BUTTON_ROW_ITEM_WIDTH, BUTTON_ROW_HEIGHT };
    [dataTaskButton setTitle:@"Data" forState:UIControlStateNormal];
    [dataTaskButton addTarget:self action:@selector(dataTaskButtonPressed:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:dataTaskButton];

    UIButton* downloadTaskButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    downloadTaskButton.frame = (CGRect){ BUTTON_ROW_ITEM_X(nbuttons % BUTTON_NUM_IN_ROW), BUTTON_ROW_ITEM_Y(nbuttons++ / BUTTON_NUM_IN_ROW), BUTTON_ROW_ITEM_WIDTH, BUTTON_ROW_HEIGHT };
    [downloadTaskButton setTitle:@"Download" forState:UIControlStateNormal];
    [downloadTaskButton addTarget:self action:@selector(downloadTaskButtonPressed:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:downloadTaskButton];

    _blockSwitchContainer = [[UIView alloc] initWithFrame:(CGRect){ 0, 0, 128, URL_BAR_HEIGHT }];
    _blockSwitch = [[UISwitch alloc] initWithFrame:CGRectZero];
    [_blockSwitchContainer addSubview:_blockSwitch];
    UILabel* blockLabel = [[UILabel alloc] initWithFrame:CGRectZero];
    blockLabel.text = @"Blocks";
    blockLabel.font = [UIFont systemFontOfSize:10.f];
    [blockLabel sizeToFit];
    CGRect ownerBounds = _blockSwitchContainer.bounds;
    CGSize labelSize = blockLabel.frame.size;
    CGSize switchSize = _blockSwitch.frame.size;
    _blockSwitch.frame = (CGRect){ (ownerBounds.size.width - (labelSize.width + switchSize.width + 4)) / 2,
                                   (ownerBounds.size.height - switchSize.height) / 2,
                                   switchSize };
    blockLabel.frame =
        (CGRect){ _blockSwitch.frame.origin.x + switchSize.width + 4, (ownerBounds.size.height - labelSize.height) / 2, labelSize };
    [_blockSwitchContainer addSubview:blockLabel];
    [self.view addSubview:_blockSwitchContainer];

    UIButton* cancelLastButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    cancelLastButton.frame = (CGRect){ BUTTON_ROW_ITEM_X(nbuttons % BUTTON_NUM_IN_ROW), BUTTON_ROW_ITEM_Y(nbuttons++ / BUTTON_NUM_IN_ROW), BUTTON_ROW_ITEM_WIDTH, BUTTON_ROW_HEIGHT };
    [cancelLastButton setTitle:@"Cancel" forState:UIControlStateNormal];
    [cancelLastButton addTarget:self action:@selector(cancelLastButtonPressed:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:cancelLastButton];

    UIButton* resumeLastButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    resumeLastButton.frame = (CGRect){ BUTTON_ROW_ITEM_X(nbuttons % BUTTON_NUM_IN_ROW), BUTTON_ROW_ITEM_Y(nbuttons++ / BUTTON_NUM_IN_ROW), BUTTON_ROW_ITEM_WIDTH, BUTTON_ROW_HEIGHT };
    [resumeLastButton setTitle:@"Resume" forState:UIControlStateNormal];
    [resumeLastButton addTarget:self action:@selector(resumeLastButtonPressed:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:resumeLastButton];

    UIButton* legacyDownloadButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    legacyDownloadButton.frame = (CGRect){ BUTTON_ROW_ITEM_X(nbuttons % BUTTON_NUM_IN_ROW), BUTTON_ROW_ITEM_Y(nbuttons++ / BUTTON_NUM_IN_ROW), BUTTON_ROW_ITEM_WIDTH, BUTTON_ROW_HEIGHT };
    [legacyDownloadButton setTitle:@"Legacy" forState:UIControlStateNormal];
    [legacyDownloadButton addTarget:self action:@selector(legacyDownloadButtonPressed:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:legacyDownloadButton];

    _tableView = [[UITableView alloc] initWithFrame:CGRectZero];
    _tableView.dataSource = self;
    _tableView.delegate = self;
    [self.view addSubview:_tableView];

    _delegateOutputTextView = [[UITextView alloc] initWithFrame:CGRectZero];
    _delegateOutputTextView.editable = NO;
    _delegateOutputTextView.font = [UIFont systemFontOfSize:12.];
    [self.view addSubview:_delegateOutputTextView];
}

- (void)viewDidLayoutSubviews {
    CGRect bounds = self.view.bounds;
    _blockSwitchContainer.frame =
        (CGRect){ self.view.bounds.size.width - _blockSwitchContainer.bounds.size.width, 0, _blockSwitchContainer.bounds.size };
    _urlTextField.frame = (CGRect){ 0, 0, bounds.size.width - (_blockSwitchContainer.bounds.size.width + 4), URL_BAR_HEIGHT };
    CGFloat contentOrigin = 2 * (BUTTON_ROW_HEIGHT + 4) + URL_BAR_HEIGHT + 4;
    _delegateOutputTextView.frame =
        (CGRect){ 0, floorf(bounds.size.height - .25f * bounds.size.height), bounds.size.width, floorf(.25f * bounds.size.height) };
    _tableView.frame = (CGRect){ 0,
                                 contentOrigin,
                                 bounds.size.width,
                                 bounds.size.height - (contentOrigin + _delegateOutputTextView.frame.size.height + 4) };
}

- (void)_reloadData {
    dispatch_async(dispatch_get_main_queue(),
                   ^{
                       [_tableView reloadData];
                   });
}
- (void)_redrawCellForTask:(NSURLSessionTask*)task {
    dispatch_async(dispatch_get_main_queue(),
                   ^{
                       NSIndexPath* indexPath = [NSIndexPath indexPathForRow:[_tasks indexOfObject:task] inSection:0];
                       URLDownloadCell* downloadCell = (URLDownloadCell*)[_tableView cellForRowAtIndexPath:indexPath];
                       [downloadCell updateDisplay];
                   });
}

- (void)_reloadTaskProgress:(NSURLSessionTask*)task {
    dispatch_async(dispatch_get_main_queue(),
                   ^{
                       NSIndexPath* indexPath = [NSIndexPath indexPathForRow:[_tasks indexOfObject:task] inSection:0];
                       URLDownloadCell* downloadCell = (URLDownloadCell*)[_tableView cellForRowAtIndexPath:indexPath];
                       [downloadCell updateProgress];
                   });
}

- (void)_clear {
    void (^block)() = ^{
        @synchronized(self) {
            _delegateOutputTextView.text = @"";
        }
    };
    if ([NSThread isMainThread]) {
        block();
    } else {
        dispatch_async(dispatch_get_main_queue(), block);
    }
}

- (void)_printOutput:(NSString*)format, ... {
    va_list ap;
    va_start(ap, format);
    NSString* newString = [[NSString alloc] initWithFormat:format arguments:ap];
    void (^block)() = ^{
        @synchronized(self) {
            _delegateOutputTextView.text = [_delegateOutputTextView.text stringByAppendingString:newString];
        }
    };
    if ([NSThread isMainThread]) {
        block();
    } else {
        dispatch_async(dispatch_get_main_queue(), block);
    }
    va_end(ap);
}

- (void)dataTaskButtonPressed:(id)sender {
    [self _clear];
    NSURLSessionDataTask* newTask = nil;
    if ([_blockSwitch isOn]) {
        newTask = [_urlSession
              dataTaskWithURL:[NSURL URLWithString:_urlTextField.text]
            completionHandler:^(NSData* data, NSURLResponse* response, NSError* error) {
                [self _printOutput:@"Data Task completed with %d bytes, %@, %@\n", data.length, response, error];
                [self _printOutput:@"Headers: %@\n", [(NSHTTPURLResponse*)response allHeaderFields]];
                [self _printOutput:@"%@\n",
                                   [[NSString alloc] initWithBytes:data.bytes length:MIN(256, data.length) encoding:NSUTF8StringEncoding]];
            }];
    } else {
        newTask = [_urlSession dataTaskWithURL:[NSURL URLWithString:_urlTextField.text]];
    }
    [self _printOutput:@"New data task.\n"];
    [newTask resume];
    _lastTask = newTask;
    [_tasks addObject:newTask];
    [self _reloadData];
}

- (void)downloadTaskButtonPressed:(id)sender {
    [self _clear];
    NSURLSessionDownloadTask* newTask = nil;
    if ([_blockSwitch isOn]) {
        newTask = [_urlSession downloadTaskWithURL:[NSURL URLWithString:_urlTextField.text]
                                 completionHandler:^(NSURL* location, NSURLResponse* response, NSError* error) {
                                     [self _printOutput:@"Download Task completed to %@: %@, %@\n", location, response, error];
                                 }];
    } else {
        newTask = [_urlSession downloadTaskWithURL:[NSURL URLWithString:_urlTextField.text]];
    }
    [self _printOutput:@"New download task.\n"];
    [newTask resume];
    _lastTask = newTask;
    [_tasks addObject:newTask];
    [self _reloadData];
}

- (void)cancelLastButtonPressed:(id)sender {
    if ([_lastTask isKindOfClass:[NSURLSessionDownloadTask class]]) {
        [(NSURLSessionDownloadTask*)_lastTask cancelByProducingResumeData:^(NSData* resumeData) {
            [self _printOutput:@"Download task produced resume data (size %d)\n", resumeData.length];
            _lastResumeData = resumeData;
        }];
    } else {
        [_lastTask cancel];
    }
}

- (void)resumeLastButtonPressed:(id)sender {
    NSURLSessionDownloadTask* newTask = nil;
    if ([_blockSwitch isOn]) {
        newTask = [_urlSession downloadTaskWithResumeData:_lastResumeData
                                        completionHandler:^(NSURL* location, NSURLResponse* response, NSError* error) {
                                            [self _printOutput:@"Resumed Task completed to %@: %@, %@\n", location, response, error];
                                        }];
    } else {
        newTask = [_urlSession downloadTaskWithResumeData:_lastResumeData];
    }
    if (!newTask) {
        [self _printOutput:@"There wasn't anything to resume.\n"];
        return;
    }
    [self _printOutput:@"New resumed task.\n", newTask];
    [newTask resume];
    _lastTask = newTask;
    [_tasks addObject:newTask];
    [self _reloadData];
}

- (void)legacyDownloadButtonPressed:(id)sender {
    [self _clear];
    NSMutableURLRequest* request = [NSMutableURLRequest requestWithURL:[NSURL URLWithString:_urlTextField.text]];
    __autoreleasing NSError* error = nil;
    __autoreleasing NSURLResponse* response = nil;
    NSURLConnection* conn = [[NSURLConnection alloc] initWithRequest:request delegate:self startImmediately:NO];
    [conn scheduleInRunLoop:[NSRunLoop mainRunLoop] forMode:NSDefaultRunLoopMode];
    [conn start];
}

- (void)connection:(NSURLConnection*)connection didReceiveResponse:(NSURLResponse*)response {
    [self _printOutput:@"Legacy connection received response:\nStatus %d\nHeaders: %@\n---\n",
                       [(NSHTTPURLResponse*)response statusCode],
                       [(NSHTTPURLResponse*)response allHeaderFields]];
}

- (void)connection:(NSURLConnection*)connection didReceiveData:(nonnull NSData*)data {
    [self _printOutput:@"%@", [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding]];
}

- (void)connection:(NSURLConnection*)connection didFailWithError:(NSError*)e {
    [self _printOutput:@"Legacy connection failed: %@\n", e];
}

- (void)URLSession:(NSURLSession*)session didBecomeInvalidWithError:(NSError*)error {
    [self _printOutput:@"URL Session became invalid with error %@\n", error];
}

- (void)URLSession:(NSURLSession*)session
    didReceiveChallenge:(NSURLAuthenticationChallenge*)challenge
      completionHandler:(void (^)(NSURLSessionAuthChallengeDisposition disposition, NSURLCredential* credential))completionHandler {
    [self _printOutput:@"URL Session received authentication challenge %@\n", challenge];
    completionHandler(NSURLSessionAuthChallengePerformDefaultHandling, nil);
}

- (void)URLSessionDidFinishEventsForBackgroundURLSession:(NSURLSession*)session {
    [self _printOutput:@"URL Session finished background events.\n"];
}

- (void)URLSession:(NSURLSession*)session task:(NSURLSessionTask*)task didCompleteWithError:(NSError*)error {
    if (error) {
        [self _printOutput:@"\nTask completed with error %@\n", error];
    } else {
        [self _printOutput:@"\nTask completed without issue.\n", error];
    }
    [self _redrawCellForTask:task];
}

- (void)URLSession:(NSURLSession*)session
                   task:(NSURLSessionTask*)task
    didReceiveChallenge:(NSURLAuthenticationChallenge*)challenge
      completionHandler:(void (^)(NSURLSessionAuthChallengeDisposition disposition, NSURLCredential* credential))completionHandler {
    [self _printOutput:@"Task received auth challenge %@\n", challenge];
    completionHandler(NSURLSessionAuthChallengePerformDefaultHandling, nil);
    [self _redrawCellForTask:task];
}

- (void)URLSession:(NSURLSession*)session
                        task:(NSURLSessionTask*)task
             didSendBodyData:(int64_t)bytesSent
              totalBytesSent:(int64_t)totalBytesSent
    totalBytesExpectedToSend:(int64_t)totalBytesExpectedToSend {
    [self _printOutput:@"Task sent %lld bytes (%lld total) out of %lld\n", bytesSent, totalBytesSent, totalBytesExpectedToSend];

    [self _redrawCellForTask:task];
}

- (void)URLSession:(NSURLSession*)session
              task:(NSURLSessionTask*)task
 needNewBodyStream:(void (^)(NSInputStream* bodyStream))completionHandler {
    [self _printOutput:@"Task needs a new body stream\n"];
    completionHandler(nil);

    [self _redrawCellForTask:task];
}

- (void)URLSession:(NSURLSession*)session
                          task:(NSURLSessionTask*)task
    willPerformHTTPRedirection:(NSHTTPURLResponse*)response
                    newRequest:(NSURLRequest*)request
             completionHandler:(void (^)(NSURLRequest*))completionHandler {
    [self _printOutput:@"Task will redirect (resp %@, req %@)\n", response, [request URL]];
    completionHandler(request);
    [self _redrawCellForTask:task];
}

- (void)URLSession:(NSURLSession*)session
          dataTask:(NSURLSessionDataTask*)task
didReceiveResponse:(NSURLResponse*)response
 completionHandler:(void (^)(NSURLSessionResponseDisposition disposition))completionHandler {
    [self _printOutput:@"Data Task received response %@\n", response];
    completionHandler(NSURLSessionResponseAllow);
    [self _redrawCellForTask:task];
}

- (void)URLSession:(NSURLSession*)session
                 dataTask:(NSURLSessionDataTask*)task
    didBecomeDownloadTask:(NSURLSessionDownloadTask*)downloadTask {
    [self _printOutput:@"Data Task promoted to DOWNLOAD task.\n"];
    [self _redrawCellForTask:task];
}

- (void)URLSession:(NSURLSession*)session dataTask:(NSURLSessionDataTask*)task didReceiveData:(NSData*)data {
    if (task.countOfBytesExpectedToReceive <= 1024) {
        [self _printOutput:@"%@", [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding]];
    }
    [self _reloadTaskProgress:task];
}

- (void)URLSession:(NSURLSession*)session
          dataTask:(NSURLSessionDataTask*)task
 willCacheResponse:(NSCachedURLResponse*)proposedResponse
 completionHandler:(void (^)(NSCachedURLResponse*))completionHandler {
    [self _printOutput:@"Data Task wants to cache response.\n"];
    completionHandler(proposedResponse);
    [self _redrawCellForTask:task];
}

- (void)URLSession:(NSURLSession*)session
      downloadTask:(NSURLSessionDownloadTask*)task
 didResumeAtOffset:(int64_t)offset
expectedTotalBytes:(int64_t)expectedTotalBytes {
    [self _printOutput:@"Download Task resumed at %lld of %lld\n", offset, expectedTotalBytes];
    [self _redrawCellForTask:task];
}

- (void)URLSession:(NSURLSession*)session
                 downloadTask:(NSURLSessionDownloadTask*)task
                 didWriteData:(int64_t)bytesWritten
            totalBytesWritten:(int64_t)totalBytesWritten
    totalBytesExpectedToWrite:(int64_t)totalBytesExpectedToWrite {
    [self _reloadTaskProgress:task];
}

- (void)URLSession:(NSURLSession*)session downloadTask:(NSURLSessionDownloadTask*)task didFinishDownloadingToURL:(NSURL*)url {
    [self _printOutput:@"\nDownload Task completed writing to %@\n", url];

    [self _redrawCellForTask:task];
}

- (NSInteger)tableView:(UITableView*)tableView numberOfRowsInSection:(NSInteger)section {
    return [_tasks count];
}

- (UITableViewCell*)tableView:(UITableView*)tableView cellForRowAtIndexPath:(NSIndexPath*)indexPath {
    NSURLSessionTask* task = [_tasks objectAtIndex:indexPath.row];
    URLDownloadCell* cell = (URLDownloadCell*)[tableView dequeueReusableCellWithIdentifier:@"DownloadCell"];
    if (nil == cell) {
        cell = [[URLDownloadCell alloc] initWithReuseIdentifier:@"DownloadCell"];
    }

    cell.download = task;
    return cell;
}

- (CGFloat)tableView:(UITableView*)tableView heightForRowAtIndexPath:(NSIndexPath*)indexPath {
    return 60.f;
}

- (void)tableView:(UITableView*)tableView didSelectRowAtIndexPath:(NSIndexPath*)indexPath {
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
}

@end
