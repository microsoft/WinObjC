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

#include "UIKit\UIKit.h"
#include "QuartzCore\QuartzCore.h"

#include "CACompositor.h"
#include "CALayerInternal.h"

CA_EXPORT_CLASS
@interface CAWebLayer : CALayer
{
    WebViewControl *_webView;
}
@end

@implementation CAWebLayer 
    -(instancetype) init
    {
        _webView = GetCACompositor()->CreateWebViewDisplayTexture();
        return [super init];
    }

    -(WebViewControl *) innerControl
    {
        return _webView;
    }

    -(DisplayTexture *) _getDisplayTexture {
        priv->contentsSize.width = ceilf(priv->bounds.size.width) * priv->contentsScale;
        priv->contentsSize.height = ceilf(priv->bounds.size.height) * priv->contentsScale;

        if ( _webView == NULL ) {
            return NULL;
        }

        DisplayTexture *ret = _webView->GetDisplayTexture();
        _globalCompositor->RetainDisplayTexture(ret);

        return ret;
    }
    
    -(void) display {
    }

    -(void) _releaseContents {
    }

    -(void) _unlockTexture {
    }

    -(void) dealloc {
        if ( _webView ) {
            DisplayTexture *webTexture = _webView->GetDisplayTexture();
            GetCACompositor()->ReleaseDisplayTexture(webTexture);
        }
        _webView = NULL;
        [super dealloc];
    }
@end

