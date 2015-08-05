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
#include "CACompositor.h"

@implementation CAEAGLLayer : CALayer
    -(void) setDrawableProperties:(id)propertiesDict {
        properties = [propertiesDict retain];
    }

    -(void) setOpaque:(BOOL)opaque {
        [super setOpaque:opaque];
    }

    -(void) _setDisplayTexture:(DisplayTexture *)tex {
        if ( _glTexture != NULL ) {
            _globalCompositor->ReleaseDisplayTexture(_glTexture);
            _glTexture = NULL;
        } 

        _glTexture = tex;
        _globalCompositor->RetainDisplayTexture(_glTexture);
        double fadeDuration = 0.25f;

        [self setNeedsDisplay];
    }

    -(DisplayTexture *) _getDisplayTexture {
        priv->contentsSize.width = ceilf(priv->bounds.size.width) * priv->contentsScale;
        priv->contentsSize.height = ceilf(priv->bounds.size.height) * priv->contentsScale;

        if ( _glTexture == NULL ) {
            return NULL;
        }

        _globalCompositor->RetainDisplayTexture(_glTexture);

        return _glTexture;
    }
    
    -(NSDictionary*) drawableProperties {
        return properties;
    }

    -(void) display {
    }

    -(void) _releaseContents {
    }

    -(void) _unlockTexture {
        if ( _glTexture ) {
            GetCACompositor()->UnlockD3DDisplayTexture(_glTexture);
        }
    }

    -(void) dealloc {
        if ( _glTexture ) {
            GetCACompositor()->UnlockD3DDisplayTexture(_glTexture);
            GetCACompositor()->ReleaseDisplayTexture(_glTexture);
        }
        _glTexture = NULL;
        [super dealloc];
    }
@end

