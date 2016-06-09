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
#include "UIImageCachedObject.h"

extern CFMutableDictionaryRef g_imageCache;
extern pthread_mutex_t imageCacheLock;

@implementation UIImageCachedObject
- (void)dealloc {
    pthread_mutex_lock(&imageCacheLock);
    [(id)g_imageCache removeObjectForKey:_cacheName];
    pthread_mutex_unlock(&imageCacheLock);
    [_cacheName release];
    if (m_pImage) {
        CGImageRelease(m_pImage);
    }

    [super dealloc];
}

@end
