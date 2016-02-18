//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#import <GLKit/GLKitExport.h>
#import <GLKit/GLKMath.h>

typedef struct _GLKMatrixStack* GLKMatrixStackRef;

GLKIT_EXPORT GLKMatrixStackRef GLKMatrixStackCreate(CFAllocatorRef alloc) STUB_METHOD;
GLKIT_EXPORT CFTypeID GLKMatrixStackGetTypeID() STUB_METHOD;
GLKIT_EXPORT void GLKMatrixStackPop(GLKMatrixStackRef stack) STUB_METHOD;
GLKIT_EXPORT void GLKMatrixStackPush(GLKMatrixStackRef stack) STUB_METHOD;
GLKIT_EXPORT int GLKMatrixStackSize(GLKMatrixStackRef stack) STUB_METHOD;
GLKIT_EXPORT GLKMatrix2 GLKMatrixStackGetMatrix2(GLKMatrixStackRef stack) STUB_METHOD;
GLKIT_EXPORT GLKMatrix3 GLKMatrixStackGetMatrix3(GLKMatrixStackRef stack) STUB_METHOD;
GLKIT_EXPORT GLKMatrix3 GLKMatrixStackGetMatrix3Inverse(GLKMatrixStackRef stack) STUB_METHOD;
GLKIT_EXPORT GLKMatrix3 GLKMatrixStackGetMatrix3InverseTranspose(GLKMatrixStackRef stack) STUB_METHOD;
GLKIT_EXPORT GLKMatrix4 GLKMatrixStackGetMatrix4(GLKMatrixStackRef stack) STUB_METHOD;
GLKIT_EXPORT GLKMatrix4 GLKMatrixStackGetMatrix4Inverse(GLKMatrixStackRef stack) STUB_METHOD;
GLKIT_EXPORT GLKMatrix4 GLKMatrixStackGetMatrix4InverseTranspose(GLKMatrixStackRef stack) STUB_METHOD;
GLKIT_EXPORT void GLKMatrixStackLoadMatrix4(GLKMatrixStackRef stack, GLKMatrix4 matrix) STUB_METHOD;
GLKIT_EXPORT void GLKMatrixStackMultiplyMatrix4(GLKMatrixStackRef stack, GLKMatrix4 matrix) STUB_METHOD;
GLKIT_EXPORT void GLKMatrixStackMultiplyMatrixStack(GLKMatrixStackRef stackLeft, GLKMatrixStackRef stackRight) STUB_METHOD;
GLKIT_EXPORT void GLKMatrixStackRotate(GLKMatrixStackRef stack, float radians, float x, float y, float z) STUB_METHOD;
GLKIT_EXPORT void GLKMatrixStackRotateWithVector3(GLKMatrixStackRef stack, float radians, GLKVector3 axisVector) STUB_METHOD;
GLKIT_EXPORT void GLKMatrixStackRotateWithVector4(GLKMatrixStackRef stack, float radians, GLKVector4 axisVector) STUB_METHOD;
GLKIT_EXPORT void GLKMatrixStackRotateX(GLKMatrixStackRef stack, float radians) STUB_METHOD;
GLKIT_EXPORT void GLKMatrixStackRotateY(GLKMatrixStackRef stack, float radians) STUB_METHOD;
GLKIT_EXPORT void GLKMatrixStackRotateZ(GLKMatrixStackRef stack, float radians) STUB_METHOD;
GLKIT_EXPORT void GLKMatrixStackScale(GLKMatrixStackRef stack, float sx, float sy, float sz) STUB_METHOD;
GLKIT_EXPORT void GLKMatrixStackScaleWithVector3(GLKMatrixStackRef stack, GLKVector3 scaleVector) STUB_METHOD;
GLKIT_EXPORT void GLKMatrixStackScaleWithVector4(GLKMatrixStackRef stack, GLKVector4 scaleVector) STUB_METHOD;
GLKIT_EXPORT void GLKMatrixStackTranslate(GLKMatrixStackRef stack, float tx, float ty, float tz) STUB_METHOD;
GLKIT_EXPORT void GLKMatrixStackTranslateWithVector3(GLKMatrixStackRef stack, GLKVector3 translationVector) STUB_METHOD;
GLKIT_EXPORT void GLKMatrixStackTranslateWithVector4(GLKMatrixStackRef stack, GLKVector4 translationVector) STUB_METHOD;
