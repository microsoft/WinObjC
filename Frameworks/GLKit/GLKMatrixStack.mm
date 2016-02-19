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

#import <StubReturn.h>
#import <GLKit/GLKMatrixStack.h>

/**
 @Status Stub
 @Notes
*/
GLKMatrixStackRef GLKMatrixStackCreate(CFAllocatorRef alloc) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFTypeID GLKMatrixStackGetTypeID() {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void GLKMatrixStackPop(GLKMatrixStackRef stack) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void GLKMatrixStackPush(GLKMatrixStackRef stack) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
int GLKMatrixStackSize(GLKMatrixStackRef stack) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
GLKMatrix2 GLKMatrixStackGetMatrix2(GLKMatrixStackRef stack) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
GLKMatrix3 GLKMatrixStackGetMatrix3(GLKMatrixStackRef stack) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
GLKMatrix3 GLKMatrixStackGetMatrix3Inverse(GLKMatrixStackRef stack) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
GLKMatrix3 GLKMatrixStackGetMatrix3InverseTranspose(GLKMatrixStackRef stack) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
GLKMatrix4 GLKMatrixStackGetMatrix4(GLKMatrixStackRef stack) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
GLKMatrix4 GLKMatrixStackGetMatrix4Inverse(GLKMatrixStackRef stack) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
GLKMatrix4 GLKMatrixStackGetMatrix4InverseTranspose(GLKMatrixStackRef stack) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void GLKMatrixStackLoadMatrix4(GLKMatrixStackRef stack, GLKMatrix4 matrix) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void GLKMatrixStackMultiplyMatrix4(GLKMatrixStackRef stack, GLKMatrix4 matrix) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void GLKMatrixStackMultiplyMatrixStack(GLKMatrixStackRef stackLeft, GLKMatrixStackRef stackRight) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void GLKMatrixStackRotate(GLKMatrixStackRef stack, float radians, float x, float y, float z) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void GLKMatrixStackRotateWithVector3(GLKMatrixStackRef stack, float radians, GLKVector3 axisVector) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void GLKMatrixStackRotateWithVector4(GLKMatrixStackRef stack, float radians, GLKVector4 axisVector) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void GLKMatrixStackRotateX(GLKMatrixStackRef stack, float radians) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void GLKMatrixStackRotateY(GLKMatrixStackRef stack, float radians) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void GLKMatrixStackRotateZ(GLKMatrixStackRef stack, float radians) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void GLKMatrixStackScale(GLKMatrixStackRef stack, float sx, float sy, float sz) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void GLKMatrixStackScaleWithVector3(GLKMatrixStackRef stack, GLKVector3 scaleVector) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void GLKMatrixStackScaleWithVector4(GLKMatrixStackRef stack, GLKVector4 scaleVector) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void GLKMatrixStackTranslate(GLKMatrixStackRef stack, float tx, float ty, float tz) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void GLKMatrixStackTranslateWithVector3(GLKMatrixStackRef stack, GLKVector3 translationVector) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void GLKMatrixStackTranslateWithVector4(GLKMatrixStackRef stack, GLKVector4 translationVector) {
    UNIMPLEMENTED();
}
