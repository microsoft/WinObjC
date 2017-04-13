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

// This is a method that UIKit exposes for the test frameworks to use.
extern "C" void UIApplicationInitializeFunctionalTest(const wchar_t*, const wchar_t*);

// Setup method to call before every test class to initialize the UIApplication
bool FunctionalTestSetupUIApplication();

// Cleanup method to call after every test class to free the UIApplication
bool FunctionalTestCleanupUIApplication();

#ifdef __OBJC__
#import <Foundation/Foundation.h>
static const NSTimeInterval c_testTimeoutInSec = 5;

NSString* appendPathRelativeToFTModule(NSString* pathAppendage);
NSString* getModulePath();
#endif
