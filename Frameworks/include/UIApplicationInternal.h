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

#ifndef _UIAPPLICATIONINTERNAL_H_
#define _UIAPPLICATIONINTERNAL_H_
#import <UIKit/UIApplication.h>

@interface WOCDisplayMode (internal)
- (float)currentWidth;
- (float)currentHeight;
- (void)_updateDisplaySettings;
- (void)_setWindowSize:(CGSize)newSize;
- (void)_setHostScrenWidth:(float)width height:(float)height scale:(float)scale xDpi:(float)xdpi yDpi:(float)yDpi;
@end

#endif /* _UIAPPLICATIONINTERNAL_H_ */
