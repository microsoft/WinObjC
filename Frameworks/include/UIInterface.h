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

#include <UIKit/UIKitExport.h>

UIKIT_EXPORT void UIRequestTransactionProcessing();
UIKIT_EXPORT void UIShutdown();
UIKIT_EXPORT void UIQueueTouchInput(
    float x, float y, int fingerID, int eventType, float surfaceWidth, float surfaceHeight, int64_t eventTime, bool bLandscape = false);
UIKIT_EXPORT void UIQueueKeyInput(int key);
UIKIT_EXPORT int UIOrientationFromString(int curOrientation, NSString* str);
UIKIT_EXPORT void UIBecomeInactive();
