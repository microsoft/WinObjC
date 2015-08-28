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

#import "GLES2/gl2.h"
#import "Foundation/NSObject.h"

enum _GLKTextureInfoAlphaState {
    GLKTextureInfoAlphaStateNone = 0,
    GLKTextureInfoAlphaStateNonPremultiplied = 1,
    GLKTextureInfoAlphaStatePremultiplied = 2
};
typedef GLuint GLKTextureInfoAlphaState;

enum _GLKTextureInfoOrigin {
    GLKTextureInfoOriginUnknown = 0,
    GLKTextureInfoOriginTopLeft = 1,
    GLKTextureInfoOriginBottomLeft = 2,
};
typedef GLuint GLKTextureInfoOrigin;

// --------------------------------------------------------------------------------

GLKIT_EXPORT_CLASS
@interface GLKTextureInfo
@property (readonly) GLuint name;
@property (readonly) GLuint target;

@property (readonly) GLuint width;
@property (readonly) GLuint height;
@property (readonly) GLKTextureInfoAlphaState alphaState;
@property (readonly) BOOL containsMipmaps;

@property (readonly) GLKTextureInfoOrigin textureOrigin;

@end

GLKIT_EXPORT_CLASS
@interface GLKTextureLoader
@end

