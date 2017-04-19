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
#import "CppWinRTHelpers.h"

#import <AVFoundation/AVFoundation.h>

#include <COMIncludes.h>
#import <RawBuffer.h>
#import <windows.storage.streams.h>
#import <winrt/Windows.UI.Xaml.Controls.h>
#import <winrt/Windows.UI.Xaml.Media.h>
#import <winrt/Windows.Storage.Streams.h>
#include <COMIncludes_End.h>
#import "AssertARCEnabled.h"

// 100 nanoseconds per tick
static const double c_durationCoef = 10000000.0;
static const wchar_t* TAG = L"AVFoundation";

using namespace winrt::Windows::UI::Xaml;
using namespace ABI::Windows::Foundation;
using namespace ABI::Windows::Storage::Streams;

using namespace Microsoft::WRL;
namespace WF = winrt::Windows::Foundation;
namespace WSS = winrt::Windows::Storage::Streams;

@interface _UIHiddenMediaView : UIView

@end

@implementation _UIHiddenMediaView

@end

@implementation AVAudioPlayer {
    _UIHiddenMediaView* _hiddenView;
    TrivialDefaultConstructor<Controls::MediaElement> _mediaElement;
    TrivialDefaultConstructor<WSS::InMemoryRandomAccessStream> _stream;
    Media::MediaElementState _lastState;

    NSDate* _startTime;

    float _rate;
    BOOL _enableRate;
    BOOL _playing;
    NSInteger _numberOfLoops;
    NSArray* _channelAssignments;
}

- (instancetype)init {
    if (self = [super init]) {
        _mediaElement = Controls::MediaElement();
        _mediaElement.AutoPlay(false);
        _mediaElement.Volume(1.0f);
        _hiddenView = [[_UIHiddenMediaView alloc] initWithFrame:{ 0, 0, 0, 0 } xamlElement:objcwinrt::to_rtobj(_mediaElement)];

        _lastState = _mediaElement.CurrentState();

        // Set up events
        __weak AVAudioPlayer* weakSelf = self;

        _mediaElement.CurrentStateChanged([weakSelf] (const WF::IInspectable& sender, const RoutedEventArgs& e) {
            [weakSelf _handleMediaElementStateChange:sender args:e];
        });
        _mediaElement.MediaEnded([weakSelf] (const WF::IInspectable& sender, const RoutedEventArgs& e) {
            [weakSelf _handleMediaElementMediaEnded:sender args:e];
        });
        _mediaElement.MediaFailed([weakSelf] (const WF::IInspectable& sender, const RoutedEventArgs& e) {
            [weakSelf _handleMediaElementMediaFailed:sender args:e];
        });

        // Add ourselves to the keyWindow even though we're hidden, just to make sure we're always in the Xaml scene graph.
        [[[UIApplication sharedApplication] keyWindow] addSubview:_hiddenView];
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
        WF::Uri mediaUri = winrt::hstring_view(objcwinrt::string(_url.absoluteString));

        TraceInfo(TAG, L"Loading media at URI: %ls\n", mediaUri.AbsoluteUri().c_str());
        _mediaElement.Source(mediaUri);

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
        _stream = WSS::InMemoryRandomAccessStream();

        WSS::DataWriter rw = _stream.GetOutputStreamAt(0);
        WSS::Buffer buffer = nullptr;
        IBuffer* rawBuffer = nullptr;
        HRESULT result;

        result = BufferFromRawData(&rawBuffer, (unsigned char*)[_data bytes], [_data length]);

        if (FAILED(result)) {
            @throw [NSException exceptionWithName:NSGenericException
                                           reason:@"Internal error: Failed to create IBuffer from NSData"
                                         userInfo:nil];
        }

        winrt::attach_abi(buffer, reinterpret_cast<winrt::ABI::Windows::Storage::Streams::IBuffer*>(rawBuffer));

        rw.WriteBuffer(buffer);
        WSS::DataWriterStoreOperation async = rw.StoreAsync();

        // Hook the stream up to the media control when the load is complete
        async.Completed(objcwinrt::callback([self] (const WF::IAsyncOperation<unsigned int>& operation, WF::AsyncStatus status) {
            if (status == WF::AsyncStatus::Completed) {
                // Access XAML control on main thread
                dispatch_sync(dispatch_get_main_queue(), ^{
                    self->_mediaElement.SetSource(self->_stream, L"");
                    self->_stream = nullptr;
                });
            }
        }));

        if (outError) {
            // TODO: Some modicum of failure returns. Right now everything is async and bound to the Xaml thread, so
            // that's not possible.
            *outError = nil;
        }
    }

    return self;
}

- (void)_handleMediaElementStateChange:(const WF::IInspectable&)sender args:(const RoutedEventArgs&)e {
    if (_mediaElement.CurrentState() != _lastState) {
        switch (_mediaElement.CurrentState()) {
            case Media::MediaElementState::Opening:
            case Media::MediaElementState::Buffering:
                break;

            case Media::MediaElementState::Playing:
                if (_startTime != nil) {
                    _startTime = nil;
                }
                _startTime = [NSDate new];
                _playing = TRUE;
                break;

            case Media::MediaElementState::Closed:
                if ((_lastState == Media::MediaElementState::Opening) || (_lastState == Media::MediaElementState::Buffering)) {
                    if ([self.delegate respondsToSelector:@selector(audioPlayerDidFinishPlaying:successfully:)]) {
                        [self.delegate audioPlayerDidFinishPlaying:self successfully:FALSE];
                    }
                }

                _startTime = nil;
                _playing = FALSE;
                break;

            case Media::MediaElementState::Stopped:
            case Media::MediaElementState::Paused:
                if ((_lastState == Media::MediaElementState::Playing) &&
                    [self.delegate respondsToSelector:@selector(audioPlayerDidFinishPlaying:successfully:)]) {
                    [self.delegate audioPlayerDidFinishPlaying:self successfully:TRUE];
                }

                _startTime = nil;
                _playing = FALSE;
                break;
        }

        _lastState = _mediaElement.CurrentState();
    }
}

- (void)_handleMediaElementMediaEnded:(const WF::IInspectable&)sender args:(const RoutedEventArgs&)e {
    TraceInfo(TAG, L"Media ended\n");
}

- (void)_handleMediaElementMediaFailed:(const WF::IInspectable&)sender args:(const RoutedEventArgs&)e {
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
    _mediaElement.AutoPlay(true);

    _mediaElement.Play();

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
    _mediaElement.AutoPlay(false);
    _mediaElement.Pause();
}

/**
 @Status Interoperable
*/
- (void)stop {
    _playing = FALSE;
    _mediaElement.AutoPlay(false);
    _mediaElement.Stop();
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
    _mediaElement.IsLooping(loops != 0);
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
    WF::TimeSpan duration = _mediaElement.NaturalDuration().TimeSpan;
    auto seconds = std::chrono::duration_cast<std::chrono::seconds>(duration);
    NSTimeInterval interval = seconds.count();

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
    WF::TimeSpan position = _mediaElement.Position();
    auto seconds = std::chrono::duration_cast<std::chrono::seconds>(position);

    return seconds.count();
}

/**
 @Status Interoperable
*/
- (void)setCurrentTime:(NSTimeInterval)currentTime {
    std::chrono::seconds time(static_cast<std::chrono::seconds::rep>(currentTime));
    _mediaElement.Position(std::chrono::duration_cast<WF::TimeSpan>(time));
}

/**
 @Status Interoperable
*/
- (float)pan {
    return _mediaElement.Balance();
}

/**
 @Status Interoperable
*/
- (void)setPan:(float)pan {
    _mediaElement.Balance(pan);
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
        _mediaElement.PlaybackRate(rate);
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
        _mediaElement.PlaybackRate(_rate);
    }
}

/**
 @Status Interoperable
*/
- (float)volume {
    return _mediaElement.Volume();
}

/**
 @Status Interoperable
*/
- (void)setVolume:(float)volume {
    _mediaElement.Volume(volume);
}

- (void)dealloc {
    [_hiddenView removeFromSuperview];
}

@end
