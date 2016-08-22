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
#pragma once

#import <UIKit/UIApplication.h>

@interface UIApplication (internal)
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
- (void)_sendProtocolReceivedEvent:(WFUri*)uri;
@end

@interface WOCDisplayMode (internal)
- (float)currentWidth;
- (float)currentHeight;
- (void)_updateDisplaySettings;
- (void)_setWindowSize:(CGSize)newSize;
- (void)_setHostScrenWidth:(float)width height:(float)height scale:(float)scale xDpi:(float)xdpi yDpi:(float)yDpi;
@end

@interface UIApplication ()
- (UIView*)_popupLayer;
- (void)_setInternalOrientation:(UIInterfaceOrientation)orientation;
- (id)_keyboardChanged;
- (id)_evaluateKeyboard;
@end

// UIApplicationMainInit is declared here instead of UIApplicationMainInternal.h because it uses NS* types and cannot be defined in
// in a file that gets included in C++/CX sources.
UIKIT_EXPORT int UIApplicationMainInit(
    NSString* pClassName, NSString* dClassName, UIInterfaceOrientation defaultOrientation, int activationType, id activationArg);
void _UIApplicationShutdown();
