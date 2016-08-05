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

static const wchar_t* c_backgroundTaskName = L"Windows.WinObjC.BackgroundTask";

#ifndef __cplusplus_winrt
@interface UWPBackgroundTask : NSObject
- (instancetype)init __attribute__((unavailable("Use sharedInstance class method to initialize.")));
+ (instancetype)sharedInstance;
- (void)isEnteringBackground;
- (void)isEnteringForeground;
- (double)timeRemaining;
- (NSUInteger)requestBackgroundTask:(void (^)(void))handler;
- (void)unregisterBackgroundTask:(NSUInteger)triggerId;
@end
#endif