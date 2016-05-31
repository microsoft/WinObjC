//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#import "Starboard.h"
#import <StubReturn.h>

#import <UIKit/UIKit.h>

#import "UIApplicationInternal.h"
#import <NSBundleInternal.h>

#import <AVFoundation/AVFoundation.h>

#include <UWP/WindowsUIXamlControls.h>

#include <COMIncludes.h>
#import <RawBuffer.h>
#import <windows.storage.streams.h>
#include <COMIncludes_End.h>
#import "AssertARCEnabled.h"

// 100 nanoseconds per tick
static const double c_durationCoef = 10000000.0;
static const wchar_t* TAG = L"AVFoundation";

using namespace ABI::Windows::Foundation;
using namespace ABI::Windows::Storage::Streams;

using namespace Microsoft::WRL;

@interface _UIHiddenMediaView : UIView

@end

@implementation _UIHiddenMediaView

@end

@implementation AVAudioPlayer {
    _UIHiddenMediaView* _hiddenView;
    WXCMediaElement* _mediaElement;
    WUXMMediaElementState _lastState;

    NSDate* _startTime;

    float _rate;
    BOOL _enableRate;
    BOOL _playing;
    NSInteger _numberOfLoops;
    NSArray* _channelAssignments;
}

- (instancetype)init {
    if (self = [super init]) {
        _mediaElement = [WXCMediaElement make];
        _mediaElement.autoPlay = NO;
        _mediaElement.volume = 1.0f;
        _hiddenView = [[_UIHiddenMediaView alloc] initWithFrame:{ 0, 0, 0, 0 }];
        [_hiddenView setNativeElement:_mediaElement];

        _lastState = _mediaElement.currentState;

        // Set up events
        __weak AVAudioPlayer* weakSelf = self;

        [_mediaElement addCurrentStateChangedEvent:^(RTObject* sender, WXRoutedEventArgs* e) {
            [weakSelf _handleMediaElementStateChange:sender args:e];
        }];
        [_mediaElement addMediaEndedEvent:^(RTObject* sender, WXRoutedEventArgs* e) {
            [weakSelf _handleMediaElementMediaEnded:sender args:e];
        }];
        [_mediaElement addMediaFailedEvent:^(RTObject* sender, WXRoutedEventArgs* e) {
            [weakSelf _handleMediaElementMediaFailed:sender args:e];
        }];

        // We utilize the internal popup UIWindow, just to make sure we're always in the Xaml scene graph.
        [[[UIApplication sharedApplication] _popupWindow] addSubview:_hiddenView];
    }

    return self;
}

/**
 @Status Caveat
 @Notes Never returns an error
*/
- (instancetype)initWithContentsOfURL:(NSURL*)url error:(NSError**)outError {
    return [self initWithContentsOfURL:url fileTypeHint:nil error:outError];
}

/**
 @Status Caveat
 @Notes Never returns an error
*/
- (instancetype)initWithData:(NSData*)data error:(NSError**)outError {
    return [self initWithData:data fileTypeHint:nil error:outError];
}

/**
 @Status Caveat
 @Notes Never returns an error, fileTypeHint ignored
*/
- (instancetype)initWithContentsOfURL:(NSURL*)url fileTypeHint:(NSString*)utiString error:(NSError**)outError {
    if (self = [self init]) {
        if (!url) {
            @throw [NSException exceptionWithName:NSInvalidArgumentException reason:@"Argument 'url' cannot be nil" userInfo:nil];
        }

        _url = [[NSBundle mainBundle] _msAppxURLForResourceWithURL:url];
        WFUri* mediaUri = [WFUri makeUri:_url.absoluteString];

        TraceInfo(TAG, L"Loading media at URI: %hs\n", [mediaUri.absoluteUri UTF8String]);
        _mediaElement.source = mediaUri;

        if (outError) {
            // TODO: Some modicum of failure returns. Right now everything is async and bound to the Xaml thread, so
            // that's not possible.
            *outError = nil;
        }
    }

    return self;
}

/**
 @Status Caveat
 @Notes Never returns an error, fileTypeHint ignored
*/
- (instancetype)initWithData:(NSData*)data fileTypeHint:(NSString*)utiString error:(NSError**)outError {
    if (self = [self init]) {
        if (!data) {
            @throw [NSException exceptionWithName:NSInvalidArgumentException reason:@"Argument 'data' cannot be nil" userInfo:nil];
        }

        _data = data;

        WSSInMemoryRandomAccessStream* stream = [WSSInMemoryRandomAccessStream make];
        WSSDataWriter* rw = [WSSDataWriter makeDataWriter:[stream getOutputStreamAt:0]];
        ComPtr<IBuffer> buffer;
        IBuffer* rawBuffer = nullptr;
        HRESULT result;

        result = BufferFromRawData(&rawBuffer, (unsigned char*)[_data bytes], [_data length]);

        if (FAILED(result)) {
            @throw [NSException exceptionWithName:NSGenericException
                                           reason:@"Internal error: Failed to create IBuffer from NSData"
                                         userInfo:nil];
        }

        buffer.Attach(rawBuffer);

        // WARNING: If someone deletes this AVAudioPlayer before the StoreAsync is completed, _data may be released
        // causing IBuffer to segfault.

        // TODO: subclassed IAsyncOperation<T>s don't get generated correctly in ObjCUWP yet, when that happens it'll
        // open up StoreAsync.
        ComPtr<IDataWriter> writer;
        ComPtr<IAsyncOperation<UInt32>> comp;

        [rw comObj].As(&writer);

        FAIL_FAST_HR_IF_NULL_MSG(E_UNEXPECTED, writer.Get(), "WSSDataWriter does not confrom to IDataWriter");

        writer->WriteBuffer(buffer.Get());
        writer->StoreAsync(&comp);

        [_mediaElement setSource:stream mimeType:@""];

        // TODO: Is this needed?
        [rw detachStream];

        if (outError) {
            // TODO: Some modicum of failure returns. Right now everything is async and bound to the Xaml thread, so
            // that's not possible.
            *outError = nil;
        }
    }

    return self;
}

- (void)_handleMediaElementStateChange:(RTObject*)sender args:(WXRoutedEventArgs*)e {
    if (_mediaElement.currentState != _lastState) {
        switch (_mediaElement.currentState) {
            case WUXMMediaElementStateOpening:
            case WUXMMediaElementStateBuffering:
                break;

            case WUXMMediaElementStatePlaying:
                if (_startTime != nil) {
                    _startTime = nil;
                }
                _startTime = [NSDate new];
                _playing = TRUE;
                break;

            case WUXMMediaElementStateClosed:
                if ((_lastState == WUXMMediaElementStateOpening) || (_lastState == WUXMMediaElementStateBuffering)) {
                    if ([self.delegate respondsToSelector:@selector(audioPlayerDidFinishPlaying:successfully:)]) {
                        [self.delegate audioPlayerDidFinishPlaying:self successfully:FALSE];
                    }
                }

                _startTime = nil;
                _playing = FALSE;
                break;

            case WUXMMediaElementStateStopped:
            case WUXMMediaElementStatePaused:
                if ((_lastState == WUXMMediaElementStatePlaying) &&
                    [self.delegate respondsToSelector:@selector(audioPlayerDidFinishPlaying:successfully:)]) {
                    [self.delegate audioPlayerDidFinishPlaying:self successfully:TRUE];
                }

                _startTime = nil;
                _playing = FALSE;
                break;
        }

        _lastState = _mediaElement.currentState;
    }
}

- (void)_handleMediaElementMediaEnded:(RTObject*)sender args:(WXRoutedEventArgs*)e {
    TraceInfo(TAG, L"Media ended\n");
}

- (void)_handleMediaElementMediaFailed:(RTObject*)sender args:(WXRoutedEventArgs*)e {
    TraceWarning(TAG, L"Media failed\n");
}

/**
 @Status Caveat
 @Notes Always returns true
*/
- (BOOL)play {
    _playing = TRUE;

    // This is to catch the scenario where we play before the media is loaded.
    // It may be possibile the sound will play erroneously if someone plays, and a short time later pauses and catches
    // MediaElement in a (Loaded & !Playing) state
    _mediaElement.autoPlay = YES;

    [_mediaElement play];

    return TRUE;
}

/**
 @Status Stub
*/
- (BOOL)playAtTime:(NSTimeInterval)time {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
- (void)pause {
    _playing = FALSE;
    _mediaElement.autoPlay = NO;
    [_mediaElement pause];
}

/**
 @Status Interoperable
*/
- (void)stop {
    _playing = FALSE;
    _mediaElement.autoPlay = NO;
    [_mediaElement stop];
}

/**
 @Status Stub
*/
- (BOOL)prepareToPlay {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (float)averagePowerForChannel:(NSUInteger)channelNumber {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (float)peakPowerForChannel:(NSUInteger)channelNumber {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (void)updateMeters {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
- (NSInteger)numberOfLoops {
    return _numberOfLoops;
}

/**
 @Status Stub
*/
- (BOOL)isMeteringEnabled {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (void)setMeteringEnabled:(BOOL)enabled {
    UNIMPLEMENTED();
}

/**
 @Status Caveat
 @Notes 0 plays once, anything else plays forever
*/
- (void)setNumberOfLoops:(NSInteger)loops {
    _numberOfLoops = loops;
    _mediaElement.isLooping = (loops != 0);
}

/**
 @Status Stub
*/
- (NSUInteger)numberOfChannels {
    UNIMPLEMENTED();
    return 1;
}

/**
 @Status Stub
*/
- (NSArray*)channelAssignments {
    UNIMPLEMENTED();
    return _channelAssignments;
}

/**
 @Status Stub
*/
- (void)setChannelAssignments:(NSArray*)assignments {
    UNIMPLEMENTED();
    _channelAssignments = assignments;
}

/**
 @Status Interoperable
*/
- (NSTimeInterval)deviceCurrentTime {
    return [_startTime timeIntervalSinceNow];
}

/**
 @Status Interoperable
*/
- (NSTimeInterval)duration {
    NSTimeInterval interval = (NSTimeInterval)((double)_mediaElement.naturalDuration.timeSpan.duration / c_durationCoef);

    // This way sliders will still respond and keep the app operable.
    if (interval == 0) {
        return 1.0;
    } else {
        return interval;
    }
}

/**
 @Status Interoperable
*/
- (NSTimeInterval)currentTime {
    return (NSTimeInterval)((double)_mediaElement.position.duration / c_durationCoef);
}

/**
 @Status Interoperable
*/
- (void)setCurrentTime:(NSTimeInterval)currentTime {
    WFTimeSpan* ts = [WFTimeSpan new];
    ts.duration = (int64_t)((double)currentTime * c_durationCoef);
    _mediaElement.position = ts;
}

/**
 @Status Interoperable
*/
- (float)pan {
    return _mediaElement.balance;
}

/**
 @Status Interoperable
*/
- (void)setPan:(float)pan {
    _mediaElement.balance = pan;
}

/**
 @Status Interoperable
*/
- (BOOL)isPlaying {
    return _playing;
}

/**
 @Status Interoperable
*/
- (float)rate {
    return _rate;
}

/**
 @Status Interoperable
*/
- (void)setRate:(float)rate {
    _rate = rate;
    if (_enableRate) {
        _mediaElement.playbackRate = rate;
    }
}

/**
 @Status Interoperable
*/
- (BOOL)enableRate {
    return _enableRate;
}

/**
 @Status Interoperable
*/
- (void)setEnableRate:(BOOL)enable {
    _enableRate = enable;
    if (_enableRate) {
        _mediaElement.playbackRate = _rate;
    }
}

/**
 @Status Interoperable
*/
- (float)volume {
    return _mediaElement.volume;
}

/**
 @Status Interoperable
*/
- (void)setVolume:(float)volume {
    _mediaElement.volume = volume;
}

- (void)dealloc {
    [_hiddenView removeFromSuperview];
}

@end
