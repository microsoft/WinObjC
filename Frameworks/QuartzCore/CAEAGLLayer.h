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

class DisplayTextureEAGL;

@interface CAEAGLLayer : CALayer {
@public
    id properties;
    DisplayTextureEAGL* _glTexture;
    DisplayTexture* _primaryTexture;
}
- (void)setDrawableProperties:(id)propertiesDict;
- (void)setOpaque:(BOOL)opaque;
- (void)_setDisplayTexture:(DisplayTexture*)tex;
- (DisplayTexture*)_getDisplayTexture;
- (NSDictionary*)drawableProperties;
- (void)display;
- (void)_releaseContents;
- (void)dealloc;
@end
