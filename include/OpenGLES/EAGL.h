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

#ifndef _EAGL_H_
#define _EAGL_H_

#import <Foundation/Foundation.h>
#import <OpenGLES/EAGLExport.h>

enum {
   kEAGLRenderingAPIOpenGLES1 = 1,
   kEAGLRenderingAPIOpenGLES2 = 2
};
typedef uint32_t EAGLRenderingAPI;

@interface EAGLSharegroup : NSObject
@end

struct EAGLContextPrivateData;

EAGL_EXPORT_CLASS
@interface EAGLContext : NSObject {
@public
    struct EAGLContextPrivateData *eaglPriv;
}

@property (readonly) EAGLSharegroup *sharegroup;

- (id)initWithAPI:(EAGLRenderingAPI)api;
- (id)initWithAPI:(EAGLRenderingAPI)api sharegroup:(EAGLSharegroup *)sharegroup;
- (BOOL) presentRenderbuffer: (int) obj;
- (BOOL) renderbufferStorage: (int) dest fromDrawable: (id) layer;

+ (BOOL) setCurrentContext: (id) newContext;
+ (EAGLContext *) currentContext;

@end

#endif /* _EAGL_H_ */