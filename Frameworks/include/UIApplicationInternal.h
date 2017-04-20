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

#import <UIKit/UIApplication.h>

#include "COMIncludes.h"
#import <inspectable.h>
#include "COMIncludes_End.h"

@class WMSSpeechRecognitionResult, WFUri, WAAFileActivatedEventArgs;

@interface UIApplication (internal)
// TODO: #2443 Remove _popupWindow (and all references to it) when we move UIAlertView over to Xaml
- (UIWindow*)_popupWindow;
- (void)_sendActiveStatus:(BOOL)isActive;
- (void)_sendToBackground;
- (void)_bringToForeground;
- (void)_bringToForeground:(NSURL*)url;
- (void)_sendHighMemoryWarning;
- (void)_sendSuspendEvent;
- (void)_sendResumeEvent;
- (void)_sendToastActionReceivedEvent:(NSDictionary*)toastAction;
- (void)_sendVoiceCommandReceivedEvent:(WMSSpeechRecognitionResult*)result;
- (void)_sendProtocolReceivedEvent:(WFUri*)protocolUri source:(NSString*)source;
- (void)_sendFileReceivedEvent:(WAAFileActivatedEventArgs*)result;
@end

@interface WOCDisplayMode (internal)
- (float)currentWidth;
- (float)currentHeight;
- (void)_updateDisplaySettings;
- (void)_setWindowSize:(CGSize)newSize;
- (void)_setHostScrenWidth:(float)width height:(float)height scale:(float)scale xDpi:(float)xdpi yDpi:(float)yDpi;
@end

// UIApplicationMainInit is declared here instead of UIApplicationMainInternal.h because it uses NS* types and cannot be defined in
// in a file that gets included in C++/CX sources.
void _UIApplicationMainInit(NSString* principalClassName, NSString* delegateClassName, int activationType, id activationArg);
void _UIApplicationShutdown();

id _createProjectionObject(const char* cls, IInspectable* source, const char* description);
