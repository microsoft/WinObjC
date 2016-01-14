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

#include <COMIncludes.h>
#import <WRL/client.h>
#include <COMIncludes_End.h>

#include "UWP/WindowsSystem.h"


using namespace Microsoft::WRL;

// Packages launcher and url together, allowing us to specify a custom launcher to be used when testing _openURL
@interface UrlLauncher : NSObject
- (UrlLauncher*)initWithLauncher:(Class)launcher;

// Launches the default app handling the url. NSURL: the url to launch. Class: Always WSLauncher, except in test cases
- (BOOL)_openURL:(NSURL*)url;

// Querys the system for an app handling the url. NSURL: the url to launch. Class: Always WSLauncher, except in test cases
- (BOOL)_canOpenURL:(NSURL*)url;
@end