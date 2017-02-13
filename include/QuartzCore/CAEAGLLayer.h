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

#import <QuartzCore/CoreAnimationExport.h>
#import <QuartzCore/CALayer.h>
#import <OpenGLES/EAGLDrawable.h>

CA_EXPORT_CLASS
@interface CAEAGLLayer : CALayer <CAMediaTiming, EAGLDrawable, NSCoding>
@property (copy) NSDictionary* drawableProperties;
@end

#ifdef __cplusplus
namespace winrt { namespace Windows { namespace UI { namespace Xaml { namespace Controls {
class SwapChainPanel;
} } } } }

@interface CAEAGLLayer (WinObjC)
@property (readonly) winrt::Windows::UI::Xaml::Controls::SwapChainPanel swapChainPanel;
@end

#endif
