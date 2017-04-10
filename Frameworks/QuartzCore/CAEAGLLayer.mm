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

#include "Starboard.h"

#include "QuartzCore/CALayer.h"
#include "CALayerInternal.h"
#include "UIKit/UIView.h"
#include "QuartzCore/CAEAGLLayer.h"
#include "CAEAGLLayerInternal.h"

#include <d3d11.h>
#include <d3d11_1.h>

#include <COMIncludes.h>
#include "Windows.ui.xaml.media.dxinterop.h"
#include "winrt/Windows.UI.Xaml.Controls.h"
#include "winrt/Windows.UI.Xaml.Media.h"
#include <COMIncludes_End.h>

using namespace winrt::Windows::UI::Xaml;

@implementation CAEAGLLayer {
    NSDictionary* _properties;
    Controls::SwapChainPanel _swapChainPanel;
}

/**
 @Status Interoperable
*/
- (void)setDrawableProperties:(NSDictionary*)propertiesDict {
    if (![propertiesDict isEqualToDictionary:_properties]) {
        [_properties release];
        _properties = [propertiesDict copy];

        [self setNeedsLayout];
    }
}

/**
 @Status Interoperable
*/
- (void)setContentsScale:(float)factor {
    [super setContentsScale:factor];

    Media::ScaleTransform scaleTransform;
    scaleTransform.ScaleX(1.0 / factor);
    scaleTransform.ScaleY(1.0 / factor);

    _swapChainPanel.RenderTransform(scaleTransform);
}

/**
 @Status Interoperable
*/
- (instancetype)init {
    if (self = [super init]) {
        // Create a sublayer for the swapchain panel
        StrongId<CALayer> sublayer;
        sublayer.attach([[CALayer alloc] _initWithXamlElement:_swapChainPanel]);
        [self addSublayer:sublayer];
    }

    return self;
}

/**
 @Status Caveat
 @Notes WinObjC extension
*/
- (Controls::SwapChainPanel)swapChainPanel {
    return _swapChainPanel;
}

- (std::shared_ptr<IDisplayTexture>)_getDisplayTexture {
    return nullptr;
}

/**
   @Status Caveat
   @Notes kEAGLDrawablePropertyRetainedBacking, while implemented here, depends on ANGLE code that is not implemented.
*/
- (NSDictionary*)drawableProperties {
    return _properties;
}

- (void)display {
}

- (void)_releaseContents {
}

- (void)_unlockTexture {
}

- (void)dealloc {
    [_properties release];
    [super dealloc];
}
@end
